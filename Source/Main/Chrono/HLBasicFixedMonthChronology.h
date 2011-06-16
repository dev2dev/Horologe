/*
 * HLBasicFixedMonthChronology.h
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
#import "Core/HLDateTimeConstants.h"


/** The length of the month. */
#define MONTH_LENGTH 30

/** The typical millis per year. */
#define MILLIS_PER_YEAR ((NSInteger) (365.25 * MILLIS_PER_DAY))

/** The length of the month in millis. */
#define MILLIS_PER_MONTH (((NSInteger) MONTH_LENGTH) * MILLIS_PER_DAY)

@class HLChronology;

@interface HLBasicFixedMonthChronology : HLBasicChronology {
    
}

//-----------------------------------------------------------------------
/**
 */
- (id)initWithChronology:(HLChronology*)base 
                   param:(id)param 
                    days:(NSInteger)minDaysInFirstWeek;

//-----------------------------------------------------------------------
- (NSInteger)setYear:(NSInteger)instant
                year:(NSInteger)year;

//-----------------------------------------------------------------------
- (NSInteger)yearDifference:(NSInteger)minuendInstant 
          subtrahendInstant:(NSInteger)subtrahendInstant;

//-----------------------------------------------------------------------
- (NSInteger)totalMillisByYearMonth:(NSInteger)year 
                              month:(NSInteger)month;

//-----------------------------------------------------------------------
- (NSInteger)dayOfMonth:(NSInteger)millis;

//-----------------------------------------------------------------------
- (BOOL)isLeapYear:(NSInteger)year;

//-----------------------------------------------------------------------
- (NSInteger)daysInYear:(NSInteger)year
                  month:(NSInteger)month;

//-----------------------------------------------------------------------
- (NSInteger)daysInMonthMax;

//-----------------------------------------------------------------------
- (NSInteger)daysInMonthMax:(NSInteger)month;

//-----------------------------------------------------------------------
- (NSInteger)monthOfYear:(NSInteger)millis;

//-----------------------------------------------------------------------
- (NSInteger)monthOfYear:(NSInteger)millis 
                    year:(NSInteger)year;

//-----------------------------------------------------------------------
- (NSInteger)maxMonth;

//-----------------------------------------------------------------------
- (NSInteger)averageMillisPerYear;

//-----------------------------------------------------------------------
- (NSInteger)averageMillisPerYearDividedByTwo;

//-----------------------------------------------------------------------
- (NSInteger)averageMillisPerMonth;

@end
