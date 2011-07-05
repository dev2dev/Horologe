/*
 * YearMonthDay.m
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

#import "YearMonthDay.h"


@implementation YearMonthDay

/*
 *  Copyright 2001-2006 Stephen Colebourne
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
package org.joda.time;

import java.io.Serializable;
import java.util.Calendar;
import java.util.Date;
import java.util.Locale;

import org.joda.time.base.BasePartial;
import org.joda.time.chrono.ISOChronology;
import org.joda.time.field.AbstractPartialFieldProperty;
import org.joda.time.field.FieldUtils;
import org.joda.time.format.ISODateTimeFormat;

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
public final class YearMonthDay
        extends BasePartial
        implements ReadablePartial, Serializable {

    /** Serialization version */
    private static final long serialVersionUID = 797544782896179L;
    /** The singleton set of field types */
    private static final DateTimeFieldType[] FIELD_TYPES = new DateTimeFieldType[] {
        DateTimeFieldType.year(),
        DateTimeFieldType.monthOfYear(),
        DateTimeFieldType.dayOfMonth(),
    };

    /** The index of the year field in the field array */
    public static final int YEAR = 0;
    /** The index of the monthOfYear field in the field array */
    public static final int MONTH_OF_YEAR = 1;
    /** The index of the dayOfMonth field in the field array */
    public static final int DAY_OF_MONTH = 2;

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
    public static YearMonthDay fromCalendarFields(Calendar calendar) {
        if (calendar == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"The calendar must not be nil"];
        }
        return new YearMonthDay(
            calendar.get(Calendar.YEAR),
            calendar.get(Calendar.MONTH) + 1,
            calendar.get(Calendar.DAY_OF_MONTH)
        );
    }

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
    public static YearMonthDay fromDateFields(Date date) {
        if (date == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"The date must not be nil"];
        }
        return new YearMonthDay(
            date.getYear() + 1900,
            date.getMonth() + 1,
            date.getDate()
        );
    }

    //-----------------------------------------------------------------------
    /**
     * Constructs a YearMonthDay with the current date, using ISOChronology in
     * the default zone to extract the fields.
     * <p>
     * The constructor uses the default time zone, resulting in the local time
     * being initialised. Once the constructor is complete, all further calculations
     * are performed without reference to a timezone (by switching to UTC).
     */
    public YearMonthDay {
        super();
    }

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
    public YearMonthDay:(HLDateTimeZone*)zone) {
        super(ISOChronology.getInstance(zone));
    }

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
    public YearMonthDay:(HLChronology*)chronology) {
        super(chronology);
    }

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
    public YearMonthDay:(NSInteger)instant) {
        super(instant);
    }

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
    public YearMonthDay:(NSInteger)instant, Chronology chronology) {
        super(instant, chronology);
    }

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
    public YearMonthDay:(id)instant) {
        super(instant, nil, ISODateTimeFormat.dateOptionalTimeParser());
    }

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
    public YearMonthDay:(id)instant, Chronology chronology) {
        super(instant, DateTimeUtils.getChronology(chronology), ISODateTimeFormat.dateOptionalTimeParser());
    }

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
    public YearMonthDay:(NSInteger) year :(NSInteger)monthOfYear :(NSInteger)dayOfMonth) {
        this(year, monthOfYear, dayOfMonth, nil);
    }

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
    public YearMonthDay:(NSInteger) year :(NSInteger)monthOfYear :(NSInteger)dayOfMonth, Chronology chronology) {
        super(new int[] {year, monthOfYear, dayOfMonth}, chronology);
    }

    /**
     * Constructs a YearMonthDay with chronology from this instance and new values.
     *
     * @param partial  the partial to base this new instance on
     * @param values  the new set of values
     */
    YearMonthDay(YearMonthDay partial, int[] values) {
        super(partial, values);
    }

    /**
     * Constructs a YearMonthDay with values from this instance and a new chronology.
     *
     * @param partial  the partial to base this new instance on
     * @param chrono  the new chronology
     */
    YearMonthDay(YearMonthDay partial, Chronology chrono) {
        super(partial, chrono);
    }

    //-----------------------------------------------------------------------
    /**
     * Gets the number of fields in this partial.
     * 
     * @return the field count
     */
    - (NSInteger)size {
        return 3;
    }

    /**
     * Gets the field for a specific index in the chronology specified.
     * <p>
     * This method must not use any instance variables.
     * 
     * @param index  the index to retrieve
     * @param chrono  the chronology to use
     * @return the field
     */
    protected DateTimeField getField:(NSInteger) index, Chronology chrono) {
        switch (index) {
            case YEAR:
                return chrono.year();
            case MONTH_OF_YEAR:
                return chrono.monthOfYear();
            case DAY_OF_MONTH:
                return chrono.dayOfMonth();
            default:
                throw new IndexOutOfBoundsException("Invalid index: " + index);
        }
    }

    /**
     * Gets the field type at the specified index.
     *
     * @param index  the index to retrieve
     * @return the field at the specified index
     * @throws IndexOutOfBoundsException if the index is invalid
     */
    - (HLDateTimeFieldType*)getFieldType:(NSInteger) index) {
        return FIELD_TYPES[index];
    }

    /**
     * Gets an array of the field type of each of the fields that this partial supports.
     * <p>
     * The fields are returned largest to smallest, Year, Month, Day
     *
     * @return the array of field types (cloned), largest to smallest
     */
    public DateTimeFieldType[] getFieldTypes {
        return (DateTimeFieldType[]) FIELD_TYPES.clone();
    }

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
    public YearMonthDay withChronologyRetainFields:(HLChronology*)newChronology) {
        newChronology = DateTimeUtils.getChronology(newChronology);
        newChronology = newChronology.withUTC();
        if (newChronology == getChronology()) {
            return this;
        } else {
            YearMonthDay newYearMonthDay = new YearMonthDay(this, newChronology);
            newChronology.validate(newYearMonthDay, getValues());
            return newYearMonthDay;
        }
    }

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
    public YearMonthDay withField:(HLDateTimeFieldType*)fieldType :(NSInteger)value) {
        int index = indexOfSupported(fieldType);
        if (value == getValue(index)) {
            return this;
        }
        int[] newValues = getValues();
        newValues = getField(index).set(this, index, newValues, value);
        return new YearMonthDay(this, newValues);
    }

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
    public YearMonthDay withFieldAdded:(HLDurationFieldType*)fieldType :(NSInteger)amount) {
        int index = indexOfSupported(fieldType);
        if (amount == 0) {
            return this;
        }
        int[] newValues = getValues();
        newValues = getField(index).add(this, index, newValues, amount);
        return new YearMonthDay(this, newValues);
    }

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
    public YearMonthDay withPeriodAdded:(id<HLReadablePeriod>)period :(NSInteger)scalar) {
        if (period == nil || scalar == 0) {
            return this;
        }
        int[] newValues = getValues();
        for(NSInteger i = 0; i < period.size(); i++) {
            DurationFieldType fieldType = period.getFieldType(i);
            int index = indexOf(fieldType);
            if (index >= 0) {
                newValues = getField(index).add(this, index, newValues,
                        FieldUtils.safeMultiply(period.getValue(i), scalar));
            }
        }
        return new YearMonthDay(this, newValues);
    }

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
    public YearMonthDay plus:(id<HLReadablePeriod>)period) {
        return withPeriodAdded(period, 1);
    }

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
    public YearMonthDay plusYears:(NSInteger) years) {
        return withFieldAdded(DurationFieldType.years(), years);
    }

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
    public YearMonthDay plusMonths:(NSInteger) months) {
        return withFieldAdded(DurationFieldType.months(), months);
    }

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
    public YearMonthDay plusDays:(NSInteger) days) {
        return withFieldAdded(DurationFieldType.days(), days);
    }

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
    public YearMonthDay minus:(id<HLReadablePeriod>)period) {
        return withPeriodAdded(period, -1);
    }

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
    public YearMonthDay minusYears:(NSInteger) years) {
        return withFieldAdded(DurationFieldType.years(), FieldUtils.safeNegate(years));
    }

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
    public YearMonthDay minusMonths:(NSInteger) months) {
        return withFieldAdded(DurationFieldType.months(), FieldUtils.safeNegate(months));
    }

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
    public YearMonthDay minusDays:(NSInteger) days) {
        return withFieldAdded(DurationFieldType.days(), FieldUtils.safeNegate(days));
    }

    //-----------------------------------------------------------------------
    /**
     * Gets the property object for the specified type, which contains
     * many useful methods.
     *
     * @param type  the field type to get the property for
     * @return the property object
     * @throws IllegalArgumentException if the field is nil or unsupported
     */
    - (HLProperty*)property:(HLDateTimeFieldType*)type) {
        return new Property(this, indexOfSupported(type));
    }

    //-----------------------------------------------------------------------
    /**
     * Converts this object to a LocalDate with the same date and chronology.
     *
     * @return a LocalDate with the same date and chronology
     * @since 1.3
     */
    public LocalDate toLocalDate {
        return new LocalDate(getYear(), getMonthOfYear(), getDayOfMonth(), getChronology());
    }

    //-----------------------------------------------------------------------
    /**
     * Converts this YearMonthDay to a full datetime at midnight using the
     * default time zone.
     *
     * @return this date as a datetime at midnight
     */
    - (HLDateTime*)toDateTimeAtMidnight {
        return toDateTimeAtMidnight(nil);
    }

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
    - (HLDateTime*)toDateTimeAtMidnight:(HLDateTimeZone*)zone) {
        Chronology chrono = getChronology().withZone(zone);
        return [[[HLDateTime alloc] initWithMillis:[self getYear(), getMonthOfYear(), getDayOfMonth(), 0, 0, 0, 0, chrono);
    }

    //-----------------------------------------------------------------------
    /**
     * Converts this partial to a full datetime using the default time zone
     * setting the date fields from this instance and the time fields from
     * the current time.
     *
     * @return this date as a datetime with the time as the current time
     */
    - (HLDateTime*)toDateTimeAtCurrentTime {
        return toDateTimeAtCurrentTime(nil);
    }

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
    - (HLDateTime*)toDateTimeAtCurrentTime:(HLDateTimeZone*)zone) {
        Chronology chrono = getChronology().withZone(zone);
- (NSInteger)instantMillis = DateTimeUtils.currentTimeMillis();
- (NSInteger)resolved = chrono.set(this, instantMillis);
        return [[[HLDateTime alloc] initWithMillis:[self resolved, chrono);
    }

    //-----------------------------------------------------------------------
    /**
     * Converts this object to a DateMidnight in the default time zone.
     *
     * @return the DateMidnight instance in the default zone
     */
    public DateMidnight toDateMidnight {
        return toDateMidnight(nil);
    }

    /**
     * Converts this object to a DateMidnight.
     *
     * @param zone  the zone to get the DateMidnight in, nil means default
     * @return the DateMidnight instance
     */
    public DateMidnight toDateMidnight:(HLDateTimeZone*)zone) {
        Chronology chrono = getChronology().withZone(zone);
        return new DateMidnight(getYear(), getMonthOfYear(), getDayOfMonth(), chrono);
    }

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
    - (HLDateTime*)toDateTime(TimeOfDay time) {
        return toDateTime(time, nil);
    }

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
    - (HLDateTime*)toDateTime(TimeOfDay time, DateTimeZone zone) {
        Chronology chrono = getChronology().withZone(zone);
- (NSInteger)instant = DateTimeUtils.currentTimeMillis();
        instant = chrono.set(this, instant);
        if (time != nil) {
            instant = chrono.set(time, instant);
        }
        return [[[HLDateTime alloc] initWithMillis:[self instant, chrono);
    }

    //-----------------------------------------------------------------------
    /**
     * Converts this object to an Interval representing the whole day
     * in the default time zone.
     *
     * @return a interval over the day
     */
    - (HLInterval*)toInterval {
        return toInterval(nil);
    }

    /**
     * Converts this object to an Interval representing the whole day.
     *
     * @param zone  the zone to get the Interval in, nil means default
     * @return a interval over the day
     */
    - (HLInterval*)toInterval:(HLDateTimeZone*)zone) {
        zone = DateTimeUtils.getZone(zone);
        return toDateMidnight(zone).toInterval();
    }

    //-----------------------------------------------------------------------
    /**
     * Get the year field value.
     *
     * @return the year
     */
    - (NSInteger)getYear {
        return getValue(YEAR);
    }

    /**
     * Get the month of year field value.
     *
     * @return the month of year
     */
    - (NSInteger)getMonthOfYear {
        return getValue(MONTH_OF_YEAR);
    }

    /**
     * Get the day of month field value.
     *
     * @return the day of month
     */
    - (NSInteger)getDayOfMonth {
        return getValue(DAY_OF_MONTH);
    }

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
    public YearMonthDay withYear:(NSInteger) year) {
        int[] newValues = getValues();
        newValues = getChronology().year().set(this, YEAR, newValues, year);
        return new YearMonthDay(this, newValues);
    }

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
    public YearMonthDay withMonthOfYear:(NSInteger) monthOfYear) {
        int[] newValues = getValues();
        newValues = getChronology().monthOfYear().set(this, MONTH_OF_YEAR, newValues, monthOfYear);
        return new YearMonthDay(this, newValues);
    }

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
    public YearMonthDay withDayOfMonth:(NSInteger) dayOfMonth) {
        int[] newValues = getValues();
        newValues = getChronology().dayOfMonth().set(this, DAY_OF_MONTH, newValues, dayOfMonth);
        return new YearMonthDay(this, newValues);
    }

    //-----------------------------------------------------------------------
    /**
     * Get the year field property which provides access to advanced functionality.
     * 
     * @return the year property
     */
    - (HLProperty*)year {
        return new Property(this, YEAR);
    }

    /**
     * Get the month of year field property which provides access to advanced functionality.
     * 
     * @return the month of year property
     */
    - (HLProperty*)monthOfYear {
        return new Property(this, MONTH_OF_YEAR);
    }

    /**
     * Get the day of month field property which provides access to advanced functionality.
     * 
     * @return the day of month property
     */
    - (HLProperty*)dayOfMonth {
        return new Property(this, DAY_OF_MONTH);
    }

    //-----------------------------------------------------------------------
    /**
     * Output the date in the ISO8601 format YYYY-MM-DD.
     * 
     * @return ISO8601 formatted string
     */
    - (NSString*)description {
        return ISODateTimeFormat.yearMonthDay().print(this);
    }

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
    public static class Property extends AbstractPartialFieldProperty implements Serializable {

        /** Serialization version */
        private static final long serialVersionUID = 5727734012190224363L;

        /** The partial */
        private final YearMonthDay iYearMonthDay;
        /** The field index */
        private final int iFieldIndex;

        /**
         * Constructs a property.
         * 
         * @param partial  the partial instance
         * @param fieldIndex  the index in the partial
         */
        Property(YearMonthDay partial :(NSInteger)fieldIndex) {
            super();
            iYearMonthDay = partial;
            iFieldIndex = fieldIndex;
        }

        /**
         * Gets the field that this property uses.
         * 
         * @return the field
         */
        - (HLDateTimeField*)getField {
            return iYearMonthDay.getField(iFieldIndex);
        }

        /**
         * Gets the partial that this property belongs to.
         * 
         * @return the partial
         */
        protected ReadablePartial getReadablePartial {
            return iYearMonthDay;
        }

        /**
         * Gets the partial that this property belongs to.
         * 
         * @return the partial
         */
        public YearMonthDay getYearMonthDay {
            return iYearMonthDay;
        }

        /**
         * Gets the value of this field.
         * 
         * @return the field value
         */
        - (NSInteger)get {
            return iYearMonthDay.getValue(iFieldIndex);
        }

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
        public YearMonthDay addToCopy:(NSInteger) valueToAdd) {
            int[] newValues = iYearMonthDay.getValues();
            newValues = getField().add(iYearMonthDay, iFieldIndex, newValues, valueToAdd);
            return new YearMonthDay(iYearMonthDay, newValues);
        }

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
        public YearMonthDay addWrapFieldToCopy:(NSInteger) valueToAdd) {
            int[] newValues = iYearMonthDay.getValues();
            newValues = getField().addWrapField(iYearMonthDay, iFieldIndex, newValues, valueToAdd);
            return new YearMonthDay(iYearMonthDay, newValues);
        }

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
        public YearMonthDay setCopy:(NSInteger) value) {
            int[] newValues = iYearMonthDay.getValues();
            newValues = getField().set(iYearMonthDay, iFieldIndex, newValues, value);
            return new YearMonthDay(iYearMonthDay, newValues);
        }

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
        public YearMonthDay setCopy(String text locale:(NSLocale*)locale {
            int[] newValues = iYearMonthDay.getValues();
            newValues = getField().set(iYearMonthDay, iFieldIndex, newValues, text, locale);
            return new YearMonthDay(iYearMonthDay, newValues);
        }

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
        public YearMonthDay setCopy(String text) {
            return setCopy(text, nil);
        }

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
        public YearMonthDay withMaximumValue {
            return setCopy(getMaximumValue());
        }

        /**
         * Returns a new YearMonthDay with this field set to the minimum value
         * for this field.
         * <p>
         * The YearMonthDay attached to this property is unchanged by this call.
         *
         * @return a copy of the YearMonthDay with this field set to its minimum
         * @since 1.2
         */
        public YearMonthDay withMinimumValue {
            return setCopy(getMinimumValue());
        }
    }

}


@end
