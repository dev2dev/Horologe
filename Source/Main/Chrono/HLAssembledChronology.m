/*
 * HLAssembledChronology.m
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

#import "HLAssembledChronology.h"
#import "HLChronology.h"
#import "HLDurationField.h"
#import "HLDateTimeField.h"


/**
 * A container of fields used for assembling a chronology.
 */
@interface HLFields (PrivateMethods) 
+ (BOOL)isDurationFieldSupported:(HLDurationField*)field;
+ (BOOL)isDateTimeFieldSupported:(HLDateTimeField*)field;
@end

@implementation HLFields

- (id)_init {
    if(self = [super init]) {
        
    }
    
    return self;
}

- (void)copyFieldsFrom:(HLChronology*)chrono {
    {
        HLDurationField* f;
        if ([HLFields isDurationFieldSupported:(f = [chrono millis])]) {
            millis = [f retain];
        }
        if ([HLFields isDurationFieldSupported:(f = [chrono seconds])]) {
            seconds = [f retain];
        }
        if ([HLFields isDurationFieldSupported:(f = [chrono minutes])]) {
            minutes = [f retain];
        }
        if ([HLFields isDurationFieldSupported:(f = [chrono hours])]) {
            hours = [f retain];
        }
        if ([HLFields isDurationFieldSupported:(f = [chrono halfdays])]) {
            halfdays = [f retain];
        }
        if ([HLFields isDurationFieldSupported:(f = [chrono days])]) {
            days = [f retain];
        }
        if ([HLFields isDurationFieldSupported:(f = [chrono weeks])]) {
            weeks = [f retain];
        }
        if ([HLFields isDurationFieldSupported:(f = [chrono weekyears])]) {
            weekyears = [f retain];
        }
        if ([HLFields isDurationFieldSupported:(f = [chrono months])]) {
            months = [f retain];
        }
        if ([HLFields isDurationFieldSupported:(f = [chrono years])]) {
            years = [f retain];
        }
        if ([HLFields isDurationFieldSupported:(f = [chrono centuries])]) {
            centuries = [f retain];
        }
        if ([HLFields isDurationFieldSupported:(f = [chrono eras])]) {
            eras = [f retain];
        }
    }
    
    {
        HLDateTimeField* f;
        if ([HLFields isDateTimeFieldSupported:(f = [chrono millisOfSecond])]) {
            millisOfSecond = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono millisOfDay])]) {
            millisOfDay = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono secondOfMinute])]) {
            secondOfMinute = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono secondOfDay])]) {
            secondOfDay = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono minuteOfHour])]) {
            minuteOfHour = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono minuteOfDay])]) {
            minuteOfDay = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono hourOfDay])]) {
            hourOfDay = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono clockhourOfDay])]) {
            clockhourOfDay = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono hourOfHalfday])]) {
            hourOfHalfday = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono clockhourOfHalfday])]) {
            clockhourOfHalfday = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono halfdayOfDay])]) {
            halfdayOfDay = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono dayOfWeek])]) {
            dayOfWeek = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono dayOfMonth])]) {
            dayOfMonth = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono dayOfYear])]) {
            dayOfYear = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono weekOfWeekyear])]) {
            weekOfWeekyear = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono weekyear])]) {
            weekyear = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono weekyearOfCentury])]) {
            weekyearOfCentury = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono monthOfYear])]) {
            monthOfYear = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono year])]) {
            year = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono yearOfEra])]) {
            yearOfEra = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono yearOfCentury])]) {
            yearOfCentury = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono centuryOfEra])]) {
            centuryOfEra = [f retain];
        }
        if ([HLFields isDateTimeFieldSupported:(f = [chrono era])]) {
            era = [f retain];
        }
    }
}

+ (BOOL)isDurationFieldSupported:(HLDurationField*)field {
    return field == nil ? NO : [field isSupported];
}

+ (BOOL)isDateTimeFieldSupported:(HLDateTimeField*)field {
    return field == nil ? NO : [field isSupported];
}

@end


//-----------------------------------------------------------------------
@interface HLAssembledChronology (PrivateMethods)
- (void)readObject:(NSInputStream*)stream;
- (void)setFields;
@end

@implementation HLAssembledChronology

- (id)_initWithChronology:(HLChronology*)base 
                    param:(id)param {
    if(self = [super init]) {
        iBase = [base retain];
        iParam = [param retain];
        
        [self setFields];
    }
    
    return self;
}

- (HLDateTimeZone*)dateTimeZone {
    HLChronology* base;
    if ((base = iBase) != nil) {
        return [base dateTimeZone];
    }
    
    return nil;
}

