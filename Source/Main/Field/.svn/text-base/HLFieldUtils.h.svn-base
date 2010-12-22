/*
 * HLFieldUtils.h
 * 
 * Horologe
 * Copyright (c) 2010 Pilgrimage Software
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

@interface HLFieldUtils : NSObject {
    
}

//------------------------------------------------------------------------
/**
 */
+ (NSInteger)safeNegate:(NSInteger)value;

/**
 */
+ (NSInteger)safeAddValue:(NSInteger)val1 
                toVAlue:(NSInteger)val2;

/**
 */
+ (NSInteger)safeSubtractValue:(NSInteger)val1 
                     fromValue:(NSInteger)val2;

/**
 */
+ (NSInteger)safeMultiplyValue:(NSInteger)val1 
                     withValue:(NSInteger)val2;

/**
 */
+ (NSInteger)safeToInteger:(NSInteger)value;

//-----------------------------------------------------------------------
/**
 */
+ (void)verifyValueBoundsOfField:(HLDateTimeField*)field
                           value:(NSInteger)value 
                      lowerBound:(NSInteger)lowerBound 
                      upperBound:(NSInteger)upperBound;

/**
 */
+ (void)verifyValueBoundsOfFieldType:(HLDateTimeFieldType*)fieldType
                               value:(NSInteger)value 
                          lowerBound:(NSInteger)lowerBound 
                          upperBound:(NSInteger)upperBound;

/**
 */
+ (void)verifyValueBounds:(NSString*)fieldName
                    value:(NSInteger)value 
               lowerBound:(NSInteger)lowerBound 
               upperBound:(NSInteger)upperBound;

/**
 */
+ (NSInteger)getWrappedValue:(NSInteger)currentValue 
                   wrapValue:(NSInteger)wrapValue
                    minValue:(NSInteger)minValue 
                    maxValue:(NSInteger)maxValue;

/**
 */
+ (NSInteger)getWrappedValue:(NSInteger)value 
                    minValue:(NSInteger)minValue 
                    maxValue:(NSInteger)maxValue;

//-----------------------------------------------------------------------
/**
 */
+ (BOOL)isObject:(id)object1 
   equalToObject:(id)object2;

@end
