/*
 * HLBaseDateTime.h
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

#import "Base/HLAbstractDateTime.h"
#import "Core/HLReadableDateTime.h"


@class HLChronology;
@class HLDateTimeZone;

@interface HLBaseDateTime : HLAbstractDateTime <HLReadableDateTime> {
    
@private
    /** The millis from 1970-01-01T00:00:00Z */
    NSInteger iMillis;
    /** The chronology to use */
    HLChronology* iChronology;
    
}

//-----------------------------------------------------------------------
/**
 */
- (id)init;

/**
 */
- (id)initWithDateTimeZone:(HLDateTimeZone*)zone;

/**
 */
- (id)initWithChronology:(HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 */
- (id)initWithInstant:(NSInteger)instant;

/**
 */
- (id)initWithInstant:(NSInteger)instant 
         dateTimeZone:(HLDateTimeZone*)zone;

/**
 */
- (id)initWithInstant:(NSInteger)instant 
           chronology:(HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 */
- (id)initWithObject:(id)instant 
        dateTimeZone:(HLDateTimeZone*)zone;

/**
 */
- (id)initWithObject:(id)instant 
          chronology:(HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 */
- (id)initWithYear:(NSInteger)year 
             month:(NSInteger)monthOfYear
               day:(NSInteger)dayOfMonth
              hour:(NSInteger)hourOfDay
            minute:(NSInteger)minuteOfHour
            second:(NSInteger)secondOfMinute
            millis:(NSInteger)millisOfSecond;

/**
 */
- (id)initWithYear:(NSInteger)year 
             month:(NSInteger)monthOfYear
               day:(NSInteger)dayOfMonth
              hour:(NSInteger)hourOfDay
            minute:(NSInteger)minuteOfHour
            second:(NSInteger)secondOfMinute
            millis:(NSInteger)millisOfSecond
      dateTimeZone:(HLDateTimeZone*)zone;

/**
 */
- (id)initWithYear:(NSInteger)year 
             month:(NSInteger)monthOfYear
               day:(NSInteger)dayOfMonth
              hour:(NSInteger)hourOfDay
            minute:(NSInteger)minuteOfHour
            second:(NSInteger)secondOfMinute
            millis:(NSInteger)millisOfSecond
        chronology:(HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 */
- (HLChronology*)_checkChronology:(HLChronology*)chronology;

/**
 */
- (NSInteger)_checkInstant:(NSInteger)instant;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)millis;

/**
 */
- (HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 */
- (void)_setMillis:(NSInteger)instant;

/**
 */
- (void)_setChronology:(HLChronology*)chronology;

@end
