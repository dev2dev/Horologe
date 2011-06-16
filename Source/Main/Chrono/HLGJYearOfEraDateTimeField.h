/*
 * HLGJYearOfEraDateTimeField.h
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

#import "HLDecoratedDateTimeField.h"
#import "HLBasicChronology.h"
#import "HLDateTimeField.h"
#import "HLReadablePartial.h"


@interface HLGJYearOfEraDateTimeField : HLDecoratedDateTimeField {
    
@private 
    HLBasicChronology* iChronology;
}

/**
 */
- (id)initWithYear:(HLDateTimeField*)yearField
        chronology:(HLBasicChronology*)chronology;

- (NSInteger)get:(NSInteger)instant;

- (NSInteger)add:(NSInteger)instant 
           years:(NSInteger)years;

- (NSInteger)add:(NSInteger)instant 
           years:(NSInteger)years;

- (NSInteger)addWrapField:(NSInteger)instant 
                    years:(NSInteger)years;

- (NSArray*)addWrapField:(id<HLReadablePartial>)instant 
              fieldIndex:(NSInteger)fieldIndex 
                  values:(NSArray*)values 
                   years:(NSInteger)years;

- (NSInteger)difference:(NSInteger)minuendInstant 
      subtrahendInstant:(NSInteger)subtrahendInstant;

- (NSInteger)differenceAsLong:(NSInteger)minuendInstant 
            subtrahendInstant:(NSInteger)subtrahendInstant;

/**
 */
- (NSInteger)set:(NSInteger)instant 
            year:(NSInteger)year;

- (NSInteger)minimumValue;

- (NSInteger)maximumValue;

- (NSInteger)roundFloor:(NSInteger)instant;

- (NSInteger)roundCeiling:(NSInteger)instant;

- (NSInteger)remainder:(NSInteger)instant;

/**
 */
- (id)readResolve;

@end
