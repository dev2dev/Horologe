/*
 * BasePartial.h
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

#import "HLAbstractPartial.h"
#import "HLReadablePartial.h"


@class HLChronology;
@class HLDateTimeFormatter;

/**
 * BasePartial is an abstract implementation of ReadablePartial that stores
 * data in array and <code>Chronology</code> fields.
 * <p>
 * This class should generally not be used directly by API users.
 * The {@link org.joda.time.ReadablePartial} interface should be used when different 
 * kinds of partial objects are to be referenced.
 * <p>
 * BasePartial subclasses may be mutable and not thread-safe.
 *
 * @author Stephen Colebourne
 * @since 1.0
 */
@interface HLBasePartial : HLAbstractPartial <HLReadablePartial> {
    
@private
    /** The chronology in use */
    HLChronology* _iChronology;
    /** The values of each field in this partial */
    NSArray* _iValues;
    
}

//-----------------------------------------------------------------------
/**
 * Constructs a partial with the current time, using the specified chronology
 * and zone to extract the fields.
 * <p>
 * The constructor uses the time zone of the chronology specified.
 * Once the constructor is complete, all further calculations are performed
 * without reference to a timezone (by switching to UTC).
 *
 * @param chronology  the chronology, nil means ISOChronology in the default zone
 */
- (id)initWithChronology:(HLChronology*)chronology;

/**
 * Constructs a partial extracting the partial fields from the specified
 * milliseconds using the ISOChronology in the default zone.
 * <p>
 * The constructor uses the default time zone, resulting in the local time
 * being initialised. Once the constructor is complete, all further calculations
 * are performed without reference to a timezone (by switching to UTC).
 *
 * @param instant  the milliseconds from 1970-01-01T00:00:00Z
 */
- (id)initWithInstantValue:(NSInteger)instant;

/**
 * Constructs a partial extracting the partial fields from the specified
 * milliseconds using the chronology provided.
 * <p>
 * The constructor uses the time zone of the chronology specified.
 * Once the constructor is complete, all further calculations are performed
 * without reference to a timezone (by switching to UTC).
 *
 * @param instant  the milliseconds from 1970-01-01T00:00:00Z
 * @param chronology  the chronology, nil means ISOChronology in the default zone
 */
- (id)initWithInstantValue:(NSInteger)instant
                chronology:(HLChronology*)chronology;

/**
 * Constructs a partial from an Object that represents a time, using the
 * specified chronology.
 * <p>
 * The recognised object types are defined in
 * {@link org.joda.time.convert.ConverterManager ConverterManager} and
 * include ReadableInstant, String, Calendar and Date.
 * <p>
 * The constructor uses the time zone of the chronology specified.
 * Once the constructor is complete, all further calculations are performed
 * without reference to a timezone (by switching to UTC).
 *
 * @param instant  the datetime object
 * @param chronology  the chronology, nil means use converter
 * @throws IllegalArgumentException if the date is invalid
 */
- (id)initWithInstant:(id)instant
           chronology:(HLChronology*)chronology;

/**
 * Constructs a partial from an Object that represents a time, using the
 * specified chronology.
 * <p>
 * The recognised object types are defined in
 * {@link org.joda.time.convert.ConverterManager ConverterManager} and
 * include ReadableInstant, String, Calendar and Date.
 * <p>
 * The constructor uses the time zone of the chronology specified.
 * Once the constructor is complete, all further calculations are performed
 * without reference to a timezone (by switching to UTC).
 *
 * @param instant  the datetime object
 * @param chronology  the chronology, nil means use converter
 * @param parser  if converting from a String, the given parser is preferred
 * @throws IllegalArgumentException if the date is invalid
 * @since 1.3
 */
- (id)initWithInstant:(id)instant
           chronology:(HLChronology*)chronology
               parser:(HLDateTimeFormatter*)parser;

/**
 * Constructs a partial with specified time field values and chronology.
 * <p>
 * The constructor uses the time zone of the chronology specified.
 * Once the constructor is complete, all further calculations are performed
 * without reference to a timezone (by switching to UTC).
 * <p>
 * The array of values is assigned (not cloned) to the new instance.
 *
 * @param values  the new set of values
 * @param chronology  the chronology, nil means ISOChronology in the default zone
 * @throws IllegalArgumentException if the values are invalid
 */
- (id)initWithValues:(NSArray*)values
          chronology:(HLChronology*)chronology;

/**
 * Private constructor to be used by subclasses only which performs no validation.
 * <p>
 * Data is assigned (not cloned) to the new instance.
 *
 * @param base  the base partial
 * @param values  the new set of values, not cloned, nil means use base
 */
- (id)initWithBasePartial:(HLBasePartial*)base
                   values:(NSArray*)values;

/**
 * Private constructor to be used by subclasses only which performs no validation.
 * <p>
 * Data is assigned (not cloned) to the new instance.
 * This should not be used by mutable subclasses.
 *
 * @param base  the base partial
 * @param chrono  the chronology to use, nil means use base
 */
- (id)initWithBasePartial:(HLBasePartial*)base
               chronology:(HLChronology*)chrono;

//-----------------------------------------------------------------------
/**
 * Gets the value of the field at the specifed index.
 * 
 * @param index  the index
 * @return the value
 * @throws IndexOutOfBoundsException if the index is invalid
 */
- (NSInteger)valueAtIndex:(NSInteger)index;

/**
 * Gets an array of the value of each of the fields that this partial supports.
 * <p>
 * The fields are returned largest to smallest, for example Hour, Minute, Second.
 * Each value corresponds to the same array index as <code>getFields()</code>
 *
 * @return the current values of each field (cloned), largest to smallest
 */
- (NSArray*)values;

/**
 * Gets the chronology of the partial which is never nil.
 * <p>
 * The {@link Chronology} is the calculation engine behind the partial and
 * provides conversion and validation of the fields in a particular calendar system.
 * 
 * @return the chronology, never nil
 */
- (HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 * Sets the value of the field at the specifed index.
 * 
 * @param index  the index
 * @param value  the value to set
 * @throws IndexOutOfBoundsException if the index is invalid
 */
- (void)setValue:(NSInteger)value
         atIndex:(NSInteger)index;

/**
 * Sets the values of all fields.
 * 
 * @param values  the array of values
 */
- (void)setValues:(NSArray*)values;

//-----------------------------------------------------------------------
/**
 * Output the date using the specified format pattern.
 *
 * @param pattern  the pattern specification, nil means use <code>toString</code>
 * @see org.joda.time.format.DateTimeFormat
 */
- (NSString*)stringWithPattern:(NSString*)pattern;

/**
 * Output the date using the specified format pattern.
 *
 * @param pattern  the pattern specification, nil means use <code>toString</code>
 * @param locale  Locale to use, nil means default
 * @see org.joda.time.format.DateTimeFormat
 */
- (NSString*)stringWithPattern:(NSString*)pattern
                        locale:(NSLocale*)locale;


@end
