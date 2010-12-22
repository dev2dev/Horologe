/*
 * HLChronology.h
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


@class HLDateTimeZone;
@class HLDateTimeField;
@class HLDurationField;
@protocol HLReadablePeriod;
@protocol HLReadablePartial;

@interface HLChronology : NSObject {
    
}

/**
 */
- (HLDateTimeZone*)dateTimeZone;

/**
 */
- (HLChronology*)withUTC;

/**
 */
- (HLChronology*)withDateTimeZone:(HLDateTimeZone*)zone;

/**
 */
- (NSInteger)getDateTimeMillis:(NSInteger)year 
                   monthOfYear:(NSInteger)monthOfYear 
                    dayOfMonth:(NSInteger)dayOfMonth 
                   millisOfDay:(NSInteger)millisOfDay;

/**
 */
- (NSInteger)getDateTimeMillis:(NSInteger)year 
                   monthOfYear:(NSInteger)monthOfYear 
                    dayOfMonth:(NSInteger)dayOfMonth
                     hourOfDay:(NSInteger)hourOfDay 
                  minuteOfHour:(NSInteger)minuteOfHour
                secondOfMinute:(NSInteger)secondOfMinute 
                millisOfSecond:(NSInteger)millisOfSecond;

/**
 */
- (NSInteger)getDateTimeMillis:(NSInteger)instant
                     hourOfDay:(NSInteger)hourOfDay 
                  minuteOfHour:(NSInteger)minuteOfHour
                secondOfMinute:(NSInteger)secondOfMinute 
                millisOfSecond:(NSInteger)millisOfSecond;

//-----------------------------------------------------------------------
/**
 */
- (void)validate:(id<HLReadablePartial>)partial 
          values:(NSArray*)values;

/**
 */
- (NSArray*)get:(id<HLReadablePartial>)partial 
        instant:(NSInteger)instant;

/**
 */
- (NSInteger)set:(id<HLReadablePartial>)partial 
         instant:(NSInteger)instant;

//-----------------------------------------------------------------------
/**
 */
- (NSArray*)get:(id<HLReadablePeriod>)period 
   startInstant:(NSInteger)startInstant 
     endInstant:(NSInteger)endInstant;

/**
 */
- (NSArray*)get:(id<HLReadablePeriod>)period 
       duration:(NSInteger)duration;

/**
 */
- (NSInteger)addPeriod:(id<HLReadablePeriod>)period 
               instant:(NSInteger)instant 
                scalar:(NSInteger)scalar;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)add:(NSInteger)instant 
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

@end
