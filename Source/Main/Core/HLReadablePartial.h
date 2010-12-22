/*
 * HLReadablePartial.h
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


@class HLDateTimeFieldType;
@class HLDateTimeField;
@class HLChronology;
@class HLDateTime;
@protocol HLReadableInstant;

@protocol HLReadablePartial <NSObject>

@required
/**
 */
- (NSInteger)size;

/**
 */
- (HLDateTimeFieldType*)fieldTypeAtIndex:(NSInteger)index;

/**
 */
- (HLDateTimeField*)fieldAtIndex:(NSInteger)index;

/**
 */
- (NSInteger)valueAtIndex:(NSInteger)index;

/**
 */
- (HLChronology*)chronology;

/**
 */
- (NSInteger)get:(HLDateTimeFieldType*)field;

/**
 */
- (BOOL)isSupported:(HLDateTimeFieldType*)field;

/**
 */
- (HLDateTime*)toDateTime:(id<HLReadableInstant>)baseInstant;

//-----------------------------------------------------------------------
/**
 */
- (BOOL)isEqual:(id)partial;

/**
 */
- (NSInteger)hashCode;

@end
