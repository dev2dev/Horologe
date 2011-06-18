/*
 * BaseDateTime.h
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

#import "HLAbstractDateTime.h"
#import "HLReadableDateTime.h"


/**
 * BaseDateTime is an abstract implementation of ReadableDateTime that stores
 * data in <code>long</code> and <code>Chronology</code> fields.
 * <p>
 * This class should generally not be used directly by API users.
 * The {@link ReadableDateTime} interface should be used when different 
 * kinds of date/time objects are to be referenced.
 * <p>
 * BaseDateTime subclasses may be mutable and not thread-safe.
 *
 * @author Stephen Colebourne
 * @author Kandarp Shah
 * @author Brian S O'Neill
 * @since 1.0
 */
@interface HLBaseDateTime : HLAbstractDateTime <HLReadableDateTime> {
    
@private
    /** The millis from 1970-01-01T00:00:00Z */
    NSInteger _iMillis;
    /** The chronology to use */
    HLChronology* _iChronology;
    
}

//-----------------------------------------------------------------------

/**
 * Constructs an instance set to the current system millisecond time
 * using <code>ISOChronology</code> in the specified time zone.
 * <p>
 * If the specified time zone is nil, the default zone is used.
 *
 * @param zone  the time zone, nil means default zone
 */
- (id)initWithDateTimeZone:(HLDateTimeZone*)zone;

/**
 * Constructs an instance set to the current system millisecond time
 * using the specified chronology.
 * <p>
 * If the chronology is nil, <code>ISOChronology</code>
 * in the default time zone is used.
 *
 * @param chronology  the chronology, nil means ISOChronology in default zone
 */
