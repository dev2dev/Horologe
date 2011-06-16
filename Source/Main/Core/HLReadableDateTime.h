/*
 * HLReadableDateTime.h
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

#import "HLReadableInstant.h"


@class HLDateTime;
@class HLMutableDateTime;

@protocol HLReadableDateTime <HLReadableInstant>

@required
/**
 */
- (NSInteger)dayOfWeekValue;

/**
 */
- (NSInteger)dayOfMonthValue;

/**
 */
- (NSInteger)dayOfYearValue;

/**
 */
- (NSInteger)weekOfWeekyearValue;

/**
 */
- (NSInteger)weekyearValue;

/**
 */
- (NSInteger)monthOfYearValue;

/**
 */
- (NSInteger)yearValue;

/**
 */
- (NSInteger)yearOfEraValue;

/**
 */
- (NSInteger)yearOfCenturyValue;

/**
 */
- (NSInteger)centuryOfEraValue;

/**
 */
- (NSInteger)eraValue;

// Time field access methods
//-----------------------------------------------------------

/**
 */
- (NSInteger)millisOfSecondValue;

/**
 */
- (NSInteger)millisOfDayValue;

/**
 */
- (NSInteger)secondOfMinuteValue;

/**
 */
- (NSInteger)secondOfDayValue;

/**
 */
- (NSInteger)minuteOfHourValue;

/**
 */
- (NSInteger)minuteOfDayValue;

/**
 */
- (NSInteger)hourOfDayValue;

/**
 */
- (HLDateTime*)toDateTime;

/**
 */
- (HLMutableDateTime*)toMutableDateTime;

/**
 */
- (NSString*)stringWithPattern:(NSString*)pattern;

/**
 */
- (NSString*)stringWithPattern:(NSString*)pattern locale:(NSLocale*)locale;

@end
