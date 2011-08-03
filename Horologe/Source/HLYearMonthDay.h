/*
 * YearMonthDay.h
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

#import "HLBasePartial.h"
#import "HLReadablePartial.h"
#import "HLAbstractPartialFieldProperty.h"


/** The index of the year field in the field array */
#define HL_YEAR (0)
/** The index of the monthOfYear field in the field array */
#define HL_MONTH_OF_YEAR (1)
/** The index of the dayOfMonth field in the field array */
#define HL_DAY_OF_MONTH (2)

@class HLProperty;
@class HLDateTimeZone;
@class HLLocalDate;
@class HLDateMidnight;
@class HLTimeOfDay;
@class HLInterval;
@class HLYearMonthDayProperty;
@protocol HLReadablePeriod;

/**
 * YearMonthDay is an immutable partial supporting the year, monthOfYear
 * and dayOfMonth fields.
 * <p>
 * NOTE: This class only supports the three fields listed above. Thus, you
 * cannot query the dayOfWeek or centuryOfEra fields for example.
 * The new <code>LocalDate</code> class removes this restriction.
 * <p>
 * Calculations on YearMonthDay are performed using a {@link Chronology}.
 * This chronology is set to be in the UTC time zone for all calculations.
 * <p>
 * Each individual field can be queried in two ways:
 * <ul>
 * <li><code>getMonthOfYear()</code>
 * <li><code>monthOfYear().get()</code>
 * </ul>
 * The second technique also provides access to other useful methods on the
 * field:
 * <ul>
 * <li>numeric value - <code>monthOfYear().get()</code>
 * <li>text value - <code>monthOfYear().getAsText()</code>
 * <li>short text value - <code>monthOfYear().getAsShortText()</code>
 * <li>maximum/minimum values - <code>monthOfYear().getMaximumValue()</code>
 * <li>add/subtract - <code>monthOfYear().addToCopy()</code>
 * <li>set - <code>monthOfYear().setCopy()</code>
 * </ul>
 * <p>
 * YearMonthDay is thread-safe and immutable, provided that the Chronology is as well.
 * All standard Chronology classes supplied are thread-safe and immutable.
 *
 * @author Stephen Colebourne
 * @since 1.0
 * @deprecated Use LocalDate which has a much better internal implementation and
 *  has been available since 1.3
 */
@interface HLYearMonthDay : HLBasePartial <HLReadablePartial> {
    
@private
    
}

//-----------------------------------------------------------------------
/**
 * Constructs a YearMonthDay from a <code>java.util.Calendar</code>
 * using exactly the same field values avoiding any time zone effects.
 * <p>
 * Each field is queried from the Calendar and assigned to the YearMonthDay.
 * This is useful if you have been using the Calendar as a local date,
 * ignoing the zone.
 * <p>
 * This factory method ignores the type of the calendar and always
 * creates a YearMonthDay with ISO chronology. It is expected that you
 * will only pass in instances of <code>GregorianCalendar</code> however
 * this is not validated.
 *
 * @param calendar  the Calendar to extract fields from
 * @return the created YearMonthDay
 * @throws IllegalArgumentException if the calendar is nil
 * @throws IllegalArgumentException if the date is invalid for the ISO chronology
 * @since 1.2
 */
+ (HLYearMonthDay*)fromDateComponents:(NSDateComponents*)components;

/**
 * Constructs a YearMonthDay from a <code>java.util.Date</code>
 * using exactly the same field values avoiding any time zone effects.
 * <p>
 * Each field is queried from the Date and assigned to the YearMonthDay.
 * This is useful if you have been using the Date as a local date,
 * ignoing the zone.
 * <p>
 * This factory method always creates a YearMonthDay with ISO chronology.
 *
 * @param date  the Date to extract fields from
 * @return the created YearMonthDay
 * @throws IllegalArgumentException if the calendar is nil
 * @throws IllegalArgumentException if the date is invalid for the ISO chronology
 * @since 1.2
 */
+ (HLYearMonthDay*)fromDate:(NSDate*)date;

//-----------------------------------------------------------------------
/**
 * Constructs a YearMonthDay with the current date, using ISOChronology in
 * the specified zone to extract the fields.
 * <p>
 * The constructor uses the specified time zone to obtain the current date.
 * Once the constructor is complete, all further calculations
 * are performed without reference to a timezone (by switching to UTC).
 * 
 * @param zone  the zone to use, nil means default zone
 * @since 1.1
 */
