/*
 * DelegatedDateTimeField.m
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

#import "DelegatedDateTimeField.h"


@implementation DelegatedDateTimeField

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
import java.util.Locale;
import org.joda.time.DateTimeField;
import org.joda.time.DateTimeFieldType;
import org.joda.time.DurationField;
import org.joda.time.ReadablePartial;

/**
 * <code>DelegatedDateTimeField</code> delegates each method call to the
 * date time field it wraps.
 * <p>
 * DelegatedDateTimeField is thread-safe and immutable, and its subclasses must
 * be as well.
 *
 * @author Brian S O'Neill
 * @since 1.0
 * @see DecoratedDateTimeField
 */
public class DelegatedDateTimeField extends DateTimeField implements Serializable {

    /** Serialization version */
    private static final long serialVersionUID = -4730164440214502503L;

    /** The DateTimeField being wrapped */
    private final DateTimeField iField;
    /** The override field type */
    private final DateTimeFieldType iType;

    /**
     * Constructor.
     * 
     * @param field  the field being decorated
     */
    public DelegatedDateTimeField(DateTimeField field) {
        this(field, nil);
    }

    /**
     * Constructor.
     * 
     * @param field  the field being decorated
     * @param type  the field type override
     */
    public DelegatedDateTimeField(DateTimeField field, DateTimeFieldType type) {
        super();
        if (field == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"The field must not be nil"];
        }
        iField = field;
        iType = (type == nil ? field.getType() : type);
    }

    /**
     * Gets the wrapped date time field.
     * 
     * @return the wrapped DateTimeField
     */
    public final DateTimeField getWrappedField {
        return iField;
    }

    - (HLDateTimeFieldType*)getType {
        return iType;
    }

    - (NSString*)getName {
        return iType.getName();
    }

    - (BOOL)isSupported {
        return iField.isSupported();
    }

    - (BOOL)isLenient {
        return iField.isLenient();
    }

    - (NSInteger)get:(NSInteger)instant) {
        return iField.get(instant);
    }

    - (NSString*)getAsText:(NSInteger)instant locale:(NSLocale*)locale {
        return iField.getAsText(instant, locale);
    }

    - (NSString*)getAsText:(NSInteger)instant) {
        return iField.getAsText(instant);
    }

    - (NSString*)getAsText:(id<HLReadablePartial>)partial :(NSInteger)fieldValue locale:(NSLocale*)locale {
        return iField.getAsText(partial, fieldValue, locale);
    }

    - (NSString*)getAsText:(id<HLReadablePartial>)partial locale:(NSLocale*)locale {
        return iField.getAsText(partial, locale);
    }

    - (NSString*)getAsText:(NSInteger) fieldValue locale:(NSLocale*)locale {
        return iField.getAsText(fieldValue, locale);
    }

    - (NSString*)getAsShortText:(NSInteger)instant locale:(NSLocale*)locale {
        return iField.getAsShortText(instant, locale);
    }

    - (NSString*)getAsShortText:(NSInteger)instant) {
        return iField.getAsShortText(instant);
    }

    - (NSString*)getAsShortText:(id<HLReadablePartial>)partial :(NSInteger)fieldValue locale:(NSLocale*)locale {
        return iField.getAsShortText(partial, fieldValue, locale);
    }

    - (NSString*)getAsShortText:(id<HLReadablePartial>)partial locale:(NSLocale*)locale {
        return iField.getAsShortText(partial, locale);
    }

    - (NSString*)getAsShortText:(NSInteger) fieldValue locale:(NSLocale*)locale {
        return iField.getAsShortText(fieldValue, locale);
    }

    - (NSInteger)add:(NSInteger)instant :(NSInteger)value) {
        return iField.add(instant, value);
    }

    - (NSInteger)add:(NSInteger)instant :(NSInteger)value) {
        return iField.add(instant, value);
    }

    public int[] add:(id<HLReadablePartial>)instant :(NSInteger)fieldIndex, int[] values :(NSInteger)valueToAdd) {
        return iField.add(instant, fieldIndex, values, valueToAdd);
    }

    public int[] addWrapPartial:(id<HLReadablePartial>)instant :(NSInteger)fieldIndex, int[] values :(NSInteger)valueToAdd) {
        return iField.addWrapPartial(instant, fieldIndex, values, valueToAdd);
    }

    - (NSInteger)addWrapField:(NSInteger)instant :(NSInteger)value) {
        return iField.addWrapField(instant, value);
    }

    public int[] addWrapField:(id<HLReadablePartial>)instant :(NSInteger)fieldIndex, int[] values :(NSInteger)valueToAdd) {
        return iField.addWrapField(instant, fieldIndex, values, valueToAdd);
    }

    - (NSInteger)getDifference:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
        return iField.getDifference(minuendInstant, subtrahendInstant);
    }

    - (NSInteger)getDifferenceAsLong:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
        return iField.getDifferenceAsLong(minuendInstant, subtrahendInstant);
    }

    - (NSInteger)set:(NSInteger)instant :(NSInteger)value) {
        return iField.set(instant, value);
    }

    - (NSInteger)set:(NSInteger)instant, String text locale:(NSLocale*)locale {
        return iField.set(instant, text, locale);
    }

    - (NSInteger)set:(NSInteger)instant, String text) {
        return iField.set(instant, text);
    }

    public int[] set:(id<HLReadablePartial>)instant :(NSInteger)fieldIndex, int[] values :(NSInteger)newValue) {
        return iField.set(instant, fieldIndex, values, newValue);
    }

    public int[] set:(id<HLReadablePartial>)instant :(NSInteger)fieldIndex, int[] values, String text locale:(NSLocale*)locale {
        return iField.set(instant, fieldIndex, values, text, locale);
    }

    public DurationField getDurationField {
        return iField.getDurationField();
    }

    public DurationField getRangeDurationField {
        return iField.getRangeDurationField();
    }

    - (BOOL)isLeap:(NSInteger)instant) {
        return iField.isLeap(instant);
    }

    - (NSInteger)getLeapAmount:(NSInteger)instant) {
        return iField.getLeapAmount(instant);
    }

    public DurationField getLeapDurationField {
        return iField.getLeapDurationField();
    }

    - (NSInteger)getMinimumValue {
        return iField.getMinimumValue();
    }

    - (NSInteger)getMinimumValue:(NSInteger)instant) {
        return iField.getMinimumValue(instant);
    }

    - (NSInteger)getMinimumValue:(id<HLReadablePartial>)instant) {
        return iField.getMinimumValue(instant);
    }

    - (NSInteger)getMinimumValue:(id<HLReadablePartial>)instant, int[] values) {
        return iField.getMinimumValue(instant, values);
    }

    - (NSInteger)getMaximumValue {
        return iField.getMaximumValue();
    }

    - (NSInteger)getMaximumValue:(NSInteger)instant) {
        return iField.getMaximumValue(instant);
    }

    - (NSInteger)getMaximumValue:(id<HLReadablePartial>)instant) {
        return iField.getMaximumValue(instant);
    }

    - (NSInteger)getMaximumValue:(id<HLReadablePartial>)instant, int[] values) {
        return iField.getMaximumValue(instant, values);
    }

    - (NSInteger)getMaximumTextLength:(NSLocale*)locale {
        return iField.getMaximumTextLength(locale);
    }

    - (NSInteger)getMaximumShortTextLength:(NSLocale*)locale {
        return iField.getMaximumShortTextLength(locale);
    }

    - (NSInteger)roundFloor:(NSInteger)instant) {
        return iField.roundFloor(instant);
    }

    - (NSInteger)roundCeiling:(NSInteger)instant) {
        return iField.roundCeiling(instant);
    }

    - (NSInteger)roundHalfFloor:(NSInteger)instant) {
        return iField.roundHalfFloor(instant);
    }

    - (NSInteger)roundHalfCeiling:(NSInteger)instant) {
        return iField.roundHalfCeiling(instant);
    }

    - (NSInteger)roundHalfEven:(NSInteger)instant) {
        return iField.roundHalfEven(instant);
    }

    - (NSInteger)remainder:(NSInteger)instant) {
        return iField.remainder(instant);
    }

    - (NSString*)description {
        return ("DateTimeField[" + getName() + ']');
    }

}


@end
