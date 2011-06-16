/*
 * AbstractDateTime.h
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

#import <Foundation/Foundation.h>

#import "HLAbstractInstant.h"
#import "HLReadableDateTime.h"
#import "HLDateTimeFieldType.h"


/**
 * AbstractDateTime provides the common behaviour for datetime classes.
 * <p>
 * This class should generally not be used directly by API users.
 * The {@link ReadableDateTime} interface should be used when different 
 * kinds of date/time objects are to be referenced.
 * <p>
 * Whenever you want to implement <code>ReadableDateTime</code> you should
 * extend this class.
 * <p>
 * AbstractDateTime subclasses may be mutable and not thread-safe.
 *
 * @author Brian S O'Neill
 * @author Stephen Colebourne
 * @since 1.0
 */
@interface HLAbstractDateTime : HLAbstractInstant <HLReadableDateTime> {
    
@private
    
}

/**
 * Constructor.
 */
- (id)_init;

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
- (NSInteger)get:(HLDateTimeFieldType*)type;

//-----------------------------------------------------------------------
/**
 * Get the era field value.
 * 
 * @return the era
 */
- (NSInteger)era;

/**
 * Get the year of era field value.
 * 
 * @return the year of era
 */
- (NSInteger)centuryOfEra;

/**
 * Get the year of era field value.
 * 
 * @return the year of era
 */
- (NSInteger)yearOfEra;

/**
 * Get the year of century field value.
 * 
 * @return the year of century
 */
- (NSInteger)yearOfCentury;

/**
 * Get the year field value.
 * 
 * @return the year
 */
- (NSInteger)year;

/**
 * Get the weekyear field value.
 * 
 * @return the year of a week based year
 */
- (NSInteger)weekyear;

/**
 * Get the month of year field value.
 * 
 * @return the month of year
 */
- (NSInteger)monthOfYear;

/**
 * Get the week of weekyear field value.
 * 
 * @return the week of a week based year
 */
- (NSInteger)weekOfWeekyear;

/**
 * Get the day of year field value.
 * 
 * @return the day of year
 */
- (NSInteger)dayOfYear;

/**
 * Get the day of month field value.
 * <p>
 * The values for the day of month are defined in {@link org.joda.time.DateTimeConstants}.
 * 
 * @return the day of month
 */
- (NSInteger)dayOfMonth;

/**
 * Get the day of week field value.
 * <p>
 * The values for the day of week are defined in {@link org.joda.time.DateTimeConstants}.
 * 
 * @return the day of week
 */
- (NSInteger)dayOfWeek;

//-----------------------------------------------------------------------
/**
 * Get the hour of day field value.
 *
 * @return the hour of day
 */
- (NSInteger)hourOfDay;

/**
 * Get the minute of day field value.
 *
 * @return the minute of day
 */
- (NSInteger)minuteOfDay;

/**
 * Get the minute of hour field value.
 *
 * @return the minute of hour
 */
- (NSInteger)minuteOfHour;

/**
 * Get the second of day field value.
 *
 * @return the second of day
 */
- (NSInteger)secondOfDay;

/**
 * Get the second of minute field value.
 *
 * @return the second of minute
 */
- (NSInteger)secondOfMinute;

/**
 * Get the millis of day field value.
 *
 * @return the millis of day
 */
- (NSInteger)millisOfDay;

/**
 * Get the millis of second field value.
 *
 * @return the millis of second
 */
- (NSInteger)millisOfSecond;

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
- (NSDate*)calendarDateWithLocale:(NSLocale*)locale;

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
- (NSDate*)gregorianCalendarDate;

//-----------------------------------------------------------------------
/**
 * Output the instant using the specified format pattern.
 *
 * @param pattern  the pattern specification, nil means use <code>toString</code>
 * @see  org.joda.time.format.DateTimeFormat
 */
- (NSString*)stringWithPattern:(NSString*)pattern;

/**
 * Output the instant using the specified format pattern.
 *
 * @param pattern  the pattern specification, nil means use <code>toString</code>
 * @param locale  Locale to use, nil means default
 * @see  org.joda.time.format.DateTimeFormat
 */
- (NSString*)stringWithPattern:(NSString*)pattern
                        locale:(NSLocale*)locale;

@end
