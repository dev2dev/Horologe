/*
 * HLPeriodType.h
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


#define YEAR_INDEX (0)
#define MONTH_INDEX (1)
#define WEEK_INDEX (2)
#define DAY_INDEX (3)
#define HOUR_INDEX (4)
#define MINUTE_INDEX (5)
#define SECOND_INDEX (6)
#define MILLI_INDEX (7)

extern HLPeriodType* cStandard;
extern HLPeriodType* cYMDTime;
extern HLPeriodType* cYMD;
extern HLPeriodType* cYWDTime;
extern HLPeriodType* cYWD;
extern HLPeriodType* cYDTime;
extern HLPeriodType* cYD;
extern HLPeriodType* cDTime;
extern HLPeriodType* cTime;

extern HLPeriodType* cYears;
extern HLPeriodType* cMonths;
extern HLPeriodType* cWeeks;
extern HLPeriodType* cDays;
extern HLPeriodType* cHours;
extern HLPeriodType* cMinutes;
extern HLPeriodType* cSeconds;
extern HLPeriodType* cMillis;

@class HLDurationFieldType;
@protocol HLReadablePeriod;

@interface HLPeriodType : NSObject {
    
@private
    NSDictionary* cTypes;
    
    /** The name of the type */
    NSString* iName;
    /** The array of types */
    NSArray* iTypes;
    /** The array of indices */
    NSArray* iIndices;
}

/**
 */
+ (HLPeriodType*)standard;

/**
 */
+ (HLPeriodType*)yearMonthDayTime;

/**
 */
+ (HLPeriodType*)yearMonthDay;

/**
 */
+ (HLPeriodType*)yearWeekDayTime;

/**
 */
+ (HLPeriodType*)yearWeekDay;

/**
 */
+ (HLPeriodType*)yearDayTime;

/**
 */
+ (HLPeriodType*)yearDay;

/**
 */
+ (HLPeriodType*)dayTime;

/**
 */
+ (HLPeriodType*)time;

/**
 */
+ (HLPeriodType*)years;

/**
 */
+ (HLPeriodType*)months;

/**
 */
+ (HLPeriodType*)weeks;

/**
 */
+ (HLPeriodType*)days;

/**
 */
+ (HLPeriodType*)hours;

/**
 */
+ (HLPeriodType*)minutes;

/**
 */
+ (HLPeriodType*)seconds;

/**
 */
+ (HLPeriodType*)millis;

/**
 */
+ (HLPeriodType*)forFields:(NSArray*)types;

//-----------------------------------------------------------------------    

/**
 */
- (id)_initWithName:(NSString*)name
              types:(NSArray*)types
            indices:(NSArray*)indices;

//-----------------------------------------------------------------------
/**
 */
- (NSString*)name;

/**
 */
- (NSInteger)size;

/**
 */
- (HLDurationFieldType*)getFieldTypeAtIndex:(NSInteger)index;

/**
 */
- (BOOL)isSupported:(HLDurationFieldType*)type;

/**
 */
- (NSInteger)indexOf:(HLDurationFieldType*)type;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)indexedField:(id<HLReadablePeriod>)period
                    index:(NSInteger)index;

/**
 */
- (BOOL)_setIndexedField:(id<HLReadablePeriod>)period
                   index:(NSInteger)index
                  values:(NSArray*)values
                   value:(NSInteger)newValue;

/**
 */
- (BOOL)_addIndexedField:(id<HLReadablePeriod>)period
                   index:(NSInteger)index
                  values:(NSArray*)values
              valueToAdd:(NSInteger)valueToAdd;

//-----------------------------------------------------------------------
/**
 */
- (HLPeriodType*)withYearsRemoved;

/**
 */
- (HLPeriodType*)withMonthsRemoved;

/**
 */
- (HLPeriodType*)withWeeksRemoved;

/**
 */
- (HLPeriodType*)withDaysRemoved;

/**
 */
- (HLPeriodType*)withHoursRemoved;

/**
 */
- (HLPeriodType*)withMinutesRemoved;

/**
 */
- (HLPeriodType*)withSecondsRemoved;

/**
 */
- (HLPeriodType*)withMillisRemoved;

//-----------------------------------------------------------------------
/**
 */
- (BOOL)isEqual:(id)obj;

/**
 */
- (NSInteger)hashCode;

@end
