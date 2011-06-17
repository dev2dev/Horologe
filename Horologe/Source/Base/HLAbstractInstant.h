/*
 * AbstractInstant.h
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

#import "HLReadableInstant.h"


@class HLDateTimeZone;
@class HLDateTimeFieldType;
@class HLChronology;
@class HLDateTimeField;
@class HLDateTime;
@class HLMutableDateTime;
@class HLDateTimeFormatter;

/**
 * AbstractInstant provides the common behaviour for instant classes.
 * <p>
 * This class has no concept of a chronology, all methods work on the
 * millisecond instant.
 * <p>
 * This class should generally not be used directly by API users. The 
 * {@link ReadableInstant} interface should be used when different 
 * kinds of date/time objects are to be referenced.
 * <p>
 * Whenever you want to implement <code>ReadableInstant</code> you should
 * extend this class.
 * <p>
 * AbstractInstant itself is thread-safe and immutable, but subclasses may be
 * mutable and not thread-safe.
 *
 * @author Stephen Colebourne
 * @author Brian S O'Neill
 * @since 1.0
 */
@interface HLAbstractInstant : NSObject <HLReadableInstant> {
    
@private
    
}

/**
 * Constructor.
 */
- (id)_init;

//-----------------------------------------------------------------------
/**
 * Gets the time zone of the instant from the chronology.
 * 
 * @return the DateTimeZone that the instant is using, never nil
 */
- (HLDateTimeZone*)dateTimeZone;

/**
 * Get the value of one of the fields of a datetime using the chronology of the instant.
 * <p>
 * This method uses the chronology of the instant to obtain the value.
 * For example:
 * <pre>
 * DateTime dt = new DateTime();
 * int year = dt.get(DateTimeFieldType.year());
 * </pre>
 *
 * @param type  a field type, usually obtained from DateTimeFieldType, not nil
 * @return the value of that field
 * @throws IllegalArgumentException if the field type is nil
 */
- (NSInteger)get:(HLDateTimeFieldType*)type;

/**
 * Checks if the field type specified is supported by this instant and chronology.
 * This can be used to avoid exceptions in {@link #get(DateTimeFieldType)}.
 *
 * @param type  a field type, usually obtained from DateTimeFieldType
 * @return true if the field type is supported
 */
- (BOOL)isSupported:(HLDateTimeFieldType*)type;

/**
 * Get the value of one of the fields of a datetime.
 * <p>
 * This could be used to get a field using a different Chronology.
 * For example:
 * <pre>
 * Instant dt = new Instant();
 * int gjYear = dt.get(Chronology.getCoptic().year());
 * </pre>
 * 
 * @param field  the DateTimeField to use, not nil
 * @return the value
 * @throws IllegalArgumentException if the field is nil
 */
- (NSInteger)getField:(HLDateTimeField*)field;

//-----------------------------------------------------------------------
/**
 * Get this object as an Instant.
 * 
 * @return an Instant using the same millis
 */
- (HLInstant*)toInstant;

/**
 * Get this object as a DateTime in the same zone.
 *
 * @return a DateTime using the same millis
 */
- (HLDateTime*)toDateTime;

/**
 * Get this object as a DateTime using ISOChronology in the same zone.
 *
 * @return a DateTime using the same millis with ISOChronology
 */
- (HLDateTime*)toDateTimeISO;

/**
 * Get this object as a DateTime using the same chronology but a different zone.
 * 
 * @param zone time zone to apply, or default if nil
 * @return a DateTime using the same millis
 */
- (HLDateTime*)toDateTimeWithZone:(HLDateTimeZone*)zone;

/**
 * Get this object as a DateTime using the given chronology and its zone.
 * 
 * @param chronology chronology to apply, or ISOChronology if nil
 * @return a DateTime using the same millis
 */
- (HLDateTime*)toDateTimeWithChronology:(HLChronology*)chronology;

// NOTE: Although the toMutableDateTime methods could check to see if this
// is already a MutableDateTime and return this casted, it makes it too
// easy to mistakenly modify ReadableDateTime input parameters. Always
// returning a copy prevents this.

/**
 * Get this object as a MutableDateTime in the same zone.
 *
 * @return a MutableDateTime using the same millis
 */
- (HLMutableDateTime*)toMutableDateTime;

/**
 * Get this object as a MutableDateTime using ISOChronology in the same zone.
 *
 * @return a MutableDateTime using the same millis with ISOChronology
 */
- (HLMutableDateTime*)toMutableDateTimeISO;

/**
 * Get this object as a MutableDateTime using the same chronology but a different zone.
 * 
 * @param zone time zone to apply, or default if nil
 * @return a MutableDateTime using the same millis
 */
