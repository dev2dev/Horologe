/*
 * BaseInterval.h
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

#import "HLAbstractInterval.h"
#import "HLReadableInterval.h"


@class HLChronology;
@protocol HLReadablePeriod;
@protocol HLReadableInstant;

/**
 * BaseInterval is an abstract implementation of ReadableInterval that stores
 * data in two <code>long</code> millisecond fields.
 * <p>
 * This class should generally not be used directly by API users.
 * The {@link ReadableInterval} interface should be used when different 
 * kinds of interval objects are to be referenced.
 * <p>
 * BaseInterval subclasses may be mutable and not thread-safe.
 *
 * @author Brian S O'Neill
 * @author Sean Geoghegan
 * @author Stephen Colebourne
 * @since 1.0
 */
@interface HLBaseInterval {
    
@private
    /** The chronology of the interval */
    HLChronology* _iChronology;
    /** The start of the interval */
    NSInteger _iStartMillis;
    /** The end of the interval */
    NSInteger _iEndMillis;
    
}

/**
 * Constructs an interval from a start and end instant.
 * 
 * @param startInstant  start of this interval, as milliseconds from 1970-01-01T00:00:00Z.
 * @param endInstant  end of this interval, as milliseconds from 1970-01-01T00:00:00Z.
 * @param chrono  the chronology to use, nil is ISO default
 * @throws IllegalArgumentException if the end is before the start
 */
- (id)initWithStartInstantValue:(NSInteger)startInstant 
                endInstantValue:(NSInteger)endInstant
                     chronology:(HLChronology*)chrono;

/**
 * Constructs an interval from a start and end instant.
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
            endInstant:(id<HLReadableInstant>)end;

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
          endInstant:(id<HLReadableInstant>)end;

/**
 * Constructs a time interval converting or copying from another object
 * that describes an interval.
 * 
 * @param interval  the time interval to copy
 * @param chrono  the chronology to use, nil means let converter decide
 * @throws IllegalArgumentException if the interval is invalid
 */
- (id)initWithInterval:(id)interval
            chronology:(HLChronology*)chrono;

//-----------------------------------------------------------------------
/**
 * Gets the chronology of this interval.
 *
 * @return the chronology
 */
- (HLChronology*)chronology;

/**
 * Gets the start of this time interval which is inclusive.
 *
 * @return the start of the time interval,
 *  millisecond instant from 1970-01-01T00:00:00Z
 */
- (NSInteger)startMillis;

/**
 * Gets the end of this time interval which is exclusive.
 *
 * @return the end of the time interval,
 *  millisecond instant from 1970-01-01T00:00:00Z
 */
- (NSInteger)endMillis;

//-----------------------------------------------------------------------
/**
 * Sets this interval from two millisecond instants and a chronology.
 *
 * @param startInstant  the start of the time interval
 * @param endInstant  the start of the time interval
 * @param chrono  the chronology, not nil
 * @throws IllegalArgumentException if the end is before the start
 */
- (void)setIntervalStart:(NSInteger)startInstant 
                     end:(NSInteger)endInstant
              chronology:(HLChronology*)chrono;

@end
