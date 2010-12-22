/*
 * HLAbstractPeriod.m
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
 
#import "Base/HLAbstractPeriod.h"
#import "Format/HLISOPeriodFormat.h"
#import "Core/HLPeriod.h"
#import "Core/HLMutablePeriod.h"


@implementation HLAbstractPeriod

- (id)init {
    if(self = [super init]) {
        
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (NSArray*)fieldTypes {
    NSMutableArray* result = [NSMutableArray arrayWithCapacity:[self size]];
    for (int i = 0; i < [self size]; i++) {
        [result addObject:[self fieldTypeAtIndex:i]];
    }
    
    return [NSArray arrayWithArray:result];
}

- (NSArray*)values {
    NSMutableArray* result = [NSMutableArray arrayWithCapacity:[self size]];
    for (int i = 0; i < [self size]; i++) {
        [result addObject:[NSNumber numberWithInteger:[self valueAtIndex:i]]];
    }

    return [NSArray arrayWithArray:result];
}

//-----------------------------------------------------------------------
- (NSInteger)get:(HLDurationFieldType*)type {
    NSInteger index = [self indexOf:type];
    if (index == -1) {
        return 0;
    }
    
    return [self valueAtIndex:index];
}

- (BOOL)isSupported:(HLDurationFieldType*)type {
    return [[self periodType] isSupported:type];
}

- (NSInteger)indexOf:(HLDurationFieldType*)type {
    return [[self periodType] indexOf:type];
}

//-----------------------------------------------------------------------
- (HLPeriod*)toPeriod {
    return [[[HLPeriod alloc] initWithPeriod:self] autorelease];
}

- (HLMutablePeriod*)toMutablePeriod {
    return [[[HLMutablePeriod alloc] initWithPeriod:self] autorelease];
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
    if ([self size] != [other size]) {
        return NO;
    }
    for (int i = 0, isize = [self size]; i < isize; i++) {
        if ([self valueAtIndex:i] != [other valueAtIndex:i] || [self fieldTypeAtIndex:i] != [other fieldTypeAtIndex:i]) {
            return NO;
        }
    }
    
    return YES;
}

- (NSInteger)hashCode {
    NSInteger total = 17;
    for (int i = 0, isize = [self size]; i < isize; i++) {
        total = 27 * total + [self valueAtIndex:i];
        total = 27 * total + [[self fieldTypeAtIndex:i] hashCode];
    }
    
    return total;
}

//-----------------------------------------------------------------------
- (NSString*)description {
    return [[HLISOPeriodFormat standard] print:self];
}

//-----------------------------------------------------------------------
- (NSString*)stringWithPeriodFormatter:(HLPeriodFormatter *)formatter {
    if (formatter == nil) {
        return [self description];
    }
    
    return [formatter print:self];
}

@end
