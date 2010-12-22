/*
 * HLBaseChronology.h
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

#import "HLChronology.h"
#import "HLDateTimeZone.h"
#import "HLDurationField.h"
#import "HLDateTimeField.h"


@interface HLBaseChronology : HLChronology {
    
}

/**
 */
- (HLDateTimeZone*)zone;

/**
 */
- (HLChronology*)withUTC;

/**
 */
- (HLChronology*)withZone:(HLDateTimeZone*)zone;

/**
 */
- (NSInteger)dateTimeMillisFromYear:(NSInteger)year
                              month:(NSInteger)monthOfYear
                                day:(NSInteger)dayOfMonth
                             millis:(NSInteger)millisOfDay;

/**
 */
- (NSInteger)dateTimeMillisFromYear:(NSInteger)year
                              month:(NSInteger)monthOfYear
                                day:(NSInteger)dayOfMonth
                               hour:(NSInteger)hourOfDay
                             minute:(NSInteger)minuteOfHour
                             second:(NSInteger)secondOfMinute
                             millis:(NSInteger)millisOfSecond;

/**
 */
- (NSInteger)dateTimeMillisFromInstant:(NSInteger)instant
                                  hour:(NSInteger)hourOfDay
                                minute:(NSInteger)minuteOfHour
                                second:(NSInteger)secondOfMinute
                                millis:(NSInteger)millisOfSecond;

//-----------------------------------------------------------------------
/**
 */
-(void)validate:(id<HLReadablePartial>)partial 
         values:(NSArray*)values;

/**
 */
- (NSArray*)getFromPartial:(id<HLReadablePartial>)partial 
                   instant:(NSInteger)instant;

/**
 */
- (NSInteger)setPartial:(id<HLReadablePartial>)partial 
                instant:(NSInteger)instant;

//-----------------------------------------------------------------------
/**
 */
- (NSArray*)getFromPeriod:(id<HLReadablePeriod>)period 
             startInstant:(NSInteger)startInstant 
               endInstant:(NSInteger)endInstant;

/**
 */
- (NSArray*)getFromPeriod:(id<HLReadablePeriod>)period 
                 duration:(NSInteger)duration;

/**
 */
- (NSInteger)addPeriod:(id<HLReadablePeriod>)period 
               instant:(NSInteger)instant 
                scalar:(NSInteger)scalar;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)addInstant:(NSInteger)instant 
               duration:(NSInteger)duration 
                 scalar:(NSInteger)scalar;

// Millis
//-----------------------------------------------------------------------
/**
 */
- (HLDurationField*)millis;

/**
 */
- (HLDateTimeField*)millisOfSecond;

/**
 */
- (HLDateTimeField*)millisOfDay;

// Second
//-----------------------------------------------------------------------
/**
 */
- (HLDurationField*)seconds;

/**
 */
- (HLDateTimeField*)secondOfMinute;

/**
 */
- (HLDateTimeField*)secondOfDay;

// Minute
//-----------------------------------------------------------------------
/**
 */
- (HLDurationField*)minutes;

/**
 */
- (HLDateTimeField*)minuteOfHour;

/**
 */
- (HLDateTimeField*)minuteOfDay;

// Hour
//-----------------------------------------------------------------------
/**
 */
- (HLDurationField*)hours;

/**
 */
- (HLDateTimeField*)hourOfDay;

/**
 */
- (HLDateTimeField*)clockhourOfDay;

// Halfday
//-----------------------------------------------------------------------
/**
 */
- (HLDurationField*)halfdays;

/**
 */
- (HLDateTimeField*)hourOfHalfday;

/**
 */
- (HLDateTimeField*)clockhourOfHalfday;

/**
 */
- (HLDateTimeField*)halfdayOfDay;

// Day
//-----------------------------------------------------------------------
/**
 */
- (HLDurationField*)days;

/**
 */
- (HLDateTimeField*)dayOfWeek;

/**
 */
- (HLDateTimeField*)dayOfMonth;

/**
 */
- (HLDateTimeField*)dayOfYear;

// Week
//-----------------------------------------------------------------------
/**
 */
- (HLDurationField*)weeks;

/**
 */
- (HLDateTimeField*)weekOfWeekyear;

// Weekyear
//-----------------------------------------------------------------------
/**
 */
- (HLDurationField*)weekyears;

/**
 */
- (HLDateTimeField*)weekyear;

/**
 */
- (HLDateTimeField*)weekyearOfCentury;

// Month
//-----------------------------------------------------------------------
/**
 */
- (HLDurationField*)months;

/**
 */
- (HLDateTimeField*)monthOfYear;

// Year
//-----------------------------------------------------------------------
/**
 */
- (HLDurationField*)years;

/**
 */
- (HLDateTimeField*)year;

/**
 */
- (HLDateTimeField*)yearOfEra;

/**
 */
- (HLDateTimeField*)yearOfCentury;

// Century
//-----------------------------------------------------------------------
/**
 */
- (HLDurationField*)centuries;

/**
 */
- (HLDateTimeField*)centuryOfEra;

// Era
//-----------------------------------------------------------------------
/**
 */
- (HLDurationField*)eras;

/**
 */
- (HLDateTimeField*)era;

//-----------------------------------------------------------------------
/**
 */
- (NSString*)string;

@end
