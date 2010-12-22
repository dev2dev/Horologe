/*
 * HLAbstractInstant.h
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

#import "Core/HLReadableInstant.h"


@class HLInstant;
@class HLDateTimeFieldType;
@class HLDateTimeZone;
@class HLDateTimeField;
@class HLDateTime;
@class HLMutableDateTime;
@class HLDateTimeFormatter;

@interface HLAbstractInstant : NSObject <HLReadableInstant> {

}

//-----------------------------------------------------------------------
- (id)_init;

//-----------------------------------------------------------------------
/**
 */
- (HLDateTimeZone*)dateTimeZone;

/**
 */
- (NSInteger)getFromType:(HLDateTimeFieldType*)type;

/**
 */
- (BOOL)isSupported:(HLDateTimeFieldType*)type;

/**
 */
- (NSInteger)getFromField:(HLDateTimeField*)field;

//-----------------------------------------------------------------------
/**
 */
- (HLInstant*)toInstant;

/**
 */
- (HLDateTime*)toDateTime;

/**
 */
- (HLDateTime*)toDateTimeISO;

/**
 */
- (HLDateTime*)toDateTimeWithZone:(HLDateTimeZone*)zone;

/**
 */
- (HLDateTime*)toDateTimeWithChronology:(HLChronology*)chronology;

/**
 */
- (HLMutableDateTime*)toMutableDateTime;

/**
 */
- (HLMutableDateTime*)toMutableDateTimeISO;

/**
 */
- (HLMutableDateTime*)toMutableDateTimeWithZone:(HLDateTimeZone*)zone;

/**
 */
- (HLMutableDateTime*)toMutableDateTimeWithChronology:(HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 */
- (NSDate*)toDate;

//-----------------------------------------------------------------------
/**
 */
- (BOOL)isEqualObject:(id)readableInstant;

/**
 */
- (NSInteger)hashCode;

/**
 */
- (NSComparisonResult)compareTo:(id<HLReadableInstant>)other;

//-----------------------------------------------------------------------
/**
 */
- (BOOL)isAfter:(NSInteger)instant;

/**
 */
- (BOOL)isAfterNow;

/**
 */
- (BOOL)isAfterInstant:(id<HLReadableInstant>)instant;

//-----------------------------------------------------------------------
/**
 */
- (BOOL)isBefore:(NSInteger)instant;

/**
 */
- (BOOL)isBeforeNow;

/**
 */
- (BOOL)isBeforeInstant:(id<HLReadableInstant>)instant;

//-----------------------------------------------------------------------
/**
 */
- (BOOL)isEqual:(NSInteger)instant;

/**
 */
- (BOOL)isEqualNow;

/**
 */
- (BOOL)isEqualInstant:(id<HLReadableInstant>)instant;

//-----------------------------------------------------------------------
/**
 */
- (NSString*)stringUsingFormatter:(HLDateTimeFormatter*)formatter;

@end
