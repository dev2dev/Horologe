/*
 * HLGregorianChronology.h
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


#define MILLIS_PER_YEAR ((NSInteger)(365.2425 * MILLIS_PER_DAY))
#define MILLIS_PER_MONTH ((NSInteger) (365.2425 * MILLIS_PER_DAY / 12))
#define DAYS_0000_TO_1970 (719527)

/** The lowest year that can be fully supported. */
#define MIN_YEAR (-292275054)

/** The highest year that can be fully supported. */
#define MAX_YEAR (292278993)

@interface HLGregorianChronology : HLBasicGJChronology {

    @private
    /** Singleton instance of a UTC GregorianChronology */
    HLGregorianChronology* instanceUTC;

    /** Cache of zone to chronology arrays */
    NSDictionary* cCache;
}

/**
 */
+ (HLGregorianChronology*)instanceUTC;

/**
 */
+ (HLGregorianChronology*)instance;

/**
 */
+ (HLGregorianChronology*)instanceWithZone:(HLDateTimeZone*)zone;

/**
 */
+ (HLGregorianChronology*)instanceWithZone:(HLDateTimeZone*)zone
                        minDaysInFirstWeek:(NSInteger)minDaysInFirstWeek;

// Constructors and instance variables
//-----------------------------------------------------------------------

/**
 */
- (id)initWithChronology:(HLChronology *)base 
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

- (void)assemble:(HLFields*)fields;

- (BOOL)isLeapYear:(NSInteger)year;

- (NSInteger)calculateFirstDayOfYearMillis:(NSInteger)year;

- (NSInteger)minYear;

- (NSInteger)maxYear;

- (NSInteger)averageMillisPerYear;

- (NSInteger)averageMillisPerYearDividedByTwo;

- (NSInteger)averageMillisPerMonth;

- (NSInteger)approxMillisAtEpochDividedByTwo;

@end
