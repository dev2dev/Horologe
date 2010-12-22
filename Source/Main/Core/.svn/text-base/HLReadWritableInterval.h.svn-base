/*
 * HLReadWritableInterval.h
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

#import "HLReadableInterval.h"


@class HLChronology;

@protocol HLReadWritableInterval <HLReadableInterval>

@required
/**
 */
- (void)setIntervalStart:(NSInteger)startInstant 
                     end:(NSInteger)endInstant;

/**
 */
- (void)setInterval:(id<HLReadableInterval>)interval;

/**
 */
- (void)setIntervalStartInstant:(id<HLReadableInstant>)startInstant 
                     endInstant:(id<HLReadableInstant>)endInstant;

//-----------------------------------------------------------------------
/**
 */
- (void)setChronology:(HLChronology*)chrono;

//-----------------------------------------------------------------------
/**
 */
- (void)setStartMillis:(NSInteger)millisInstant;

/**
 */
- (void)setStart:(id<HLReadableInstant>)instant;

//-----------------------------------------------------------------------
/** 
 */
- (void)setEndMillis:(NSInteger)millisInstant;

/** 
 */
- (void)setEnd:(id<HLReadableInstant>)instant;

//-----------------------------------------------------------------------
/**
 */
- (void)setDurationAfterStart:(id<HLReadableDuration>)duration;

/**
 */
- (void)setDurationBeforeEnd:(id<HLReadableDuration>)duration;

//-----------------------------------------------------------------------
/**
 */
- (void)setPeriodAfterStart:(id<HLReadablePeriod>)period;

/**
 */
- (void)setPeriodBeforeEnd:(id<HLReadablePeriod>)period;

@end
