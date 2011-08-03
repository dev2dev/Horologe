/*
 * TimeOfDay.h
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

#import "HLBasePartial.h"
#import "HLReadablePartial.h"
#import "HLAbstractPartialFieldProperty.h"

/** The index of the hourOfDay field in the field array */
#define HL_HOUR_OF_DAY (0)
/** The index of the minuteOfHour field in the field array */
#define HL_MINUTE_OF_HOUR (1)
/** The index of the secondOfMinute field in the field array */
#define HL_SECOND_OF_MINUTE (2)
/** The index of the millisOfSecond field in the field array */
#define HL_MILLIS_OF_SECOND (3)

@class HLTimeOfDayProperty;
@class HLDateTimeZone;
@class HLLocalTime;
@protocol HLReadablePeriod;

/**
 * TimeOfDay is an immutable partial supporting the hour, minute, second
 * and millisecond fields.
 * <p>
 * NOTE: This class only supports the four fields listed above. Thus, you
 * cannot query the millisOfDay or secondOfDay fields for example.
 * The new <code>LocalTime</code> class removes this restriction.
 * <p>
 * Calculations on TimeOfDay are performed using a {@link Chronology}.
 * This chronology is set to be in the UTC time zone for all calculations.
 * <p>
 * Each individual field can be queried in two ways:
 * <ul>
 * <li><code>getHourOfDay()</code>
 * <li><code>hourOfDay().get()</code>
 * </ul>
 * The second technique also provides access to other useful methods on the
 * field:
 * <ul>
 * <li>numeric value - <code>hourOfDay().get()</code>
 * <li>text value - <code>hourOfDay().getAsText()</code>
 * <li>short text value - <code>hourOfDay().getAsShortText()</code>
 * <li>maximum/minimum values - <code>hourOfDay().getMaximumValue()</code>
 * <li>add/subtract - <code>hourOfDay().addToCopy()</code>
 * <li>set - <code>hourOfDay().setCopy()</code>
 * </ul>
 * <p>
 * TimeOfDay is thread-safe and immutable, provided that the Chronology is as well.
 * All standard Chronology classes supplied are thread-safe and immutable.
 *
 * @author Stephen Colebourne
 * @author Brian S O'Neill
 * @since 1.0
 * @deprecated Use LocalTime which has a much better internal implementation and
 *  has been available since 1.3
 */
@interface HLTimeOfDay : HLBasePartial <HLReadablePartial> {
    
@private
    
}

//-----------------------------------------------------------------------
/**
 * Constructs a TimeOfDay from a <code>java.util.Calendar</code>
 * using exactly the same field values avoiding any time zone effects.
 * <p>
 * Each field is queried from the Calendar and assigned to the TimeOfDay.
 * This is useful to ensure that the field values are the same in the
 * created TimeOfDay no matter what the time zone is. For example, if
 * the Calendar states that the time is 04:29, then the created TimeOfDay
 * will always have the time 04:29 irrespective of time zone issues.
 * <p>
 * This factory method ignores the type of the calendar and always
 * creates a TimeOfDay with ISO chronology.
 *
 * @param calendar  the Calendar to extract fields from
 * @return the created TimeOfDay
 * @throws IllegalArgumentException if the calendar is nil
 * @throws IllegalArgumentException if the time is invalid for the ISO chronology
 * @since 1.2
 */
+ (HLTimeOfDay*)fromDateComponents:(NSDateComponents*)components;

/**
 * Constructs a TimeOfDay from a <code>java.util.Date</code>
 * using exactly the same field values avoiding any time zone effects.
 * <p>
 * Each field is queried from the Date and assigned to the TimeOfDay.
 * This is useful to ensure that the field values are the same in the
 * created TimeOfDay no matter what the time zone is. For example, if
 * the Calendar states that the time is 04:29, then the created TimeOfDay
 * will always have the time 04:29 irrespective of time zone issues.
 * <p>
 * This factory method always creates a TimeOfDay with ISO chronology.
 *
 * @param date  the Date to extract fields from
 * @return the created TimeOfDay
 * @throws IllegalArgumentException if the calendar is nil
 * @throws IllegalArgumentException if the date is invalid for the ISO chronology
 * @since 1.2
 */
+ (HLTimeOfDay*)fromDateFields:(NSDate*)date;

