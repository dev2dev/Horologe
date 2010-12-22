/*
 * HLBasicDayOfYearDateTimeField.h
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

#import "Core/HLPreciseDurationDateTimeField.h"


@class HLBasicChronology;
@class HLChronology;
@class HLDurationField;
@class HLReadablePartial;

@interface HLBasicDayOfYearDateTimeField : HLPreciseDurationDateTimeField {
    
@private
    HLBasicChronology* iChronology;
}

/**
 */
- (id)initWithChronology:(HLChronology*)chronology 
                    days:(HLDurationField*)days;

//-----------------------------------------------------------------------
- (NSInteger)get:(NSInteger)instant;

- (HLDurationField*)rangeDurationField;

- (NSInteger)minimumValue;

- (NSInteger)maximumValue;

- (NSInteger)maximumValueFromInstant:(NSInteger)instant;

- (NSInteger)maximumValueFromPartial:(id<HLReadablePartial>)partial;

- (NSInteger)maximumValueFromPartial:(id<HLReadablePartial>)partial 
                              values:(NSArray*)values;

- (NSInteger)maximumValueForSet:(NSInteger)instant 
                          value:(NSInteger)value;

/**
 */
- (id)readResolve;

@end
