/*
 * MutableDateTime.h
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

#import "HLBaseDateTime.h"
#import "HLReadWritableDateTime.h"
#import "HLAbstractReadableInstantFieldProperty.h"


@class HLChronology;
@class HLDateTimeZone;
@class HLDateTimeField;
@class HLDurationFieldType;
@class HLMutableDateTimeProperty;
@protocol HLReadableInstant;
@protocol HLReadableDuration;
@protocol HLReadablePeriod;

/** Rounding is disabled */
#define HL_ROUND_NONE (0)
/** Rounding mode as described by {@link DateTimeField#roundFloor} */
#define HL_ROUND_FLOOR (1)
/** Rounding mode as described by {@link DateTimeField#roundCeiling} */
#define HL_ROUND_CEILING (2)
/** Rounding mode as described by {@link DateTimeField#roundHalfFloor} */
#define HL_ROUND_HALF_FLOOR (3)
/** Rounding mode as described by {@link DateTimeField#roundHalfCeiling} */
#define HL_ROUND_HALF_CEILING (4)
/** Rounding mode as described by {@link DateTimeField#roundHalfEven} */
#define HL_ROUND_HALF_EVEN (5)

/**
 * MutableDateTime is the standard implementation of a modifiable datetime class.
 * It holds the datetime as milliseconds from the Java epoch of 1970-01-01T00:00:00Z.
 * <p>
 * This class uses a Chronology internally. The Chronology determines how the
 * millisecond instant value is converted into the date time fields.
 * The default Chronology is <code>ISOChronology</code> which is the agreed
 * international standard and compatable with the modern Gregorian calendar.
 * <p>
 * Each individual field can be accessed in two ways:
 * <ul>
 * <li><code>getHourOfDay()</code>
 * <li><code>hourOfDay().get()</code>
 * </ul>
 * The second technique also provides access to other useful methods on the
 * field:
 * <ul>
 * <li>get numeric value
 * <li>set numeric value
 * <li>add to numeric value
 * <li>add to numeric value wrapping with the field
 * <li>get text vlaue
 * <li>get short text value
 * <li>set text value
 * <li>field maximum value
 * <li>field minimum value
 * </ul>
 *
 * <p>
 * MutableDateTime is mutable and not thread-safe, unless concurrent threads
 * are not invoking mutator methods.
 *
 * @author Guy Allard
 * @author Brian S O'Neill
 * @author Stephen Colebourne
 * @author Mike Schrag
 * @since 1.0
 * @see DateTime
 */
