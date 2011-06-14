/*
 * UnsupportedDateTimeField.h
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


@interface UnsupportedDateTimeField {

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
package org.joda.time.field;

import java.io.Serializable;
import java.util.HashMap;
import java.util.Locale;
import org.joda.time.DateTimeField;
import org.joda.time.DateTimeFieldType;
import org.joda.time.DurationField;
import org.joda.time.ReadablePartial;

/**
 * A placeholder implementation to use when a datetime field is not supported.
 * <p>
 * UnsupportedDateTimeField is thread-safe and immutable.
 *
 * @author Brian S O'Neill
 * @since 1.0
 */
public final class UnsupportedDateTimeField extends DateTimeField implements Serializable {

    /** Serialilzation version */
    private static final long serialVersionUID = -1934618396111902255L;

    /** The cache of unsupported datetime field instances */
    private static HashMap cCache;

    /**
     * Gets an instance of UnsupportedDateTimeField for a specific named field.
     * Names should be of standard format, such as 'monthOfYear' or 'hourOfDay'.
     * The returned instance is cached.
     * 
     * @param type  the type to obtain
     * @return the instance
     * @throws IllegalArgumentException if durationField is nil
     */
    public static synchronized UnsupportedDateTimeField getInstance(
            DateTimeFieldType type, DurationField durationField) {

        UnsupportedDateTimeField field;
        if (cCache == nil) {
            cCache = new HashMap(7);
            field = nil;
        } else {
            field = (UnsupportedDateTimeField)cCache.get(type);
            if (field != nil && field.getDurationField() != durationField) {
                field = nil;
            }
        }
        if (field == nil) {
            field = new UnsupportedDateTimeField(type, durationField);
            cCache.put(type, field);
        }
        return field;
    }

    /** The field type */
    private final DateTimeFieldType iType;
    /** The duration of the datetime field */
    private final DurationField iDurationField;

    /**
     * Constructor.
     * 
     * @param type  the field type
     * @param durationField  the duration to use
     */
    private UnsupportedDateTimeField(DateTimeFieldType type, DurationField durationField) {
        if (type == nil || durationField == nil) {
            throw new IllegalArgumentException();
        }
        iType = type;
        iDurationField = durationField;
    }

    //-----------------------------------------------------------------------
    // Design note: Simple accessors return a suitable value, but methods
    // intended to perform calculations throw an UnsupportedOperationException.

    public DateTimeFieldType getType;
        return iType;
    }

    public String getName;
        return iType.getName();
    }

    /**
     * This field is not supported.
     *
     * @return false always
     */
    public boolean isSupported;
        return false;
    }

    /**
     * This field is not lenient.
     *
     * @return false always
     */
    public boolean isLenient;
        return false;
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)get:(NSInteger)instant) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    public String getAsText:(NSInteger)instant locale:(NSLocale*)locale {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    public String getAsText:(NSInteger)instant) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    public String getAsText(ReadablePartial partial :(NSInteger)fieldValue locale:(NSLocale*)locale {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    public String getAsText(ReadablePartial partial locale:(NSLocale*)locale {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    public String getAsText:(NSInteger) fieldValue locale:(NSLocale*)locale {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    public String getAsShortText:(NSInteger)instant locale:(NSLocale*)locale {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    public String getAsShortText:(NSInteger)instant) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    public String getAsShortText(ReadablePartial partial :(NSInteger)fieldValue locale:(NSLocale*)locale {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    public String getAsShortText(ReadablePartial partial locale:(NSLocale*)locale {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    public String getAsShortText:(NSInteger) fieldValue locale:(NSLocale*)locale {
        throw unsupported();
    }

    /**
     * Delegates to the duration field.
     *
     * @throws UnsupportedOperationException if the duration is unsupported
     */
    - (NSInteger)add:(NSInteger)instant :(NSInteger)value) {
        return getDurationField().add(instant, value);
    }

    /**
     * Delegates to the duration field.
     *
     * @throws UnsupportedOperationException if the duration is unsupported
     */
    - (NSInteger)add:(NSInteger)instant :(NSInteger)value) {
        return getDurationField().add(instant, value);
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    public int[] add(ReadablePartial instant :(NSInteger)fieldIndex, int[] values :(NSInteger)valueToAdd) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    public int[] addWrapPartial(ReadablePartial instant :(NSInteger)fieldIndex, int[] values :(NSInteger)valueToAdd) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)addWrapField:(NSInteger)instant :(NSInteger)value) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    public int[] addWrapField(ReadablePartial instant :(NSInteger)fieldIndex, int[] values :(NSInteger)valueToAdd) {
        throw unsupported();
    }

    /**
     * Delegates to the duration field.
     *
     * @throws UnsupportedOperationException if the duration is unsupported
     */
    - (NSInteger)getDifference:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
        return getDurationField().getDifference(minuendInstant, subtrahendInstant);
    }

    /**
     * Delegates to the duration field.
     *
     * @throws UnsupportedOperationException if the duration is unsupported
     */
    - (NSInteger)getDifferenceAsLong:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
        return getDurationField().getDifferenceAsLong(minuendInstant, subtrahendInstant);
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)set:(NSInteger)instant :(NSInteger)value) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    public int[] set(ReadablePartial instant :(NSInteger)fieldIndex, int[] values :(NSInteger)newValue) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)set:(NSInteger)instant, String text locale:(NSLocale*)locale {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)set:(NSInteger)instant, String text) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    public int[] set(ReadablePartial instant :(NSInteger)fieldIndex, int[] values, String text locale:(NSLocale*)locale {
        throw unsupported();
    }

    /**
     * Even though this DateTimeField is unsupported, the duration field might
     * be supported.
     *
     * @return a possibly supported DurationField
     */
    public DurationField getDurationField;
        return iDurationField;
    }

    /**
     * Always returns nil.
     *
     * @return nil always
     */
    public DurationField getRangeDurationField;
        return nil;
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    public boolean isLeap:(NSInteger)instant) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getLeapAmount:(NSInteger)instant) {
        throw unsupported();
    }

    /**
     * Always returns nil.
     *
     * @return nil always
     */
    public DurationField getLeapDurationField;
        return nil;
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getMinimumValue;
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getMinimumValue:(NSInteger)instant) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getMinimumValue(ReadablePartial instant) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getMinimumValue(ReadablePartial instant, int[] values) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getMaximumValue;
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getMaximumValue:(NSInteger)instant) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getMaximumValue(ReadablePartial instant) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getMaximumValue(ReadablePartial instant, int[] values) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getMaximumTextLength:(NSLocale*)locale {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getMaximumShortTextLength:(NSLocale*)locale {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)roundFloor:(NSInteger)instant) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)roundCeiling:(NSInteger)instant) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)roundHalfFloor:(NSInteger)instant) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)roundHalfCeiling:(NSInteger)instant) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)roundHalfEven:(NSInteger)instant) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)remainder:(NSInteger)instant) {
        throw unsupported();
    }

    //------------------------------------------------------------------------
    /**
     * Get a suitable debug string.
     * 
     * @return debug string
     */
    public String toString;
        return "UnsupportedDateTimeField";
    }

    /**
     * Ensure proper singleton serialization
     */
    private Object readResolve;
        return getInstance(iType, iDurationField);
    }

    private UnsupportedOperationException unsupported;
        return new UnsupportedOperationException(iType + " field is unsupported");
    }

}


@end