- (id)initWithChronology:(HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 * Constructs an instance set to the milliseconds from 1970-01-01T00:00:00Z
 * using <code>ISOChronology</code> in the default time zone.
 *
 * @param instant  the milliseconds from 1970-01-01T00:00:00Z
 */
- (id)initWithInstant:(NSInteger)instant;

/**
 * Constructs an instance set to the milliseconds from 1970-01-01T00:00:00Z
 * using <code>ISOChronology</code> in the specified time zone.
 * <p>
 * If the specified time zone is nil, the default zone is used.
 *
 * @param instant  the milliseconds from 1970-01-01T00:00:00Z
 * @param zone  the time zone, nil means default zone
 */
- (id)initWithInstant:(NSInteger)instant
                 zone:(HLDateTimeZone*)zone;

/**
 * Constructs an instance set to the milliseconds from 1970-01-01T00:00:00Z
 * using the specified chronology.
 * <p>
 * If the chronology is nil, <code>ISOChronology</code>
 * in the default time zone is used.
 *
 * @param instant  the milliseconds from 1970-01-01T00:00:00Z
 * @param chronology  the chronology, nil means ISOChronology in default zone
 */
- (id)initWithInstant:(NSInteger)instant
           chronology:(HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 * Constructs an instance from an Object that represents a datetime,
 * forcing the time zone to that specified.
 * <p>
 * If the object contains no chronology, <code>ISOChronology</code> is used.
 * If the specified time zone is nil, the default zone is used.
 * <p>
 * The recognised object types are defined in
 * {@link org.joda.time.convert.ConverterManager ConverterManager} and
 * include ReadableInstant, String, Calendar and Date.
 *
 * @param instant  the datetime object
 * @param zone  the time zone
 * @throws IllegalArgumentException if the instant is invalid
 */
- (id)initWithInstant:(id)instant
                 zone:(HLDateTimeZone*)zone;

/**
 * Constructs an instance from an Object that represents a datetime,
 * using the specified chronology.
 * <p>
 * If the chronology is nil, ISO in the default time zone is used.
 * <p>
 * The recognised object types are defined in
 * {@link org.joda.time.convert.ConverterManager ConverterManager} and
 * include ReadableInstant, String, Calendar and Date.
 *
 * @param instant  the datetime object
 * @param chronology  the chronology
 * @throws IllegalArgumentException if the instant is invalid
 */
- (id)initWithInstantObject:(id)instant
           chronology:(HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 * Constructs an instance from datetime field values
 * using <code>ISOChronology</code> in the default time zone.
 *
 * @param year  the year
 * @param monthOfYear  the month of the year
 * @param dayOfMonth  the day of the month
 * @param hourOfDay  the hour of the day
 * @param minuteOfHour  the minute of the hour
 * @param secondOfMinute  the second of the minute
 * @param millisOfSecond  the millisecond of the second
 */
- (id)initWithYear:(NSInteger)year
             month:(NSInteger)monthOfYear
               day:(NSInteger)dayOfMonth
              hour:(NSInteger)hourOfDay
            minute:(NSInteger)minuteOfHour
            second:(NSInteger)secondOfMinute
            millis:(NSInteger)millisOfSecond;

/**
 * Constructs an instance from datetime field values
 * using <code>ISOChronology</code> in the specified time zone.
 * <p>
 * If the specified time zone is nil, the default zone is used.
 *
 * @param year  the year
 * @param monthOfYear  the month of the year
 * @param dayOfMonth  the day of the month
 * @param hourOfDay  the hour of the day
 * @param minuteOfHour  the minute of the hour
 * @param secondOfMinute  the second of the minute
 * @param millisOfSecond  the millisecond of the second
 * @param zone  the time zone, nil means default time zone
 */
- (id)initWithYear:(NSInteger)year
             month:(NSInteger)monthOfYear
               day:(NSInteger)dayOfMonth
              hour:(NSInteger)hourOfDay
            minute:(NSInteger)minuteOfHour
            second:(NSInteger)secondOfMinute
            millis:(NSInteger)millisOfSecond
              zone:(HLDateTimeZone*)dateTimeZone;

/**
 * Constructs an instance from datetime field values
 * using the specified chronology.
 * <p>
 * If the chronology is nil, <code>ISOChronology</code>
 * in the default time zone is used.
 *
 * @param year  the year
 * @param monthOfYear  the month of the year
 * @param dayOfMonth  the day of the month
 * @param hourOfDay  the hour of the day
 * @param minuteOfHour  the minute of the hour
 * @param secondOfMinute  the second of the minute
 * @param millisOfSecond  the millisecond of the second
 * @param chronology  the chronology, nil means ISOChronology in default zone
 */
- (id)initWithYear:(NSInteger)year
             month:(NSInteger)monthOfYear
               day:(NSInteger)dayOfMonth
              hour:(NSInteger)hourOfDay
            minute:(NSInteger)minuteOfHour
            second:(NSInteger)secondOfMinute
            millis:(NSInteger)millisOfSecond
        chronology:(HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 * Checks the specified chronology before storing it, potentially altering it.
 * This method must not access any instance variables.
 * <p>
 * This implementation converts nulls to ISOChronology in the default zone.
 *
 * @param chronology  the chronology to use, may be nil
 * @return the chronology to store in this datetime, not nil
 */
- (HLChronology*)_checkChronology:(HLChronology*)chronology;

/**
 * Checks the specified instant before storing it, potentially altering it.
 * This method must not access any instance variables.
 * <p>
 * This implementation simply returns the instant.
 *
 * @param instant  the milliseconds from 1970-01-01T00:00:00Z to round
 * @param chronology  the chronology to use, not nil
 * @return the instant to store in this datetime
 */
- (NSInteger)_checkInstant:(NSInteger)instant
                chronology:(HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 * Gets the milliseconds of the datetime instant from the Java epoch
 * of 1970-01-01T00:00:00Z.
 * 
 * @return the number of milliseconds since 1970-01-01T00:00:00Z
 */
- (NSInteger)millis;

/**
 * Gets the chronology of the datetime.
 * 
 * @return the Chronology that the datetime is using
 */
- (HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 * Sets the milliseconds of the datetime.
 * <p>
 * All changes to the millisecond field occurs via this method.
 * Override and block this method to make a subclass immutable.
 *
 * @param instant  the milliseconds since 1970-01-01T00:00:00Z to set the datetime to
 */
- (void)_setMillis:(NSInteger)instant;

/**
 * Sets the chronology of the datetime.
 * <p>
 * All changes to the chronology field occurs via this method.
 * Override and block this method to make a subclass immutable.
 *
 * @param chronology  the chronology to set
 */
- (void)_setChronology:(HLChronology*)chronology;

@end
