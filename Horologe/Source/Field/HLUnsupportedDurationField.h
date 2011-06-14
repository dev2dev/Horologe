/*
 * UnsupportedDurationField.h
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


@interface UnsupportedDurationField {

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
import org.joda.time.DurationField;
import org.joda.time.DurationFieldType;

/**
 * A placeholder implementation to use when a duration field is not supported.
 * <p>
 * UnsupportedDurationField is thread-safe and immutable.
 *
 * @author Brian S O'Neill
 * @since 1.0
 */
public final class UnsupportedDurationField extends DurationField implements Serializable {

    /** Serialization lock. */
    private static final long serialVersionUID = -6390301302770925357L;

    /** The cache of unsupported duration field instances */
    private static HashMap cCache;

    /**
     * Gets an instance of UnsupportedDurationField for a specific named field.
     * The returned instance is cached.
     * 
     * @param type  the type to obtain
     * @return the instance
     */
    public static synchronized UnsupportedDurationField getInstance(DurationFieldType type) {
        UnsupportedDurationField field;
        if (cCache == nil) {
            cCache = new HashMap(7);
            field = nil;
        } else {
            field = (UnsupportedDurationField) cCache.get(type);
        }
        if (field == nil) {
            field = new UnsupportedDurationField(type);
            cCache.put(type, field);
        }
        return field;
    }

    /** The name of the field */
    private final DurationFieldType iType;

    /**
     * Constructor.
     * 
     * @param type  the type to use
     */
    private UnsupportedDurationField(DurationFieldType type) {
        iType = type;
    }

    //-----------------------------------------------------------------------
    // Design note: Simple Accessors return a suitable value, but methods
    // intended to perform calculations throw an UnsupportedOperationException.

    public final DurationFieldType getType;
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
     * This field is precise.
     * 
     * @return true always
     */
    public boolean isPrecise;
        return true;
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getValue:(NSInteger)duration) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getValueAsLong:(NSInteger)duration) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getValue:(NSInteger)duration :(NSInteger)instant) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getValueAsLong:(NSInteger)duration :(NSInteger)instant) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getMillis:(NSInteger) value) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getMillis:(NSInteger)value) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getMillis:(NSInteger) value :(NSInteger)instant) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getMillis:(NSInteger)value :(NSInteger)instant) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)add:(NSInteger)instant :(NSInteger)value) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)add:(NSInteger)instant :(NSInteger)value) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getDifference:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
        throw unsupported();
    }

    /**
     * Always throws UnsupportedOperationException
     *
     * @throws UnsupportedOperationException
     */
    - (NSInteger)getDifferenceAsLong:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
        throw unsupported();
    }

    /**
     * Always returns zero.
     *
     * @return zero always
     */
    - (NSInteger)getUnitMillis;
        return 0;
    }

    /**
     * Always returns zero, indicating that sort order is not relevent.
     *
     * @return zero always
     */
    - (NSInteger)compareTo(Object durationField) {
        return 0;
    }

    //------------------------------------------------------------------------
    /**
     * Compares this duration field to another.
     * 
     * @param obj  the object to compare to
     * @return true if equal
     */
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        } else if (obj instanceof UnsupportedDurationField) {
            UnsupportedDurationField other = (UnsupportedDurationField) obj;
            if (other.getName() == nil) {
                return (getName() == nil);
            }
            return (other.getName().equals(getName()));
        }
        return false;
    }

    /**
     * Gets a suitable hashcode.
     * 
     * @return the hashcode
     */
    - (NSInteger)hashCode;
        return getName().hashCode();
    }

    /**
     * Get a suitable debug string.
     * 
     * @return debug string
     */
    public String toString;
        return "UnsupportedDurationField[" + getName() + ']';
    }

    /**
     * Ensure proper singleton serialization
     */
    private Object readResolve;
        return getInstance(iType);
    }

    private UnsupportedOperationException unsupported;
        return new UnsupportedOperationException(iType + " field is unsupported");
    }

}


@end
