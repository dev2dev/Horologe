/*
 * Hours.h
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


@class HLPeriodFormatter;
@class HLWeeks;
@class HLDays;
@class HLSeconds;
@class HLDuration;
@class HLMinutes;
@protocol HLReadableInterval;

/**
 * An immutable time period representing a number of hours.
 * <p>
 * <code>Hours</code> is an immutable period that can only store hours.
 * It does not store years, months or minutes for example. As such it is a
 * type-safe way of representing a number of hours in an application.
 * <p>
 * The number of hours is set in the constructor, and may be queried using
 * <code>getHours()</code>. Basic mathematical operations are provided -
 * <code>plus()</code>, <code>minus()</code>, <code>multipliedBy()</code> and
 * <code>dividedBy()</code>.
 * <p>
 * <code>Hours</code> is thread-safe and immutable.
 *
 * @author Stephen Colebourne
 * @since 1.4
 */
@interface HLHours : HLBaseSingleFieldPeriod {
    
@private
    /** The paser to use for this class. */
    HLPeriodFormatter* _parser;
    
}


//-----------------------------------------------------------------------
/**
 * Obtains an instance of <code>Hours</code> that may be cached.
 * <code>Hours</code> is immutable, so instances can be cached and shared.
 * This factory method provides access to shared instances.
 *
 * @param hours  the number of hours to obtain an instance for
 * @return the instance of Hours
 */
+ (HLHours*)hours:(NSInteger)hours;

//-----------------------------------------------------------------------
/**
 * Creates a <code>Hours</code> representing the number of whole hours
 * between the two specified datetimes.
 *
 * @param start  the start instant, must not be nil
 * @param end  the end instant, must not be nil
 * @return the period in hours
 * @throws IllegalArgumentException if the instants are nil or invalid
 */
+ (HLHours*)hoursBetweenStartInstant:(id<HLReadableInstant>)start
                          endInstant:(id<HLReadableInstant>)end;

/**
 * Creates a <code>Hours</code> representing the number of whole hours
 * between the two specified partial datetimes.
 * <p>
 * The two partials must contain the same fields, for example you can specify
 * two <code>LocalTime</code> objects.
 *
 * @param start  the start partial date, must not be nil
 * @param end  the end partial date, must not be nil
 * @return the period in hours
 * @throws IllegalArgumentException if the partials are nil or invalid
 */
+ (HLHours*)hoursBetweenStartPartial:(id<HLReadablePartial>)start
                          endPartial:(id<HLReadablePartial>)end;

/**
 * Creates a <code>Hours</code> representing the number of whole hours
 * in the specified interval.
 *
 * @param interval  the interval to extract hours from, nil returns zero
 * @return the period in hours
 * @throws IllegalArgumentException if the partials are nil or invalid
 */
+ (HLHours*)hoursIn:(id<HLReadableInterval>)interval;

/**
 * Creates a new <code>Hours</code> representing the number of complete
 * standard length hours in the specified period.
 * <p>
 * This factory method converts all fields from the period to hours using standardised
 * durations for each field. Only those fields which have a precise duration in
 * the ISO UTC chronology can be converted.
 * <ul>
 * <li>One week consists of 7 days.
 * <li>One day consists of 24 hours.
 * <li>One hour consists of 60 minutes.
 * <li>One minute consists of 60 seconds.
 * <li>One second consists of 1000 milliseconds.
 * </ul>
 * Months and Years are imprecise and periods containing these values cannot be converted.
 *
 * @param period  the period to get the number of hours from, nil returns zero
 * @return the period in hours
 * @throws IllegalArgumentException if the period contains imprecise duration values
 */
+ (HLHours*)standardHoursIn:(id<HLReadablePeriod>)period;

/**
 * Creates a new <code>Hours</code> by parsing a string in the ISO8601 format 'PTnH'.
 * <p>
 * The parse will accept the full ISO syntax of PnYnMnWnDTnHnMnS however only the
 * hours component may be non-zero. If any other component is non-zero, an exception
 * will be thrown.
 *
 * @param periodStr  the period string, nil returns zero
 * @return the period in hours
 * @throws IllegalArgumentException if the string format is invalid
 */
+ (HLHours*)parseHours:(NSString*)periodStr;

//-----------------------------------------------------------------------
/**
 * Gets the duration field type, which is <code>hours</code>.
 *
 * @return the period type
 */
- (HLDurationFieldType*)fieldType;

/**
 * Gets the period type, which is <code>hours</code>.
 *
 * @return the period type
 */
- (HLPeriodType*)periodType;

//-----------------------------------------------------------------------
/**
 * Converts this period in hours to a period in weeks assuming a
 * 7 day week and 24 hour day.
 * <p>
 * This method allows you to convert between different types of period.
 * However to achieve this it makes the assumption that all weeks are 7 days
 * long and all days are 24 hours long.
 * This is not true when daylight savings time is considered, and may also
 * not be true for some unusual chronologies. However, it is included as it
 * is a useful operation for many applications and business rules.
 * 
 * @return a period representing the number of whole weeks for this number of hours
 */
- (HLWeeks*)toStandardWeeks;

/**
 * Converts this period in hours to a period in days assuming a
 * 24 hour day.
 * <p>
 * This method allows you to convert between different types of period.
 * However to achieve this it makes the assumption that all days are 24 hours long.
 * This is not true when daylight savings time is considered, and may also
 * not be true for some unusual chronologies. However, it is included as it
 * is a useful operation for many applications and business rules.
 * 
 * @return a period representing the number of whole days for this number of hours
 */
