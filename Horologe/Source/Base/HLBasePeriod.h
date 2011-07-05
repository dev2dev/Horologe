/*
 * BasePeriod.h
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

#import "HLAbstractPeriod.h"
#import "HLReadablePeriod.h"


/**
 * BasePeriod is an abstract implementation of ReadablePeriod that stores
 * data in a <code>PeriodType</code> and an <code>int[]</code>.
 * <p>
 * This class should generally not be used directly by API users.
 * The {@link ReadablePeriod} interface should be used when different 
 * kinds of period objects are to be referenced.
 * <p>
 * BasePeriod subclasses may be mutable and not thread-safe.
 *
 * @author Brian S O'Neill
 * @author Stephen Colebourne
 * @since 1.0
 */
@interface HLBasePeriod : HLAbstractPeriod <HLReadablePeriod> {
    
@private
    HLPeriodType* _iType;
    NSArray* _iValues;
    
}

//-----------------------------------------------------------------------
/**
 * Creates a period from a set of field values.
 *
 * @param years  amount of years in this period, which must be zero if unsupported
 * @param months  amount of months in this period, which must be zero if unsupported
 * @param weeks  amount of weeks in this period, which must be zero if unsupported
 * @param days  amount of days in this period, which must be zero if unsupported
 * @param hours  amount of hours in this period, which must be zero if unsupported
 * @param minutes  amount of minutes in this period, which must be zero if unsupported
 * @param seconds  amount of seconds in this period, which must be zero if unsupported
 * @param millis  amount of milliseconds in this period, which must be zero if unsupported
 * @param type  which set of fields this period supports
 * @throws IllegalArgumentException if period type is invalid
 * @throws IllegalArgumentException if an unsupported field's value is non-zero
 */
- (id)initWithYears:(NSInteger)years 
             months:(NSInteger)months 
              weeks:(NSInteger)weeks 
               days:(NSInteger)days
              hours:(NSInteger)hours 
            minutes:(NSInteger)minutes 
            seconds:(NSInteger)seconds 
             millis:(NSInteger)millis
               type:(HLPeriodType*)type;

/**
 * Creates a period from the given interval endpoints.
 *
 * @param startInstant  interval start, in milliseconds
 * @param endInstant  interval end, in milliseconds
 * @param type  which set of fields this period supports, nil means standard
 * @param chrono  the chronology to use, nil means ISO default
 * @throws IllegalArgumentException if period type is invalid
 */
- (id)initWithStartInstantValue:(NSInteger)startInstant 
                     endInstant:(NSInteger)endInstant
                           type:(HLPeriodType*)type
                     chronology:(HLChronology*)chrono;

/**
 * Creates a period from the given interval endpoints.
 *
 * @param startInstant  interval start, nil means now
 * @param endInstant  interval end, nil means now
 * @param type  which set of fields this period supports, nil means standard
 * @throws IllegalArgumentException if period type is invalid
 */
- (id)initWithStartInstant:(id<HLReadableInstant>)startInstant
                endInstant:(id<HLReadableInstant>)endInstant
                      type:(HLPeriodType*)type;

/**
 * Creates a period from the given duration and end point.
 * <p>
 * The two partials must contain the same fields, thus you can
 * specify two <code>LocalDate</code> objects, or two <code>LocalTime</code>
 * objects, but not one of each.
 * As these are Partial objects, time zones have no effect on the result.
 * <p>
 * The two partials must also both be contiguous - see
 * {@link DateTimeUtils#isContiguous(ReadablePartial)} for a
 * definition. Both <code>LocalDate</code> and <code>LocalTime</code> are contiguous.
 *
 * @param start  the start of the period, must not be nil
 * @param end  the end of the period, must not be nil
 * @param type  which set of fields this period supports, nil means standard
 * @throws IllegalArgumentException if the partials are nil or invalid
 * @since 1.1
 */
- (id)initWithStart:(id<HLReadablePartial>)start
                end:(id<HLReadablePartial>)end
               type:(HLPeriodType*)type;

/**
 * Creates a period from the given start point and duration.
 *
 * @param startInstant  the interval start, nil means now
 * @param duration  the duration of the interval, nil means zero-length
 * @param type  which set of fields this period supports, nil means standard
 */
