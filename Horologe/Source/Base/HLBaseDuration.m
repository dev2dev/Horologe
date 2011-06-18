/*
 * BaseDuration.m
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

#import "HLBaseDuration.h"

#import "HLInterval.h"
#import "HLFieldUtils.h"
#import "HLDateTimeUtils.h"
#import "HLConverterManager.h"
#import "HLDurationConverter.h"
#import "HLPeriod.h"


/**
 * BaseDuration is an abstract implementation of ReadableDuration that stores
 * data in a <code>long</code> duration milliseconds field.
 * <p>
 * This class should generally not be used directly by API users.
 * The {@link ReadableDuration} interface should be used when different 
 * kinds of duration objects are to be referenced.
 * <p>
 * BaseDuration subclasses may be mutable and not thread-safe.
 *
 * @author Brian S O'Neill
 * @author Stephen Colebourne
 * @since 1.0
 */
@implementation HLBaseDuration

- (id)_initWithDuration:(NSInteger)duration {
    self = [super _init];
    if(self) {
        _iMillis = duration;
    }
    
    return self;
}

- (id)_initWithStart:(NSInteger)startInstant 
                 end:(NSInteger)endInstant {
    self = [super _init];
    if(self) {
        _iMillis = [HLFieldUtils safeAddValue:endInstant
                                     andValue:-startInstant];
    }
    
    return self;
}

- (id)_initWithStartInstant:(id<HLReadableInstant>)start 
                 endInstant:(id<HLReadableInstant>)end {
    self = [super _init];
    if(self) {
        if (start == end) {
            _iMillis = 0L;
        } 
        else {
            NSInteger startMillis = [HLDateTimeUtils instantMillis:start];
            NSInteger endMillis = [HLDateTimeUtils instantMillis:end];
            _iMillis = [HLFieldUtils safeAddValue:endMillis
                                         andValue:-startMillis];
        }
    }
    
    return self;
}

- (id)_initWithDurationObject:(id)duration {
    self = [super _init];
    if(self) {
        HLDurationConverter* converter = [[HLConverterManager instance] durationConverter:duration];
        _iMillis = [converter durationMillis:duration];
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (NSInteger)millis {
    return _iMillis;
}

//-----------------------------------------------------------------------
- (void)_setMillis:(NSInteger)duration {
    
    [self willChangeValueForKey:@"millis"];
    _iMillis = duration;
    [self didChangeValueForKey:@"millis"];
}

//-----------------------------------------------------------------------
- (HLPeriod*)toPeriod:(HLPeriodType*)type {
    return [[[HLPeriod alloc] init (getMillis(), type);
}

- (HLPeriod*)toPeriod:(HLChronology*)chrono {
    return new Period(getMillis(), chrono);
}

- (HLPeriod*)toPeriod:(HLPeriodType*)type,
chronology:(HLChronology*)chrono {
    return new Period(getMillis(), type, chrono);
}

- (HLPeriod*)toPeriodFrom:(id<HLReadableInstant>)startInstant {
    return new Period(startInstant, this);
}

- (HLPeriod*)toPeriodFrom:(id<HLReadableInstant>)startInstant
periodType:(HLPeriodType*)type {
    return new Period(startInstant, this, type);
}

- (HLPeriod*)toPeriodTo:(id<HLReadableInstant>)endInstant {
    return new Period(this, endInstant);
}

- (HLPeriod*)toPeriodTo:(id<HLReadableInstant>)endInstant
periodType:(HLPeriodType*)type {
    return new Period(this, endInstant, type);
}

- (HLInterval*)toIntervalFrom:(id<HLReadableInstant>)startInstant {
    return [[[HLInterval alloc] initWithStartInstant:startInstant
                                          endInstant:self] autorelease];
}

- (HLInterval*)toIntervalTo:(id<HLReadableInstant>)endInstant {
    return [[[HLInterval alloc] initWithStartInstant:self
                                          endInstant:endInstant] autorelease];
}

@end
