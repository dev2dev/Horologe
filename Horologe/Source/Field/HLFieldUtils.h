/*
 * FieldUtils.h
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


@class HLDateTimeField;
@class HLDateTimeFieldType;

/**
 * General utilities that don't fit elsewhere.
 * <p>
 * FieldUtils is thread-safe and immutable.
 *
 * @author Stephen Colebourne
 * @since 1.0
 */
@interface HLFieldUtils : NSObject {
    
@private
    
}

//------------------------------------------------------------------------
/**
 * Negates the input throwing an exception if it can't negate it.
 * 
 * @param value  the value to negate
 * @return the negated value
 * @throws ArithmeticException if the value is Integer.MIN_VALUE
 * @since 1.1
 */
+ (NSInteger)safeNegate:(NSInteger)value;

/**
 * Add two values throwing an exception if overflow occurs.
 * 
 * @param val1  the first value
 * @param val2  the second value
 * @return the new total
 * @throws ArithmeticException if the value is too big or too small
 */
+ (NSInteger)safeAddValue:(NSInteger)val1 
                 andValue:(NSInteger)val2;

/**
 * Subtracts two values throwing an exception if overflow occurs.
 * 
 * @param val1  the first value, to be taken away from
 * @param val2  the second value, the amount to take away
 * @return the new total
 * @throws ArithmeticException if the value is too big or too small
 */
+ (NSInteger)safeSubtractValue:(NSInteger)val1 
                      andValue:(NSInteger)val2;

/**
 * Multiply two values throwing an exception if overflow occurs.
 * 
 * @param val1  the first value
 * @param val2  the second value
 * @return the new total
 * @throws ArithmeticException if the value is too big or too small
 * @since 1.2
 */
+ (NSInteger)safeMultiplyValue:(NSInteger)val1 
                      andValue:(NSInteger)val2;

/**
 * Multiply two values throwing an exception if overflow occurs.
 * 
 * @param val1  the first value
 * @param scalar  the second value
 * @return the new total
 * @throws ArithmeticException if the value is too big or too small
 * @since 1.2
 */
+ (NSInteger)safeMultiplyValue:(NSInteger)val1 
                     andScalar:(NSInteger)scalar;

/**
 * Multiply two values throwing an exception if overflow occurs.
 * 
 * @param val1  the first value
 * @param val2  the second value
 * @return the new total
 * @throws ArithmeticException if the value is too big or too small
 */
+ (NSInteger)safeMultiplyValue:(NSInteger)val1 
                      andValue:(NSInteger)val2;

/**
 * Casts to an int throwing an exception if overflow occurs.
 * 
 * @param value  the value
 * @return the value as an int
 * @throws ArithmeticException if the value is too big or too small
 */
+ (NSInteger)safeToInteger:(NSInteger)value;

/**
 * Multiply two values to return an int throwing an exception if overflow occurs.
 * 
 * @param val1  the first value
 * @param val2  the second value
 * @return the new total
 * @throws ArithmeticException if the value is too big or too small
 */
+ (NSInteger)safeMultiplyToIntegerValue:(NSInteger)val1 
                               andValue:(NSInteger)val2;

//-----------------------------------------------------------------------
/**
 * Verify that input values are within specified bounds.
 * 
 * @param value  the value to check
 * @param lowerBound  the lower bound allowed for value
 * @param upperBound  the upper bound allowed for value
 * @throws IllegalFieldValueException if value is not in the specified bounds
 */
+ (void)verifyValueBoundsOfField:(HLDateTimeField*)field
                           value:(NSInteger)value 
                      lowerBound:(NSInteger)lowerBound 
                      upperBound:(NSInteger)upperBound;

/**
 * Verify that input values are within specified bounds.
 * 
 * @param value  the value to check
 * @param lowerBound  the lower bound allowed for value
 * @param upperBound  the upper bound allowed for value
 * @throws IllegalFieldValueException if value is not in the specified bounds
 * @since 1.1
 */
+ (void)verifyValueBoundsInFieldType:(HLDateTimeFieldType*)fieldType 
                               value:(NSInteger)value 
                          lowerBound:(NSInteger)lowerBound 
                          upperBound:(NSInteger)upperBound;

/**
 * Verify that input values are within specified bounds.
 * 
 * @param value  the value to check
 * @param lowerBound  the lower bound allowed for value
 * @param upperBound  the upper bound allowed for value
 * @throws IllegalFieldValueException if value is not in the specified bounds
 */
+ (void)verifyValueBoundsInFieldName:(NSString*)fieldName
                               value:(NSInteger)value 
                          lowerBound:(NSInteger)lowerBound 
                          upperBound:(NSInteger)upperBound;

/**
 * Utility method used by addWrapField implementations to ensure the new
 * value lies within the field's legal value range.
 *
 * @param currentValue the current value of the data, which may lie outside
 * the wrapped value range
 * @param wrapValue  the value to add to current value before
 *  wrapping.  This may be negative.
 * @param minValue the wrap range minimum value.
 * @param maxValue the wrap range maximum value.  This must be
 *  greater than minValue (checked by the method).
 * @return the wrapped value
 * @throws IllegalArgumentException if minValue is greater
 *  than or equal to maxValue
 */
+ (NSInteger)wrappedValue:(NSInteger)currentValue 
                wrapValue:(NSInteger)wrapValue
                 minValue:(NSInteger)minValue 
                 maxValue:(NSInteger)maxValue;

/**
 * Utility method that ensures the given value lies within the field's
 * legal value range.
 * 
 * @param value  the value to fit into the wrapped value range
 * @param minValue the wrap range minimum value.
 * @param maxValue the wrap range maximum value.  This must be
 *  greater than minValue (checked by the method).
 * @return the wrapped value
 * @throws IllegalArgumentException if minValue is greater
 *  than or equal to maxValue
 */
+ (NSInteger)wrappedValue:(NSInteger)value 
                 minValue:(NSInteger)minValue 
                 maxValue:(NSInteger)maxValue;

//-----------------------------------------------------------------------
/**
 * Compares two objects as equals handling nil.
 * 
 * @param object1  the first object
 * @param object2  the second object
 * @return true if equal
 * @since 1.4
 */
+ (BOOL)isObject:(id)object1
   equalToObject:(id)object2;

@end