- (NSInteger)getDateTimeMillisFromYear:(NSInteger)year 
                           monthOfYear:(NSInteger)monthOfYear 
                            dayOfMonth:(NSInteger)dayOfMonth
                           millisOfDay:(NSInteger)millisOfDay {
    HLChronology* base;
    if ((base = iBase) != nil && (iBaseFlags & 6) == 6) {
        // Only call specialized implementation if applicable fields are the same.
        return [base dateTimeMillisFromYear:year monthOfYear:monthOfYear dayOfMonth:dayOfMonth millisOfDay:millisOfDay];
    }
    
    return [super dateTimeMillisFromYear:year monthOfYear:monthOfYear dayOfMonth:dayOfMonth millisOfDay:millisOfDay];
}

- (NSInteger)getDateTimeMillisFromYear:(NSInteger)year 
                           monthOfYear:(NSInteger)monthOfYear 
                            dayOfMonth:(NSInteger)dayOfMonth
                             hourOfDay:(NSInteger)hourOfDay 
                          minuteOfHour:(NSInteger)minuteOfHour
                        secondOfMinute:(NSInteger)secondOfMinute 
                        millisOfSecond:(NSInteger)millisOfSecond {
    HLChronology* base;
    if ((base = iBase) != nil && (iBaseFlags & 5) == 5) {
        // Only call specialized implementation if applicable fields are the same.
        return [base dateTimeMillisFromYear:year 
                                monthOfYear:monthOfYear 
                                 dayOfMonth:dayOfMonth
                                  hourOfDay:hourOfDay 
                               minuteOfHour:minuteOfHour 
                             secondOfMinute:secondOfMinute
                             millisOfSecond:millisOfSecond];
    }
    
    return [super dateTimeMillisFromYear:year, monthOfYear, dayOfMonth,
            hourOfDay, minuteOfHour, secondOfMinute, millisOfSecond];
}

- (NSInteger)getDateTimeMillisFromInstant:(NSInteger)instant
                                hourOfDay:(NSInteger)hourOfDay 
                             minuteOfHour:(NSInteger)minuteOfHour
                           secondOfMinute:(NSInteger)secondOfMinute 
                           millisOfSecond:(NSInteger)millisOfSecond {
    HLChronology* base;
    if ((base = iBase) != nil && (iBaseFlags & 1) == 1) {
        // Only call specialized implementation if applicable fields are the same.
        return [base dateTimeMillisFromInstant:instant 
                                     hourOfDay:hourOfDay
                                  minuteOfHour:minuteOfHour
                                secondOfMinute:secondOfMinute
                                millisOfSecond:millisOfSecond];
    }
    
    return [super dateTimeMillisFromInstant:instant
                                  hourOfDay:hourOfDay
                               minuteOfHour:minuteOfHour
                             secondOfMinute:secondOfMinute
                             millisOfSecond:millisOfSecond];
}

- (HLDurationField*)millis {
    return iMillis;
}

- (HLDateTimeField*)millisOfSecond {
    return iMillisOfSecond;
}

- (HLDateTimeField*)millisOfDay {
    return iMillisOfDay;
}

- (HLDurationField*)seconds {
    return iSeconds;
}

- (HLDateTimeField*)secondOfMinute {
    return iSecondOfMinute;
}

- (HLDateTimeField*)secondOfDay {
    return iSecondOfDay;
}

- (HLDurationField*)minutes {
    return iMinutes;
}

- (HLDateTimeField*)minuteOfHour {
    return iMinuteOfHour;
}

- (HLDateTimeField*)minuteOfDay {
    return iMinuteOfDay;
}

- (HLDurationField*)hours {
    return iHours;
}

- (HLDateTimeField*)hourOfDay {
    return iHourOfDay;
}

- (HLDateTimeField*)clockhourOfDay {
    return iClockhourOfDay;
}

- (HLDurationField*)halfdays {
    return iHalfdays;
}

- (HLDateTimeField*)hourOfHalfday {
    return iHourOfHalfday;
}

- (HLDateTimeField*)clockhourOfHalfday {
    return iClockhourOfHalfday;
}

- (HLDateTimeField*)halfdayOfDay {
    return iHalfdayOfDay;
}

- (HLDurationField*)days {
    return iDays;
}

- (HLDateTimeField*)dayOfWeek {
    return iDayOfWeek;
}

- (HLDateTimeField*)dayOfMonth {
    return iDayOfMonth;
}

- (HLDateTimeField*)dayOfYear {
    return iDayOfYear;
}

- (HLDurationField*)weeks {
    return iWeeks;
}

- (HLDateTimeField*)weekOfWeekyear {
    return iWeekOfWeekyear;
}

- (HLDurationField*)weekyears {
    return iWeekyears;
}

- (HLDateTimeField*)weekyear {
    return iWeekyear;
}

- (HLDateTimeField*)weekyearOfCentury {
    return iWeekyearOfCentury;
}

- (HLDurationField*)months {
    return iMonths;
}

- (HLDateTimeField*)monthOfYear {
    return iMonthOfYear;
}

- (HLDurationField*)years {
    return iYears;
}

- (HLDateTimeField*)year {
    return iYear;
}

- (HLDateTimeField*)yearOfEra {
    return iYearOfEra;
}

- (HLDateTimeField*)yearOfCentury {
    return iYearOfCentury;
}

