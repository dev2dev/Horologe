/*
 * Interval.h
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

#import "HLBaseInterval.h"
#import "HLReadableInterval.h"


@class HLChronology;
@class HLDateTimeZone;
@protocol HLReadablePeriod;

/**
 * Interval is the standard implementation of an immutable time interval.
 * <p>
 * A time interval represents a period of time between two instants.
 * Intervals are inclusive of the start instant and exclusive of the end.
 * The end instant is always greater than or equal to the start instant.
 * <p>
 * Intervals have a fixed millisecond duration.
 * This is the difference between the start and end instants.
 * The duration is represented separately by {@link ReadableDuration}.
 * As a result, intervals are not comparable.
 * To compare the length of two intervals, you should compare their durations.
 * <p>
 * An interval can also be converted to a {@link ReadablePeriod}.
 * This represents the difference between the start and end points in terms of fields
 * such as years and days.
 * <p>
 * Interval is thread-safe and immutable.
 *
 * @author Brian S O'Neill
 * @author Sean Geoghegan
 * @author Stephen Colebourne
 * @author Julen Parra
 * @since 1.0
 */
@interface HLInterval : HLBaseInterval <HLReadableInterval> {
    
@private
    
}

//-----------------------------------------------------------------------
/**
 * Constructs an interval from a start and end instant with the ISO
 * default chronology in the default time zone.
 * 
 * @param startInstant  start of this interval, as milliseconds from 1970-01-01T00:00:00Z.
 * @param endInstant  end of this interval, as milliseconds from 1970-01-01T00:00:00Z.
 * @throws IllegalArgumentException if the end is before the start
 */
- (id)initWithStart:(NSInteger)startInstant 
                end:(NSInteger)endInstant;

/**
 * Constructs an interval from a start and end instant with the ISO
 * default chronology in the specified time zone.
 * 
 * @param startInstant  start of this interval, as milliseconds from 1970-01-01T00:00:00Z.
 * @param endInstant  end of this interval, as milliseconds from 1970-01-01T00:00:00Z.
 * @param zone  the time zone to use, nil means default zone
 * @throws IllegalArgumentException if the end is before the start
 * @since 1.5
 */
- (id)initWithStart:(NSInteger)startInstant 
                end:(NSInteger)endInstant
               zone:(HLDateTimeZone*)zone;

/**
 * Constructs an interval from a start and end instant with the
 * specified chronology.
 * 
 * @param chronology  the chronology to use, nil is ISO default
 * @param startInstant  start of this interval, as milliseconds from 1970-01-01T00:00:00Z.
 * @param endInstant  end of this interval, as milliseconds from 1970-01-01T00:00:00Z.
 * @throws IllegalArgumentException if the end is before the start
 */
- (id)initWithStart:(NSInteger)startInstant 
                end:(NSInteger)endInstant
         chronology:(HLChronology*)chronology;

/**
 * Constructs an interval from a start and end instant.
 * <p>
 * The chronology used is that of the start instant.
 * 
 * @param start  start of this interval, nil means now
 * @param end  end of this interval, nil means now
 * @throws IllegalArgumentException if the end is before the start
 */
- (id)initWithStartInstant:(id<HLReadableInstant>)start
                endInstant:(id<HLReadableInstant>)end;

/**
 * Constructs an interval from a start instant and a duration.
 * 
 * @param start  start of this interval, nil means now
 * @param duration  the duration of this interval, nil means zero length
 * @throws IllegalArgumentException if the end is before the start
 * @throws ArithmeticException if the end instant exceeds the capacity of a long
 */
- (id)initWithStartInstant:(id<HLReadableInstant>)start
                  duration:(id<HLReadableDuration>)duration;

/**
 * Constructs an interval from a millisecond duration and an end instant.
 * 
 * @param duration  the duration of this interval, nil means zero length
 * @param end  end of this interval, nil means now
 * @throws IllegalArgumentException if the end is before the start
 * @throws ArithmeticException if the start instant exceeds the capacity of a long
 */
- (id)initWithDuration:(id<HLReadableDuration>)duration
                   end:(id<HLReadableInstant>)end;

/**
 * Constructs an interval from a start instant and a time period.
 * <p>
 * When forming the interval, the chronology from the instant is used
 * if present, otherwise the chronology of the period is used.
 * 
 * @param start  start of this interval, nil means now
 * @param period  the period of this interval, nil means zero length
 * @throws IllegalArgumentException if the end is before the start
 * @throws ArithmeticException if the end instant exceeds the capacity of a long
 */
