/*
 * HLEthiopicChronology.h
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

#import "HLBasicFixedMonthChronology.h"
#import "HLDateTimeConstants.h"
#import "HLChronology.h"
#import "HLDateTimeZone.h"


/**
 * Constant value for 'Ethiopean Era', equivalent
 * to the value returned for AD/CE.
 */
#define EE (CE)

/** The lowest year that can be fully supported. */
#define MIN_YEAR (-292269337)

/** The highest year that can be fully supported. */
#define MAX_YEAR (292272984)

@interface HLEthiopicChronology : HLBasicFixedMonthChronology {
    
@private
    /** A singleton era field. */
    HLDateTimeField* eraField;
    
    /** Cache of zone to chronology arrays */
    NSDictionary* cCache;
    
    /** Singleton instance of a UTC EthiopicChronology */
    HLEthiopicChronology* instanceUTC;
}

//-----------------------------------------------------------------------
/**
 */
+ (HLEthiopicChronology*)instanceUTC;

/**
 */
+ (HLEthiopicChronology*)instance;

/**
 */
+ (HLEthiopicChronology*)instanceWithZone:(HLDateTimeZone*)zone;

/**
 */
+ (HLEthiopicChronology*)instanceWithZone:(HLDateTimeZone*)zone
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

//-----------------------------------------------------------------------
- (NSInteger)calculateFirstDayOfYearMillis:(NSInteger)year;

//-----------------------------------------------------------------------
- (NSInteger)minYear;

//-----------------------------------------------------------------------
- (NSInteger)maxYear;

//-----------------------------------------------------------------------
- (NSInteger)approxMillisAtEpochDividedByTwo;

//-----------------------------------------------------------------------
- (void)assemble:(HLFields*)fields;

@end
