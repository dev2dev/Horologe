/*
 * Seconds.h
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

#import "HLBaseSingleFieldPeriod.h"


@class HLWeeks;
@class HLDays;
@class HLHours;
@class HLMinutes;
@class HLDuration;
@protocol HLReadableInterval;

/**
 * An immutable time period representing a number of seconds.
 * <p>
 * <code>Seconds</code> is an immutable period that can only store seconds.
 * It does not store years, months or hours for example. As such it is a
 * type-safe way of representing a number of seconds in an application.
 * <p>
 * The number of seconds is set in the constructor, and may be queried using
 * <code>getSeconds()</code>. Basic mathematical operations are provided -
 * <code>plus()</code>, <code>minus()</code>, <code>multipliedBy()</code> and
 * <code>dividedBy()</code>.
 * <p>
 * <code>Seconds</code> is thread-safe and immutable.
 *
 * @author Stephen Colebourne
 * @since 1.4
 */
@interface HLSeconds : HLBaseSingleFieldPeriod {
    
@private
    
}

//-----------------------------------------------------------------------
/**
 * Obtains an instance of <code>Seconds</code> that may be cached.
 * <code>Seconds</code> is immutable, so instances can be cached and shared.
 * This factory method provides access to shared instances.
 *
 * @param seconds  the number of seconds to obtain an instance for
 * @return the instance of Seconds
 */
+ (HLSeconds*)seconds:(NSInteger)seconds;

//-----------------------------------------------------------------------
/**
 * Creates a <code>Seconds</code> representing the number of whole seconds
 * between the two specified datetimes.
 *
 * @param start  the start instant, must not be nil
 * @param end  the end instant, must not be nil
 * @return the period in seconds
 * @throws IllegalArgumentException if the instants are nil or invalid
 */
+ (HLSeconds*)secondsBetweenStartInstant:(id<HLReadableInstant>)start
                              endInstant:(id<HLReadableInstant>)end;

/**
 * Creates a <code>Seconds</code> representing the number of whole seconds
 * between the two specified partial datetimes.
 * <p>
 * The two partials must contain the same fields, for example you can specify
 * two <code>LocalTime</code> objects.
 *
 * @param start  the start partial date, must not be nil
 * @param end  the end partial date, must not be nil
 * @return the period in seconds
 * @throws IllegalArgumentException if the partials are nil or invalid
 */
+ (HLSeconds*)secondsBetweenStartPartial:(id<HLReadablePartial>)start
                              endPartial:(id<HLReadablePartial>)end;

/**
 * Creates a <code>Seconds</code> representing the number of whole seconds
 * in the specified interval.
 *
 * @param interval  the interval to extract seconds from, nil returns zero
 * @return the period in seconds
 * @throws IllegalArgumentException if the partials are nil or invalid
 */
+ (HLSeconds*)secondsIn:(id<HLReadableInterval>)interval;

/**
 * Creates a new <code>Seconds</code> representing the number of complete
 * standard length seconds in the specified period.
 * <p>
 * This factory method converts all fields from the period to hours using standardised
 * durations for each field. Only those fields which have a precise duration in
 * the ISO UTC chronology can be converted.
 * <ul>
 * <li>One week consists of 7 seconds.
 * <li>One day consists of 24 hours.
 * <li>One hour consists of 60 minutes.
 * <li>One minute consists of 60 seconds.
 * <li>One second consists of 1000 milliseconds.
 * </ul>
 * Months and Years are imprecise and periods containing these values cannot be converted.
 *
 * @param period  the period to get the number of hours from, nil returns zero
 * @return the period in seconds
 * @throws IllegalArgumentException if the period contains imprecise duration values
 */
+ (HLSeconds*)standardSecondsIn:(id<HLReadablePeriod>)period;

/**
 * Creates a new <code>Seconds</code> by parsing a string in the ISO8601 format 'PTnS'.
 * <p>
 * The parse will accept the full ISO syntax of PnYnMnWnDTnHnMnS however only the
 * seconds component may be non-zero. If any other component is non-zero, an exception
 * will be thrown.
 *
 * @param periodStr  the period string, nil returns zero
 * @return the period in seconds
 * @throws IllegalArgumentException if the string format is invalid
 */
+ (HLSeconds*)parseSeconds:(NSString*)periodStr;

//-----------------------------------------------------------------------
/**
 * Creates a new instance representing a number of seconds.
 * You should consider using the factory method {@link #seconds(int)}
 * instead of the constructor.
 *
 * @param seconds  the number of seconds to represent
 */
- (id)initWithSeconds:(NSInteger)seconds;

//-----------------------------------------------------------------------
/**
 * Gets the duration field type, which is <code>seconds</code>.
 *
 * @return the period type
 */
- (HLDurationFieldType*)fieldType;

/**
 * Gets the period type, which is <code>seconds</code>.
 *
 * @return the period type
 */
- (HLPeriodType*)periodType;

//-----------------------------------------------------------------------
/**
 * Converts this period in seconds to a period in weeks assuming a
 * 7 day week, 24 hour day, 60 minute hour and 60 second minute.
 * <p>
 * This method allows you to convert between different types of period.
 * However to achieve this it makes the assumption that all weeks are 7 days
 * long, all days are 24 hours long, all hours are 60 minutes long and
 * all minutes are 60 seconds long.
 * This is not true when daylight savings time is considered, and may also
 * not be true for some unusual chronologies. However, it is included as it
 * is a useful operation for many applications and business rules.
 * 
 * @return a period representing the number of whole weeks for this number of seconds
 */
- (HLWeeks*)toStandardWeeks;

