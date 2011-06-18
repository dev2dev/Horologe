/*
 * AbstractInstant.m
 *
 * Horologe
 * Copyright (c) 2011 Pilgrimage Software
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

#import "HLAbstractInstant.h"

#import "HLConstants.h"
#import "HLChronology.h"


@implementation HLAbstractInstant

- (id)_init {
    self = [super init];
    if(self) {
        
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (HLDateTimeZone*)dateTimeZone {
    return [[self chronology] dateTimeZone];
}

- (NSInteger)get:(HLDateTimeFieldType*)type) {
    if(type == nil) {
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"The DateTimeFieldType must not be nil"];
    }
    
    return [[type field:[self chronology]] get:[self millis]];
}

- (BOOL)isSupported:(HLDateTimeFieldType*)type {
    if (type == nil) {
        return NO;
    }
    
    return [[type field:[self chronology]] isSupported];
}

- (NSInteger)getField:(HLDateTimeField*)field {
    if(field == nil) {
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"The DateTimeField must not be nil"];
    }
    
    return [field get:[self millis]];
}

//-----------------------------------------------------------------------
- (HLInstant*)toInstant {
    return [[[HLInstant alloc] initWithMillis:[self millis]] autorelease];
}

- (HLDateTime*)toDateTime {
    return [[[HLDateTime alloc] initWithMillis:[self millis] 
                                          zone:[self dateTimeZone]] autorelease];
}

- (HLDateTime*)toDateTimeISO {
    return [[[HLDateTime alloc] initWithMillis:[self millis]
                                    chronology:[HLISOChronology instanceWithZone:[self dateTimeZone]]] autorelease];
}

- (HLDateTime*)toDateTime:(HLDateTimeZone*)zone {
    HLChronology* chrono = [HLDateTimeUtils chronology:[self chronology]];
    chrono = [chrono withZone:zone];
    return [[[HLDateTime alloc] initWithMillis:[self millis]
                                    chronology:chrono] autorelease];
}

- (HLDateTime*)toDateTime:(HLChronology*)chronology {
    return [[[HLDateTime alloc] initWithMillis:[self millis]
                                    chronology:chronology] autorelease];
}

- (HLMutableDateTime*)toMutableDateTime {
    return [[[HLMutableDateTime alloc] initWithMillis:[self millis]
                                                 zone:[self dateTimeZone]] autorelease];
}

- (HLMutableDateTime*)toMutableDateTimeISO {
    return [[[HLMutableDateTime alloc] initWithMillis:[self millis]
                                           chronology:[HLISOChronology instanceWithZone:[self dateTimeZone]]] autorelease];
}

- (HLMutableDateTime*)toMutableDateTime:(HLDateTimeZone*)zone {
    HLChronology* chrono = [HLDateTimeUtils chronology:[self chronology]];
    chrono = [chrono withZone:zone];
    return [[[HLMutableDateTime alloc] initWithMillis:[self millis]
                                           chronology:chrono] autorelease];
}

- (HLMutableDateTime*)toMutableDateTime:(HLChronology*)chronology {
    return [[[HLMutableDateTime alloc] initWithMillis:[self millis]
                                           chronology:chronology] autorelease];
}

//-----------------------------------------------------------------------
- (NSDate*)toDate {
    return [[[NSDate alloc] initWithTimeIntervalSince1970:([self millis] / 1000)] autorelease];
}

//-----------------------------------------------------------------------
- (BOOL)equals:(id)readableInstant {
    // must be to fulfil ReadableInstant contract
    if (self == readableInstant) {
        return YES;
    }
    if ([readableInstant conformsToProtocol:@protocol(HLReadableInstant)] == NO) {
        return NO;
    }
    id<HLReadableInstant> otherInstant = (id<HLReadableInstant>)readableInstant;
    return
    [self millis] == [otherInstant millis] &&
    [HLFieldUtils isChronology:[self chronology] 
             equalToChronology:[otherInstant chronology]];
}

- (NSUInteger)hash {
    // must be to fulfil ReadableInstant contract
    return
    ((NSInteger) ([self millis] ^ ([self millis] >>> 32))) +
    ([[self chronology] hash]);
}

- (NSComparisonResult)compare:(id)instant {
    if (self == instant) {
        return NSOrderedSame;
    }
    
    id<HLReadableInstant> otherInstant = (id<HLReadableInstant>)instant;
    
    NSInteger otherMillis = [otherInstant millis];
    NSInteger thisMillis = [self millis];
    
    // cannot do (thisMillis - otherMillis) as can overflow
    if (thisMillis == otherMillis) {
        return NSOrderedSame;
    }
    if (thisMillis < otherMillis) {
        return NSOrderedDescending;
    } else {
        return NSOrderedAscending;
    }
}

//-----------------------------------------------------------------------
- (BOOL)isAfter:(NSInteger)instant {
    return ([self millis] > instant);
}

- (BOOL)isAfterNow {
    return [self isAfter:[HLDateTimeUtils currentTimeMillis]];
}

- (BOOL)isAfter:(id<HLReadableInstant>)instant {
    NSInteger instantMillis = [HLDateTimeUtils instantMillis:instant];
    return [self isAfter:instantMillis];
}

//-----------------------------------------------------------------------
- (BOOL)isBefore:(NSInteger)instant {
    return ([self millis] < instant);
}

- (BOOL)isBeforeNow {
    return [self isBefore:[HLDateTimeUtils currentTimeMillis]];
}

- (BOOL)isBefore:(id<HLReadableInstant>)instant {
    NSInteger instantMillis = [HLDateTimeUtils instantMillis:instant];
    return [self isBefore:instantMillis];
}

//-----------------------------------------------------------------------
- (BOOL)isEqual:(NSInteger)instant {
    return ([self millis] == instant);
}

- (BOOL)isEqualNow {
    return [self isEqual:[HLDateTimeUtils currentTimeMillis]];
}

- (BOOL)isEqual:(id<HLReadableInstant>)instant {
    NSInteger instantMillis = [HLDateTimeUtils instantMillis:instant];
    return [self isEqual:instantMillis];
}

//-----------------------------------------------------------------------
- (NSString*)description {
    return [[HLISODateTimeFormat dateTime] print:self];
}

//-----------------------------------------------------------------------
- (NSString*)stringWithFormatter:(HLDateTimeFormatter*)formatter {
    if (formatter == nil) {
        return [self description];
    }
    
    return [formatter print:self];
}

@end
