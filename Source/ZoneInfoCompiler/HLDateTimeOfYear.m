//
//  HLDateTimeOfYear.m
//  Horologe
//
//  Created by Paul Schifferer on 10/18/10.
//  Copyright (c) 2010 Pilgrim Age Software. All rights reserved.
//

#import "HLDateTimeOfYear.h"


@implementation HLDateTimeOfYear

- (id)init {
    if ((self = [super init])) {
        // Initialization code here.
    }
    
    return self;
}
static class DateTimeOfYear {
    public final int iMonthOfYear;
    public final int iDayOfMonth;
    public final int iDayOfWeek;
    public final boolean iAdvanceDayOfWeek;
    public final int iMillisOfDay;
    public final char iZoneChar;
    
    DateTimeOfYear() {
        iMonthOfYear = 1;
        iDayOfMonth = 1;
        iDayOfWeek = 0;
        iAdvanceDayOfWeek = false;
        iMillisOfDay = 0;
        iZoneChar = 'w';
    }
    
    DateTimeOfYear(StringTokenizer st) {
        int month = 1;
        int day = 1;
        int dayOfWeek = 0;
        int millis = 0;
        boolean advance = false;
        char zoneChar = 'w';
        
        if (st.hasMoreTokens()) {
            month = parseMonth(st.nextToken());
            
            if (st.hasMoreTokens()) {
                String str = st.nextToken();
                if (str.startsWith("last")) {
                    day = -1;
                    dayOfWeek = parseDayOfWeek(str.substring(4));
                    advance = false;
                } else {
                    try {
                        day = Integer.parseInt(str);
                        dayOfWeek = 0;
                        advance = false;
                    } catch (NumberFormatException e) {
                        int index = str.indexOf(">=");
                        if (index > 0) {
                            day = Integer.parseInt(str.substring(index + 2));
                            dayOfWeek = parseDayOfWeek(str.substring(0, index));
                            advance = true;
                        } else {
                            index = str.indexOf("<=");
                            if (index > 0) {
                                day = Integer.parseInt(str.substring(index + 2));
                                dayOfWeek = parseDayOfWeek(str.substring(0, index));
                                advance = false;
                            } else {
                                throw new IllegalArgumentException(str);
                            }
                        }
                    }
                }
                
                if (st.hasMoreTokens()) {
                    str = st.nextToken();
                    zoneChar = parseZoneChar(str.charAt(str.length() - 1));
                    if (str.equals("24:00")) {
                        LocalDate date = (day == -1 ?
                                          new LocalDate(2001, month, 1).plusMonths(1) :
                                          new LocalDate(2001, month, day).plusDays(1));
                        advance = (day != -1);
                        month = date.getMonthOfYear();
                        day = date.getDayOfMonth();
                        dayOfWeek = ((dayOfWeek - 1 + 1) % 7) + 1;
                    } else {
                        millis = parseTime(str);
                    }
                }
            }
        }
        
        iMonthOfYear = month;
        iDayOfMonth = day;
        iDayOfWeek = dayOfWeek;
        iAdvanceDayOfWeek = advance;
        iMillisOfDay = millis;
        iZoneChar = zoneChar;
    }
    
    /**
     * Adds a recurring savings rule to the builder.
     */
    public void addRecurring(DateTimeZoneBuilder builder, String nameKey,
                             int saveMillis, int fromYear, int toYear)
    {
        builder.addRecurringSavings(nameKey, saveMillis,
                                    fromYear, toYear,
                                    iZoneChar,
                                    iMonthOfYear,
                                    iDayOfMonth,
                                    iDayOfWeek,
                                    iAdvanceDayOfWeek,
                                    iMillisOfDay);
    }
    
    /**
     * Adds a cutover to the builder.
     */
    public void addCutover(DateTimeZoneBuilder builder, int year) {
        builder.addCutover(year,
                           iZoneChar,
                           iMonthOfYear,
                           iDayOfMonth,
                           iDayOfWeek,
                           iAdvanceDayOfWeek,
                           iMillisOfDay);
    }
    
    public String toString() {
        return
        "MonthOfYear: " + iMonthOfYear + "\n" +
        "DayOfMonth: " + iDayOfMonth + "\n" +
        "DayOfWeek: " + iDayOfWeek + "\n" +
        "AdvanceDayOfWeek: " + iAdvanceDayOfWeek + "\n" +
        "MillisOfDay: " + iMillisOfDay + "\n" +
        "ZoneChar: " + iZoneChar + "\n";
    }
}

private static class Rule {
    public final String iName;
    public final int iFromYear;
    public final int iToYear;
    public final String iType;
    public final DateTimeOfYear iDateTimeOfYear;
    public final int iSaveMillis;
    public final String iLetterS;
    
    Rule(StringTokenizer st) {
        iName = st.nextToken().intern();
        iFromYear = parseYear(st.nextToken(), 0);
        iToYear = parseYear(st.nextToken(), iFromYear);
        if (iToYear < iFromYear) {
            throw new IllegalArgumentException();
        }
        iType = parseOptional(st.nextToken());
        iDateTimeOfYear = new DateTimeOfYear(st);
        iSaveMillis = parseTime(st.nextToken());
        iLetterS = parseOptional(st.nextToken());
    }
    
    /**
     * Adds a recurring savings rule to the builder.
     */
    public void addRecurring(DateTimeZoneBuilder builder, String nameFormat) {
        String nameKey = formatName(nameFormat);
        iDateTimeOfYear.addRecurring
        (builder, nameKey, iSaveMillis, iFromYear, iToYear);
    }
    
    private String formatName(String nameFormat) {
        int index = nameFormat.indexOf('/');
        if (index > 0) {
            if (iSaveMillis == 0) {
                // Extract standard name.
                return nameFormat.substring(0, index).intern();
            } else {
                return nameFormat.substring(index + 1).intern();
            }
        }
        index = nameFormat.indexOf("%s");
        if (index < 0) {
            return nameFormat;
        }
        String left = nameFormat.substring(0, index);
        String right = nameFormat.substring(index + 2);
        String name;
        if (iLetterS == null) {
            name = left.concat(right);
        } else {
            name = left + iLetterS + right;
        }
        return name.intern();
    }
    
    public String toString() {
        return
        "[Rule]\n" + 
        "Name: " + iName + "\n" +
        "FromYear: " + iFromYear + "\n" +
        "ToYear: " + iToYear + "\n" +
        "Type: " + iType + "\n" +
        iDateTimeOfYear +
        "SaveMillis: " + iSaveMillis + "\n" +
        "LetterS: " + iLetterS + "\n";
    }
}

- (void)dealloc {
    // Clean-up code here.
    
    [super dealloc];
}

@end