/**
 * Converts this period in seconds to a period in days assuming a
 * 24 hour day, 60 minute hour and 60 second minute.
 * <p>
 * This method allows you to convert between different types of period.
 * However to achieve this it makes the assumption that all days are 24 hours
 * long, all hours are 60 minutes long and all minutes are 60 seconds long.
 * This is not true when daylight savings is considered and may also not
 * be true for some unusual chronologies. However, it is included
 * as it is a useful operation for many applications and business rules.
 * 
 * @return a period representing the number of days for this number of seconds
 */
- (HLDays*)toStandardDays;

/**
 * Converts this period in seconds to a period in hours assuming a
 * 60 minute hour and 60 second minute.
 * <p>
 * This method allows you to convert between different types of period.
 * However to achieve this it makes the assumption that all hours are
 * 60 minutes long and all minutes are 60 seconds long.
 * This may not be true for some unusual chronologies. However, it is included
 * as it is a useful operation for many applications and business rules.
 * 
 * @return a period representing the number of hours for this number of seconds
 */
- (HLHours*)toStandardHours;

/**
 * Converts this period in seconds to a period in minutes assuming a
 * 60 second minute.
 * <p>
 * This method allows you to convert between different types of period.
 * However to achieve this it makes the assumption that all minutes are
 * 60 seconds long.
 * This may not be true for some unusual chronologies. However, it is included
 * as it is a useful operation for many applications and business rules.
 * 
 * @return a period representing the number of minutes for this number of seconds
 */
- (HLMinutes*)toStandardMinutes;

//-----------------------------------------------------------------------
/**
 * Converts this period in seconds to a duration in milliseconds assuming a
 * 24 hour day, 60 minute hour and 60 second minute.
 * <p>
 * This method allows you to convert from a period to a duration.
 * However to achieve this it makes the assumption that all seconds are 24 hours
 * long, all hours are 60 minutes and all minutes are 60 seconds.
 * This is not true when daylight savings time is considered, and may also
 * not be true for some unusual chronologies. However, it is included as it
 * is a useful operation for many applications and business rules.
 * 
 * @return a duration equivalent to this number of seconds
 */
- (HLDuration*)toStandardDuration;

//-----------------------------------------------------------------------
/**
 * Gets the number of seconds that this period represents.
 *
 * @return the number of seconds in the period
 */
- (NSInteger)getSeconds;

//-----------------------------------------------------------------------
/**
 * Returns a new instance with the specified number of seconds added.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param seconds  the amount of seconds to add, may be negative
 * @return the new period plus the specified number of seconds
 * @throws ArithmeticException if the result overflows an int
 */
- (HLSeconds*)plusSecondsValue:(NSInteger)seconds;

/**
 * Returns a new instance with the specified number of seconds added.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param seconds  the amount of seconds to add, may be negative, nil means zero
 * @return the new period plus the specified number of seconds
 * @throws ArithmeticException if the result overflows an int
 */
- (HLSeconds*)plusSeconds:(HLSeconds*)seconds;

//-----------------------------------------------------------------------
/**
 * Returns a new instance with the specified number of seconds taken away.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param seconds  the amount of seconds to take away, may be negative
 * @return the new period minus the specified number of seconds
 * @throws ArithmeticException if the result overflows an int
 */
- (HLSeconds*)minusSecondsValue:(NSInteger)seconds;

/**
 * Returns a new instance with the specified number of seconds taken away.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param seconds  the amount of seconds to take away, may be negative, nil means zero
 * @return the new period minus the specified number of seconds
 * @throws ArithmeticException if the result overflows an int
 */
- (HLSeconds*)minusSeconds:(HLSeconds*)seconds;

//-----------------------------------------------------------------------
/**
 * Returns a new instance with the seconds multiplied by the specified scalar.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param scalar  the amount to multiply by, may be negative
 * @return the new period multiplied by the specified scalar
 * @throws ArithmeticException if the result overflows an int
 */
- (HLSeconds*)multipliedBy:(NSInteger)scalar;

/**
 * Returns a new instance with the seconds divided by the specified divisor.
 * The calculation uses integer division, thus 3 divided by 2 is 1.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param divisor  the amount to divide by, may be negative
 * @return the new period divided by the specified divisor
 * @throws ArithmeticException if the divisor is zero
 */
- (HLSeconds*)dividedBy:(NSInteger)divisor;

//-----------------------------------------------------------------------
/**
 * Returns a new instance with the seconds value negated.
 *
 * @return the new period with a negated value
 * @throws ArithmeticException if the result overflows an int
 */
- (HLSeconds*)negated;

//-----------------------------------------------------------------------
/**
 * Is this seconds instance greater than the specified number of seconds.
 *
 * @param other  the other period, nil means zero
 * @return true if this seconds instance is greater than the specified one
 */
- (BOOL)isGreaterThan:(HLSeconds*)other;

/**
 * Is this seconds instance less than the specified number of seconds.
 *
 * @param other  the other period, nil means zero
 * @return true if this seconds instance is less than the specified one
 */
- (BOOL)isLessThan:(HLSeconds*)other;

@end

/** Constant representing zero seconds. */
extern const HLSeconds* ZERO;
/** Constant representing one second. */
extern const HLSeconds* ONE;
/** Constant representing two seconds. */
extern const HLSeconds* TWO;
/** Constant representing three seconds. */
extern const HLSeconds* THREE;
/** Constant representing the maximum number of seconds that can be stored in this object. */
extern const HLSeconds* MAX_VALUE;
/** Constant representing the minimum number of seconds that can be stored in this object. */
extern const HLSeconds* MIN_VALUE;

