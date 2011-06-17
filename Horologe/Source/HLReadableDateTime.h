/*
 * ReadableDateTime.h
 * 
 * Horologe
 * Copyright (c) 2011 Pilgrimage Software
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

#import "HLReadableInstant.h"


/**
 * Defines an instant in time that can be queried using datetime fields.
 * <p>
 * The implementation of this interface may be mutable or immutable.
 * This interface only gives access to retrieve data, never to change it.
 * <p>
 * Methods in your application should be defined using <code>ReadableDateTime</code>
 * as a parameter if the method only wants to read the datetime, and not perform
 * any advanced manipulations.
 *
 * @author Stephen Colebourne
 * @author Brian S O'Neill
 * @since 1.0
 */
@protocol HLReadableDateTime <HLReadableInstant>

/**
 * Get the day of week field value.
 * <p>
 * The values for the day of week are defined in {@link DateTimeConstants}.
 * 
 * @return the day of week
 */
- (NSInteger)dayOfWeek;

/**
 * Get the day of month field value.
 * 
 * @return the day of month
 */
- (NSInteger)dayOfMonth;

/**
 * Get the day of year field value.
 * 
 * @return the day of year
 */
- (NSInteger)dayOfYear;

/**
 * Get the week of weekyear field value.
 * 
 * @return the week of a week based year
 */
- (NSInteger)weekOfWeekyear;

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
 * Get the year field value.
 * 
 * @return the year
 */
- (NSInteger)year;

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
 * Get the year of era field value.
 * 
 * @return the year of era
 */
- (NSInteger)centuryOfEra;

/**
 * Get the era field value.
 * 
 * @return the era
 */
- (NSInteger)era;

// Time field access methods
//-----------------------------------------------------------

/**
 * Get the millis of second field value.
 *
 * @return the millis of second
 */
- (NSInteger)millisOfSecond;

/**
 * Get the millis of day field value.
 *
 * @return the millis of day
 */
- (NSInteger)millisOfDay;

/**
 * Get the second of minute field value.
 *
 * @return the second of minute
 */
- (NSInteger)secondOfMinute;

/**
 * Get the second of day field value.
 *
 * @return the second of day
 */
- (NSInteger)secondOfDay;

/**
 * Get the minute of hour field value.
 *
 * @return the minute of hour
 */
- (NSInteger)minuteOfHour;

/**
 * Get the minute of day field value.
 *
 * @return the minute of day
 */
- (NSInteger)minuteOfDay;

/**
 * Get the hour of day field value.
 *
 * @return the hour of day
 */
- (NSInteger)hourOfDay;

/**
 * Get this object as a DateTime.
 * <p>
 * If the implementation of the interface is a DateTime, it is returned directly.
 * 
 * @return a DateTime using the same millis
 */
- (HLDateTime*)toDateTime;

/**
 * Get this object as a MutableDateTime, always returning a new instance.
 * 
 * @return a MutableDateTime using the same millis
 */
- (HLMutableDateTime*)toMutableDateTime;

/**
 * Output the instant using the specified format pattern.
 *
 * @param pattern  pattern specification
 * @throws IllegalArgumentException  if pattern is invalid
 * @see  org.joda.time.format.DateTimeFormat
 */
- (NSString*)stringWithPattern:(NSString*)pattern;

/**
 * Output the instant using the specified format pattern.
 *
 * @param pattern  pattern specification
 * @param locale  Locale to use, or nil for default
 * @throws IllegalArgumentException  if pattern is invalid
 * @see  org.joda.time.format.DateTimeFormat
 */
- (NSString*)stringWithPattern:(NSString*)pattern 
                        locale:(NSLocale*)locale;

@end
