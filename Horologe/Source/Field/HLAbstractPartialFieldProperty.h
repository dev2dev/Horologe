/*
 * AbstractPartialFieldProperty.h
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


@class HLDateTimeField;
@class HLDateTimeFieldType;
@class HLDurationField;
@protocol HLReadablePartial;
@protocol HLReadableInstant;

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
@interface HLAbstractPartialFieldProperty : NSObject {
    
@private
    
}

//-----------------------------------------------------------------------
/**
 * Gets the field being used.
 * 
 * @return the field
 */
- (HLDateTimeField*)field;

/**
 * Gets the field type being used.
 * 
 * @return the field type
 */
- (HLDateTimeFieldType*)fieldType;

/**
 * Gets the name of the field.
 * 
 * @return the field name
 */
- (NSString*)name;

/**
 * Gets the partial instant being used.
 * 
 * @return the partial instant
 */
- (id<HLReadablePartial>)readablePartial;

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
- (NSInteger)value;

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
- (NSString*)valueAsString;

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
- (NSString*)valueAsText;

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
- (NSString*)valueAsTextWithLocale:(NSLocale*)locale;

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
- (NSString*)valueAsShortText;

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
- (NSString*)valueAsShortTextWithLocale:(NSLocale*)locale;

//-----------------------------------------------------------------------
/**
 * Returns the duration per unit value of this field. For example, if this
 * field represents "hour of day", then the duration is an hour.
 *
 * @return the duration of this field, or UnsupportedDurationField
 */
- (HLDurationField*)durationField;

/**
 * Returns the range duration of this field. For example, if this field
 * represents "hour of day", then the range duration is a day.
 *
 * @return the range duration of this field, or nil if field has no range
 */
- (HLDurationField*)rangeDurationField;

//-----------------------------------------------------------------------
/**
 * Gets the minimum value for the field ignoring the current time.
 * 
 * @return the minimum value
 * @see DateTimeField#getMinimumValue
 */
- (NSInteger)minimumValueOverall;

/**
 * Gets the minimum value for this field given the current field values.
 * 
 * @return the minimum value
 * @see DateTimeField#getMinimumValue
 */
- (NSInteger)minimumValue;

/**
 * Gets the maximum value for the field ignoring the current time.
 * 
 * @return the maximum value
 * @see DateTimeField#getMaximumValue
 */
- (NSInteger)maximumValueOverall;

/**
 * Gets the maximum value for this field given the current field values.
 * 
 * @return the maximum value
 * @see DateTimeField#getMaximumValue
 */
- (NSInteger)maximumValue;

//-----------------------------------------------------------------------
/**
 * Gets the maximum text length for the field.
 * 
 * @param locale  optional locale to use for selecting a text symbol
 * @return the maximum length
 * @see DateTimeField#getMaximumTextLength
 */
- (NSInteger)maximumTextLengthWithLocale:(NSLocale*)locale;

/**
 * Gets the maximum short text length for the field.
 * 
 * @param locale  optional locale to use for selecting a text symbol
 * @return the maximum length
 * @see DateTimeField#getMaximumShortTextLength
 */
- (NSInteger)maximumShortTextLengthWithLocale:(NSLocale*)locale;

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
- (NSComparisonResult)compareToInstant:(id<HLReadableInstant>)instant;

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
- (NSComparisonResult)compareToPartial:(id<HLReadablePartial>)partial;

//-----------------------------------------------------------------------
/**
 * Compares this property to another.
 * 
 * @param object  the object to compare to
 * @return true if equal
 */
- (BOOL)isEqualTo:(id)object;

//-----------------------------------------------------------------------
/**
 * Gets a suitable hashcode for the object.
 * 
 * @return the hashcode
 * @since 1.3
 */
- (NSUInteger)hash;

@end