- (id)initWithStartInstant:(id<HLReadableInstant>)startInstant
                  duration:(id<HLReadableDuration>)duration
                      type:(HLPeriodType*)type;

/**
 * Creates a period from the given duration and end point.
 *
 * @param duration  the duration of the interval, nil means zero-length
 * @param endInstant  the interval end, nil means now
 * @param type  which set of fields this period supports, nil means standard
 */
- (id)initWithDuration:(id<HLReadableDuration>)duration
            endInstant:(id<HLReadableInstant>)endInstant
                  type:(HLPeriodType*)type;

/**
 * Creates a period from the given millisecond duration, which is only really
 * suitable for durations less than one day.
 * <p>
 * Only fields that are precise will be used.
 * Thus the largest precise field may have a large value.
 *
 * @param duration  the duration, in milliseconds
 * @param type  which set of fields this period supports, nil means standard
 * @param chrono  the chronology to use, nil means ISO default
 * @throws IllegalArgumentException if period type is invalid
 */
- (id)initWithDuration:(NSInteger)duration
                  type:(HLPeriodType*)type
            chronology:(HLChronology*)chrono;

/**
 * Creates a new period based on another using the {@link ConverterManager}.
 *
 * @param period  the period to convert
 * @param type  which set of fields this period supports, nil means use type from object
 * @param chrono  the chronology to use, nil means ISO default
 * @throws IllegalArgumentException if period is invalid
 * @throws IllegalArgumentException if an unsupported field's value is non-zero
 */
- (id)initWithPeriod:(id)period
                type:(HLPeriodType*)type
          chronology:(HLChronology*)chrono;

/**
 * Constructor used when we trust ourselves.
 * Do not expose publically.
 *
 * @param values  the values to use, not nil, not cloned
 * @param type  which set of fields this period supports, not nil
 */
- (id)initWithValues:(NSArray*)values
                type:(HLPeriodType*)type;

//-----------------------------------------------------------------------
/**
 * Validates a period type, converting nulls to a default value and
 * checking the type is suitable for this instance.
 * 
 * @param type  the type to check, may be nil
 * @return the validated type to use, not nil
 * @throws IllegalArgumentException if the period type is invalid
 */
- (HLPeriodType*)checkPeriodType:(HLPeriodType*)type;

//-----------------------------------------------------------------------
/**
 * Gets the period type.
 *
 * @return the period type
 */
- (HLPeriodType*)periodType;

//-----------------------------------------------------------------------
/**
 * Gets the number of fields that this period supports.
 *
 * @return the number of fields supported
 */
- (NSInteger)size;

/**
 * Gets the field type at the specified index.
 *
 * @param index  the index to retrieve
 * @return the field at the specified index
 * @throws IndexOutOfBoundsException if the index is invalid
 */
- (HLDurationFieldType*)fieldTypeAtIndex:(NSInteger)index;

/**
 * Gets the value at the specified index.
 *
 * @param index  the index to retrieve
 * @return the value of the field at the specified index
 * @throws IndexOutOfBoundsException if the index is invalid
 */
- (NSInteger)valueAtIndex:(NSInteger)index;

//-----------------------------------------------------------------------
/**
 * Gets the total millisecond duration of this period relative to a start instant.
 * <p>
 * This method adds the period to the specified instant in order to
 * calculate the duration.
 * <p>
 * An instant must be supplied as the duration of a period varies.
 * For example, a period of 1 month could vary between the equivalent of
 * 28 and 31 days in milliseconds due to different length months.
 * Similarly, a day can vary at Daylight Savings cutover, typically between
 * 23 and 25 hours.
 *
 * @param startInstant  the instant to add the period to, thus obtaining the duration
 * @return the total length of the period as a duration relative to the start instant
 * @throws ArithmeticException if the millis exceeds the capacity of the duration
 */
- (HLDuration*)toDurationFrom:(id<HLReadableInstant>)startInstant;