//-----------------------------------------------------------------------
/**
 * Constructs a TimeOfDay from the specified millis of day using the
 * ISO chronology.
 * <p>
 * The millisOfDay value may exceed the number of millis in one day,
 * but additional days will be ignored.
 * This method uses the UTC time zone internally.
 *
 * @param millisOfDay  the number of milliseconds into a day to convert
 */
+ (HLTimeOfDay*)fromMillisOfDay:(NSInteger)millisOfDay;

/**
 * Constructs a TimeOfDay from the specified millis of day using the
 * specified chronology.
 * <p>
 * The millisOfDay value may exceed the number of millis in one day,
 * but additional days will be ignored.
 * This method uses the UTC time zone internally.
 *
 * @param millisOfDay  the number of milliseconds into a day to convert
 * @param chrono  the chronology, nil means ISO chronology
 */
+ (HLTimeOfDay*)fromMillisOfDay:(NSInteger)millisOfDay
                     chronology:(HLChronology*)chrono;

// Constructors
//-----------------------------------------------------------------------
/**
 * Constructs a TimeOfDay with the current time, using ISOChronology in
 * the specified zone to extract the fields.
 * <p>
 * The constructor uses the specified time zone to obtain the current time.
 * Once the constructor is complete, all further calculations
 * are performed without reference to a timezone (by switching to UTC).
 * 
 * @param zone  the zone to use, nil means default zone
 * @since 1.1
 */
- (id)initWithDateTimeZone:(HLDateTimeZone*)zone;

/**
 * Constructs a TimeOfDay with the current time, using the specified chronology
 * and zone to extract the fields.
 * <p>
 * The constructor uses the time zone of the chronology specified.
 * Once the constructor is complete, all further calculations are performed
 * without reference to a timezone (by switching to UTC).
 *
 * @param chronology  the chronology, nil means ISOChronology in the default zone
 */
- (id)initWithChronology:(HLChronology*)chronology;

/**
 * Constructs a TimeOfDay extracting the partial fields from the specified
 * milliseconds using the ISOChronology in the default zone.
 * <p>
 * The constructor uses the default time zone, resulting in the local time
 * being initialised. Once the constructor is complete, all further calculations
 * are performed without reference to a timezone (by switching to UTC).
 *
 * @param instant  the milliseconds from 1970-01-01T00:00:00Z
 */
- (id)initWithInstantValue:(NSInteger)instant;

/**
 * Constructs a TimeOfDay extracting the partial fields from the specified
 * milliseconds using the chronology provided.
 * <p>
 * The constructor uses the time zone of the chronology specified.
 * Once the constructor is complete, all further calculations are performed
 * without reference to a timezone (by switching to UTC).
 *
 * @param instant  the milliseconds from 1970-01-01T00:00:00Z
 * @param chronology  the chronology, nil means ISOChronology in the default zone
 */
- (id)initWithInstantValue:(NSInteger)instant
                chronology:(HLChronology*)chronology;

/**
 * Constructs a TimeOfDay from an Object that represents a time.
 * <p>
 * The recognised object types are defined in
 * {@link org.joda.time.convert.ConverterManager ConverterManager} and
 * include ReadableInstant, String, Calendar and Date.
 * The String formats are described by {@link ISODateTimeFormat#timeParser()}.
 * <p>
 * The chronology used will be derived from the object, defaulting to ISO.
 * <p>
 * NOTE: Prior to v1.3 the string format was described by
 * {@link ISODateTimeFormat#dateTimeParser()}. Dates are now rejected.
 *
 * @param instant  the datetime object, nil means now
 * @throws IllegalArgumentException if the instant is invalid
 */
- (id)initWithInstantValue:(NSInteger)instant;

/**
 * Constructs a TimeOfDay from an Object that represents a time, using the
 * specified chronology.
 * <p>
 * The recognised object types are defined in
 * {@link org.joda.time.convert.ConverterManager ConverterManager} and
 * include ReadableInstant, String, Calendar and Date.
 * The String formats are described by {@link ISODateTimeFormat#timeParser()}.
 * <p>
 * The constructor uses the time zone of the chronology specified.
 * Once the constructor is complete, all further calculations are performed
 * without reference to a timezone (by switching to UTC).
 * The specified chronology overrides that of the object.
 * <p>
 * NOTE: Prior to v1.3 the string format was described by
 * {@link ISODateTimeFormat#dateTimeParser()}. Dates are now rejected.
 *
 * @param instant  the datetime object, nil means now
 * @param chronology  the chronology, nil means ISO default
 * @throws IllegalArgumentException if the instant is invalid
 */
