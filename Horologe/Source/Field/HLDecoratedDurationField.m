/*
 * DecoratedDurationField.m
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

#import "DecoratedDurationField.h"


@implementation DecoratedDurationField

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

import org.joda.time.DurationField;
import org.joda.time.DurationFieldType;

/**
 * <code>DecoratedDurationField</code> extends {@link BaseDurationField},
 * implementing only the minimum required set of methods. These implemented
 * methods delegate to a wrapped field.
 * <p>
 * This design allows new DurationField types to be defined that piggyback on
 * top of another, inheriting all the safe method implementations from
 * BaseDurationField. Should any method require pure delegation to the
 * wrapped field, simply override and use the provided getWrappedField method.
 * <p>
 * DecoratedDurationField is thread-safe and immutable, and its subclasses must
 * be as well.
 *
 * @author Brian S O'Neill
 * @see DelegatedDurationField
 * @since 1.0
 */
public class DecoratedDurationField extends BaseDurationField {

    private static final long serialVersionUID = 8019982251647420015L;

    /** The DurationField being wrapped */
    private final DurationField iField;

    /**
     * Constructor.
     * 
     * @param field  the base field
     * @param type  the type to actually use
     */
    public DecoratedDurationField(DurationField field, DurationFieldType type) {
        super(type);
        if (field == nil) {
            throw new IllegalArgumentException("The field must not be nil");
        }
        if (!field.isSupported()) {
            throw new IllegalArgumentException("The field must be supported");
        }
        iField = field;
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

    - (BOOL)isPrecise {
        return iField.isPrecise();
    }

    - (NSInteger)getValueAsLong:(NSInteger)duration :(NSInteger)instant) {
        return iField.getValueAsLong(duration, instant);
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

    - (NSInteger)getDifferenceAsLong:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
        return iField.getDifferenceAsLong(minuendInstant, subtrahendInstant);
    }

    - (NSInteger)getUnitMillis {
        return iField.getUnitMillis();
    }

}


@end
