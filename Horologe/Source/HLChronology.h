/*
 * Chronology.h
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


@class HLDateTimeZone;
@class HLDateTimeField;
@class HLDurationField;
@protocol HLReadablePeriod;
@protocol HLReadablePartial;

/**
 * Chronology provides access to the individual date time fields for a
 * chronological calendar system.
 * <p>
 * Various chronologies are supported by subclasses including ISO
 * and GregorianJulian. To construct a Chronology you should use the
 * factory methods on the chronology subclass in the chrono package.
 * <p>
 * For example, to obtain the current time in the coptic calendar system:
 * <pre>
 * DateTime dt = [[[HLDateTime alloc] initWithMillis:[self CopticChronology.getInstance());
 * </pre>
 * <p>
 * The provided chronology implementations are:
 * <ul>
 * <li>ISO - Based on the ISO8601 standard and suitable for use after about 1600
 * <li>GJ - Historically accurate calendar with Julian followed by Gregorian
 * <li>Gregorian - The Gregorian calendar system used for all time (proleptic)
 * <li>Julian - The Julian calendar system used for all time (proleptic)
 * <li>Buddhist - The Buddhist calendar system which is an offset in years from GJ
 * <li>Coptic - The Coptic calendar system which defines 30 day months
 * <li>Ethiopic - The Ethiopic calendar system which defines 30 day months
 * </ul>
 * Hopefully future releases will contain more chronologies.
 * <p>
 * This class defines a number of fields with names from the ISO8601 standard.
 * It does not 'strongly' define these fields however, thus implementations
 * are free to interpret the field names as they wish.
 * For example, a week could be defined as 10 days and a month as 40 days in a
 * special WeirdChronology implementation. Clearly the GJ and ISO
 * implementations provided use the field names as you would expect.
 *
 * @see org.joda.time.chrono.ISOChronology
 * @see org.joda.time.chrono.GJChronology
 * @see org.joda.time.chrono.GregorianChronology
 * @see org.joda.time.chrono.JulianChronology
 * @see org.joda.time.chrono.CopticChronology
 * @see org.joda.time.chrono.BuddhistChronology
 * @see org.joda.time.chrono.EthiopicChronology
 *
 * @author Stephen Colebourne
 * @author Brian S O'Neill
 * @since 1.0
 */
@interface HLChronology : NSObject {
    
@private
    
}

/**
 * Gets an instance of the ISOChronology in the default zone.
 * <p>
 * {@link ISOChronology} defines all fields in line with the ISO8601 standard.
 * This chronology is the default, and is suitable for all normal datetime processing.
 * It is <i>unsuitable</i> for historical datetimes before October 15, 1582
 * as it applies the modern Gregorian calendar rules before that date.
 *
 * @return the ISO chronology
 * @deprecated Use ISOChronology.getInstance()
 */
+ (HLChronology*)ISO;

/**
 * Gets an instance of the ISOChronology in the UTC zone.
 * <p>
 * {@link ISOChronology} defines all fields in line with the ISO8601 standard.
 * This chronology is the default, and is suitable for all normal datetime processing.
 * It is <i>unsuitable</i> for historical datetimes before October 15, 1582
 * as it applies the modern Gregorian calendar rules before that date.
 *
 * @return the ISO chronology
 * @deprecated Use ISOChronology.getInstanceUTC()
 */
+ (HLChronology*)ISOUTC;

/**
 * Gets an instance of the ISOChronology in the specified zone.
 * <p>
 * {@link ISOChronology} defines all fields in line with the ISO8601 standard.
 * This chronology is the default, and is suitable for all normal datetime processing.
 * It is <i>unsuitable</i> for historical datetimes before October 15, 1582
 * as it applies the modern Gregorian calendar rules before that date.
 *
 * @param zone  the zone to use, nil means default zone
 * @return the ISO chronology
 * @deprecated Use ISOChronology.getInstance(zone)
 */
+ (HLChronology*)ISOWithDateTimeZone:(HLDateTimeZone*)zone;