- (id)initWithInstant:(id)instant
           chronology:(HLChronology*)chronology;

/**
 * Constructs a TimeOfDay with specified hour and minute and zero seconds and milliseconds
 * using <code>ISOChronology</code> in the default zone.
 * <p>
 * The constructor uses the no time zone initialising the fields as provided.
 * Once the constructor is complete, all further calculations
 * are performed without reference to a timezone (by switching to UTC).
 *
 * @param hourOfDay  the hour of the day
 * @param minuteOfHour  the minute of the hour
 */
- (id)initwithHourOfDay:(NSInteger)hourOfDay 
           minuteOfHour:(NSInteger)minuteOfHour;

/**
 * Constructs a TimeOfDay with specified hour and minute and zero seconds and milliseconds.
 * <p>
 * The constructor uses the time zone of the chronology specified.
 * Once the constructor is complete, all further calculations are performed
 * without reference to a timezone (by switching to UTC).
 *
 * @param hourOfDay  the hour of the day
 * @param minuteOfHour  the minute of the hour
 * @param chronology  the chronology, nil means ISOChronology in the default zone
 */
- (id)initWithHourOfDay:(NSInteger)hourOfDay 
           minuteOfHour:(NSInteger)minuteOfHour
             chronology:(HLChronology*)chronology;

/**
 * Constructs a TimeOfDay with specified time field values and zero milliseconds
 * using <code>ISOChronology</code> in the default zone.
 * <p>
 * The constructor uses the no time zone initialising the fields as provided.
 * Once the constructor is complete, all further calculations
 * are performed without reference to a timezone (by switching to UTC).
 *
 * @param hourOfDay  the hour of the day
 * @param minuteOfHour  the minute of the hour
 * @param secondOfMinute  the second of the minute
 */
- (id)initWithHourOfDay:(NSInteger)hourOfDay 
           minuteOfHour:(NSInteger)minuteOfHour 
         seconfOfMinute:(NSInteger)secondOfMinute;

/**
 * Constructs a TimeOfDay with specified time field values and zero milliseconds.
 * <p>
 * The constructor uses the time zone of the chronology specified.
 * Once the constructor is complete, all further calculations are performed
 * without reference to a timezone (by switching to UTC).
 *
 * @param hourOfDay  the hour of the day
 * @param minuteOfHour  the minute of the hour
 * @param secondOfMinute  the second of the minute
 * @param chronology  the chronology, nil means ISOChronology in the default zone
 */
- (id)initWithHourOfDay:(NSInteger)hourOfDay 
           minuteOfHour:(NSInteger)minuteOfHour 
         secondOfMinute:(NSInteger)secondOfMinute
             chronology:(HLChronology*)chronology;

/**
 * Constructs a TimeOfDay with specified time field values using
 * <code>ISOChronology</code> in the default zone.
 * <p>
 * The constructor uses the no time zone initialising the fields as provided.
 * Once the constructor is complete, all further calculations
 * are performed without reference to a timezone (by switching to UTC).
 *
 * @param hourOfDay  the hour of the day
 * @param minuteOfHour  the minute of the hour
 * @param secondOfMinute  the second of the minute
 * @param millisOfSecond  the millisecond of the second
 */
- (id)initWithHourOfDay:(NSInteger)hourOfDay 
           minuteOfHour:(NSInteger)minuteOfHour 
         secondOfMinute:(NSInteger)secondOfMinute 
         millisOfSecond:(NSInteger)millisOfSecond;

/**
 * Constructs a TimeOfDay with specified time field values and chronology.
 * <p>
 * The constructor uses the time zone of the chronology specified.
 * Once the constructor is complete, all further calculations are performed
 * without reference to a timezone (by switching to UTC).
 *
 * @param hourOfDay  the hour of the day
 * @param minuteOfHour  the minute of the hour
 * @param secondOfMinute  the second of the minute
 * @param millisOfSecond  the millisecond of the second
 * @param chronology  the chronology, nil means ISOChronology in the default zone
 */
- (id)initWithHourOfDay:(NSInteger)hourOfDay 
           minuteOfHour:(NSInteger)minuteOfHour 
         secondOfMinute:(NSInteger)secondOfMinute 
         millisOfSecond:(NSInteger)millisOfSecond
             chronology:(HLChronology*)chronology;

/**
 * Constructs a TimeOfDay with chronology from this instance and new values.
 *
 * @param partial  the partial to base this new instance on
 * @param values  the new set of values
 */
