/*
 * AbstractReadableInstantFieldProperty.h
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
@class HLInterval;
@protocol HLReadableInstant;
@protocol HLReadablePartial;

/**
 * AbstractReadableInstantFieldProperty is a base class for binding a
 * ReadableInstant to a DateTimeField.
 * <p>
 * It allows the date and time manipulation code to be field based yet
 * still easy to use.
 * <p>
 * AbstractReadableInstantFieldProperty itself is thread-safe and immutable,
 * but the ReadableInstant being operated on may be mutable and not
 * thread-safe.
 *
 * @author Stephen Colebourne
 * @author Brian S O'Neill
 * @author Mike Schrag
 * @since 1.0
 */
@interface HLAbstractReadableInstantFieldProperty : NSObject {
    
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
 * Gets the milliseconds of the datetime that this property is linked to.
 * 
 * @return the milliseconds
 */
- (NSInteger)millis;

/**
 * Gets the chronology of the datetime that this property is linked to.
 * <p>
 * This implementation throws UnsupportedOperationException, and must be
 * implemented by subclasses to enable the equals() and hashCode() methods.
 * 
 * @return the chronology
 * @since 1.4
 */
- (HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 * Gets the value of this property from the instant.
 * <p>
 * For example, the following two lines of code are equivalent:
 * <pre>
 * datetime.getDayOfMonth();
 * datetime.dayOfMonth().get();
 * </pre>
 * 
 * @return the current value
 * @see DateTimeField#get
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
 * Returns the difference between this field property instant and the one
 * passed in, in the units of this field. The sign of the difference
 * matches that of compareTo. In other words, this field property's instant
 * is the minuend.
 *
 * @param instant  the subtrahend, nil means now
 * @return the difference in the units of this field
 * @see DateTimeField#getDifference
 */
- (NSInteger)differenceWithInstant:(id<HLReadableInstant>)instant;

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

/**
 * Gets whether this field is leap.
 * 
 * @return true if a leap field
 * @see DateTimeField#isLeap
 */
- (BOOL)isLeap;

/**
 * Gets the amount by which this field is leap.
 * 
 * @return the amount by which the field is leap
 * @see DateTimeField#getLeapAmount
 */
- (NSInteger)leapAmount;

/**
 * If this field were to leap, then it would be in units described by the
 * returned duration. If this field doesn't ever leap, nil is returned.
 */
- (HLDurationField*)leapDurationField;

//-----------------------------------------------------------------------
/**
 * Gets the minimum value for the field ignoring the current time.
 * 
 * @return the minimum value
 * @see DateTimeField#getMinimumValue
 */
- (NSInteger)minimumValueOverall;

/**
 * Gets the minimum value for the field.
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
 * Gets the maximum value for the field.
 * 
 * @return the maximum value
 * @see DateTimeField#getMaximumValue
 */
- (NSInteger)maximumValue;

/**
 * Gets the maximum text length for the field.
 * 
 * @param locale  optional locale to use for selecting a text symbol
 * @return the maximum length
 * @see DateTimeField#getMaximumTextLength
 */
- (NSInteger)getMaximumTextLengthWithLocale:(NSLocale*)locale;

/**
 * Gets the maximum short text length for the field.
 * 
 * @param locale  optional locale to use for selecting a text symbol
 * @return the maximum length
 * @see DateTimeField#getMaximumShortTextLength
 */
- (NSInteger)getMaximumShortTextLengthWithLocale:(NSLocale*)locale;

/**
 * Returns the fractional duration milliseconds of this field.
 *
 * @see DateTimeField#remainder
 * @return remainder duration, in milliseconds
 */
- (NSInteger)remainder;

/**
 * Returns the interval that represents the range of the minimum
 * and maximum values of this field.
 * <p>
 * For example, <code>datetime.monthOfYear().toInterval()</code>
 * will return an interval over the whole month.
 *
 * @return the interval of this field
 * @since 1.2
 */
- (HLInterval*)toInterval;

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
 * @throws IllegalArgumentException if the instant is nil
 */
- (NSInteger)compareToInstant:(id<HLReadableInstant>)instant;

//-----------------------------------------------------------------------
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
 * @throws IllegalArgumentException if the partial is nil
 * @throws IllegalArgumentException if the partial doesn't support this field
 */
- (NSInteger)compareToPartial:(id<HLReadablePartial>)partial;

//-----------------------------------------------------------------------
/**
 * Compares this property to another.
 * 
 * @param object  the object to compare to
 * @return true if equal
 */
- (BOOL)isEqualTo:(id)object;

/**
 * Returns a hashcode compatible with the equals method.
 * 
 * @return the hashcode
 */
- (NSUInteger)hash;

@end