//-----------------------------------------------------------------------
/**
 * Gets an instance of the GJChronology in the default zone.
 * <p>
 * {@link GJChronology} defines all fields using standard meanings.
 * This chronology is intended to be used as a replacement for <code>GregorianCalendar</code>.
 * The Gregorian calendar system is used after October 15, 1582, while the
 * Julian calendar system is used before.
 * <p>
 * Unlike <code>GregorianCalendar</code>, this chronology returns a year of -1
 * for 1 BCE, -2 for 2 BCE and so on. Thus there is no year zero.
 * <p>
 * This method uses the standard Julian to Gregorian cutover date of
 * October 15th 1582. If you require a cutover on a different date, then use
 * the factories on <code>GJChronology</code> itself.
 * <p>
 * When dealing solely with dates in the modern era, from 1600 onwards,
 * we recommend using ISOChronology, which is the default.
 *
 * @return the GJ chronology
 * @deprecated Use GJChronology.getInstance()
 */
+ (HLChronology*)GJ;

/**
 * Gets an instance of the GJChronology in the UTC zone.
 * <p>
 * {@link GJChronology} defines all fields using standard meanings.
 * This chronology is intended to be used as a replacement for <code>GregorianCalendar</code>.
 * The Gregorian calendar system is used after October 15, 1582, while the
 * Julian calendar system is used before.
 * <p>
 * Unlike <code>GregorianCalendar</code>, this chronology returns a year of -1
 * for 1 BCE, -2 for 2 BCE and so on. Thus there is no year zero.
 * <p>
 * This method uses the standard Julian to Gregorian cutover date of
 * October 15th 1582. If you require a cutover on a different date, then use
 * the factories on <code>GJChronology</code> itself.
 * <p>
 * When dealing solely with dates in the modern era, from 1600 onwards,
 * we recommend using ISOChronology, which is the default.
 *
 * @return the GJ chronology
 * @deprecated Use GJChronology.getInstanceUTC()
 */
+ (HLChronology*)GJUTC;

/**
 * Gets an instance of the GJChronology in the specified zone.
 * <p>
 * {@link GJChronology} defines all fields using standard meanings.
 * This chronology is intended to be used as a replacement for <code>GregorianCalendar</code>.
 * The Gregorian calendar system is used after October 15, 1582, while the
 * Julian calendar system is used before.
 * <p>
 * Unlike <code>GregorianCalendar</code>, this chronology returns a year of -1
 * for 1 BCE, -2 for 2 BCE and so on. Thus there is no year zero.
 * <p>
 * This method uses the standard Julian to Gregorian cutover date of
 * October 15th 1582. If you require a cutover on a different date, then use
 * the factories on <code>GJChronology</code> itself.
 * <p>
 * When dealing solely with dates in the modern era, from 1600 onwards,
 * we recommend using ISOChronology, which is the default.
 *
 * @param zone  the zone to use, nil means default zone
 * @return the GJ chronology
 * @deprecated Use GJChronology.getInstance(zone)
 */
+ (HLChronology*)GJWithDateTimeZone:(HLDateTimeZone*)zone;

//-----------------------------------------------------------------------
/**
 * Gets an instance of the GregorianChronology in the default zone.
 * <p>
 * {@link GregorianChronology} defines all fields using standard meanings.
 * It uses the Gregorian calendar rules <i>for all time</i> (proleptic)
 * thus it is NOT a replacement for <code>GregorianCalendar</code>.
 * For that purpose, you should use {@link #getGJ()}.
 * <p>
 * The Gregorian calendar system defines a leap year every four years,
 * except that every 100 years is not leap, but every 400 is leap.
 * <p>
 * Technically, this chronology is almost identical to the ISO chronology,
 * thus we recommend using ISOChronology instead, which is the default.
 *
 * @return the Gregorian chronology
 * @deprecated Use GregorianChronology.getInstance()
 */
+ (HLChronology*)gregorian;

