/*
 * HLBasePartial.h
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

#import "Base/HLAbstractPartial.h"
#import "Core/HLReadablePartial.h"


@class HLChronology;

@interface HLBasePartial : HLAbstractPartial <HLReadablePartial> {
    
@private
    /** The chronology in use */
    HLChronology* iChronology;
    /** The values of each field in this partial */
    NSArray* iValues;
    
}

- (id)_init;

- (id)_initWithChronology:(HLChronology*)chronology;

- (id)_init:(NSInteger)instant;

- (id)_initWithMillis:(NSInteger)instant
           chronology:(HLChronology*)chronology;

- (id)_initWithObject:(id)instant
           chronology:(HLChronology*)chronology;

- (id)_initWithObject:(id)instant 
           chronology:(HLChronology*)chronology 
               parser:(HLDateTimeFormatter*)parser;

- (id)_initWithValues:(NSArray*)values
           chronology:(HLChronology*)chronology;

- (id)_initWithPartial:(HLBasePartial*)base
                values:(NSArray*)values;

- (id)_initWithPartial:(HLBasePartial*)base 
            chronology:(HLChronology*)chrono;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)valueAtIndex:(NSInteger)index;

/**
 */
- (NSArray*)values;

/**
 */
- (HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 */
- (NSString*)stringWithPattern:(NSString*)pattern;

/**
 */
- (NSString*)stringWithPattern:(NSString*)pattern 
                        locale:(NSLocale*)locale;

@end
