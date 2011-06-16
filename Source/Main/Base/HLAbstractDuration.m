/*
 * HLAbstractDuration.m
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

#import "Base/HLAbstractDuration.h"
#import "Core/HLDuration.h"
#import "Core/HLPeriod.h"
#import "Format/HLFormatUtils.h"


@implementation HLAbstractDuration

- (id)_init {
    if (self = [super init]) {
        
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (HLDuration*)toDuration {
    return [[[HLDuration alloc] initWithMillis:[self millis]] autorelease];
}

//-----------------------------------------------------------------------
- (HLPeriod*)toPeriod {
    return [[[HLPeriod alloc] initWithMillis:[self millis]] autorelease];
}

//-----------------------------------------------------------------------
- (NSComparisonResult)compareTo:(id<HLReadableDuration>)other {
    NSInteger thisMillis = [self millis];
    NSInteger otherMillis = [other millis];
    
    // cannot do (thisMillis - otherMillis) as it can overflow
    if (thisMillis < otherMillis) {
        return NSOrderedAscending;
    }
    if (thisMillis > otherMillis) {
        return NSOrderedDescending;
    }
    return NSOrderedSame;
}

- (BOOL)isEqualDuration:(id<HLReadableDuration>)duration {
    if (duration == nil) {
        duration = HL_DURATION_ZERO;
    }
    return [self compareTo:duration] == NSOrderedSame;
}

- (BOOL)isLongerThan:(id<HLReadableDuration>)duration {
    if (duration == nil) {
        duration = HL_DURATION_ZERO;
    }
    return [self compareTo:duration] == NSOrderedDescending;
}

- (BOOL)isShorterThan:(id<HLReadableDuration>)duration {
    if (duration == nil) {
        duration = HL_DURATION_ZERO;
    }
    return [self compareTo:duration] == NSOrderedAscending;
}

//-----------------------------------------------------------------------
- (BOOL)isEqual:(id)duration {
    if (self == duration) {
        return YES;
    }
    if (![duration conformsToProtocol:@protocol(HLReadableDuration)]) {
        return NO;
    }
    id<HLReadableDuration> other = (id<HLReadableDuration>) duration;
    return [self millis] == [other millis];
}

- (NSInteger)hashCode {
    NSInteger len = [self millis];
    return (NSInteger) (len ^ (len >> 32));
}

//-----------------------------------------------------------------------
- (NSString*)description {
    
    NSInteger millis = [self millis];
    NSMutableString* buf = [[NSMutableString alloc] init];
    [buf appendString:@"PT"];
    [HLFormatUtils appendUnpaddedInteger:(millis / 1000) toString:buf];
    NSInteger part = abs(millis % 1000);
    if (part > 0) {
        [buf appendString:@"."];
        [HLFormatUtils appendPaddedInteger:part padding:3 toString:buf];
    }
    [buf appendString:@"S"];
    NSString* string = [buf string];
    [buf release];
    return string;
}

@end