- (HLDays*)toStandardDays;

/**
 * Converts this period in hours to a period in minutes assuming a
 * 60 minute hour.
 * <p>
 * This method allows you to convert between different types of period.
 * However to achieve this it makes the assumption that all hours are 60 minutes long.
 * This may not be true for some unusual chronologies. However, it is included
 * as it is a useful operation for many applications and business rules.
 * 
 * @return a period representing the number of minutes for this number of hours
 * @throws ArithmeticException if the number of minutes is too large to be represented
 */
- (HLMinutes*)toStandardMinutes;

/**
 * Converts this period in hours to a period in seconds assuming a
 * 60 minute hour and 60 second minute.
 * <p>
 * This method allows you to convert between different types of period.
 * However to achieve this it makes the assumption that all hours are
 * 60 minutes long and all minutes are 60 seconds long.
 * This may not be true for some unusual chronologies. However, it is included
 * as it is a useful operation for many applications and business rules.
 * 
 * @return a period representing the number of seconds for this number of hours
 * @throws ArithmeticException if the number of seconds is too large to be represented
 */
- (HLSeconds*)toStandardSeconds;

//-----------------------------------------------------------------------
/**
 * Converts this period in hours to a duration in milliseconds assuming a
 * 60 minute hour and 60 second minute.
 * <p>
 * This method allows you to convert from a period to a duration.
 * However to achieve this it makes the assumption that all hours are
 * 60 minutes and all minutes are 60 seconds. This might not be true for an
 * unusual chronology, for example one that takes leap seconds into account.
 * However, the method is included as it is a useful operation for many
 * applications and business rules.
 *
 * @return a duration equivalent to this number of hours
 */
- (HLDuration*)toStandardDuration;

//-----------------------------------------------------------------------
/**
 * Gets the number of hours that this period represents.
 *
 * @return the number of hours in the period
 */
- (NSInteger)hours;

//-----------------------------------------------------------------------
/**
 * Returns a new instance with the specified number of hours added.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param hours  the amount of hours to add, may be negative
 * @return the new period plus the specified number of hours
 * @throws ArithmeticException if the result overflows an int
 */
- (HLHours*)plusHoursValue:(NSInteger)hours;

/**
 * Returns a new instance with the specified number of hours added.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param hours  the amount of hours to add, may be negative, nil means zero
 * @return the new period plus the specified number of hours
 * @throws ArithmeticException if the result overflows an int
 */
- (HLHours*)plusHours:(HLHours*)hours;

//-----------------------------------------------------------------------
/**
 * Returns a new instance with the specified number of hours taken away.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param hours  the amount of hours to take away, may be negative
 * @return the new period minus the specified number of hours
 * @throws ArithmeticException if the result overflows an int
 */
- (HLHours*)minusHoursValue:(NSInteger)hours;

/**
 * Returns a new instance with the specified number of hours taken away.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param hours  the amount of hours to take away, may be negative, nil means zero
 * @return the new period minus the specified number of hours
 * @throws ArithmeticException if the result overflows an int
 */
- (HLHours*)minusHours:(HLHours*)hours;

//-----------------------------------------------------------------------
/**
 * Returns a new instance with the hours multiplied by the specified scalar.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param scalar  the amount to multiply by, may be negative
 * @return the new period multiplied by the specified scalar
 * @throws ArithmeticException if the result overflows an int
 */
- (HLHours*)multipliedBy:(NSInteger)scalar;

/**
 * Returns a new instance with the hours divided by the specified divisor.
 * The calculation uses integer division, thus 3 divided by 2 is 1.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param divisor  the amount to divide by, may be negative
 * @return the new period divided by the specified divisor
 * @throws ArithmeticException if the divisor is zero
 */
- (HLHours*)dividedBy:(NSInteger)divisor;

//-----------------------------------------------------------------------
/**
 * Returns a new instance with the hours value negated.
 *
 * @return the new period with a negated value
 * @throws ArithmeticException if the result overflows an int
 */
- (HLHours*)negated;

//-----------------------------------------------------------------------
/**
 * Is this hours instance greater than the specified number of hours.
 *
 * @param other  the other period, nil means zero
 * @return true if this hours instance is greater than the specified one
 */
- (BOOL)isGreaterThanHours:(HLHours*)other;

/**
 * Is this hours instance less than the specified number of hours.
 *
 * @param other  the other period, nil means zero
 * @return true if this hours instance is less than the specified one
 */
- (BOOL)isLessThanHours:(HLHours*)other;

@end

/** Constant representing zero hours. */
extern const HLHours* HL_HOURS_ZERO;
/** Constant representing one hour. */
extern const HLHours* HL_HOURS_ONE;
/** Constant representing two hours. */
extern const HLHours* HL_HOURS_TWO;
/** Constant representing three hours. */
extern const HLHours* HL_HOURS_THREE;
/** Constant representing four hours. */
extern const HLHours* HL_HOURS_FOUR;
/** Constant representing five hours. */
extern const HLHours* HL_HOURS_FIVE;
/** Constant representing six hours. */
extern const HLHours* HL_HOURS_SIX;
/** Constant representing seven hours. */
extern const HLHours* HL_HOURS_SEVEN;
/** Constant representing eight hours. */
extern const HLHours* HL_HOURS_EIGHT;
/** Constant representing the maximum number of hours that can be stored in this object. */
extern const HLHours* HL_HOURS_MAX_VALUE;
/** Constant representing the minimum number of hours that can be stored in this object. */
extern const HLHours* HL_HOURS_MIN_VALUE;

