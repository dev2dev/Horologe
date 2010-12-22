/*
 * HLBasicWeekyearDateTimeField.h
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

#import "HLImpreciseDateTimeField.h"
#import "HLDateTimeConstants.h"
#import "HLBasicChronology.h"
#import "HLDurationField.h"


#define WEEK_53 ((53L - 1) * MILLIS_PER_WEEK)

@interface HLBasicWeekyearDateTimeField : HLImpreciseDateTimeField {
    
@private
    HLBasicChronology* iChronology;
}

/**
 */
- (id)initWithChronology:(HLBasicChronology*)chronology;

- (BOOL)isLenient;

/**
 */
- (NSInteger)get:(NSInteger)instant;

/**
 */
- (NSInteger)add:(NSInteger)instant 
           years:(NSInteger)years;

- (NSInteger)add:(NSInteger)instant 
           value:(NSInteger)value;

/**
 */
- (NSInteger)addWrapField:(NSInteger)instant 
                    years:(NSInteger)years;

- (NSInteger)differenceAsLong:(NSInteger)minuendInstant
            subtrahendInstant:(NSInteger)subtrahendInstant;

/**
 */
- (NSInteger)set:(NSInteger)instant 
            year:(NSInteger)year;

- (HLDurationField*)rangeDurationField;

- (BOOL)isLeap:(NSInteger)instant;

- (NSInteger)leapAmount:(NSInteger)instant;

- (HLDurationField*)leapDurationField;

- (NSInteger)minimumValue;

- (NSInteger)maximumValue;

- (NSInteger)roundFloor:(NSInteger)instant;

- (NSInteger)remainder:(NSInteger)instant;

/**
 */
- (id)readResolve;

@end
