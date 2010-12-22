/*
 * HLReadWritableDateTime.h
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

#import "HLReadableDateTime.h"
#import "HLReadWritableInstant.h"


@protocol HLReadWritableDateTime <HLReadableDateTime, HLReadWritableInstant>

@required
//-----------------------------------------------------------------------
/**
 */
- (void)setYear:(NSInteger)year;

/**
 */
- (void)addYears:(NSInteger)years;

//-----------------------------------------------------------------------
/**
 */
- (void)setWeekyear:(NSInteger)weekyear;

/**
 */
- (void)addWeekyears:(NSInteger)weekyears;

//-----------------------------------------------------------------------
/**
 */
- (void)setMonthOfYear:(NSInteger)monthOfYear;

/**
 */
- (void)addMonths:(NSInteger)months;

//-----------------------------------------------------------------------
/**
 */
- (void)setWeekOfWeekyear:(NSInteger)weekOfWeekyear;

/**
 */
- (void)addWeeks:(NSInteger)weeks;

//-----------------------------------------------------------------------
/**
 */
- (void)setDayOfYear:(NSInteger)dayOfYear;

/**
 */
- (void)setDayOfMonth:(NSInteger)dayOfMonth;

/**
 */
- (void)setDayOfWeek:(NSInteger)dayOfWeek;

/**
 */
- (void)addDays:(NSInteger)days;

//-----------------------------------------------------------------------
/**
 */
- (void)setHourOfDay:(NSInteger)hourOfDay;

/**
 */
- (void)addHours:(NSInteger)hours;

//-----------------------------------------------------------------------
/**
 */
- (void)setMinuteOfDay:(NSInteger)minuteOfDay;

/**
 */
- (void)setMinuteOfHour:(NSInteger)minuteOfHour;

/**
 */
- (void)addMinutes:(NSInteger)minutes;

//-----------------------------------------------------------------------
/**
 */
- (void)setSecondOfDay:(NSInteger)secondOfDay;

/**
 */
- (void)setSecondOfMinute:(NSInteger)secondOfMinute;

/**
 */
- (void)addSeconds:(NSInteger)seconds;

//-----------------------------------------------------------------------
/**
 */
- (void)setMillisOfDay:(NSInteger)millisOfDay;

/**
 */
- (void)setMillisOfSecond:(NSInteger)millisOfSecond;

/**
 */
- (void)addMillis:(NSInteger)millis;

/**
 */
- (void)setDateYear:(NSInteger)year
              month:(NSInteger)monthOfYear 
                day:(NSInteger)dayOfMonth;

/**
 */
- (void)setTimeHour:(NSInteger)hour 
             minute:(NSInteger)minuteOfHour
             second:(NSInteger)secondOfMinute 
             millis:(NSInteger)millisOfSecond;

/**
 */
- (void)setDateTimeYear:(NSInteger)year 
                  month:(NSInteger)monthOfYear
                    day:(NSInteger)dayOfMonth
                   hour:(NSInteger)hourOfDay 
                 minute:(NSInteger)minuteOfHour 
                 second:(NSInteger)secondOfMinute 
                 millis:(NSInteger)millisOfSecond;

@end
