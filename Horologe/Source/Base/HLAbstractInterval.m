/*
 * AbstractInterval.m
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

#import "HLAbstractInterval.h"

#import "HLConstants.h"
#import "HLDateTime.h"
#import "HLDateTimeUtils.h"
#import "HLReadableInstant.h"
#import "HLReadableInterval.h"
#import "HLInterval.h"
#import "HLDateTimeFormatter.h"
#import "HLPeriod.h"
#import "HLDuration.h"
#import "HLMutableInterval.h"


@implementation AbstractInterval

/**
 * Constructor.
 */
- (id)init {
    self = [super init];
    if(self) {
        
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (void)checkIntervalWithStart:(NSInteger)start 
                            end:(NSInteger)end {
    if (end < start) {
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"The end instant must be greater or equal to the start"];
    }
}

//-----------------------------------------------------------------------
- (HLDateTime*)start {
    return [[[HLDateTime alloc] initWithMillis:[self startMillis]
                                    chronology:[self chronology]] autorelease];
}

- (HLDateTime*)end {
    return [[[HLDateTime alloc] initWithMillis:[self endMillis]
                                    chronology:[self chronology]] autorelease];
}

//-----------------------------------------------------------------------
- (BOOL)contains:(NSInteger)millisInstant {
    NSInteger thisStart = [self startMillis];
    NSInteger thisEnd = [self endMillis];
    return (millisInstant >= thisStart && millisInstant < thisEnd);
}

- (BOOL)containsNow {
    return [self contains:[HLDateTimeUtils currentTimeMillis]];
}

- (BOOL)containsInstant:(id<HLReadableInstant>)instant {
    if (instant == nil) {
        return [self containsNow];
    }
    
    return [self contains:[instant millis]];
}

- (BOOL)contains:(id<HLReadableInterval>)interval {
    if (interval == nil) {
        return [self containsNow];
    }
    
    NSInteger otherStart = [interval startMillis];
    NSInteger otherEnd = [interval endMillis];
    NSInteger thisStart = [self startMillis];
    NSInteger thisEnd = [self endMillis];
    
    return (thisStart <= otherStart && otherStart < thisEnd && otherEnd <= thisEnd);
}

- (BOOL)overlaps:(id<HLReadableInterval>)interval {
    NSInteger thisStart = [self startMillis];
    NSInteger thisEnd = [self endMillis];
    
    if (interval == nil) {
        NSInteger now = [HLDateTimeUtils currentTimeMillis];
        return (thisStart < now && now < thisEnd);
    }  
    else {
        NSInteger otherStart = [interval startMillis];
        NSInteger otherEnd = [interval endMillis];
        return (thisStart < otherEnd && otherStart < thisEnd);
    }
}

//-----------------------------------------------------------------------
- (BOOL)isBeforeInstantValue:(NSInteger)millisInstant {
    return ([self endMillis] <= millisInstant);
}

- (BOOL)isBeforeNow {
    return [self isBefore:[HLDateTimeUtils currentTimeMillis]];
}

- (BOOL)isBeforeInstant:(id<HLReadableInstant>)instant {
    if (instant == nil) {
        return [self isBeforeNow];
    }
    
    return [self isBefore:[instant millis]];
}

- (BOOL)isBeforeInterval:(id<HLReadableInterval>)interval {
    if (interval == nil) {
        return [self isBeforeNow];
    }
    
    return [self isBefore:[interval startMillis]];
}

//-----------------------------------------------------------------------
- (BOOL)isAfterInstantValue:(NSInteger)millisInstant {
    return ([self startMillis] > millisInstant);
}

- (BOOL)isAfterNow {
    return [self isAfter:[HLDateTimeUtils currentTimeMillis]];
}

- (BOOL)isAfterInstant:(id<HLReadableInstant>)instant {
    if (instant == nil) {
        return [self isAfterNow];
    }
    
    return [self isAfter:[instant millis]];
}

- (BOOL)isAfterInterval:(id<HLReadableInterval>)interval {
    NSInteger endMillis;
    if (interval == nil) {
        endMillis = [HLDateTimeUtils currentTimeMillis]
    } 
    else {
        endMillis = [interval endMillis];
    }
    
    return ([self startMillis] >= endMillis);
}

//-----------------------------------------------------------------------
- (HLInterval*)toInterval {
    return [[[HLInterval alloc] initWithStartMillis:[self startMillis]
                                          endMillis:[self endMillis]
                                         chronology:[self chronology]] autorelease];
}

- (HLMutableInterval*)toMutableInterval {
    return [[[HLMutableInterval alloc] initWithStartMillis:[self startMillis]
                                                 endMillis:[self endMillis]
                                                chronology:[self chronology]] autorelease];
}

//-----------------------------------------------------------------------
- (NSInteger)toDurationMillis {
    return [HLFieldUtils safeAddMillis:[self endMillis]
                              toMillis:-[self startMillis]];
}

- (HLDuration*)toDuration {
    NSInteger durMillis = [self toDurationMillis];
    if (durMillis == 0) {
        return [HLDuration zeroDuration];
    } 
    else {
        return [[[HLDuration alloc] initWithMillis:durMillis] autorelease];
    }
}

//-----------------------------------------------------------------------
- (HLPeriod*)toPeriod {
    return [[[HLPeriod alloc] initWithStartMillis:[self startMillis]
                                        endMillis:[self endMillis]
                                       chronology:[self chronology]] autorelease];
}

- (HLPeriod*)toPeriod:(HLPeriodType*)type {
    return [[[HLPeriod alloc] initWithStartMillis:[self startMillis]
                                        endMillis:[self endMillis]
                                             type:type
                                       chronology:[self chronology]] autorelease];
}

//-----------------------------------------------------------------------
- (BOOL)equals:(id)readableInterval {
    if (self == readableInterval) {
        return YES;
    }
    if ([readableInterval conformsToProtocol:@protocol(HLReadableInterval)] == false) {
        return NO;
    }
    id<HLReadableInterval> other = (id<HLReadableInterval>) readableInterval;
    
    return [self startMillis] == [other startMillis] &&
    [self endMillis] == [other endMillis] &&
    [HLFieldUtils chronology:[self chronology]
            equalsChronology:[other chronology]];
}

- (NSUInteger)hash {
    NSInteger start = [self startMillis];
    NSInteger end = [self endMillis];
    NSInteger result = 97;
    result = 31 * result + ((NSInteger) (start ^ (start >>> 32)));
    result = 31 * result + ((NSInteger) (end ^ (end >>> 32)));
    result = 31 * result + [[self chronology] hash];
    return result;
}

- (NSString*)description {
    HLDateTimeFormatter* printer = [HLISODateTimeFormat dateHourMinuteSecondFraction];
    printer = [printer withChronology:[self chronology]];
    NSMutableString* buf = [[[NSMutableString alloc] initWithCapacity:48] autorelease];
    [printer printMillis:[self startMillis]
                      to:buf];
    [buf appendString:@"/"];
    [printer print:[self endMillis]
                to:buf];
    
    return [buf copy];
}

@end
