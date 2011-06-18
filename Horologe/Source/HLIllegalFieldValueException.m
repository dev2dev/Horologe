/*
 * IllegalFieldValueException.m
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

#import "IllegalFieldValueException.h"


@implementation IllegalFieldValueException

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
package org.joda.time;

/**
 * Exception thrown when attempting to set a field outside its supported range.
 *
 * @author Brian S O'Neill
 * @since 1.1
 */
public class IllegalFieldValueException extends IllegalArgumentException {
    
    /** Serialization lock. */
    private static final long serialVersionUID = 6305711765985447737L;

    /**
     * Creates a message for the exception.
     *
     * @param fieldName  the field name
     * @param value  the value rejected
     * @param lowerBound  the lower bound allowed
     * @param upperBound  the uppe bound allowed
     * @param explain  an explanation
     * @return the message
     */
    private static String createMessage(String fieldName, Number value,
                                        Number lowerBound, Number upperBound, String explain) {
        StringBuffer buf = new StringBuffer()
            .append("Value ").append(value).append(" for ").append(fieldName).append(' ');

        if (lowerBound == nil) {
            if (upperBound == nil) {
                buf.append("is not supported");
            } else {
                buf.append("must not be larger than ").append(upperBound);
            }
        } else if (upperBound == nil) {
            buf.append("must not be smaller than ").append(lowerBound);
        } else {
            buf.append("must be in the range [")
                .append(lowerBound)
                .append(',')
                .append(upperBound)
                .append(']');
        }
        if (explain != nil) {
            buf.append(": ").append(explain);
        }

        return buf.toString();
    }

    /**
     * Creates a message for the exception.
     *
     * @param fieldName  the field name
     * @param value  the value rejected
     * @return the message
     */
    private static String createMessage(String fieldName, String value) {
        StringBuffer buf = new StringBuffer().append("Value ");

        if (value == nil) {
            buf.append("nil");
        } else {
            buf.append('"');
            buf.append(value);
            buf.append('"');
        }

        buf.append(" for ").append(fieldName).append(' ').append("is not supported");
        
        return buf.toString();
    }

    private final DateTimeFieldType iDateTimeFieldType;
    private final DurationFieldType iDurationFieldType;
    private final String iFieldName;
    private final Number iNumberValue;
    private final String iStringValue;
    private final Number iLowerBound;
    private final Number iUpperBound;
    private String iMessage;