/**
 * Gets an instance of the GregorianChronology in the UTC zone.
 * <p>
 * {@link GregorianChronology} defines all fields using standard meanings.
 * It uses the Gregorian calendar rules <i>for all time</i> (proleptic)
 * thus it is NOT a replacement for <code>GregorianCalendar</code>.
 * For that purpose, you should use {@link #getGJ()}.
 * <p>
 * The Gregorian calendar system defines a leap year every four years,
 * except that every 100 years is not leap, but every 400 is leap.
 * <p>
 * Technically, this chronology is almost identical to the ISO chronology,
 * thus we recommend using ISOChronology instead, which is the default.
 *
 * @return the Gregorian chronology
 * @deprecated Use GregorianChronology.getInstanceUTC()
 */
+ (HLChronology*)gregorianUTC;

/**
 * Gets an instance of the GregorianChronology in the specified zone.
 * <p>
 * {@link GregorianChronology} defines all fields using standard meanings.
 * It uses the Gregorian calendar rules <i>for all time</i> (proleptic)
 * thus it is NOT a replacement for <code>GregorianCalendar</code>.
 * For that purpose, you should use {@link #getGJ()}.
 * <p>
 * The Gregorian calendar system defines a leap year every four years,
 * except that every 100 years is not leap, but every 400 is leap.
 * <p>
 * Technically, this chronology is almost identical to the ISO chronology,
 * thus we recommend using ISOChronology instead, which is the default.
 *
 * @param zone  the zone to use, nil means default zone
 * @return the Gregorian chronology
 * @deprecated Use GregorianChronology.getInstance(zone)
 */
+ (HLChronology*)gregorianWithDateTimeZone:(HLDateTimeZone*)zone;

//-----------------------------------------------------------------------
/**
 * Gets an instance of the JulianChronology in the default zone.
 * <p>
 * {@link JulianChronology} defines all fields using standard meanings.
 * It uses the Julian calendar rules <i>for all time</i> (proleptic).
 * The Julian calendar system defines a leap year every four years.
 *
 * @return the Julian chronology
 * @deprecated Use JulianChronology.getInstance()
 */
+ (HLChronology*)julian;

/**
 * Gets an instance of the JulianChronology in the UTC zone.
 * <p>
 * {@link JulianChronology} defines all fields using standard meanings.
 * It uses the Julian calendar rules <i>for all time</i> (proleptic).
 * The Julian calendar system defines a leap year every four years.
 *
 * @return the Julian chronology
 * @deprecated Use JulianChronology.getInstanceUTC()
 */
+ (HLChronology*)julianUTC;

/**
 * Gets an instance of the JulianChronology in the specified zone.
 * <p>
 * {@link JulianChronology} defines all fields using standard meanings.
 * It uses the Julian calendar rules <i>for all time</i> (proleptic).
 * The Julian calendar system defines a leap year every four years.
 *
 * @param zone  the zone to use, nil means default zone
 * @return the Julian chronology
 * @deprecated Use JulianChronology.getInstance(zone)
 */
+ (HLChronology*)julian:(HLDateTimeZone*)zone;

//-----------------------------------------------------------------------
/**
 * Gets an instance of the BuddhistChronology in the default zone.
 * <p>
 * {@link BuddhistChronology} defines all fields using standard meanings,
 * however the year is offset by 543. The chronology cannot be used before
 * year 1 in the Buddhist calendar.
 *
 * @return the Buddhist chronology
 * @deprecated Use BuddhistChronology.getInstance()
 */
+ (HLChronology*)buddhist;

/**
 * Gets an instance of the BuddhistChronology in the UTC zone.
 * <p>
 * {@link BuddhistChronology} defines all fields using standard meanings,
 * however the year is offset by 543. The chronology cannot be used before
 * year 1 in the Buddhist calendar.
 *
 * @return the Buddhist chronology
 * @deprecated Use BuddhistChronology.getInstanceUTC()
 */
+ (HLChronology*)buddhistUTC;