- (id)initWithPartial:(HLTimeOfDay*)partial
               values:(NSArray*)values;

/**
 * Constructs a TimeOfDay with values from this instance and a new chronology.
 *
 * @param partial  the partial to base this new instance on
 * @param chrono  the new chronology
 */
- (id)initWithPartial:(HLTimeOfDay*)partial
           chronology:(HLChronology*)chrono;

//-----------------------------------------------------------------------
/**
 * Gets the number of fields in this partial.
 * 
 * @return the field count
 */
- (NSInteger)size;

/**
 * Gets the field for a specific index in the chronology specified.
 * <p>
 * This method must not use any instance variables.
 * 
 * @param index  the index to retrieve
 * @param chrono  the chronology to use
 * @return the field
 */
- (HLDateTimeField*)fieldAtIndex:(NSInteger)index 
                  withChronology:(HLChronology*)chrono;

/**
 * Gets the field type at the specified index.
 *
 * @param index  the index to retrieve
 * @return the field at the specified index
 * @throws IndexOutOfBoundsException if the index is invalid
 */
- (HLDateTimeFieldType*)fieldTypeAtIndex:(NSInteger)index;

/**
 * Gets an array of the field type of each of the fields that this partial supports.
 * <p>
 * The fields are returned largest to smallest, Hour, Minute, Second, Millis.
 *
 * @return the array of field types (cloned), largest to smallest
 */
- (NSArray*)fieldTypes;

//-----------------------------------------------------------------------
/**
 * Returns a copy of this time with the specified chronology.
 * This instance is immutable and unaffected by this method call.
 * <p>
 * This method retains the values of the fields, thus the result will
 * typically refer to a different instant.
 * <p>
 * The time zone of the specified chronology is ignored, as TimeOfDay
 * operates without a time zone.
 *
 * @param newChronology  the new chronology, nil means ISO
 * @return a copy of this datetime with a different chronology
 * @throws IllegalArgumentException if the values are invalid for the new chronology
 */
- (HLTimeOfDay*)withChronologyRetainFields:(HLChronology*)newChronology;

/**
 * Returns a copy of this time with the specified field set to a new value.
 * <p>
 * For example, if the field type is <code>minuteOfHour</code> then the day
 * would be changed in the returned instance.
 * <p>
 * These three lines are equivalent:
 * <pre>
 * TimeOfDay updated = tod.withField(DateTimeFieldType.minuteOfHour(), 6);
 * TimeOfDay updated = tod.minuteOfHour().setCopy(6);
 * TimeOfDay updated = tod.property(DateTimeFieldType.minuteOfHour()).setCopy(6);
 * </pre>
 *
 * @param fieldType  the field type to set, not nil
 * @param value  the value to set
 * @return a copy of this instance with the field set
 * @throws IllegalArgumentException if the value is nil or invalid
 */
- (HLTimeOfDay*)withField:(HLDateTimeFieldType*)fieldType 
                    value:(NSInteger)value;

/**
 * Returns a copy of this time with the value of the specified field increased,
 * wrapping to what would be a new day if required.
 * <p>
 * If the addition is zero, then <code>this</code> is returned.
 * <p>
 * These three lines are equivalent:
 * <pre>
 * TimeOfDay added = tod.withFieldAdded(DurationFieldType.minutes(), 6);
 * TimeOfDay added = tod.plusMinutes(6);
 * TimeOfDay added = tod.minuteOfHour().addToCopy(6);
 * </pre>
 * 
 * @param fieldType  the field type to add to, not nil
 * @param amount  the amount to add
 * @return a copy of this instance with the field updated
 * @throws IllegalArgumentException if the value is nil or invalid
 * @throws ArithmeticException if the new datetime exceeds the capacity
 */
- (HLTimeOfDay*)withField:(HLDurationFieldType*)fieldType 
             addingAmount:(NSInteger)amount;

/**
 * Returns a copy of this time with the specified period added,
 * wrapping to what would be a new day if required.
 * <p>
 * If the addition is zero, then <code>this</code> is returned.
 * Fields in the period that aren't present in the partial are ignored.
 * <p>
 * This method is typically used to add multiple copies of complex
 * period instances. Adding one field is best achieved using methods
 * like {@link #withFieldAdded(DurationFieldType, int)}
 * or {@link #plusHours(int)}.
 * 
 * @param period  the period to add to this one, nil means zero
 * @param scalar  the amount of times to add, such as -1 to subtract once
 * @return a copy of this instance with the period added
 * @throws ArithmeticException if the new datetime exceeds the capacity
 */
