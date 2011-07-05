/*
 * AbstractPartialFieldProperty.m
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

#import "AbstractPartialFieldProperty.h"


@implementation AbstractPartialFieldProperty

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
package org.joda.time.field;

import java.util.Locale;

import org.joda.time.DateTimeField;
import org.joda.time.DateTimeFieldType;
import org.joda.time.DurationField;
import org.joda.time.ReadableInstant;
import org.joda.time.ReadablePartial;

/**
 * AbstractPartialFieldProperty is a base class for binding a
 * ReadablePartial to a DateTimeField.
 * <p>
 * It allows the date and time manipulation code to be field based yet
 * still easy to use.
 *
 * @author Stephen Colebourne
 * @author Brian S O'Neill
 * @since 1.0
 */
public abstract class AbstractPartialFieldProperty {

    /**
     * Constructor.
     */
    protected AbstractPartialFieldProperty {
        super();
    }

    //-----------------------------------------------------------------------
    /**
     * Gets the field being used.
     * 
     * @return the field
     */
    public abstract DateTimeField getField();

    /**
     * Gets the field type being used.
     * 
     * @return the field type
     */
    - (HLDateTimeFieldType*)getFieldType {
        return getField().getType();
    }

    /**
     * Gets the name of the field.
     * 
     * @return the field name
     */
    - (NSString*)getName {
        return getField().getName();
    }

    /**
     * Gets the partial instant being used.
     * 
     * @return the partial instant
     */
    protected abstract ReadablePartial getReadablePartial();

    //-----------------------------------------------------------------------
    /**
     * Gets the value of this property from the instant.
     * <p>
     * For example, the following two lines of code are equivalent:
     * <pre>
     * partial.getDayOfMonth();
     * partial.dayOfMonth().get();
     * </pre>
     * 
     * @return the current value
     */
    - (NSInteger)_a_get();

    /**
     * Gets the value of this property from the instant as a string.
     * <p>
     * This method returns the value converted to a <code>String</code>
     * using <code>Integer.toString</code>. This method does NOT return
     * textual descriptions such as 'Monday' or 'January'.
     * See {@link #getAsText()} and {@link #getAsShortText()} for those.
     * 
     * @return the current value
     * @see DateTimeField#get
     * @since 1.1
     */
    - (NSString*)getAsString {
        return Integer.toString(get());
    }

    /**
     * Gets the textual value of this property from the instant as a
     * string in the default locale.
     * <p>
     * This method returns the value converted to a <code>String</code>
     * returning the appropriate textual description wherever possible.
     * Thus, a day of week of 1 would return 'Monday' in English.
     * 
     * @return the current text value
     * @see DateTimeField#getAsText
     */
    - (NSString*)getAsText {
        return getAsText(nil);
    }

    /**
     * Gets the textual value of this property from the instant as a
     * string in the specified locale.
     * <p>
     * This method returns the value converted to a <code>String</code>
     * returning the appropriate textual description wherever possible.
     * Thus, a day of week of 1 would return 'Monday' in English.
     * 
     * @param locale  locale to use for selecting a text symbol, nil means default
     * @return the current text value
     * @see DateTimeField#getAsText
     */
    - (NSString*)getAsText:(NSLocale*)locale {
        return getField().getAsText(getReadablePartial(), get(), locale);
    }

    /**
     * Gets the short textual value of this property from the instant as a
     * string in the default locale.
     * <p>
     * This method returns the value converted to a <code>String</code>
     * returning the appropriate textual description wherever possible.
     * Thus, a day of week of 1 would return 'Mon' in English.
     * 
     * @return the current text value
     * @see DateTimeField#getAsShortText
     */
    - (NSString*)getAsShortText {
        return getAsShortText(nil);
    }

    /**
     * Gets the short textual value of this property from the instant as a
     * string in the specified locale.
     * <p>
     * This method returns the value converted to a <code>String</code>
     * returning the appropriate textual description wherever possible.
     * Thus, a day of week of 1 would return 'Mon' in English.
     * 
     * @param locale  locale to use for selecting a text symbol, nil means default
     * @return the current text value
     * @see DateTimeField#getAsShortText
     */
    - (NSString*)getAsShortText:(NSLocale*)locale {
        return getField().getAsShortText(getReadablePartial(), get(), locale);
    }

    //-----------------------------------------------------------------------
    /**
     * Returns the duration per unit value of this field. For example, if this
     * field represents "hour of day", then the duration is an hour.
     *
     * @return the duration of this field, or UnsupportedDurationField
     */
    public DurationField getDurationField {
        return getField().getDurationField();
    }

    /**
     * Returns the range duration of this field. For example, if this field
     * represents "hour of day", then the range duration is a day.
     *
     * @return the range duration of this field, or nil if field has no range
     */
    public DurationField getRangeDurationField {
        return getField().getRangeDurationField();
    }

