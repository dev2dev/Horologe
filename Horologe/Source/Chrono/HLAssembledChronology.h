/*
 * AssembledChronology.h
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

#import <Foundation/Foundation.h>

#import "HLBaseChronology.h"


@class HLChronology;
@class HLDurationField;
@class HLDateTimeField;
@class HLDateTimeZone;
@class HLFields;

/**
 * Abstract Chronology that enables chronologies to be assembled from
 * a container of fields.
 * <p>
 * AssembledChronology is thread-safe and immutable.
 *
 * @author Brian S O'Neill
 * @since 1.0
 */
@interface HLAssembledChronology : HLBaseChronology {
    
@private
    HLChronology* _iBase;
    id _iParam;
    
    volatile HLDurationField* _iMillis;
    volatile HLDurationField* _iSeconds;
    volatile HLDurationField* _iMinutes;
    volatile HLDurationField* _iHours;
    volatile HLDurationField* _iHalfdays;
    
    volatile HLDurationField* _iDays;
    volatile HLDurationField* _iWeeks;
    volatile HLDurationField* _iWeekyears;
    volatile HLDurationField* _iMonths;
    volatile HLDurationField* _iYears;
    volatile HLDurationField* _iCenturies;
    volatile HLDurationField* _iEras;
    
    volatile HLDateTimeField* _iMillisOfSecond;
    volatile HLDateTimeField* _iMillisOfDay;
    volatile HLDateTimeField* _iSecondOfMinute;
    volatile HLDateTimeField* _iSecondOfDay;
    volatile HLDateTimeField* _iMinuteOfHour;
    volatile HLDateTimeField* _iMinuteOfDay;
    volatile HLDateTimeField* _iHourOfDay;
    volatile HLDateTimeField* _iClockhourOfDay;
    volatile HLDateTimeField* _iHourOfHalfday;
    volatile HLDateTimeField* _iClockhourOfHalfday;
    volatile HLDateTimeField* _iHalfdayOfDay;
    
    volatile HLDateTimeField* _iDayOfWeek;
    volatile HLDateTimeField* _iDayOfMonth;
    volatile HLDateTimeField* _iDayOfYear;
    volatile HLDateTimeField* _iWeekOfWeekyear;
    volatile HLDateTimeField* _iWeekyear;
    volatile HLDateTimeField* _iWeekyearOfCentury;
    volatile HLDateTimeField* _iMonthOfYear;
    volatile HLDateTimeField* _iYear;
    volatile HLDateTimeField* _iYearOfEra;
    volatile HLDateTimeField* _iYearOfCentury;
    volatile HLDateTimeField* _iCenturyOfEra;
    volatile HLDateTimeField* _iEra;
    
    // Bit set determines which base fields are used
    // bit 1 set: hourOfDay, minuteOfHour, secondOfMinute, and millisOfSecond fields
    // bit 2 set: millisOfDayField
    // bit 3 set: year, monthOfYear, and dayOfMonth fields
    volatile NSInteger _iBaseFlags;
    
}

/**
 * Constructor calls the assemble method, enabling subclasses to define its
 * supported fields. If a base chronology is supplied, the field set
 * initially contains references to each base chronology field.
 * <p>
 * Other methods in this class will delegate to the base chronology, if it
 * can be determined that the base chronology will produce the same results
 * as AbstractChronology.
 *
 * @param base optional base chronology to copy initial fields from
 * @param param optional param object avalable for assemble method
 */
- (id)initWithBase:(HLChronology*)base
             param:(id)param;

- (HLDateTimeZone*)dateTimeZone;

- (NSInteger)dateTimeMillisWithYear:(NSInteger)year 
                        monthOfYear:(NSInteger)monthOfYear
                         dayOfMonth:(NSInteger)dayOfMonth
                        millisOfDay:(NSInteger)millisOfDay;

- (NSInteger)dateTimeMillisWithYear:(NSInteger)year 
                        monthOfYear:(NSInteger)monthOfYear 
                         dayOfMonth:(NSInteger)dayOfMonth
                          hourOfDay:(NSInteger)hourOfDay 
                       minuteOfHour:(NSInteger)minuteOfHour
                     secondOfMinute:(NSInteger)secondOfMinute 
                     millisOfSecond:(NSInteger)millisOfSecond;

- (NSInteger)getDateTimeMillisWithInstantValue:(NSInteger)instant,
hourOfDay:(NSInteger)hourOfDay 
minuteOfHour:(NSInteger)minuteOfHour
secondOfMinute:(NSInteger)secondOfMinute 
millisOfSecond:(NSInteger)millisOfSecond;

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

/**
 * Invoked by the constructor and after deserialization to allow subclasses
 * to define all of its supported fields. All unset fields default to
 * unsupported instances.
 *
 * @param fields container of fields
 */
- (void)assemble:(HLFields*)fields;

/**
 * Returns the same base chronology as passed into the constructor.
 */
- (HLChronology*)base;

/**
 * Returns the same param object as passed into the constructor.
 */
- (id)param;

@end


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

/**
 * Copy the supported fields from a chronology into this container.
 */
- (void)copyFieldsFrom:(HLChronology*)chrono;

@end
