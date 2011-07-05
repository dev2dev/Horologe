/*
 * AbstractDuration.m
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

#import "HLAbstractDuration.h"

#import "HLPeriod.h"
#import "HLDuration.h"
#import "HLFormatUtils.h"


@implementation HLAbstractDuration

//-----------------------------------------------------------------------
- (HLDuration*)toDuration {
    return [[[HLDuration alloc] initWithMillis:[self millis]] autorelease];
}

//-----------------------------------------------------------------------
- (HLPeriod*)toPeriod {
    return [[[HLPeriod alloc] initWithMillis:[self millis]] autorelease];
}

//-----------------------------------------------------------------------
- (NSComparisonResult)compare:(id)obj {
    
    // Comparable contract means we cannot handle nil or other types gracefully
    id<HLReadableDuration> thisDuration = (id<HLReadableDuration>)self;
    id<HLReadableDuration> otherDuration = (id<HLReadableDuration>)obj;
    
    NSInteger thisMillis = [thisDuration millis];
    NSInteger otherMillis = [otherDuration millis];
    
    // cannot do (thisMillis - otherMillis) as it can overflow
    if (thisMillis < otherMillis) {
        return NSOrderedDescending;
    }
    if (thisMillis > otherMillis) {
        return NSOrderedAscending;
    }
    
    return NSOrderedSame;
}

- (BOOL)isEqualToDuration:(id<HLReadableDuration>)duration {
    if (duration == nil) {
        duration = [HLDuration zeroDuration];
    }
    
    return [self compare:duration] == NSOrderedSame;
}

- (BOOL)isLongerThanDuration:(id<HLReadableDuration>)duration {
    if (duration == nil) {
        duration = [HLDuration zeroDuration];
    }
    
    return [self compare:duration] == NSOrderedAscending;
}

- (BOOL)isShorterThanDuration:(id<HLReadableDuration>)duration {
    if (duration == nil) {
        duration = [HLDuration zeroDuration];
    }
    
    return [self compare:duration] == NSOrderedDescending;
}

//-----------------------------------------------------------------------
- (BOOL)isEqualToDuration:(id)duration {
    if(self == duration) {
        return YES;
    }
    if([duration conformsToProtocol:@protocol(HLReadableDuration)] == NO) {
        return NO;
    }
    
    id<HLReadableDuration> other = (id<HLReadableDuration>)duration;
    
    return ([self millis] == [other millis]);
}

- (NSUInteger)hash {
    NSInteger len = [self millis];
    return (NSUInteger) (len ^ (len >>> 32));
}

//-----------------------------------------------------------------------
- (NSString*)description {
    
    NSInteger millis = [self millis];
    NSMutableString* buf = [NSMutableString string];
    [buf appendString:@"PT"];
    [HLFormatUtils appendUnpaddedInteger:(millis / 1000)
                         toMutableString:buf];
    NSInteger part = abs(millis % 1000);
    if(part > 0) {
        [buf appendString:@"."];
        [HLFormatUtils appendPaddedInteger:part
                               withPadding:3
                           toMutableString:buf];
    }
    [buf appendString:@"S"];
    
    return [[buf copy] autorelease];
}

@end
