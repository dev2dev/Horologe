/*
 * Days.h
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


/**
 * An immutable time period representing a number of days.
 * <p>
 * <code>Days</code> is an immutable period that can only store days.
 * It does not store years, months or hours for example. As such it is a
 * type-safe way of representing a number of days in an application.
 * <p>
 * The number of days is set in the constructor, and may be queried using
 * <code>getDays()</code>. Basic mathematical operations are provided -
 * <code>plus()</code>, <code>minus()</code>, <code>multipliedBy()</code> and
 * <code>dividedBy()</code>.
 * <p>
 * <code>Days</code> is thread-safe and immutable.
 *
 * @author Stephen Colebourne
 * @since 1.4
 */
@interface HLDays : HLBaseSingleFieldPeriod {
    
@private
    
}

//-----------------------------------------------------------------------
/**
 * Obtains an instance of <code>Days</code> that may be cached.
 * <code>Days</code> is immutable, so instances can be cached and shared.
 * This factory method provides access to shared instances.
 *
 * @param days  the number of days to obtain an instance for
 * @return the instance of Days
 */
+ (HLDays*)days:(NSInteger)days;

//-----------------------------------------------------------------------
/**
 * Creates a <code>Days</code> representing the number of whole days
 * between the two specified datetimes. This method corectly handles
 * any daylight savings time changes that may occur during the interval.
 *
 * @param start  the start instant, must not be nil
 * @param end  the end instant, must not be nil
 * @return the period in days
 * @throws IllegalArgumentException if the instants are nil or invalid
 */
+ (HLDays*)daysBetweenStartInstant:(id<HLReadableInstant>)start
                        endInstant:(id<HLReadableInstant>)end;

/**
 * Creates a <code>Days</code> representing the number of whole days
 * between the two specified partial datetimes.
 * <p>
 * The two partials must contain the same fields, for example you can specify
 * two <code>LocalDate</code> objects.
 *
 * @param start  the start partial date, must not be nil
 * @param end  the end partial date, must not be nil
 * @return the period in days
 * @throws IllegalArgumentException if the partials are nil or invalid
 */
+ (HLDays*)daysBetweenStartPartial:(id<HLReadablePartial>)start
                        endPartial:(id<HLReadablePartial>)end;

/**
 * Creates a <code>Days</code> representing the number of whole days
 * in the specified interval. This method corectly handles any daylight
 * savings time changes that may occur during the interval.
 *
 * @param interval  the interval to extract days from, nil returns zero
 * @return the period in days
 * @throws IllegalArgumentException if the partials are nil or invalid
 */
+ (HLDays*)daysInInterval:(id<HLReadableInterval>)interval;

/**
 * Creates a new <code>Days</code> representing the number of complete
 * standard length days in the specified period.
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
 * @return the period in days
 * @throws IllegalArgumentException if the period contains imprecise duration values
 */
+ (HLDays*)standardDaysInPeriod:(id<HLReadablePeriod>)period;

/**
 * Creates a new <code>Days</code> by parsing a string in the ISO8601 format 'PnD'.
 * <p>
 * The parse will accept the full ISO syntax of PnYnMnWnDTnHnMnS however only the
 * days component may be non-zero. If any other component is non-zero, an exception
 * will be thrown.
 *
 * @param periodStr  the period string, nil returns zero
 * @return the period in days
 * @throws IllegalArgumentException if the string format is invalid
 */
+ (HLDays*)parseDays:(NSString*)periodStr;

//-----------------------------------------------------------------------
/**
 * Gets the duration field type, which is <code>days</code>.
 *
 * @return the period type
 */
- (HLDurationFieldType*)fieldType;

/**
 * Gets the period type, which is <code>days</code>.
 *
 * @return the period type
 */
- (HLPeriodType*)periodType;

//-----------------------------------------------------------------------
/**
 * Converts this period in days to a period in weeks assuming a
 * 7 day week.
 * <p>
 * This method allows you to convert between different types of period.
 * However to achieve this it makes the assumption that all weeks are
 * 7 days long.
 * This may not be true for some unusual chronologies. However, it is included
 * as it is a useful operation for many applications and business rules.
 * 
 * @return a period representing the number of weeks for this number of days
 */
- (HLWeeks*)toStandardWeeks;

/**
 * Converts this period in days to a period in hours assuming a
 * 24 hour day.
 * <p>
 * This method allows you to convert between different types of period.
 * However to achieve this it makes the assumption that all days are 24 hours long.
 * This is not true when daylight savings is considered and may also not
 * be true for some unusual chronologies. However, it is included
 * as it is a useful operation for many applications and business rules.
 * 
 * @return a period representing the number of hours for this number of days
 * @throws ArithmeticException if the number of hours is too large to be represented
 */
- (HLHours*)toStandardHours;

/**
 * Converts this period in days to a period in minutes assuming a
 * 24 hour day and 60 minute hour.
 * <p>
 * This method allows you to convert between different types of period.
 * However to achieve this it makes the assumption that all days are 24 hours
 * long and all hours are 60 minutes long.
 * This is not true when daylight savings is considered and may also not
 * be true for some unusual chronologies. However, it is included
 * as it is a useful operation for many applications and business rules.
 * 
 * @return a period representing the number of minutes for this number of days
 * @throws ArithmeticException if the number of minutes is too large to be represented
 */
