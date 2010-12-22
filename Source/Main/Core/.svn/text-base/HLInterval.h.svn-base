/*
 * HLInterval.h
 * 
 * Horologe
 * Copyright (c) 2010 Pilgrimage Software
 *
 * A Cocoa version of the Joda-Time Java date/time library.
 *
 * Licensed under the Apache License :(Version 2.0 (the "License";
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing :(software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND :(either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

#import "HLBaseInterval.h"
#import "HLReadableInterval.h"
#import "HLChronology.h"
#import "HLReadableInstant.h"
#import "HLReadablePeriod.h"
#import "HLReadableDuration.h"


@interface HLInterval : HLBaseInterval <HLReadableInterval> {
    
}

//-----------------------------------------------------------------------
/**
 */
- (id)initWithStartInstant:(NSInteger)startInstant endInstant:(NSInteger)endInstant;

/**
 */
- (id)initWithStartInstant:(NSInteger)startInstant endInstant:(NSInteger)endInstant zone:(HLDateTimeZone*)zone;

/**
 */
- (id)initWithStartInstant:(NSInteger)startInstant endInstant:(NSInteger)endInstant chronology:(HLChronology*)chronology;

/**
 */
- (id)initWithStartReadableInstant:(id<HLReadableInstant>)start endReadableInstant:(id<HLReadableInstant>)end;

/**
 */
- (id)initWithStartReadableInstant:(id<HLReadableInstant>)start duration:(id<HLReadableDuration>)duration;

/**
 */
- (id)initWithDuration:(id<HLReadableDuration>)duration endInstant:(id<HLReadableInstant>)end;

/**
 */
- (id)initWithStartReadableInstant:(id<HLReadableInstant>)start period:(id<HLReadablePeriod>)period;

/**
 */
- (id)initWithPeriod:(id<HLReadablePeriod>)period end:(id<HLReadableInstant>)end;

/**
 */
- (id)initWithObject:(id)interval;

/**
 */
- (id)initWithObject:(id)interval chronology:(HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 */
- (HLInterval*)toInterval;

//-----------------------------------------------------------------------
/**
 */
- (HLInterval*)overlap:(id<HLReadableInterval>)interval;

//-----------------------------------------------------------------------
/**
 */
- (HLInterval*)gap:(id<HLReadableInterval>)interval;

//-----------------------------------------------------------------------
/**
 */
- (BOOL)abuts:(id<HLReadableInterval>)interval;

//-----------------------------------------------------------------------
/**
 */
- (HLInterval*)withChronology:(HLChronology*)chronology;

/**
 */
- (HLInterval*)withStartMillis:(NSInteger)startInstant;

/**
 */
- (HLInterval*)withStart:(id<HLReadableInstant>)start;

/**
 */
- (HLInterval*)withEndMillis:(NSInteger)endInstant;

/**
 */
- (HLInterval*)withEnd:(id<HLReadableInstant>)end;

//-----------------------------------------------------------------------
/**
 */
- (HLInterval*)withDurationAfterStart:(id<HLReadableDuration>)duration;

/**
 */
- (HLInterval*)withDurationBeforeEnd:(id<HLReadableDuration>)duration;

//-----------------------------------------------------------------------
/**
 */
- (HLInterval*)withPeriodAfterStart:(id<HLReadablePeriod>)period;

/**
 */
- (HLInterval*)withPeriodBeforeEnd:(id<HLReadablePeriod>)period;

@end
