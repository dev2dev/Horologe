/*
 * Years.h
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


@class HLPeriodType;
@class HLDurationFieldType;
@class HLPeriodFormatter;
@class HLYears;
@protocol HLReadableInstant;
@protocol HLReadablePartial;
@protocol HLReadableInterval;

extern const HLYears* HL_YEARS_ZERO;
extern const HLYears* HL_YEARS_ONE;
extern const HLYears* HL_YEARS_TWO;
extern const HLYears* HL_YEARS_THREE;
extern const HLYears* HL_YEARS_MAX_VALUE;
extern const HLYears* HL_YEARS_MIN_VALUE;

/**
 * An immutable time period representing a number of years.
 * <p>
 * <code>Years</code> is an immutable period that can only store years.
 * It does not store years, days or hours for example. As such it is a
 * type-safe way of representing a number of years in an application.
 * <p>
 * The number of years is set in the constructor, and may be queried using
 * <code>getYears()</code>. Basic mathematical operations are provided -
 * <code>plus()</code>, <code>minus()</code>, <code>multipliedBy()</code> and
 * <code>dividedBy()</code>.
 * <p>
 * <code>Years</code> is thread-safe and immutable.
 *
 * @author Stephen Colebourne
 * @since 1.4
 */
@interface HLYears : HLBaseSingleFieldPeriod {
    
@private
    
}

//-----------------------------------------------------------------------
/**
 * Obtains an instance of <code>Years</code> that may be cached.
 * <code>Years</code> is immutable, so instances can be cached and shared.
 * This factory method provides access to shared instances.
 *
 * @param years  the number of years to obtain an instance for
 * @return the instance of Years
 */
+ (HLYears*)years:(NSInteger)years;

//-----------------------------------------------------------------------
/**
 * Creates a <code>Years</code> representing the number of whole years
 * between the two specified datetimes. This method corectly handles
 * any daylight savings time changes that may occur during the interval.
 *
 * @param start  the start instant, must not be nil
 * @param end  the end instant, must not be nil
 * @return the period in years
 * @throws IllegalArgumentException if the instants are nil or invalid
 */
+ (HLYears*)yearsBetweenStartInstant:(id<HLReadableInstant>)start
                          endInstant:(id<HLReadableInstant>)end;

/**
 * Creates a <code>Years</code> representing the number of whole years
 * between the two specified partial datetimes.
 * <p>
 * The two partials must contain the same fields, for example you can specify
 * two <code>LocalDate</code> objects.
 *
 * @param start  the start partial date, must not be nil
 * @param end  the end partial date, must not be nil
 * @return the period in years
 * @throws IllegalArgumentException if the partials are nil or invalid
 */
+ (HLYears*)yearsBetweenStartPartial:(id<HLReadablePartial>)start
                          endPartial:(id<HLReadablePartial>)end;

/**
 * Creates a <code>Years</code> representing the number of whole years
 * in the specified interval. This method corectly handles any daylight
 * savings time changes that may occur during the interval.
 *
 * @param interval  the interval to extract years from, nil returns zero
 * @return the period in years
 * @throws IllegalArgumentException if the partials are nil or invalid
 */
+ (HLYears*)yearsInInterval:(id<HLReadableInterval>)interval;

/**
 * Creates a new <code>Years</code> by parsing a string in the ISO8601 format 'PnY'.
 * <p>
 * The parse will accept the full ISO syntax of PnYnMnWnDTnHnMnS however only the
 * years component may be non-zero. If any other component is non-zero, an exception
 * will be thrown.
 *
 * @param periodStr  the period string, nil returns zero
 * @return the period in years
 * @throws IllegalArgumentException if the string format is invalid
 */
+ (HLYears*)parseYears:(NSString*)periodStr;

//-----------------------------------------------------------------------
/**
 * Creates a new instance representing a number of years.
 * You should consider using the factory method {@link #years(int)}
 * instead of the constructor.
 *
 * @param years  the number of years to represent
 */
- (id)initWithYears:(NSInteger)years;

/**
 * Resolves singletons.
 * 
 * @return the singleton instance
 */
- (id)readResolve;

//-----------------------------------------------------------------------
/**
 * Gets the duration field type, which is <code>years</code>.
 *
 * @return the period type
 */
- (HLDurationFieldType*)fieldType;

/**
 * Gets the period type, which is <code>years</code>.
 *
 * @return the period type
 */
- (HLPeriodType*)periodType;

//-----------------------------------------------------------------------
/**
 * Gets the number of years that this period represents.
 *
 * @return the number of years in the period
 */
- (NSInteger)years;

//-----------------------------------------------------------------------
/**
 * Returns a new instance with the specified number of years added.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param years  the amount of years to add, may be negative
 * @return the new period plus the specified number of years
 * @throws ArithmeticException if the result overflows an int
 */
- (HLYears*)plusYearsValue:(NSInteger)years;

/**
 * Returns a new instance with the specified number of years added.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param years  the amount of years to add, may be negative, nil means zero
 * @return the new period plus the specified number of years
 * @throws ArithmeticException if the result overflows an int
 */
- (HLYears*)plusYears:(HLYears*)years;

//-----------------------------------------------------------------------
/**
 * Returns a new instance with the specified number of years taken away.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param years  the amount of years to take away, may be negative
 * @return the new period minus the specified number of years
 * @throws ArithmeticException if the result overflows an int
 */
- (HLYears*)minusYearsValue:(NSInteger)years;

/**
 * Returns a new instance with the specified number of years taken away.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param years  the amount of years to take away, may be negative, nil means zero
 * @return the new period minus the specified number of years
 * @throws ArithmeticException if the result overflows an int
 */
- (HLYears*)minusYears:(HLYears*)years;

//-----------------------------------------------------------------------
/**
 * Returns a new instance with the years multiplied by the specified scalar.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param scalar  the amount to multiply by, may be negative
 * @return the new period multiplied by the specified scalar
 * @throws ArithmeticException if the result overflows an int
 */
- (HLYears*)multipliedBy:(NSInteger)scalar;

/**
 * Returns a new instance with the years divided by the specified divisor.
 * The calculation uses integer division, thus 3 divided by 2 is 1.
 * <p>
 * This instance is immutable and unaffected by this method call.
 *
 * @param divisor  the amount to divide by, may be negative
 * @return the new period divided by the specified divisor
 * @throws ArithmeticException if the divisor is zero
 */
- (HLYears*)dividedBy:(NSInteger)divisor;

//-----------------------------------------------------------------------
/**
 * Returns a new instance with the years value negated.
 *
 * @return the new period with a negated value
 * @throws ArithmeticException if the result overflows an int
 */
- (HLYears*)negated;

//-----------------------------------------------------------------------
/**
 * Is this years instance greater than the specified number of years.
 *
 * @param other  the other period, nil means zero
 * @return true if this years instance is greater than the specified one
 */
- (BOOL)isGreaterThanYears:(HLYears*)other;

/**
 * Is this years instance less than the specified number of years.
 *
 * @param other  the other period, nil means zero
 * @return true if this years instance is less than the specified one
 */
- (BOOL)isLessThanYears:(HLYears*)other;

@end
