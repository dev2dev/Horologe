/*
 * HLChronology.m
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

#import "HLChronology.h"


@implementation HLChronology

/**
 * Returns the DateTimeZone that this Chronology operates in, or null if
 * unspecified.
 *
 * @return the DateTimeZone, null if unspecified
 */
- (HLDateTimeZone*)dateTimeZone {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Returns an instance of this Chronology that operates in the UTC time
 * zone. Chronologies that do not operate in a time zone or are already
 * UTC must return themself.
 *
 * @return a version of this chronology that ignores time zones
 */
- (HLChronology*)withUTC {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Returns an instance of this Chronology that operates in any time zone.
 *
 * @return a version of this chronology with a specific time zone
 * @param zone to use, or default if null
 * @see org.joda.time.chrono.ZonedChronology
 */
- (HLChronology*)withDateTimeZone:(HLDateTimeZone*)zone {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

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
- (NSInteger)getDateTimeMillis:(NSInteger)year 
                   monthOfYear:(NSInteger)monthOfYear 
                    dayOfMonth:(NSInteger)dayOfMonth 
                   millisOfDay:(NSInteger)millisOfDay {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return 0;
}

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
- (NSInteger)getDateTimeMillis:(NSInteger)year 
                   monthOfYear:(NSInteger)monthOfYear 
                    dayOfMonth:(NSInteger)dayOfMonth
                     hourOfDay:(NSInteger)hourOfDay 
                  minuteOfHour:(NSInteger)minuteOfHour
                secondOfMinute:(NSInteger)secondOfMinute 
                millisOfSecond:(NSInteger)millisOfSecond {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return 0;
}

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
- (NSInteger)getDateTimeMillis:(NSInteger)instant
                     hourOfDay:(NSInteger)hourOfDay 
                  minuteOfHour:(NSInteger)minuteOfHour
                secondOfMinute:(NSInteger)secondOfMinute 
                millisOfSecond:(NSInteger)millisOfSecond {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return 0;
}

//-----------------------------------------------------------------------
/**
 * Validates whether the values are valid for the fields of a partial instant.
 *
 * @param partial  the partial instant to validate
 * @param values  the values to validate, not null, match fields in partial
 * @throws IllegalArgumentException if the instant is invalid
 */
- (void)validate:(id<HLReadablePartial>)partial 
          values:(NSArray*)values {
    [NSException raise:@"TODO" format:@"Method not implemented."];
}

/**
 * Gets the values of a partial from an instant.
 *
 * @param partial  the partial instant to use
 * @param instant  the instant to query
 * @return the values of this partial extracted from the instant
 */
- (NSArray*)get:(id<HLReadablePartial>)partial 
        instant:(NSInteger)instant {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Sets the partial into the instant.
 *
 * @param partial  the partial instant to use
 * @param instant  the instant to update
 * @return the updated instant
 */
- (NSInteger)set:(id<HLReadablePartial>)partial 
         instant:(NSInteger)instant {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return 0;
}

//-----------------------------------------------------------------------
/**
 * Gets the values of a period from an interval.
 *
 * @param period  the period instant to use
 * @param startInstant  the start instant of an interval to query
 * @param endInstant  the start instant of an interval to query
 * @return the values of the period extracted from the interval
 */
- (NSArray*)get:(id<HLReadablePeriod>)period 
   startInstant:(NSInteger)startInstant 
     endInstant:(NSInteger)endInstant {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Gets the values of a period from an interval.
 *
 * @param period  the period instant to use
 * @param duration  the duration to query
 * @return the values of the period extracted from the duration
 */
- (NSArray*)get:(id<HLReadablePeriod>)period 
       duration:(NSInteger)duration {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Adds the period to the instant, specifying the number of times to add.
 *
 * @param period  the period to add, null means add nothing
 * @param instant  the instant to add to
 * @param scalar  the number of times to add
 * @return the updated instant
 */
- (NSInteger)addPeriod:(id<HLReadablePeriod>)period 
               instant:(NSInteger)instant 
                scalar:(NSInteger)scalar {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return 0;
}

//-----------------------------------------------------------------------
/**
 * Adds the duration to the instant, specifying the number of times to add.
 *
 * @param instant  the instant to add to
 * @param duration  the duration to add
 * @param scalar  the number of times to add
 * @return the updated instant
 */
- (NSInteger)add:(NSInteger)instant 
        duration:(NSInteger)duration 
          scalar:(NSInteger)scalar {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return 0;
}

// Millis
//-----------------------------------------------------------------------
/**
 * Get the millis duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)millis {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the millis of second field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)millisOfSecond {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the millis of day field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)millisOfDay {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

// Second
//-----------------------------------------------------------------------
/**
 * Get the seconds duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)seconds {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the second of minute field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)secondOfMinute {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the second of day field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)secondOfDay {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

// Minute
//-----------------------------------------------------------------------
/**
 * Get the minutes duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)minutes {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the minute of hour field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)minuteOfHour {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the minute of day field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)minuteOfDay {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

// Hour
//-----------------------------------------------------------------------
/**
 * Get the hours duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)hours {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the hour of day (0-23) field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)hourOfDay {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the hour of day (offset to 1-24) field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)clockhourOfDay {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

// Halfday
//-----------------------------------------------------------------------
/**
 * Get the halfdays duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)halfdays {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the hour of am/pm (0-11) field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)hourOfHalfday {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the hour of am/pm (offset to 1-12) field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)clockhourOfHalfday {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the AM(0) PM(1) field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)halfdayOfDay {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

// Day
//-----------------------------------------------------------------------
/**
 * Get the days duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)days {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the day of week field for this chronology.
 *
 * <p>DayOfWeek values are defined in {@link DateTimeConstants}.
 * They use the ISO definitions, where 1 is Monday and 7 is Sunday.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)dayOfWeek {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the day of month field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)dayOfMonth {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the day of year field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)dayOfYear {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

// Week
//-----------------------------------------------------------------------
/**
 * Get the weeks duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)weeks {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the week of a week based year field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)weekOfWeekyear {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

// Weekyear
//-----------------------------------------------------------------------
/**
 * Get the weekyears duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)weekyears {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the year of a week based year field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)weekyear {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the year of a week based year in a century field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)weekyearOfCentury {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

// Month
//-----------------------------------------------------------------------
/**
 * Get the months duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)months {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the month of year field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)monthOfYear {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

// Year
//-----------------------------------------------------------------------
/**
 * Get the years duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)years {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the year field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)year {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the year of era field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)yearOfEra {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the year of century field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)yearOfCentury {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

// Century
//-----------------------------------------------------------------------
/**
 * Get the centuries duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)centuries {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the century of era field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)centuryOfEra {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

// Era
//-----------------------------------------------------------------------
/**
 * Get the eras duration field for this chronology.
 * 
 * @return DurationField or UnsupportedDurationField if unsupported
 */
- (HLDurationField*)eras {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

/**
 * Get the era field for this chronology.
 * 
 * @return DateTimeField or UnsupportedDateTimeField if unsupported
 */
- (HLDateTimeField*)era {
    [NSException raise:@"TODO" format:@"Method not implemented."];
    return nil;
}

@end
