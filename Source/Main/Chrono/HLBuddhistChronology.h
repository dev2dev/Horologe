/*
 * HLBuddhistChronology.h
 * 
 * Horologe
 * Copyright (c) 2010 Pilgrimage Software
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
#import "HLDateTimeConstants.h"


/**
 * Constant value for 'Buddhist Era', equivalent to the value returned
 * for AD/CE. Note that this differs from the constant in BuddhistCalendar.
 */
#define BE (CE)

/** Number of years difference in calendars. */
#define BUDDHIST_OFFSET (543)

@interface HLBuddhistChronology : HLAssembledChronology {
    
@private
    /** A singleton era field. */
    HLDateTimeField* eraField;
    
    /** Cache of zone to chronology */
    NSDictionary* cCache;
    
    /** UTC instance of the chronology */
    HLBuddhistChronology* instanceUTC;
}

/**
 */
+ (HLBuddhistChronology*)instanceUTC;

/**
 */
+ (HLBuddhistChronology*)instance;

/**
 */
+ (HLBuddhistChronology*)instanceWithZone:(HLDateTimeZone*)zone;

// Constructors and instance variables
//-----------------------------------------------------------------------

/**
 */
- (id)initWithChronology:(HLChronology*)base
                   param:(id)param;

/**
 */
- (id)readResolve;

// Conversion
//-----------------------------------------------------------------------
/**
 */
- (HLChronology*)withUTC;

/**
 */
- (HLChronology*)withZone:(HLDateTimeZone*)zone;

/**
 */
- (BOOL)isEqual:(id)object;

/**
 */
- (NSInteger)hashCode;

// Output
//-----------------------------------------------------------------------
/**
 */
- (NSString*)string;

- (void)assemble:(HLFields*)fields;

@end
