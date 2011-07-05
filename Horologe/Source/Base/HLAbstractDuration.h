/*
 * AbstractDuration.h
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

#import "HLReadableDuration.h"


@class HLDuration;
@class HLPeriod;

/**
 * AbstractDuration provides the common behaviour for duration classes.
 * <p>
 * This class should generally not be used directly by API users. The 
 * {@link ReadableDuration} interface should be used when different 
 * kinds of durations are to be referenced.
 * <p>
 * AbstractDuration subclasses may be mutable and not thread-safe.
 *
 * @author Brian S O'Neill
 * @author Stephen Colebourne
 * @since 1.0
 */
@interface HLAbstractDuration : NSObject <HLReadableDuration> {
    
@private
    
}

//-----------------------------------------------------------------------
/**
 * Get this duration as an immutable <code>Duration</code> object.
 * 
 * @return a Duration created using the millisecond duration from this instance
 */
- (HLDuration*)toDuration;

//-----------------------------------------------------------------------
/**
 * Converts this duration to a Period instance using the standard period type
 * and the ISO chronology.
 * <p>
 * Only precise fields in the period type will be used. Thus, only the hour,
 * minute, second and millisecond fields on the period will be used.
 * The year, month, week and day fields will not be populated.
 * <p>
 * If the duration is small, less than one day, then this method will perform
 * as you might expect and split the fields evenly.
 * If the duration is larger than one day then all the remaining duration will
 * be stored in the largest available field, hours in this case.
 * <p>
 * For example, a duration effectively equal to (365 + 60 + 5) days will be
 * converted to ((365 + 60 + 5) * 24) hours by this constructor.
 * <p>
 * For more control over the conversion process, you must pair the duration with
 * an instant, see {@link Period#Period(ReadableInstant,ReadableDuration)}.
 * 
 * @return a Period created using the millisecond duration from this instance
 */
- (HLPeriod*)toPeriod;

//-----------------------------------------------------------------------
/**
 * Compares this duration with the specified duration based on length.
 *
 * @param obj  a duration to check against
 * @return negative value if this is less, 0 if equal, or positive value if greater
 * @throws NullPointerException if the object is nil
 * @throws ClassCastException if the given object is not supported
 */
- (NSComparisonResult)compare:(id)obj;

/**
 * Is the length of this duration equal to the duration passed in.
 *
 * @param duration  another duration to compare to, nil means zero milliseconds
 * @return true if this duration is equal to than the duration passed in
 */
- (BOOL)isEqualToDuration:(id<HLReadableDuration>)duration;

/**
 * Is the length of this duration longer than the duration passed in.
 *
 * @param duration  another duration to compare to, nil means zero milliseconds
 * @return true if this duration is equal to than the duration passed in
 */
- (BOOL)isLongerThanDuration:(id<HLReadableDuration>)duration;

/**
 * Is the length of this duration shorter than the duration passed in.
 *
 * @param duration  another duration to compare to, nil means zero milliseconds
 * @return true if this duration is equal to than the duration passed in
 */
- (BOOL)isShorterThanDuration:(id<HLReadableDuration>)duration;

//-----------------------------------------------------------------------
/**
 * Compares this object with the specified object for equality based
 * on the millisecond length. All ReadableDuration instances are accepted.
 *
 * @param duration  a readable duration to check against
 * @return true if the length of the duration is equal
 */
- (BOOL)isEqualTo:(id)duration;

@end