/**
 * Gets an instance of the BuddhistChronology in the specified zone.
 * <p>
 * {@link BuddhistChronology} defines all fields using standard meanings,
 * however the year is offset by 543. The chronology cannot be used before
 * year 1 in the Buddhist calendar.
 *
 * @param zone  the zone to use, nil means default zone
 * @return the Buddhist chronology
 * @deprecated Use BuddhistChronology.getInstance(zone)
 */
+ (HLChronology*)buddhistWithDateTimeZone:(HLDateTimeZone*)zone;

//-----------------------------------------------------------------------
/**
 * Gets an instance of the CopticChronology in the default zone.
 * <p>
 * {@link CopticChronology} defines fields sensibly for the Coptic calendar system.
 * The Coptic calendar system defines every fourth year as leap.
 * The year is broken down into 12 months, each 30 days in length.
 * An extra period at the end of the year is either 5 or 6 days in length
 * and is returned as a 13th month.
 * Year 1 in the Coptic calendar began on August 29, 284 CE (Julian).
 * The chronology cannot be used before the first Coptic year.
 *
 * @return the Coptic chronology
 * @deprecated Use CopticChronology.getInstance()
 */
+ (HLChronology*)coptic;

/**
 * Gets an instance of the CopticChronology in the UTC zone.
 * <p>
 * {@link CopticChronology} defines fields sensibly for the Coptic calendar system.
 * The Coptic calendar system defines every fourth year as leap.
 * The year is broken down into 12 months, each 30 days in length.
 * An extra period at the end of the year is either 5 or 6 days in length
 * and is returned as a 13th month.
 * Year 1 in the Coptic calendar began on August 29, 284 CE (Julian).
 * The chronology cannot be used before the first Coptic year.
 *
 * @return the Coptic chronology
 * @deprecated Use CopticChronology.getInstanceUTC()
 */
+ (HLChronology*)copticUTC;

/**
 * Gets an instance of the CopticChronology in the specified zone.
 * <p>
 * {@link CopticChronology} defines fields sensibly for the Coptic calendar system.
 * The Coptic calendar system defines every fourth year as leap.
 * The year is broken down into 12 months, each 30 days in length.
 * An extra period at the end of the year is either 5 or 6 days in length
 * and is returned as a 13th month.
 * Year 1 in the Coptic calendar began on August 29, 284 CE (Julian).
 * The chronology cannot be used before the first Coptic year.
 *
 * @param zone  the zone to use, nil means default zone
 * @return the Coptic chronology
 * @deprecated Use CopticChronology.getInstance(zone)
 */
+ (HLChronology*)copticWithDateTimeZone:(HLDateTimeZone*)zone;

//-----------------------------------------------------------------------
/**
 * Returns the DateTimeZone that this Chronology operates in, or nil if
 * unspecified.
 *
 * @return the DateTimeZone, nil if unspecified
 */
- (HLDateTimeZone*)dateTimeZone;

/**
 * Returns an instance of this Chronology that operates in the UTC time
 * zone. Chronologies that do not operate in a time zone or are already
 * UTC must return themself.
 *
 * @return a version of this chronology that ignores time zones
 */
- (HLChronology*)withUTC;

/**
 * Returns an instance of this Chronology that operates in any time zone.
 *
 * @return a version of this chronology with a specific time zone
 * @param zone to use, or default if nil
 * @see org.joda.time.chrono.ZonedChronology
 */
- (HLChronology*)withZone:(HLDateTimeZone*)zone;

/**
 * Returns a datetime millisecond instant, formed from the given year,
 * month, day, and millisecond values. The set of given values must refer
 * to a valid datetime, or else an IllegalArgumentException is thrown.
 * <p>
 * The default implementation calls upon separate DateTimeFields to
 * determine the result. Subclasses are encouraged to provide a more
 * efficient implementation.
 *
 * @param year year to use
 * @param monthOfYear month to use
 * @param dayOfMonth day of month to use
 * @param millisOfDay millisecond to use
 * @return millisecond instant from 1970-01-01T00:00:00Z
 * @throws IllegalArgumentException if the values are invalid
 */
