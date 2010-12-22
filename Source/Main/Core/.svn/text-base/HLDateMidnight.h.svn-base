/*
 * HLDateMidnight.h
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

#import "Base/HLBaseDateTime.h"
#import "Core/HLReadableDateTime.h"
#import "Field/HLAbstractReadableInstantFieldProperty.h"


@class HLDateTimeZone;
@class HLChronology;
@class HLDateMidnight;
@class HLDurationFieldType;
@class HLYearMonthDay;
@class HLLocalDate;
@class HLInterval;
@protocol HLReadablePartial;
@protocol HLReadableDateTime;
@protocol HLReadableDuration;
@protocol HLReadablePeriod;

//-----------------------------------------------------------------------
@interface HLProperty : HLAbstractReadableInstantFieldProperty {
    
@private
    /** The instant this property is working against */
    HLDateMidnight* iInstant;
    /** The field this property is working against */
    HLDateTimeField* iField;
    
}

/**
 * Constructor.
 * 
 * @param instant  the instant to set
 * @param field  the field to use
 */
- (id)_initWithInstant:(HLDateMidnight*)instant
                 field:(HLDateTimeField*)field;

- (HLDateTimeField*)field;

- (NSInteger)_millis;

- (HLChronology*)_chronology;

- (HLDateMidnight*)dateMidnight;

//-----------------------------------------------------------------------
- (HLDateMidnight*)addToCopy:(NSInteger)value;

- (HLDateMidnight*)addToCopy:(NSInteger)value;

- (HLDateMidnight*)addWrapFieldToCopy:(NSInteger)value;

//-----------------------------------------------------------------------
- (HLDateMidnight*)setCopy:(NSInteger)value;

- (HLDateMidnight*)setCopyWithText:(NSString*)text 
                            locale:(NSLocale*)locale;

- (HLDateMidnight*)setCopyWithText:(NSString*)text;

//-----------------------------------------------------------------------
- (HLDateMidnight*)withMaximumValue;

- (HLDateMidnight*)withMinimumValue;

//-----------------------------------------------------------------------
- (HLDateMidnight*)roundFloorCopy;

- (HLDateMidnight*)roundCeilingCopy;

- (HLDateMidnight*)roundHalfFloorCopy;

- (HLDateMidnight*)roundHalfCeilingCopy;

- (HLDateMidnight*)roundHalfEvenCopy;

@end


//-----------------------------------------------------------------------
@interface HLDateMidnight : HLBaseDateTime <HLReadableDateTime> {
    
}

// Constructors
//-----------------------------------------------------------------------

- (id)init;

- (id)initWithDateTimeZone:(HLDateTimeZone *)zone;

- (id)initWithChronology:(HLChronology *)chronology;

//-----------------------------------------------------------------------
- (id)initWithInstant:(NSInteger)instant;

- (id)initWithInstant:(NSInteger)instant 
         dateTimeZone:(HLDateTimeZone*)zone;

- (id)initWithInstant:(NSInteger)instant
           chronology:(HLChronology*)chronology;

//-----------------------------------------------------------------------
- (id)initWithObject:(id)instant;

- (id)initWithObject:(id)instant
        dateTimeZone:(HLDateTimeZone*)zone;

- (id)initWithObject:(id)instant
          chronology:(HLChronology*)chronology;

//-----------------------------------------------------------------------
- (id)initWithYear:(NSInteger)year 
       monthOfYear:(NSInteger)monthOfYear 
        dayOfMonth:(NSInteger)dayOfMonth;

- (id)initWithYear:(NSInteger)year 
       monthOfYear:(NSInteger)monthOfYear 
        dayOfMonth:(NSInteger)dayOfMonth 
      dateTimeZone:(HLDateTimeZone*)zone;

- (id)initWithYear:(NSInteger)year 
       monthOfYear:(NSInteger)monthOfYear 
        dayOfMonth:(NSInteger)dayOfMonth 
        chronology:(HLChronology*)chronology;

- (NSInteger)_checkInstant:(NSInteger)instant 
                chronology:(HLChronology*)chronology;

//-----------------------------------------------------------------------
- (HLDateMidnight*)withMillis:(NSInteger)newMillis;

