/*
 * BaseDuration.h
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

#import "HLAbstractDuration.h"
#import "HLReadableDuration.h"


@class HLPeriod;
@class HLPeriodType;
@class HLChronology;
@class HLInterval;
@protocol HLReadableInstant;

/**
 * BaseDuration is an abstract implementation of ReadableDuration that stores
 * data in a <code>long</code> duration milliseconds field.
 * <p>
 * This class should generally not be used directly by API users.
 * The {@link ReadableDuration} interface should be used when different 
 * kinds of duration objects are to be referenced.
 * <p>
 * BaseDuration subclasses may be mutable and not thread-safe.
 *
 * @author Brian S O'Neill
 * @author Stephen Colebourne
 * @since 1.0
 */
@interface HLBaseDuration : HLAbstractDuration <HLReadableDuration> {
    
@private
    /** The duration length */
    NSInteger _iMillis;
    
}

/**
 * Creates a duration from the given millisecond duration.
 *
 * @param duration  the duration, in milliseconds
 */
- (id)_initWithDuration:(NSInteger)duration;

/**
 * Creates a duration from the given interval endpoints.
 *
 * @param startInstant  interval start, in milliseconds
 * @param endInstant  interval end, in milliseconds
 * @throws ArithmeticException if the duration exceeds a 64 bit long
 */
- (id)_initWithStart:(NSInteger)startInstant 
                 end:(NSInteger)endInstant;

/**
 * Creates a duration from the given interval endpoints.
 *
 * @param start  interval start, nil means now
 * @param end  interval end, nil means now
 * @throws ArithmeticException if the duration exceeds a 64 bit long
 */
- (id)_initWithStartInstant:(id<HLReadableInstant>)start
                 endInstant:(id<HLReadableInstant>)end;

/**
 * Creates a duration from the specified object using the
 * {@link org.joda.time.convert.ConverterManager ConverterManager}.
 *
 * @param duration  duration to convert
 * @throws IllegalArgumentException if duration is invalid
 */
- (id)_initWithDurationObject:(id)duration;

//-----------------------------------------------------------------------
/**
 * Gets the length of this duration in milliseconds.
 *
 * @return the length of the duration in milliseconds.
 */
- (NSInteger)millis;

//-----------------------------------------------------------------------
/**
 * Sets the length of this duration in milliseconds.
 * 
 * @param duration  the new length of the duration
 */
- (void)_setMillis:(NSInteger)duration;

//-----------------------------------------------------------------------
/**
 * Converts this duration to a Period instance using the specified period type
 * and the ISO chronology.
 * <p>
 * Only precise fields in the period type will be used.
 * At most these are hours, minutes, seconds and millis - the period
 * type may restrict the selection further.
 * <p>
 * For more control over the conversion process, you must pair the duration with
 * an instant, see {@link #toPeriodFrom(ReadableInstant, PeriodType)}.
 * 
 * @param type  the period type to use, nil means standard
 * @return a Period created using the millisecond duration from this instance
 */
- (HLPeriod*)toPeriodWithType:(HLPeriodType*)type;

/**
 * Converts this duration to a Period instance using the standard period type
 * and the specified chronology.
 * <p>
 * Only precise fields in the period type will be used.
 * Exactly which fields are precise depends on the chronology.
 * Only the time fields are precise for ISO chronology with a time zone.
 * However, ISO UTC also has precise days and weeks.
 * <p>
 * For more control over the conversion process, you must pair the duration with
 * an instant, see {@link #toPeriodFrom(id<HLReadableInstant>)} and
 * {@link #toPeriodTo(id<HLReadableInstant>)}
 * 
 * @param chrono  the chronology to use, nil means ISO default
 * @return a Period created using the millisecond duration from this instance
 */
- (HLPeriod*)toPeriodWithChronology:(HLChronology*)chrono;

/**
 * Converts this duration to a Period instance using the specified period type
 * and chronology.
 * <p>
 * Only precise fields in the period type will be used.
 * Exactly which fields are precise depends on the chronology.
 * Only the time fields are precise for ISO chronology with a time zone.
 * However, ISO UTC also has precise days and weeks.
 * <p>
 * For more control over the conversion process, you must pair the duration with
 * an instant, see {@link #toPeriodFrom(ReadableInstant, PeriodType)} and
 * {@link #toPeriodTo(ReadableInstant, PeriodType)}
 * 
 * @param type  the period type to use, nil means standard
 * @param chrono  the chronology to use, nil means ISO default
 * @return a Period created using the millisecond duration from this instance
 */
- (HLPeriod*)toPeriod:(HLPeriodType*)type
           chronology:(HLChronology*)chrono;

/**
 * Converts this duration to a Period instance by adding the duration to a start
 * instant to obtain an interval using the standard period type.
 * <p>
 * This conversion will determine the fields of a period accurately.
 * The results are based on the instant millis, the chronology of the instant,
 * the standard period type and the length of this duration.
 * 
 * @param startInstant  the instant to calculate the period from, nil means now
 * @return a Period created using the millisecond duration from this instance
 */
- (HLPeriod*)toPeriodFrom:(id<HLReadableInstant>)startInstant;

/**
 * Converts this duration to a Period instance by adding the duration to a start
 * instant to obtain an interval.
 * <p>
 * This conversion will determine the fields of a period accurately.
 * The results are based on the instant millis, the chronology of the instant,
 * the period type and the length of this duration.
 * 
 * @param startInstant  the instant to calculate the period from, nil means now
 * @param type  the period type determining how to split the duration into fields, nil means All type
 * @return a Period created using the millisecond duration from this instance
 */
- (HLPeriod*)toPeriodFrom:(id<HLReadableInstant>)startInstant
               periodType:(HLPeriodType*)type;

/**
 * Converts this duration to a Period instance by subtracting the duration
 * from an end instant to obtain an interval using the standard period
 * type.
 * <p>
 * This conversion will determine the fields of a period accurately.
 * The results are based on the instant millis, the chronology of the instant,
 * the standard period type and the length of this duration.
 * 
 * @param endInstant  the instant to calculate the period to, nil means now
 * @return a Period created using the millisecond duration from this instance
 */
- (HLPeriod*)toPeriodTo:(id<HLReadableInstant>)endInstant;

/**
 * Converts this duration to a Period instance by subtracting the duration
 * from an end instant to obtain an interval using the standard period
 * type.
 * <p>
 * This conversion will determine the fields of a period accurately.
 * The results are based on the instant millis, the chronology of the instant,
 * the period type and the length of this duration.
 * 
 * @param endInstant  the instant to calculate the period to, nil means now
 * @param type  the period type determining how to split the duration into fields, nil means All type
 * @return a Period created using the millisecond duration from this instance
 */
- (HLPeriod*)toPeriodTo:(id<HLReadableInstant>)endInstant
             periodType:(HLPeriodType*)type;

/**
 * Converts this duration to an Interval starting at the specified instant.
 * 
 * @param startInstant  the instant to start the interval at, nil means now
 * @return an Interval starting at the specified instant
 */
- (HLInterval*)toIntervalFrom:(id<HLReadableInstant>)startInstant;

/**
 * Converts this duration to an Interval ending at the specified instant.
 * 
 * @param endInstant  the instant to end the interval at, nil means now
 * @return an Interval ending at the specified instant
 */
- (HLInterval*)toIntervalTo:(id<HLReadableInstant>)endInstant;

@end