- (id)initWithDateTimeZone:(HLDateTimeZone*)zone;

/**
 * Constructs a YearMonthDay with the current date, using the specified chronology
 * and zone to extract the fields.
 * <p>
 * The constructor uses the time zone of the chronology specified.
 * Once the constructor is complete, all further calculations are performed
 * without reference to a timezone (by switching to UTC).
 *
 * @param chronology  the chronology, nil means ISOChronology in the default zone
 */
- (id)initWithChronology:(HLChronology*)chronology;

/**
 * Constructs a YearMonthDay extracting the partial fields from the specified
 * milliseconds using the ISOChronology in the default zone.
 * <p>
 * The constructor uses the default time zone, resulting in the local time
 * being initialised. Once the constructor is complete, all further calculations
 * are performed without reference to a timezone (by switching to UTC).
 *
 * @param instant  the milliseconds from 1970-01-01T00:00:00Z
 */
- (id)initWithInstantValue:(NSInteger)instant;

/**
 * Constructs a YearMonthDay extracting the partial fields from the specified
 * milliseconds using the chronology provided.
 * <p>
 * The constructor uses the time zone of the chronology specified.
 * Once the constructor is complete, all further calculations are performed
 * without reference to a timezone (by switching to UTC).
 *
 * @param instant  the milliseconds from 1970-01-01T00:00:00Z
 * @param chronology  the chronology, nil means ISOChronology in the default zone
 */
- (id)initWithInstantValue:(NSInteger)instant
                chronology:(HLChronology*)chronology;

/**
 * Constructs a YearMonthDay from an Object that represents a time.
 * <p>
 * The recognised object types are defined in
 * {@link org.joda.time.convert.ConverterManager ConverterManager} and
 * include ReadableInstant, String, Calendar and Date.
 * The String formats are described by {@link ISODateTimeFormat#dateOptionalTimeParser()}.
 * <p>
 * The chronology used will be derived from the object, defaulting to ISO.
 * <p>
 * NOTE: Prior to v1.3 the string format was described by
 * {@link ISODateTimeFormat#dateTimeParser()}. Time ony strings are now rejected.
 *
 * @param instant  the datetime object, nil means now
 * @throws IllegalArgumentException if the instant is invalid
 */
- (id)initWithInstant:(id)instant;

/**
 * Constructs a YearMonthDay from an Object that represents a time, using the
 * specified chronology.
 * <p>
 * The recognised object types are defined in
 * {@link org.joda.time.convert.ConverterManager ConverterManager} and
 * include ReadableInstant, String, Calendar and Date.
 * The String formats are described by {@link ISODateTimeFormat#dateOptionalTimeParser()}.
 * <p>
 * The constructor uses the time zone of the chronology specified.
 * Once the constructor is complete, all further calculations are performed
 * without reference to a timezone (by switching to UTC).
 * The specified chronology overrides that of the object.
 * <p>
 * NOTE: Prior to v1.3 the string format was described by
 * {@link ISODateTimeFormat#dateTimeParser()}. Time only strings are now rejected.
 *
 * @param instant  the datetime object, nil means now
 * @param chronology  the chronology, nil means ISO default
 * @throws IllegalArgumentException if the instant is invalid
 */
- (id)initWithInstant:(id)instant
           chronology:(HLChronology*)chronology;

/**
 * Constructs a YearMonthDay with specified time field values
 * using <code>ISOChronology</code> in the default zone.
 * <p>
 * The constructor uses the no time zone initialising the fields as provided.
 * Once the constructor is complete, all further calculations
 * are performed without reference to a timezone (by switching to UTC).
 *
 * @param year  the year
 * @param monthOfYear  the month of the year
 * @param dayOfMonth  the day of the month
 */
- (id)initWithYear:(NSInteger)year 
       monthOfYear:(NSInteger)monthOfYear 
        dayOfMonth:(NSInteger)dayOfMonth;

/**
 * Constructs a YearMonthDay with specified time field values.
 * <p>
 * The constructor uses the time zone of the chronology specified.
 * Once the constructor is complete, all further calculations are performed
 * without reference to a timezone (by switching to UTC).
 *
 * @param year  the year
 * @param monthOfYear  the month of the year
 * @param dayOfMonth  the day of the month
 * @param chronology  the chronology, nil means ISOChronology in the default zone
 */