/**
 * Returns a copy of this date with a different chronology, potentially
 * changing the day in unexpected ways.
 * <p>
 * This method creates a new DateMidnight using the midnight millisecond value
 * and the new chronology. If the same or similar chronology is specified, but
 * with a different time zone, the day may change. This occurs because the new
 * DateMidnight rounds down the millisecond value to get to midnight, and the
 * time zone change may result in a rounding down to a different day.
 * <p>
 * For example, changing time zone from London (+00:00) to Paris (+01:00) will
 * retain the same day, but changing from Paris to London will change the day.
 * (When its midnight in London its the same day in Paris, but when its midnight
 * in Paris its still the previous day in London)
 * <p>
 * To avoid these unusual effects, use {@link #withZoneRetainFields(DateTimeZone)}
 * to change time zones.
 *
 * @param newChronology  the new chronology
 * @return a copy of this instant with a different chronology
 */
- (HLDateMidnight*)withChronology:(HLChronology*)newChronology;

/**
 * Returns a copy of this date with a different time zone, preserving the day
 * The returned object will have a local time of midnight in the new zone on
 * the same day as the original instant.
 *
 * @param newZone  the new time zone, null means default
 * @return a copy of this instant with a different time zone
 */
- (HLDateMidnight*)withZoneRetainFields:(HLDateTimeZone*)newZone;

//-----------------------------------------------------------------------
/**
 * Returns a copy of this date with the partial set of fields replacing those
 * from this instance.
 * <p>
 * For example, if the partial is a <code>LocalDate</code> then the date fields
 * would be changed in the returned instance.
 * If the partial is null, then <code>this</code> is returned.
 *
 * @param partial  the partial set of fields to apply to this datetime, null ignored
 * @return a copy of this datetime with a different set of fields
 * @throws IllegalArgumentException if any value is invalid
 */
- (HLDateMidnight*)withFields:(id<HLReadablePartial>)partial;

/**
 * Returns a copy of this date with the specified field set to a new value.
 * <p>
 * For example, if the field type is <code>dayOfMonth</code> then the day of month
 * field would be changed in the returned instance.
 * If the field type is null, then <code>this</code> is returned.
 * <p>
 * These three lines are equivalent:
 * <pre>
 * DateTime updated = dt.withField(DateTimeFieldType.dayOfMonth(), 6);
 * DateTime updated = dt.dayOfMonth().setCopy(6);
 * DateTime updated = dt.property(DateTimeFieldType.dayOfMonth()).setCopy(6);
 * </pre>
 *
 * @param fieldType  the field type to set, not null
 * @param value  the value to set
 * @return a copy of this datetime with the field set
 * @throws IllegalArgumentException if the value is null or invalid
 */
- (HLDateMidnight*)withField:(HLDateTimeFieldType*)fieldType
                       value:(NSInteger)value;

/**
 * Returns a copy of this date with the value of the specified field increased.
 * <p>
 * If the addition is zero or the field is null, then <code>this</code> is returned.
 * <p>
 * These three lines are equivalent:
 * <pre>
 * DateMidnight added = dt.withFieldAdded(DateTimeFieldType.year(), 6);
 * DateMidnight added = dt.plusYears(6);
 * DateMidnight added = dt.year().addToCopy(6);
 * </pre>
 * 
 * @param fieldType  the field type to add to, not null
 * @param amount  the amount to add
 * @return a copy of this datetime with the field updated
 * @throws IllegalArgumentException if the value is null or invalid
 * @throws ArithmeticException if the new datetime exceeds the capacity of a long
 */
- (HLDateMidnight*)withFieldAdded:(HLDurationFieldType*)fieldType
                           amount:(NSInteger)amount;

//-----------------------------------------------------------------------
/**
 * Returns a copy of this date with the specified duration added.
 * <p>
 * If the addition is zero, then <code>this</code> is returned.
 * 
 * @param durationToAdd  the duration to add to this one
 * @param scalar  the amount of times to add, such as -1 to subtract once
 * @return a copy of this datetime with the duration added
 * @throws ArithmeticException if the new datetime exceeds the capacity of a long
 */
- (HLDateMidnight*)withDurationAdded:(NSInteger)durationToAdd
                              scalar:(NSInteger)scalar;

/**
 * Returns a copy of this date with the specified duration added.
 * <p>
 * If the addition is zero, then <code>this</code> is returned.
 * 
 * @param durationToAdd  the duration to add to this one, null means zero
 * @param scalar  the amount of times to add, such as -1 to subtract once
 * @return a copy of this datetime with the duration added
 * @throws ArithmeticException if the new datetime exceeds the capacity of a long
 */
