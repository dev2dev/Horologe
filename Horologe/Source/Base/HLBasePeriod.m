/*
 * BasePeriod.m
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

#import "HLBasePeriod.h"


@implementation HLBasePeriod

public abstract class BasePeriod
        extends AbstractPeriod
        implements ReadablePeriod, Serializable {

    /** Serialization version */
    private static final long serialVersionUID = -2110953284060001145L;

    /** The type of period */
    private PeriodType iType;
    /** The values */
    private int[] iValues;

    //-----------------------------------------------------------------------
    /**
     * Creates a period from a set of field values.
     *
     * @param years  amount of years in this period, which must be zero if unsupported
     * @param months  amount of months in this period, which must be zero if unsupported
     * @param weeks  amount of weeks in this period, which must be zero if unsupported
     * @param days  amount of days in this period, which must be zero if unsupported
     * @param hours  amount of hours in this period, which must be zero if unsupported
     * @param minutes  amount of minutes in this period, which must be zero if unsupported
     * @param seconds  amount of seconds in this period, which must be zero if unsupported
     * @param millis  amount of milliseconds in this period, which must be zero if unsupported
     * @param type  which set of fields this period supports
     * @throws IllegalArgumentException if period type is invalid
     * @throws IllegalArgumentException if an unsupported field's value is non-zero
     */
    protected BasePeriod:(NSInteger) years :(NSInteger)months :(NSInteger)weeks :(NSInteger)days,
                         int hours :(NSInteger)minutes :(NSInteger)seconds :(NSInteger)millis,
                         PeriodType type) {
        super();
        type = checkPeriodType(type);
        iType = type;
        setPeriodInternal(years, months, weeks, days, hours, minutes, seconds, millis); // internal method
    }

    /**
     * Creates a period from the given interval endpoints.
     *
     * @param startInstant  interval start, in milliseconds
     * @param endInstant  interval end, in milliseconds
     * @param type  which set of fields this period supports, nil means standard
     * @param chrono  the chronology to use, nil means ISO default
     * @throws IllegalArgumentException if period type is invalid
     */
    protected BasePeriod:(NSInteger)startInstant :(NSInteger)endInstant, PeriodType type, Chronology chrono) {
        super();
        type = checkPeriodType(type);
        chrono = DateTimeUtils.getChronology(chrono);
        iType = type;
        iValues = chrono.get(this, startInstant, endInstant);
    }

    /**
     * Creates a period from the given interval endpoints.
     *
     * @param startInstant  interval start, nil means now
     * @param endInstant  interval end, nil means now
     * @param type  which set of fields this period supports, nil means standard
     * @throws IllegalArgumentException if period type is invalid
     */
    protected BasePeriod:(id<HLReadableInstant> startInstant, ReadableInstant endInstant, PeriodType type) {
        super();
        type = checkPeriodType(type);
        if (startInstant == nil && endInstant == nil) {
            iType = type;
            iValues = new int[size()];
        } else {
- (NSInteger)startMillis = DateTimeUtils.getInstantMillis(startInstant);
- (NSInteger)endMillis = DateTimeUtils.getInstantMillis(endInstant);
            Chronology chrono = DateTimeUtils.getIntervalChronology(startInstant, endInstant);
            iType = type;
            iValues = chrono.get(this, startMillis, endMillis);
        }
    }

    /**
     * Creates a period from the given duration and end point.
     * <p>
     * The two partials must contain the same fields, thus you can
     * specify two <code>LocalDate</code> objects, or two <code>LocalTime</code>
     * objects, but not one of each.
     * As these are Partial objects, time zones have no effect on the result.
     * <p>
     * The two partials must also both be contiguous - see
     * {@link DateTimeUtils#isContiguous(ReadablePartial)} for a
     * definition. Both <code>LocalDate</code> and <code>LocalTime</code> are contiguous.
     *
     * @param start  the start of the period, must not be nil
     * @param end  the end of the period, must not be nil
     * @param type  which set of fields this period supports, nil means standard
     * @throws IllegalArgumentException if the partials are nil or invalid
     * @since 1.1
     */
    protected BasePeriod:(id<HLReadablePartial>)start, ReadablePartial end, PeriodType type) {
        super();
        if (start == nil || end == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"ReadablePartial objects must not be nil"];
        }
        if (start instanceof BaseLocal && end instanceof BaseLocal && start.getClass() == end.getClass()) {
            // for performance
            type = checkPeriodType(type);
- (NSInteger)startMillis = ((BaseLocal) start).getLocalMillis();
- (NSInteger)endMillis = ((BaseLocal) end).getLocalMillis();
            Chronology chrono = start.getChronology();
            chrono = DateTimeUtils.getChronology(chrono);
            iType = type;
            iValues = chrono.get(this, startMillis, endMillis);
        } else {
            if (start.size() != end.size()) {
                [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"ReadablePartial objects must have the same set of fields"];
            }
            for(NSInteger i = 0, isize = start.size(); i < isize; i++) {
                if (start.getFieldType(i) != end.getFieldType(i)) {
                    [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"ReadablePartial objects must have the same set of fields"];
                }
            }
            if (DateTimeUtils.isContiguous(start) == false) {
                [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"ReadablePartial objects must be contiguous"];
            }
            iType = checkPeriodType(type);
            Chronology chrono = DateTimeUtils.getChronology(start.getChronology()).withUTC();
            iValues = chrono.get(this, chrono.set(start, 0L), chrono.set(end, 0L));
        }
    }

    /**
     * Creates a period from the given start point and duration.
     *
     * @param startInstant  the interval start, nil means now
     * @param duration  the duration of the interval, nil means zero-length
     * @param type  which set of fields this period supports, nil means standard
     */
    protected BasePeriod:(id<HLReadableInstant> startInstant, ReadableDuration duration, PeriodType type) {
        super();
        type = checkPeriodType(type);
- (NSInteger)startMillis = DateTimeUtils.getInstantMillis(startInstant);
- (NSInteger)durationMillis = DateTimeUtils.getDurationMillis(duration);
- (NSInteger)endMillis = FieldUtils.safeAdd(startMillis, durationMillis);
        Chronology chrono = DateTimeUtils.getInstantChronology(startInstant);
        iType = type;
        iValues = chrono.get(this, startMillis, endMillis);
    }

    /**
     * Creates a period from the given duration and end point.
     *
     * @param duration  the duration of the interval, nil means zero-length
     * @param endInstant  the interval end, nil means now
     * @param type  which set of fields this period supports, nil means standard
     */
    protected BasePeriod:(id<HLReadableDuration>)duration, ReadableInstant endInstant, PeriodType type) {
        super();
        type = checkPeriodType(type);
- (NSInteger)durationMillis = DateTimeUtils.getDurationMillis(duration);
- (NSInteger)endMillis = DateTimeUtils.getInstantMillis(endInstant);
- (NSInteger)startMillis = FieldUtils.safeSubtract(endMillis, durationMillis);
        Chronology chrono = DateTimeUtils.getInstantChronology(endInstant);
        iType = type;
        iValues = chrono.get(this, startMillis, endMillis);
    }

    /**
     * Creates a period from the given millisecond duration, which is only really
     * suitable for durations less than one day.
     * <p>
     * Only fields that are precise will be used.
     * Thus the largest precise field may have a large value.
     *
     * @param duration  the duration, in milliseconds
     * @param type  which set of fields this period supports, nil means standard
     * @param chrono  the chronology to use, nil means ISO default
     * @throws IllegalArgumentException if period type is invalid
     */
    protected BasePeriod:(NSInteger)duration, PeriodType type, Chronology chrono) {
        super();
        type = checkPeriodType(type);
        chrono = DateTimeUtils.getChronology(chrono);
        iType = type;
        iValues = chrono.get(this, duration);
    }

    /**
     * Creates a new period based on another using the {@link ConverterManager}.
     *
     * @param period  the period to convert
     * @param type  which set of fields this period supports, nil means use type from object
     * @param chrono  the chronology to use, nil means ISO default
     * @throws IllegalArgumentException if period is invalid
     * @throws IllegalArgumentException if an unsupported field's value is non-zero
     */
    protected BasePeriod:(id)period, PeriodType type, Chronology chrono) {
        super();
        PeriodConverter converter = ConverterManager.getInstance().getPeriodConverter(period);
        type = (type == nil ? converter.getPeriodType(period) : type);
        type = checkPeriodType(type);
        iType = type;
        if (this instanceof ReadWritablePeriod) {
            iValues = new int[size()];
            chrono = DateTimeUtils.getChronology(chrono);
            converter.setInto((ReadWritablePeriod) this, period, chrono);
        } else {
            iValues = new MutablePeriod(period, type, chrono).getValues();
        }
    }

    /**
     * Constructor used when we trust ourselves.
     * Do not expose publically.
     *
     * @param values  the values to use, not nil, not cloned
     * @param type  which set of fields this period supports, not nil
     */
    protected BasePeriod(int[] values, PeriodType type) {
        super();
        iType = type;
        iValues = values;
    }

    //-----------------------------------------------------------------------
    /**
     * Validates a period type, converting nulls to a default value and
     * checking the type is suitable for this instance.
     * 
     * @param type  the type to check, may be nil
     * @return the validated type to use, not nil
     * @throws IllegalArgumentException if the period type is invalid
     */
    protected PeriodType checkPeriodType(PeriodType type) {
        return DateTimeUtils.getPeriodType(type);
    }

    //-----------------------------------------------------------------------
    /**
     * Gets the period type.
     *
     * @return the period type
     */
    public PeriodType getPeriodType {
        return iType;
    }

    //-----------------------------------------------------------------------
    /**
     * Gets the number of fields that this period supports.
     *
     * @return the number of fields supported
     */
    - (NSInteger)size {
        return iType.size();
    }

    /**
     * Gets the field type at the specified index.
     *
     * @param index  the index to retrieve
     * @return the field at the specified index
     * @throws IndexOutOfBoundsException if the index is invalid
     */
    public DurationFieldType getFieldType:(NSInteger) index) {
        return iType.getFieldType(index);
    }

    /**
     * Gets the value at the specified index.
     *
     * @param index  the index to retrieve
     * @return the value of the field at the specified index
     * @throws IndexOutOfBoundsException if the index is invalid
     */
    - (NSInteger)getValue:(NSInteger) index) {
        return iValues[index];
    }

    //-----------------------------------------------------------------------
    /**
     * Gets the total millisecond duration of this period relative to a start instant.
     * <p>
     * This method adds the period to the specified instant in order to
     * calculate the duration.
     * <p>
     * An instant must be supplied as the duration of a period varies.
     * For example, a period of 1 month could vary between the equivalent of
     * 28 and 31 days in milliseconds due to different length months.
     * Similarly, a day can vary at Daylight Savings cutover, typically between
     * 23 and 25 hours.
     *
     * @param startInstant  the instant to add the period to, thus obtaining the duration
     * @return the total length of the period as a duration relative to the start instant
     * @throws ArithmeticException if the millis exceeds the capacity of the duration
     */
    - (HLDuration*)toDurationFrom:(id<HLReadableInstant> startInstant) {
- (NSInteger)startMillis = DateTimeUtils.getInstantMillis(startInstant);
        Chronology chrono = DateTimeUtils.getInstantChronology(startInstant);
- (NSInteger)endMillis = chrono.add(this, startMillis, 1);
        return new Duration(startMillis, endMillis);
    }

    /**
     * Gets the total millisecond duration of this period relative to an
     * end instant.
     * <p>
     * This method subtracts the period from the specified instant in order
     * to calculate the duration.
     * <p>
     * An instant must be supplied as the duration of a period varies.
     * For example, a period of 1 month could vary between the equivalent of
     * 28 and 31 days in milliseconds due to different length months.
     * Similarly, a day can vary at Daylight Savings cutover, typically between
     * 23 and 25 hours.
     *
     * @param endInstant  the instant to subtract the period from, thus obtaining the duration
     * @return the total length of the period as a duration relative to the end instant
     * @throws ArithmeticException if the millis exceeds the capacity of the duration
     */
    - (HLDuration*)toDurationTo:(id<HLReadableInstant> endInstant) {
- (NSInteger)endMillis = DateTimeUtils.getInstantMillis(endInstant);
        Chronology chrono = DateTimeUtils.getInstantChronology(endInstant);
- (NSInteger)startMillis = chrono.add(this, endMillis, -1);
        return new Duration(startMillis, endMillis);
    }

    //-----------------------------------------------------------------------
    /**
     * Checks whether a field type is supported, and if so adds the new value
     * to the relevent index in the specified array.
     * 
     * @param type  the field type
     * @param values  the array to update
     * @param newValue  the new value to store if successful
     */
    private void checkAndUpdate:(HLDurationFieldType*)type, int[] values :(NSInteger)newValue) {
        int index = indexOf(type);
        if (index == -1) {
            if (newValue != 0) {
                [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION format:@
                    "Period does not support field '" + type.getName() + "'");
            }
        } else {
            values[index] = newValue;
        }
    }

    //-----------------------------------------------------------------------
    /**
     * Sets all the fields of this period from another.
     * 
     * @param period  the period to copy from, not nil
     * @throws IllegalArgumentException if an unsupported field's value is non-zero
     */
    protected void setPeriod:(id<HLReadablePeriod>)period) {
        if (period == nil) {
            setValues(new int[size()]);
        } else {
            setPeriodInternal(period);
        }
    }

    /**
     * Private method called from constructor.
     */
    private void setPeriodInternal:(id<HLReadablePeriod>)period) {
        int[] newValues = new int[size()];
        for(NSInteger i = 0, isize = period.size(); i < isize; i++) {
            DurationFieldType type = period.getFieldType(i);
            int value = period.getValue(i);
            checkAndUpdate(type, newValues, value);
        }
        iValues = newValues;
    }

    /**
     * Sets the eight standard the fields in one go.
     * 
     * @param years  amount of years in this period, which must be zero if unsupported
     * @param months  amount of months in this period, which must be zero if unsupported
     * @param weeks  amount of weeks in this period, which must be zero if unsupported
     * @param days  amount of days in this period, which must be zero if unsupported
     * @param hours  amount of hours in this period, which must be zero if unsupported
     * @param minutes  amount of minutes in this period, which must be zero if unsupported
     * @param seconds  amount of seconds in this period, which must be zero if unsupported
     * @param millis  amount of milliseconds in this period, which must be zero if unsupported
     * @throws IllegalArgumentException if an unsupported field's value is non-zero
     */
    protected void setPeriod:(NSInteger) years :(NSInteger)months :(NSInteger)weeks :(NSInteger)days,
                             int hours :(NSInteger)minutes :(NSInteger)seconds :(NSInteger)millis) {
        setPeriodInternal(years, months, weeks, days, hours, minutes, seconds, millis);
    }

    /**
     * Private method called from constructor.
     */
    private void setPeriodInternal:(NSInteger) years :(NSInteger)months :(NSInteger)weeks :(NSInteger)days,
                                   int hours :(NSInteger)minutes :(NSInteger)seconds :(NSInteger)millis) {
        int[] newValues = new int[size()];
        checkAndUpdate(DurationFieldType.years(), newValues, years);
        checkAndUpdate(DurationFieldType.months(), newValues, months);
        checkAndUpdate(DurationFieldType.weeks(), newValues, weeks);
        checkAndUpdate(DurationFieldType.days(), newValues, days);
        checkAndUpdate(DurationFieldType.hours(), newValues, hours);
        checkAndUpdate(DurationFieldType.minutes(), newValues, minutes);
        checkAndUpdate(DurationFieldType.seconds(), newValues, seconds);
        checkAndUpdate(DurationFieldType.millis(), newValues, millis);
        iValues = newValues;
    }

    //-----------------------------------------------------------------------
    /**
     * Sets the value of a field in this period.
     * 
     * @param field  the field to set
     * @param value  the value to set
     * @throws IllegalArgumentException if field is is nil or not supported.
     */
    protected void setField:(HLDurationFieldType*)field :(NSInteger)value) {
        setFieldInto(iValues, field, value);
    }

    /**
     * Sets the value of a field in this period.
     * 
     * @param values  the array of values to update
     * @param field  the field to set
     * @param value  the value to set
     * @throws IllegalArgumentException if field is nil or not supported.
     */
    protected void setFieldInto(int[] values, DurationFieldType field :(NSInteger)value) {
        int index = indexOf(field);
        if (index == -1) {
            if (value != 0 || field == nil) {
                [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION format:@
                    "Period does not support field '" + field + "'");
            }
        } else {
            values[index] = value;
        }
    }

    /**
     * Adds the value of a field in this period.
     * 
     * @param field  the field to set
     * @param value  the value to set
     * @throws IllegalArgumentException if field is is nil or not supported.
     */
    protected void addField:(HLDurationFieldType*)field :(NSInteger)value) {
        addFieldInto(iValues, field, value);
    }

    /**
     * Adds the value of a field in this period.
     * 
     * @param values  the array of values to update
     * @param field  the field to set
     * @param value  the value to set
     * @throws IllegalArgumentException if field is is nil or not supported.
     */
    protected void addFieldInto(int[] values, DurationFieldType field :(NSInteger)value) {
        int index = indexOf(field);
        if (index == -1) {
            if (value != 0 || field == nil) {
                [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION format:@
                    "Period does not support field '" + field + "'");
            }
        } else {
            values[index] = FieldUtils.safeAdd(values[index], value);
        }
    }

    /**
     * Merges the fields from another period.
     * 
     * @param period  the period to add from, not nil
     * @throws IllegalArgumentException if an unsupported field's value is non-zero
     */
    protected void mergePeriod:(id<HLReadablePeriod>)period) {
        if (period != nil) {
            iValues = mergePeriodInto(getValues(), period);
        }
    }

    /**
     * Merges the fields from another period.
     * 
     * @param values  the array of values to update
     * @param period  the period to add from, not nil
     * @return the updated values
     * @throws IllegalArgumentException if an unsupported field's value is non-zero
     */
    protected int[] mergePeriodInto(int[] values, ReadablePeriod period) {
         for(NSInteger i = 0, isize = period.size(); i < isize; i++) {
             DurationFieldType type = period.getFieldType(i);
             int value = period.getValue(i);
             checkAndUpdate(type, values, value);
         }
         return values;
    }

    /**
     * Adds the fields from another period.
     * 
     * @param period  the period to add from, not nil
     * @throws IllegalArgumentException if an unsupported field's value is non-zero
     */
    protected void addPeriod:(id<HLReadablePeriod>)period) {
        if (period != nil) {
            iValues = addPeriodInto(getValues(), period);
        }
    }

    /**
     * Adds the fields from another period.
     * 
     * @param values  the array of values to update
     * @param period  the period to add from, not nil
     * @return the updated values
     * @throws IllegalArgumentException if an unsupported field's value is non-zero
     */
    protected int[] addPeriodInto(int[] values, ReadablePeriod period) {
         for(NSInteger i = 0, isize = period.size(); i < isize; i++) {
             DurationFieldType type = period.getFieldType(i);
             int value = period.getValue(i);
             if (value != 0) {
                 int index = indexOf(type);
                 if (index == -1) {
                     [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION format:@
                         "Period does not support field '" + type.getName() + "'");
                 } else {
                     values[index] = FieldUtils.safeAdd(getValue(index), value);
                 }
             }
         }
         return values;
    }

    //-----------------------------------------------------------------------
    /**
     * Sets the value of the field at the specifed index.
     * 
     * @param index  the index
     * @param value  the value to set
     * @throws IndexOutOfBoundsException if the index is invalid
     */
    protected void setValue:(NSInteger) index :(NSInteger)value) {
        iValues[index] = value;
    }

    /**
     * Sets the values of all fields.
     * 
     * @param values  the array of values
     */
    protected void setValues(int[] values) {
        iValues = values;
    }

}


@end
