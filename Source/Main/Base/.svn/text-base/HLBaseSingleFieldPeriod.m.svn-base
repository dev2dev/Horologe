/*
 * HLBaseSingleFieldPeriod.m
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

#import "Base/HLBaseSingleFieldPeriod.h"
#import "Core/HLReadablePeriod.h"
#import "Core/HLDateTimeUtils.h"
#import "Core/HLChronology.h"
#import "Core/HLDurationFieldType.h"
#import "Field/HLFieldUtils.h"
#import "Chrono/HLISOChronology.h"
#import "Core/HLReadableInstant.h"


@implementation HLBaseSingleFieldPeriod

//-----------------------------------------------------------------------
+ (NSInteger)betweenInstantStart:(id<HLReadableInstant>)start 
                             end:(id<HLReadableInstant>)end 
                           field:(HLDurationFieldType*)field {
    if (start == nil || end == nil) {
        [NSException raise:NSInvalidArgumentException format:@"HLReadableInstant objects must not be null"];
    }
    HLChronology* chrono = [HLDateTimeUtils instantChronology:start];
    NSInteger amount = [[field fieldWithChronology:chrono] differenceBetweenValue:[end millis] andValue:[start millis]];
    return amount;
}

//-----------------------------------------------------------------------
+ (NSInteger)betweenPartialStart:(id<HLReadablePartial>)start 
                             end:(id<HLReadablePartial>)end 
                          period:(id<HLReadablePeriod>)zeroInstance {
    if (start == nil || end == nil) {
        [NSException raise:NSInvalidArgumentException format:@"HLReadablePartial objects must not be null"];
    }
    if ([start size] != [end size]) {
        [NSException raise:NSInvalidArgumentException format:@"HLReadablePartial objects must have the same set of fields"];
    }
    for (NSInteger i = 0, isize = [start size]; i < isize; i++) {
        if ([start fieldTypeAtIndex:i] != [end fieldTypeAtIndex:i]) {
            [NSException raise:NSInvalidArgumentException format:@"HLReadablePartial objects must have the same set of fields"];
        }
    }
    if ([HLDateTimeUtils isContiguous:start] == NO) {
        [NSException raise:NSInvalidArgumentException format:@"HLReadablePartial objects must be contiguous"];
    }
    HLChronology* chrono = [[HLDateTimeUtils chronology:[start chronology]] withUTC];
    NSArray* values = [chrono get:zeroInstance 
                     startInstant:[chrono set:start 
                                      instant:0L]
                       endInstant:[chrono set:end 
                                      instant:0L]];
    return [(NSNumber*)[values objectAtIndex:0] integerValue];
}

+ (NSInteger)standardPeriodInPeriod:(id<HLReadablePeriod>)period 
                      millisPerUnit:(long)millisPerUnit {
    if (period == nil) {
        return 0;
    }
    HLChronology* iso = [HLISOChronology instanceUTC];
    long duration = 0L;
    for (NSInteger i = 0; i < [period size]; i++) {
        NSInteger value = [period valueAtIndex:i];
        if (value != 0) {
            HLDurationField* field = [[period fieldTypeAtIndex:i] fieldWithChronology:iso];
            if ([field isPrecise] == NO) {
                [NSException raise:NSInvalidArgumentException 
                            format:@"Cannot convert period to duration as %@ is not precise in the period %@", 
                 [field name], period];
            }
            duration = [HLFieldUtils safeAddValue:duration andValue:[HLFieldUtils safeMultiplyValue:[field unitMillis] andValue:value]];
        }
    }
    return [HLFieldUtils safeToInt:(duration / millisPerUnit)];
}

//-----------------------------------------------------------------------
- (id)initWithPeriod:(NSInteger)period {
    if(self = [super init]) {
        iPeriod = period;
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (NSInteger)value {
    return iPeriod;
}

- (void)setValue:(NSInteger)value {
    iPeriod = value;
}

//-----------------------------------------------------------------------
//- (HLDurationFieldType*)fieldType;

//- (HLPeriodType*)periodType;

//-----------------------------------------------------------------------
- (NSInteger)size {
    return 1;
}

- (HLDurationFieldType*)fieldTypeAtIndex:(NSInteger)index {
    if (index != 0) {
        [NSException raise:NSRangeException format:@"Array index out of bounds: %d", index];
    }
    
    return [self fieldType];
}

- (NSInteger)valueAtIndex:(NSInteger)index {
    if (index != 0) {
        [NSException raise:NSRangeException format:@"Array index out of bounds: %d", index];
    }
    return [self value];
}

- (NSInteger)get:(HLDurationFieldType*)type {
    if (type == [self fieldType]) {
        return [self value];
    }
    
    return 0;
}

- (BOOL)isSupported:(HLDurationFieldType*)type {
    return (type == [self fieldType]);
}

//-----------------------------------------------------------------------
- (HLPeriod*)toPeriod {
    return [[HLPeriod zeroPeriod] withFields:self];
}

- (HLMutablePeriod*)toMutablePeriod {
    HLMutablePeriod* period = [[[HLMutablePeriod alloc] init] autorelease];
    [period add:self];
    return period;
}

//-----------------------------------------------------------------------
- (BOOL)isEqual:(id)period {
    if (self == period) {
        return YES;
    }
    if (![period conformsToProtocol:@protocol(HLReadablePeriod)]) {
        return NO;
    }
    id<HLReadablePeriod> other = (id<HLReadablePeriod>) period;
    return ([other periodType] == [self periodType] && [other valueAtIndex:0] == [self value]);
}

- (NSInteger)hashCode {
    NSInteger total = 17;
    total = 27 * total + [self value];
    total = 27 * total + [[self fieldType] hashCode];
    return total;
}

- (NSInteger)compareTo:(HLBaseSingleFieldPeriod*)other {
    
    if([other class] != [self class]) {
        [NSException raise:NSInvalidArgumentException format:@"%@ cannot be compared to %@", [self class], [other class]];
    }
    NSInteger otherValue = [other value];
    NSInteger thisValue = [self value];
    if (thisValue > otherValue) {
        return 1;
    }
    if (thisValue < otherValue) {
        return -1;
    }
    return 0;
}

@end
