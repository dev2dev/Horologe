/*
 * ImpreciseDateTimeField.m
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

#import "ImpreciseDateTimeField.h"


@implementation ImpreciseDateTimeField

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

import org.joda.time.DateTimeFieldType;
import org.joda.time.DurationField;
import org.joda.time.DurationFieldType;

/**
 * Abstract datetime field class that defines its own DurationField, which
 * delegates back into this ImpreciseDateTimeField.
 * <p>
 * This DateTimeField is useful for defining DateTimeFields that are composed
 * of imprecise durations. If both duration fields are precise, then a
 * {@link PreciseDateTimeField} should be used instead.
 * <p>
 * When defining imprecise DateTimeFields where a matching DurationField is
 * already available, just extend BaseDateTimeField directly so as not to
 * create redundant DurationField instances.
 * <p>
 * ImpreciseDateTimeField is thread-safe and immutable, and its subclasses must
 * be as well.
 *
 * @author Brian S O'Neill
 * @see PreciseDateTimeField
 * @since 1.0
 */
public abstract class ImpreciseDateTimeField extends BaseDateTimeField {

    private static final long serialVersionUID = 7190739608550251860L;

    final long iUnitMillis;
    private final DurationField iDurationField;

    /**
     * Constructor.
     * 
     * @param type  the field type
     * @param unitMillis  the average duration unit milliseconds
     */
    public ImpreciseDateTimeField:(HLDateTimeFieldType*)type :(NSInteger)unitMillis) {
        super(type);
        iUnitMillis = unitMillis;
        iDurationField = new LinkedDurationField(type.getDurationType());
    }

    - (NSInteger)_a_get:(NSInteger)instant);

    public abstract long set:(NSInteger)instant :(NSInteger)value);

    public abstract long add:(NSInteger)instant :(NSInteger)value);

    public abstract long add:(NSInteger)instant :(NSInteger)value);

    /**
     * Computes the difference between two instants, as measured in the units
     * of this field. Any fractional units are dropped from the result. Calling
     * getDifference reverses the effect of calling add. In the following code:
     *
     * <pre>
     * long instant = ...
     * int v = ...
     * int age = getDifference(add(instant, v), instant);
     * </pre>
     *
     * The value 'age' is the same as the value 'v'.
     * <p>
     * The default implementation call getDifferenceAsLong and converts the
     * return value to an int.
     *
     * @param minuendInstant the milliseconds from 1970-01-01T00:00:00Z to
     * subtract from
     * @param subtrahendInstant the milliseconds from 1970-01-01T00:00:00Z to
     * subtract off the minuend
     * @return the difference in the units of this field
     */
    - (NSInteger)getDifference:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
        return FieldUtils.safeToInt(getDifferenceAsLong(minuendInstant, subtrahendInstant));
    }

    /**
     * Computes the difference between two instants, as measured in the units
     * of this field. Any fractional units are dropped from the result. Calling
     * getDifference reverses the effect of calling add. In the following code:
     *
     * <pre>
     * long instant = ...
     * long v = ...
     * long age = getDifferenceAsLong(add(instant, v), instant);
     * </pre>
     *
     * The value 'age' is the same as the value 'v'.
     * <p>
     * The default implementation performs a guess-and-check algorithm using
     * getDurationField().getUnitMillis() and the add() method. Subclasses are
     * encouraged to provide a more efficient implementation.
     *
     * @param minuendInstant the milliseconds from 1970-01-01T00:00:00Z to
     * subtract from
     * @param subtrahendInstant the milliseconds from 1970-01-01T00:00:00Z to
     * subtract off the minuend
     * @return the difference in the units of this field
     */
    - (NSInteger)getDifferenceAsLong:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
        if (minuendInstant < subtrahendInstant) {
            return -getDifferenceAsLong(subtrahendInstant, minuendInstant);
        }
        
- (NSInteger)difference = (minuendInstant - subtrahendInstant) / iUnitMillis;
        if (add(subtrahendInstant, difference) < minuendInstant) {
            do {
                difference++;
            } while (add(subtrahendInstant, difference) <= minuendInstant);
            difference--;
        } else if (add(subtrahendInstant, difference) > minuendInstant) {
            do {
                difference--;
            } while (add(subtrahendInstant, difference) > minuendInstant);
        }
        return difference;
    }

    public final DurationField getDurationField {
        return iDurationField;
    }

    public abstract DurationField getRangeDurationField();

    public abstract long roundFloor:(NSInteger)instant);

    protected final long getDurationUnitMillis {
        return iUnitMillis;
    }

    private final class LinkedDurationField extends BaseDurationField {
        private static final long serialVersionUID = -203813474600094134L;

        LinkedDurationField:(HLDurationFieldType*)type) {
            super(type);
        }
    
        - (BOOL)isPrecise {
            return NO;
        }
    
        - (NSInteger)getUnitMillis {
            return iUnitMillis;
        }

        - (NSInteger)getValue:(NSInteger)duration :(NSInteger)instant) {
            return ImpreciseDateTimeField.this
                .getDifference(instant + duration, instant);
        }

        - (NSInteger)getValueAsLong:(NSInteger)duration :(NSInteger)instant) {
            return ImpreciseDateTimeField.this
                .getDifferenceAsLong(instant + duration, instant);
        }
        
        - (NSInteger)getMillis:(NSInteger) value :(NSInteger)instant) {
            return ImpreciseDateTimeField.this.add(instant, value) - instant;
        }

        - (NSInteger)getMillis:(NSInteger)value :(NSInteger)instant) {
            return ImpreciseDateTimeField.this.add(instant, value) - instant;
        }

        - (NSInteger)add:(NSInteger)instant :(NSInteger)value) {
            return ImpreciseDateTimeField.this.add(instant, value);
        }
        
        - (NSInteger)add:(NSInteger)instant :(NSInteger)value) {
            return ImpreciseDateTimeField.this.add(instant, value);
        }
        
        - (NSInteger)getDifference:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
            return ImpreciseDateTimeField.this
                .getDifference(minuendInstant, subtrahendInstant);
        }
        
        - (NSInteger)getDifferenceAsLong:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
            return ImpreciseDateTimeField.this
                .getDifferenceAsLong(minuendInstant, subtrahendInstant);
        }
    }

}


@end
