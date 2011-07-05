/*
 * BaseSingleFieldPeriod.h
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

#import "HLReadablePeriod.h"


@class HLDurationFieldType;
@class HLPeriod;
@class HLMutablePeriod;
@protocol HLReadableInstant;
@protocol HLReadablePartial;

/**
 * BaseSingleFieldPeriod is an abstract implementation of ReadablePeriod that
 * manages a single duration field, such as days or minutes.
 * <p>
 * This class should generally not be used directly by API users.
 * The {@link ReadablePeriod} interface should be used when different 
 * kinds of period objects are to be referenced.
 * <p>
 * BaseSingleFieldPeriod subclasses may be mutable and not thread-safe.
 *
 * @author Stephen Colebourne
 * @since 1.4
 */
@interface HLBaseSingleFieldPeriod : NSObject <HLReadablePeriod> {
    
@private
    NSInteger _iPeriod;
    
}

//-----------------------------------------------------------------------
/**
 * Calculates the number of whole units between the two specified datetimes.
 *
 * @param start  the start instant, validated to not be nil
 * @param end  the end instant, validated to not be nil
 * @param field  the field type to use, must not be nil
 * @return the period
 * @throws IllegalArgumentException if the instants are nil or invalid
 */
+ (NSInteger)_betweenStart:(id<HLReadableInstant>)start
                       end:(id<HLReadableInstant>)end
                 fieldType:(HLDurationFieldType*)field;

//-----------------------------------------------------------------------
/**
 * Calculates the number of whole units between the two specified partial datetimes.
 * <p>
 * The two partials must contain the same fields, for example you can specify
 * two <code>LocalDate</code> objects.
 *
 * @param start  the start partial date, validated to not be nil
 * @param end  the end partial date, validated to not be nil
 * @param zeroInstance  the zero instance constant, must not be nil
 * @return the period
 * @throws IllegalArgumentException if the partials are nil or invalid
 */
+ (NSInteger)_betweenStart:(id<HLReadablePartial>)start
                       end:(id<HLReadablePartial>)end
                      zero:(id<HLReadablePeriod>)zeroInstance;

/**
 * Creates a new instance representing the number of complete standard length units
 * in the specified period.
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
 * @param period  the period to get the number of hours from, must not be nil
 * @param millisPerUnit  the number of milliseconds in one standard unit of this period
 * @throws IllegalArgumentException if the period contains imprecise duration values
 */
+ (NSInteger)_standardPeriodIn:(id<HLReadablePeriod>)period 
                        millis:(NSInteger)millisPerUnit;

//-----------------------------------------------------------------------
/**
 * Creates a new instance representing the specified period.
 *
 * @param period  the period to represent
 */
- (id)initWithPeriod:(NSInteger)period;

//-----------------------------------------------------------------------
/**
 * Gets the amount of this period.
 *
 * @return the period value
 */
- (NSInteger)_value;

/**
 * Sets the amount of this period.
 * To make a subclass immutable you must declare it final, or block this method.
 *
 * @param value  the period value
 */
- (void)_setValue:(NSInteger)value;

//-----------------------------------------------------------------------
/**
 * Gets the single duration field type.
 *
 * @return the duration field type, not nil
 */
- (HLDurationFieldType*)fieldType;

/**
 * Gets the period type which matches the duration field type.
 *
 * @return the period type, not nil
 */
- (HLPeriodType*)periodType;

//-----------------------------------------------------------------------
/**
 * Gets the number of fields that this period supports, which is one.
 *
 * @return the number of fields supported, which is one
 */
- (NSInteger)size;

/**
 * Gets the field type at the specified index.
 * <p>
 * The only index supported by this period is zero which returns the
 * field type of this class.
 *
 * @param index  the index to retrieve, which must be zero
 * @return the field at the specified index
 * @throws IndexOutOfBoundsException if the index is invalid
 */
- (HLDurationFieldType*)fieldTypeAtIndex:(NSInteger)index;

/**
 * Gets the value at the specified index.
 * <p>
 * The only index supported by this period is zero.
 *
 * @param index  the index to retrieve, which must be zero
 * @return the value of the field at the specified index
 * @throws IndexOutOfBoundsException if the index is invalid
 */
- (NSInteger)valueAtIndex:(NSInteger)index;

/**
 * Gets the value of a duration field represented by this period.
 * <p>
 * If the field type specified does not match the type used by this class
 * then zero is returned.
 *
 * @param type  the field type to query, nil returns zero
 * @return the value of that field, zero if field not supported
 */
- (NSInteger)get:(HLDurationFieldType*)type;

/**
 * Checks whether the duration field specified is supported by this period.
 *
 * @param type  the type to check, may be nil which returns false
 * @return true if the field is supported
 */
- (BOOL)isSupported:(HLDurationFieldType*)type;

//-----------------------------------------------------------------------
/**
 * Get this period as an immutable <code>Period</code> object.
 * The period will use <code>PeriodType.standard()</code>.
 *
 * @return a <code>Period</code> representing the same number of days
 */
- (HLPeriod*)toPeriod;

/**
 * Get this object as a <code>MutablePeriod</code>.
 * <p>
 * This will always return a new <code>MutablePeriod</code> with the same fields.
 * The period will use <code>PeriodType.standard()</code>.
 * 
 * @return a MutablePeriod using the same field set and values
 */
- (HLMutablePeriod*)toMutablePeriod;

//-----------------------------------------------------------------------
/**
 * Compares this object with the specified object for equality based on the
 * value of each field. All ReadablePeriod instances are accepted, but only
 * those with a matching <code>PeriodType</code> can return true.
 *
 * @param period  a readable period to check against
 * @return true if all the field values are equal, false if
 *  not or the period is nil or of an incorrect type
 */
- (BOOL)isEqualTo:(id)period;

/**
 * Gets a hash code for the period as defined by ReadablePeriod.
 *
 * @return a hash code
 */
- (NSUInteger)hash;

/**
 * Compares this period to another object of the same class.
 *
 * @param other  the other period, must not be nil
 * @return zero if equal, positive if greater, negative if less
 * @throws NullPointerException if the other period is nil
 * @throws ClassCastException if the other period is of a different type
 */
- (NSComparisonResult)compareTo:(id)other;

@end
