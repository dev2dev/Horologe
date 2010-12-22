/*
 * HLAssembledChronology.h
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

#import <Foundation/Foundation.h>


@class HLDurationField;
@class HLDateTimeField;
@class HLChronology;
@class HLDateTimeZone;

@interface HLFields : NSObject {
    
@public
    HLDurationField* millis;
    HLDurationField* seconds;
    HLDurationField* minutes;
    HLDurationField* hours;
    HLDurationField* halfdays;
    
    HLDurationField* days;
    HLDurationField* weeks;
    HLDurationField* weekyears;
    HLDurationField* months;
    HLDurationField* years;
    HLDurationField* centuries;
    HLDurationField* eras;
    
    HLDateTimeField* millisOfSecond;
    HLDateTimeField* millisOfDay;
    HLDateTimeField* secondOfMinute;
    HLDateTimeField* secondOfDay;
    HLDateTimeField* minuteOfHour;
    HLDateTimeField* minuteOfDay;
    HLDateTimeField* hourOfDay;
    HLDateTimeField* clockhourOfDay;
    HLDateTimeField* hourOfHalfday;
    HLDateTimeField* clockhourOfHalfday;
    HLDateTimeField* halfdayOfDay;
    
    HLDateTimeField* dayOfWeek;
    HLDateTimeField* dayOfMonth;
    HLDateTimeField* dayOfYear;
    HLDateTimeField* weekOfWeekyear;
    HLDateTimeField* weekyear;
    HLDateTimeField* weekyearOfCentury;
    HLDateTimeField* monthOfYear;
    HLDateTimeField* year;
    HLDateTimeField* yearOfEra;
    HLDateTimeField* yearOfCentury;
    HLDateTimeField* centuryOfEra;
    HLDateTimeField* era;
}

- (void)copyFieldsFrom:(HLChronology*)chrono;

@end


@interface HLAssembledChronology : NSObject {
    
@private
    HLChronology* iBase;
    id iParam;
    
    HLDurationField* iMillis;
    HLDurationField* iSeconds;
    HLDurationField* iMinutes;
    HLDurationField* iHours;
    HLDurationField* iHalfdays;
    
    HLDurationField* iDays;
    HLDurationField* iWeeks;
    HLDurationField* iWeekyears;
    HLDurationField* iMonths;
    HLDurationField* iYears;
    HLDurationField* iCenturies;
    HLDurationField* iEras;
    
    HLDateTimeField* iMillisOfSecond;
    HLDateTimeField* iMillisOfDay;
    HLDateTimeField* iSecondOfMinute;
    HLDateTimeField* iSecondOfDay;
    HLDateTimeField* iMinuteOfHour;
    HLDateTimeField* iMinuteOfDay;
    HLDateTimeField* iHourOfDay;
    HLDateTimeField* iClockhourOfDay;
    HLDateTimeField* iHourOfHalfday;
    HLDateTimeField* iClockhourOfHalfday;
    HLDateTimeField* iHalfdayOfDay;
    
    HLDateTimeField* iDayOfWeek;
    HLDateTimeField* iDayOfMonth;
    HLDateTimeField* iDayOfYear;
    HLDateTimeField* iWeekOfWeekyear;
    HLDateTimeField* iWeekyear;
    HLDateTimeField* iWeekyearOfCentury;
    HLDateTimeField* iMonthOfYear;
    HLDateTimeField* iYear;
    HLDateTimeField* iYearOfEra;
    HLDateTimeField* iYearOfCentury;
    HLDateTimeField* iCenturyOfEra;
    HLDateTimeField* iEra;
    
    // Bit set determines which base fields are used
    // bit 1 set: hourOfDay, minuteOfHour, secondOfMinute, and millisOfSecond fields
    // bit 2 set: millisOfDayField
    // bit 3 set: year, monthOfYear, and dayOfMonth fields
    int iBaseFlags : 3;
    
}

- (id)_initWithChronology:(HLChronology*)base 
                   param:(id)param;

- (HLDateTimeZone*)dateTimeZone;

- (NSInteger)dateTimeMillisFromYear:(NSInteger)year 
                              month:(NSInteger)monthOfYear 
                                day:(NSInteger)dayOfMonth
                             millis:(NSInteger)millisOfDay;

- (NSInteger)dateTimeMillisFromYear:(NSInteger)year 
                              month:(NSInteger)monthOfYear 
                                day:(NSInteger)dayOfMonth
                               hour:(NSInteger)hourOfDay 
                             minute:(NSInteger)minuteOfHour
                             second:(NSInteger)secondOfMinute
                             millis:(NSInteger)millisOfSecond;

- (NSInteger)dateTimeMillisFromInstant:(NSInteger)instant
                                  hour:(NSInteger)hourOfDay
                                minute:(NSInteger)minuteOfHour
                                second:(NSInteger)secondOfMinute
                                millis:(NSInteger)millisOfSecond;

- (HLDurationField*)millis;

- (HLDateTimeField*)millisOfSecond;

- (HLDateTimeField*)millisOfDay;

- (HLDurationField*)seconds;

- (HLDateTimeField*)secondOfMinute;

- (HLDateTimeField*)secondOfDay;

- (HLDurationField*)minutes;

- (HLDateTimeField*)minuteOfHour;

- (HLDateTimeField*)minuteOfDay;

- (HLDurationField*)hours;

- (HLDateTimeField*)hourOfDay;

- (HLDateTimeField*)clockhourOfDay;

- (HLDurationField*)halfdays;

- (HLDateTimeField*)hourOfHalfday;

- (HLDateTimeField*)clockhourOfHalfday;

- (HLDateTimeField*)halfdayOfDay;

- (HLDurationField*)days;

- (HLDateTimeField*)dayOfWeek;

- (HLDateTimeField*)dayOfMonth;

- (HLDateTimeField*)dayOfYear;

- (HLDurationField*)weeks;

- (HLDateTimeField*)weekOfWeekyear;

- (HLDurationField*)weekyears;

- (HLDateTimeField*)weekyear;

- (HLDateTimeField*)weekyearOfCentury;

- (HLDurationField*)months;

- (HLDateTimeField*)monthOfYear;

- (HLDurationField*)years;

- (HLDateTimeField*)year;

- (HLDateTimeField*)yearOfEra;

- (HLDateTimeField*)yearOfCentury;

- (HLDurationField*)centuries;

- (HLDateTimeField*)centuryOfEra;

- (HLDurationField*)eras;

- (HLDateTimeField*)era;

- (void)_assemble:(HLFields*)fields;

- (HLChronology*)_base;

- (id)_param;

@end
