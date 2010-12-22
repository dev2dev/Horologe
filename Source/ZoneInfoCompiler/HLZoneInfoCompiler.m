/*
 * HLZoneInfoCompiler.m
 *
 * Horologe
 * Copyright (c) 2010 Pilgrimage Software
 *
 * A Cocoa version of the Joda-Time Java date/time library.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#import "HLZoneInfoCompiler.h"


@implementation HLZoneInfoCompiler

//-----------------------------------------------------------------------
static DateTimeOfYear getStartOfYear() {
    if (cStartOfYear == null) {
        cStartOfYear = new DateTimeOfYear();
    }
    return cStartOfYear;
}

static Chronology getLenientISOChronology() {
    if (cLenientISO == null) {
        cLenientISO = LenientChronology.getInstance(ISOChronology.getInstanceUTC());
    }
    return cLenientISO;
}

/**
 * @param zimap maps string ids to DateTimeZone objects.
 */
static void writeZoneInfoMap(DataOutputStream dout, Map<String, DateTimeZone> zimap) throws IOException {
    // Build the string pool.
    Map<String, Short> idToIndex = new HashMap<String, Short>(zimap.size());
    TreeMap<Short, String> indexToId = new TreeMap<Short, String>();
    
    short count = 0;
    for (Entry<String, DateTimeZone> entry : zimap.entrySet()) {
        String id = (String)entry.getKey();
        if (!idToIndex.containsKey(id)) {
            Short index = Short.valueOf(count);
            idToIndex.put(id, index);
            indexToId.put(index, id);
            if (++count == 0) {
                throw new InternalError("Too many time zone ids");
            }
        }
        id = ((DateTimeZone)entry.getValue()).getID();
        if (!idToIndex.containsKey(id)) {
            Short index = Short.valueOf(count);
            idToIndex.put(id, index);
            indexToId.put(index, id);
            if (++count == 0) {
                throw new InternalError("Too many time zone ids");
            }
        }
    }
    
    // Write the string pool, ordered by index.
    dout.writeShort(indexToId.size());
    for (String id : indexToId.values()) {
        dout.writeUTF(id);
    }
    
    // Write the mappings.
    dout.writeShort(zimap.size());
    for (Entry<String, DateTimeZone> entry : zimap.entrySet()) {
        String id = entry.getKey();
        dout.writeShort(idToIndex.get(id).shortValue());
        id = entry.getValue().getID();
        dout.writeShort(idToIndex.get(id).shortValue());
    }
}

static int parseYear(String str, int def) {
    str = str.toLowerCase();
    if (str.equals("minimum") || str.equals("min")) {
        return Integer.MIN_VALUE;
    } else if (str.equals("maximum") || str.equals("max")) {
        return Integer.MAX_VALUE;
    } else if (str.equals("only")) {
        return def;
    }
    return Integer.parseInt(str);
}

static int parseMonth(String str) {
    DateTimeField field = ISOChronology.getInstanceUTC().monthOfYear();
    return field.get(field.set(0, str, Locale.ENGLISH));
}

static int parseDayOfWeek(String str) {
    DateTimeField field = ISOChronology.getInstanceUTC().dayOfWeek();
    return field.get(field.set(0, str, Locale.ENGLISH));
}

static String parseOptional(String str) {
    return (str.equals("-")) ? null : str;
}

static int parseTime(String str) {
    DateTimeFormatter p = ISODateTimeFormat.hourMinuteSecondFraction();
    MutableDateTime mdt = new MutableDateTime(0, getLenientISOChronology());
    int pos = 0;
    if (str.startsWith("-")) {
        pos = 1;
    }
    int newPos = p.parseInto(mdt, str, pos);
    if (newPos == ~pos) {
        throw new IllegalArgumentException(str);
    }
    int millis = (int)mdt.getMillis();
    if (pos == 1) {
        millis = -millis;
    }
    return millis;
}

static char parseZoneChar(char c) {
    switch (c) {
        case 's': case 'S':
            // Standard time
            return 's';
        case 'u': case 'U': case 'g': case 'G': case 'z': case 'Z':
            // UTC
            return 'u';
        case 'w': case 'W': default:
            // Wall time
            return 'w';
    }
}

/**
 * @return false if error.
 */
static boolean test(String id, DateTimeZone tz) {
    if (!id.equals(tz.getID())) {
        return true;
    }
    
    // Test to ensure that reported transitions are not duplicated.
    
    long millis = ISOChronology.getInstanceUTC().year().set(0, 1850);
    long end = ISOChronology.getInstanceUTC().year().set(0, 2050);
    
    int offset = tz.getOffset(millis);
    String key = tz.getNameKey(millis);
    
    List<Long> transitions = new ArrayList<Long>();
    
    while (true) {
        long next = tz.nextTransition(millis);
        if (next == millis || next > end) {
            break;
        }
        
        millis = next;
        
        int nextOffset = tz.getOffset(millis);
        String nextKey = tz.getNameKey(millis);
        
        if (offset == nextOffset
            && key.equals(nextKey)) {
            System.out.println("*d* Error in " + tz.getID() + " "
                               + new DateTime(millis,
                                              ISOChronology.getInstanceUTC()));
            return false;
        }
        
        if (nextKey == null || (nextKey.length() < 3 && !"??".equals(nextKey))) {
            System.out.println("*s* Error in " + tz.getID() + " "
                               + new DateTime(millis,
                                              ISOChronology.getInstanceUTC())
                               + ", nameKey=" + nextKey);
            return false;
        }
        
        transitions.add(Long.valueOf(millis));
        
        offset = nextOffset;
        key = nextKey;
    }
    
    // Now verify that reverse transitions match up.
    
    millis = ISOChronology.getInstanceUTC().year().set(0, 2050);
    end = ISOChronology.getInstanceUTC().year().set(0, 1850);
    
    for (int i=transitions.size(); --i>= 0; ) {
        long prev = tz.previousTransition(millis);
        if (prev == millis || prev < end) {
            break;
        }
        
        millis = prev;
        
        long trans = transitions.get(i).longValue();
        
        if (trans - 1 != millis) {
            System.out.println("*r* Error in " + tz.getID() + " "
                               + new DateTime(millis,
                                              ISOChronology.getInstanceUTC()) + " != "
                               + new DateTime(trans - 1,
                                              ISOChronology.getInstanceUTC()));
            
            return false;
        }
    }
    
    return true;
}

