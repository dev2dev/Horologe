/*
 * HLBasePeriod.m
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

#import "Base/HLBasePeriod.h"
#import "Core/HLPeriodType.h"
#import "Core/HLDurationFieldType.h"
#import "Core/HLReadablePeriod.h"
#import "Core/HLChronology.h"
#import "Core/HLDateTimeUtils.h"
#import "Base/HLBaseLocal.h"
#import "Field/HLFieldUtils.h"
#import "Convert/HLPeriodConverter.h"
#import "Convert/HLConverterManager.h"
#import "Core/HLReadWritablePeriod.h"


@interface HLBasePeriod (PrivateMethods)

- (void)checkAndUpdate:(HLDurationFieldType*)type 
                values:(NSMutableArray*)values
              newValue:(NSInteger)newValue;

- (void)setPeriodInternal:(id<HLReadablePeriod>)period;

- (void)setPeriodInternalYears:(NSInteger)years 
                        months:(NSInteger)months 
                         weeks:(NSInteger)weeks
                          days:(NSInteger)days
                         hours:(NSInteger)hours
                       minutes:(NSInteger)minutes
                       seconds:(NSInteger)seconds
                        millis:(NSInteger)millis;

@end


@implementation HLBasePeriod

//-----------------------------------------------------------------------
- (id)_initWithYears:(NSInteger)years 
              months:(NSInteger)months 
               weeks:(NSInteger)weeks
                days:(NSInteger)days
               hours:(NSInteger)hours
             minutes:(NSInteger)minutes
             seconds:(NSInteger)seconds
              millis:(NSInteger)millis
                type:(HLPeriodType*)type {
    
    if(self = [super init]) {
        type = [self _checkPeriodType:type];
        iType = [type retain];
        [self _setPeriodInternalYears:years months:months weeks:weeks days:days hours:hours minutes:minutes seconds:seconds millis:millis]; // internal method
    }
    
    return self;
}

- (id)_initWithInstantStart:(NSInteger)startInstant
                        end:(NSInteger)endInstant
                       type:(HLPeriodType*)type
                 chronology:(HLChronology*)chrono {
    
    if(self = [super init]) {
        type = [self _checkPeriodType:type];
        chrono = [HLDateTimeUtils chronology:chrono];
        iType = [type retain];
        iValues = [[chrono getWithPeriod:self startInstant:startInstant endInstant:endInstant] retain];
    }
    
    return self;
}

- (id)_initWithInstantStart:(NSInteger)startInstant
                        end:(NSInteger)endInstant
                       type:(HLPeriodType*)type {
    
    if(self = [super init]) {
        type = [self _checkPeriodType:type];
        if (startInstant == nil && endInstant == nil) {
            iType = [type retain];
            iValues = [NSMutableArray arrayWithCapacity:[self size]];
        } 
        else {
            NSInteger startMillis = [HLDateTimeUtils instantMillis:startInstant];
            NSInteger endMillis = [HLDateTimeUtils instantMillis:endInstant];
            HLChronology* chrono = [HLDateTimeUtils intervalChronologyWithStartInstant:startInstant endInstant:endInstant];
            iType = [type retain];
            iValues = [[chrono getWithPeriod:self start:startMillis end:endMillis] retain];
        }
    }
    
    return self;
}

- (id)_initWithPartialStart:(id<HLReadablePartial>)start
                        end:(id<HLReadablePartial>)end
                       type:(HLPeriodType*)type {
    
    if(self = [super init]) {
        if (start == nil || end == nil) {
            [NSException raise:NSInvalidArgumentException format:@"HLReadablePartial objects must not be null"];
        }
        
        if ([start isKindOfClass:[HLBaseLocal class]] && [end isKindOfClass:[HLBaseLocal class]] && [start class] == [end class]) {
            // for performance
            type = [self _checkPeriodType:type];
            NSInteger startMillis = [(HLBaseLocal*)start localMillis];
            NSInteger endMillis = [(HLBaseLocal*)end localMillis];
            HLChronology* chrono = [start chronology];
            chrono = [HLDateTimeUtils chronology:chrono];
            iType = [type retain];
            iValues = [chrono get:self startInstant:startMillis endInstant:endMillis];
        } 
        else {
            if ([start size] != [end size]) {
                [NSException raise:NSInvalidArgumentException format:@"HLReadablePartial objects must have the same set of fields"];
            }
            
            for (int i = 0, isize = [start size]; i < isize; i++) {
                if ([start fieldTypeAtIndex:i] != [end fieldTypeAtIndex:i]) {
                    [NSException raise:NSInvalidArgumentException format:@"HLReadablePartial objects must have the same set of fields"];
                }
                
                
                if (![HLDateTimeUtils isContiguous:start]) {
                    [NSException raise:NSInvalidArgumentException format:@"HLReadablePartial objects must be contiguous"];
                }
                
                iType = [self _checkPeriodType:type];
                HLChronology* chrono = [[HLDateTimeUtils chronology:[start chronology]] withUTC];
                iValues = [chrono get:self startInstant:[chrono set:start instant:0L] endInstant:[chrono set:end instant:0L]];
            }
        }
    }
    
    return self;
}

- (id)_initWithStartInstant:(id<HLReadableInstant>)startInstant
                   duration:(id<HLReadableDuration>)duration
                       type:(HLPeriodType*)type {
    
    if(self = [super init]) {
        type = [self _checkPeriodType:type];
        NSInteger startMillis = [HLDateTimeUtils instantMillis:startInstant];
        NSInteger durationMillis = [HLDateTimeUtils durationMillis:duration];
        NSInteger endMillis = [HLFieldUtils safeAddValue:startMillis toValue:durationMillis];
        HLChronology* chrono = [HLDateTimeUtils instantChronology:startInstant];
        iType = [type retain];
        iValues = [chrono get:self startInstant:startMillis endInstant:endMillis];
    }
    
    return self;
}

- (id)_initWithDuration:(id<HLReadableDuration>)duration
             endInstant:(id<HLReadableInstant>)endInstant
                   type:(HLPeriodType*)type {
    
    if(self = [super init]) {
        type = [self _checkPeriodType:type];
        NSInteger durationMillis = [HLDateTimeUtils durationMillis:duration];
        NSInteger endMillis = [HLDateTimeUtils instantMillis:endInstant];
        NSInteger startMillis = [HLFieldUtils safeSubtract:endMillis andValue:durationMillis];
        HLChronology* chrono = [HLDateTimeUtils instantChronology:endInstant];
        iType = [type retain];
        iValues = [chrono get:self startInstant:startMillis endInstant:endMillis];
    }
    
    return self;
}

- (id)_initWithDuration:(NSInteger)duration
                   type:(HLPeriodType*)type
             chronology:(HLChronology*)chrono {
    if(self = [super init]) {
        type = [self _checkPeriodType:type];
        chrono = [HLDateTimeUtils chronology:chrono];
        iType = [type retain];
        iValues = [chrono get:self duration:duration];
    }
    
    return self;
}

- (id)_initWithPeriodObject:(id)period
                       type:(HLPeriodType*)type
                 chronology:(HLChronology*)chrono {
    if(self = [super init]) {
        HLPeriodConverter* converter = [[HLConverterManager instance] periodConverter:period];
        type = (type == nil ? [converter periodType:period] : type);
        type = [self _checkPeriodType:type];
        iType = [type retain];
        if ([self conformsToProtocol:@protocol(HLReadWritablePeriod)]) {
            iValues = [[[NSMutableArray arrayWithCapacity:[self size]] array] retain];
            chrono = [HLDateTimeUtils chronology:chrono];
            [converter setIntoPeriod:self period:period chronology:chrono];
        } 
        else {
            HLMutablePeriod* period = [[HLMutablePeriod alloc] initWithPeriod:period type:type chronology:chrono];
            iValues = [period values];
            [period release];
        }        
    }
    
    return self;
}

- (id)_initWithValues:(NSArray*)values
                 type:(HLPeriodType*)type {
    if(self = [super init]) {
        iType = [type retain];
        iValues = [[NSArray arrayWithArray:values] retain];
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (HLPeriodType*)_checkPeriodType:(HLPeriodType*)type {
    return [HLDateTimeUtils periodType:type];
}

//-----------------------------------------------------------------------
- (HLPeriodType*)periodType {
    return iType;
}

//-----------------------------------------------------------------------
- (NSInteger)size {
    return [iType size];
}

- (HLDurationFieldType*)fieldTypeAtIndex:(NSInteger)index {
    return [iType fieldTypeAtIndex:index];
}

- (NSInteger)valueAtIndex:(NSInteger)index {
    return [(NSNumber*)[iValues objectAtIndex:index] integerValue];
}

//-----------------------------------------------------------------------
- (HLDuration*)toDurationFrom:(id<HLReadableInstant>)startInstant {
    NSInteger startMillis = [HLDateTimeUtils instantMillis:startInstant];
    HLChronology* chrono = [HLDateTimeUtils instantChronology:startInstant];
    NSInteger endMillis = [chrono addPeriod:self duration:startMillis scalar:1];
    return [[[HLDuration alloc] initWithStart:startMillis end:endMillis] autorelease];
}

- (HLDuration*)toDurationTo:(id<HLReadableInstant>)endInstant {
    NSInteger endMillis = [HLDateTimeUtils instantMillis:endInstant];
    HLChronology* chrono = [HLDateTimeUtils instantChronology:endInstant];
    NSInteger startMillis = [chrono addPeriod:self instant:endMillis scalar:-1];
    return [[[HLDuration alloc] initWithStart:startMillis end:endMillis] autorelease];
}

//-----------------------------------------------------------------------
- (void)checkAndUpdate:(HLDurationFieldType*)type
                values:(NSMutableArray*)values
              newValue:(NSInteger)newValue {
    NSInteger index = [self indexOf:type];
    if (index == -1) {
        if (newValue != 0) {
            [NSException raise:NSInvalidArgumentException format:@"Period does not support field '%@'", [type name]];
        }
    } 
    else {
        [values replaceObjectAtIndex:index withObject:[NSNumber numberWithInteger:newValue]];
    }
}

//-----------------------------------------------------------------------
- (void)_setPeriod:(id<HLReadablePeriod>)period {
    if (period == nil) {
        [self _setValues:[[NSMutableArray arrayWithCapacity:[self size]] array]];
    } 
    else {
        [self setPeriodInternal:period];
    }
}

- (void)setPeriodInternal:(id<HLReadablePeriod>)period {
    NSMutableArray* newValues = [NSMutableArray arrayWithCapacity:[self size]];
    for (NSInteger i = 0, isize = [period size]; i < isize; i++) {
        HLDurationFieldType* type = [period fieldTypeAtIndex:i];
        NSInteger value = [period valueAtIndex:i];
        [self checkAndUpdate:type values:newValues value:value];
    }
    
    iValues = [newValues retain];
}

- (void)_setPeriodYears:(NSInteger)years
                 months:(NSInteger)months
                  weeks:(NSInteger)weeks
                   days:(NSInteger)days
                  hours:(NSInteger)hours
                minutes:(NSInteger)minutes
                seconds:(NSInteger)seconds
                 millis:(NSInteger)millis {
    [self setPeriodInternalYears:years months:months weeks:weeks days:days hours:hours minutes:minutes seconds:seconds millis:millis];
}

- (void)setPeriodInternalYears:(NSInteger)years
                        months:(NSInteger)months
                         weeks:(NSInteger)weeks
                          days:(NSInteger)days
                         hours:(NSInteger)hours
                       minutes:(NSInteger)minutes
                       seconds:(NSInteger)seconds
                        millis:(NSInteger)millis {
    NSMutableArray* newValues = [NSMutableArray arrayWithCapacity:[self size]];
    [self checkAndUpdate:[HLDurationFieldType years] values:newValues value:years];
    [self checkAndUpdate:[HLDurationFieldType months] values:newValues value:months];
    [self checkAndUpdate:[HLDurationFieldType weeks] values:newValues value:weeks];
    [self checkAndUpdate:[HLDurationFieldType days] values:newValues value:days];
    [self checkAndUpdate:[HLDurationFieldType hours] values:newValues value:hours];
    [self checkAndUpdate:[HLDurationFieldType minutes] values:newValues value:minutes];
    [self checkAndUpdate:[HLDurationFieldType seconds] values:newValues value:seconds];
    [self checkAndUpdate:[HLDurationFieldType millis] values:newValues value:millis];
    iValues = [newValues retain];
}

//-----------------------------------------------------------------------
- (void)_setField:(HLDurationFieldType*)field 
            value:(NSInteger)value {
    [self _setFieldInto:iValues field:field value:value];
}

- (void)_setFieldInto:(NSMutableArray*)values
                field:(HLDurationFieldType*)field
                value:(NSInteger)value {
    NSInteger index = [self indexOf:field];
    if (index == -1) {
        if (value != 0 || field == nil) {
            [NSException raise:NSInvalidArgumentException format:@"Period does not support field '%@'", field];
        }
    } 
    else {
        [values replaceObjectAtIndex:index withObject:[NSNumber numberWithInteger:value]];
    }
}

- (void)_addField:(HLDurationFieldType*)field
            value:(NSInteger)value {
    [self addFieldInto:iValues field:field value:value];
}

- (void)addFieldInto:(NSArray*)values
               field:(HLDurationFieldType*)field
               value:(NSInteger)value {
    NSInteger index = [self indexOf:field];
    if (index == -1) {
        if (value != 0 || field == nil) {
            [NSException raise:NSInvalidArgumentException format:@"Period does not support field '%@'", field];
        }
    }
    else {
        [values replaceObjectAtIndex:index 
                          withObject:[NSNumber numberWithInteger:[HLFieldUtils safeAddValue:[(NSNumber*)[values objectAtIndex:index] integerValue] 
                                                                                   andValue:value]]];
    }
}

- (void)_mergePeriod:(id<HLReadablePeriod>)period {
    if (period != nil) {
        iValues = [self _mergePeriodInto:[self values] 
                                  period:period];
    }
}

- (NSArray*)_mergePeriodInto:(NSArray*)values 
                      period:(id<HLReadablePeriod>)period {
    for (NSInteger i = 0, isize = [period size]; i < isize; i++) {
        HLDurationFieldType* type = [period fieldTypeAtIndex:i];
        NSInteger value = [period valueAtIndex:i];
        [self _checkAndUpdate:type 
                       values:values 
                        value:value];
    }
    
    return values;
}

- (void)_addPeriod:(id<HLReadablePeriod>)period {
    if (period != nil) {
        iValues = [self _addPeriodInto:[self values] 
                                period:period];
    }
}

- (NSArray*)_addPeriodInto:(NSArray*)values
                    period:(id<HLReadablePeriod>)period {
    
    for (NSInteger i = 0, isize = [period size]; i < isize; i++) {
        HLDurationFieldType* type = [period fieldTypeAtIndex:i];
        NSInteger value = [period valueAtIndex:i];
        if (value != 0) {
            NSInteger index = [self indexOf:type];
            if (index == -1) {
                [NSException raise:NSInvalidArgumentException format:@"Period does not support field '%@'", [type name]];
            } else {
                [values setValue:[HLFieldUtils safeAddValue:[self valueAtIndex:index] 
                                                   andValue:value] 
                         atIndex:index];
            }
        }
    }
    
    return values;
}

//-----------------------------------------------------------------------
- (void)_setValue:(NSInteger)value atIndex:(NSInteger)index {
    [iValues setValue:value 
              atIndex:index];
}

- (void)_setValues:(NSArray*)values {
    [iValues release];
    iValues = [values retain];
}

//-----------------------------------------------------------------------
- (void)dealloc {
    [iType release];
    [iValues release];
    
    [super dealloc];
}

@end
