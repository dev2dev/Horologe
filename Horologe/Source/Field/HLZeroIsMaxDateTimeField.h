/*
 * ZeroIsMaxDateTimeField.h
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

#import "HLDecoratedDateTimeField.h"


@class HLDateTimeField;
@class HLDateTimeFieldType;
@class HLDurationField;
@protocol HLReadablePartial;

/**
 * Wraps another field such that zero values are replaced with one more than
 * it's maximum. This is particularly useful for implementing an clockhourOfDay
 * field, where the midnight value of 0 is replaced with 24.
 * <p>
 * ZeroIsMaxDateTimeField is thread-safe and immutable.
 *
 * @author Brian S O'Neill
 * @since 1.0
 */
@interface HLZeroIsMaxDateTimeField : HLDecoratedDateTimeField {
    
@private
    
}

/**
 * Constructor.
 * 
 * @param field  the base field
 * @param type  the field type this field will actually use
 * @throws IllegalArgumentException if wrapped field's minimum value is not zero
 */
- (id)initWithDateTimeField:(HLDateTimeField*)field
                       type:(HLDateTimeFieldType*)type;

- (NSInteger)valueWithInstantValue:(NSInteger)instant;

- (NSInteger)addValue:(NSInteger)value
       toInstantValue:(NSInteger)instant;

- (NSInteger)addWrapFieldInstantValue:(NSInteger)instant 
                                value:(NSInteger)value;

- (NSArray*)addWrapFieldPartial:(id<HLReadablePartial>)instant 
                          index:(NSInteger)fieldIndex
                         values:(NSArray*)values 
                     valueToAdd:(NSInteger)valueToAdd;

- (NSInteger)differenceWithMinuend:(NSInteger)minuendInstant 
                        subtrahend:(NSInteger)subtrahendInstant;

- (NSInteger)setInstantValue:(NSInteger)instant 
                       value:(NSInteger)value;

- (BOOL)isLeap:(NSInteger)instant;

- (NSInteger)leapAmountWithInstantValue:(NSInteger)instant;

- (HLDurationField*)leapDurationField;

/**
 * Always returns 1.
 * 
 * @return the minimum value of 1
 */
- (NSInteger)minimumValue;

/**
 * Always returns 1.
 * 
 * @return the minimum value of 1
 */
- (NSInteger)minimumValue:(NSInteger)instant;

/**
 * Always returns 1.
 * 
 * @return the minimum value of 1
 */
- (NSInteger)minimumValueWithPartial:(id<HLReadablePartial>)instant;

/**
 * Always returns 1.
 * 
 * @return the minimum value of 1
 */
- (NSInteger)minimumValueWithPartial:(id<HLReadablePartial>)instant
                              values:(NSArray*)values;

/**
 * Get the maximum value for the field, which is one more than the wrapped
 * field's maximum value.
 * 
 * @return the maximum value
 */
- (NSInteger)maximumValue;

/**
 * Get the maximum value for the field, which is one more than the wrapped
 * field's maximum value.
 * 
 * @return the maximum value
 */
- (NSInteger)maximumValueWithInstantValue:(NSInteger)instant;

/**
 * Get the maximum value for the field, which is one more than the wrapped
 * field's maximum value.
 * 
 * @return the maximum value
 */
- (NSInteger)maximumValueWithPartial:(id<HLReadablePartial>)instant;

/**
 * Get the maximum value for the field, which is one more than the wrapped
 * field's maximum value.
 * 
 * @return the maximum value
 */
- (NSInteger)maximumValue:(id<HLReadablePartial>)instant
                   values:(NSArray*)values;

- (NSInteger)roundFloor:(NSInteger)instant;

- (NSInteger)roundCeiling:(NSInteger)instant;

- (NSInteger)roundHalfFloor:(NSInteger)instant;

- (NSInteger)roundHalfCeiling:(NSInteger)instant;

- (NSInteger)roundHalfEven:(NSInteger)instant;

- (NSInteger)remainder:(NSInteger)instant;

@end