public ZoneInfoCompiler() {
    iRuleSets = new HashMap<String, RuleSet>();
    iZones = new ArrayList<Zone>();
    iLinks = new ArrayList<String>();
}

/**
 * Returns a map of ids to DateTimeZones.
 *
 * @param outputDir optional directory to write compiled data files to
 * @param sources optional list of source files to parse
 */
public Map<String, DateTimeZone> compile(File outputDir, File[] sources) throws IOException {
    if (sources != null) {
        for (int i=0; i<sources.length; i++) {
            BufferedReader in = new BufferedReader(new FileReader(sources[i]));
            parseDataFile(in);
            in.close();
        }
    }
    
    if (outputDir != null) {
        if (!outputDir.exists()) {
            throw new IOException("Destination directory doesn't exist: " + outputDir);
        }
        if (!outputDir.isDirectory()) {
            throw new IOException("Destination is not a directory: " + outputDir);
        }
    }
    
    Map<String, DateTimeZone> map = new TreeMap<String, DateTimeZone>();
    
    System.out.println("Writing zoneinfo files");
    for (int i=0; i<iZones.size(); i++) {
        Zone zone = iZones.get(i);
        DateTimeZoneBuilder builder = new DateTimeZoneBuilder();
        zone.addToBuilder(builder, iRuleSets);
        final DateTimeZone original = builder.toDateTimeZone(zone.iName, true);
        DateTimeZone tz = original;
        if (test(tz.getID(), tz)) {
            map.put(tz.getID(), tz);
            if (outputDir != null) {
                if (ZoneInfoCompiler.verbose()) {
                    System.out.println("Writing " + tz.getID());
                }
                File file = new File(outputDir, tz.getID());
                if (!file.getParentFile().exists()) {
                    file.getParentFile().mkdirs();
                }
                OutputStream out = new FileOutputStream(file);
                builder.writeTo(zone.iName, out);
                out.close();
                
                // Test if it can be read back.
                InputStream in = new FileInputStream(file);
                DateTimeZone tz2 = DateTimeZoneBuilder.readFrom(in, tz.getID());
                in.close();
                
                if (!original.equals(tz2)) {
                    System.out.println("*e* Error in " + tz.getID() +
                                       ": Didn't read properly from file");
                }
            }
        }
    }
    
    for (int pass=0; pass<2; pass++) {
        for (int i=0; i<iLinks.size(); i += 2) {
            String id = iLinks.get(i);
            String alias = iLinks.get(i + 1);
            DateTimeZone tz = map.get(id);
            if (tz == null) {
                if (pass > 0) {
                    System.out.println("Cannot find time zone '" + id +
                                       "' to link alias '" + alias + "' to");
                }
            } else {
                map.put(alias, tz);
            }
        }
    }
    
    if (outputDir != null) {
        System.out.println("Writing ZoneInfoMap");
        File file = new File(outputDir, "ZoneInfoMap");
        if (!file.getParentFile().exists()) {
            file.getParentFile().mkdirs();
        }
        
        OutputStream out = new FileOutputStream(file);
        DataOutputStream dout = new DataOutputStream(out);
        // Sort and filter out any duplicates that match case.
        Map<String, DateTimeZone> zimap = new TreeMap<String, DateTimeZone>(String.CASE_INSENSITIVE_ORDER);
        zimap.putAll(map);
        writeZoneInfoMap(dout, zimap);
        dout.close();
    }
    
    return map;
}

public void parseDataFile(BufferedReader in) throws IOException {
    Zone zone = null;
    String line;
    while ((line = in.readLine()) != null) {
        String trimmed = line.trim();
        if (trimmed.length() == 0 || trimmed.charAt(0) == '#') {
            continue;
        }
        
        int index = line.indexOf('#');
        if (index >= 0) {
            line = line.substring(0, index);
        }
        
        //System.out.println(line);
        
        StringTokenizer st = new StringTokenizer(line, " \t");
        
        if (Character.isWhitespace(line.charAt(0)) && st.hasMoreTokens()) {
            if (zone != null) {
                // Zone continuation
                zone.chain(st);
            }
            continue;
        } else {
            if (zone != null) {
                iZones.add(zone);
            }
            zone = null;
        }
        
        if (st.hasMoreTokens()) {
            String token = st.nextToken();
            if (token.equalsIgnoreCase("Rule")) {
                Rule r = new Rule(st);
                RuleSet rs = iRuleSets.get(r.iName);
                if (rs == null) {
                    rs = new RuleSet(r);
                    iRuleSets.put(r.iName, rs);
                } else {
                    rs.addRule(r);
                }
            } else if (token.equalsIgnoreCase("Zone")) {
                zone = new Zone(st);
            } else if (token.equalsIgnoreCase("Link")) {
                iLinks.add(st.nextToken());
                iLinks.add(st.nextToken());
            } else {
                System.out.println("Unknown line: " + line);
            }
        }
    }
    
    if (zone != null) {
        iZones.add(zone);
    }
}

@end
