/*
 * BaseSingleFieldPeriod.m
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

#import "HLBaseSingleFieldPeriod.h"

#import "HLConstants.h"
#import "HLChronology.h"
#import "HLDateTimeUtils.h"
#import "HLFieldUtils.h"
#import "HLDurationField.h"
#import "HLReadablePartial.h"
#import "HLReadablePeriod.h"
#import "HLISOChronology.h"


@implementation HLBaseSingleFieldPeriod

//-----------------------------------------------------------------------
+ (NSInteger)_betweenStart:(id<HLReadableInstant>)start
                       end:(id<HLReadableInstant>)end
                 fieldType:(HLDurationFieldType*)field {
    if (start == nil || end == nil) {
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"HLReadableInstant objects must not be nil"];
    }
    
    HLChronology* chrono = [HLDateTimeUtils instantChronology:start];
    NSInteger amount = [[field field:chrono]
                        difference:[end millis] 
                        :[start millis]];
    return amount;
}

//-----------------------------------------------------------------------
+ (NSInteger)_betweenStart:(id<HLReadablePartial>)start
                       end:(id<HLReadablePartial>)end 
                      zero:(id<HLReadablePeriod>)zeroInstance {
    if (start == nil || end == nil) {
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"ReadablePartial objects must not be nil"];
    }
    if ([start size] != [end size]) {
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"ReadablePartial objects must have the same set of fields"];
    }
    for(NSInteger i = 0, isize = [start size]; i < isize; i++) {
        if ([start fieldTypeAtIndex:i] != [end fieldTypeAtIndex:i]) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                        format:@"ReadablePartial objects must have the same set of fields"];
        }
    }
    if([HLDateTimeUtils isContiguous:start] == NO) {
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"ReadablePartial objects must be contiguous"];
    }
    HLChronology* chrono = [[HLDateTimeUtils chronology:[start chronology]] withUTC];
    NSArray* values = [chrono valuesOfPeriod:zeroInstance
                           startInstantValue:[chrono setPartial:start
                                                    intoInstant:0]
                             endInstantValue:[chrono setPartial:end
                                                    intoInstant:0]];
    return [values objectAtIndex:0];
}

+ (NSInteger)_standardPeriodIn:(id<HLReadablePeriod>)period 
                        millis:(NSInteger)millisPerUnit {
    if (period == nil) {
        return 0;
    }
    
    HLChronology* iso = [HLISOChronology instanceUTC];
    NSInteger duration = 0L;
    for(NSInteger i = 0; i < [period size]; i++) {
        int value = [period valueAtIndex:i];
        if (value != 0) {
            HLDurationField* field = [[period fieldTypeAtIndex:i] field:iso];
            if ([field isPrecise] == NO) {
                [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION 
                            format:@"Cannot convert period to duration as '%@' is not precise in the period '%@'",
                 [field name], period];
            }
            duration = [HLFieldUtils safeAddValue:duration
                                         andValue:[HLFieldUtils safeMultiplyValue:[field unitMillis]
                                                                         andValue:value]];
        }
    }
    return [HLFieldUtils safeToInteger:(duration / millisPerUnit)];
}

//-----------------------------------------------------------------------
/**
 * Creates a new instance representing the specified period.
 *
 * @param period  the period to represent
 */
- (id)initWithPeriod:(NSInteger)period {
    self = [super init];
    if(self) {
        
        _iPeriod = period;
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (NSInteger)_value {
    return _iPeriod;
}

- (void)_setValue:(NSInteger)value {
    _iPeriod = value;
}

//-----------------------------------------------------------------------
- (HLDurationFieldType*)fieldType {
    [NSException raise:HL_UNIMPLEMENTED_EXCEPTION
                format:@"%s must be implemented by subclass", _cmd];
}

- (HLPeriodType*)periodType {
    [NSException raise:HL_UNIMPLEMENTED_EXCEPTION
                format:@"%s must be implemented by subclass", _cmd];
}

//-----------------------------------------------------------------------
- (NSInteger)size {
    return 1;
}

- (HLDurationFieldType*)fieldTypeAtIndex:(NSInteger)index {
    if (index != 0) {
        [NSException raise:HL_INDEX_OUT_OF_BOUNDS_EXCEPTION
                    format:@"Index (%ld) out of bounds", index];
    }
    
    return [self fieldType];
}

- (NSInteger)valueAtIndex:(NSInteger)index {
    if (index != 0) {
        [NSException raise:HL_INDEX_OUT_OF_BOUNDS_EXCEPTION
                    format:@"Index (%ld) out of bounds", index];
    }
    
    return [self _value];
}

- (NSInteger)get:(HLDurationFieldType*)type {
    if (type == [self fieldType]) {
        return [self _value];
    }
    
    return 0;
}

- (BOOL)isSupported:(HLDurationFieldType*)type) {
    return (type == [self fieldType]);
}

//-----------------------------------------------------------------------
- (HLPeriod*)toPeriod {
    return [HL_PERIOD_ZERO withFields:self];
}

- (HLMutablePeriod*)toMutablePeriod {
    HLMutablePeriod* period = [[HLMutablePeriod alloc] init];
    [period add:self];
    return [period autorelease];
}

//-----------------------------------------------------------------------
- (BOOL)isEqualTo:(id)period {
    if(self == period) {
        return YES;
    }
    if([period conformsToProtocol:@protocol(HLReadablePeriod)] == NO) {
        return NO;
    }
    id<HLReadablePeriod> other = (id<HLReadablePeriod>)period;
    return ([other periodType] == [self periodType] && 
            [other valueAtIndex:0] == [self _value]);
}

- (NSUInteger)hash {
    NSInteger total = 17;
    total = 27 * total + [self _value];
    total = 27 * total + [[self fieldType] hash];
    return total;
}

- (NSComparisonResult)compareTo:(id)other {
    if([other class] != [self class]) {
        [NSException raise:HL_OBJECT_MISMATCH_EXCEPTION
                    format:@"%@ cannot be compared to %@", [self class], [other class]];
    }
    NSInteger otherValue = [(HLBaseSingleFieldPeriod*)other _value];
    NSInteger thisValue = [self _value];
    if (thisValue > otherValue) {
        return NSOrderedAscending;
    }
    if (thisValue < otherValue) {
        return NSOrderedDescending;
    }
    return NSOrderedSame;
}

@end