- (HLMinutes*)toStandardMinutes;

/**
 * Converts this period in days to a period in seconds assuming a
 * 24 hour day, 60 minute hour and 60 second minute.
 * <p>
 * This method allows you to convert between different types of period.
 * However to achieve this it makes the assumption that all days are 24 hours
 * long, all hours are 60 minutes long and all minutes are 60 seconds long.
 * This is not true when daylight savings is considered and may also not
 * be true for some unusual chronologies. However, it is included
 * as it is a useful operation for many applications and business rules.
 * 
 * @return a period representing the number of seconds for this number of days
 * @throws ArithmeticException if the number of seconds is too large to be represented
 */
- (HLSeconds*)toStandardSeconds;

//-----------------------------------------------------------------------
/**
 * Converts this period in days to a duration in milliseconds assuming a
 * 24 hour day, 60 minute hour and 60 second minute.
 * <p>
 * This method allows you to convert from a period to a duration.
 * However to achieve this it makes the assumption that all days are 24 hours
 * long, all hours are 60 minutes and all minutes are 60 seconds.
 * This is not true when daylight savings time is considered, and may also
 * not be true for some unusual chronologies. However, it is included as it
 * is a useful operation for many applications and business rules.
 * 
 * @return a duration equivalent to this number of days
 */
- (HLDuration*)toStandardDuration;

//-----------------------------------------------------------------------
/**
 * Gets the number of days that this period represents.
 *
 * @return the number of days in the period
 */
- (NSInteger)getDays;

//-----------------------------------------------------------------------
/**
 * Returns a new instance with the specified number of days added.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param days  the amount of days to add, may be negative
 * @return the new period plus the specified number of days
 * @throws ArithmeticException if the result overflows an int
 */
- (HLDays*)plusDaysValue:(NSInteger)days;

/**
 * Returns a new instance with the specified number of days added.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param days  the amount of days to add, may be negative, nil means zero
 * @return the new period plus the specified number of days
 * @throws ArithmeticException if the result overflows an int
 */
- (HLDays*)plusDays:(HLDays*)days;

//-----------------------------------------------------------------------
/**
 * Returns a new instance with the specified number of days taken away.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param days  the amount of days to take away, may be negative
 * @return the new period minus the specified number of days
 * @throws ArithmeticException if the result overflows an int
 */
- (HLDays*)minusDaysValue:(NSInteger)days;

/**
 * Returns a new instance with the specified number of days taken away.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param days  the amount of days to take away, may be negative, nil means zero
 * @return the new period minus the specified number of days
 * @throws ArithmeticException if the result overflows an int
 */
- (HLDays*)minusDays:(HLDays*)days;

//-----------------------------------------------------------------------
/**
 * Returns a new instance with the days multiplied by the specified scalar.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param scalar  the amount to multiply by, may be negative
 * @return the new period multiplied by the specified scalar
 * @throws ArithmeticException if the result overflows an int
 */
- (HLDays*)multipliedBy:(NSInteger)scalar;

/**
 * Returns a new instance with the days divided by the specified divisor.
 * The calculation uses integer division, thus 3 divided by 2 is 1.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param divisor  the amount to divide by, may be negative
 * @return the new period divided by the specified divisor
 * @throws ArithmeticException if the divisor is zero
 */
- (HLDays*)dividedBy:(NSInteger)divisor;

//-----------------------------------------------------------------------
/**
 * Returns a new instance with the days value negated.
 *
 * @return the new period with a negated value
 * @throws ArithmeticException if the result overflows an int
 */
- (HLDays*)negated;

//-----------------------------------------------------------------------
/**
 * Is this days instance greater than the specified number of days.
 *
 * @param other  the other period, nil means zero
 * @return true if this days instance is greater than the specified one
 */
- (BOOL)isGreaterThanDays:(HLDays*)other;

/**
 * Is this days instance less than the specified number of days.
 *
 * @param other  the other period, nil means zero
 * @return true if this days instance is less than the specified one
 */
- (BOOL)isLessThanDays:(HLDays*)other;

@end

/** Constant representing zero days. */
extern const HLDays* HL_DAYS_ZERO;
/** Constant representing one day. */
extern const HLDays* HL_DAYS_ONE;
/** Constant representing two days. */
extern const HLDays* HL_DAYS_TWO;
/** Constant representing three days. */
extern const HLDays* HL_DAYS_THREE;
/** Constant representing four days. */
extern const HLDays* HL_DAYS_FOUR;
/** Constant representing five days. */
extern const HLDays* HL_DAYS_FIVE;
/** Constant representing six days. */
extern const HLDays* HL_DAYS_SIX;
/** Constant representing seven days. */
extern const HLDays* HL_DAYS_SEVEN;
/** Constant representing the maximum number of days that can be stored in this object. */
extern const HLDays* HL_DAYS_MAX_VALUE;
/** Constant representing the minimum number of days that can be stored in this object. */
extern const HLDays* HL_DAYS_MIN_VALUE;

