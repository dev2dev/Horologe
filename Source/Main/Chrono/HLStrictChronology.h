/*
 * HLStrictChronology.h
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

#import "HLAssembledChronology.h"
#import "HLChronology.h"
#import "HLDateTimeField.h"


@interface HLStrictChronology : HLAssembledChronology {
    
@private
    HLChronology* iWithUTC;    
}

/**
 */
+ (HLStrictChronology*)instance:(HLChronology*)base;

/**
 */
- (id)initWithChronology:(HLChronology*)base;

- (HLChronology*)withUTC;

- (HLChronology*)withZone:(HLDateTimeZone*)zone;

- (void)assemble:(HLFields*)fields;

+ (HLDateTimeField*)convertField:(HLDateTimeField*)field;

//-----------------------------------------------------------------------
/**
 */
- (BOOL)isEqual:(id)obj;

/**
 */
- (NSInteger)hashCode;

/**
 */
- (NSString*)string;

@end
