//
//  HLZone.m
//  Horologe
//
//  Created by Paul Schifferer on 10/18/10.
//  Copyright (c) 2010 Pilgrim Age Software. All rights reserved.
//

#import "HLZone.h"


@implementation HLZone

- (id)init {
    if ((self = [super init])) {
        // Initialization code here.
    }
    
    return self;
}

private static class Zone {
    public final String iName;
    public final int iOffsetMillis;
    public final String iRules;
    public final String iFormat;
    public final int iUntilYear;
    public final DateTimeOfYear iUntilDateTimeOfYear;
    
    private Zone iNext;
    
    Zone(StringTokenizer st) {
        this(st.nextToken(), st);
    }
    
    private Zone(String name, StringTokenizer st) {
        iName = name.intern();
        iOffsetMillis = parseTime(st.nextToken());
        iRules = parseOptional(st.nextToken());
        iFormat = st.nextToken().intern();
        
        int year = Integer.MAX_VALUE;
        DateTimeOfYear dtOfYear = getStartOfYear();
        
        if (st.hasMoreTokens()) {
            year = Integer.parseInt(st.nextToken());
            if (st.hasMoreTokens()) {
                dtOfYear = new DateTimeOfYear(st);
            }
        }
        
        iUntilYear = year;
        iUntilDateTimeOfYear = dtOfYear;
    }
    
    void chain(StringTokenizer st) {
        if (iNext != null) {
            iNext.chain(st);
        } else {
            iNext = new Zone(iName, st);
        }
    }
    
    /*
     public DateTimeZone buildDateTimeZone(Map ruleSets) {
     DateTimeZoneBuilder builder = new DateTimeZoneBuilder();
     addToBuilder(builder, ruleSets);
     return builder.toDateTimeZone(iName);
     }
     */
    
    /**
     * Adds zone info to the builder.
     */
    public void addToBuilder(DateTimeZoneBuilder builder, Map<String, RuleSet> ruleSets) {
        addToBuilder(this, builder, ruleSets);
    }
    
    private static void addToBuilder(Zone zone,
                                     DateTimeZoneBuilder builder,
                                     Map<String, RuleSet> ruleSets)
    {
        for (; zone != null; zone = zone.iNext) {
            builder.setStandardOffset(zone.iOffsetMillis);
            
            if (zone.iRules == null) {
                builder.setFixedSavings(zone.iFormat, 0);
            } else {
                try {
                    // Check if iRules actually just refers to a savings.
                    int saveMillis = parseTime(zone.iRules);
                    builder.setFixedSavings(zone.iFormat, saveMillis);
                }
                catch (Exception e) {
                    RuleSet rs = ruleSets.get(zone.iRules);
                    if (rs == null) {
                        throw new IllegalArgumentException
                        ("Rules not found: " + zone.iRules);
                    }
                    rs.addRecurring(builder, zone.iFormat);
                }
            }
            
            if (zone.iUntilYear == Integer.MAX_VALUE) {
                break;
            }
            
            zone.iUntilDateTimeOfYear.addCutover(builder, zone.iUntilYear);
        }
    }
    
    public String toString() {
        String str =
        "[Zone]\n" + 
        "Name: " + iName + "\n" +
        "OffsetMillis: " + iOffsetMillis + "\n" +
        "Rules: " + iRules + "\n" +
        "Format: " + iFormat + "\n" +
        "UntilYear: " + iUntilYear + "\n" +
        iUntilDateTimeOfYear;
        
        if (iNext == null) {
            return str;
        }
        
        return str + "...\n" + iNext.toString();
    }
}

- (void)dealloc {
    // Clean-up code here.
    
    [super dealloc];
}

@end
