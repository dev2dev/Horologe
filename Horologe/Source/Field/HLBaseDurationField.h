/*
 * BaseDurationField.h
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

#import "HLDurationField.h"


@class HLDurationFieldType;

/**
 * BaseDurationField provides the common behaviour for DurationField
 * implementations.
 * <p>
 * This class should generally not be used directly by API users. The
 * DurationField class should be used when different kinds of DurationField
 * objects are to be referenced.
 * <p>
 * BaseDurationField is thread-safe and immutable, and its subclasses must
 * be as well.
 *
 * @author Brian S O'Neill
 * @see DecoratedDurationField
 * @since 1.0
 */
@interface HLBaseDurationField : HLDurationField {
    
@private
    /** A desriptive name for the field. */
    HLDurationFieldType* _iType;
    
}

- (id)initWithFieldType:(HLDurationFieldType*)type;

- (HLDurationFieldType*)type;

- (NSString*)name;

/**
 * @return true always
 */
- (BOOL)isSupported;

//------------------------------------------------------------------------
/**
 * Get the value of this field from the milliseconds, which is approximate
 * if this field is imprecise.
 *
 * @param duration  the milliseconds to query, which may be negative
 * @return the value of the field, in the units of the field, which may be
 * negative
 */
- (NSInteger)valueWithDuration:(NSInteger)duration;

/**
 * Get the value of this field from the milliseconds relative to an
 * instant.
 *
 * <p>If the milliseconds is positive, then the instant is treated as a
 * "start instant". If negative, the instant is treated as an "end
 * instant".
 *
 * <p>The default implementation returns
 * <code>Utils.safeToInt(getAsLong(millisDuration, instant))</code>.
 * 
 * @param duration  the milliseconds to query, which may be negative
 * @param instant  the start instant to calculate relative to
 * @return the value of the field, in the units of the field, which may be
 * negative
 */
- (NSInteger)valueWithDurationValue:(NSInteger)duration 
                       instantValue:(NSInteger)instant;

/**
 * Get the millisecond duration of this field from its value, which is
 * approximate if this field is imprecise.
 * 
 * @param value  the value of the field, which may be negative
 * @return the milliseconds that the field represents, which may be
 * negative
 */
- (NSInteger)millisWithValue:(NSInteger)value;

// Calculation API
//------------------------------------------------------------------------
- (NSInteger)differenceWithMinuend:(NSInteger)minuendInstant 
                        subtrahend:(NSInteger)subtrahendInstant;

//------------------------------------------------------------------------
- (NSComparisonResult)compareToField:(id)durationField;

@end
