/*
 * HLAbstractInterval.h
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

#import "Core/HLReadableInterval.h"


@class HLDateTime;
@class HLReadableInstant;
@class HLInterval;
@class HLMutableInterval;
@class HLDuration;
@class HLPeriod;

@interface HLAbstractInterval : NSObject <HLReadableInterval> {

}

- (id)_init;

- (void)_checkIntervalStart:(NSInteger)start
                        end:(NSInteger)end;

//-----------------------------------------------------------------------
/**
 */
- (HLDateTime*)start;

/** 
 */
- (HLDateTime*)end;

//-----------------------------------------------------------------------
/**
 */
- (BOOL)contains:(NSInteger)millisInstant;

/**
 */
- (BOOL)containsNow;

/**
 */
- (BOOL)containsInstant:(id<HLReadableInstant>)instant;

/**
 */
- (BOOL)containsInterval:(id<HLReadableInterval>)interval;

/**
 */
- (BOOL)overlaps:(id<HLReadableInterval>)interval;

//-----------------------------------------------------------------------
/**
 */
- (BOOL)isBefore:(NSInteger)millisInstant;

/**
 */
- (BOOL)isBeforeNow;

/**
 */
- (BOOL)isBeforeInstant:(id<HLReadableInstant>)instant;

/**
 */
- (BOOL)isBeforeInterval:(id<HLReadableInterval>)interval;

//-----------------------------------------------------------------------
/**
 */
- (BOOL)isAfter:(NSInteger)millisInstant;

/**
 */
- (BOOL)isAfterNow;

/**
 */
- (BOOL)isAfterInstant:(id<HLReadableInstant>)instant;

/**
 */
- (BOOL)isAfterInterval:(id<HLReadableInterval>)interval;

//-----------------------------------------------------------------------
/**
 */
- (HLInterval*)toInterval;

/**
 */
- (HLMutableInterval*)toMutableInterval;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)toDurationMillis;

/**
 */
- (HLDuration*)toDuration;

//-----------------------------------------------------------------------
/**
 */
- (HLPeriod*)toPeriod;

/**
 */
- (HLPeriod*)toPeriod:(HLPeriodType*)type;

//-----------------------------------------------------------------------
/**
 */
- (BOOL)isEqual:(id)readableInterval;

/**
 */
- (NSInteger)hashCode;

@end
