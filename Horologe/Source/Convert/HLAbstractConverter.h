/*
 * AbstractConverter.h
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

#import "HLConverter.h"


@class HLChronology;
@class HLPeriodType;
@class HLDateTimeZone;
@class HLDateTimeFormatter;
@protocol HLReadablePartial;

/**
 * AbstractConverter simplifies the process of implementing a converter.
 *
 * @author Stephen Colebourne
 * @since 1.0
 */
@interface HLAbstractConverter : NSObject <HLConverter> {
    
@private
    
}

//-----------------------------------------------------------------------
/**
 * Extracts the millis from an object of this convertor's type.
 * <p>
 * This implementation returns the current time.
 * 
 * @param object  the object to convert
 * @param chrono  the chronology to use, which is always non-nil
 * @return the millisecond value
 */
- (NSInteger)instantMillis:(id)object
                chronology:(HLChronology*)chrono;

//-----------------------------------------------------------------------
/**
 * Extracts the chronology from an object of this convertor's type
 * where the time zone is specified.
 * <p>
 * This implementation returns the ISO chronology.
 * 
 * @param object  the object to convert
 * @param zone  the specified zone to use, nil means default zone
 * @return the chronology, never nil
 */
- (HLChronology*)chronologyOfObject:(id)object
                       dateTimeZone:(HLDateTimeZone*)zone;

/**
 * Extracts the chronology from an object of this convertor's type
 * where the chronology is specified.
 * <p>
 * This implementation returns the chronology specified, or the
 * ISO chronology in the default zone if nil passed in.
 * 
 * @param object  the object to convert
 * @param chrono  the chronology to use, nil means ISO default
 * @return the chronology, never nil
 */
- (HLChronology*)chronologyOfObject:(id)object
                         chronology:(HLChronology*)chrono;

//-----------------------------------------------------------------------
/**
 * Extracts the values of the partial from an object of this converter's type.
 * The chrono parameter is a hint to the converter, should it require a
 * chronology to aid in conversion.
 * <p>
 * This implementation calls {@link #getInstantMillis(Object, Chronology)}.
 * 
 * @param fieldSource  a partial that provides access to the fields.
 *  This partial may be incomplete and only getFieldType(int) should be used
 * @param object  the object to convert
 * @param chrono  the chronology to use, which is the non-nil result of getChronology()
 * @return the array of field values that match the fieldSource, must be non-nil valid
 * @throws ClassCastException if the object is invalid
 */
- (NSArray*)partialValuesWithSource:(id<HLReadablePartial>)fieldSource
                             object:(id)object
                         chronology:(HLChronology*)chrono;

/**
 * Extracts the values of the partial from an object of this converter's type.
 * The chrono parameter is a hint to the converter, should it require a
 * chronology to aid in conversion.
 * <p>
 * This implementation calls {@link #getPartialValues(ReadablePartial, Object, Chronology)}.
 * 
 * @param fieldSource  a partial that provides access to the fields.
 *  This partial may be incomplete and only getFieldType(int) should be used
 * @param object  the object to convert
 * @param chrono  the chronology to use, which is the non-nil result of getChronology()
 * @param parser  if converting from a String, the given parser is preferred
 * @return the array of field values that match the fieldSource, must be non-nil valid
 * @throws ClassCastException if the object is invalid
 * @since 1.3
 */
- (NSArray*)partialValuesWithSource:(id<HLReadablePartial>)fieldSource
                             object:(id)object
                         chronology:(HLChronology*)chrono
                             parser:(HLDateTimeFormatter*)parser;

//-----------------------------------------------------------------------
/**
 * Selects a suitable period type for the given object.
 *
 * @param object  the object to examine
 * @return the period type, never nil
 */
- (HLPeriodType*)periodTypeOfObject:(id)object;

//-----------------------------------------------------------------------
/**
 * Checks if the input is a ReadableInterval.
 * <p>
 * If it is, then the calling code should cast and copy the fields directly.
 *
 * @param object  the object to convert
 * @param chrono  the chronology to use, may be nil
 * @return true if the input is a ReadableInterval
 */
- (BOOL)isReadableInterval:(id)object
                chronology:(HLChronology*)chrono;

@end
