/*
 * FieldUtils.m
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

#import "HLFieldUtils.h"

#import "HLConstants.h"
#import "HLDateTimeFieldType.h"
#import "HLDateTimeField.h"


@implementation HLFieldUtils

//------------------------------------------------------------------------
+ (NSInteger)safeNegate:(NSInteger)value {
    if (value == NSIntegerMin) {
        [NSException raise:HL_ARITHMETIC_EXCEPTION 
                    format:@"Integer minimum value cannot be negated"];
    }
    
    return -value;
}

+ (NSInteger)safeAddValue:(NSInteger)val1 
                 andValue:(NSInteger)val2 {
    NSInteger sum = val1 + val2;
    // If there is a sign change, but the two values have the same sign...
    if ((val1 ^ sum) < 0 && (val1 ^ val2) >= 0) {
        [NSException raise:HL_ARITHMETIC_EXCEPTION 
                    format:@"The calculation caused an overflow: %ld + %ld", val1, val2];
    }
    
    return sum;
}

+ (NSInteger)safeSubtractValue:(NSInteger)val1 
                      andValue:(NSInteger)val2 {
    NSInteger diff = val1 - val2;
    // If there is a sign change, but the two values have different signs...
    if ((val1 ^ diff) < 0 && (val1 ^ val2) < 0) {
        [NSException raise:HL_ARITHMETIC_EXCEPTION 
                    format:@"The calculation caused an overflow: %ld - %ld", val1, val2];
    }
    
    return diff;
}

+ (NSInteger)safeMultiply:(NSInteger)val1 
                 andValue:(NSInteger)val2 {
    NSInteger total = (NSInteger) val1 * (NSInteger) val2;
    if (total < NSIntegerMin || total > NSIntegerMax) {
        [NSException raise:HL_ARITHMETIC_EXCEPTION 
                    format:@"The calculation caused an overflow: %ld * %ld", val1, val2];
    }
    return (int) total;
}

+ (NSInteger)safeMultiply:(NSInteger)val1 
                andScalar:(NSInteger)scalar {
    switch (scalar) {
        case -1:
            return -val1;
        case 0:
            return 0L;
        case 1:
            return val1;
    }
    NSInteger total = val1 * scalar;
    if (total / scalar != val1) {
        [NSException raise:HL_ARITHMETIC_EXCEPTION 
                    format:@"The calculation caused an overflow: %ld * %ld", val1, scalar];
    }
    return total;
}

+ (NSInteger)safeMultiplyValue:(NSInteger)val1 
                      andValue:(NSInteger)val2 {
    if (val2 == 1) {
        return val1;
    }
    if (val2 == 0) {
        return 0;
    }
    
    NSInteger total = val1 * val2;
    if (total / val2 != val1) {
        [NSException raise:HL_ARITHMETIC_EXCEPTION 
                    format:@"The calculation caused an overflow: %ld * %ld", val1, val2];
    }
    
    return total;
}

+ (NSInteger)safeToInteger:(NSInteger)value {
    if (NSIntegerMin <= value &&
        value <= NSIntegerMax) {
        return (NSInteger) value;
    }
    
    [NSException raise:HL_ARITHMETIC_EXCEPTION 
                format:@"Value cannot fit in a long integer: %ld", value];
}

+ (NSInteger)safeMultiplyToIntegerValue:(NSInteger)val1 andValue:(NSInteger)val2 {
    NSInteger val = [HLFieldUtils safeMultiplyValue:val1
                                           andValue:val2];
    return [HLFieldUtils safeToInteger:val];
}

//-----------------------------------------------------------------------
+ (void)verifyValueBoundsOfField:(HLDateTimeField*)field
                           value:(NSInteger)value 
                      lowerBound:(NSInteger)lowerBound 
                      upperBound:(NSInteger)upperBound {
    
    if ((value < lowerBound) || 
        (value > upperBound)) {
        [NSException raise:HL_ILLEGAL_FIELD_VALUE_EXCEPTION
                    format:@"Type: %@, value: %ld, lower-bound: %ld, upper-bound: %ld",
         [field type], value, lowerBound, upperBound];
    }
}

+ (void)verifyValueBoundsInFieldType:(HLDateTimeFieldType*)fieldType 
                               value:(NSInteger)value
                          lowerBound:(NSInteger)lowerBound 
                          upperBound:(NSInteger)upperBound {
    
    if ((value < lowerBound) || 
        (value > upperBound)) {
        [NSException raise:HL_ILLEGAL_FIELD_VALUE_EXCEPTION
                    format:@"Type: %@, value: %ld, lower-bound: %ld, upper-bound: %ld",
         [field type], value, lowerBound, upperBound];
    }
}

+ (void)verifyValueBoundsInFieldName:(NSString*)fieldName 
                               value:(NSInteger)value 
                          lowerBound:(NSInteger)lowerBound 
                          upperBound:(NSInteger)upperBound {
    
    if ((value < lowerBound) || 
        (value > upperBound)) {
        [NSException raise:HL_ILLEGAL_FIELD_VALUE_EXCEPTION
                    format:@"Type: %@, value: %ld, lower-bound: %ld, upper-bound: %ld",
         [field type], value, lowerBound, upperBound];
    }
}

+ (NSInteger)wrappedValue:(NSInteger)currentValue 
                wrapValue:(NSInteger)wrapValue
                 minValue:(NSInteger)minValue 
                 maxValue:(NSInteger)maxValue {
    return [HLFieldUtils wrappedValue:(currentValue + wrapValue)
                             minValue:minValue
                             maxValue:maxValue];
}

+ (NSInteger)wrappedValue:(NSInteger)value 
                 minValue:(NSInteger)minValue 
                 maxValue:(NSInteger)maxValue {
    if (minValue >= maxValue) {
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"MIN > MAX"];
    }
    
    NSInteger wrapRange = maxValue - minValue + 1;
    value -= minValue;
    
    if (value >= 0) {
        return (value % wrapRange) + minValue;
    }
    
    NSInteger remByRange = (-value) % wrapRange;
    
    if (remByRange == 0) {
        return 0 + minValue;
    }
    return (wrapRange - remByRange) + minValue;
}

//-----------------------------------------------------------------------
+ (BOOL)isObject:(id)object1
   equalToObject:(id)object2 {
    if (object1 == object2) {
        return YES;
    }
    if (object1 == nil || object2 == nil) {
        return NO;
    }
    return [object1 isEqual:object2];
}

@end
