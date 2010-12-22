/*
 * HLBasicGJChronology.h
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

#import "Chrono/HLBasicChronology.h"


#define FEB_29 ((31L + 29 - 1) * MILLIS_PER_DAY)

@class HLChronology;

@interface HLBasicGJChronology : HLBasicChronology {
    
@private
    // These arrays are NOT public. We trust ourselves not to alter the array.
    // They use zero-based array indexes so the that valid range of months is
    // automatically checked.
    NSArray* minDaysPerMonth;
    NSArray* maxDaysPerMonth;
    NSArray* minTotalMillisByMonth;
    NSArray* maxTotalMillisByMonth;
}

/**
 * Constructor.
 */
- (id)initWithChronology:(HLChronology*)base
                   param:(id)param
      minDaysInFirstWeek:(NSInteger)minDaysInFirstWeek;

//-----------------------------------------------------------------------
- (NSInteger)monthOfYearFromMillis:(NSInteger)millis
                              year:(NSInteger)year;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)daysInYear:(NSInteger)year
                  month:(NSInteger)month;

//-----------------------------------------------------------------------
- (NSInteger)daysInMonthMax:(NSInteger)month;

//-----------------------------------------------------------------------
- (NSInteger)daysInMonthMaxForSet:(NSInteger)instant
                            value:(NSInteger)value;

//-----------------------------------------------------------------------
- (NSInteger)totalMillisByYearMonth:(NSInteger)year
                              month:(NSInteger)month;

//-----------------------------------------------------------------------
- (NSInteger)yearDifference:(NSInteger)minuendInstant
          subtrahendInstant:(NSInteger)subtrahendInstant;

//-----------------------------------------------------------------------
- (NSInteger)setYear:(NSInteger)instant
                year:(NSInteger)year;

@end