- (id)initWithStartInstant:(id<HLReadableInstant>)start
                    period:(id<HLReadablePeriod>)period;

/**
 * Constructs an interval from a time period and an end instant.
 * <p>
 * When forming the interval, the chronology from the instant is used
 * if present, otherwise the chronology of the period is used.
 * 
 * @param period  the period of this interval, nil means zero length
 * @param end  end of this interval, nil means now
 * @throws IllegalArgumentException if the end is before the start
 * @throws ArithmeticException if the start instant exceeds the capacity of a long
 */
- (id)initWithPeriod:(id<HLReadablePeriod>)period
                 end:(id<HLReadableInstant>)end;

/**
 * Constructs a time interval by converting or copying from another object.
 * <p>
 * The recognised object types are defined in
 * {@link org.joda.time.convert.ConverterManager ConverterManager} and
 * include ReadableInterval and String.
 * The String formats are described by {@link ISODateTimeFormat#dateTimeParser()}
 * and {@link ISOPeriodFormat#standard()}, and may be 'datetime/datetime',
 * 'datetime/period' or 'period/datetime'.
 * 
 * @param interval  the time interval to copy
 * @throws IllegalArgumentException if the interval is invalid
 */
- (id)initWithInterval:(id)interval;

/**
 * Constructs a time interval by converting or copying from another object,
 * overriding the chronology.
 * <p>
 * The recognised object types are defined in
 * {@link org.joda.time.convert.ConverterManager ConverterManager} and
 * include ReadableInterval and String.
 * The String formats are described by {@link ISODateTimeFormat#dateTimeParser()}
 * and {@link ISOPeriodFormat#standard()}, and may be 'datetime/datetime',
 * 'datetime/period' or 'period/datetime'.
 * 
 * @param interval  the time interval to copy
 * @param chronology  the chronology to use, nil means ISO default
 * @throws IllegalArgumentException if the interval is invalid
 */
