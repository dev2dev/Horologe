/*
 * AbstractInstant.m
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

#import "HLAbstractInstant.h"

#import "HLChronology.h"


@implementation HLAbstractInstant

- (id)_init {
    self = [super init];
    if(self) {
        
    }
    
    return self;
}

    //-----------------------------------------------------------------------
- (HLDateTimeZone*)dateTimeZone {
    return [[self chronology] dateTimeZone];
    }

- (NSInteger)get:(HLDateTimeFieldType*)type) {
        if(type == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                        format:@"The DateTimeFieldType must not be nil"];
        }
    return [[type field:[self chronology]] get:[self millis]];
    }

- (BOOL)isSupported:(HLDateTimeFieldType*)type {
        if (type == nil) {
            return NO;
        }
    return [[type field:[self chronology]] isSupported];
    }

- (NSInteger)getField:(HLDateTimeField*)field {
        if(field == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                        format:@"The DateTimeField must not be nil"];
        }
        return field.get(getMillis());
    }

    //-----------------------------------------------------------------------
    public Instant toInstant {
        return new Instant(getMillis());
    }

    public DateTime toDateTime {
        return new DateTime(getMillis(), getZone());
    }

    public DateTime toDateTimeISO {
        return new DateTime(getMillis(), ISOChronology.getInstance(getZone()));
    }

    public DateTime toDateTime:(HLDateTimeZone*)zone) {
        Chronology chrono = DateTimeUtils.getChronology(getChronology());
        chrono = chrono.withZone(zone);
        return new DateTime(getMillis(), chrono);
    }

    public DateTime toDateTime:(HLChronology*)chronology) {
        return new DateTime(getMillis(), chronology);
    }

    public MutableDateTime toMutableDateTime {
        return new MutableDateTime(getMillis(), getZone());
    }

    public MutableDateTime toMutableDateTimeISO {
        return new MutableDateTime(getMillis(), ISOChronology.getInstance(getZone()));
    }

    public MutableDateTime toMutableDateTime:(HLDateTimeZone*)zone) {
        Chronology chrono = DateTimeUtils.getChronology(getChronology());
        chrono = chrono.withZone(zone);
        return new MutableDateTime(getMillis(), chrono);
    }

    public MutableDateTime toMutableDateTime:(HLChronology*)chronology) {
        return new MutableDateTime(getMillis(), chronology);
    }

    //-----------------------------------------------------------------------
    public Date toDate {
        return new Date(getMillis());
    }

    //-----------------------------------------------------------------------
    - (BOOL)equals:(id)readableInstant) {
        // must be to fulfil ReadableInstant contract
        if (this == readableInstant) {
            return true;
        }
        if (readableInstant instanceof ReadableInstant == false) {
            return false;
        }
        id<HLReadableInstant> otherInstant = (id<HLReadableInstant>)readableInstant;
        return
            getMillis() == otherInstant.getMillis() &&
            FieldUtils.equals(getChronology(), otherInstant.getChronology());
    }

    - (NSUInteger)hash {
        // must be to fulfil ReadableInstant contract
        return
            ((NSInteger) ([self millis] ^ ([self millis] >>> 32))) +
            ([[self chronology] hash]);
    }

    - (NSComparisonResult)compare:(id)instant {
        if (self == instant) {
            return NSOrderedSame;
        }
        
        id<HLReadableInstant> otherInstant = (id<HLReadableInstant>)instant;
        
NSInteger otherMillis = [otherInstant millis];
NSInteger thisMillis = [self millis];
        
        // cannot do (thisMillis - otherMillis) as can overflow
        if (thisMillis == otherMillis) {
            return NSOrderedSame;
        }
        if (thisMillis < otherMillis) {
            return NSOrderedDescending;
        } else {
            return NSOrderedAscending;
        }
    }

    //-----------------------------------------------------------------------
    - (BOOL)isAfter:(NSInteger)instant {
        return ([self millis] > instant);
    }

    - (BOOL)isAfterNow {
        return [self isAfter:[HLDateTimeUtils currentTimeMillis]];
    }

    - (BOOL)isAfter:(id<HLReadableInstant>)instant {
        NSInteger instantMillis = [HLDateTimeUtils instantMillis:instant];
        return [self isAfter:instantMillis];
    }

    //-----------------------------------------------------------------------
    - (BOOL)isBefore:(NSInteger)instant {
        return ([self millis] < instant);
    }

    - (BOOL)isBeforeNow {
        return [self isBefore:[HLDateTimeUtils currentTimeMillis]];
    }

    - (BOOL)isBefore:(id<HLReadableInstant>)instant {
        NSInteger instantMillis = [HLDateTimeUtils instantMillis:instant];
        return [self isBefore:instantMillis];
    }

    //-----------------------------------------------------------------------
    - (BOOL)isEqual:(NSInteger)instant {
        return ([self millis] == instant);
    }

    - (BOOL)isEqualNow {
        return [self isEqual:[HLDateTimeUtils currentTimeMillis]];
    }

    - (BOOL)isEqual:(id<HLReadableInstant>)instant {
        NSInteger instantMillis = [HLDateTimeUtils instantMillis:instant];
        return [self isEqual:instantMillis];
    }

    //-----------------------------------------------------------------------
    - (NSString*)description {
        return [[HLISODateTimeFormat dateTime] print:self];
    }

    //-----------------------------------------------------------------------
- (NSString*)stringWithFormatter:(HLDateTimeFormatter*)formatter {
        if (formatter == nil) {
            return [self description];
        }
    
    return [formatter print:self];
    }

@end
