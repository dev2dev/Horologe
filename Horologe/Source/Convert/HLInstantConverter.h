/*
 * InstantConverter.h
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
@class HLDateTimeZone;

/**
 * InstantConverter defines how an object is converted to milliseconds/chronology.
 * <p>
 * The two methods in this interface must be called in order, as the
 * <code>getInstantMillis</code> method relies on the result of the
 * <code>getChronology</code> method being passed in.
 *
 * @author Stephen Colebourne
 * @since 1.0
 */
@protocol HLInstantConverter <HLConverter>

/**
 * Extracts the chronology from an object of this converter's type
 * where the time zone is specified.
 * 
 * @param object  the object to convert
 * @param zone  the specified zone to use, nil means default zone
 * @return the chronology, never nil
 * @throws ClassCastException if the object is invalid
 */
- (HLChronology*)chronologyFromInstant:(id)object
                                  zone:(HLDateTimeZone*)zone;

/**
 * Extracts the chronology from an object of this converter's type
 * where the chronology may be specified.
 * <p>
 * If the chronology is non-nil it should be used. If it is nil, then the
 * object should be queried, and if it has no chronology then ISO default is used.
 * 
 * @param object  the object to convert
 * @param chrono  the chronology to use, nil means use object
 * @return the chronology, never nil
 * @throws ClassCastException if the object is invalid
 */
- (HLChronology*)chronologyFromInstant:(id)object
                            chronology:(HLChronology*)chrono;

//-----------------------------------------------------------------------
/**
 * Extracts the millis from an object of this converter's type.
 * <p>
 * The chronology passed in is the result of the call to <code>getChronology</code>.
 * 
 * @param object  the object to convert
 * @param chrono  the chronology to use, which is the non-nil result of getChronology()
 * @return the millisecond instant
 * @throws ClassCastException if the object is invalid
 * @throws IllegalArgumentException if object conversion fails
 */
- (NSInteger)instantMillisFromInstant:(id)object
                           chronology:(HLChronology*)chrono;

@end