- (NSInteger)dateTimeMillisWithYear:(NSInteger)year 
                        monthOfYear:(NSInteger)monthOfYear 
                         dayOfMonth:(NSInteger)dayOfMonth 
                        millisOfDay:(NSInteger)millisOfDay;

/**
 * Returns a datetime millisecond instant, formed from the given year,
 * month, day, hour, minute, second, and millisecond values. The set of
 * given values must refer to a valid datetime, or else an
 * IllegalArgumentException is thrown.
 * <p>
 * The default implementation calls upon separate DateTimeFields to
 * determine the result. Subclasses are encouraged to provide a more
 * efficient implementation.
 *
 * @param year year to use
 * @param monthOfYear month to use
 * @param dayOfMonth day of month to use
 * @param hourOfDay hour to use
 * @param minuteOfHour minute to use
 * @param secondOfMinute second to use
 * @param millisOfSecond millisecond to use
 * @return millisecond instant from 1970-01-01T00:00:00Z
 * @throws IllegalArgumentException if the values are invalid
 */
- (NSInteger)dateTimeMillisWithYear:(NSInteger)year 
                        monthOfYear:(NSInteger)monthOfYear 
                         dayOfMonth:(NSInteger)dayOfMonth
                          hourOfDay:(NSInteger)hourOfDay 
                       minuteOfHour:(NSInteger)minuteOfHour
                     secondOfMinute:(NSInteger)secondOfMinute 
                     millisOfSecond:(NSInteger)millisOfSecond;

/**
 * Returns a datetime millisecond instant, from from the given instant,
 * hour, minute, second, and millisecond values. The set of given values
 * must refer to a valid datetime, or else an IllegalArgumentException is
 * thrown.
 * <p>
 * The default implementation calls upon separate DateTimeFields to
 * determine the result. Subclasses are encouraged to provide a more
 * efficient implementation.
 *
 * @param instant instant to start from
 * @param hourOfDay hour to use
 * @param minuteOfHour minute to use
 * @param secondOfMinute second to use
 * @param millisOfSecond millisecond to use
 * @return millisecond instant from 1970-01-01T00:00:00Z
 * @throws IllegalArgumentException if the values are invalid
 */
- (NSInteger)dateTimeMillisUsingInstant:(NSInteger)instant
                              hourOfDay:(NSInteger)hourOfDay 
                           minuteOfHour:(NSInteger)minuteOfHour
                         secondOfMinute:(NSInteger)secondOfMinute 
                         millisOfSecond:(NSInteger)millisOfSecond;

//-----------------------------------------------------------------------
/**
 * Validates whether the values are valid for the fields of a partial instant.
 *
 * @param partial  the partial instant to validate
 * @param values  the values to validate, not nil, match fields in partial
 * @throws IllegalArgumentException if the instant is invalid
 */
- (void)validatePartial:(id<HLReadablePartial>)partial
            usingValues:(NSArray*)values;

/**
 * Gets the values of a partial from an instant.
 *
 * @param partial  the partial instant to use
 * @param instant  the instant to query
 * @return the values of this partial extracted from the instant
 */
- (NSArray*)valuesOfPartial:(id<HLReadablePartial>)partial 
                fromInstant:(NSInteger)instant;

/**
 * Sets the partial into the instant.
 *
 * @param partial  the partial instant to use
 * @param instant  the instant to update
 * @return the updated instant
 */
- (NSInteger)setPartial:(id<HLReadablePartial>)partial 
            intoInstant:(NSInteger)instant;

//-----------------------------------------------------------------------
/**
 * Gets the values of a period from an interval.
 *
 * @param period  the period instant to use
 * @param startInstant  the start instant of an interval to query
 * @param endInstant  the start instant of an interval to query
 * @return the values of the period extracted from the interval
 */
- (NSArray*)valuesOfPeriod:(id<HLReadablePeriod>)period 
         startInstantValue:(NSInteger)startInstant 
           endInstantValue:(NSInteger)endInstant;

