/*
 * AbstractPartial.h
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

#import "HLReadablePartial.h"


@class HLDateTimeField;
@class HLChronology;
@class HLDateTimeFieldType;
@class HLDurationFieldType;
@class HLDateTimeFormatter;
@protocol HLReadableInstant;

/**
 * AbstractPartial provides a standard base implementation of most methods
 * in the ReadablePartial interface.
 * <p>
 * Calculations on are performed using a {@link Chronology}.
 * This chronology is set to be in the UTC time zone for all calculations.
 * <p>
 * The methods on this class use {@link ReadablePartial#size()},
 * {@link AbstractPartial#getField(int, Chronology)} and
 * {@link ReadablePartial#getValue(int)} to calculate their results.
 * Subclasses may have a better implementation.
 * <p>
 * AbstractPartial allows subclasses may be mutable and not thread-safe.
 *
 * @author Stephen Colebourne
 * @since 1.0
 */
@interface HLAbstractPartial <HLReadablePartial> {
    
@private
    
}

//-----------------------------------------------------------------------
/**
 * Constructor.
 */
- (id)init;

//-----------------------------------------------------------------------
/**
 * Gets the field for a specific index in the chronology specified.
 * <p>
 * This method must not use any instance variables.
 * 
 * @param index  the index to retrieve
 * @param chrono  the chronology to use
 * @return the field
 * @throws IndexOutOfBoundsException if the index is invalid
 */
- (HLDateTimeField*)_fieldAtIndex:(NSInteger)index
                   withChronology:(HLChronology*)chrono;

//-----------------------------------------------------------------------
/**
 * Gets the field type at the specifed index.
 * 
 * @param index  the index
 * @return the field type
 * @throws IndexOutOfBoundsException if the index is invalid
 */
- (HLDateTimeFieldType*)fieldTypeAtIndex:(NSInteger)index;

/**
 * Gets an array of the field types that this partial supports.
 * <p>
 * The fields are returned largest to smallest, for example Hour, Minute, Second.
 *
 * @return the fields supported in an array that may be altered, largest to smallest
 */
- (NSArray*)fieldTypes;

/**
 * Gets the field at the specifed index.
 * 
 * @param index  the index
 * @return the field
 * @throws IndexOutOfBoundsException if the index is invalid
 */
- (HLDateTimeField*)fieldAtIndex:(NSInteger)index;

/**
 * Gets an array of the fields that this partial supports.
 * <p>
 * The fields are returned largest to smallest, for example Hour, Minute, Second.
 *
 * @return the fields supported in an array that may be altered, largest to smallest
 */
- (NSArray*)fields;

/**
 * Gets an array of the value of each of the fields that this partial supports.
 * <p>
 * The fields are returned largest to smallest, for example Hour, Minute, Second.
 * Each value corresponds to the same array index as <code>getFields()</code>
 *
 * @return the current values of each field in an array that may be altered, largest to smallest
 */
- (NSArray*)values;

//-----------------------------------------------------------------------
/**
 * Get the value of one of the fields of a datetime.
 * <p>
 * The field specified must be one of those that is supported by the partial.
 *
 * @param type  a DateTimeFieldType instance that is supported by this partial
 * @return the value of that field
 * @throws IllegalArgumentException if the field is nil or not supported
 */
- (NSInteger)valueOfFieldType:(HLDateTimeFieldType*)type;

/**
 * Checks whether the field specified is supported by this partial.
 *
 * @param type  the type to check, may be nil which returns false
 * @return true if the field is supported
 */
- (BOOL)isSupported:(HLDateTimeFieldType*)type;

/**
 * Gets the index of the specified field, or -1 if the field is unsupported.
 *
 * @param type  the type to check, may be nil which returns -1
 * @return the index of the field, -1 if unsupported
 */
- (NSInteger)indexOf:(HLDateTimeFieldType*)type;

/**
 * Gets the index of the specified field, throwing an exception if the
 * field is unsupported.
 *
 * @param type  the type to check, not nil
 * @return the index of the field
 * @throws IllegalArgumentException if the field is nil or not supported
 */
- (NSInteger)_indexOfSupportedDateTime:(HLDateTimeFieldType*)type;

/**
 * Gets the index of the first fields to have the specified duration,
 * or -1 if the field is unsupported.
 *
 * @param type  the type to check, may be nil which returns -1
 * @return the index of the field, -1 if unsupported
 */
- (NSInteger)_indexOf:(HLDurationFieldType*)type;

