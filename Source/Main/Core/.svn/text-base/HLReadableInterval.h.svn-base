/*
 * HLReadableInterval.h
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


@class HLChronology;
@class HLDateTime;
@class HLInterval;
@class HLMutableInterval;
@class HLDuration;
@class HLPeriod;
@class HLPeriodType;
@protocol HLReadableInstant;

@protocol HLReadableInterval <NSObject>

@required
/**
 */
- (HLChronology*)chronology;

/**
 */
- (NSInteger)startMillis;

/**
 */
- (HLDateTime*)start;

/** 
 */
- (NSInteger)endMillis;

/** 
 */
- (HLDateTime*)end;

//-----------------------------------------------------------------------
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
- (BOOL)isAfterInstant:(id<HLReadableInstant>)instant;

/**
 */
- (BOOL)isAfterInterval:(id<HLReadableInterval>)interval;

/**
 */
- (BOOL)isBeforeInstant:(id<HLReadableInstant>)instant;

/**
 */
- (BOOL)isBeforeInterval:(id<HLReadableInterval>)interval;

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
- (HLDuration*)toDuration;

/**
 */
- (NSInteger)toDurationMillis;

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
    
