/*
 * BaseDateTime.m
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

#import "HLBaseDateTime.h"

#import "HLDateTimeUtils.h"
#import "HLISOChronology.h"
#import "HLChronology.h"
#import "HLInstantConverter.h"
#import "HLConverterManager.h"


/**
 * BaseDateTime is an abstract implementation of ReadableDateTime that stores
 * data in <code>long</code> and <code>Chronology</code> fields.
 * <p>
 * This class should generally not be used directly by API users.
 * The {@link ReadableDateTime} interface should be used when different 
 * kinds of date/time objects are to be referenced.
 * <p>
 * BaseDateTime subclasses may be mutable and not thread-safe.
 *
 * @author Stephen Colebourne
 * @author Kandarp Shah
 * @author Brian S O'Neill
 * @since 1.0
 */
@implementation HLBaseDateTime

//-----------------------------------------------------------------------
- (id)init {
    self = [self initWithInstant:[HLDateTimeUtils currentTimeMillis]
                      chronology:[[[HLISOChronology alloc] init] autorelease]];
    if(self) {
        
    }
    
    return self;
}

- (id)initWithDateTimeZone:(HLDateTimeZone *)zone {
    self = [self initWithInstant:[HLDateTimeUtils currentTimeMillis]
                      chronology:[[[HLISOChronology alloc] initWithDateTimeZone:zone] autorelease]];
    if(self) {
        
    }
    
    return self;
}

- (id)initWithChronology:(HLChronology *)chronology {
    self = [self initWithInstant:[HLDateTimeUtils currentTimeMillis]
                      chronology:chronology];
    if(self) {
        
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (id)initWithInstant:(NSInteger)instant {
    self = [self initWithInstant:instant
                      chronology:[[[HLISOChronology alloc] init] autorelease]];
    if(self) {
        
    }
    
    return self;
}

- (id)initWithInstant:(id)instant 
                 zone:(HLDateTimeZone *)zone {
    self = [self initWithInstant:instant
                      chronology:[[[HLISOChronology alloc] initWithDateTimeZone:zone] autorelease]];
    if(self) {
        
    }
    
    return self;
}

- (id)initWithInstant:(id)instant 
           chronology:(HLChronology*)chronology {
    self = [super init];
    if(self) {
        _iChronology = [[self _checkChronology:chronology] retain];
        _iMillis = [self _checkInstant:instant
                            chronology:_iChronology];
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (id)initWithInstant:(id)instant 
                 zone:(HLDateTimeZone*)zone {
    self = [super init];
    if(self) {
        HLInstantConverter* converter = [[HLConverterManager instance] instantConverter:instant];
        HLChronology* chrono = [[self _checkChronology:[converter chronologyFromInstant:instant
                                                                                   zone:zone]] retain];
        _iChronology = chrono;
        _iMillis = [self _checkInstant:[converter instantMillis:instant
                                                     chronology:chrono]
                            chronology:chrono];
    }
    
    return self;
}

- (id)initWithInstantObject:(id)instant
                 chronology:(HLChronology*)chronology {
    self = [super init];
    if(self) {
        HLInstantConverter* converter = [[HLConverterManager instance] instantConverter:instant];
        _iChronology = [[self _checkChronology:[converter chronologyFromInstant:instant
                                                                     chronology:chronology]] retain];
        _iMillis = [self _checkInstant:[converter instantMillis:instant
                                                     chronology:chronology]
                            chronology:iChronology];
        
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (id)initWithYear:(NSInteger)year
             month:(NSInteger)monthOfYear
               day:(NSInteger)dayOfMonth 
              hour:(NSInteger)hourOfDay 
            minute:(NSInteger)minuteOfHour 
            second:(NSInteger)secondOfMinute
            millis:(NSInteger)millisOfSecond {
    self = [self initWithYear:year
                        month:monthOfYear
                          day:dayOfMonth
                         hour:hourOfDay
                       minute:minuteOfHour
                       second:secondOfMinute
                       millis:millisOfSecond
                   chronology:[[[HLISOChronology alloc] init] autorelease]];
    if(self) {
        
    }
    
    return self;
}

- (id)initWithYear:(NSInteger)year 
             month:(NSInteger)monthOfYear 
               day:(NSInteger)dayOfMonth 
              hour:(NSInteger)hourOfDay
            minute:(NSInteger)minuteOfHour
            second:(NSInteger)secondOfMinute 
            millis:(NSInteger)millisOfSecond 
              zone:(HLDateTimeZone*)dateTimeZone {
    self = [self initWithYear:year
                        month:monthOfYear
                          day:dayOfMonth
                         hour:hourOfDay
                       minute:minuteOfHour
                       second:secondOfMinute
                       millis:millisOfSecond
                   chronology:[[[HLISOChronology alloc] initWithDateTimeZone:zone] autorelease]];
    if(self) {
        
    }
    
    return self;
}

- (id)initWithYear:(NSInteger)year 
             month:(NSInteger)monthOfYear 
               day:(NSInteger)dayOfMonth 
              hour:(NSInteger)hourOfDay 
            minute:(NSInteger)minuteOfHour 
            second:(NSInteger)secondOfMinute
            millis:(NSInteger)millisOfSecond
        chronology:(HLChronology*)chronology {
    self = [super init];
    if(self) {
        _iChronology = [[self _checkChronology:chronology] retain];
        NSInteger instant = [_iChronology dateTimeMillisWithYear:year
                                                           month:monthOfYear
                                                             day:dayOfMonth
                                                            hour:hourOfDay
                                                          minute:minuteOfHour
                                                          second:secondOfMinute
                                                          millis:millisOfSecond];
        _iMillis = [self _checkInstant:instant
                            chronology:_iChronology];
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (HLChronology*)checkChronology:(HLChronology*)chronology {
    return [HLDateTimeUtils chronology:chronology];
}

- (NSInteger)checkInstant:(NSInteger)instant
                chronology:(HLChronology*)chronology {
    return instant;
}

//-----------------------------------------------------------------------
- (NSInteger)millis {
    return _iMillis;
}

- (HLChronology*)chronology {
    return _iChronology;
}

//-----------------------------------------------------------------------
- (void)setMillis:(NSInteger)instant {
    
    [self willChangeValueForKey:@"millis"];
    _iMillis = [self _checkInstant:instant
                        chronology:_iChronology];
    [self didChangeValueForKey:@"millis"];
}

- (void)setChronology:(HLChronology*)chronology {
    
    [self willChangeValueForKey:@"chronology"];
    [_iChronology release], _iChronology = nil;
    _iChronology = [[self _checkChronology:chronology] retain];
    [self didChangeValueForKey:@"chronology"];
}

@end
