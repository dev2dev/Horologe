/*
 * HLAbstractDuration.h
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

#import "Core/HLReadableDuration.h"


@class HLDuration;
@class HLPeriod;

@interface HLAbstractDuration : NSObject <HLReadableDuration> {

}

- (id)_init;

//-----------------------------------------------------------------------
/**
 */
- (HLDuration*)toDuration;

//-----------------------------------------------------------------------
/**
 */
- (HLPeriod*)toPeriod;

//-----------------------------------------------------------------------
/**
 */
- (NSComparisonResult)compareTo:(id<HLReadableDuration>)other;

/**
 */
- (BOOL)isEqualDuration:(id<HLReadableDuration>)duration;

/**
 */
- (BOOL)isLongerThan:(id<HLReadableDuration>)duration;

/**
 */
- (BOOL)isShorterThan:(id<HLReadableDuration>)duration;

//-----------------------------------------------------------------------
/**
 */
- (BOOL)isEqual:(id)duration;

/**
 */
- (NSInteger)hashCode;

@end
