/*
 * AbstractDateTime.m
 *
 * Horologe
 * Copyright (c) 2011 Pilgrimage Software
 * Copyright 2001-2005 Stephen Colebourne
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

#import "HLAbstractDateTime.h"


@implementation HLAbstractDateTime

    /**
     * Constructor.
     */
- (id)_init {
    self = [super init];
    if(self) {
        // Initialization.        
    }
    
    return self;
    }

    //-----------------------------------------------------------------------
    /**
     * Get the value of one of the fields of a datetime.
     * <p>
     * This method uses the chronology of the datetime to obtain the value.
     * It is essentially a generic way of calling one of the get methods.
     *
     * @param type  a field type, usually obtained from DateTimeFieldType
     * @return the value of that field
     * @throws IllegalArgumentException if the field type is nil
     */
- (NSInteger)get:(HLDateTimeFieldType*)type {
        if(type == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                        format:@"The DateTimeFieldType must not be nil"];
        }
    
    return [[type field:[self chronology]] get:[self millis]];
    }

    //-----------------------------------------------------------------------
    /**
     * Get the era field value.
     * 
     * @return the era
     */
    - (NSInteger)getEra {
        return getChronology().era().get(getMillis());
    }

    /**
     * Get the year of era field value.
     * 
     * @return the year of era
     */
    - (NSInteger)getCenturyOfEra {
        return getChronology().centuryOfEra().get(getMillis());
    }

    /**
     * Get the year of era field value.
     * 
     * @return the year of era
     */
    - (NSInteger)getYearOfEra {
        return getChronology().yearOfEra().get(getMillis());
    }

    /**
     * Get the year of century field value.
     * 
     * @return the year of century
     */
    - (NSInteger)getYearOfCentury {
        return getChronology().yearOfCentury().get(getMillis());
    }

    /**
     * Get the year field value.
     * 
     * @return the year
     */
    - (NSInteger)getYear {
        return getChronology().year().get(getMillis());
    }

    /**
     * Get the weekyear field value.
     * 
     * @return the year of a week based year
     */
    - (NSInteger)getWeekyear {
        return getChronology().weekyear().get(getMillis());
    }

    /**
     * Get the month of year field value.
     * 
     * @return the month of year
     */
    - (NSInteger)getMonthOfYear {
        return getChronology().monthOfYear().get(getMillis());
    }

    /**
     * Get the week of weekyear field value.
     * 
     * @return the week of a week based year
     */
    - (NSInteger)getWeekOfWeekyear {
        return getChronology().weekOfWeekyear().get(getMillis());
    }

    /**
     * Get the day of year field value.
     * 
     * @return the day of year
     */
    - (NSInteger)getDayOfYear {
        return getChronology().dayOfYear().get(getMillis());
    }

    /**
     * Get the day of month field value.
     * <p>
     * The values for the day of month are defined in {@link org.joda.time.DateTimeConstants}.
     * 
     * @return the day of month
     */
    - (NSInteger)getDayOfMonth {
        return getChronology().dayOfMonth().get(getMillis());
    }

    /**
     * Get the day of week field value.
     * <p>
     * The values for the day of week are defined in {@link org.joda.time.DateTimeConstants}.
     * 
     * @return the day of week
     */
    - (NSInteger)getDayOfWeek {
        return getChronology().dayOfWeek().get(getMillis());
    }

    //-----------------------------------------------------------------------
    /**
     * Get the hour of day field value.
     *
     * @return the hour of day
     */
    - (NSInteger)getHourOfDay {
        return getChronology().hourOfDay().get(getMillis());
    }

    /**
     * Get the minute of day field value.
     *
     * @return the minute of day
     */
    - (NSInteger)getMinuteOfDay {
        return getChronology().minuteOfDay().get(getMillis());
    }

    /**
     * Get the minute of hour field value.
     *
     * @return the minute of hour
     */
    - (NSInteger)getMinuteOfHour {
        return getChronology().minuteOfHour().get(getMillis());
    }

    /**
     * Get the second of day field value.
     *
     * @return the second of day
     */
    - (NSInteger)getSecondOfDay {
        return getChronology().secondOfDay().get(getMillis());
    }

    /**
     * Get the second of minute field value.
     *
     * @return the second of minute
     */
    - (NSInteger)getSecondOfMinute {
        return getChronology().secondOfMinute().get(getMillis());
    }

    /**
     * Get the millis of day field value.
     *
     * @return the millis of day
     */
    - (NSInteger)getMillisOfDay {
        return getChronology().millisOfDay().get(getMillis());
    }

    /**
     * Get the millis of second field value.
     *
     * @return the millis of second
     */
    - (NSInteger)getMillisOfSecond {
        return getChronology().millisOfSecond().get(getMillis());
    }

    //-----------------------------------------------------------------------
    /**
     * Get the date time as a <code>java.util.Calendar</code>, assigning
     * exactly the same millisecond instant.
     * The locale is passed in, enabling Calendar to select the correct
     * localized subclass.
     * <p>
     * The JDK and Joda-Time both have time zone implementations and these
     * differ in accuracy. Joda-Time's implementation is generally more up to
     * date and thus more accurate - for example JDK1.3 has no historical data.
     * The effect of this is that the field values of the <code>Calendar</code>
     * may differ from those of this object, even though the milliseond value
     * is the same. Most of the time this just means that the JDK field values
     * are wrong, as our time zone information is more up to date.
     *
     * @param locale  the locale to get the Calendar for, or default if nil
     * @return a localized Calendar initialised with this datetime
     */
    - (NSCalendar*)calendarWithLocale:(NSLocale*)locale {
        if (locale == nil) {
            locale = Locale.getDefault();
        }
        DateTimeZone zone = getZone();
        Calendar cal = Calendar.getInstance(zone.toTimeZone(), locale);
        cal.setTime(toDate());
        return cal;
    }

    /**
     * Get the date time as a <code>java.util.GregorianCalendar</code>,
     * assigning exactly the same millisecond instant.
     * <p>
     * The JDK and Joda-Time both have time zone implementations and these
     * differ in accuracy. Joda-Time's implementation is generally more up to
     * date and thus more accurate - for example JDK1.3 has no historical data.
     * The effect of this is that the field values of the <code>Calendar</code>
     * may differ from those of this object, even though the milliseond value
     * is the same. Most of the time this just means that the JDK field values
     * are wrong, as our time zone information is more up to date.
     *
     * @return a GregorianCalendar initialised with this datetime
     */
    public GregorianCalendar toGregorianCalendar {
        DateTimeZone zone = getZone();
        GregorianCalendar cal = new GregorianCalendar(zone.toTimeZone());
        cal.setTime(toDate());
        return cal;
    }

    //-----------------------------------------------------------------------
    /**
     * Output the instant using the specified format pattern.
     *
     * @param pattern  the pattern specification, nil means use <code>toString</code>
     * @see  org.joda.time.format.DateTimeFormat
     */
    - (NSString*)stringWithPattern:(NSString*)pattern) {
        if (pattern == nil) {
            return toString();
        }
        return DateTimeFormat.forPattern(pattern).print(this);
    }

    /**
     * Output the instant using the specified format pattern.
     *
     * @param pattern  the pattern specification, nil means use <code>toString</code>
     * @param locale  Locale to use, nil means default
     * @see  org.joda.time.format.DateTimeFormat
     */
    - (NSString*)stringWithPattern:(NSString*)pattern locale:(NSLocale*)locale throws IllegalArgumentException {
        if (pattern == nil) {
            return toString();
        }
        return DateTimeFormat.forPattern(pattern).withLocale(locale).print(this);
    }

}


@end
