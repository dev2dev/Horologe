/*
 * HLInstant.h
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

#import "Base/HLAbstractInstant.h"
#import "HLReadableInstant.h"
#import "HLDateTime.h"
#import "HLReadableDuration.h"
#import "HLChronology.h"
#import "HLMutableDateTime.h"


@interface HLInstant : HLAbstractInstant <HLReadableInstant> {
    
@private
    NSInteger iMillis;
}

//-----------------------------------------------------------------------
/**
 */
- (id)init;

/**
 */
- (id)initWithInstant:(NSInteger)instant;

/**
 */
- (id)initWithObject:(id)instant;

//-----------------------------------------------------------------------
/**
 */
- (HLInstant*)toInstant;

//-----------------------------------------------------------------------
/**
 */
- (HLInstant*)withMillis:(NSInteger)newMillis;

/**
 */
- (HLInstant*)withDurationAdded:(NSInteger)durationToAdd scalar:(NSInteger)scalar;

/**
 */
- (HLInstant*)withReadableDurationAdded:(id<HLReadableDuration>)durationToAdd scalar:(NSInteger)scalar;

//-----------------------------------------------------------------------
/**
 */
- (HLInstant*)plus:(NSInteger)duration;

/**
 */
- (HLInstant*)plusReadableDuration:(id<HLReadableDuration>)duration;

//-----------------------------------------------------------------------
/**
 */
- (HLInstant*)minus:(NSInteger)duration;

/**
 */
- (HLInstant*)minusReadableDuration:(id<HLReadableDuration>)duration;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)millis;

/**
 */
- (HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 */
- (HLDateTime*)toDateTime;

/**
 */
- (HLDateTime*)toDateTimeISO;

/**
 */
- (HLMutableDateTime*)toMutableDateTime;

/**
 */
- (HLMutableDateTime*)toMutableDateTimeISO;

@end
