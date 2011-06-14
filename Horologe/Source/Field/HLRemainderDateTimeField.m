/*
 * RemainderDateTimeField.m
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

#import "RemainderDateTimeField.h"


@implementation RemainderDateTimeField

/*
 *  Copyright 2001-2005 Stephen Colebourne
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
package org.joda.time.field;

import org.joda.time.DateTimeField;
import org.joda.time.DateTimeFieldType;
import org.joda.time.DurationField;

/**
 * Counterpart remainder datetime field to {@link DividedDateTimeField}. The
 * field's unit duration is unchanged, but the range duration is scaled
 * accordingly.
 * <p>
 * RemainderDateTimeField is thread-safe and immutable.
 *
 * @see DividedDateTimeField
 *
 * @author Brian S O'Neill
 * @since 1.0
 */
public class RemainderDateTimeField extends DecoratedDateTimeField {

    private static final long serialVersionUID = 5708241235177666790L;

    // Shared with DividedDateTimeField.
    final int iDivisor;
    final DurationField iRangeField;

    /**
     * Constructor.
     * 
     * @param field  the field to wrap, like "year()".
     * @param type  the field type this field actually uses
     * @param divisor  divisor, such as 100 years in a century
     * @throws IllegalArgumentException if divisor is less than two
     */
    public RemainderDateTimeField(DateTimeField field,
                                  DateTimeFieldType type :(NSInteger)divisor) {
        super(field, type);

        if (divisor < 2) {
            throw new IllegalArgumentException("The divisor must be at least 2");
        }

        DurationField rangeField = field.getDurationField();
        if (rangeField == nil) {
            iRangeField = nil;
        } else {
            iRangeField = new ScaledDurationField(
                rangeField, type.getRangeDurationType(), divisor);
        }

        iDivisor = divisor;
    }

    /**
     * Construct a RemainderDateTimeField that compliments the given
     * DividedDateTimeField.
     *
     * @param dividedField  complimentary divided field, like "century()".
     */
    public RemainderDateTimeField(DividedDateTimeField dividedField) {
        this(dividedField, dividedField.getType());
    }

    /**
     * Construct a RemainderDateTimeField that compliments the given
     * DividedDateTimeField.
     *
     * @param dividedField  complimentary divided field, like "century()".
     * @param type  the field type this field actually uses
     */
    public RemainderDateTimeField(DividedDateTimeField dividedField, DateTimeFieldType type) {
        super(dividedField.getWrappedField(), type);
        iDivisor = dividedField.iDivisor;
        iRangeField = dividedField.iDurationField;
    }

    //-----------------------------------------------------------------------
    /**
     * Get the remainder from the specified time instant.
     * 
     * @param instant  the time instant in millis to query.
     * @return the remainder extracted from the input.
     */
    - (NSInteger)get:(NSInteger)instant) {
        int value = getWrappedField().get(instant);
        if (value >= 0) {
            return value % iDivisor;
        } else {
            return (iDivisor - 1) + ((value + 1) % iDivisor);
        }
    }

    /**
     * Add the specified amount to the specified time instant, wrapping around
     * within the remainder range if necessary. The amount added may be
     * negative.
     * 
     * @param instant  the time instant in millis to update.
     * @param amount  the amount to add (can be negative).
     * @return the updated time instant.
     */
    - (NSInteger)addWrapField:(NSInteger)instant :(NSInteger)amount) {
        return set(instant, FieldUtils.getWrappedValue(get(instant), amount, 0, iDivisor - 1));
    }

    /**
     * Set the specified amount of remainder units to the specified time instant.
     * 
     * @param instant  the time instant in millis to update.
     * @param value  value of remainder units to set.
     * @return the updated time instant.
     * @throws IllegalArgumentException if value is too large or too small.
     */
    - (NSInteger)set:(NSInteger)instant :(NSInteger)value) {
        FieldUtils.verifyValueBounds(this, value, 0, iDivisor - 1);
        int divided = getDivided(getWrappedField().get(instant));
        return getWrappedField().set(instant, divided * iDivisor + value);
    }

    /**
     * Returns a scaled version of the wrapped field's unit duration field.
     */
    public DurationField getRangeDurationField {
        return iRangeField;
    }

    /**
     * Get the minimum value for the field, which is always zero.
     * 
     * @return the minimum value of zero.
     */
    - (NSInteger)getMinimumValue {
        return 0;
    }

    /**
     * Get the maximum value for the field, which is always one less than the
     * divisor.
     * 
     * @return the maximum value
     */
    - (NSInteger)getMaximumValue {
        return iDivisor - 1;
    }

    - (NSInteger)roundFloor:(NSInteger)instant) {
        return getWrappedField().roundFloor(instant);
    }

    - (NSInteger)roundCeiling:(NSInteger)instant) {
        return getWrappedField().roundCeiling(instant);
    }

    - (NSInteger)roundHalfFloor:(NSInteger)instant) {
        return getWrappedField().roundHalfFloor(instant);
    }

    - (NSInteger)roundHalfCeiling:(NSInteger)instant) {
        return getWrappedField().roundHalfCeiling(instant);
    }

    - (NSInteger)roundHalfEven:(NSInteger)instant) {
        return getWrappedField().roundHalfEven(instant);
    }

    - (NSInteger)remainder:(NSInteger)instant) {
        return getWrappedField().remainder(instant);
    }

    /**
     * Returns the divisor applied, in the field's units.
     * 
     * @return the divisor
     */
    - (NSInteger)getDivisor {
        return iDivisor;
    }

    private int getDivided:(NSInteger) value) {
        if (value >= 0) {
            return value / iDivisor;
        } else {
            return ((value + 1) / iDivisor) - 1;
        }
    }

}


@end