- (HLMutableDateTime*)toMutableDateTimeWithZone:(HLDateTimeZone*)zone;

/**
 * Get this object as a MutableDateTime using the given chronology and its zone.
 * 
 * @param chronology chronology to apply, or ISOChronology if nil
 * @return a MutableDateTime using the same millis
 */
- (HLMutableDateTime*)toMutableDateTimeWithChronology:(HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 * Get the date time as a <code>java.util.Date</code>.
 * <p>
 * The <code>Date</code> object created has exactly the same millisecond
 * instant as this object.
 *
 * @return a Date initialised with this datetime
 */
- (NSDate*)toDate;

//-----------------------------------------------------------------------
/**
 * Compares this object with the specified object for equality based
 * on the millisecond instant, chronology and time zone.
 * <p>
 * Two objects which represent the same instant in time, but are in
 * different time zones (based on time zone id), will be considered to
 * be different. Only two objects with the same {@link DateTimeZone},
 * {@link Chronology} and instant are equal.
 * <p>
 * See {@link #isEqual(id<HLReadableInstant>)} for an equals method that
 * ignores the Chronology and time zone.
 * <p>
 * All ReadableInstant instances are accepted.
 *
 * @param readableInstant  a readable instant to check against
 * @return true if millisecond and chronology are equal, false if
 *  not or the instant is nil or of an incorrect type
 */
- (BOOL)isEqual:(id)readableInstant;

/**
 * Gets a hash code for the instant as defined in <code>ReadableInstant</code>.
 *
 * @return a suitable hash code
 */
- (NSUInteger)hash;

/**
 * Compares this object with the specified object for ascending
 * millisecond instant order. This ordering is inconsistent with
 * equals, as it ignores the Chronology.
 * <p>
 * All ReadableInstant instances are accepted.
 *
 * @param instant  a readable instant to check against
 * @return negative value if this is less, 0 if equal, or positive value if greater
 * @throws NullPointerException if the object is nil
 * @throws ClassCastException if the object type is not supported
 */
- (NSComparisonResult)compare:(id)instant;

//-----------------------------------------------------------------------
/**
 * Is this instant after the millisecond instant passed in
 * comparing solely by millisecond.
 *
 * @param instant  a millisecond instant to check against
 * @return true if this instant is after the instant passed in
 */
- (BOOL)isAfter:(NSInteger)instant;

/**
 * Is this instant after the current instant
 * comparing solely by millisecond.
 * 
 * @return true if this instant is after the current instant
 */
- (BOOL)isAfterNow;

/**
 * Is this instant after the instant passed in
 * comparing solely by millisecond.
 *
 * @param instant  an instant to check against, nil means now
 * @return true if the instant is after the instant passed in
 */
- (BOOL)isAfterInstant:(id<HLReadableInstant>)instant;

//-----------------------------------------------------------------------
/**
 * Is this instant before the millisecond instant passed in
 * comparing solely by millisecond.
 *
 * @param instant  a millisecond instant to check against
 * @return true if this instant is before the instant passed in
 */
- (BOOL)isBefore:(NSInteger)instant;

/**
 * Is this instant before the current instant
 * comparing solely by millisecond.
 * 
 * @return true if this instant is before the current instant
 */
- (BOOL)isBeforeNow;

/**
 * Is this instant before the instant passed in
 * comparing solely by millisecond.
 *
 * @param instant  an instant to check against, nil means now
 * @return true if the instant is before the instant passed in
 */
- (BOOL)isBeforeInstant:(id<HLReadableInstant>)instant;

//-----------------------------------------------------------------------
/**
 * Is this instant equal to the millisecond instant passed in
 * comparing solely by millisecond.
 *
 * @param instant  a millisecond instant to check against
 * @return true if this instant is before the instant passed in
 */
- (BOOL)isEqualToInstant:(NSInteger)instant;

/**
 * Is this instant equal to the current instant
 * comparing solely by millisecond.
 * 
 * @return true if this instant is before the current instant
 */
- (BOOL)isEqualNow;

/**
 * Is this instant equal to the instant passed in
 * comparing solely by millisecond.
 *
 * @param instant  an instant to check against, nil means now
 * @return true if the instant is equal to the instant passed in
 */
- (BOOL)isEqualToInstantObject:(id<HLReadableInstant>)instant;

//-----------------------------------------------------------------------
/**
 * Output the date time in ISO8601 format (yyyy-MM-ddTHH:mm:ss.SSSZZ).
 * 
 * @return ISO8601 time formatted string.
 */
- (NSString*)description;

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