@interface HLMutableDateTime {
    
@private
    /** The field to round on */
    HLDateTimeField* _iRoundingField;
    /** The mode of rounding */
    NSInteger _iRoundingMode;
    
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
- (Id)initWithInstantValue:(NSInteger)instant;

/**
 * Constructs an instance set to the milliseconds from 1970-01-01T00:00:00Z
 * using <code>ISOChronology</code> in the specified time zone.
 * <p>
 * If the specified time zone is nil, the default zone is used.
 *
 * @param instant  the milliseconds from 1970-01-01T00:00:00Z
 * @param zone  the time zone, nil means default zone
 */
- (id)initWithInstantValue:(NSInteger)instant
              dateTimeZone:(HLDateTimeZone*)zone;

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
- (id)initWithInstantValue:(NSInteger)instant
                chronology:(HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 * Constructs an instance from an Object that represents a datetime.
 * <p>
 * If the object implies a chronology (such as GregorianCalendar does),
 * then that chronology will be used. Otherwise, ISO default is used.
 * Thus if a GregorianCalendar is passed in, the chronology used will
 * be GJ, but if a Date is passed in the chronology will be ISO.
 * <p>
 * The recognised object types are defined in
 * {@link org.joda.time.convert.ConverterManager ConverterManager} and
 * include ReadableInstant, String, Calendar and Date.
 *
 * @param instant  the datetime object, nil means now
 * @throws IllegalArgumentException if the instant is invalid
 */
- (id)initwithInstant:(id)instant;

/**
 * Constructs an instance from an Object that represents a datetime,
 * forcing the time zone to that specified.
 * <p>
 * If the object implies a chronology (such as GregorianCalendar does),
 * then that chronology will be used, but with the time zone adjusted.
 * Otherwise, ISO is used in the specified time zone.
 * If the specified time zone is nil, the default zone is used.
 * Thus if a GregorianCalendar is passed in, the chronology used will
 * be GJ, but if a Date is passed in the chronology will be ISO.
 * <p>
 * The recognised object types are defined in
 * {@link org.joda.time.convert.ConverterManager ConverterManager} and
 * include ReadableInstant, String, Calendar and Date.
 *
 * @param instant  the datetime object, nil means now
 * @param zone  the time zone, nil means default time zone
 * @throws IllegalArgumentException if the instant is invalid
 */
- (id)initWithInstant:(id)instant
         dateTimeZone:(HLDateTimeZone*)zone;

/**
 * Constructs an instance from an Object that represents a datetime,
 * using the specified chronology.
 * <p>
 * If the chronology is nil, ISO in the default time zone is used.
 * Any chronology implied by the object (such as GregorianCalendar does)
 * is ignored.
 * <p>
 * The recognised object types are defined in
 * {@link org.joda.time.convert.ConverterManager ConverterManager} and
 * include ReadableInstant, String, Calendar and Date.
 *
 * @param instant  the datetime object, nil means now
 * @param chronology  the chronology, nil means ISOChronology in default zone
 * @throws IllegalArgumentException if the instant is invalid
 */
- (id)initWithInstant:(id)instant
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
       monthOfYear:(NSInteger)monthOfYear
        dayOfMonth:(NSInteger)dayOfMonth
         hourOfDay:(NSInteger)hourOfDay
      minuteOfHour:(NSInteger)minuteOfHour
    secondOfMinute:(NSInteger)secondOfMinute
    millisOfSecond:(NSInteger)millisOfSecond;

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
       monthOfYear:(NSInteger)monthOfYear
        dayOfMonth:(NSInteger)dayOfMonth
         hourOfDay:(NSInteger)hourOfDay
      minuteOfHour:(NSInteger)minuteOfHour
    secondOfMinute:(NSInteger)secondOfMinute
    millisOfSecond:(NSInteger)millisOfSecond
      dateTimeZone:(HLDateTimeZone*)zone;

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
       monthOfYear:(NSInteger)monthOfYear
        dayOfMonth:(NSInteger)dayOfMonth
         hourOfDay:(NSInteger)hourOfDay
      minuteOfHour:(NSInteger)minuteOfHour
    secondOfMinute:(NSInteger)secondOfMinute
    millisOfSecond:(NSInteger)millisOfSecond
        chronology:(HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 * Gets the field used for rounding this instant, returning nil if rounding
 * is not enabled.
 * 
 * @return the rounding field
 */
- (HLDateTimeField*)roundingField;

/**
 * Gets the rounding mode for this instant, returning ROUND_NONE if rounding
 * is not enabled.
 * 
 * @return the rounding mode constant
 */
- (NSInteger)roundingMode;

/**
 * Sets the status of rounding to use the specified field and ROUND_FLOOR mode.
 * A nil field will disable rounding.
 * Once set, the instant is then rounded using the new field and mode.
 * <p>
 * Enabling rounding will cause all subsequent calls to {@link #setMillis(long)}
 * to be rounded. This can be used to control the precision of the instant,
 * for example by setting a rounding field of minuteOfDay, the seconds and
 * milliseconds will always be zero.
 *
 * @param field rounding field or nil to disable
 */
- (void)setRoundingField:(HLDateTimeField*)field;

/**
 * Sets the status of rounding to use the specified field and mode.
 * A nil field or mode of ROUND_NONE will disable rounding.
 * Once set, the instant is then rounded using the new field and mode.
 * <p>
 * Enabling rounding will cause all subsequent calls to {@link #setMillis(long)}
 * to be rounded. This can be used to control the precision of the instant,
 * for example by setting a rounding field of minuteOfDay, the seconds and
 * milliseconds will always be zero.
 *
 * @param field  rounding field or nil to disable
 * @param mode  rounding mode or ROUND_NONE to disable
 * @throws IllegalArgumentException if mode is unknown, no exception if field is nil
 */
- (void)setRoundingField:(HLDateTimeField*)field 
                    mode:(NSInteger)mode;

//-----------------------------------------------------------------------
/**
 * Set the milliseconds of the datetime.
 * <p>
 * All changes to the millisecond field occurs via this method.
 *
 * @param instant  the milliseconds since 1970-01-01T00:00:00Z to set the
 * datetime to
 */
- (void)setMillis:(NSInteger)instant;

/**
 * Sets the millisecond instant of this instant from another.
 * <p>
 * This method does not change the chronology of this instant, just the
 * millisecond instant.
 * 
 * @param instant  the instant to use, nil means now
 */
- (void)setMillisWithInstant:(id<HLReadableInstant>)instant;

//-----------------------------------------------------------------------
/**
 * Add an amount of time to the datetime.
 * 
 * @param duration  the millis to add
 * @throws ArithmeticException if the result exceeds the capacity of the instant
 */
- (void)addDurationValue:(NSInteger)duration;

/**
 * Adds a duration to this instant.
 * <p>
 * This will typically change the value of most fields.
 *
 * @param duration  the duration to add, nil means add zero
 * @throws ArithmeticException if the result exceeds the capacity of the instant
 */
- (void)addDuration:(id<HLReadableDuration>)duration;

/**
 * Adds a duration to this instant specifying how many times to add.
 * <p>
 * This will typically change the value of most fields.
 *
 * @param duration  the duration to add, nil means add zero
 * @param scalar  direction and amount to add, which may be negative
 * @throws ArithmeticException if the result exceeds the capacity of the instant
 */
- (void)addDuration:(id<HLReadableDuration>)duration 
        usingScalar:(NSInteger)scalar;

/**
 * Adds a period to this instant.
 * <p>
 * This will typically change the value of most fields.
 *
 * @param period  the period to add, nil means add zero
 * @throws ArithmeticException if the result exceeds the capacity of the instant
 */
- (void)addPeriod:(id<HLReadablePeriod>)period;

/**
 * Adds a period to this instant specifying how many times to add.
 * <p>
 * This will typically change the value of most fields.
 *
 * @param period  the period to add, nil means add zero
 * @param scalar  direction and amount to add, which may be negative
 * @throws ArithmeticException if the result exceeds the capacity of the instant
 */
- (void)addPeriod:(id<HLReadablePeriod>)period 
      usingScalar:(NSInteger)scalar;

//-----------------------------------------------------------------------
/**
 * Set the chronology of the datetime.
 * <p>
 * All changes to the chronology occur via this method.
 * 
 * @param chronology  the chronology to use, nil means ISOChronology in default zone
 */
- (void)setChronology:(HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 * Sets the time zone of the datetime, changing the chronology and field values.
 * <p>
 * Changing the zone using this method retains the millisecond instant.
 * The millisecond instant is adjusted in the new zone to compensate.
 * 
 * chronology. Setting the time zone does not affect the millisecond value
 * of this instant.
 * <p>
 * If the chronology already has this time zone, no change occurs.
 *
 * @param newZone  the time zone to use, nil means default zone
 * @see #setZoneRetainFields
 */
- (void)setDateTimeZone:(HLDateTimeZone*)newZone;

/**
 * Sets the time zone of the datetime, changing the chronology and millisecond.
 * <p>
 * Changing the zone using this method retains the field values.
 * The millisecond instant is adjusted in the new zone to compensate.
 * <p>
 * If the chronology already has this time zone, no change occurs.
 *
 * @param newZone  the time zone to use, nil means default zone
 * @see #setZone
 */
- (void)setDateTimeZoneRetainFields:(HLDateTimeZone*)newZone;

//-----------------------------------------------------------------------
/**
 * Sets the value of one of the fields of the instant, such as hourOfDay.
 *
 * @param type  a field type, usually obtained from DateTimeFieldType, not nil
 * @param value  the value to set the field to
 * @throws IllegalArgumentException if the value is nil or invalid
 */
- (void)setValue:(NSInteger)value
    forFieldType:(HLDateTimeFieldType*)type;

/**
 * Adds to the instant specifying the duration and multiple to add.
 *
 * @param type  a field type, usually obtained from DateTimeFieldType, not nil
 * @param amount  the amount to add of this duration
 * @throws IllegalArgumentException if the value is nil or invalid
 * @throws ArithmeticException if the result exceeds the capacity of the instant
 */
- (void)addAmount:(NSInteger)amount
      toFieldType:(HLDurationFieldType*)type;

//-----------------------------------------------------------------------
/**
 * Set the year to the specified value.
 *
 * @param year  the year
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)setYear:(NSInteger)year;

/**
 * Add a number of years to the date.
 *
 * @param years  the years to add
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)addYears:(NSInteger)years;

//-----------------------------------------------------------------------
/**
 * Set the weekyear to the specified value.
 *
 * @param weekyear  the weekyear
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)setWeekyear:(NSInteger)weekyear;

/**
 * Add a number of weekyears to the date.
 *
 * @param weekyears  the weekyears to add
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)addWeekyears:(NSInteger)weekyears;

//-----------------------------------------------------------------------
/**
 * Set the month of the year to the specified value.
 *
 * @param monthOfYear  the month of the year
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)setMonthOfYear:(NSInteger)monthOfYear;

/**
 * Add a number of months to the date.
 *
 * @param months  the months to add
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)addMonths:(NSInteger)months;

//-----------------------------------------------------------------------
/**
 * Set the week of weekyear to the specified value.
 *
 * @param weekOfWeekyear the week of the weekyear
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)setWeekOfWeekyear:(NSInteger)weekOfWeekyear;

/**
 * Add a number of weeks to the date.
 *
 * @param weeks  the weeks to add
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)addWeeks:(NSInteger)weeks;

//-----------------------------------------------------------------------
/**
 * Set the day of year to the specified value.
 *
 * @param dayOfYear the day of the year
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)setDayOfYear:(NSInteger)dayOfYear;

/**
 * Set the day of the month to the specified value.
 *
 * @param dayOfMonth  the day of the month
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)setDayOfMonth:(NSInteger)dayOfMonth;

/**
 * Set the day of week to the specified value.
 *
 * @param dayOfWeek  the day of the week
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)setDayOfWeek:(NSInteger)dayOfWeek;

/**
 * Add a number of days to the date.
 *
 * @param days  the days to add
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)addDays:(NSInteger)days;

//-----------------------------------------------------------------------
/**
 * Set the hour of the day to the specified value.
 *
 * @param hourOfDay  the hour of day
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)setHourOfDay:(NSInteger)hourOfDay;

/**
 * Add a number of hours to the date.
 *
 * @param hours  the hours to add
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)addHours:(NSInteger)hours;

//-----------------------------------------------------------------------
/**
 * Set the minute of the day to the specified value.
 *
 * @param minuteOfDay  the minute of day
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)setMinuteOfDay:(NSInteger)minuteOfDay;

/**
 * Set the minute of the hour to the specified value.
 *
 * @param minuteOfHour  the minute of hour
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)setMinuteOfHour:(NSInteger)minuteOfHour;

/**
 * Add a number of minutes to the date.
 *
 * @param minutes  the minutes to add
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)addMinutes:(NSInteger)minutes;

//-----------------------------------------------------------------------
/**
 * Set the second of the day to the specified value.
 *
 * @param secondOfDay  the second of day
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)setSecondOfDay:(NSInteger)secondOfDay;

/**
 * Set the second of the minute to the specified value.
 *
 * @param secondOfMinute  the second of minute
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)setSecondOfMinute:(NSInteger)secondOfMinute;

/**
 * Add a number of seconds to the date.
 *
 * @param seconds  the seconds to add
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)addSeconds:(NSInteger)seconds;

//-----------------------------------------------------------------------
/**
 * Set the millis of the day to the specified value.
 *
 * @param millisOfDay  the millis of day
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)setMillisOfDay:(NSInteger)millisOfDay;

/**
 * Set the millis of the second to the specified value.
 *
 * @param millisOfSecond  the millis of second
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)setMillisOfSecond:(NSInteger)millisOfSecond;

/**
 * Add a number of milliseconds to the date. The implementation of this
 * method differs from the {@link #add(long)} method in that a
 * DateTimeField performs the addition.
 *
 * @param millis  the milliseconds to add
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)addMillis:(NSInteger)millis;

//-----------------------------------------------------------------------
/**
 * Set the date from milliseconds.
 * The time part of this object will be unaffected.
 *
 * @param instant  an instant to copy the date from, time part ignored
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)setDateWithInstantValue:(NSInteger)instant;

/**
 * Set the date from another instant.
 * The time part of this object will be unaffected.
 *
 * @param instant  an instant to copy the date from, time part ignored
 * @throws IllegalArgumentException if the object is invalid
 */
- (void)setDateWithInstant:(id<HLReadableInstant>)instant;

/**
 * Set the date from fields.
 * The time part of this object will be unaffected.
 *
 * @param year  the year
 * @param monthOfYear  the month of the year
 * @param dayOfMonth  the day of the month
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)setDateWithYear:(NSInteger)year
            monthOfYear:(NSInteger)monthOfYear
             dayOfMonth:(NSInteger)dayOfMonth;

//-----------------------------------------------------------------------
/**
 * Set the time from milliseconds.
 * The date part of this object will be unaffected.
 *
 * @param millis  an instant to copy the time from, date part ignored
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)setTimeWithMillis:(NSInteger)millis;

/**
 * Set the time from another instant.
 * The date part of this object will be unaffected.
 *
 * @param instant  an instant to copy the time from, date part ignored
 * @throws IllegalArgumentException if the object is invalid
 */
- (void)setTimeWithInstant:(id<HLReadableInstant>)instant;

/**
 * Set the time from fields.
 * The date part of this object will be unaffected.
 *
 * @param hour  the hour
 * @param minuteOfHour  the minute of the hour
 * @param secondOfMinute  the second of the minute
 * @param millisOfSecond  the millisecond of the second
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)setTimeWithHour:(NSInteger)hour
           minuteOfHour:(NSInteger)minuteOfHour
         secondOfMinute:(NSInteger)secondOfMinute
         millisOfSecond:(NSInteger)millisOfSecond;

/**
 * Set the date and time from fields.
 *
 * @param year  the year
 * @param monthOfYear  the month of the year
 * @param dayOfMonth  the day of the month
 * @param hourOfDay  the hour of the day
 * @param minuteOfHour  the minute of the hour
 * @param secondOfMinute  the second of the minute
 * @param millisOfSecond  the millisecond of the second
 * @throws IllegalArgumentException if the value is invalid
 */
- (void)setDateTimeWithYear:(NSInteger)year
                monthOfYear:(NSInteger)monthOfYear
                 dayOfMonth:(NSInteger)dayOfMonth
                  hourOfDay:(NSInteger)hourOfDay
               minuteOfHour:(NSInteger)minuteOfHour
             secondOfMinute:(NSInteger)secondOfMinute
             millisOfSecond:(NSInteger)millisOfSecond;

//-----------------------------------------------------------------------
/**
 * Gets the property object for the specified type, which contains many useful methods.
 *
 * @param type  the field type to get the chronology for
 * @return the property object
 * @throws IllegalArgumentException if the field is nil or unsupported
 * @since 1.2
 */
- (HLMutableDateTimeProperty*)propertyOfFieldType:(HLDateTimeFieldType*)type;

/**
 * Get the era property.
 * 
 * @return the era property
 */
- (HLMutableDateTimeProperty*)era;

/**
 * Get the century of era property.
 * 
 * @return the year of era property
 */
- (HLMutableDateTimeProperty*)centuryOfEra;

/**
 * Get the year of century property.
 * 
 * @return the year of era property
 */
- (HLMutableDateTimeProperty*)yearOfCentury;

/**
 * Get the year of era property.
 * 
 * @return the year of era property
 */
- (HLMutableDateTimeProperty*)yearOfEra;

/**
 * Get the year property.
 * 
 * @return the year property
 */
- (HLMutableDateTimeProperty*)year;

/**
 * Get the year of a week based year property.
 * 
 * @return the year of a week based year property
 */
- (HLMutableDateTimeProperty*)weekyear;

/**
 * Get the month of year property.
 * 
 * @return the month of year property
 */
- (HLMutableDateTimeProperty*)monthOfYear;

/**
 * Get the week of a week based year property.
 * 
 * @return the week of a week based year property
 */
- (HLMutableDateTimeProperty*)weekOfWeekyear;

/**
 * Get the day of year property.
 * 
 * @return the day of year property
 */
- (HLMutableDateTimeProperty*)dayOfYear;

/**
 * Get the day of month property.
 * <p>
 * The values for day of month are defined in {@link DateTimeConstants}.
 * 
 * @return the day of month property
 */
- (HLMutableDateTimeProperty*)dayOfMonth;

/**
 * Get the day of week property.
 * <p>
 * The values for day of week are defined in {@link DateTimeConstants}.
 * 
 * @return the day of week property
 */
- (HLMutableDateTimeProperty*)dayOfWeek;

//-----------------------------------------------------------------------
/**
 * Get the hour of day field property
 * 
 * @return the hour of day property
 */
- (HLMutableDateTimeProperty*)hourOfDay;

/**
 * Get the minute of day property
 * 
 * @return the minute of day property
 */
- (HLMutableDateTimeProperty*)minuteOfDay;

/**
 * Get the minute of hour field property
 * 
 * @return the minute of hour property
 */
- (HLMutableDateTimeProperty*)minuteOfHour;

/**
 * Get the second of day property
 * 
 * @return the second of day property
 */
- (HLMutableDateTimeProperty*)secondOfDay;

/**
 * Get the second of minute field property
 * 
 * @return the second of minute property
 */
- (HLMutableDateTimeProperty*)secondOfMinute;

/**
 * Get the millis of day property
 * 
 * @return the millis of day property
 */
- (HLMutableDateTimeProperty*)millisOfDay;

/**
 * Get the millis of second property
 * 
 * @return the millis of second property
 */
- (HLMutableDateTimeProperty*)millisOfSecond;

//-----------------------------------------------------------------------
/**
 * Clone this object without having to cast the returned object.
 *
 * @return a clone of the this object.
 */
- (HLMutableDateTime*)copy;

@end


/**
 * MutableDateTime.Property binds a MutableDateTime to a
 * DateTimeField allowing powerful datetime functionality to be easily
 * accessed.
 * <p>
 * The example below shows how to use the property to change the value of a
 * MutableDateTime object.
 * <pre>
 * MutableDateTime dt = new MutableDateTime(1972, 12, 3, 13, 32, 19, 123);
 * dt.year().add(20);
 * dt.second().roundFloor().minute().set(10);
 * </pre>
 * <p>
 * MutableDateTime.Propery itself is thread-safe and immutable, but the
 * MutableDateTime being operated on is not.
 *
 * @author Stephen Colebourne
 * @author Brian S O'Neill
 * @since 1.0
 */
@interface HLMutableDateTimeProperty : HLAbstractReadableInstantFieldProperty {
    
@private
    /** The instant this property is working against */
    HLMutableDateTime* _iInstant;
    /** The field this property is working against */
    HLDateTimeField* _iField;
    
}

/**
 * Constructor.
 * 
 * @param instant  the instant to set
 * @param field  the field to use
 */
- (id)initWithInstant:(HLMutableDateTime*)instant
                field:(HLDateTimeField*)field;

//-----------------------------------------------------------------------
/**
 * Gets the field being used.
 * 
 * @return the field
 */
- (HLDateTimeField*)getField;

/**
 * Gets the milliseconds of the datetime that this property is linked to.
 * 
 * @return the milliseconds
 */
- (NSInteger)millis;

/**
 * Gets the chronology of the datetime that this property is linked to.
 * 
 * @return the chronology
 * @since 1.4
 */
- (HLChronology*)chronology;

/**
 * Gets the mutable datetime being used.
 * 
 * @return the mutable datetime
 */
- (HLMutableDateTime*)mutableDateTime;

//-----------------------------------------------------------------------
/**
 * Adds a value to the millis value.
 * 
 * @param value  the value to add
 * @return the mutable datetime being used, so calls can be chained
 * @see DateTimeField#add(long,int)
 */
- (HLMutableDateTime*)addValue:(NSInteger)value;

/**
 * Adds a value, possibly wrapped, to the millis value.
 * 
 * @param value  the value to add
 * @return the mutable datetime being used, so calls can be chained
 * @see DateTimeField#addWrapField
 */
- (HLMutableDateTime*)addWrapField:(NSInteger)value;

//-----------------------------------------------------------------------
/**
 * Sets a value.
 * 
 * @param value  the value to set.
 * @return the mutable datetime being used, so calls can be chained
 * @see DateTimeField#set(long,int)
 */
- (HLMutableDateTime*)setValue:(NSInteger)value;

/**
 * Sets a text value.
 * 
 * @param text  the text value to set
 * @param locale  optional locale to use for selecting a text symbol
 * @return the mutable datetime being used, so calls can be chained
 * @throws IllegalArgumentException if the text value isn't valid
 * @see DateTimeField#set(long,java.lang.String,java.util.Locale)
 */
- (HLMutableDateTime*)setTextValue:(NSString*)text 
                            locale:(NSLocale*)locale;

/**
 * Sets a text value.
 * 
 * @param text  the text value to set
 * @return the mutable datetime being used, so calls can be chained
 * @throws IllegalArgumentException if the text value isn't valid
 * @see DateTimeField#set(long,java.lang.String)
 */
- (HLMutableDateTime*)setTextValue:(NSString*)text;

//-----------------------------------------------------------------------
/**
 * Round to the lowest whole unit of this field.
 *
 * @return the mutable datetime being used, so calls can be chained
 * @see DateTimeField#roundFloor
 */
- (HLMutableDateTime*)roundFloor;

/**
 * Round to the highest whole unit of this field.
 *
 * @return the mutable datetime being used, so calls can be chained
 * @see DateTimeField#roundCeiling
 */
- (HLMutableDateTime*)roundCeiling;

/**
 * Round to the nearest whole unit of this field, favoring the floor if
 * halfway.
 *
 * @return the mutable datetime being used, so calls can be chained
 * @see DateTimeField#roundHalfFloor
 */
- (HLMutableDateTime*)roundHalfFloor;

/**
 * Round to the nearest whole unit of this field, favoring the ceiling if
 * halfway.
 *
 * @return the mutable datetime being used, so calls can be chained
 * @see DateTimeField#roundHalfCeiling
 */
- (HLMutableDateTime*)roundHalfCeiling;

/**
 * Round to the nearest whole unit of this field. If halfway, the ceiling
 * is favored over the floor only if it makes this field's value even.
 *
 * @return the mutable datetime being used, so calls can be chained
 * @see DateTimeField#roundHalfEven
 */
- (HLMutableDateTime*)roundHalfEven;

@end
