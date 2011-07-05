/*
 * ISOChronology.h
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


@class HLISOChronology;
@class HLFields;
@class HLDateTimeZone;

/**
 * Implements a chronology that follows the rules of the ISO8601 standard,
 * which is compatible with Gregorian for all modern dates.
 * When ISO does not define a field, but it can be determined (such as AM/PM)
 * it is included.
 * <p>
 * With the exception of century related fields, ISOChronology is exactly the
 * same as {@link GregorianChronology}. In this chronology, centuries and year
 * of century are zero based. For all years, the century is determined by
 * dropping the last two digits of the year, ignoring sign. The year of century
 * is the value of the last two year digits.
 * <p>
 * ISOChronology is thread-safe and immutable.
 *
 * @author Stephen Colebourne
 * @author Brian S O'Neill
 * @since 1.0
 */
@interface ISOChronology : HLAssembledChronology {
    
@private
    
}

/**
 * Gets an instance of the ISOChronology.
 * The time zone of the returned instance is UTC.
 * 
 * @return a singleton UTC instance of the chronology
 */
+ (HLISOChronology*)instanceUTC;

/**
 * Gets an instance of the ISOChronology in the default time zone.
 * 
 * @return a chronology in the default time zone
 */
+ (HLISOChronology*)instance;

/**
 * Gets an instance of the ISOChronology in the given time zone.
 * 
 * @param zone  the time zone to get the chronology in, nil is default
 * @return a chronology in the specified time zone
 */
+ (HLISOChronology*)instanceWithDateTimeZone:(HLDateTimeZone*)zone;

// Constructors and instance variables
//-----------------------------------------------------------------------

/**
 * Restricted constructor
 */
- (id)initWithChronology:(HLChronology*)base;

// Conversion
//-----------------------------------------------------------------------
/**
 * Gets the Chronology in the UTC time zone.
 * 
 * @return the chronology in UTC
 */
- (HLChronology*)withUTC;

/**
 * Gets the Chronology in a specific time zone.
 * 
 * @param zone  the zone to get the chronology in, nil is default
 * @return the chronology
 */
- (HLChronology*)withZone:(HLDateTimeZone*)zone;

// Output
//-----------------------------------------------------------------------
- (void)assemble:(HLFields*)fields;

/**
 * Checks if this chronology instance equals another.
 * 
 * @param obj  the object to compare to
 * @return true if equal
 * @since 1.6
 */
- (BOOL)isEqualTo:(id)obj;

@end

