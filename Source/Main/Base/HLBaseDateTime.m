/*
 * HLBaseDateTime.m
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

#import "Base/HLBaseDateTime.h"
#import "Core/HLDateTimeUtils.h"
#import "Chrono/HLISOChronology.h"
#import "Convert/HLConverterManager.h"
#import "Core/HLChronology.h"
#import "Convert/HLInstantConverter.h"


@class HLDateTimeZone;

@implementation HLBaseDateTime

//-----------------------------------------------------------------------
- (id)init {
    
    if(self = [self initWithInstant:[HLDateTimeUtils currentTimeMillis] 
                         chronology:[HLISOChronology instance]]) {
        
    }
    
    return self;
}

- (id)initWithDateTimeZone:(HLDateTimeZone*)zone {
    
    if(self = [self initWithInstant:[HLDateTimeUtils currentTimeMillis]
                         chronology:[HLISOChronology instance:zone]]) {
        
    }
    
    return self;
}

- (id)initWithChronology:(HLChronology*)chronology {
    
    if(self = [self initWithInstant:[HLDateTimeUtils currentTimeMillis]
                         chronology:chronology]) {
        
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (id)initWithInstant:(NSInteger)instant {
    
    if(self = [self initWithInstant:instant
                         chronology:[HLISOChronology instance]]) {
        
    }
    
    return self;
}

- (id)initWithInstant:(NSInteger)instant 
         dateTimeZone:(HLDateTimeZone*)zone {
    
    if(self = [self initWithInstant:instant
                         chronology:[HLISOChronology instance:zone]]) {
        
    }
    
    return self;
}

- (id)initWithInstant:(NSInteger)instant 
           chronology:(HLChronology*)chronology {
    
    if(self = [super init]) {
        iChronology = [[self _checkChronology:chronology] retain];
        iMillis = [self _checkInstant:instant 
                           chronology:iChronology];
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (id)initWithObject:(id)instant
        dateTimeZone:(HLDateTimeZone*)zone {
    
    if(self = [super init]) {
        HLInstantConverter* converter = [[HLConverterManager instance] instantConverter:instant];
        HLChronology* chrono = [self _checkChronology:[converter chronologyWithInstant:instant 
                                                                          dateTimeZone:zone]];
        iChronology = [chrono retain];
        iMillis = [self _checkInstant:[converter instantMillis:instant 
                                                    chronology:chrono] chronology:chrono];        
    }
    
    return self;
}

- (id)initWithObject:(id)instant 
          chronology:(HLChronology*)chronology {
    
    if(self = [super init]) {
        
        HLInstantConverter* converter = [[HLConverterManager instance] instantConverter:instant];
        iChronology = [[self _checkChronology:[converter chronology:instant
                                                         chronology:chronology]] retain];
        iMillis = [self _checkInstant:[converter instantMillis:instant
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
    
    if(self = [self initWithYear:year 
                           month:monthOfYear 
                             day:dayOfMonth 
                            hour:hourOfDay
                          minute:minuteOfHour 
                          second:secondOfMinute 
                          millis:millisOfSecond 
                      chronology:[HLISOChronology instance]]) {
        
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
      dateTimeZone:(HLDateTimeZone*)zone {
    
    if(self = [self initWithYear:year 
                           month:monthOfYear
                             day:dayOfMonth
                            hour:hourOfDay 
                          minute:minuteOfHour
                          second:secondOfMinute
                          millis:millisOfSecond
                      chronology:[HLISOChronology instance:zone]]) {
        
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
    
    if(self = [super init]) {
        iChronology = [[self _checkChronology:chronology] retain];
        NSInteger instant = [iChronology dateTimeMillisYear:year
                                                      month:monthOfYear
                                                        day:dayOfMonth
                                                       hour:hourOfDay 
                                                     minute:minuteOfHour 
                                                     second:secondOfMinute 
                                                     millis:millisOfSecond];
        iMillis = [self _checkInstant:instant
                           chronology:iChronology];
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (HLChronology*)_checkChronology:(HLChronology*)chronology {
    return [HLDateTimeUtils chronology:chronology];
}

- (NSInteger)_checkInstant:(NSInteger)instant
                chronology:(HLChronology*)chronology {
    return instant;
}

//-----------------------------------------------------------------------
- (NSInteger)millis {
    return iMillis;
}

- (HLChronology*)chronology {
    return iChronology;
}

//-----------------------------------------------------------------------
- (void)_setMillis:(NSInteger)instant {
    iMillis = [self _checkInstant:instant 
                      chronology:iChronology];
}

- (void)_setChronology:(HLChronology*)chronology {
    iChronology = [[self _checkChronology:chronology] retain];
}

- (void)dealloc {
    [iChronology release];
    
    [super dealloc];
}

@end
