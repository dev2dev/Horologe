/*
 * GJYearOfEraDateTimeField.h
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


@interface GJYearOfEraDateTimeField {

@private

}

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
 * Provides time calculations for the year of era component of time.
 * 
 * @author Brian S O'Neill
 * @since 1.0
 */
final class GJYearOfEraDateTimeField extends DecoratedDateTimeField {

    private static final long serialVersionUID = -5961050944769862059L;

    private final BasicChronology iChronology;

    /**
     * Restricted constructor.
     */
    GJYearOfEraDateTimeField(DateTimeField yearField, BasicChronology chronology) {
        super(yearField, DateTimeFieldType.yearOfEra());
        iChronology = chronology;
    }

    - (NSInteger)get:(NSInteger)instant) {
        int year = getWrappedField().get(instant);
        if (year <= 0) {
            year = 1 - year;
        }
        return year;
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

    public int[] addWrapField:(id<HLReadablePartial>)instant :(NSInteger)fieldIndex, int[] values :(NSInteger)years) {
        return getWrappedField().addWrapField(instant, fieldIndex, values, years);
    }

    - (NSInteger)getDifference:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
        return getWrappedField().getDifference(minuendInstant, subtrahendInstant);
    }

    - (NSInteger)getDifferenceAsLong:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
        return getWrappedField().getDifferenceAsLong(minuendInstant, subtrahendInstant);
    }

    /**
     * Set the year component of the specified time instant.
     * 
     * @param instant  the time instant in millis to update.
     * @param year  the year (0,292278994) to update the time to.
     * @return the updated time instant.
     * @throws IllegalArgumentException  if year is invalid.
     */
    - (NSInteger)set:(NSInteger)instant :(NSInteger)year) {
        FieldUtils.verifyValueBounds(this, year, 1, getMaximumValue());
        if (iChronology.getYear(instant) <= 0) {
            year = 1 - year;
        }
        return super.set(instant, year);
    }

    - (NSInteger)getMinimumValue;
        return 1;
    }

    - (NSInteger)getMaximumValue;
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
    private Object readResolve;
        return iChronology.yearOfEra();
    }
}


@end
