/*
 * HLBaseDuration.m
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

#import "Base/HLBaseDuration.h"
#import "Field/HLFieldUtils.h"
#import "Core/HLDateTimeUtils.h"
#import "Convert/HLConverterManager.h"
#import "Convert/HLDurationConverter.h"
#import "Core/HLPeriod.h"
#import "Core/HLInterval.h"


@implementation HLBaseDuration

- (id)_initWithDuration:(NSInteger)duration {
    
    if(self = [super _init]) {
        iMillis = duration;
    }    
    
    return self;
}

- (id)_initWithStart:(NSInteger)startInstant
                 end:(NSInteger)endInstant {
    
    if(self = [super _init]) {
        iMillis = [HLFieldUtils safeAdd:endInstant val2:-startInstant];        
    }
    
    return self;
}

- (id)_initWithReadableInstantStart:(id<HLReadableInstant>)start
                                end:(id<HLReadableInstant>)end {
    
    if(self = [super _init]) {
        if (start == end) {
            iMillis = 0L;
        } 
        else {
            NSInteger startMillis = [HLDateTimeUtils instantMillis:start];
            NSInteger endMillis = [HLDateTimeUtils instantMillis:end];
            iMillis = [HLFieldUtils safeAdd:endMillis val2:-startMillis];
        }        
    }
    
    return self;
}

- (id)_initWithObject:(id)duration {
    
    if(self = [super _init]) {
        HLDurationConverter* converter = [[HLConverterManager instance] durationConverter:duration];
        iMillis = [converter durationMillis:duration];
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (NSInteger)millis {
    return iMillis;
}

//-----------------------------------------------------------------------
- (void)_setMillis:(NSInteger)duration {
    iMillis = duration;
}

//-----------------------------------------------------------------------
- (HLPeriod*)toPeriodFromType:(HLPeriodType*)type {
    return [[[HLPeriod alloc] initWithMillis:[self millis] type:type] autorelease];
}

- (HLPeriod*)toPeriodFromChronology:(HLChronology*)chrono {
    return [[[HLPeriod alloc] initWithMillis:[self millis] chronology:chrono] autorelease];
}

- (HLPeriod*)toPeriodFromType:(HLPeriodType*)type
                   chronology:(HLChronology*)chrono {
    return [[[HLPeriod alloc] initWithMillis:[self millis] type:type chronology:chrono] autorelease];
}

- (HLPeriod*)toPeriodFromInstantFrom:(id<HLReadableInstant>)startInstant {
    return [[[HLPeriod alloc] initWithStartInstant:startInstant duration:self] autorelease];
}

- (HLPeriod*)toPeriodFromInstantFrom:(id<HLReadableInstant>)startInstant 
                                type:(HLPeriodType*)type {
    return [[[HLPeriod alloc] initWithStartInstant:startInstant duration:self type:type] autorelease];
}

- (HLPeriod*)toPeriodFromInstantTo:(id<HLReadableInstant>)endInstant {
    return [[[HLPeriod alloc] initWithDuration:self endInstant:endInstant] autorelease];
}

- (HLPeriod*)toPeriodFromInstantTo:(id<HLReadableInstant>)endInstant 
                              type:(HLPeriodType*)type {
    return [[[HLPeriod alloc] initWithStartInstant:self endInstant:endInstant type:type] autorelease];
}

- (HLInterval*)toIntervalFromInstantFrom:(id<HLReadableInstant>)startInstant {
    return [[[HLInterval alloc] initWithStartInstant:startInstant duration:self] autorelease];
}

- (HLInterval*)toIntervalFromInstantTo:(id<HLReadableInstant>)endInstant {
    return [[[HLInterval alloc] initWithDuration:self endInstant:endInstant] autorelease];
}

@end
