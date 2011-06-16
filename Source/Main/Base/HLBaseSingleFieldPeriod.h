/*
 * HLBaseSingleFieldPeriod.h
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

#import "Core/HLReadablePeriod.h"


@class HLDurationFieldType;
@class HLPeriodType;
@class HLPeriod;
@class HLMutablePeriod;
@class HLBaseSingleFieldPeriod;
@protocol HLReadablePartial;
@protocol HLReadableInstant;

@interface HLBaseSingleFieldPeriod : NSObject <HLReadablePeriod> {
    
@private
    /** The period in the units of this period. */
    NSInteger iPeriod;
    
}

//-----------------------------------------------------------------------
/**
 */
+ (NSInteger)betweenInstantStart:(id<HLReadableInstant>)start 
                             end:(id<HLReadableInstant>)end 
                           field:(HLDurationFieldType*)field;

//-----------------------------------------------------------------------
/**
 */
+ (NSInteger)betweenPartialStart:(id<HLReadablePartial>)start 
                             end:(id<HLReadablePartial>)end 
                          period:(id<HLReadablePeriod>)zeroInstance;

/**
 */
+ (NSInteger)standardPeriodInPeriod:(id<HLReadablePeriod>)period 
                      millisPerUnit:(long)millisPerUnit;

//-----------------------------------------------------------------------
/**
 */
- (id)initWithPeriod:(NSInteger)period;

//-----------------------------------------------------------------------
/**
 */
- (HLDurationFieldType*)fieldType; /* abstract */

/**
 */
- (HLPeriodType*)periodType; /* abstract */

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)size;

/**
 */
- (HLDurationFieldType*)fieldTypeAtIndex:(NSInteger)index;

/**
 */
- (NSInteger)valueAtIndex:(NSInteger)index;

/**
 */
- (NSInteger)get:(HLDurationFieldType*)type;

/**
 */
- (BOOL)isSupported:(HLDurationFieldType*)type;

//-----------------------------------------------------------------------
/**
 */
- (HLPeriod*)toPeriod;

/**
 */
- (HLMutablePeriod*)toMutablePeriod;

//-----------------------------------------------------------------------
/**
 */
- (BOOL)isEqual:(id)period;

/**
 */
- (NSInteger)hashCode;

/**
 */
- (NSInteger)compareTo:(HLBaseSingleFieldPeriod*)other;

@end
