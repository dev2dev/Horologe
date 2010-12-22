/*
 * HLInstant.m
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

#import "HLInstant.h"
#import "HLInstantConverter.h"
#import "HLConverterManager.h"
#import "HLDateTimeUtils.h"
#import "HLISOChronology.h"


@implementation HLInstant

//-----------------------------------------------------------------------
- (id)init {
    if(self = [super init]) {
        iMillis = [HLDateTimeUtils currentTimeMillis];
    }
    
    return self;
}

- (id)initWithInstant:(NSInteger)instant {
    if(self = [super init]) {
        iMillis = instant;
    }
    
    return self;
}

- (id)initWithObject:(id)instant {
    if(self = [super init]) {
        HLInstantConverter* converter = [[HLConverterManager instance] instantConverter:instant];
        iMillis = [converter instantMillis:instant chronology:[HLISOChronology instanceUTC]];
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (HLInstant*)toInstant {
    return self;
}

//-----------------------------------------------------------------------
- (HLInstant*)withMillis:(NSInteger)newMillis {
    return (newMillis == iMillis ? self : [[[HLInstant alloc] initWithMillis:newMillis] autorelease]);
}

- (HLInstant*)withDurationAdded:(NSInteger)durationToAdd scalar:(NSInteger)scalar {
    if (durationToAdd == 0 || scalar == 0) {
        return self;
    }
    NSInteger instant = [[self chronology] add:[self millis] duration:durationToAdd scalar:scalar];
    return [self withMillis:instant];
}

- (HLInstant*)withReadableDurationAdded:(id<HLReadableDuration>)durationToAdd scalar:(NSInteger)scalar {
    if (durationToAdd == nil || scalar == 0) {
        return self;
    }
    return [self withDurationAdded:[durationToAdd millis] scalar:scalar];
}

//-----------------------------------------------------------------------
- (HLInstant*)plus:(NSInteger)duration {
    return [self withDurationAdded:duration scalar:1];
}

- (HLInstant*)plusReadableDuration:(id<HLReadableDuration>)duration {
    return [self withReadableDurationAdded:duration scalar:1];
}

//-----------------------------------------------------------------------
- (HLInstant*)minus:(NSInteger)duration {
    return [self withDurationAdded:duration scalar:-1];
}

- (HLInstant*)minusReadableDuration:(id<HLReadableDuration>)duration {
    return [self withReadableDurationAdded:duration scalar:-1];
}

//-----------------------------------------------------------------------
- (NSInteger)millis {
    return iMillis;
}

- (HLChronology*)chronology {
    return [HLISOChronology instanceUTC];
}

//-----------------------------------------------------------------------
- (HLDateTime*)toDateTime {
    return [[[HLDateTime alloc] initWithMillis:[self millis] chronology:[HLISOChronology instance]] autorelease];
}

- (HLDateTime*)toDateTimeISO {
    return [self toDateTime];
}

- (HLMutableDateTime*)toMutableDateTime {
    return [[[HLMutableDateTime alloc] initWithMillis:[self millis] chronology:[HLISOChronology instance]] autorelease];
}

- (HLMutableDateTime*)toMutableDateTimeISO {
    return [self toMutableDateTime];
}

@end
