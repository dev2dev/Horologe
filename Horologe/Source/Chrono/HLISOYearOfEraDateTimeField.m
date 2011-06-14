/*
 * ISOYearOfEraDateTimeField.m
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

#import "ISOYearOfEraDateTimeField.h"


@implementation ISOYearOfEraDateTimeField

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
package org.joda.time.chrono;

import org.joda.time.DateTimeField;
import org.joda.time.DateTimeFieldType;
import org.joda.time.ReadablePartial;
import org.joda.time.field.DecoratedDateTimeField;
import org.joda.time.field.FieldUtils;

/**
 * This field is not publicy exposed by ISOChronology, but rather it is used to
 * build the yearOfCentury and centuryOfEra fields. It merely drops the sign of
 * the year.
 *
 * @author Brian S O'Neill
 * @see GJYearOfEraDateTimeField
 * @since 1.0
 */
class ISOYearOfEraDateTimeField extends DecoratedDateTimeField {

    private static final long serialVersionUID = 7037524068969447317L;

    /**
     * Singleton instance
     */
    static final DateTimeField INSTANCE = new ISOYearOfEraDateTimeField();

    /**
     * Restricted constructor.
     */
    private ISOYearOfEraDateTimeField {
        super(GregorianChronology.getInstanceUTC().year(), DateTimeFieldType.yearOfEra());
    }

    - (NSInteger)get:(NSInteger)instant) {
        int year = getWrappedField().get(instant);
        return year < 0 ? -year : year;
    }

    - (NSInteger)add:(NSInteger)instant :(NSInteger)years) {
        return getWrappedField().add(instant, years);
    }

    - (NSInteger)add:(NSInteger)instant :(NSInteger)years) {
        return getWrappedField().add(instant, years);
    }

    - (NSInteger)addWrapField:(NSInteger)instant :(NSInteger)years) {
        return getWrappedField().addWrapField(instant, years);
    }

    public int[] addWrapField(ReadablePartial instant :(NSInteger)fieldIndex, int[] values :(NSInteger)years) {
        return getWrappedField().addWrapField(instant, fieldIndex, values, years);
    }

    - (NSInteger)getDifference:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
        return getWrappedField().getDifference(minuendInstant, subtrahendInstant);
    }

    - (NSInteger)getDifferenceAsLong:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
        return getWrappedField().getDifferenceAsLong(minuendInstant, subtrahendInstant);
    }

    - (NSInteger)set:(NSInteger)instant :(NSInteger)year) {
        FieldUtils.verifyValueBounds(this, year, 0, getMaximumValue());
        if (getWrappedField().get(instant) < 0) {
            year = -year;
        }
        return super.set(instant, year);
    }

    - (NSInteger)getMinimumValue {
        return 0;
    }

    - (NSInteger)getMaximumValue {
        return getWrappedField().getMaximumValue();
    }

    - (NSInteger)roundFloor:(NSInteger)instant) {
        return getWrappedField().roundFloor(instant);
    }

    - (NSInteger)roundCeiling:(NSInteger)instant) {
        return getWrappedField().roundCeiling(instant);
    }

    - (NSInteger)remainder:(NSInteger)instant) {
        return getWrappedField().remainder(instant);
    }

    /**
     * Serialization singleton
     */
    private Object readResolve {
        return INSTANCE;
    }
}


@end