- (id)initWithYear:(NSInteger)year 
       monthOfYear:(NSInteger)monthOfYear 
        dayOfMonth:(NSInteger)dayOfMonth
        chronology:(HLChronology*)chronology;

/**
 * Constructs a YearMonthDay with chronology from this instance and new values.
 *
 * @param partial  the partial to base this new instance on
 * @param values  the new set of values
 */
- (id)initWithPartial:(HLYearMonthDay*)partial
               values:(NSArray*)values;

/**
 * Constructs a YearMonthDay with values from this instance and a new chronology.
 *
 * @param partial  the partial to base this new instance on
 * @param chrono  the new chronology
 */
-(id)initWithPartial:(HLYearMonthDay*)partial
          chronology:(HLChronology*)chrono;

//-----------------------------------------------------------------------
/**
 * Gets the number of fields in this partial.
 * 
 * @return the field count
 */
- (NSInteger)size;

/**
 * Gets the field for a specific index in the chronology specified.
 * <p>
 * This method must not use any instance variables.
 * 
 * @param index  the index to retrieve
 * @param chrono  the chronology to use
 * @return the field
 */
- (HLDateTimeField*)fieldAtIndex:(NSInteger)index 
                  withChronology:(HLChronology *)chrono;

/**
 * Gets the field type at the specified index.
 *
 * @param index  the index to retrieve
 * @return the field at the specified index
 * @throws IndexOutOfBoundsException if the index is invalid
 */
- (HLDateTimeFieldType*)fieldTypeAtIndex:(NSInteger)index;

/**
 * Gets an array of the field type of each of the fields that this partial supports.
 * <p>
 * The fields are returned largest to smallest, Year, Month, Day
 *
 * @return the array of field types (cloned), largest to smallest
 */
- (NSArray*)fieldTypes;

//-----------------------------------------------------------------------
/**
 * Returns a copy of this date with the specified chronology.
 * This instance is immutable and unaffected by this method call.
 * <p>
 * This method retains the values of the fields, thus the result will
 * typically refer to a different instant.
 * <p>
 * The time zone of the specified chronology is ignored, as YearMonthDay
 * operates without a time zone.
 *
 * @param newChronology  the new chronology, nil means ISO
 * @return a copy of this datetime with a different chronology
 * @throws IllegalArgumentException if the values are invalid for the new chronology
 */
- (HLYearMonthDay*)withChronologyRetainFields:(HLChronology*)newChronology;

/**
 * Returns a copy of this date with the specified field set to a new value.
 * <p>
 * For example, if the field type is <code>dayOfMonth</code> then the day
 * would be changed in the returned instance.
 * <p>
 * These three lines are equivalent:
 * <pre>
 * YearMonthDay updated = ymd.withField(DateTimeFieldType.dayOfMonth(), 6);
 * YearMonthDay updated = ymd.dayOfMonth().setCopy(6);
 * YearMonthDay updated = ymd.property(DateTimeFieldType.dayOfMonth()).setCopy(6);
 * </pre>
 *
 * @param fieldType  the field type to set, not nil
 * @param value  the value to set
 * @return a copy of this instance with the field set
 * @throws IllegalArgumentException if the value is nil or invalid
 */
- (HLYearMonthDay*)withField:(HLDateTimeFieldType*)fieldType 
                       value:(NSInteger)value;

/**
 * Returns a copy of this date with the value of the specified field increased.
 * <p>
 * If the addition is zero, then <code>this</code> is returned.
 * <p>
 * These three lines are equivalent:
 * <pre>
 * YearMonthDay added = ymd.withFieldAdded(DurationFieldType.days(), 6);
 * YearMonthDay added = ymd.plusDays(6);
 * YearMonthDay added = ymd.dayOfMonth().addToCopy(6);
 * </pre>
 * 
 * @param fieldType  the field type to add to, not nil
 * @param amount  the amount to add
 * @return a copy of this instance with the field updated
 * @throws IllegalArgumentException if the value is nil or invalid
 * @throws ArithmeticException if the new datetime exceeds the capacity
 */
- (HLYearMonthDay*)withField:(HLDurationFieldType*)fieldType 
                addingAmount:(NSInteger)amount;

