/*
 * HLAbstractPartial.h
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

#import "Core/HLReadablePartial.h"


@class HLDateTimeField;
@class HLDateTimeFieldType;
@class HLDateTime;
@class HLDateTimeFormatter;
@protocol HLReadableInstant;

@interface HLAbstractPartial : NSObject <HLReadablePartial> {

}

//-----------------------------------------------------------------------
/**
 */
- (HLDateTimeFieldType*)fieldTypeAtIndex:(NSInteger)index;

/**
 */
- (NSArray*)fieldTypes;

/**
 */
- (HLDateTimeField*)_fieldAtIndex:(NSInteger)index;

/**
 */
- (NSArray*)fields;

/**
 */
- (NSArray*)values;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)get:(HLDateTimeFieldType*)type;

/**
 */
- (BOOL)isSupported:(HLDateTimeFieldType*)type;

/**
 */
- (NSInteger)indexOf:(HLDateTimeFieldType*)type;

//-----------------------------------------------------------------------
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

//-----------------------------------------------------------------------
/**
 */
- (NSComparisonResult)compareTo:(id<HLReadablePartial>)other;

/**
 */
- (BOOL)isAfter:(id<HLReadablePartial>)partial;

/**
 */
- (BOOL)isBefore:(id<HLReadablePartial>)partial;

/**
 */
- (BOOL)isEqualToPartial:(id<HLReadablePartial>)partial;

//-----------------------------------------------------------------------
/**
 */
- (NSString*)stringWithFormatter:(HLDateTimeFormatter*)formatter;

@end
