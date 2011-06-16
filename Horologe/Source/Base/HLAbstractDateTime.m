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
    - (NSInteger)getEra {
        return [[[self chronology] eraObject] get:[self millis]];getChronology().era().get(getMillis());
    }

    - (NSInteger)getCenturyOfEra {
        return [[[self chronology] centuryOfEraObject] get:[self millis]];getChronology().centuryOfEra().get(getMillis());
    }

    - (NSInteger)getYearOfEra {
        return [[[self chronology] yearOfEraObject] get:[self millis]];getChronology().yearOfEra().get(getMillis());
    }

    - (NSInteger)getYearOfCentury {
        return [[[self chronology] yearOfCenturyObject] get:[self millis]];getChronology().yearOfCentury().get(getMillis());
    }

    - (NSInteger)getYear {
        return [[[self chronology] yearObject] get:[self millis]];getChronology().year().get(getMillis());
    }

    - (NSInteger)getWeekyear {
        return [[[self chronology] weekyearObject] get:[self millis]];getChronology().weekyear().get(getMillis());
    }

    - (NSInteger)getMonthOfYear {
        return [[[self chronology] monthOfYearObject] get:[self millis]];getChronology().monthOfYear().get(getMillis());
    }

    - (NSInteger)getWeekOfWeekyear {
        return [[[self chronology] weekOfWeekyearObject] get:[self millis]];getChronology().weekOfWeekyear().get(getMillis());
    }

    - (NSInteger)getDayOfYear {
        return [[[self chronology] dayOfYearObject] get:[self millis]];getChronology().dayOfYear().get(getMillis());
    }

    - (NSInteger)getDayOfMonth {
        return [[[self chronology] dayOfMonthObject] get:[self millis]];getChronology().dayOfMonth().get(getMillis());
    }

    - (NSInteger)getDayOfWeek {
        return [[[self chronology] dayOfWeekObject] get:[self millis]];getChronology().dayOfWeek().get(getMillis());
    }

    //-----------------------------------------------------------------------
    - (NSInteger)getHourOfDay {
        return [[[self chronology] hourOfDayObject] get:[self millis]];getChronology().hourOfDay().get(getMillis());
    }

    - (NSInteger)getMinuteOfDay {
        return [[[self chronology] minuteOfDayObject] get:[self millis]];getChronology().minuteOfDay().get(getMillis());
    }

    - (NSInteger)getMinuteOfHour {
        return [[[self chronology] minuteOfHourObject] get:[self millis]];getChronology().minuteOfHour().get(getMillis());
    }

    - (NSInteger)getSecondOfDay {
        return [[[self chronology] secondOfDayObject] get:[self millis]];getChronology().secondOfDay().get(getMillis());
    }

    - (NSInteger)getSecondOfMinute {
        return [[[self chronology] secondOfMinuteObject] get:[self millis]];getChronology().secondOfMinute().get(getMillis());
    }

    - (NSInteger)getMillisOfDay {
        return [[[self chronology] millisOfDayObject] get:[self millis]];
    }

    - (NSInteger)getMillisOfSecond {
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