- (HLDurationField*)centuries {
    return iCenturies;
}

- (HLDateTimeField*)centuryOfEra {
    return iCenturyOfEra;
}

- (HLDurationField*)eras {
    return iEras;
}

- (HLDateTimeField*)era {
    return iEra;
}

- (HLChronology*)_base {
    return iBase;
}

- (id)_param {
    return iParam;
}

- (void)setFields {
    HLFields* fields = [[HLFields alloc] init];
    if (iBase != nil) {
        [fields copyFieldsFrom:iBase];
    }
    
    [self _assemble:fields];
    
    {
        HLDurationField* f;
        iMillis    = (f = [fields millis])    != nil ? f : [super millis];
        iSeconds   = (f = [fields seconds])   != nil ? f : [super seconds];
        iMinutes   = (f = [fields minutes])   != nil ? f : [super minutes];
        iHours     = (f = [fields hours])     != nil ? f : [super hours];
        iHalfdays  = (f = [fields halfdays])  != nil ? f : [super halfdays];
        iDays      = (f = [fields days])      != nil ? f : [super days];
        iWeeks     = (f = [fields weeks])     != nil ? f : [super weeks];
        iWeekyears = (f = [fields weekyears]) != nil ? f : [super weekyears];
        iMonths    = (f = [fields months])    != nil ? f : [super months];
        iYears     = (f = [fields years])     != nil ? f : [super years];
        iCenturies = (f = [fields centuries]) != nil ? f : [super centuries];
        iEras      = (f = [fields eras])      != nil ? f : [super eras];
    }
    
    {
        HLDateTimeField* f;
        iMillisOfSecond     = (f = [fields millisOfSecond])     != nil ? f : [super millisOfSecond];
        iMillisOfDay        = (f = [fields millisOfDay])        != nil ? f : [super millisOfDay];
        iSecondOfMinute     = (f = [fields secondOfMinute])     != nil ? f : [super secondOfMinute];
        iSecondOfDay        = (f = [fields secondOfDay])        != nil ? f : [super secondOfDay];
        iMinuteOfHour       = (f = [fields minuteOfHour])       != nil ? f : [super minuteOfHour];
        iMinuteOfDay        = (f = [fields minuteOfDay])        != nil ? f : [super minuteOfDay];
        iHourOfDay          = (f = [fields hourOfDay])          != nil ? f : [super hourOfDay];
        iClockhourOfDay     = (f = [fields clockhourOfDay])     != nil ? f : [super clockhourOfDay];
        iHourOfHalfday      = (f = [fields hourOfHalfday])      != nil ? f : [super hourOfHalfday];
        iClockhourOfHalfday = (f = [fields clockhourOfHalfday]) != nil ? f : [super clockhourOfHalfday];
        iHalfdayOfDay       = (f = [fields halfdayOfDay])       != nil ? f : [super halfdayOfDay];
        iDayOfWeek          = (f = [fields dayOfWeek])          != nil ? f : [super dayOfWeek];
        iDayOfMonth         = (f = [fields dayOfMonth])         != nil ? f : [super dayOfMonth];
        iDayOfYear          = (f = [fields dayOfYear])          != nil ? f : [super dayOfYear];
        iWeekOfWeekyear     = (f = [fields weekOfWeekyear])     != nil ? f : [super weekOfWeekyear];
        iWeekyear           = (f = [fields weekyear])           != nil ? f : [super weekyear];
        iWeekyearOfCentury  = (f = [fields weekyearOfCentury])  != nil ? f : [super weekyearOfCentury];
        iMonthOfYear        = (f = [fields monthOfYear])        != nil ? f : [super monthOfYear];
        iYear               = (f = [fields year])               != nil ? f : [super year];
        iYearOfEra          = (f = [fields yearOfEra])          != nil ? f : [super yearOfEra];
        iYearOfCentury      = (f = [fields yearOfCentury])      != nil ? f : [super yearOfCentury];
        iCenturyOfEra       = (f = [fields centuryOfEra])       != nil ? f : [super centuryOfEra];
        iEra                = (f = [fields era])                != nil ? f : [super era];
    }
    
    NSInteger flags;
    if (iBase == nil) {
        flags = 0;
    } 
    else {
        flags = 
        ((iHourOfDay      == [iBase hourOfDay]      &&
          iMinuteOfHour   == [iBase minuteOfHour]   &&
          iSecondOfMinute == [iBase secondOfMinute] &&
          iMillisOfSecond == [iBase millisOfSecond]   ) ? 1 : 0) |
        
        ((iMillisOfDay == [iBase millisOfDay]) ? 2 : 0) |
        
        ((iYear        == [iBase year]        &&
          iMonthOfYear == [iBase monthOfYear] &&
          iDayOfMonth  == [iBase dayOfMonth]    ) ? 4 : 0);
    }
    
    iBaseFlags = flags;
}

- (void)readObject:(NSInputStream*)stream {
    [stream defaultReadObject];
    [self setFields];
}

@end