- (HLTimeOfDay*)withPeriod:(id<HLReadablePeriod>)period 
              addingScalar:(NSInteger)scalar;

//-----------------------------------------------------------------------
/**
 * Returns a copy of this time with the specified period added,
 * wrapping to what would be a new day if required.
 * <p>
 * If the amount is zero or nil, then <code>this</code> is returned.
 * <p>
 * This method is typically used to add complex period instances.
 * Adding one field is best achieved using methods
 * like {@link #plusHours(int)}.
 * 
 * @param period  the duration to add to this one, nil means zero
 * @return a copy of this instance with the period added
 * @throws ArithmeticException if the new datetime exceeds the capacity of a long
 */
- (HLTimeOfDay*)plusPeriod:(id<HLReadablePeriod>)period;

//-----------------------------------------------------------------------
/**
 * Returns a copy of this time plus the specified number of hours.
 * <p>
 * This time instance is immutable and unaffected by this method call.
 * <p>
 * The following three lines are identical in effect:
 * <pre>
 * TimeOfDay added = dt.plusHours(6);
 * TimeOfDay added = dt.plus(Period.hours(6));
 * TimeOfDay added = dt.withFieldAdded(DurationFieldType.hours(), 6);
 * </pre>
 *
 * @param hours  the amount of hours to add, may be negative
 * @return the new time plus the increased hours
 * @since 1.1
 */
- (HLTimeOfDay*)plusHours:(NSInteger)hours;

/**
 * Returns a copy of this time plus the specified number of minutes.
 * <p>
 * This time instance is immutable and unaffected by this method call.
 * <p>
 * The following three lines are identical in effect:
 * <pre>
 * TimeOfDay added = dt.plusMinutes(6);
 * TimeOfDay added = dt.plus(Period.minutes(6));
 * TimeOfDay added = dt.withFieldAdded(DurationFieldType.minutes(), 6);
 * </pre>
 *
 * @param minutes  the amount of minutes to add, may be negative
 * @return the new time plus the increased minutes
 * @since 1.1
 */
- (HLTimeOfDay*)plusMinutes:(NSInteger)minutes;

/**
 * Returns a copy of this time plus the specified number of seconds.
 * <p>
 * This time instance is immutable and unaffected by this method call.
 * <p>
 * The following three lines are identical in effect:
 * <pre>
 * TimeOfDay added = dt.plusSeconds(6);
 * TimeOfDay added = dt.plus(Period.seconds(6));
 * TimeOfDay added = dt.withFieldAdded(DurationFieldType.seconds(), 6);
 * </pre>
 *
 * @param seconds  the amount of seconds to add, may be negative
 * @return the new time plus the increased seconds
 * @since 1.1
 */
- (HLTimeOfDay*)plusSeconds:(NSInteger)seconds;

/**
 * Returns a copy of this time plus the specified number of millis.
 * <p>
 * This time instance is immutable and unaffected by this method call.
 * <p>
 * The following three lines are identical in effect:
 * <pre>
 * TimeOfDay added = dt.plusMillis(6);
 * TimeOfDay added = dt.plus(Period.millis(6));
 * TimeOfDay added = dt.withFieldAdded(DurationFieldType.millis(), 6);
 * </pre>
 *
 * @param millis  the amount of millis to add, may be negative
 * @return the new time plus the increased millis
 * @since 1.1
 */
- (HLTimeOfDay*)plusMillis:(NSInteger)millis;

//-----------------------------------------------------------------------
/**
 * Returns a copy of this time with the specified period taken away,
 * wrapping to what would be a new day if required.
 * <p>
 * If the amount is zero or nil, then <code>this</code> is returned.
 * <p>
 * This method is typically used to subtract complex period instances.
 * Subtracting one field is best achieved using methods
 * like {@link #minusHours(int)}.
 * 
 * @param period  the period to reduce this instant by
 * @return a copy of this instance with the period taken away
 * @throws ArithmeticException if the new time exceeds capacity
 */
- (HLTimeOfDay*)minusPeriod:(id<HLReadablePeriod>)period;

