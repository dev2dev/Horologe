/*
 * HLBasicMonthOfYearDateTimeField.h
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

#import "Field/HLImpreciseDateTimeField.h"
#import "Core/HLDateTimeConstants.h"


@class HLBasicChronology;
@class HLDurationField;
@protocol HLReadablePartial;

@interface HLBasicMonthOfYearDateTimeField : HLImpreciseDateTimeField {
    
@private
    HLBasicChronology* iChronology;
    NSInteger iMax;
    NSInteger iLeapMonth;
}

/**
 */
- (id)initWithChronology:(HLBasicChronology*)chronology
               leapMonth:(NSInteger)leapMonth;

//-----------------------------------------------------------------------
- (BOOL)isLenient;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)get:(NSInteger)instant;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)addInstant:(NSInteger)instant
                 months:(NSInteger)months;

//-----------------------------------------------------------------------
- (NSInteger)add:(NSInteger)instant
          months:(NSInteger)months;

//-----------------------------------------------------------------------
- (NSArray*)addPartial:(id<HLReadablePartial>)partial
            fieldIndex:(NSInteger)fieldIndex
                values:(NSArray*)values
            valueToAdd:(NSInteger)valueToAdd;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)addWrapField:(NSInteger)instant
                   months:(NSInteger)months;

//-----------------------------------------------------------------------
- (NSInteger)difference:(NSInteger)minuendInstant
      subtrahendInstant:(NSInteger)subtrahendInstant;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)set:(NSInteger)instant
           month:(NSInteger)month;

//-----------------------------------------------------------------------
- (HLDurationField*)rangeDurationField;

//-----------------------------------------------------------------------
- (BOOL)isLeap:(NSInteger)instant;

//-----------------------------------------------------------------------
- (NSInteger)leapAmount:(NSInteger)instant;

//-----------------------------------------------------------------------
- (HLDurationField*)leapDurationField;

//-----------------------------------------------------------------------
- (NSInteger)minimumValue;

//-----------------------------------------------------------------------
- (NSInteger)maximumValue;

//-----------------------------------------------------------------------
- (NSInteger)roundFloor:(NSInteger)instant;

//-----------------------------------------------------------------------
- (NSInteger)remainder:(NSInteger)instant;

//-----------------------------------------------------------------------
/**
 */
- (id)readResolve;

@end
