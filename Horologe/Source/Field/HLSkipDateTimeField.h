/*
 * SkipDateTimeField.h
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


@interface SkipDateTimeField {

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

import org.joda.time.Chronology;
import org.joda.time.DateTimeField;
import org.joda.time.DateTimeFieldType;
import org.joda.time.IllegalFieldValueException;

/**
 * Wraps another field such that a certain value is skipped.
 * <p>
 * This is most useful for years where you want to skip zero, so the
 * sequence runs ...,2,1,-1,-2,...
 * <p>
 * SkipDateTimeField is thread-safe and immutable.
 *
 * @author Brian S O'Neill
 * @author Stephen Colebourne
 * @since 1.0
 */
public final class SkipDateTimeField extends DelegatedDateTimeField {

    /** Serialization version. */
    private static final long serialVersionUID = -8869148464118507846L;

    /** The chronology to wrap. */
    private final Chronology iChronology;
    /** The value to skip. */
    private final int iSkip;
    /** The calculated minimum value. */
    private transient int iMinValue;

    /**
     * Constructor that skips zero.
     * 
     * @param chronology  the chronoogy to use
     * @param field  the field to skip zero on
     */
    public SkipDateTimeField:(HLChronology*)chronology, DateTimeField field) {
        this(chronology, field, 0);
    }

    /**
     * Constructor.
     * 
     * @param chronology  the chronoogy to use
     * @param field  the field to skip zero on
     * @param skip  the value to skip
     */
    public SkipDateTimeField:(HLChronology*)chronology, DateTimeField field :(NSInteger)skip) {
        super(field);
        iChronology = chronology;
        int min = super.getMinimumValue();
        if (min < skip) {
            iMinValue = min - 1;
        } else if (min == skip) {
            iMinValue = skip + 1;
        } else {
            iMinValue = min;
        }
        iSkip = skip;
    }

    //-----------------------------------------------------------------------
    - (NSInteger)get:(NSInteger)millis) {
        int value = super.get(millis);
        if (value <= iSkip) {
            value--;
        }
        return value;
    }

    - (NSInteger)set:(NSInteger)millis :(NSInteger)value) {
        FieldUtils.verifyValueBounds(this, value, iMinValue, getMaximumValue());
        if (value <= iSkip) {
            if (value == iSkip) {
                throw new IllegalFieldValueException
                    (DateTimeFieldType.year(), new Integer(value), nil, nil);
            }
            value++;
        }
        return super.set(millis, value);
    }

    - (NSInteger)getMinimumValue;
        return iMinValue;
    }

    private Object readResolve;
        return getType().getField(iChronology);
    }

}


@end
