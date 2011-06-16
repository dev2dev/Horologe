/*
 * HLDateMidnight.m
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
 
#import "HLDateMidnight.h"


@implementation HLProperty

@end


//-----------------------------------------------------------------------
@implementation HLDateMidnight

// Constructors
//-----------------------------------------------------------------------
- (id)init {
    if(self = [super init]) {
        
    }
    
    return self;
}

- (id)initWithDateTimeZone:(HLDateTimeZone*)zone {
    if(self = [super initWithDateTimeZone:zone]) {
        
    }
    
    return self;
}

- (id)initWithChronology:(HLChronology*)chronology {
    if(self = [super initWithChronology:chronology]) {
        
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (id)initWithInstant:(NSInteger)instant {
    if(self = [super initWithInstant:instant]) {
        
    }
    
    return self;
}

- (id)initWithInstant:(NSInteger)instant
                 zone:(HLDateTimeZone*)zone {
    if(self = [super initWithInstant:instant zone:zone]) {
        
    }
    
    return self;
}

- (id)initWithInstant:(NSInteger)instant
           chronology:(HLChronology*)chronology {
    if(self = [super initWithInstant:instant chronology:chronology]) {
        
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (id)initWithObject:(id)instant {
    if(self = [super initWithObject:instant chronology:nil]) {
        
    }
    
    return self;
}

- (id)initWithObject:(id)instant
                zone:(HLDateTimeZone*)zone {
    if(self = [super initWithObject:instant zone:zone]) {
        
    }
    
    return self;
}

- (id)initWithObject:(id)instant
          chronology:(HLChronology*)chronology {
    if(self = [super initWithObject:instant 
                         chronology:[HLDateTimeUtils chronology:chronology]]) {
        
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (id)initWithYear:(NSInteger)year
monthOfYear:(NSInteger)monthOfYear
dayOfMonth:(NSInteger)dayOfMonth {
    if(self = [super _initWithYear:year
                      monthOfYear:monthOfYear
                       dayOfMonth:dayOfMonth
                         hourOfDay:0
                      minuteOfHour:0
                    secondOfMinute:0
                    millisOfSecond:0]) {
        
    }
    
    return self;
}

- (id)initWithYear:(NSInteger)year 
                  monthOfYear:(NSInteger)monthOfYear 
                  dayOfMOnth:(NSInteger)dayOfMonth 
zone:(HLDateTimeZone*)zone {
    if(self = [super _initWithYear:year
                       monthOfYear:monthOfYear
                        dayOfMonth:dayOfMonth
                         hourOfDay:0
                      minuteOfHour:0
                    secondOfMinute:0
                    millisOfSecond:0
                              zone:zone]) {
        
    }
    
    return self;
}

- (id)initWithYear:(NSInteger)year 
                  monthOfYear:(NSInteger)monthOfYear 
        dayOfMOnth:(NSInteger)dayOfMonth 
        chronology:(HLChronology*)chronology {
    if(self = [super _initWithYear:year
                       monthOfYear:monthOfYear
                        dayOfMonth:dayOfMonth
                         hourOfDay:0
                      minuteOfHour:0
                    secondOfMinute:0
                    millisOfSecond:0
                        chronology:chronology]) {
        
    }
    
    return self;
}

- (NSInteger)_checkInstant:(NSInteger)instant
                chronology:(HLChronology*)chronology {
    return [[chronology dayOfMonth] roundFloor:instant];
}

//-----------------------------------------------------------------------
- (HLDateMidnight*)withMillis:(NSInteger)newMillis {
    HLChronology* chrono = [self chronology];
    newMillis = [self _checkInstant:newMillis chronology:chrono];
    return (newMillis == [self millis] ? self : [[[HLDateMidnight alloc] initWithMillis:newMillis
                                                                             chronology:chrono] autorelease]);
}

            - (HLDateMidnight*)withChronology:(HLChronology*)newChronology {
                return (newChronology == [self chronology] ? self : [[[HLDateMidnight alloc] initWithMillis:[self millis] chronology:newChronology] autorelease]);
}

- (HLDateMidnight*)withZoneRetainFields:(HLDateTimeZone*)newZone {
    newZone = [HLDateTimeUtils zone:newZone];
    HLDateTimeZone* originalZone = [HLDateTimeUtils zone:[self zone]];
    if (newZone == originalZone) {
        return self;
    }
    
    NSInteger millis = [originalZone millisKeepLocal:newZone 
                                              millis:[self millis]];
    return [[[HLDateMidnight alloc] initWithMillis:millis 
                                        chronology:[[self chronology] withZone:newZone]] autorelease];
}

//-----------------------------------------------------------------------
- (HLDateMidnight*)withFields:(id<HLReadablePartial>)partial {
    if (partial == nil) {
        return self;
    }
    return [self withMillis:[[self chronology] set:partial instant:[self millis]]];
}

- (HLDateMidnight*)withField(DateTimeFieldType fieldType :(NSInteger)value) {
    if (fieldType == null) {
        throw new IllegalArgumentException("Field must not be null");
    }
    long instant = fieldType.getField([self chronology]).set([self millis], value);
    return withMillis(instant);
}

- (HLDateMidnight*)withFieldAdded(DurationFieldType fieldType :(NSInteger)amount) {
    if (fieldType == null) {
        throw new IllegalArgumentException("Field must not be null");
    }
    if (amount == 0) {
        return this;
    }
    long instant = fieldType.getField([self chronology]).add([self millis], amount);
    return withMillis(instant);
}

//-----------------------------------------------------------------------
- (HLDateMidnight*)withDurationAdded:(NSInteger)durationToAdd :(NSInteger)scalar) {
    if (durationToAdd == 0 || scalar == 0) {
        return this;
    }
    long instant = [self chronology].add([self millis], durationToAdd, scalar);
    return withMillis(instant);
}

- (HLDateMidnight*)withDurationAdded(ReadableDuration durationToAdd :(NSInteger)scalar) {
    if (durationToAdd == null || scalar == 0) {
        return this;
    }
    return withDurationAdded(durationToAdd.[self millis], scalar);
}

- (HLDateMidnight*)withPeriodAdded(ReadablePeriod period :(NSInteger)scalar) {
    if (period == null || scalar == 0) {
        return this;
    }
    long instant = [self chronology].add(period, [self millis], scalar);
    return withMillis(instant);
}

//-----------------------------------------------------------------------
- (HLDateMidnight*)plus:(NSInteger)duration) {
    return withDurationAdded(duration, 1);
}

- (HLDateMidnight*)plus(ReadableDuration duration) {
    return withDurationAdded(duration, 1);
}

- (HLDateMidnight*)plus(ReadablePeriod period) {
    return withPeriodAdded(period, 1);
}

//-----------------------------------------------------------------------
- (HLDateMidnight*)plusYears:(NSInteger)years) {
    if (years == 0) {
        return this;
    }
    long instant = [self chronology].years().add([self millis], years);
    return withMillis(instant);
}

- (HLDateMidnight*)plusMonths:(NSInteger)months) {
    if (months == 0) {
        return this;
    }
    long instant = [self chronology].months().add([self millis], months);
    return withMillis(instant);
}

- (HLDateMidnight*)plusWeeks:(NSInteger)weeks) {
    if (weeks == 0) {
        return this;
    }
    long instant = [self chronology].weeks().add([self millis], weeks);
    return withMillis(instant);
}

- (HLDateMidnight*)plusDays:(NSInteger)days) {
    if (days == 0) {
        return this;
    }
    long instant = [self chronology].days().add([self millis], days);
    return withMillis(instant);
}

//-----------------------------------------------------------------------
- (HLDateMidnight*)minusDuration:(NSInteger)duration) {
    return withDurationAdded(duration, -1);
}

- (HLDateMidnight*)minusReadableDuration:(id<HLReadableDuration>)duration {
    return [self withDurationAdded:duration -1];
}

- (HLDateMidnight*)minus(ReadablePeriod period) {
    return withPeriodAdded(period, -1);
}

//-----------------------------------------------------------------------
- (HLDateMidnight*)minusYears:(NSInteger)years) {
    if (years == 0) {
        return this;
    }
    long instant = [self chronology].years().subtract([self millis], years);
    return withMillis(instant);
}

- (HLDateMidnight*)minusMonths:(NSInteger)months) {
    if (months == 0) {
        return this;
    }
    long instant = [self chronology].months().subtract([self millis], months);
    return withMillis(instant);
}

- (HLDateMidnight*)minusWeeks:(NSInteger)weeks) {
    if (weeks == 0) {
        return this;
    }
    long instant = [self chronology].weeks().subtract([self millis], weeks);
    return withMillis(instant);
}

- (HLDateMidnight*)minusDays:(NSInteger)days) {
    if (days == 0) {
        return this;
    }
    long instant = [self chronology].days().subtract([self millis], days);
    return withMillis(instant);
}

//-----------------------------------------------------------------------
- (HLProperty*)property(DateTimeFieldType type) {
    if (type == nil) {
        [NSException raise:NSInvalidArgumentException format:@"The DateTimeFieldType must not be nil."];
    }
    HLDateTimeField* field = [type field:[self chronology]];
    if ([field isSupported] == NO) {
        [NSException raise:NSInvalidArgumentException format:@"Field '%@' is not supported", type];
    }
    return [[[HLProperty alloc] init:self field:field] autorelease];
}

//-----------------------------------------------------------------------
- (HLYearMonthDay*)toYearMonthDay {
    return [[[HLYearMonthDay alloc] initWithMillis:[self millis] chronology:[self chronology]] autorelease];
}

- (HLLocalDate*)toLocalDate {
    return [[[HLLocalDate alloc] initWithMillis:[self millis] chronology:[self chronology]] autorelease];
}

- (HLInterval*)toInterval {
    HLChronology* chrono = [self chronology];
    NSInteger start = [self millis];
    NSInteger end = [[[HLDurationFieldType days] field:chrono] add:start 1];
    return new Interval(start, end, chrono);
}

//-----------------------------------------------------------------------
- (HLDateMidnight*)withEra:(NSInteger)era {
    return [self withMillis:[[[self chronology] era] set:[self millis] era:era]];
}

- (HLDateMidnight*)withCenturyOfEra:(NSInteger)centuryOfEra {
    return [self withMillis:[[[self chronology] centuryOfEra] set:[self millis] centuryOfEra:centuryOfEra]];
}

- (HLDateMidnight*)withYearOfEra:(NSInteger)yearOfEra {
    return [self withMillis:[[[self chronology] yearOfEra] set:[self millis] yearOfEra:yearOfEra]];
}

- (HLDateMidnight*)withYearOfCentury:(NSInteger)yearOfCentury {
    return [self withMillis:[[[self chronology] yearOfCentury] set:[self millis] yearOfCentury:yearOfCentury]];
}

- (HLDateMidnight*)withYear:(NSInteger)year {
    return [self withMillis:[[[self chronology] year] set:[self millis] year:year]];
}

- (HLDateMidnight*)withWeekyear:(NSInteger)weekyear {
    return [self withMillis:[[[self chronology] weekyear] set:[self millis] weekyear:weekyear]];
}

- (HLDateMidnight*)withMonthOfYear:(NSInteger)monthOfYear {
    return [self withMillis:[[[self chronology] monthOfYear] set:[self millis] monthOfYear:monthOfYear]];
}

- (HLDateMidnight*)withWeekOfWeekyear:(NSInteger)weekOfWeekyear {
    return [self withMillis:[[[self chronology] weekOfWeekyear] set:[self millis] weekOfWeekyear:weekOfWeekyear]];
}

- (HLDateMidnight*)withDayOfYear:(NSInteger)dayOfYear {
    return [self withMillis:[[[self chronology] dayOfYear] set:[self millis] dayOfYear:dayOfYear]];
}

- (HLDateMidnight*)withDayOfMonth:(NSInteger)dayOfMonth {
    return [self withMillis:[[[self chronology] dayOfMonth] set:[self millis] dayOfMonth:dayOfMonth]];
}

- (HLDateMidnight*)withDayOfWeek:(NSInteger)dayOfWeek {
    return [self withMillis:[[[self chronology] dayOfWeek] set:[self millis] dayOfWeek:dayOfWeek]];
}

// Date properties
//-----------------------------------------------------------------------
- (HLProperty*)era {
    return [[[HLProperty alloc] _initWithInstant:self field:[[self chronology] era]] autorelease];
}

- (HLProperty*)centuryOfEra {
    return [[[HLProperty alloc] _initWithInstant:self field:[[self chronology] centuryOfEra]] autorelease];
}

- (HLProperty*)yearOfCentury {
    return [[[HLProperty alloc] _initWithInstant:self field:[[self chronology] yearOfCentury]] autorelease];
}

- (HLProperty*)yearOfEra {
    return [[[HLProperty alloc] _initWithInstant:self field:[[self chronology] yearOfEra]] autorelease];
}

- (HLProperty*)year {
    return [[[HLProperty alloc] _initWithInstant:self field:[[self chronology] year]] autorelease];
}

- (HLProperty*)weekyear {
    return [[[HLProperty alloc] _initWithInstant:self field:[[self chronology] weekyear]] autorelease];
}

- (HLProperty*)monthOfYear {
    return [[[HLProperty alloc] _initWithInstant:self field:[[self chronology] monthOfYear]] autorelease];
}

- (HLProperty*)weekOfWeekyear {
    return [[[HLProperty alloc] _initWithInstant:self field:[[self chronology] weekOfWeekyear]] autorelease];
}

- (HLProperty*)dayOfYear {
    return [[[HLProperty alloc] _initWithInstant:self field:[[self chronology] dayOfYear]] autorelease];
}

- (HLProperty*)dayOfMonth {
    return [[[HLProperty alloc] _initWithInstant:self field:[[self chronology] dayOfMonth]] autorelease];
}

- (HLProperty*)dayOfWeek {
    return [[[HLProperty alloc] _initWithInstant:self field:[[self chronology] dayOfWeek]] autorelease];
}

@end