/**
 * Returns a copy of this date with the specified period added.
 * <p>
 * If the addition is zero, then <code>this</code> is returned.
 * Fields in the period that aren't present in the partial are ignored.
 * <p>
 * This method is typically used to add multiple copies of complex
 * period instances. Adding one field is best achieved using methods
 * like {@link #withFieldAdded(DurationFieldType, int)}
 * or {@link #plusYears(int)}.
 * 
 * @param period  the period to add to this one, nil means zero
 * @param scalar  the amount of times to add, such as -1 to subtract once
 * @return a copy of this instance with the period added
 * @throws ArithmeticException if the new datetime exceeds the capacity
 */
- (HLYearMonthDay*)withPeriod:(id<HLReadablePeriod>)period 
                 addingScalar:(NSInteger)scalar;

//-----------------------------------------------------------------------
/**
 * Returns a copy of this date with the specified period added.
 * <p>
 * If the amount is zero or nil, then <code>this</code> is returned.
 * <p>
 * This method is typically used to add complex period instances.
 * Adding one field is best achieved using methods
 * like {@link #plusYears(int)}.
 * 
 * @param period  the duration to add to this one, nil means zero
 * @return a copy of this instance with the period added
 * @throws ArithmeticException if the new datetime exceeds the capacity of a long
 */
- (HLYearMonthDay*)plusPeriod:(id<HLReadablePeriod>)period;

//-----------------------------------------------------------------------
/**
 * Returns a copy of this date plus the specified number of years.
 * <p>
 * This date instance is immutable and unaffected by this method call.
 * <p>
 * The following three lines are identical in effect:
 * <pre>
 * YearMonthDay added = dt.plusYears(6);
 * YearMonthDay added = dt.plus(Period.years(6));
 * YearMonthDay added = dt.withFieldAdded(DurationFieldType.years(), 6);
 * </pre>
 *
 * @param years  the amount of years to add, may be negative
 * @return the new date plus the increased years
 * @since 1.1
 */
- (HLYearMonthDay*)plusYears:(NSInteger)years;

/**
 * Returns a copy of this date plus the specified number of months.
 * <p>
 * This date instance is immutable and unaffected by this method call.
 * <p>
 * The following three lines are identical in effect:
 * <pre>
 * YearMonthDay added = dt.plusMonths(6);
 * YearMonthDay added = dt.plus(Period.months(6));
 * YearMonthDay added = dt.withFieldAdded(DurationFieldType.months(), 6);
 * </pre>
 *
 * @param months  the amount of months to add, may be negative
 * @return the new date plus the increased months
 * @since 1.1
 */
- (HLYearMonthDay*)plusMonths:(NSInteger)months;

/**
 * Returns a copy of this date plus the specified number of days.
 * <p>
 * This date instance is immutable and unaffected by this method call.
 * <p>
 * The following three lines are identical in effect:
 * <pre>
 * YearMonthDay added = dt.plusDays(6);
 * YearMonthDay added = dt.plus(Period.days(6));
 * YearMonthDay added = dt.withFieldAdded(DurationFieldType.days(), 6);
 * </pre>
 *
 * @param days  the amount of days to add, may be negative
 * @return the new date plus the increased days
 * @since 1.1
 */
- (HLYearMonthDay*)plusDays:(NSInteger)days;

//-----------------------------------------------------------------------
/**
 * Returns a copy of this date with the specified period taken away.
 * <p>
 * If the amount is zero or nil, then <code>this</code> is returned.
 * <p>
 * This method is typically used to subtract complex period instances.
 * Subtracting one field is best achieved using methods
 * like {@link #minusYears(int)}.
 * 
 * @param period  the period to reduce this instant by
 * @return a copy of this instance with the period taken away
 * @throws ArithmeticException if the new datetime exceeds the capacity of a long
 */
- (HLYearMonthDay*)minusPeriod:(id<HLReadablePeriod>)period;

//-----------------------------------------------------------------------
/**
 * Returns a copy of this date minus the specified number of years.
 * <p>
 * This datetime instance is immutable and unaffected by this method call.
 * <p>
 * The following three lines are identical in effect:
 * <pre>
 * YearMonthDay subtracted = dt.minusYears(6);
 * YearMonthDay subtracted = dt.minus(Period.years(6));
 * YearMonthDay subtracted = dt.withFieldAdded(DurationFieldType.years(), -6);
 * </pre>
 *
 * @param years  the amount of years to subtract, may be negative
 * @return the new datetime minus the increased years
 * @since 1.1
 */
