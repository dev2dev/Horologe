/*
 * StrictChronology.h
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

#import "HLAssembledChronology.h"


@class HLChronology;
@class HLFields;
@class HLDateTimeField;
@class HLDateTimeZone;

/**
 * Wraps another Chronology, ensuring all the fields are strict.
 * <p>
 * StrictChronology is thread-safe and immutable.
 *
 * @author Brian S O'Neill
 * @since 1.0
 * @see StrictDateTimeField
 * @see LenientChronology
 */
@interface HLStrictChronology : HLAssembledChronology {
    
@private
    HLChronology* _iWithUTC;
    
}

/**
 * Create a StrictChronology for any chronology.
 *
 * @param base the chronology to wrap
 * @throws IllegalArgumentException if chronology is nil
 */
+ (HLStrictChronology*)instanceWithBaseChronology:(HLChronology*)base;

- (HLChronology*)withUTC;

- (HLChronology*)withDateTimeZone:(HLDateTimeZone*)zone;

- (void)assemble:(HLFields*)fields;

+ (HLDateTimeField*)convertField:(HLDateTimeField*)field;

//-----------------------------------------------------------------------
/**
 * A strict chronology is only equal to a strict chronology with the
 * same base chronology.
 * 
 * @param obj  the object to compare to
 * @return true if equal
 * @since 1.4
 */
- (BOOL)isEqualTo:(id)obj;

/**
 * A suitable hashcode for the chronology.
 * 
 * @return the hashcode
 * @since 1.4
 */
- (NSInteger)hash;

@end