- (HLDateMidnight*)withReadableDurationAdded:(id<HLReadableDuration>)durationToAdd
                                      scalar:(NSInteger)scalar;

/**
 * Returns a copy of this date with the specified period added.
 * <p>
 * If the addition is zero, then <code>this</code> is returned.
 * <p>
 * This method is typically used to add multiple copies of complex
 * period instances. Adding one field is best achieved using methods
 * like {@link #withFieldAdded(DurationFieldType, int)}
 * or {@link #plusYears(int)}.
 * 
 * @param period  the period to add to this one, null means zero
 * @param scalar  the amount of times to add, such as -1 to subtract once
 * @return a copy of this datetime with the period added
 * @throws ArithmeticException if the new datetime exceeds the capacity of a long
 */
- (HLDateMidnight*)withPeriodAdded:(id<HLReadablePeriod>)period
                            scalar:(NSInteger)scalar;

//-----------------------------------------------------------------------
/**
 * Returns a copy of this date with the specified duration added.
 * <p>
 * If the amount is zero, then <code>this</code> is returned.
 * 
 * @param duration  the duration, in millis, to add to this one
 * @return a copy of this datetime with the duration added
 * @throws ArithmeticException if the new datetime exceeds the capacity of a long
 */
- (HLDateMidnight*)plus:(NSInteger)duration;

- (HLDateMidnight*)plusReadableDuration:(id<HLReadableDuration>)duration;

- (HLDateMidnight*)plusReadablePeriod:(id<HLReadablePeriod>)period;

//-----------------------------------------------------------------------
- (HLDateMidnight*)plusYears:(NSInteger)years;

- (HLDateMidnight*)plusMonths:(NSInteger)months;

- (HLDateMidnight*)plusWeeks:(NSInteger)weeks;

- (HLDateMidnight*)plusDays:(NSInteger)days;

//-----------------------------------------------------------------------
- (HLDateMidnight*)minus:(NSInteger)duration;

- (HLDateMidnight*)minusReadableDuration:(id<HLReadableDuration>)duration;

- (HLDateMidnight*)minusReadablePeriod:(id<HLReadablePeriod>)period;

//-----------------------------------------------------------------------
- (HLDateMidnight*)minusYears:(NSInteger)years;

- (HLDateMidnight*)minusMonths:(NSInteger)months;

- (HLDateMidnight*)minusWeeks:(NSInteger)weeks;

- (HLDateMidnight*)minusDays:(NSInteger)days;

//-----------------------------------------------------------------------
- (HLProperty*)property:(HLDateTimeFieldType*)type;

//-----------------------------------------------------------------------
- (HLYearMonthDay*)toYearMonthDay;

- (HLLocalDate*)toLocalDate;

- (HLInterval*)toInterval;

//-----------------------------------------------------------------------
- (HLDateMidnight*)withEra:(NSInteger)era;

- (HLDateMidnight*)withCenturyOfEra:(NSInteger)centuryOfEra;

- (HLDateMidnight*)withYearOfEra:(NSInteger)yearOfEra;

- (HLDateMidnight*)withYearOfCentury:(NSInteger)yearOfCentury;

- (HLDateMidnight*)withYear:(NSInteger)year;

- (HLDateMidnight*)withWeekyear:(NSInteger)weekyear;

- (HLDateMidnight*)withMonthOfYear:(NSInteger)monthOfYear;

- (HLDateMidnight*)withWeekOfWeekyear:(NSInteger)weekOfWeekyear;

- (HLDateMidnight*)withDayOfYear:(NSInteger)dayOfYear;

- (HLDateMidnight*)withDayOfMonth:(NSInteger)dayOfMonth;

- (HLDateMidnight*)withDayOfWeek:(NSInteger)dayOfWeek;

// Date properties
//-----------------------------------------------------------------------
- (HLProperty*)era;

- (HLProperty*)centuryOfEra;

- (HLProperty*)yearOfCentury;

- (HLProperty*)yearOfEra;

- (HLProperty*)year;

- (HLProperty*)weekyear;

- (HLProperty*)monthOfYear;

- (HLProperty*)weekOfWeekyear;

- (HLProperty*)dayOfYear;

- (HLProperty*)dayOfMonth;

- (HLProperty*)dayOfWeek;

@end

