/*
 * HLAbstractDateTime.m
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

#import "Base/HLAbstractDateTime.h"
#import "Core/HLDateTimeFieldType.h"
#import "Format/HLDateTimeFormat.h"
#import "Format/HLDateTimeFormatter.h"

 
@implementation HLAbstractDateTime

- (id)_init {
    if(self = [super init]) {
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (NSInteger)get:(HLDateTimeFieldType*)type {
    if (type == nil) {
        [NSException raise:NSInvalidArgumentException format:@"The HLDateTimeFieldType must not be nil"];
    }
    
    return [[type field:[self chronology]] get:[self millis]];
}

//-----------------------------------------------------------------------
- (NSInteger)eraValue {
    return [[[self chronology] era] get:[self millis]];
}

- (NSInteger)centuryOfEraValue {
    return [[[self chronology] centuryOfEra] get:[self millis]];
}

- (NSInteger)getYearOfEraValue {
    return [[[self chronology] yearOfEra] get:[self millis]];
}

- (NSInteger)getYearOfCenturyValue {
    return [[[self chronology] yearOfCentury] get:[self millis]];
}

- (NSInteger)getYearValue {
    return [[[self chronology] year] get:[self millis]];
}

- (NSInteger)getWeekyearValue {
    return [[[self chronology] weekyear] get:[self millis]];
}

- (NSInteger)getMonthOfYearValue {
    return [[[self chronology] monthOfYear] get:[self millis]];
}

- (NSInteger)getWeekOfWeekyearValue {
    return [[[self chronology] weekOfWeekyear] get:[self millis]];
}

- (NSInteger)getDayOfYearValue {
    return [[[self chronology] dayOfYear] get:[self millis]];
}

- (NSInteger)getDayOfMonthValue {
    return [[[self chronology] dayOfMonth] get:[self millis]];
}

- (NSInteger)getDayOfWeekValue {
    return [[[self chronology] dayOfWeek] get:[self millis]];
}

//-----------------------------------------------------------------------
- (NSInteger)getHourOfDayValue {
    return [[[self chronology] hourOfDay] get:[self millis]];
}

- (NSInteger)getMinuteOfDayValue {
    return [[[self chronology] minuteOfDay] get:[self millis]];
}

- (NSInteger)getMinuteOfHourValue {
    return [[[self chronology] minuteOfHour] get:[self millis]];
}

- (NSInteger)getSecondOfDayValue {
    return [[[self chronology] secondOfDay] get:[self millis]];
}

- (NSInteger)getSecondOfMinuteValue {
    return [[[self chronology] secondOfMinute] get:[self millis]];
}

- (NSInteger)getMillisOfDayValue {
    return [[[self chronology] millisOfDay] get:[self millis]];
}

- (NSInteger)getMillisOfSecondValue {
    return [[[self chronology] millisOfSecond] get:[self millis]];
}

//-----------------------------------------------------------------------
//- (NSCalendar*)toCalendar:(NSLocale*)locale {
//    if (locale == nil) {
//        locale = [NSLocale ];
//    }
//    HLDateTimeZone* zone = [self zone];
//    NSCalendar* cal = [NSCalendar currentCalendar];
//    [cal setTimeZone:[zone toTimeZone]];
//    [cal setLocale:locale];
//    [cal set
//    cal.setTime([self toDate]);
//
//     return cal;
//}

//public GregorianCalendar toGregorianCalendar() {
//    DateTimeZone zone = getZone();
//    GregorianCalendar cal = new GregorianCalendar(zone.toTimeZone());
//    cal.setTime(toDate());
//    return cal;
//}

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
    
    return [[[HLDateTimeFormat forPattern:pattern] withLocale:locale] print:self];
}

@end
