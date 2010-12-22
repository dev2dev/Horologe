/*
 * HLAbstractPartial.m
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
 
#import "Base/HLAbstractPartial.h"
#import "Core/HLDateTimeFieldType.h"
#import "Core/HLDateTimeUtils.h"
#import "Field/HLFieldUtils.h"
#import "Format/HLDateTimeFormatter.h"


@implementation HLAbstractPartial

//-----------------------------------------------------------------------
- (id)_init {
    if(self = [super init]) {
        
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (HLDateTimeField*)fieldAtIndex:(NSInteger)index
                       chronology:(HLChronology*)chrono {
    [NSException raise:@"TODO" format:@"Method fieldAtIndex not implemented in this class."];
}

//-----------------------------------------------------------------------
- (HLDateTimeFieldType*)fieldTypeAtIndex:(NSInteger)index {
    return [[self fieldAtIndex:index chronology:[self chronology]] type];
}

- (NSArray*)fieldTypes {
    NSInteger size = [self size];
    NSMutableArray* result = [NSMutableArray arrayWithCapacity:size];

    for (int i = 0; i < size; i++) {
        [result addObject:[self fieldTypeAtIndex:i]];
    }

    return [NSArray arrayWithArray:result];
}

- (HLDateTimeField*)fieldAtIndex:(NSInteger)index {
    return [self fieldAtIndex:index chronology:[self chronology]];
}

- (NSArray*)fields {
    NSInteger size = [self size];
    NSMutableArray* result = [NSMutableArray arrayWithCapacity:size];
    for (int i = 0; i < size; i++) {
        [result addObject:[self fieldAtIndex:i]];
    }

    return [NSArray arrayWithArray:result];
}

- (NSArray*)values {
    NSInteger size = [self size];
    NSMutableArray* result = [NSMutableArray arrayWithCapacity:size];
    for (int i = 0; i < size; i++) {
        [result addObject:[NSNumber numberWithInteger:[self valueAtIndex:i]]];
    }
    
    return [NSArray arrayWithArray:result];
}

//-----------------------------------------------------------------------
- (NSInteger)get:(HLDateTimeFieldType*)type {
    return [self valueAtIndex:[self _indexOfSupported:type]];
}

- (BOOL)isSupported:(HLDateTimeFieldType*)type {
    return ([self indexOf:type] != -1);
}

- (NSInteger)indexOf:(HLDateTimeFieldType*)type {
    NSInteger size = [self size];
    for (int i = 0, isize = size; i < isize; i++) {
        if ([self fieldTypeAtIndex:i] == type) {
            return i;
        }
    }

    return -1;
}

- (NSInteger)_indexOfDateTimeFieldTypeSupported:(HLDateTimeFieldType*)type {
    NSInteger index = [self indexOf:type];
    if (index == -1) {
        [NSException raise:NSInvalidArgumentException format:@"Field '%@' is not supported", type];
    }

    return index;
}

- (NSInteger)_indexOf:(HLDurationFieldType*)type {
    NSInteger size = [self size];
    for (int i = 0, isize = size; i < isize; i++) {
        if ([[self fieldTypeAtIndex:i] durationType] == type) {
            return i;
        }
    }

    return -1;
}

- (NSInteger)_indexOfDurationFieldTypeSupported:(HLDurationFieldType*)type {
    NSInteger index = [self _indexOf:type];
    if (index == -1) {
        [NSException raise:NSInvalidArgumentException format:@"Field '%@' is not supported", type];
    }

    return index;
}

//-----------------------------------------------------------------------
- (HLDateTime*)toDateTime:(id<HLReadableInstant>)baseInstant {
    HLChronology* chrono = [HLDateTimeUtils instantChronology:baseInstant];
    NSInteger instantMillis = [HLDateTimeUtils instantMillis:baseInstant];
    NSInteger resolved = [chrono set:self millis:instantMillis];
    return [[[HLDateTime alloc] initWithMillis:resolved chronology:chrono] autorelease];
}

//-----------------------------------------------------------------------
- (BOOL)isEqual:(id)partial {
    if (self == partial) {
        return YES;
    }
    if (![partial conformsToProtocol:@protocol(HLReadablePartial)]) {
        return NO;
    }
    id<HLReadablePartial> other = (id<HLReadablePartial>) partial;
    if ([self size] != [other size]) {
        return NO;
    }
    for (int i = 0, isize = [self size]; i < isize; i++) {
        if ([self valueAtIndex:i] != [other valueAtIndex:i] || [self fieldTypeAtIndex:i] != [other fieldTypeAtIndex:i]) {
            return NO;
        }
    }

    return [HLFieldUtils isObject:[self chronology] equalToObject:[other chronology]];
}

- (NSInteger)hashCode {
    NSInteger total = 157;
    for (int i = 0, isize = [self size]; i < isize; i++) {
        total = 23 * total + [self valueAtIndex:i];
        total = 23 * total + [[self fieldTypeAtIndex:i] hashCode];
    }
    total += [[self chronology] hashCode];
    
    return total;
}

//-----------------------------------------------------------------------
- (NSComparisonResult)compareTo:(id<HLReadablePartial>)other {
    if (self == other) {
        return NSOrderedSame;
    }
    if ([self size] != [other size]) {
        [NSException raise:@"TODO" format:@"ReadablePartial objects must have matching field types"];
    }
    for (int i = 0, isize = [self size]; i < isize; i++) {
        if ([self fieldTypeAtIndex:i] != [other fieldTypeAtIndex:i]) {
            [NSException raise:@"TODO" format:@"ReadablePartial objects must have matching field types"];
        }
    }
    // fields are ordered largest first
    for (int i = 0, isize = [self size]; i < isize; i++) {
        if ([self valueAtIndex:i] > [other valueAtIndex:i]) {
            return NSOrderedAscending;
        }
        if ([self valueAtIndex:i] < [other valueAtIndex:i]) {
            return NSOrderedDescending;
        }
    }
    return NSOrderedSame;
}

- (BOOL)isAfter:(id<HLReadablePartial>)partial {
    if (partial == nil) {
        [NSException raise:NSInvalidArgumentException format:@"Partial cannot be null"];
    }

    return [self compareTo:partial] == NSOrderedAscending;
}

- (BOOL)isBefore:(id<HLReadablePartial>)partial {
    if (partial == nil) {
        [NSException raise:NSInvalidArgumentException format:@"Partial cannot be null"];
    }

    return [self compareTo:partial] == NSOrderedDescending;
}

- (BOOL)isEqualToPartial:(id<HLReadablePartial>)partial {
    if (partial == nil) {
        [NSException raise:NSInvalidArgumentException format:@"Partial cannot be null"];
    }

    return [self compareTo:partial] == NSOrderedSame;
}

//-----------------------------------------------------------------------
- (NSString*)stringWithFormatter:(HLDateTimeFormatter *)formatter {
    if (formatter == nil) {
        return [self description];
    }
    
    return [formatter print:self];
}

@end
