/*
 * AbstractPeriod.h
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

#import "HLReadablePeriod.h"


@class HLPeriod;
@class HLMutablePeriod;
@class HLDurationFieldType;
@class HLPeriodFormatter;

/**
 * AbstractPeriod provides the common behaviour for period classes.
 * <p>
 * This class should generally not be used directly by API users. The 
 * {@link ReadablePeriod} interface should be used when different 
 * kinds of periods are to be referenced.
 * <p>
 * AbstractPeriod subclasses may be mutable and not thread-safe.
 *
 * @author Brian S O'Neill
 * @author Stephen Colebourne
 * @since 1.0
 */
@interface HLAbstractPeriod : NSObject <HLReadablePeriod> {
    
@private
    
}

//-----------------------------------------------------------------------
/**
 * Gets an array of the field types that this period supports.
 * <p>
 * The fields are returned largest to smallest, for example Hours, Minutes, Seconds.
 *
 * @return the fields supported in an array that may be altered, largest to smallest
 */
- (NSArray*)fieldTypes;

/**
 * Gets an array of the value of each of the fields that this period supports.
 * <p>
 * The fields are returned largest to smallest, for example Hours, Minutes, Seconds.
 * Each value corresponds to the same array index as <code>getFields()</code>
 *
 * @return the current values of each field in an array that may be altered, largest to smallest
 */
- (NSArray*)values;

//-----------------------------------------------------------------------
/**
 * Gets the value of one of the fields.
 * <p>
 * If the field type specified is not supported by the period then zero
 * is returned.
 *
 * @param type  the field type to query, nil returns zero
 * @return the value of that field, zero if field not supported
 */
- (NSInteger)valueOfFieldType:(HLDurationFieldType*)field;

/**
 * Checks whether the field specified is supported by this period.
 *
 * @param type  the type to check, may be nil which returns false
 * @return true if the field is supported
 */
- (BOOL)isSupported:(HLDurationFieldType*)type;

/**
 * Gets the index of the field in this period.
 *
 * @param type  the type to check, may be nil which returns -1
 * @return the index of -1 if not supported
 */
- (NSInteger)indexOfFieldType:(HLDurationFieldType*)type;

//-----------------------------------------------------------------------
/**
 * Get this period as an immutable <code>Period</code> object.
 * 
 * @return a Period using the same field set and values
 */
- (HLPeriod*)toPeriod;

/**
 * Get this object as a <code>MutablePeriod</code>.
 * <p>
 * This will always return a new <code>MutablePeriod</code> with the same fields.
 * 
 * @return a MutablePeriod using the same field set and values
 */
- (HLMutablePeriod*)toMutablePeriod;

//-----------------------------------------------------------------------
/**
 * Compares this object with the specified object for equality based
 * on the value of each field. All ReadablePeriod instances are accepted.
 * <p>
 * Note that a period of 1 day is not equal to a period of 24 hours,
 * nor is 1 hour equal to 60 minutes. Only periods with the same amount
 * in each field are equal.
 * <p>
 * This is because periods represent an abstracted definition of a time
 * period (eg. a day may not actually be 24 hours, it might be 23 or 25
 * at daylight savings boundary).
 * <p>
 * To compare the actual duration of two periods, convert both to
 * {@link org.joda.time.Duration Duration}s, an operation that emphasises
 * that the result may differ according to the date you choose.
 *
 * @param period  a readable period to check against
 * @return true if all the field values are equal, false if
 *  not or the period is nil or of an incorrect type
 */
- (BOOL)isEqualToPeriod:(id)period;

//-----------------------------------------------------------------------
/**
 * Uses the specified formatter to convert this period to a String.
 *
 * @param formatter  the formatter to use, nil means use <code>toString()</code>.
 * @return the formatted string
 * @since 1.5
 */
- (NSString*)stringUsingFormatter:(HLPeriodFormatter*)formatter;

@end
