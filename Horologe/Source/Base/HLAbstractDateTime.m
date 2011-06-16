/*
 * AbstractDateTime.m
 *
 * Horologe
 * Copyright (c) 2011 Pilgrimage Software
 * Copyright 2001-2005 Stephen Colebourne
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

#import "HLAbstractDateTime.h"

#import "HLConstants.h"


@implementation HLAbstractDateTime

- (id)_init {
    self = [super init];
    if(self) {
        // Initialization.        
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (NSInteger)get:(HLDateTimeFieldType*)type {
    if(type == nil) {
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"The DateTimeFieldType must not be nil"];
    }
    
    return [[type field:[self chronology]] get:[self millis]];
}

//-----------------------------------------------------------------------
- (NSInteger)era {
    return [[[self chronology] eraObject] get:[self millis]];
}

- (NSInteger)centuryOfEra {
    return [[[self chronology] centuryOfEraObject] get:[self millis]];
}

- (NSInteger)yearOfEra {
    return [[[self chronology] yearOfEraObject] get:[self millis]];
}

- (NSInteger)yearOfCentury {
    return [[[self chronology] yearOfCenturyObject] get:[self millis]];
}

- (NSInteger)year {
    return [[[self chronology] yearObject] get:[self millis]];
}

- (NSInteger)weekyear {
    return [[[self chronology] weekyearObject] get:[self millis]];
}

- (NSInteger)monthOfYear {
    return [[[self chronology] monthOfYearObject] get:[self millis]];
}

- (NSInteger)weekOfWeekyear {
    return [[[self chronology] weekOfWeekyearObject] get:[self millis]];
}

- (NSInteger)dayOfYear {
    return [[[self chronology] dayOfYearObject] get:[self millis]];
}

- (NSInteger)dayOfMonth {
    return [[[self chronology] dayOfMonthObject] get:[self millis]];
}

- (NSInteger)dayOfWeek {
    return [[[self chronology] dayOfWeekObject] get:[self millis]];
}

//-----------------------------------------------------------------------
- (NSInteger)hourOfDay {
    return [[[self chronology] hourOfDayObject] get:[self millis]];
}

- (NSInteger)minuteOfDay {
    return [[[self chronology] minuteOfDayObject] get:[self millis]];
}

- (NSInteger)minuteOfHour {
    return [[[self chronology] minuteOfHourObject] get:[self millis]];
}

- (NSInteger)secondOfDay {
    return [[[self chronology] secondOfDayObject] get:[self millis]];
}

- (NSInteger)secondOfMinute {
    return [[[self chronology] secondOfMinuteObject] get:[self millis]];
}

- (NSInteger)millisOfDay {
    return [[[self chronology] millisOfDayObject] get:[self millis]];
}

- (NSInteger)millisOfSecond {
    return [[[self chronology] millisOfSecondObject] get:[self millis]];
}

//-----------------------------------------------------------------------
- (NSDate*)calendarDateWithLocale:(NSLocale*)locale {
    if (locale == nil) {
        locale = [NSLocale systemLocale];
    }
    HLDateTimeZone* zone = [self dateTimeZone];
    NSCalendar* cal = [locale displayNameForKey:NSLocaleCalendar
                                          value:[locale localeIdentifier]];
    NSDateComponents* comp = [[NSDateComponents alloc] init];    
    [comp setYear:[self year]];
    [comp setMonth:[self monthOfYear]];
    [comp setDay:[self dayOfMonth]];
    [comp setHour:[self hourOfDay]];
    [comp setMinute:[self minuteOfHour]];
    [comp setSecond:[self secondOfMinute]];
    [comp setTimeZone:[zone timeZone]];
    
    NSDate* date = [cal dateFromComponents:comp];
    [comp release];
    
    return date;
}

- (NSDate*)gregorianCalendarDate {
    HLDateTimeZone* zone = [self dateTimeZone];
    NSCalendar* cal = [[[NSCalendar alloc] initWithCalendarIdentifier:NSGregorianCalendar] autorelease];
    NSDateComponents* comp = [[NSDateComponents alloc] init];    
    [comp setYear:[self year]];
    [comp setMonth:[self monthOfYear]];
    [comp setDay:[self dayOfMonth]];
    [comp setHour:[self hourOfDay]];
    [comp setMinute:[self minuteOfHour]];
    [comp setSecond:[self secondOfMinute]];
    [comp setTimeZone:[zone timeZone]];
    
    NSDate* date = [cal dateFromComponents:comp];
    [comp release];
    
    return cal;
}

//-----------------------------------------------------------------------
- (NSString*)stringWithPattern:(NSString*)pattern {
    if (pattern == nil) {
        return [self description];
    }
    
    return [[HLDateTimeFormat forPattern:pattern] print:self];
}

- (NSString*)stringWithPattern:(NSString*)pattern 
                        locale:(NSLocale*)locale {
    if (pattern == nil) {
        return [self description];
    }
    
    return [[HLDateTimeFormat forPattern:pattern withLocale:locale] print:self];
}

}

@end