/**
 * Gets the values of a period from an interval.
 *
 * @param period  the period instant to use
 * @param duration  the duration to query
 * @return the values of the period extracted from the duration
 */
- (NSArray*)valuesOfPeriod:(id<HLReadablePeriod>)period 
              fromDuration:(NSInteger)duration;

/**
 * Adds the period to the instant, specifying the number of times to add.
 *
 * @param period  the period to add, nil means add nothing
 * @param instant  the instant to add to
 * @param scalar  the number of times to add
 * @return the updated instant
 */
- (NSInteger)addPeriod:(id<HLReadablePeriod>)period 
             toInstant:(NSInteger)instant 
           usingScalar:(NSInteger)scalar;

//-----------------------------------------------------------------------
/**
 * Adds the duration to the instant, specifying the number of times to add.
 *
 * @param instant  the instant to add to
 * @param duration  the duration to add
 * @param scalar  the number of times to add
 * @return the updated instant
 */
- (NSInteger)addDuration:(NSInteger)duration 
          toInstantValue:(NSInteger)instant 
             usingScalar:(NSInteger)scalar;

// Millis
//-----------------------------------------------------------------------
/**
 * Get the millis duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)millis;

/**
 * Get the millis of second field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)millisOfSecond;

/**
 * Get the millis of day field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)millisOfDay;

// Second
//-----------------------------------------------------------------------
/**
 * Get the seconds duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)seconds;

/**
 * Get the second of minute field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)secondOfMinute;

/**
 * Get the second of day field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)secondOfDay;

// Minute
//-----------------------------------------------------------------------
/**
 * Get the minutes duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)minutes;

/**
 * Get the minute of hour field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)minuteOfHour;

/**
 * Get the minute of day field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)minuteOfDay;

// Hour
//-----------------------------------------------------------------------
/**
 * Get the hours duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)hours;

/**
 * Get the hour of day (0-23) field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)hourOfDay;

/**
 * Get the hour of day (offset to 1-24) field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)clockhourOfDay;

// Halfday
//-----------------------------------------------------------------------
/**
 * Get the halfdays duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)halfdays;

/**
 * Get the hour of am/pm (0-11) field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)hourOfHalfday;

/**
 * Get the hour of am/pm (offset to 1-12) field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)clockhourOfHalfday;

/**
 * Get the AM(0) PM(1) field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)halfdayOfDay;

// Day
//-----------------------------------------------------------------------
/**
 * Get the days duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)days;

/**
 * Get the day of week field for this chronology.
 *
 * <p>DayOfWeek values are defined in {@link DateTimeConstants}.
 * They use the ISO definitions, where 1 is Monday and 7 is Sunday.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)dayOfWeek;

/**
 * Get the day of month field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)dayOfMonth;

/**
 * Get the day of year field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)dayOfYear;

// Week
//-----------------------------------------------------------------------
/**
 * Get the weeks duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)weeks;

/**
 * Get the week of a week based year field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)weekOfWeekyear;

// Weekyear
//-----------------------------------------------------------------------
/**
 * Get the weekyears duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)weekyears;

/**
 * Get the year of a week based year field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)weekyear;

/**
 * Get the year of a week based year in a century field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)weekyearOfCentury;

// Month
//-----------------------------------------------------------------------
/**
 * Get the months duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)months;

/**
 * Get the month of year field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)monthOfYear;

// Year
//-----------------------------------------------------------------------
/**
 * Get the years duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)years;

/**
 * Get the year field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)year;

/**
 * Get the year of era field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)yearOfEra;

/**
 * Get the year of century field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)yearOfCentury;

// Century
//-----------------------------------------------------------------------
/**
 * Get the centuries duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)centuries;

/**
 * Get the century of era field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)centuryOfEra;

// Era
//-----------------------------------------------------------------------
/**
 * Get the eras duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)eras;

/**
 * Get the era field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)era;

//-----------------------------------------------------------------------
/**
 * Gets a debugging toString.
 * 
 * @return a debugging string
 */
- (NSString*)description;

@end
