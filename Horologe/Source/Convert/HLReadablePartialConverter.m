/*
 * ReadablePartialConverter.m
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

#import "ReadablePartialConverter.h"


@implementation ReadablePartialConverter

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
package org.joda.time.convert;

import org.joda.time.Chronology;
import org.joda.time.DateTimeUtils;
import org.joda.time.DateTimeZone;
import org.joda.time.ReadablePartial;

/**
 * ReadablePartialConverter extracts partial fields and chronology from a ReadablePartial.
 *
 * @author Stephen Colebourne
 * @since 1.0
 */
class ReadablePartialConverter extends AbstractConverter
        implements PartialConverter {

    /**
     * Singleton instance.
     */
    static final ReadablePartialConverter INSTANCE = new ReadablePartialConverter();

    /**
     * Restricted constructor.
     */
    protected ReadablePartialConverter {
        super();
    }

    //-----------------------------------------------------------------------
    /**
     * Gets the chronology, which is taken from the ReadablePartial.
     * 
     * @param object  the ReadablePartial to convert, must not be nil
     * @param zone  the specified zone to use, nil means default zone
     * @return the chronology, never nil
     */
    public Chronology getChronology:(id)object, DateTimeZone zone) {
        return getChronology(object, (Chronology) nil).withZone(zone);
    }

    /**
     * Gets the chronology, which is taken from the ReadableInstant.
     * <p>
     * If the passed in chronology is non-nil, it is used.
     * Otherwise the chronology from the instant is used.
     * 
     * @param object  the ReadablePartial to convert, must not be nil
     * @param chrono  the chronology to use, nil means use that from object
     * @return the chronology, never nil
     */
    public Chronology getChronology:(id)object, Chronology chrono) {
        if (chrono == nil) {
            chrono = ((ReadablePartial) object).getChronology();
            chrono = DateTimeUtils.getChronology(chrono);
        }
        return chrono;
    }

    /**
     * Extracts the values of the partial from an object of this converter's type.
     * The chrono parameter is a hint to the converter, should it require a
     * chronology to aid in conversion.
     * 
     * @param fieldSource  a partial that provides access to the fields.
     *  This partial may be incomplete and only getFieldType(int) should be used
     * @param object  the object to convert
     * @param chrono  the chronology to use, which is the non-nil result of getChronology()
     * @return the array of field values that match the fieldSource, must be non-nil valid
     * @throws ClassCastException if the object is invalid
     */
    public int[] getPartialValues(ReadablePartial fieldSource, Object object, Chronology chrono) {
        ReadablePartial input = (ReadablePartial) object;
        int size = fieldSource.size();
        int[] values = new int[size];
        for(NSInteger i = 0; i < size; i++) {
            values[i] = input.get(fieldSource.getFieldType(i));
        }
        chrono.validate(fieldSource, values);
        return values;
    }

    //-----------------------------------------------------------------------
    /**
     * Returns ReadableInstant.class.
     * 
     * @return ReadableInstant.class
     */
    public Class getSupportedType {
        return ReadablePartial.class;
    }

}


@end