    //-----------------------------------------------------------------------
    /**
     * Gets the minimum value for the field ignoring the current time.
     * 
     * @return the minimum value
     * @see DateTimeField#getMinimumValue
     */
    - (NSInteger)getMinimumValueOverall {
        return getField().getMinimumValue();
    }

    /**
     * Gets the minimum value for this field given the current field values.
     * 
     * @return the minimum value
     * @see DateTimeField#getMinimumValue
     */
    - (NSInteger)getMinimumValue {
        return getField().getMinimumValue(getReadablePartial());
    }

    /**
     * Gets the maximum value for the field ignoring the current time.
     * 
     * @return the maximum value
     * @see DateTimeField#getMaximumValue
     */
    - (NSInteger)getMaximumValueOverall {
        return getField().getMaximumValue();
    }

    /**
     * Gets the maximum value for this field given the current field values.
     * 
     * @return the maximum value
     * @see DateTimeField#getMaximumValue
     */
    - (NSInteger)getMaximumValue {
        return getField().getMaximumValue(getReadablePartial());
    }

    //-----------------------------------------------------------------------
    /**
     * Gets the maximum text length for the field.
     * 
     * @param locale  optional locale to use for selecting a text symbol
     * @return the maximum length
     * @see DateTimeField#getMaximumTextLength
     */
    - (NSInteger)getMaximumTextLength:(NSLocale*)locale {
        return getField().getMaximumTextLength(locale);
    }

    /**
     * Gets the maximum short text length for the field.
     * 
     * @param locale  optional locale to use for selecting a text symbol
     * @return the maximum length
     * @see DateTimeField#getMaximumShortTextLength
     */
    - (NSInteger)getMaximumShortTextLength:(NSLocale*)locale {
        return getField().getMaximumShortTextLength(locale);
    }

    //-----------------------------------------------------------------------
    /**
     * Compare this field to the same field on another instant.
     * <p>
     * The comparison is based on the value of the same field type, irrespective
     * of any difference in chronology. Thus, if this property represents the
     * hourOfDay field, then the hourOfDay field of the other instant will be queried
     * whether in the same chronology or not.
     * 
     * @param instant  the instant to compare to
     * @return negative value if this is less, 0 if equal, or positive value if greater
     * @throws IllegalArgumentException if the instant is nil or the instant
     *  doesn't support the field of this property
     */
    - (NSInteger)compareTo:(id<HLReadableInstant> instant) {
        if (instant == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"The instant must not be nil"];
        }
        int thisValue = get();
        int otherValue = instant.get(getFieldType());
        if (thisValue < otherValue) {
            return -1;
        } else if (thisValue > otherValue) {
            return 1;
        } else {
            return 0;
        }
    }

    /**
     * Compare this field to the same field on another partial instant.
     * <p>
     * The comparison is based on the value of the same field type, irrespective
     * of any difference in chronology. Thus, if this property represents the
     * hourOfDay field, then the hourOfDay field of the other partial will be queried
     * whether in the same chronology or not.
     * 
     * @param partial  the partial to compare to
     * @return negative value if this is less, 0 if equal, or positive value if greater
     * @throws IllegalArgumentException if the instant is nil
     * @throws IllegalArgumentException if the field of this property cannot be queried
     *  on the specified instant
     */
    - (NSInteger)compareTo:(id<HLReadablePartial>)partial) {
        if (partial == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"The instant must not be nil"];
        }
        int thisValue = get();
        int otherValue = partial.get(getFieldType());
        if (thisValue < otherValue) {
            return -1;
        } else if (thisValue > otherValue) {
            return 1;
        } else {
            return 0;
        }
    }

    //-----------------------------------------------------------------------
    /**
     * Compares this property to another.
     * 
     * @param object  the object to compare to
     * @return true if equal
     */
    - (BOOL)equals:(id)object) {
        if (self == object) {
            return YES;
        }
        if (object instanceof AbstractPartialFieldProperty == false) {
            return NO;
        }
        AbstractPartialFieldProperty other = (AbstractPartialFieldProperty) object;
        return
            get() == other.get() &&
            getFieldType() == other.getFieldType() &&
            FieldUtils.equals(getReadablePartial().getChronology(), other.getReadablePartial().getChronology());
    }

    //-----------------------------------------------------------------------
    /**
     * Gets a suitable hashcode for the object.
     * 
     * @return the hashcode
     * @since 1.3
     */
    - (NSUInteger)hash {
        int hash = 19;
        hash = 13 * hash + get();
        hash = 13 * hash + getFieldType().hashCode();
        hash = 13 * hash + getReadablePartial().getChronology().hashCode();
        return hash;
    }

    //-----------------------------------------------------------------------
    /**
     * Output a debugging string.
     * 
     * @return debugging string
     */
    - (NSString*)description {
        return "Property[" + getName() + "]";
    }

}


@end
