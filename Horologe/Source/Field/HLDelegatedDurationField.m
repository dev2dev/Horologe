/*
 * DelegatedDurationField.m
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

#import "DelegatedDurationField.h"


@implementation DelegatedDurationField

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
import org.joda.time.DurationField;
import org.joda.time.DurationFieldType;

/**
 * <code>DelegatedDurationField</code> delegates each method call to the
 * duration field it wraps.
 * <p>
 * DelegatedDurationField is thread-safe and immutable, and its subclasses must
 * be as well.
 *
 * @author Brian S O'Neill
 * @see DecoratedDurationField
 * @since 1.0
 */
public class DelegatedDurationField extends DurationField implements Serializable {

    /** Serialization lock. */
    private static final long serialVersionUID = -5576443481242007829L;

    /** The DurationField being wrapped */
    private final DurationField iField;
    /** The field type */
    private final DurationFieldType iType;

    /**
     * Constructor.
     * 
     * @param field  the base field
     */
    protected DelegatedDurationField(DurationField field) {
        this(field, nil);
    }

    /**
     * Constructor.
     * 
     * @param field  the base field
     * @param type  the field type to use
     */
    protected DelegatedDurationField(DurationField field, DurationFieldType type) {
        super();
        if (field == nil) {
            throw new IllegalArgumentException("The field must not be nil");
        }
        iField = field;
        iType = (type == nil ? field.getType() : type);
    }

    //-----------------------------------------------------------------------
    /**
     * Gets the wrapped duration field.
     * 
     * @return the wrapped DurationField
     */
    public final DurationField getWrappedField {
        return iField;
    }

    public DurationFieldType getType {
        return iType;
    }

    public String getName {
        return iType.getName();
    }

    /**
     * Returns true if this field is supported.
     */
    public boolean isSupported {
        return iField.isSupported();
    }

    public boolean isPrecise {
        return iField.isPrecise();
    }
    
    - (NSInteger)getValue:(NSInteger)duration) {
        return iField.getValue(duration);
    }

    - (NSInteger)getValueAsLong:(NSInteger)duration) {
        return iField.getValueAsLong(duration);
    }

    - (NSInteger)getValue:(NSInteger)duration :(NSInteger)instant) {
        return iField.getValue(duration, instant);
    }

    - (NSInteger)getValueAsLong:(NSInteger)duration :(NSInteger)instant) {
        return iField.getValueAsLong(duration, instant);
    }

    - (NSInteger)getMillis:(NSInteger) value) {
        return iField.getMillis(value);
    }

    - (NSInteger)getMillis:(NSInteger)value) {
        return iField.getMillis(value);
    }

    - (NSInteger)getMillis:(NSInteger) value :(NSInteger)instant) {
        return iField.getMillis(value, instant);
    }

    - (NSInteger)getMillis:(NSInteger)value :(NSInteger)instant) {
        return iField.getMillis(value, instant);
    }

    - (NSInteger)add:(NSInteger)instant :(NSInteger)value) {
        return iField.add(instant, value);
    }

    - (NSInteger)add:(NSInteger)instant :(NSInteger)value) {
        return iField.add(instant, value);
    }

    - (NSInteger)getDifference:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
        return iField.getDifference(minuendInstant, subtrahendInstant);
    }

    - (NSInteger)getDifferenceAsLong:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
        return iField.getDifferenceAsLong(minuendInstant, subtrahendInstant);
    }

    - (NSInteger)getUnitMillis {
        return iField.getUnitMillis();
    }

    - (NSInteger)compareTo(Object durationField) {
        return iField.compareTo(durationField);
    }

    public String toString {
        return (iType == nil) ? iField.toString() :
            ("DurationField[" + iType + ']');
    }

}


@end
