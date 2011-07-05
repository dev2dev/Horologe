/*
 * AbstractPartial.m
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

#import "HLAbstractPartial.h"

#import "HLConstants.h"
#import "HLDateTimeFieldType.h"
#import "HLDateTimeUtils.h"


@implementation HLAbstractPartial

//-----------------------------------------------------------------------
- (id)init {
    self = [super init];
    if(self) {
        
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (HLDateTimeField*)fieldAtIndex:(NSInteger)index
                  withChronology:(HLChronology*)chrono {
    [NSException raise:HL_UNIMPLEMENTED_EXCEPTION
                format:@"Attempt to call %s on abstract class", _cmd];
}

//-----------------------------------------------------------------------
- (HLDateTimeFieldType*)fieldTypeAtIndex:(NSInteger)index {
    return [[self fieldAtIndex:index
                 withChronology:[self chronology]] type];
}

- (NSArray*)fieldTypes {
    NSMutableArray* result = [NSMutableArray array];
    for(NSInteger i = 0; i < [self size]; i++) {
        [result addObject:[self fieldTypeAtIndex:i]];
    }
    
    return result;
}

- (HLDateTimeField*)fieldAtIndex:(NSInteger)index {
    return [self fieldAtIndex:index 
               withChronology:[self chronology]];
}

- (NSArray*)fields {
    NSMutableArray* result = [NSMutableArray array];
    
    for(NSInteger i = 0; i < [self size]; i++) {
        [result addObject:[self fieldAtIndex:i]];
    }
    
    return result;
}

- (NSArray*)values {
    NSMutableArray* result = [NSMutableArray array];
    
    for(NSInteger i = 0; i < [self size]; i++) {
        [result addObject:[NSNumber numberWithInteger:[self valueAtIndex:i]]];
    }
    
    return result;
}

//-----------------------------------------------------------------------
/**
 * Get the value of one of the fields of a datetime.
 * <p>
 * The field specified must be one of those that is supported by the partial.
 *
 * @param type  a DateTimeFieldType instance that is supported by this partial
 * @return the value of that field
 * @throws IllegalArgumentException if the field is nil or not supported
 */
- (NSInteger)valueOfFieldType:(HLDateTimeFieldType *)type {
    return [self valueAtIndex:[self indexOfSupportedDateTime:type]];
}

/**
 * Checks whether the field specified is supported by this partial.
 *
 * @param type  the type to check, may be nil which returns false
 * @return true if the field is supported
 */
- (BOOL)isSupported:(HLDateTimeFieldType*)type {
    return ([self indexOf:type] != -1);
}

/**
 * Gets the index of the specified field, or -1 if the field is unsupported.
 *
 * @param type  the type to check, may be nil which returns -1
 * @return the index of the field, -1 if unsupported
 */
- (NSInteger)indexOf:(HLDateTimeFieldType*)type) {
    for(NSInteger i = 0, isize = [self size]; i < isize; i++) {
        if ([self fieldTypeAtIndex:i] == type) {
            return i;
        }
    }
    
    return -1;
}

/**
 * Gets the index of the specified field, throwing an exception if the
 * field is unsupported.
 *
 * @param type  the type to check, not nil
 * @return the index of the field
 * @throws IllegalArgumentException if the field is nil or not supported
 */
- (NSInteger)indexOfSupported:(HLDateTimeFieldType*)type) {
    NSInteger index = [self indexOfFieldType:type];
    if (index == -1) {
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"Field '%@' is not supported", type];
    }
    
    return index;
}

/**
 * Gets the index of the first fields to have the specified duration,
 * or -1 if the field is unsupported.
 *
 * @param type  the type to check, may be nil which returns -1
 * @return the index of the field, -1 if unsupported
 */
- (NSInteger)indexOf:(HLDurationFieldType*)type) {
    for(NSInteger i = 0, isize = [self size]; i < isize; i++) {
        if ([[self fieldTypeAtIndex:i] durationType] == type) {
            return i;
        }
    }
    
    return -1;
}

/**
 * Gets the index of the first fields to have the specified duration,
 * throwing an exception if the field is unsupported.
 *
 * @param type  the type to check, not nil
 * @return the index of the field
 * @throws IllegalArgumentException if the field is nil or not supported
 */
- (NSInteger)indexOfSupported:(HLDurationFieldType*)type) {
    int index = [self _indexOf:type];
    if (index == -1) {
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"Field '%@' is not supported", type];
    }
    
    return index;
}