//-----------------------------------------------------------------------
/**
 * Returns a copy of this time minus the specified number of hours.
 * <p>
 * This time instance is immutable and unaffected by this method call.
 * <p>
 * The following three lines are identical in effect:
 * <pre>
 * TimeOfDay subtracted = dt.minusHours(6);
 * TimeOfDay subtracted = dt.minus(Period.hours(6));
 * TimeOfDay subtracted = dt.withFieldAdded(DurationFieldType.hours(), -6);
 * </pre>
 *
 * @param hours  the amount of hours to subtract, may be negative
 * @return the new time minus the increased hours
 * @since 1.1
 */
- (HLTimeOfDay*)minusHours:(NSInteger)hours;

/**
 * Returns a copy of this time minus the specified number of minutes.
 * <p>
 * This time instance is immutable and unaffected by this method call.
 * <p>
 * The following three lines are identical in effect:
 * <pre>
 * TimeOfDay subtracted = dt.minusMinutes(6);
 * TimeOfDay subtracted = dt.minus(Period.minutes(6));
 * TimeOfDay subtracted = dt.withFieldAdded(DurationFieldType.minutes(), -6);
 * </pre>
 *
 * @param minutes  the amount of minutes to subtract, may be negative
 * @return the new time minus the increased minutes
 * @since 1.1
 */
- (HLTimeOfDay*)minusMinutes:(NSInteger)minutes;

/**
 * Returns a copy of this time minus the specified number of seconds.
 * <p>
 * This time instance is immutable and unaffected by this method call.
 * <p>
 * The following three lines are identical in effect:
 * <pre>
 * TimeOfDay subtracted = dt.minusSeconds(6);
 * TimeOfDay subtracted = dt.minus(Period.seconds(6));
 * TimeOfDay subtracted = dt.withFieldAdded(DurationFieldType.seconds(), -6);
 * </pre>
 *
 * @param seconds  the amount of seconds to subtract, may be negative
 * @return the new time minus the increased seconds
 * @since 1.1
 */
- (HLTimeOfDay*)minusSeconds:(NSInteger)seconds;

/**
 * Returns a copy of this time minus the specified number of millis.
 * <p>
 * This time instance is immutable and unaffected by this method call.
 * <p>
 * The following three lines are identical in effect:
 * <pre>
 * TimeOfDay subtracted = dt.minusMillis(6);
 * TimeOfDay subtracted = dt.minus(Period.millis(6));
 * TimeOfDay subtracted = dt.withFieldAdded(DurationFieldType.millis(), -6);
 * </pre>
 *
 * @param millis  the amount of millis to subtract, may be negative
 * @return the new time minus the increased millis
 * @since 1.1
 */
- (HLTimeOfDay*)minusMillis:(NSInteger)millis;

//-----------------------------------------------------------------------
/**
 * Gets the property object for the specified type, which contains
 * many useful methods.
 *
 * @param type  the field type to get the property for
 * @return the property object
 * @throws IllegalArgumentException if the field is nil or unsupported
 */
- (HLTimeOfDayProperty*)property:(HLDateTimeFieldType*)type;

//-----------------------------------------------------------------------
/**
 * Converts this object to a LocalTime with the same time and chronology.
 *
 * @return a LocalTime with the same time and chronology
 * @since 1.3
 */
- (HLLocalTime*)toLocalTime;

//-----------------------------------------------------------------------
/**
 * Converts this partial to a full datetime using the default time zone
 * setting the time fields from this instance and the date fields from
 * the current time.
 *
 * @return this date as a datetime with the time as the current time
 */
- (HLDateTime*)toDateTimeToday;

/**
 * Converts this partial to a full datetime using the specified time zone
 * setting the time fields from this instance and the date fields from
 * the current time.
 * <p>
 * This method uses the chronology from this instance plus the time zone
 * specified.
 *
 * @param zone  the zone to use, nil means default
 * @return this date as a datetime with the time as the current time
 */
- (HLDateTime*)toDateTimeToday:(HLDateTimeZone*)zone;

//-----------------------------------------------------------------------
/**
 * Get the hour of day (0-23) field value.
 *
 * @return the hour of day
 */
- (NSInteger)getHourOfDay;

/**
 * Get the minute of hour field value.
 *
 * @return the minute of hour
 */
- (NSInteger)getMinuteOfHour;

/**
 * Get the second of minute field value.
 *
 * @return the second of minute
 */
- (NSInteger)getSecondOfMinute;

/**
 * Get the millis of second field value.
 *
 * @return the millis of second
 */
- (NSInteger)getMillisOfSecond;

