/*
 * HLReadWritablePeriod.h
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

#import "HLReadablePeriod.h"


@class HLDurationFieldType;
@protocol HLReadableInterval;

@protocol HLReadWritablePeriod <HLReadablePeriod>

@required
/**
 */
- (void)clear;

/**
 */
- (void)setValue:(NSInteger)value 
         atIndex:(NSInteger)index;

/**
 */
- (void)setField:(HLDurationFieldType*)field 
           value:(NSInteger)value;

/**
 */
- (void)setPeriod:(id<HLReadablePeriod>)period;

/**
 */
- (void)setPeriodYears:(NSInteger)years 
                months:(NSInteger)months 
                 weeks:(NSInteger)weeks 
                  days:(NSInteger)days
                 hours:(NSInteger)hours 
               minutes:(NSInteger)minutes 
               seconds:(NSInteger)seconds 
                millis:(NSInteger)millis;

/**
 */
- (void)setInterval:(id<HLReadableInterval>)interval;

//-----------------------------------------------------------------------
/**
 */
- (void)addField:(HLDurationFieldType*)field 
           value:(NSInteger)value;

/**
 */
- (void)addPeriod:(id<HLReadablePeriod>)period;

/**
 */
- (void)addYears:(NSInteger)years 
          months:(NSInteger)months 
           weeks:(NSInteger)weeks 
            days:(NSInteger)days
           hours:(NSInteger)hours 
         minutes:(NSInteger)minutes 
         seconds:(NSInteger)seconds 
          millis:(NSInteger)millis;

/**
 */
- (void)addInterval:(id<HLReadableInterval>)interval;

//-----------------------------------------------------------------------
/**
 */
- (void)setYears:(NSInteger)years;

/**
 */
- (void)addYears:(NSInteger)years;

//-----------------------------------------------------------------------
/**
 */
- (void)setMonths:(NSInteger)months;

/**
 */
- (void)addMonths:(NSInteger)months;

//-----------------------------------------------------------------------
/**
 */
- (void)setWeeks:(NSInteger)weeks;

/**
 */
- (void)addWeeks:(NSInteger)weeks;

//-----------------------------------------------------------------------
/**
 */
- (void)setDays:(NSInteger)days;

/**
 */
- (void)addDays:(NSInteger)days;

//-----------------------------------------------------------------------
/**
 */
- (void)setHours:(NSInteger)hours;

/**
 */
- (void)addHours:(NSInteger)hours;

//-----------------------------------------------------------------------
/**
 */
- (void)setMinutes:(NSInteger)minutes;

/**
 */
- (void)addMinutes:(NSInteger)minutes;

//-----------------------------------------------------------------------
/**
 */
- (void)setSeconds:(NSInteger)seconds;

/**
 */
- (void)addSeconds:(NSInteger)seconds;

//-----------------------------------------------------------------------
/**
 */
- (void)setMillis:(NSInteger)millis;

/**
 */
- (void)addMillis:(NSInteger)millis;

@end