- (HLYearMonthDay*)minusYears:(NSInteger)years;

/**
 * Returns a copy of this date minus the specified number of months.
 * <p>
 * This datetime instance is immutable and unaffected by this method call.
 * <p>
 * The following three lines are identical in effect:
 * <pre>
 * YearMonthDay subtracted = dt.minusMonths(6);
 * YearMonthDay subtracted = dt.minus(Period.months(6));
 * YearMonthDay subtracted = dt.withFieldAdded(DurationFieldType.months(), -6);
 * </pre>
 *
 * @param months  the amount of months to subtract, may be negative
 * @return the new datetime minus the increased months
 * @since 1.1
 */
- (HLYearMonthDay*)minusMonths:(NSInteger)months;

/**
 * Returns a copy of this date minus the specified number of days.
 * <p>
 * This datetime instance is immutable and unaffected by this method call.
 * <p>
 * The following three lines are identical in effect:
 * <pre>
 * YearMonthDay subtracted = dt.minusDays(6);
 * YearMonthDay subtracted = dt.minus(Period.days(6));
 * YearMonthDay subtracted = dt.withFieldAdded(DurationFieldType.days(), -6);
 * </pre>
 *
 * @param days  the amount of days to subtract, may be negative
 * @return the new datetime minus the increased days
 * @since 1.1
 */
- (HLYearMonthDay*)minusDays:(NSInteger)days;

//-----------------------------------------------------------------------
/**
 * Gets the property object for the specified type, which contains
 * many useful methods.
 *
 * @param type  the field type to get the property for
 * @return the property object
 * @throws IllegalArgumentException if the field is nil or unsupported
 */
- (HLProperty*)property:(HLDateTimeFieldType*)type;

//-----------------------------------------------------------------------
/**
 * Converts this object to a LocalDate with the same date and chronology.
 *
 * @return a LocalDate with the same date and chronology
 * @since 1.3
 */
- (HLLocalDate*)toLocalDate;

//-----------------------------------------------------------------------
/**
 * Converts this YearMonthDay to a full datetime at midnight using the
 * default time zone.
 *
 * @return this date as a datetime at midnight
 */
- (HLDateTime*)toDateTimeAtMidnight;

/**
 * Converts this YearMonthDay to a full datetime at midnight using the
 * specified time zone.
 * <p>
 * This method uses the chronology from this instance plus the time zone
 * specified.
 *
 * @param zone  the zone to use, nil means default
 * @return this date as a datetime at midnight
 */
- (HLDateTime*)toDateTimeAtMidnight:(HLDateTimeZone*)zone;

//-----------------------------------------------------------------------
/**
 * Converts this partial to a full datetime using the default time zone
 * setting the date fields from this instance and the time fields from
 * the current time.
 *
 * @return this date as a datetime with the time as the current time
 */
- (HLDateTime*)toDateTimeAtCurrentTime;

/**
 * Converts this partial to a full datetime using the specified time zone
 * setting the date fields from this instance and the time fields from
 * the current time.
 * <p>
 * This method uses the chronology from this instance plus the time zone
 * specified.
 *
 * @param zone  the zone to use, nil means default
 * @return this date as a datetime with the time as the current time
 */
- (HLDateTime*)toDateTimeAtCurrentTime:(HLDateTimeZone*)zone;

//-----------------------------------------------------------------------
/**
 * Converts this object to a DateMidnight in the default time zone.
 *
 * @return the DateMidnight instance in the default zone
 */
- (HLDateMidnight*)toDateMidnight;

/**
 * Converts this object to a DateMidnight.
 *
 * @param zone  the zone to get the DateMidnight in, nil means default
 * @return the DateMidnight instance
 */
- (HLDateMidnight*)toDateMidnightWithDateTimeZone:(HLDateTimeZone*)zone;

//-----------------------------------------------------------------------
/**
 * Converts this object to a DateTime using a TimeOfDay to fill in the
 * missing fields and using the default time zone.
 * This instance is immutable and unaffected by this method call.
 * <p>
 * The resulting chronology is determined by the chronology of this
 * YearMonthDay plus the time zone.
 * The chronology of the time is ignored - only the field values are used.
 *
 * @param time  the time of day to use, nil means current time
 * @return the DateTime instance
 */
- (HLDateTime*)toDateTime:(HLTimeOfDay*)time;