- (id)initWithInterval:(id)interval
            chronology:(HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 * Get this interval as an immutable <code>Interval</code> object
 * by returning <code>this</code>.
 *
 * @return <code>this</code>
 */
- (HLInterval*)toInterval;

//-----------------------------------------------------------------------
/**
 * Gets the overlap between this interval and another interval.
 * <p>
 * Intervals are inclusive of the start instant and exclusive of the end.
 * An interval overlaps another if it shares some common part of the
 * datetime continuum. This method returns the amount of the overlap,
 * only if the intervals actually do overlap.
 * If the intervals do not overlap, then nil is returned.
 * <p>
 * When two intervals are compared the result is one of three states:
 * (a) they abut, (b) there is a gap between them, (c) they overlap.
 * The abuts state takes precedence over the other two, thus a zero duration
 * interval at the start of a larger interval abuts and does not overlap.
 * <p>
 * The chronology of the returned interval is the same as that of
 * this interval (the chronology of the interval parameter is not used).
 * Note that the use of the chronology was only correctly implemented
 * in version 1.3.
 *
 * @param interval  the interval to examine, nil means now
 * @return the overlap interval, nil if no overlap
 * @since 1.1
 */
- (HLInterval*)overlap:(id<HLReadableInterval>)interval;

//-----------------------------------------------------------------------
/**
 * Gets the gap between this interval and another interval.
 * The other interval can be either before or after this interval.
 * <p>
 * Intervals are inclusive of the start instant and exclusive of the end.
 * An interval has a gap to another interval if there is a non-zero
 * duration between them. This method returns the amount of the gap only
 * if the intervals do actually have a gap between them.
 * If the intervals overlap or abut, then nil is returned.
 * <p>
 * When two intervals are compared the result is one of three states:
 * (a) they abut, (b) there is a gap between them, (c) they overlap.
 * The abuts state takes precedence over the other two, thus a zero duration
 * interval at the start of a larger interval abuts and does not overlap.
 * <p>
 * The chronology of the returned interval is the same as that of
 * this interval (the chronology of the interval parameter is not used).
 * Note that the use of the chronology was only correctly implemented
 * in version 1.3.
 *
 * @param interval  the interval to examine, nil means now
 * @return the gap interval, nil if no gap
 * @since 1.1
 */
- (HLInterval*)gap:(id<HLReadableInterval>)interval;

//-----------------------------------------------------------------------
/**
 * Does this interval abut with the interval specified.
 * <p>
 * Intervals are inclusive of the start instant and exclusive of the end.
 * An interval abuts if it starts immediately after, or ends immediately
 * before this interval without overlap.
 * A zero duration interval abuts with itself.
 * <p>
 * When two intervals are compared the result is one of three states:
 * (a) they abut, (b) there is a gap between them, (c) they overlap.
 * The abuts state takes precedence over the other two, thus a zero duration
 * interval at the start of a larger interval abuts and does not overlap.
 * <p>
 * For example:
 * <pre>
 * [09:00 to 10:00) abuts [08:00 to 08:30)  = false (completely before)
 * [09:00 to 10:00) abuts [08:00 to 09:00)  = true
 * [09:00 to 10:00) abuts [08:00 to 09:01)  = false (overlaps)
 * 
 * [09:00 to 10:00) abuts [09:00 to 09:00)  = true
 * [09:00 to 10:00) abuts [09:00 to 09:01)  = false (overlaps)
 * 
 * [09:00 to 10:00) abuts [10:00 to 10:00)  = true
 * [09:00 to 10:00) abuts [10:00 to 10:30)  = true
 * 
 * [09:00 to 10:00) abuts [10:30 to 11:00)  = false (completely after)
 * 
 * [14:00 to 14:00) abuts [14:00 to 14:00)  = true
 * [14:00 to 14:00) abuts [14:00 to 15:00)  = true
 * [14:00 to 14:00) abuts [13:00 to 14:00)  = true
 * </pre>
 *
 * @param interval  the interval to examine, nil means now
 * @return true if the interval abuts
 * @since 1.1
 */
- (BOOL)abuts:(id<HLReadableInterval>)interval;

//-----------------------------------------------------------------------
/**
 * Creates a new interval with the same start and end, but a different chronology.
 *
 * @param chronology  the chronology to use, nil means ISO default
 * @return an interval with a different chronology
 */
- (HLInterval*)withChronology:(HLChronology*)chronology;

/**
 * Creates a new interval with the specified start millisecond instant.
 *
 * @param startInstant  the start instant for the new interval
 * @return an interval with the end from this interval and the specified start
 * @throws IllegalArgumentException if the resulting interval has end before start
 */
- (HLInterval*)withStartMillis:(NSInteger)startInstant;

/**
 * Creates a new interval with the specified start instant.
 *
 * @param start  the start instant for the new interval, nil means now
 * @return an interval with the end from this interval and the specified start
 * @throws IllegalArgumentException if the resulting interval has end before start
 */
- (HLInterval*)withStart:(id<HLReadableInstant>)start;

/**
 * Creates a new interval with the specified start millisecond instant.
 *
 * @param endInstant  the end instant for the new interval
 * @return an interval with the start from this interval and the specified end
 * @throws IllegalArgumentException if the resulting interval has end before start
 */
- (HLInterval*)withEndMillis:(NSInteger)endInstant;

/**
 * Creates a new interval with the specified end instant.
 *
 * @param end  the end instant for the new interval, nil means now
 * @return an interval with the start from this interval and the specified end
 * @throws IllegalArgumentException if the resulting interval has end before start
 */
- (HLInterval*)withEnd:(id<HLReadableInstant>)end;

//-----------------------------------------------------------------------
/**
 * Creates a new interval with the specified duration after the start instant.
 *
 * @param duration  the duration to add to the start to get the new end instant, nil means zero
 * @return an interval with the start from this interval and a calculated end
 * @throws IllegalArgumentException if the duration is negative
 */
- (HLInterval*)withDurationAfterStart:(id<HLReadableDuration>)duration;

/**
 * Creates a new interval with the specified duration before the end instant.
 *
 * @param duration  the duration to add to the start to get the new end instant, nil means zero
 * @return an interval with the start from this interval and a calculated end
 * @throws IllegalArgumentException if the duration is negative
 */
- (HLInterval*)withDurationBeforeEnd:(id<HLReadableDuration>)duration;

//-----------------------------------------------------------------------
/**
 * Creates a new interval with the specified period after the start instant.
 *
 * @param period  the period to add to the start to get the new end instant, nil means zero
 * @return an interval with the start from this interval and a calculated end
 * @throws IllegalArgumentException if the period is negative
 */
- (HLInterval*)withPeriodAfterStart:(id<HLReadablePeriod>)period;

/**
 * Creates a new interval with the specified period before the end instant.
 *
 * @param period  the period to add to the start to get the new end instant, nil means zero
 * @return an interval with the start from this interval and a calculated end
 * @throws IllegalArgumentException if the period is negative
 */
- (HLInterval*)withPeriodBeforeEnd:(id<HLReadablePeriod>)period;

@end
