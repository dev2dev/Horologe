/*
 * DateTimeUtils.m
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

#import "HLDateTimeUtils.h"

#import "HLISOChronology.h"


/** The singleton instance of the system millisecond provider. */
static const HLSystemMillisProvider* SYSTEM_MILLIS_PROVIDER = [[HLSystemMillisProvider alloc] init];
/** The millisecond provider currently in use. */
static volatile HLMillisProvider* cMillisProvider = SYSTEM_MILLIS_PROVIDER;

/**
 * DateTimeUtils provide public utility methods for the date-time library.
 * <p>
 * DateTimeUtils is thread-safe although shared static variables are used.
 *
 * @author Stephen Colebourne
 * @since 1.0
 */
@implementation HLDateTimeUtils

/**
 * Restrictive constructor
 */
- (id)_init {
    self = [super init];
    if(self) {
        
    }
    
    return self;
}

//-----------------------------------------------------------------------
+ (NSInteger)currentTimeMillis {
    return [cMillisProvider millis];
}

+ (void)setCurrentMillisSystem {
    [self _checkPermission];
    cMillisProvider = SYSTEM_MILLIS_PROVIDER;
}

+ (void)setCurrentMillisFixed:(NSInteger)fixedMillis {
    [self _checkPermission];
    cMillisProvider = [[HLFixedMillisProvider alloc] initWithMillis:fixedMillis];
}

+ (void)setCurrentMillisOffset:(NSInteger)offsetMillis {
    [self _checkPermission];
    if (offsetMillis == 0) {
        cMillisProvider = SYSTEM_MILLIS_PROVIDER;
    } 
    else {
        cMillisProvider = [[HLOffsetMillisProvider alloc] initWithMillis:offsetMillis];
    }
}

+ (void)_checkPermission {
    // NOT IMPLEMENTED
}

//-----------------------------------------------------------------------
+ (NSInteger)instantMillis:(id<HLReadableInstant>)instant {
    if (instant == nil) {
        return [HLDateTimeUtils currentTimeMillis];
    }
    
    return [instant millis];
}

//-----------------------------------------------------------------------
+ (HLChronology*)instantChronology:(id<HLReadableInstant>)instant {
    if (instant == nil) {
        return [[[HLISOChronology alloc] init] autorelease];
    }
    
    HLChronology* chrono = [instant chronology];
    if (chrono == nil) {
        return [[[HLISOChronology alloc] init] autorelease];
    }
    
    return chrono;
}

//-----------------------------------------------------------------------
+ (HLChronology*)intervalChronologyWithStart:(id<HLReadableInstant>)start 
                                         end:(id<HLReadableInstant>)end {
    HLChronology* chrono = nil;
    
    if (start != nil) {
        chrono = [start chronology];
    } 
    else if (end != nil) {
        chrono = [end chronology];
    }
    
    if (chrono == nil) {
        chrono = [[[HLISOChronology alloc] init] autorelease];
    }
    
    return chrono;
}

//-----------------------------------------------------------------------
+ (HLChronology*)intervalChronology:(id<HLReadableInterval>)interval {
    
    if (interval == nil) {
        return [[[HLISOChronology alloc] init] autorelease];
    }
    
    HLChronology* chrono = [interval chronology];
    if (chrono == nil) {
        return [[[HLISOChronology alloc] init] autorelease];
    }
    
    return chrono;
}

//-----------------------------------------------------------------------
+ (id<HLReadableInterval>)readableInterval:(id<HLReadableInterval>)interval {
    
    if (interval == nil) {
        NSInteger now = [HLDateTimeUtils currentTimeMillis];
        interval = [[[HLInterval alloc] initWithStart:now
                                                  end:now] autorelease];
    }
    
    return interval;
}

//-----------------------------------------------------------------------
+ (HLChronology*)chronology:(HLChronology*)chrono {
    if (chrono == nil) {
        return [[[HLISOChronology alloc] init] autorelease];
    }
    
    return chrono;
}

//-----------------------------------------------------------------------
+ (HLDateTimeZone*)dateTimeZone:(HLDateTimeZone *)zone {
    
    if (zone == nil) {
        return [HLDateTimeZone defaultDateTimeZone];
    }
    
    return zone;
}

//-----------------------------------------------------------------------
+ (HLPeriodType*)periodType:(HLPeriodType*)type {
    
    if (type == nil) {
        return [HLPeriodType standard];
    }
    
    return type;
}

//-----------------------------------------------------------------------
+ (NSInteger)durationMillis:(id<HLReadableDuration>)duration {
    
    if (duration == nil) {
        return 0L;
    }
    
    return [duration millis];
}

//-----------------------------------------------------------------------
+ (BOOL)isContiguous:(id<HLReadablePartial>)partial {
    
    if (partial == nil) {
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"Partial must not be nil"];
    }
    
    HLDurationFieldType* lastType = nil;
    for(NSInteger i = 0; i < [partial size]; i++) {
        HLDateTimeField* loopField = [partial fieldAtIndexi];
        if (i > 0) {
            if ([[loopField rangeDurationField] type] != lastType) {
                return NO;
            }
        }
        
        lastType = [[loopField durationField] type];
    }
    
    return YES;
}

@end


//-----------------------------------------------------------------------
/**
 * Base class defining a millisecond provider.
 */
@implementation HLMillisProvider 

@end


//-----------------------------------------------------------------------
/**
 * System millis provider.
 */
@implementation HLSystemMillisProvider

- (NSInteger)millis {
    struct timeval tv;
    NSInteger milliseconds = 0;
    if(gettimeofday(&tv, NULL) == 0)
        milliseconds = tv.tv_usec / 1000;
    
    return milliseconds;
}

@end


//-----------------------------------------------------------------------
/**
 * Fixed millisecond provider.
 */
@implementation HLFixedMillisProvider

- (id)initWithMillis:(NSInteger)fixedMillis  {
    _iMillis = fixedMillis;
}

- (NSInteger)millis {
    return _iMillis;
}

@end


//-----------------------------------------------------------------------
/**
 * Offset from system millis provider.
 */
@implementation HLOffsetMillisProvider

- (id)initWithMillis:(NSInteger)offsetMillis {
    _iMillis = offsetMillis;
}

- (NSInteger)millis {
    struct timeval tv;
    NSInteger milliseconds = 0;
    if(gettimeofday(&tv, NULL) == 0)
        milliseconds = tv.tv_usec / 1000;
    
    return milliseconds + _iMillis;
}

@end