/**
 * Converts this object to a DateTime using a TimeOfDay to fill in the
 * missing fields.
 * This instance is immutable and unaffected by this method call.
 * <p>
 * The resulting chronology is determined by the chronology of this
 * YearMonthDay plus the time zone.
 * The chronology of the time is ignored - only the field values are used.
 *
 * @param time  the time of day to use, nil means current time
 * @param zone  the zone to get the DateTime in, nil means default
 * @return the DateTime instance
 */
- (HLDateTime*)toDateTime:(HLTimeOfDay*)time
             dateTimeZone:(HLDateTimeZone*)zone;

//-----------------------------------------------------------------------
/**
 * Converts this object to an Interval representing the whole day
 * in the default time zone.
 *
 * @return a interval over the day
 */
- (HLInterval*)toInterval;

/**
 * Converts this object to an Interval representing the whole day.
 *
 * @param zone  the zone to get the Interval in, nil means default
 * @return a interval over the day
 */
- (HLInterval*)toInterval:(HLDateTimeZone*)zone;

//-----------------------------------------------------------------------
/**
 * Get the year field value.
 *
 * @return the year
 */
- (NSInteger)year;

/**
 * Get the month of year field value.
 *
 * @return the month of year
 */
- (NSInteger)monthOfYear;

/**
 * Get the day of month field value.
 *
 * @return the day of month
 */
- (NSInteger)dayOfMonth;

//-----------------------------------------------------------------------
/**
 * Returns a copy of this date with the year field updated.
 * <p>
 * YearMonthDay is immutable, so there are no set methods.
 * Instead, this method returns a new instance with the value of
 * year changed.
 *
 * @param year  the year to set
 * @return a copy of this object with the field set
 * @throws IllegalArgumentException if the value is invalid
 * @since 1.3
 */
- (HLYearMonthDay*)withYear:(NSInteger)year;

/**
 * Returns a copy of this date with the month of year field updated.
 * <p>
 * YearMonthDay is immutable, so there are no set methods.
 * Instead, this method returns a new instance with the value of
 * month of year changed.
 *
 * @param monthOfYear  the month of year to set
 * @return a copy of this object with the field set
 * @throws IllegalArgumentException if the value is invalid
 * @since 1.3
 */
- (HLYearMonthDay*)withMonthOfYear:(NSInteger)monthOfYear;

/**
 * Returns a copy of this date with the day of month field updated.
 * <p>
 * YearMonthDay is immutable, so there are no set methods.
 * Instead, this method returns a new instance with the value of
 * day of month changed.
 *
 * @param dayOfMonth  the day of month to set
 * @return a copy of this object with the field set
 * @throws IllegalArgumentException if the value is invalid
 * @since 1.3
 */
- (HLYearMonthDay*)withDayOfMonth:(NSInteger)dayOfMonth;

//-----------------------------------------------------------------------
/**
 * Get the year field property which provides access to advanced functionality.
 * 
 * @return the year property
 */
- (HLYearMonthDayProperty*)yearProperty;

/**
 * Get the month of year field property which provides access to advanced functionality.
 * 
 * @return the month of year property
 */
- (HLYearMonthDayProperty*)monthOfYearProperty;

/**
 * Get the day of month field property which provides access to advanced functionality.
 * 
 * @return the day of month property
 */
- (HLYearMonthDayProperty*)dayOfMonthProperty;

@end


//-----------------------------------------------------------------------
/**
 * The property class for <code>YearMonthDay</code>.
 * <p>
 * This class binds a <code>YearMonthDay</code> to a <code>DateTimeField</code>.
 * 
 * @author Stephen Colebourne
 * @since 1.0
 * @deprecated Use LocalDate which has a much better internal implementation
 */
@interface HLYearMonthDayProperty : HLAbstractPartialFieldProperty {
    
@private
    /** The partial */
    HLYearMonthDay* _iYearMonthDay;
    /** The field index */
    NSInteger _iFieldIndex;
    
}

/**
 * Constructs a property.
 * 
 * @param partial  the partial instance
 * @param fieldIndex  the index in the partial
 */
- (id)initWithPartial:(HLYearMonthDay*)partial 
           fieldIndex:(NSInteger)fieldIndex;

/**
 * Gets the field that this property uses.
 * 
 * @return the field
 */
- (HLDateTimeField*)field;