//-----------------------------------------------------------------------
/**
 * Resolves this partial against another complete instant to create a new
 * full instant. The combination is performed using the chronology of the
 * specified instant.
 * <p>
 * For example, if this partial represents a time, then the result of this
 * method will be the datetime from the specified base instant plus the
 * time from this partial.
 *
 * @param baseInstant  the instant that provides the missing fields, nil means now
 * @return the combined datetime
 */
- (HLDateTime*)toDateTime:(id<HLReadableInstant>)baseInstant {
    HLChronology* chrono = [HLDateTimeUtils instantChronology:baseInstant];
    NSInteger instantMillis = [HLDateTimeUtils instantMillis:baseInstant];
    NSInteger resolved = [chrono set:self
                              millis:instantMillis];
    return [[[HLDateTime alloc] initWithMillis:[self resolved]
                                    chronology:chrono] autorelease];
}

//-----------------------------------------------------------------------
/**
 * Compares this ReadablePartial with another returning true if the chronology,
 * field types and values are equal.
 *
 * @param partial  an object to check against
 * @return true if fields and values are equal
 */
- (BOOL)equals:(id)partial {
    if (self == partial) {
        return YES;
    }
    if ([partial conformsToProtocol:@protocol(HLReadablePartial)] == NO) {
        return NO;
    }
    id<HLReadablePartial> other = (id<HLReadablePartial>) partial;
    if ([self size] != [other size]) {
        return NO;
    }
    for(NSInteger i = 0, isize = [self size]; i < isize; i++) {
        if ([self valueAtIndex:i] != [other valueAtIndex:i] || 
            [self fieldTypeAtIndex:i] != [other fieldTypeAtIndex:i]) {
            return NO;
        }
    }
    return [HLFieldUtils isChronology:[self chronology]
                    equalToChronology:[other chronology]];
}

/**
 * Gets a hash code for the ReadablePartial that is compatible with the 
 * equals method.
 *
 * @return a suitable hash code
 */
- (NSUInteger)hash {
    int total = 157;
    
    for(NSInteger i = 0, isize = [self size]; i < isize; i++) {
        total = 23 * total + [self valueAtIndex:i];
        total = 23 * total + [[self fieldTypeAtIndex:i] hash];
    }
    
    total += [[self chronology] hash];
    
    return total;
}

//-----------------------------------------------------------------------
- (NSComparisonResult)compare:(id)partial {
    if (self == partial) {
        return NSOrderedSame;
    }
    
    id<HLReadablePartial> other = (id<HLReadablePartial>) partial;
    if([self size] != [other size]) {
        [NSException raise:HL_OBJECT_MISMATCH_EXCEPTION
                    format:@"ReadablePartial objects must have matching field types"];
    }
    
    for(NSInteger i = 0, isize = [self size]; i < isize; i++) {
        if([self fieldTypeAtIndex:i] != [other fieldTypeAtIndex:i]) {
            [NSException raise:HL_OBJECT_MISMATCH_EXCEPTION
                        format:@"ReadablePartial objects must have matching field types"];
        }
    }
    // fields are ordered largest first
    for(NSInteger i = 0, isize = size(); i < isize; i++) {
        if([self valueAtIndex:i] > [other valueAtIndex:i]) {
            return NSOrderedAscending;
        }
        if([self valueAtIndex:i] < [other valueAtIndex:i]) {
            return NSOrderedDescending;
        }
    }
    
    return NSOrderedSame;
}

- (BOOL)isAfter:(id<HLReadablePartial>)partial {
    if (partial == nil) {
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"Partial cannot be nil"];
    }
    
    return [self compare:partial] == NSOrderedAscending;
}

- (BOOL)isBefore:(id<HLReadablePartial>)partial {
    if (partial == nil) {
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"Partial cannot be nil"];
    }
    
    return [self compare:partial] == NSOrderedDescending;
}

- (BOOL)isEqual:(id<HLReadablePartial>)partial {
    if (partial == nil) {
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"Partial cannot be nil"];
    }
    
    return [self compare:partial] == NSOrderedSame;
}

//-----------------------------------------------------------------------
- (NSString*)stringWithFormatter:(HLDateTimeFormatter*)formatter {
    if (formatter == nil) {
        return [self description];
    }
    
    return [formatter print:self];
}

@end
