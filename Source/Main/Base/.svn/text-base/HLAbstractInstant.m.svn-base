/*
 * HLAbstractInstant.m
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

#import "Base/HLAbstractInstant.h"
#import "Core/HLDateTimeFieldType.h"
#import "Core/HLChronology.h"
#import "Chrono/HLISOChronology.h"
#import "Core/HLDateTimeUtils.h"
#import "Format/HLISODateTimeFormat.h"
#import "Field/HLFieldUtils.h"
#import "Format/HLDateTimeFormatter.h"

 
@implementation HLAbstractInstant

- (id)_init {
    if ((self = [super init])) {
    }

    return self;
}

//-----------------------------------------------------------------------
- (HLDateTimeZone*)dateTimeZone {
    return [[self chronology] dateTimeZone];
}

- (NSInteger)getFromType:(HLDateTimeFieldType*)type {
    if (type == nil) {
        [NSException raise:NSInvalidArgumentException format:@"The DateTimeFieldType must not be null"];
    }

    return [[type getField:[self chronology]] get:[self millis]];
}

- (BOOL)isSupported:(HLDateTimeFieldType*)type {
    if (type == nil) {
        return NO;
    }
    return [[type field:[self chronology]] isSupported];
}

- (NSInteger)get:(HLDateTimeField*)field {
    if (field == nil) {
[NSException raise:NSInvalidArgumentException format:@"The DateTimeField must not be null"];
    }
    
    return [field get:[self millis]];
}

//-----------------------------------------------------------------------
- (HLInstant*)toInstant {
    return [[[HLInstant alloc] initWithMillis:[self millis]] autorelease];
}

- (HLDateTime*)toDateTime {
    return [[[HLDateTime alloc] initWithMillis:[self millis] zone:[self zone]] autorelease];
}

- (HLDateTime*)toDateTimeISO {
    return [[[HLDateTime alloc] initWithMillis:[self millis] chronology:[HLISOChronology instance:[self zone]]] autorelease];
}

- (HLDateTime*)toDateTimeWithZone:(HLDateTimeZone*)zone {
    HLChronology* chrono = [HLDateTimeUtils chronology:[self chronology]];
    chrono = [chrono withDateTimeZone:zone];
    return [[[HLDateTime alloc] initWithMillis:[self millis] chronology:chrono] autorelease];
}

- (HLDateTime*)toDateTimeWithChronology:(HLChronology*)chronology {
    return [[[HLDateTime alloc] initWithMillis:[self millis] chronology:chronology] autorelease];
}

- (HLMutableDateTime*)toMutableDateTime {
    return [[[HLMutableDateTime alloc] initWithMillis:[self millis] zone:[self dateTimeZone]] autorelease];
}

- (HLMutableDateTime*)toMutableDateTimeISO {
    return [[[HLMutableDateTime alloc] initWithMillis:[self millis] chronology:[HLISOChronology instanceWithZone:[self dateTimeZone]]] autorelease];
}

- (HLMutableDateTime*)toMutableDateTimeWithZone:(HLDateTimeZone*)zone {
    HLChronology* chrono = [HLDateTimeUtils chronology:[self chronology]];
    chrono = [chrono withZone:zone];
    return [[[HLMutableDateTime alloc] initWithMillis:[self millis] chronology:chrono] autorelease];
}

- (HLMutableDateTime*)toMutableDateTimeWithChronology:(HLChronology*)chronology {
    return [[[HLMutableDateTime alloc] initWithMillis:[self millis] chronology:chronology] autorelease];
}

//-----------------------------------------------------------------------
- (NSDate*)toDate {
    return [NSDate dateFromMilliseconds:[self getMillis]];
}

//-----------------------------------------------------------------------
- (BOOL)isEqualObject:(id)readableInstant {
    // must be to fulfill ReadableInstant contract
    if (self == readableInstant) {
        return true;
    }
    if (![readableInstant conformsToProtocol:@protocol(HLReadableInstant)]) {
        return false;
    }
    id<HLReadableInstant> otherInstant = (id<HLReadableInstant>) readableInstant;

    return [self millis] == [otherInstant millis] &&
    [HLFieldUtils isEqualChronology:[self chronology] chronology:[otherInstant chronology]];
}

- (NSInteger)hashCode {
    // must be to fulfil ReadableInstant contract
    return ((NSInteger) ([self millis] ^ ([self millis] >> 32))) +
    ([[self chronology] hashCode]);
}

- (NSComparisonResult)compareTo:(id<HLReadableInstant>)other {
    if (self == other) {
        return NSOrderedSame;
    }
    
    NSInteger otherMillis = [other millis];
    NSInteger thisMillis = [self millis];
    
    // cannot do (thisMillis - otherMillis) as can overflow
    if (thisMillis == otherMillis) {
        return NSOrderedSame;
    }
    if (thisMillis < otherMillis) {
        return NSOrderedAscending;
    } 
    else {
        return NSOrderedDescending;
    }
}

//-----------------------------------------------------------------------
- (BOOL)isAfter:(NSInteger)instant {
    return [self millis] > instant;
}

- (BOOL)isAfterNow {
    return [self isAfter:[HLDateTimeUtils currentTimeMillis]];
}

- (BOOL)isAfterInstant:(id<HLReadableInstant>)instant {
    NSInteger instantMillis = [HLDateTimeUtils instantMillis:instant];
    return [self isAfter:instantMillis];
}

//-----------------------------------------------------------------------
- (BOOL)isBefore:(NSInteger)instant {
    return [self millis] < instant;
}

- (BOOL)isBeforeNow {
    return [self isBefore:[HLDateTimeUtils currentTimeMillis]];
}

- (BOOL)isBeforeInstant:(id<HLReadableInstant>)instant {
    NSInteger instantMillis = [HLDateTimeUtils instantMillis:instant];
    return [self isBefore:instantMillis];
}

//-----------------------------------------------------------------------
- (BOOL)isEqual:(NSInteger)instant {
    return [self millis] == instant;
}

- (BOOL)isEqualNow {
    return [self isEqual:[HLDateTimeUtils currentTimeMillis]];
}

- (BOOL)isEqualInstant:(id<HLReadableInstant>)instant {
    NSInteger instantMillis = [HLDateTimeUtils instantMillis:instant];
    return [self isEqual:instantMillis];
}

//-----------------------------------------------------------------------
- (NSString*)description {
    return [[HLISODateTimeFormat dateTime] print:self];
}

//-----------------------------------------------------------------------
- (NSString*)stringUsingFormatter:(HLDateTimeFormatter*)formatter {
    if (formatter == nil) {
        return [self description];
    }
    
    return [formatter print:self];
}

//-----------------------------------------------------------------------
- (void)dealloc {
    [super dealloc];
}

@end