/**
 * Gets the partial that this property belongs to.
 * 
 * @return the partial
 */
- (id<HLReadablePartial>)readablePartial;

/**
 * Gets the partial that this property belongs to.
 * 
 * @return the partial
 */
- (HLYearMonthDay*)yearMonthDay;

/**
 * Gets the value of this field.
 * 
 * @return the field value
 */
- (NSInteger)value;

//-----------------------------------------------------------------------
/**
 * Adds to the value of this field in a copy of this YearMonthDay.
 * <p>
 * The value will be added to this field. If the value is too large to be
 * added solely to this field then it will affect larger fields.
 * Smaller fields are unaffected.
 * <p>
 * If the result would be too large, beyond the maximum year, then an
 * IllegalArgumentException is thrown.
 * <p>
 * The YearMonthDay attached to this property is unchanged by this call.
 * Instead, a new instance is returned.
 * 
 * @param valueToAdd  the value to add to the field in the copy
 * @return a copy of the YearMonthDay with the field value changed
 * @throws IllegalArgumentException if the value isn't valid
 */
- (HLYearMonthDay*)addToCopy:(NSInteger)valueToAdd;

/**
 * Adds to the value of this field in a copy of this YearMonthDay wrapping
 * within this field if the maximum value is reached.
 * <p>
 * The value will be added to this field. If the value is too large to be
 * added solely to this field then it wraps within this field.
 * Other fields are unaffected.
 * <p>
 * For example,
 * <code>2004-12-20</code> addWrapField one month returns <code>2004-01-20</code>.
 * <p>
 * The YearMonthDay attached to this property is unchanged by this call.
 * Instead, a new instance is returned.
 * 
 * @param valueToAdd  the value to add to the field in the copy
 * @return a copy of the YearMonthDay with the field value changed
 * @throws IllegalArgumentException if the value isn't valid
 */
- (HLYearMonthDay*)addWrapFieldToCopy:(NSInteger)valueToAdd;

//-----------------------------------------------------------------------
/**
 * Sets this field in a copy of the YearMonthDay.
 * <p>
 * The YearMonthDay attached to this property is unchanged by this call.
 * Instead, a new instance is returned.
 * 
 * @param value  the value to set the field in the copy to
 * @return a copy of the YearMonthDay with the field value changed
 * @throws IllegalArgumentException if the value isn't valid
 */
- (HLYearMonthDay*)setCopyWithValue:(NSInteger)value;

/**
 * Sets this field in a copy of the YearMonthDay to a parsed text value.
 * <p>
 * The YearMonthDay attached to this property is unchanged by this call.
 * Instead, a new instance is returned.
 * 
 * @param text  the text value to set
 * @param locale  optional locale to use for selecting a text symbol
 * @return a copy of the YearMonthDay with the field value changed
 * @throws IllegalArgumentException if the text value isn't valid
 */
- (HLYearMonthDay*)setCopyWithText:(NSString*)text 
                            locale:(NSLocale*)locale;

/**
 * Sets this field in a copy of the YearMonthDay to a parsed text value.
 * <p>
 * The YearMonthDay attached to this property is unchanged by this call.
 * Instead, a new instance is returned.
 * 
 * @param text  the text value to set
 * @return a copy of the YearMonthDay with the field value changed
 * @throws IllegalArgumentException if the text value isn't valid
 */
- (HLYearMonthDay*)setCopyWithText:(NSString*)text;

//-----------------------------------------------------------------------
/**
 * Returns a new YearMonthDay with this field set to the maximum value
 * for this field.
 * <p>
 * This operation is useful for obtaining a DateTime on the last day
 * of the month, as month lengths vary.
 * <pre>
 * YearMonthDay lastDayOfMonth = dt.dayOfMonth().withMaximumValue();
 * </pre>
 * <p>
 * The YearMonthDay attached to this property is unchanged by this call.
 *
 * @return a copy of the YearMonthDay with this field set to its maximum
 * @since 1.2
 */
- (HLYearMonthDay*)withMaximumValue;

/**
 * Returns a new YearMonthDay with this field set to the minimum value
 * for this field.
 * <p>
 * The YearMonthDay attached to this property is unchanged by this call.
 *
 * @return a copy of the YearMonthDay with this field set to its minimum
 * @since 1.2
 */
- (HLYearMonthDay*)withMinimumValue;

@end
