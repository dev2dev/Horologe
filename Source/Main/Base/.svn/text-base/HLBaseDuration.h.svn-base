/*
 * HLBaseDuration.h
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

#import "Base/HLAbstractDuration.h"
#import "Core/HLReadableDuration.h"


@class HLPeriod;
@class HLChronology;
@class HLPeriodType;
@class HLInterval;
@protocol HLReadableInstant;

@interface HLBaseDuration : HLAbstractDuration <HLReadableDuration> {
    
@private
    /** The duration length */
    NSInteger iMillis;
    
}

- (id)_initWithDuration:(NSInteger)duration;

- (id)_initWithStart:(NSInteger)startInstant
                 end:(NSInteger)endInstant;

- (id)_initWithReadableInstantStart:(id<HLReadableInstant>)start
                                end:(id<HLReadableInstant>)end;

- (id)_initWithObject:(id)duration;
    
//-----------------------------------------------------------------------
/**
 */
- (NSInteger)millis;

//-----------------------------------------------------------------------
/**
 */
- (HLPeriod*)toPeriodFromType:(HLPeriodType*)type;

/**
 */
- (HLPeriod*)toPeriodFromChronology:(HLChronology*)chrono;

/**
 */
- (HLPeriod*)toPeriodFromType:(HLPeriodType*)type 
                   chronology:(HLChronology*)chrono;

/**
 */
- (HLPeriod*)toPeriodFromInstantFrom:(id<HLReadableInstant>)startInstant;

/**
 */
- (HLPeriod*)toPeriodFromInstantFrom:(id<HLReadableInstant>)startInstant 
                                type:(HLPeriodType*)type;

/**
 */
- (HLPeriod*)toPeriodFromInstantTo:(id<HLReadableInstant>)endInstant;

/**
 */
- (HLPeriod*)toPeriodFromInstantTo:(id<HLReadableInstant>)endInstant 
                              type:(HLPeriodType*)type;

/**
 */
- (HLInterval*)toIntervalFromInstantFrom:(id<HLReadableInstant>)startInstant;

/**
 */
- (HLInterval*)toIntervalFromInstantTo:(id<HLReadableInstant>)endInstant;

@end
