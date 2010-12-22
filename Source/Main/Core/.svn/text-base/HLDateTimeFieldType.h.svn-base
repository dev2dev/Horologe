/*
 * HLDateTimeFieldType.h
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
#import "HLDurationFieldType.h"
#import "HLDateTimeField.h"


@interface HLDateTimeFieldType {
    
@private
    /** The name of the field. */
    NSString* iName;
}

/** Ordinal values for standard field types. */
#define HL_ERA                  1
#define HL_YEAR_OF_ERA          2
#define HL_CENTURY_OF_ERA       3
#define HL_YEAR_OF_CENTURY      4
#define HL_YEAR                 5
#define HL_DAY_OF_YEAR          6
#define HL_MONTH_OF_YEAR        7
#define HL_DAY_OF_MONTH         8
#define HL_WEEKYEAR_OF_CENTURY  9
#define HL_WEEKYEAR             10
#define HL_WEEK_OF_WEEKYEAR     11
#define HL_DAY_OF_WEEK          12
#define HL_HALFDAY_OF_DAY       13
#define HL_HOUR_OF_HALFDAY      14
#define HL_CLOCKHOUR_OF_HALFDAY 15
#define HL_CLOCKHOUR_OF_DAY     16
#define HL_HOUR_OF_DAY          17
#define HL_MINUTE_OF_DAY        18
#define HL_MINUTE_OF_HOUR       19
#define HL_SECOND_OF_DAY        20
#define HL_SECOND_OF_MINUTE     21
#define HL_MILLIS_OF_DAY        22
#define HL_MILLIS_OF_SECOND     23

/** The era field type. */
extern HLDateTimeFieldType* const ERA_TYPE;
/** The yearOfEra field type. */
extern HLDateTimeFieldType* const YEAR_OF_ERA_TYPE;
/** The centuryOfEra field type. */
extern HLDateTimeFieldType* const CENTURY_OF_ERA_TYPE;
/** The yearOfCentury field type. */
extern HLDateTimeFieldType* const YEAR_OF_CENTURY_TYPE;
/** The year field type. */
extern HLDateTimeFieldType* const YEAR_TYPE;
/** The dayOfYear field type. */
extern HLDateTimeFieldType* const DAY_OF_YEAR_TYPE;
/** The monthOfYear field type. */
extern HLDateTimeFieldType* const MONTH_OF_YEAR_TYPE;
/** The dayOfMonth field type. */
extern HLDateTimeFieldType* const DAY_OF_MONTH_TYPE;
/** The weekyearOfCentury field type. */
extern HLDateTimeFieldType* const WEEKYEAR_OF_CENTURY_TYPE;
/** The weekyear field type. */
extern HLDateTimeFieldType* const WEEKYEAR_TYPE;
/** The weekOfWeekyear field type. */
extern HLDateTimeFieldType* const WEEK_OF_WEEKYEAR_TYPE;
/** The dayOfWeek field type. */
extern HLDateTimeFieldType* const DAY_OF_WEEK_TYPE;

/** The halfday field type. */
extern HLDateTimeFieldType* const HALFDAY_OF_DAY_TYPE;
/** The hourOfHalfday field type. */
extern HLDateTimeFieldType* const HOUR_OF_HALFDAY_TYPE;
/** The clockhourOfHalfday field type. */
extern HLDateTimeFieldType* const CLOCKHOUR_OF_HALFDAY_TYPE;
/** The clockhourOfDay field type. */
extern HLDateTimeFieldType* const CLOCKHOUR_OF_DAY_TYPE;
/** The hourOfDay field type. */
extern HLDateTimeFieldType* const HOUR_OF_DAY_TYPE;
/** The minuteOfDay field type. */
extern HLDateTimeFieldType* const MINUTE_OF_DAY_TYPE;
/** The minuteOfHour field type. */
extern HLDateTimeFieldType* const MINUTE_OF_HOUR_TYPE;
/** The secondOfDay field type. */
extern HLDateTimeFieldType* const SECOND_OF_DAY_TYPE;
/** The secondOfMinute field type. */
extern HLDateTimeFieldType* const SECOND_OF_MINUTE_TYPE;
/** The millisOfDay field type. */
extern HLDateTimeFieldType* const MILLIS_OF_DAY_TYPE;
/** The millisOfSecond field type. */
extern HLDateTimeFieldType* const MILLIS_OF_SECOND_TYPE;

//-----------------------------------------------------------------------
/**
 */
- (id)initWithName:(NSString*)name;

//-----------------------------------------------------------------------
/**
 */
+ (HLDateTimeFieldType*)millisOfSecond;

/**
 */
+ (HLDateTimeFieldType*)millisOfDay;

/**
 */
+ (HLDateTimeFieldType*)secondOfMinute;

/**
 */
+ (HLDateTimeFieldType*)secondOfDay;

/**
 */
+ (HLDateTimeFieldType*)minuteOfHour;

/**
 */
+ (HLDateTimeFieldType*)minuteOfDay;

/**
 */
+ (HLDateTimeFieldType*)hourOfDay;

/**
 */
+ (HLDateTimeFieldType*)clockhourOfDay;

/**
 */
+ (HLDateTimeFieldType*)hourOfHalfday;

/**
 */
+ (HLDateTimeFieldType*)clockhourOfHalfday;

/**
 */
+ (HLDateTimeFieldType*)halfdayOfDay;

//-----------------------------------------------------------------------
/**
 */
+ (HLDateTimeFieldType*)dayOfWeek;

/**
 */
+ (HLDateTimeFieldType*)dayOfMonth;

/**
 */
+ (HLDateTimeFieldType*)dayOfYear;

/**
 */
+ (HLDateTimeFieldType*)weekOfWeekyear;

/**
 */
+ (HLDateTimeFieldType*)weekyear;

/**
 */
+ (HLDateTimeFieldType*)weekyearOfCentury;

/**
 */
+ (HLDateTimeFieldType*)monthOfYear;

/**
 */
+ (HLDateTimeFieldType*)year;

/**
 */
+ (HLDateTimeFieldType*)yearOfEra;

/**
 */
+ (HLDateTimeFieldType*)yearOfCentury;

/**
 */
+ (HLDateTimeFieldType*)centuryOfEra;

/**
 */
+ (HLDateTimeFieldType*)era;

//-----------------------------------------------------------------------
/**
 */
- (NSString*)name;

/**
 */
- (HLDurationFieldType*)durationType;

/**
 */
- (HLDurationFieldType*)rangeDurationType;

/**
 */
- (HLDateTimeField*)fieldFromChronology:(HLChronology*)chronology;

/**
 */
- (BOOL)isSupported:(HLChronology*)chronology;

/**
 */
- (NSString*)string;

@end
