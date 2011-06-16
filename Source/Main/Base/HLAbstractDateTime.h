/*
 * HLAbstractDateTime.h
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

#import "Base/HLAbstractInstant.h"
#import "Core/HLReadableDateTime.h"


@class HLDateTimeFieldType;

@interface HLAbstractDateTime : HLAbstractInstant <HLReadableDateTime> {
    
}

/**
 */
- (id)_init;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)get:(HLDateTimeFieldType*)type;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)eraValue;

/**
 */
- (NSInteger)centuryOfEraValue;

/**
 */
- (NSInteger)yearOfEraValue;

/**
 */
- (NSInteger)yearOfCenturyValue;

/**
 */
- (NSInteger)yearValue;

/**
 */
- (NSInteger)weekyearValue;

/**
 */
- (NSInteger)monthOfYearValue;

/**
 */
- (NSInteger)weekOfWeekyearValue;

/**
 */
- (NSInteger)dayOfYearValue;

/**
 */
- (NSInteger)dayOfMonthValue;

/**
 */
- (NSInteger)dayOfWeekValue;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)hourOfDayValue;

/**
 */
- (NSInteger)minuteOfDayValue;

/**
 */
- (NSInteger)minuteOfHourValue;

/**
 */
- (NSInteger)secondOfDayValue;

/**
 */
- (NSInteger)secondOfMinuteValue;

/**
 */
- (NSInteger)millisOfDayValue;

/**
 */
- (NSInteger)millisOfSecondValue;

//-----------------------------------------------------------------------
/**
 */
//- (NSCalendar*)toCalendar:(NSLocale*)locale;

/**
 */
//- (NSGregorianCalendar*)toGregorianCalendar;

//-----------------------------------------------------------------------
/**
 */
- (NSString*)stringWithPattern:(NSString*)pattern;

/**
 */
- (NSString*)stringWithPattern:(NSString*)pattern 
                        locale:(NSLocale*)locale;

@end