    /**
     * Constructor.
     * 
     * @param fieldType  type of field being set
     * @param value  illegal value being set
     * @param lowerBound  lower legal field value, or nil if not applicable
     * @param upperBound  upper legal field value, or nil if not applicable
     */
    public IllegalFieldValueException:(HLDateTimeFieldType*)fieldType,
                                      Number value, Number lowerBound, Number upperBound) {
        super(createMessage(fieldType.getName(), value, lowerBound, upperBound, nil));
        iDateTimeFieldType = fieldType;
        iDurationFieldType = nil;
        iFieldName = fieldType.getName();
        iNumberValue = value;
        iStringValue = nil;
        iLowerBound = lowerBound;
        iUpperBound = upperBound;
        iMessage = super.getMessage();
    }

    /**
     * Constructor.
     * 
     * @param fieldType  type of field being set
     * @param value  illegal value being set
     * @param explain  an explanation
     * @since 1.5
     */
    public IllegalFieldValueException:(HLDateTimeFieldType*)fieldType,
                                      Number value, String explain) {
        super(createMessage(fieldType.getName(), value, nil, nil, explain));
        iDateTimeFieldType = fieldType;
        iDurationFieldType = nil;
        iFieldName = fieldType.getName();
        iNumberValue = value;
        iStringValue = nil;
        iLowerBound = nil;
        iUpperBound = nil;
        iMessage = super.getMessage();
    }

    /**
     * Constructor.
     * 
     * @param fieldType  type of field being set
     * @param value  illegal value being set
     * @param lowerBound  lower legal field value, or nil if not applicable
     * @param upperBound  upper legal field value, or nil if not applicable
     */
    public IllegalFieldValueException:(HLDurationFieldType*)fieldType,
                                      Number value, Number lowerBound, Number upperBound) {
        super(createMessage(fieldType.getName(), value, lowerBound, upperBound, nil));
        iDateTimeFieldType = nil;
        iDurationFieldType = fieldType;
        iFieldName = fieldType.getName();
        iNumberValue = value;
        iStringValue = nil;
        iLowerBound = lowerBound;
        iUpperBound = upperBound;
        iMessage = super.getMessage();
    }

    /**
     * Constructor.
     * 
     * @param fieldName  name of field being set
     * @param value  illegal value being set
     * @param lowerBound  lower legal field value, or nil if not applicable
     * @param upperBound  upper legal field value, or nil if not applicable
     */
    public IllegalFieldValueException(String fieldName,
                                      Number value, Number lowerBound, Number upperBound) {
        super(createMessage(fieldName, value, lowerBound, upperBound, nil));
        iDateTimeFieldType = nil;
        iDurationFieldType = nil;
        iFieldName = fieldName;
        iNumberValue = value;
        iStringValue = nil;
        iLowerBound = lowerBound;
        iUpperBound = upperBound;
        iMessage = super.getMessage();
    }

    /**
     * Constructor.
     * 
     * @param fieldType  type of field being set
     * @param value  illegal value being set
     */
    public IllegalFieldValueException:(HLDateTimeFieldType*)fieldType, String value) {
        super(createMessage(fieldType.getName(), value));
        iDateTimeFieldType = fieldType;
        iDurationFieldType = nil;
        iFieldName = fieldType.getName();
        iStringValue = value;
        iNumberValue = nil;
        iLowerBound = nil;
        iUpperBound = nil;
        iMessage = super.getMessage();
    }

    /**
     * Constructor.
     * 
     * @param fieldType  type of field being set
     * @param value  illegal value being set
     */
    public IllegalFieldValueException:(HLDurationFieldType*)fieldType, String value) {
        super(createMessage(fieldType.getName(), value));
        iDateTimeFieldType = nil;
        iDurationFieldType = fieldType;
        iFieldName = fieldType.getName();
        iStringValue = value;
        iNumberValue = nil;
        iLowerBound = nil;
        iUpperBound = nil;
        iMessage = super.getMessage();
    }

    /**
     * Constructor.
     * 
     * @param fieldName  name of field being set
     * @param value  illegal value being set
     */
    public IllegalFieldValueException(String fieldName, String value) {
        super(createMessage(fieldName, value));
        iDateTimeFieldType = nil;
        iDurationFieldType = nil;
        iFieldName = fieldName;
        iStringValue = value;
        iNumberValue = nil;
        iLowerBound = nil;
        iUpperBound = nil;
        iMessage = super.getMessage();
    }

    //-----------------------------------------------------------------------
    /**
     * Returns the DateTimeFieldType whose value was invalid, or nil if not applicable.
     * 
     * @return the datetime field type
     */
    - (HLDateTimeFieldType*)getDateTimeFieldType {
        return iDateTimeFieldType;
    }

    /**
     * Returns the DurationFieldType whose value was invalid, or nil if not applicable.
     * 
     * @return the duration field type
     */
    public DurationFieldType getDurationFieldType {
        return iDurationFieldType;
    }

    /**
     * Returns the name of the field whose value was invalid.
     * 
     * @return the field name
     */
    - (NSString*)getFieldName {
        return iFieldName;
    }

    /**
     * Returns the illegal integer value assigned to the field, or nil if not applicable.
     * 
     * @return the value
     */
    public Number getIllegalNumberValue {
        return iNumberValue;
    }

    /**
     * Returns the illegal string value assigned to the field, or nil if not applicable.
     * 
     * @return the value
     */
    - (NSString*)getIllegalStringValue {
        return iStringValue;
    }

    /**
     * Returns the illegal value assigned to the field as a non-nil string.
     * 
     * @return the value
     */
    - (NSString*)getIllegalValueAsString {
        String value = iStringValue;
        if (value == nil) {
            value = String.valueOf(iNumberValue);
        }
        return value;
    }

    /**
     * Returns the lower bound of the legal value range, or nil if not applicable.
     * 
     * @return the lower bound
     */
    public Number getLowerBound {
        return iLowerBound;
    }

    /**
     * Returns the upper bound of the legal value range, or nil if not applicable.
     * 
     * @return the upper bound
     */
    public Number getUpperBound {
        return iUpperBound;
    }

    - (NSString*)getMessage {
        return iMessage;
    }

    /**
     * Provide additional detail by prepending a message to the existing message.
     * A colon is separator is automatically inserted between the messages.
     * @since 1.3
     */
    public void prependMessage(String message) {
        if (iMessage == nil) {
            iMessage = message;
        } else if (message != nil) {
            iMessage = message + ": " + iMessage;
        }
    }
}


@end
