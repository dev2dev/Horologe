/*
 * HLBasicChronology.h
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

#import "Chrono/HLAssembledChronology.h"
#import "Core/HLPreciseDateTimeField.h"


#define CACHE_SIZE (1 << 10)
#define CACHE_MASK (CACHE_SIZE - 1)

@class HLDurationField;
@class HLDateTimeField;
@class HLChronology;
@class HLDateTimeZone;

@interface HLYearInfo : NSObject {
@public
    NSInteger iYear;
    NSInteger iFirstDayMillis;
}

- (id)initWithYear:(NSInteger)year 
            millis:(NSInteger)firstDayMillis;

@end


@interface HLHalfdayField : HLPreciseDateTimeField {
    
}

- (NSString*)asText:(NSInteger)fieldValue 
             locale:(NSLocale*)locale;

- (NSInteger)setMillis:(NSInteger)millis 
                  text:(NSString*)text 
                locale:(NSLocale*)locale;

- (NSInteger)maximumTextLength:(NSLocale*)locale;

@end


@interface HLBasicChronology : HLAssembledChronology {
    
@private
    HLDurationField* cMillisField;
    HLDurationField* cSecondsField;
    HLDurationField* cMinutesField;
    HLDurationField* cHoursField;
    HLDurationField* cHalfdaysField;
    HLDurationField* cDaysField;
    HLDurationField* cWeeksField;
    
    HLDateTimeField* cMillisOfSecondField;
    HLDateTimeField* cMillisOfDayField;
    HLDateTimeField* cSecondOfMinuteField;
    HLDateTimeField* cSecondOfDayField;
    HLDateTimeField* cMinuteOfHourField;
    HLDateTimeField* cMinuteOfDayField;
    HLDateTimeField* cHourOfDayField;
    HLDateTimeField* cHourOfHalfdayField;
    HLDateTimeField* cClockhourOfDayField;
    HLDateTimeField* cClockhourOfHalfdayField;
    HLDateTimeField* cHalfdayOfDayField;
    
    HLYearInfo* iYearInfoCache[CACHE_SIZE];
    
    NSInteger iMinDaysInFirstWeek;
}

- (id)initWithChronology:(HLChronology*)base 
                   param:(id)param 
                 minDays:(NSInteger)minDaysInFirstWeek;

- (HLDateTimeZone*)zone;

- (NSInteger)dateTimeMillisFromYear:(NSInteger)year 
                              month:(NSInteger)monthOfYear
                                day:(NSInteger)dayOfMonth
                             millis:(NSInteger)millisOfDay;

- (NSInteger)dateTimeMillisFromYear:(NSInteger)year
                              month:(NSInteger)monthOfYear
                                day:(NSInteger)dayOfMonth
                               hour:(NSInteger)hourOfDay
                             minute:(NSInteger)minuteOfHour
                             second:(NSInteger)secondOfMinute
                             millis:(NSInteger)millisOfSecond;

- (NSInteger)minimumDaysInFirstWeek;

/**
 */
- (BOOL)isEqual:(id)object;

/**
 */
- (NSInteger)hashCode;

// Output
//-----------------------------------------------------------------------
/**
 */
- (NSString*)string;

- (void)assemble(HLFields*)fields;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)daysInYearMax;

/**
 */
- (NSInteger)daysInYear:(NSInteger)year;

/**
 */
- (NSInteger)weeksInYear:(NSInteger)year;

/**
 */
- (NSInteger)firstWeekOfYearMillis:(NSInteger)year;

/**
 */
- (NSInteger)yearMillis:(NSInteger)year;

/**
 */
- (NSInteger)yearMonthMillis:(NSInteger)year 
                       month:(NSInteger)month;

/**
 */
- (NSInteger)yearMonthDayMillis:(NSInteger)year
                          month:(NSInteger)month
                            day:(NSInteger)dayOfMonth;

/**
 */
- (NSInteger)yearFromInstant:(NSInteger)instant;

/**
 */
- (NSInteger)monthOfYear:(NSInteger)millis;

/**
 */
- (NSInteger)monthOfYear:(NSInteger)millis year:(NSInteger)year;

/**
 */
- (NSInteger)dayOfMonth:(NSInteger)millis;

/**
 */
- (NSInteger)dayOfMonth:(NSInteger)millis 
                   year:(NSInteger)year;

/**
 */
- (NSInteger)dayOfMonth:(NSInteger)millis 
                   year:(NSInteger)year 
                  month:(NSInteger)month;

/**
 */
- (NSInteger)dayOfYear:(NSInteger)instant;

/**
 */
- (NSInteger)dayOfYear:(NSInteger)instant 
                  year:(NSInteger)year;

/**
 */
- (NSInteger)weekyear:(NSInteger)instant;

/**
 */
- (NSInteger)weekOfWeekyear:(NSInteger)instant;

/**
 */
- (NSInteger)weekOfWeekyear:(NSInteger)instant 
                       year:(NSInteger)year;

/**
 */
- (NSInteger)dayOfWeek:(NSInteger)instant;

/**
 */
- (NSInteger)millisOfDay:(NSInteger)instant;

/**
 */
- (NSInteger)daysInMonthMax;

/**
 */
- (NSInteger)daysInMonthMax:(NSInteger)instant;

/**
 */
- (NSInteger)daysInMonthMaxForSet:(NSInteger)instant 
                            value:(NSInteger)value;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)dateMidnightMillis:(NSInteger)year 
                          month:(NSInteger)monthOfYear 
                            day:(NSInteger)dayOfMonth;

/**
 */
- (NSInteger)yearDifference:(NSInteger)minuendInstant 
          subtrahendInstant:(NSInteger)subtrahendInstant);

/**
 */
- (BOOL)isLeapYear:(NSInteger)year;

/**
 */
- (NSInteger)daysInYear:(NSInteger) 
                  month:(NSInteger)month;

/**
 */
- (NSInteger)daysInMonthMax:(NSInteger)month;

/**
 */
- (NSInteger)totalMillisByYear:(NSInteger)year 
                         month:(NSInteger)month;

/**
 */
- (NSInteger)calculateFirstDayOfYearMillis:(NSInteger)year;

/**
 */
- (NSInteger)minYear;

/**
 */
- (NSInteger)maxYear;

/**
 */
- (NSInteger)maxMonth:(NSInteger)year;

/**
 */
- (NSInteger)maxMonth;

/**
 */
- (NSInteger)averageMillisPerYear;

/**
 */
- (NSInteger)averageMillisPerYearDividedByTwo;

/**
 */
- (NSInteger)averageMillisPerMonth;

/**
 */
- (NSInteger)approxMillisAtEpochDividedByTwo;

/**
 */
- (NSInteger)setYearInstant:(NSInteger)instant 
                       year:(NSInteger)year;

//-----------------------------------------------------------------------
// Although accessed by multiple threads, this method doesn't need to be synchronized.
- (HLYearInfo*)yearInfo:(NSInteger)year;

@end