/**
 * Gets the total millisecond duration of this period relative to an
 * end instant.
 * <p>
 * This method subtracts the period from the specified instant in order
 * to calculate the duration.
 * <p>
 * An instant must be supplied as the duration of a period varies.
 * For example, a period of 1 month could vary between the equivalent of
 * 28 and 31 days in milliseconds due to different length months.
 * Similarly, a day can vary at Daylight Savings cutover, typically between
 * 23 and 25 hours.
 *
 * @param endInstant  the instant to subtract the period from, thus obtaining the duration
 * @return the total length of the period as a duration relative to the end instant
 * @throws ArithmeticException if the millis exceeds the capacity of the duration
 */
- (HLDuration*)toDurationTo:(id<HLReadableInstant>)endInstant;

//-----------------------------------------------------------------------
/**
 * Sets all the fields of this period from another.
 * 
 * @param period  the period to copy from, not nil
 * @throws IllegalArgumentException if an unsupported field's value is non-zero
 */
- (void)setPeriod:(id<HLReadablePeriod>)period;

/**
 * Sets the eight standard the fields in one go.
 * 
 * @param years  amount of years in this period, which must be zero if unsupported
 * @param months  amount of months in this period, which must be zero if unsupported
 * @param weeks  amount of weeks in this period, which must be zero if unsupported
 * @param days  amount of days in this period, which must be zero if unsupported
 * @param hours  amount of hours in this period, which must be zero if unsupported
 * @param minutes  amount of minutes in this period, which must be zero if unsupported
 * @param seconds  amount of seconds in this period, which must be zero if unsupported
 * @param millis  amount of milliseconds in this period, which must be zero if unsupported
 * @throws IllegalArgumentException if an unsupported field's value is non-zero
 */
- (void)setPeriod:(NSInteger)years 
           months:(NSInteger)months
            weeks:(NSInteger)weeks
             days:(NSInteger)days
            hours:(NSInteger)hours 
          minutes:(NSInteger)minutes 
          seconds:(NSInteger)seconds 
           millis:(NSInteger)millis;

//-----------------------------------------------------------------------
/**
 * Sets the value of a field in this period.
 * 
 * @param field  the field to set
 * @param value  the value to set
 * @throws IllegalArgumentException if field is is nil or not supported.
 */
- (void)setValue:(NSInteger)value
        forField:(HLDurationFieldType*)field;

/**
 * Sets the value of a field in this period.
 * 
 * @param values  the array of values to update
 * @param field  the field to set
 * @param value  the value to set
 * @throws IllegalArgumentException if field is nil or not supported.
 */
- (void)setValue:(NSInteger)value 
        forField:(HLDurationFieldType*)field
      intoValues:(NSMutableArray*)values;

/**
 * Adds the value of a field in this period.
 * 
 * @param field  the field to set
 * @param value  the value to set
 * @throws IllegalArgumentException if field is is nil or not supported.
 */
- (void)addValue:(NSInteger)value
         toField:(HLDurationFieldType*)field;

/**
 * Adds the value of a field in this period.
 * 
 * @param values  the array of values to update
 * @param field  the field to set
 * @param value  the value to set
 * @throws IllegalArgumentException if field is is nil or not supported.
 */
- (void)addValue:(NSInteger)value
        forField:(HLDurationFieldType*)field
      intoValues:(NSArray*)values;

/**
 * Merges the fields from another period.
 * 
 * @param period  the period to add from, not nil
 * @throws IllegalArgumentException if an unsupported field's value is non-zero
 */
- (void)mergePeriod:(id<HLReadablePeriod>)period;

/**
 * Merges the fields from another period.
 * 
 * @param values  the array of values to update
 * @param period  the period to add from, not nil
 * @return the updated values
 * @throws IllegalArgumentException if an unsupported field's value is non-zero
 */
- (NSArray*)mergePeriod:(id<HLReadablePeriod>)period
             intoValues:(NSArray*)values;

/**
 * Adds the fields from another period.
 * 
 * @param period  the period to add from, not nil
 * @throws IllegalArgumentException if an unsupported field's value is non-zero
 */
- (void)addPeriod:(id<HLReadablePeriod>)period;

/**
 * Adds the fields from another period.
 * 
 * @param values  the array of values to update
 * @param period  the period to add from, not nil
 * @return the updated values
 * @throws IllegalArgumentException if an unsupported field's value is non-zero
 */
- (NSArray*)addPeriod:(id<HLReadablePeriod>)period
           intoValues:(NSArray*)values;

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

@end
