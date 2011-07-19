/*
 * Duration.h
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

#import "HLBaseDuration.h"
#import "HLReadableDuration.h"


@class HLSeconds;

/**
 * An immutable duration specifying a length of time in milliseconds.
 * <p>
 * A duration is defined by a fixed number of milliseconds.
 * There is no concept of fields, such as days or seconds, as these fields can vary in length.
 * A duration may be converted to a {@link Period} to obtain field values.
 * This conversion will typically cause a loss of precision however.
 * <p>
 * Duration is thread-safe and immutable.
 *
 * @author Brian S O'Neill
 * @author Stephen Colebourne
 * @since 1.0
 */
@interface HLDuration : HLBaseDuration <HLReadableDuration> {
    
@private
    
}

//-----------------------------------------------------------------------
/**
 * Create a duration with the specified number of days assuming that
 * there are the standard number of milliseconds in a day.
 * <p>
 * This method assumes that there are 24 hours in a day,
 * 60 minutes in an hour, 60 seconds in a minute and 1000 milliseconds in
 * a second. This will be true for most days, however days with Daylight
 * Savings changes will not have 24 hours, so use this method with care.
 * <p>
 * A Duration is a representation of an amount of time. If you want to express
 * the concepts of 'days' you should consider using the {@link Days} class.
 *
 * @param days  the number of standard days in this duration
 * @return the duration, never nil
 * @throws ArithmeticException if the days value is too large
 * @since 1.6
 */
+ (HLDuration*)standardDays:(NSInteger)days;

/**
 * Create a duration with the specified number of hours assuming that
 * there are the standard number of milliseconds in an hour.
 * <p>
 * This method assumes that there are 60 minutes in an hour,
 * 60 seconds in a minute and 1000 milliseconds in a second.
 * All currently supplied chronologies use this definition.
 * <p>
 * A Duration is a representation of an amount of time. If you want to express
 * the concepts of 'hours' you should consider using the {@link Hours} class.
 *
 * @param hours  the number of standard hours in this duration
 * @return the duration, never nil
 * @throws ArithmeticException if the hours value is too large
 * @since 1.6
 */
+ (HLDuration*)standardHours:(NSInteger)hours;

/**
 * Create a duration with the specified number of minutes assuming that
 * there are the standard number of milliseconds in a minute.
 * <p>
 * This method assumes that there are 60 seconds in a minute and
 * 1000 milliseconds in a second.
 * All currently supplied chronologies use this definition.
 * <p>
 * A Duration is a representation of an amount of time. If you want to express
 * the concepts of 'minutes' you should consider using the {@link Minutes} class.
 *
 * @param minutes  the number of standard minutes in this duration
 * @return the duration, never nil
 * @throws ArithmeticException if the minutes value is too large
 * @since 1.6
 */
+ (HLDuration*)standardMinutes:(NSInteger)minutes;

/**
 * Create a duration with the specified number of seconds assuming that
 * there are the standard number of milliseconds in a second.
 * <p>
 * This method assumes that there are 1000 milliseconds in a second.
 * All currently supplied chronologies use this definition.
 * <p>
 * A Duration is a representation of an amount of time. If you want to express
 * the concepts of 'seconds' you should consider using the {@link Seconds} class.
 *
 * @param seconds  the number of standard seconds in this duration
 * @return the duration, never nil
 * @throws ArithmeticException if the seconds value is too large
 * @since 1.6
 */
+ (HLDuration*)standardSeconds:(NSInteger)seconds;

//-----------------------------------------------------------------------
/**
 * Creates a duration from the given millisecond duration.
 *
 * @param duration  the duration, in milliseconds
 */
- (id)initWithDurationValue:(NSInteger)duration;

/**
 * Creates a duration from the given interval endpoints.
 *
 * @param startInstant  interval start, in milliseconds
 * @param endInstant  interval end, in milliseconds
 * @throws ArithmeticException if the duration exceeds a 64 bit long
 */
- (id)initWithStartInstantValue:(NSInteger)startInstant 
                endInstantValue:(NSInteger)endInstant;

