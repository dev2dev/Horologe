/*
 * HLJulianChronology.h
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

#import "HLBasicGJChronology.h"
#import "HLDateTimeConstants.h"
#import "HLChronology.h"
#import "HLDateTimeZone.h"


#define MILLIS_PER_YEAR ((NSInteger) (365.25 * MILLIS_PER_DAY))

#define MILLIS_PER_MONTH ((NSInteger) (365.25 * DateTimeConstants.MILLIS_PER_DAY / 12))

/** The lowest year that can be fully supported. */
#define MIN_YEAR (-292269054)

/** The highest year that can be fully supported. */
#define MAX_YEAR (292272992)

@interface HLJulianChronology : HLBasicGJChronology {
    
@private
    /** Singleton instance of a UTC JulianChronology */
    HLJulianChronology* instanceUTC;
    
    /** Cache of zone to chronology arrays */
    NSDictionary* cCache;    
}

+ (NSInteger)adjustYearForSet:(NSInteger)year;

/**
 */
+ (HLJulianChronology*)getInstanceUTC;

/**
 */
+ (HLJulianChronology*)getInstance;

/**
 */
+ (HLJulianChronology*)getInstance:(HLDateTimeZone*)zone;

/**
 */
+ (HLJulianChronology*)getInstance:(HLDateTimeZone*)zone 
                minDaysInFirstWeek:(NSInteger)minDaysInFirstWeek;

// Constructors and instance variables
//-----------------------------------------------------------------------

/**
 */
- (id)initWithChronology:(HLChronology*)base
                   param:(id)param 
      minDaysInFirstWeek:(NSInteger)minDaysInFirstWeek;

/**
 */
- (id)readResolve;

// Conversion
//-----------------------------------------------------------------------
/**
 */
- (HLChronology*)withUTC;

/**
 */
- (HLChronology*)withZone:(HLDateTimeZone*)zone;

- (NSInteger)dateMidnightMillis:(NSInteger)year 
                    monthOfYear:(NSInteger)monthOfYear 
                     dayOfMOnth:(NSInteger)dayOfMonth;

- (BOOL)isLeapYear:(NSInteger)year;

- (NSInteger)calculateFirstDayOfYearMillis:(NSInteger)year;

- (NSInteger)minYear;

- (NSInteger)maxYear;

- (NSInteger)averageMillisPerYear;

- (NSInteger)averageMillisPerYearDividedByTwo;

- (NSInteger)averageMillisPerMonth;

- (NSInteger)approxMillisAtEpochDividedByTwo;

- (void)assemble:(HLFields*)fields;

@end
