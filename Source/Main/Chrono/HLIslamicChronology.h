/*
 * HLIslamicChronology.h
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

#import "HLBasicChronology.h"
#import "HLDateTimeConstants.h"


/**
 * Constant value for 'Anno Hegirae', equivalent
 * to the value returned for AD/CE.
 */
#define AH (CE)

/** The lowest year that can be fully supported. */
#define MIN_YEAR (-292269337)

/**
 * The highest year that can be fully supported.
 * Although calculateFirstDayOfYearMillis can go higher without
 * overflowing, the getYear method overflows when it adds the
 * approximate millis at the epoch.
 */
#define MAX_YEAR (292271022)

/** The days in a pair of months. */
#define MONTH_PAIR_LENGTH (59)

/** The length of the long month. */
#define LONG_MONTH_LENGTH (30)

/** The length of the short month. */
#define SHORT_MONTH_LENGTH (29)

/** The length of the long month in millis. */
#define MILLIS_PER_MONTH_PAIR (59L * MILLIS_PER_DAY)

/** The length of the long month in millis. */
#define MILLIS_PER_MONTH ((NSInteger) (29.53056 * MILLIS_PER_DAY))

/** The length of the long month in millis. */
#define MILLIS_PER_LONG_MONTH (30L * MILLIS_PER_DAY)

/** The typical millis per year. */
#define MILLIS_PER_YEAR ((NSInteger) (354.36667 * MILLIS_PER_DAY))

/** The typical millis per year. */
#define MILLIS_PER_SHORT_YEAR (354L * MILLIS_PER_DAY)

/** The typical millis per year. */
#define MILLIS_PER_LONG_YEAR (355L * MILLIS_PER_DAY)

/** The millis of 0001-01-01. */
#define MILLIS_YEAR_1 (-42521587200000L)
//        -42520809600000L;
//    long start = 0L - 278L * DateTimeConstants.MILLIS_PER_DAY;
//    long cy = 46L * MILLIS_PER_CYCLE;  // 1381-01-01
//    long rem = 5L * MILLIS_PER_SHORT_YEAR +
//            3L * MILLIS_PER_LONG_YEAR;  // 1389-01-01

/** The length of the cycle of leap years. */
#define CYCLE (30)

/** The millis of a 30 year cycle. */
#define MILLIS_PER_CYCLE (((19L * 354L + 11L * 355L) * MILLIS_PER_DAY))


//-----------------------------------------------------------------------
/**
 * Opaque object describing a leap year pattern for the Islamic Chronology.
 *
 * @since 1.2
 */
@interface HLLeapYearPatternType : NSObject {
    
@private
    //        /** Leap year raw data encoded into bits. */
    //        private static final int[][] LEAP_YEARS = {
    //            {2, 5, 7, 10, 13, 15, 18, 21, 24, 26, 29},  // 623158436
    //            {2, 5, 7, 10, 13, 16, 18, 21, 24, 26, 29},  // 623191204
    //            {2, 5, 8, 10, 13, 16, 19, 21, 24, 27, 29},  // 690562340
    //            {0, 2, 5, 8, 11, 13, 16, 19, 21, 24, 27},   // 153692453
    //        };
    
    /** The index. */
    NSInteger index;
    /** The leap year pattern, a bit-based 1=true pattern. */
    NSInteger pattern;
}

/**
 */
- (id)initWithIndex:(NSInteger)index 
            pattern:(NSInteger)pattern;

/**
 */
- (BOOL)isLeapYear:(NSInteger)year;

/**
 */
- (id)readResolve;
@end


//-----------------------------------------------------------------------
@interface HLIslamicChronology : HLBasicChronology {
    
@private
    /** A singleton era field. */
    HLDateTimeField* eraField;
    
    /** Leap year 15-based pattern. */
    HLLeapYearPatternType* leapYear15Based;
    /** Leap year 16-based pattern. */
    HLLeapYearPatternType* leapYear16Based;
    /** Leap year Indian pattern. */
    HLLeapYearPatternType* leapYearIndian;
    /** Leap year Habash al-Hasib pattern. */
    HLLeapYearPatternType* leapYearHabashAlHasib;
    
    /** Cache of zone to chronology arrays */
    NSDictionary* cCache;
    
    /** Singleton instance of a UTC IslamicChronology */
    HLIslamicChronology* instanceUTC;
    
    /** The leap years to use. */
    HLLeapYearPatternType* iLeapYears;    
}

//-----------------------------------------------------------------------
/**
 */
+ (HLIslamicChronology*)instanceUTC;

/**
 */
+ (HLIslamicChronology*)instance;

/**
 */
+ (HLIslamicChronology*)instanceWithZone:(HLDateTimeZone*)zone;

/**
 */
+ (HLIslamicChronology*)instanceWithZone:(HLDateTimeZone*)zone 
                               leapYears:(HLLeapYearPatternType*)leapYears;

// Constructors and instance variables
//-----------------------------------------------------------------------
/**
 */
- (id)initWithChronology:(HLChronology*)base
                   param:(id)param
               leapYears:(HLLeapYearPatternType*)leapYears;

/**
 */
- (id)readResolve;

//-----------------------------------------------------------------------
/**
 */
- (HLLeapYearPatternType*)leapYearPatternType;

// Conversion
//-----------------------------------------------------------------------
/**
 */
- (HLChronology*)withUTC;

/**
 */
- (HLChronology*)withZone:(HLDateTimeZone*)zone;

/**
 */
- (NSInteger)hashCode;

//-----------------------------------------------------------------------
- (NSInteger)year:(NSInteger)instant;

- (NSInteger)setYear:(NSInteger)instant 
                year:(NSInteger)year;

//-----------------------------------------------------------------------
- (NSInteger)getYearDifference:(NSInteger)minuendInstant 
             subtrahendInstant:(NSInteger)subtrahendInstant;

//-----------------------------------------------------------------------
- (NSInteger)totalMillisByYearMonth:(NSInteger)year 
                              month:(NSInteger)month;

//-----------------------------------------------------------------------
- (NSInteger)dayOfMonth:(NSInteger)millis;

//-----------------------------------------------------------------------
- (BOOL)isLeapYear:(NSInteger)year;

//-----------------------------------------------------------------------
- (NSInteger)daysInYearMax;

//-----------------------------------------------------------------------
- (NSInteger)daysInYear:(NSInteger)year;

//-----------------------------------------------------------------------
- (NSInteger)daysInYearMonth:(NSInteger)year 
                       month:(NSInteger)month;

//-----------------------------------------------------------------------
- (NSInteger)daysInMonthMax;

//-----------------------------------------------------------------------
- (NSInteger)daysInMonthMax:(NSInteger)month;

//-----------------------------------------------------------------------
- (NSInteger)monthOfYear:(NSInteger)millis
                    year:(NSInteger)year;

//-----------------------------------------------------------------------
- (NSInteger)averageMillisPerYear;

//-----------------------------------------------------------------------
- (NSInteger)averageMillisPerYearDividedByTwo;

//-----------------------------------------------------------------------
- (NSInteger)averageMillisPerMonth;

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