//-----------------------------------------------------------------------
/**
 * Returns a copy of this time with the hour of day field updated.
 * <p>
 * TimeOfDay is immutable, so there are no set methods.
 * Instead, this method returns a new instance with the value of
 * hour of day changed.
 *
 * @param hour  the hour of day to set
 * @return a copy of this object with the field set
 * @throws IllegalArgumentException if the value is invalid
 * @since 1.3
 */
- (HLTimeOfDay*)withHourOfDay:(NSInteger)hour;

/**
 * Returns a copy of this time with the minute of hour field updated.
 * <p>
 * TimeOfDay is immutable, so there are no set methods.
 * Instead, this method returns a new instance with the value of
 * minute of hour changed.
 *
 * @param minute  the minute of hour to set
 * @return a copy of this object with the field set
 * @throws IllegalArgumentException if the value is invalid
 * @since 1.3
 */
- (HLTimeOfDay*)withMinuteOfHour:(NSInteger)minute;

/**
 * Returns a copy of this time with the second of minute field updated.
 * <p>
 * TimeOfDay is immutable, so there are no set methods.
 * Instead, this method returns a new instance with the value of
 * second of minute changed.
 *
 * @param second  the second of minute to set
 * @return a copy of this object with the field set
 * @throws IllegalArgumentException if the value is invalid
 * @since 1.3
 */
- (HLTimeOfDay*)withSecondOfMinute:(NSInteger)second;

/**
 * Returns a copy of this time with the millis of second field updated.
 * <p>
 * TimeOfDay is immutable, so there are no set methods.
 * Instead, this method returns a new instance with the value of
 * millis of second changed.
 *
 * @param millis  the millis of second to set
 * @return a copy of this object with the field set
 * @throws IllegalArgumentException if the value is invalid
 * @since 1.3
 */
- (HLTimeOfDay*)withMillisOfSecond:(NSInteger)millis;

//-----------------------------------------------------------------------
/**
 * Get the hour of day field property which provides access to advanced functionality.
 * 
 * @return the hour of day property
 */
- (HLTimeOfDayProperty*)hourOfDayProperty;

/**
 * Get the minute of hour field property which provides access to advanced functionality.
 * 
 * @return the minute of hour property
 */
- (HLTimeOfDayProperty*)minuteOfHourProperty;

/**
 * Get the second of minute field property which provides access to advanced functionality.
 * 
 * @return the second of minute property
 */
- (HLTimeOfDayProperty*)secondOfMinuteProperty;

/**
 * Get the millis of second property which provides access to advanced functionality.
 * 
 * @return the millis of second property
 */
- (HLTimeOfDayProperty*)millisOfSecondProperty;

@end


//-----------------------------------------------------------------------
/**
 * The property class for <code>TimeOfDay</code>.
 * <p>
 * This class binds a <code>TimeOfDay</code> to a <code>DateTimeField</code>.
 * 
 * @author Stephen Colebourne
 * @since 1.0
 * @deprecated Use LocalTime which has a much better internal implementation
 */
@interface HLTimeOfDayProperty : HLAbstractPartialFieldProperty {
    
    /** The partial */
    HLTimeOfDay* _iTimeOfDay;
    /** The field index */
    NSInteger _iFieldIndex;
    
}

/**
 * Constructs a property.
 * 
 * @param partial  the partial instance
 * @param fieldIndex  the index in the partial
 */
- (id)initWithPartial:(HLTimeOfDay*)partial 
           fieldIndex:(NSInteger)fieldIndex;

/**
 * Gets the field that this property uses.
 * 
 * @return the field
 */
- (HLDateTimeField*)field;

/**
 * Gets the partial that this property belongs to.
 * 
 * @return the partial
 */
- (id<HLReadablePartial>)readablePartial;

/**
 * Gets the partial that this property belongs to.
 * 
 * @return the partial
 */
- (HLTimeOfDay*)timeOfDay;

/**
 * Gets the value of this field.
 * 
 * @return the field value
 */
- (NSInteger)value;

//-----------------------------------------------------------------------
/**
 * Adds to the value of this field in a copy of this TimeOfDay,
 * wrapping to what would be the next day if necessary.
 * <p>
 * The value will be added to this field. If the value is too large to be
 * added solely to this field then it will affect larger fields.
 * Smaller fields are unaffected.
 * <p>
 * If the result would be too large, beyond 23:59:59:999, then the
 * calculation wraps to 00:00:00.000. For the alternate strict behaviour
 * with no wrapping see {@link #addNoWrapToCopy(int)}.
 * <p>
 * The TimeOfDay attached to this property is unchanged by this call.
 * Instead, a new instance is returned.
 * 
 * @param valueToAdd  the value to add to the field in the copy
 * @return a copy of the TimeOfDay with the field value changed
 * @throws IllegalArgumentException if the value isn't valid
 */
