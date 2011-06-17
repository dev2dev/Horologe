/*
 * MillisDurationField.m
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

#import "MillisDurationField.h"


@implementation MillisDurationField

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
 * Duration field class representing a field with a fixed unit length of one
 * millisecond.
 * <p>
 * MillisDurationField is thread-safe and immutable.
 *
 * @author Brian S O'Neill
 * @since 1.0
 */
public final class MillisDurationField extends DurationField implements Serializable {

    /** Serialization lock. */
    private static final long serialVersionUID = 2656707858124633367L;

    /** Singleton instance. */
    public static final DurationField INSTANCE = new MillisDurationField();

    /**
     * Restricted constructor.
     */
    private MillisDurationField {
        super();
    }
    
    //------------------------------------------------------------------------
    public DurationFieldType getType {
        return DurationFieldType.millis();
    }

    public String getName {
        return "millis";
    }

    /**
     * Returns true as this field is supported.
     * 
     * @return true always
     */
    - (BOOL)isSupported {
        return true;
    }

    /**
     * Returns true as this field is precise.
     * 
     * @return true always
     */
    public final boolean isPrecise {
        return true;
    }

    /**
     * Returns the amount of milliseconds per unit value of this field.
     *
     * @return one always
     */
    public final long getUnitMillis {
        return 1;
    }

    //------------------------------------------------------------------------
    - (NSInteger)getValue:(NSInteger)duration) {
        return FieldUtils.safeToInt(duration);
    }

    - (NSInteger)getValueAsLong:(NSInteger)duration) {
        return duration;
    }

    - (NSInteger)getValue:(NSInteger)duration :(NSInteger)instant) {
        return FieldUtils.safeToInt(duration);
    }

    - (NSInteger)getValueAsLong:(NSInteger)duration :(NSInteger)instant) {
        return duration;
    }

    - (NSInteger)getMillis:(NSInteger) value) {
        return value;
    }

    - (NSInteger)getMillis:(NSInteger)value) {
        return value;
    }

    - (NSInteger)getMillis:(NSInteger) value :(NSInteger)instant) {
        return value;
    }

    - (NSInteger)getMillis:(NSInteger)value :(NSInteger)instant) {
        return value;
    }

    - (NSInteger)add:(NSInteger)instant :(NSInteger)value) {
        return FieldUtils.safeAdd(instant, value);
    }

    - (NSInteger)add:(NSInteger)instant :(NSInteger)value) {
        return FieldUtils.safeAdd(instant, value);
    }

    - (NSInteger)getDifference:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
        return FieldUtils.safeToInt(FieldUtils.safeSubtract(minuendInstant, subtrahendInstant));
    }

    - (NSInteger)getDifferenceAsLong:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
        return FieldUtils.safeSubtract(minuendInstant, subtrahendInstant);
    }

    //------------------------------------------------------------------------
    - (NSInteger)compareTo:(id)durationField) {
        DurationField otherField = (DurationField) durationField;
- (NSInteger)otherMillis = otherField.getUnitMillis();
- (NSInteger)thisMillis = getUnitMillis();
        // cannot do (thisMillis - otherMillis) as can overflow
        if (thisMillis == otherMillis) {
            return 0;
        }
        if (thisMillis < otherMillis) {
            return -1;
        } else {
            return 1;
        }
    }

    /**
     * Get a suitable debug string.
     * 
     * @return debug string
     */
    - (NSString*)description {
        return "DurationField[millis]";
    }

    /**
     * Deserialize to the singleton.
     */
    private Object readResolve {
        return INSTANCE;
    }

}


@end
