/*
 * HLAbstractPeriod.h
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
@class HLPeriod;
@class HLMutablePeriod;
@class HLPeriodFormatter;

@interface HLAbstractPeriod : NSObject <HLReadablePeriod> {

}

//-----------------------------------------------------------------------
/**
 */
- (NSArray*)fieldTypes;

/**
 */
- (NSArray*)values;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)get:(HLDurationFieldType*)type;

/**
 */
- (BOOL)isSupported:(HLDurationFieldType*)type;

/**
 */
- (NSInteger)indexOf:(HLDurationFieldType*)type;

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

//-----------------------------------------------------------------------
/**
 */
- (NSString*)stringWithPeriodFormatter:(HLPeriodFormatter*)formatter;

@end