- (HLTimeOfDay*)addToCopy:(NSInteger)valueToAdd;

/**
 * Adds to the value of this field in a copy of this TimeOfDay,
 * throwing an Exception if the bounds are exceeded.
 * <p>
 * The value will be added to this field. If the value is too large to be
 * added solely to this field then it will affect larger fields.
 * Smaller fields are unaffected.
 * <p>
 * If the result would be too large (beyond 23:59:59:999) or too
 * small (less than 00:00:00.000) then an Execption is thrown.
 * For the alternate behaviour which wraps to the next 'day',
 * see {@link #addToCopy(int)}.
 * <p>
 * The TimeOfDay attached to this property is unchanged by this call.
 * Instead, a new instance is returned.
 * 
 * @param valueToAdd  the value to add to the field in the copy
 * @return a copy of the TimeOfDay with the field value changed
 * @throws IllegalArgumentException if the value isn't valid
 */
- (HLTimeOfDay*)addNoWrapToCopy:(NSInteger)valueToAdd;

/**
 * Adds to the value of this field in a copy of this TimeOfDay wrapping
 * within this field if the maximum value is reached.
 * <p>
 * The value will be added to this field. If the value is too large to be
 * added solely to this field then it wraps within this field.
 * Other fields are unaffected.
 * <p>
 * For example,
 * <code>12:59:37</code> addWrapField one minute returns <code>12:00:37</code>.
 * <p>
 * The TimeOfDay attached to this property is unchanged by this call.
 * Instead, a new instance is returned.
 * 
 * @param valueToAdd  the value to add to the field in the copy
 * @return a copy of the TimeOfDay with the field value changed
 * @throws IllegalArgumentException if the value isn't valid
 */
- (HLTimeOfDay*)addWrapFieldToCopy:(NSInteger)valueToAdd;

//-----------------------------------------------------------------------
/**
 * Sets this field in a copy of the TimeOfDay.
 * <p>
 * The TimeOfDay attached to this property is unchanged by this call.
 * Instead, a new instance is returned.
 * 
 * @param value  the value to set the field in the copy to
 * @return a copy of the TimeOfDay with the field value changed
 * @throws IllegalArgumentException if the value isn't valid
 */
- (HLTimeOfDay*)setCopyWithValue:(NSInteger)value;

/**
 * Sets this field in a copy of the TimeOfDay to a parsed text value.
 * <p>
 * The TimeOfDay attached to this property is unchanged by this call.
 * Instead, a new instance is returned.
 * 
 * @param text  the text value to set
 * @param locale  optional locale to use for selecting a text symbol
 * @return a copy of the TimeOfDay with the field value changed
 * @throws IllegalArgumentException if the text value isn't valid
 */
- (HLTimeOfDay*)setCopyWithText:(NSString*)text 
                         locale:(NSLocale*)locale;

/**
 * Sets this field in a copy of the TimeOfDay to a parsed text value.
 * <p>
 * The TimeOfDay attached to this property is unchanged by this call.
 * Instead, a new instance is returned.
 * 
 * @param text  the text value to set
 * @return a copy of the TimeOfDay with the field value changed
 * @throws IllegalArgumentException if the text value isn't valid
 */
- (HLTimeOfDay*)setCopyWithText:(NSString*)text;

//-----------------------------------------------------------------------
/**
 * Returns a new TimeOfDay with this field set to the maximum value
 * for this field.
 * <p>
 * The TimeOfDay attached to this property is unchanged by this call.
 *
 * @return a copy of the TimeOfDay with this field set to its maximum
 * @since 1.2
 */
- (HLTimeOfDay*)withMaximumValue;

/**
 * Returns a new TimeOfDay with this field set to the minimum value
 * for this field.
 * <p>
 * The TimeOfDay attached to this property is unchanged by this call.
 *
 * @return a copy of the TimeOfDay with this field set to its minimum
 * @since 1.2
 */
- (HLTimeOfDay*)withMinimumValue;

@end

/** Constant for midnight. */
extern const HLTimeOfDay* MIDNIGHT;