/**
 * Creates a duration from the given interval endpoints.
 *
 * @param start  interval start, nil means now
 * @param end  interval end, nil means now
 * @throws ArithmeticException if the duration exceeds a 64 bit long
 */
- (id)initWithStartInstant:(id<HLReadableInstant>)start 
                endInstant:(id<HLReadableInstant>)end;

/**
 * Creates a duration from the specified object using the
 * {@link org.joda.time.convert.ConverterManager ConverterManager}.
 *
 * @param duration  duration to convert
 * @throws IllegalArgumentException if duration is invalid
 */
- (id)initWithDuration:(id)duration;

//-----------------------------------------------------------------------
/**
 * Gets the length of this duration in seconds assuming 1000 milliseconds
 * in a second.
 * <p>
 * This returns <code>getMillis() / 1000</code>.
 * The result is an integer division, so 2999 millis returns 2 seconds.
 *
 * @return the length of the duration in standard seconds
 * @since 1.6
 */
- (NSInteger)standardSeconds;

//-----------------------------------------------------------------------
/**
 * Get this duration as an immutable <code>Duration</code> object
 * by returning <code>this</code>.
 * 
 * @return <code>this</code>
 */
- (HLDuration*)toDuration;

/**
 * Converts this duration to a period in seconds assuming 1000 milliseconds
 * in a second.
 * <p>
 * This method allows you to convert between a duration and a period.
 * 
 * @return a period representing the number of standard seconds in this period, never nil
 * @throws ArithmeticException if the number of seconds is too large to be represented
 * @since 1.6
 */
- (HLSeconds*)toStandardSeconds;

//-----------------------------------------------------------------------
/**
 * Creates a new Duration instance with a different milisecond length.
 * 
 * @param duration  the new length of the duration
 * @return the new duration instance
 */
- (HLDuration*)withMillis:(NSInteger)duration;

/**
 * Returns a new duration with this length plus that specified multiplied by the scalar.
 * This instance is immutable and is not altered.
 * <p>
 * If the addition is zero, this instance is returned.
 * 
 * @param durationToAdd  the duration to add to this one
 * @param scalar  the amount of times to add, such as -1 to subtract once
 * @return the new duration instance
 */
- (HLDuration*)withDurationValueAdded:(NSInteger)durationToAdd 
                          usingScalar:(NSInteger)scalar;

/**
 * Returns a new duration with this length plus that specified multiplied by the scalar.
 * This instance is immutable and is not altered.
 * <p>
 * If the addition is zero, this instance is returned.
 * 
 * @param durationToAdd  the duration to add to this one, nil means zero
 * @param scalar  the amount of times to add, such as -1 to subtract once
 * @return the new duration instance
 */
- (HLDuration*)withDurationAdded:(id<HLReadableDuration>)durationToAdd 
                     usingScalar:(NSInteger)scalar;

//-----------------------------------------------------------------------
/**
 * Returns a new duration with this length plus that specified.
 * This instance is immutable and is not altered.
 * <p>
 * If the addition is zero, this instance is returned.
 * 
 * @param amount  the duration to add to this one
 * @return the new duration instance
 */
- (HLDuration*)plus:(NSInteger)amount;

/**
 * Returns a new duration with this length plus that specified.
 * This instance is immutable and is not altered.
 * <p>
 * If the amount is zero, this instance is returned.
 * 
 * @param amount  the duration to add to this one, nil means zero
 * @return the new duration instance
 */
- (HLDuration*)plusDuration:(id<HLReadableDuration>)amount;

/**
 * Returns a new duration with this length minus that specified.
 * This instance is immutable and is not altered.
 * <p>
 * If the addition is zero, this instance is returned.
 * 
 * @param amount  the duration to take away from this one
 * @return the new duration instance
 */
- (HLDuration*)minus:(NSInteger)amount;

/**
 * Returns a new duration with this length minus that specified.
 * This instance is immutable and is not altered.
 * <p>
 * If the amount is zero, this instance is returned.
 * 
 * @param amount  the duration to take away from this one, nil means zero
 * @return the new duration instance
 */
- (HLDuration*)minusDuration:(id<HLReadableDuration>)amount;

@end

extern const HLSeconds* HL_SECONDS_ZERO;

