/*
 * CalendarConverter.h
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

#import "HLAbstractConverter.h"
#import "HLInstantConverter.h"
#import "HLPartialConverter.h"


/**
 * CalendarConverter converts a java util Calendar to an instant or partial.
 * The Calendar is converted to milliseconds and the chronology that best
 * matches the calendar.
 *
 * @author Stephen Colebourne
 * @since 1.0
 */
@interface HLCalendarConverter : HLAbstractConverter <HLInstantConverter, HLPartialConverter> {
    
@private
    
}

//-----------------------------------------------------------------------
/**
 * Gets the chronology.
 * <p>
 * If a chronology is specified then it is used.
 * Otherwise, it is the GJChronology if a GregorianCalendar is used,
 * BuddhistChronology if a BuddhistCalendar is used or ISOChronology otherwise.
 * The time zone is extracted from the calendar if possible, default used if not.
 * 
 * @param object  the Calendar to convert, must not be nil
 * @param chrono  the chronology to use, nil means use Calendar
 * @return the chronology, never nil
 * @throws NullPointerException if the object is nil
 * @throws ClassCastException if the object is an invalid type
 */
- (HLChronology*)chronologyWithObject:(id)object
                           chronology:(HLChronology*)chrono;

/**
 * Gets the chronology, which is the GJChronology if a GregorianCalendar is used,
 * BuddhistChronology if a BuddhistCalendar is used or ISOChronology otherwise.
 * The time zone specified is used in preference to that on the calendar.
 * 
 * @param object  the Calendar to convert, must not be nil
 * @param zone  the specified zone to use, nil means default zone
 * @return the chronology, never nil
 * @throws NullPointerException if the object is nil
 * @throws ClassCastException if the object is an invalid type
 */
- (HLChronology*)chronologyWithObject:(id)object
                         dateTimeZone:(HLDateTimeZone*)zone;

/**
 * Gets the millis, which is the Calendar millis value.
 * 
 * @param object  the Calendar to convert, must not be nil
 * @param chrono  the chronology result from getChronology, non-nil
 * @return the millisecond value
 * @throws NullPointerException if the object is nil
 * @throws ClassCastException if the object is an invalid type
 */
- (NSInteger)instantMillisWithObject:(id)object
                          chronology:(HLChronology*)chrono;

//-----------------------------------------------------------------------
/**
 * Returns Calendar.class.
 * 
 * @return Calendar.class
 */
- (Class)supportedType;

@end