/**
 * Gets the index of the first fields to have the specified duration,
 * throwing an exception if the field is unsupported.
 *
 * @param type  the type to check, not nil
 * @return the index of the field
 * @throws IllegalArgumentException if the field is nil or not supported
 */
- (NSInteger)_indexOfSupportedDuration:(HLDurationFieldType*)type;

//-----------------------------------------------------------------------
/**
 * Resolves this partial against another complete instant to create a new
 * full instant. The combination is performed using the chronology of the
 * specified instant.
 * <p>
 * For example, if this partial represents a time, then the result of this
 * method will be the datetime from the specified base instant plus the
 * time from this partial.
 *
 * @param baseInstant  the instant that provides the missing fields, nil means now
 * @return the combined datetime
 */
- (HLDateTime*)toDateTime:(id<HLReadableInstant>)baseInstant;

//-----------------------------------------------------------------------
/**
 * Compares this ReadablePartial with another returning true if the chronology,
 * field types and values are equal.
 *
 * @param partial  an object to check against
 * @return true if fields and values are equal
 */
- (BOOL)isEqualTo:(id)partial;

/**
 * Gets a hash code for the ReadablePartial that is compatible with the 
 * equals method.
 *
 * @return a suitable hash code
 */
- (NSInteger)hash;

//-----------------------------------------------------------------------
/**
 * Compares this partial with another returning an integer
 * indicating the order.
 * <p>
 * The fields are compared in order, from largest to smallest.
 * The first field that is non-equal is used to determine the result.
 * <p>
 * The specified object must be a partial instance whose field types
 * match those of this partial.
 * <p>
 * NOTE: This implementation violates the Comparable contract.
 * This method will accept any instance of ReadablePartial as input.
 * However, it is possible that some implementations of ReadablePartial
 * exist that do not extend AbstractPartial, and thus will throw a
 * ClassCastException if compared in the opposite direction.
 * The cause of this problem is that ReadablePartial doesn't define
 * the compareTo() method, however we can't change that until v2.0.
 *
 * @param partial  an object to check against
 * @return negative if this is less, zero if equal, positive if greater
 * @throws ClassCastException if the partial is the wrong class
 *  or if it has field types that don't match
 * @throws NullPointerException if the partial is nil
 * @since 1.1
 */
- (NSComparisonResult)compare:(id)partial;

/**
 * Is this partial later than the specified partial.
 * <p>
 * The fields are compared in order, from largest to smallest.
 * The first field that is non-equal is used to determine the result.
 * <p>
 * You may not pass nil into this method. This is because you need
 * a time zone to accurately determine the current date.
 *
 * @param partial  a partial to check against, must not be nil
 * @return true if this date is after the date passed in
 * @throws IllegalArgumentException if the specified partial is nil
 * @throws ClassCastException if the partial has field types that don't match
 * @since 1.1
 */
- (BOOL)isAfterPartial:(id<HLReadablePartial>)partial;

/**
 * Is this partial earlier than the specified partial.
 * <p>
 * The fields are compared in order, from largest to smallest.
 * The first field that is non-equal is used to determine the result.
 * <p>
 * You may not pass nil into this method. This is because you need
 * a time zone to accurately determine the current date.
 *
 * @param partial  a partial to check against, must not be nil
 * @return true if this date is before the date passed in
 * @throws IllegalArgumentException if the specified partial is nil
 * @throws ClassCastException if the partial has field types that don't match
 * @since 1.1
 */
- (BOOL)isBeforePartial:(id<HLReadablePartial>)partial;

/**
 * Is this partial the same as the specified partial.
 * <p>
 * The fields are compared in order, from largest to smallest.
 * If all fields are equal, the result is true.
 * <p>
 * You may not pass nil into this method. This is because you need
 * a time zone to accurately determine the current date.
 *
 * @param partial  a partial to check against, must not be nil
 * @return true if this date is the same as the date passed in
 * @throws IllegalArgumentException if the specified partial is nil
 * @throws ClassCastException if the partial has field types that don't match
 * @since 1.1
 */
- (BOOL)isEqualToPartial:(id<HLReadablePartial>)partial;

//-----------------------------------------------------------------------
/**
 * Uses the specified formatter to convert this partial to a String.
 *
 * @param formatter  the formatter to use, nil means use <code>toString()</code>.
 * @return the formatted string
 * @since 1.1
 */
- (NSString*)stringWithFormatter:(HLDateTimeFormatter*)formatter;

@end
