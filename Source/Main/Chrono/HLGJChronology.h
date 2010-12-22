/*
 * HLGJChronology.h
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
#import "HLInstant.h"
#import "HLGregorianChronology.h"
#import "HLJulianChronology.h"
#import "HLChronology.h"
#import "HLBaseDateTimeField.h"
#import "HLDateTimeField.h"
#import "HLDurationField.h"
#import "HLDecoratedDurationField.h"


//-----------------------------------------------------------------------
/**
 */
@interface HLCutoverField : HLBaseDateTimeField {
    
@private
    HLDateTimeField* iJulianField;
    HLDateTimeField* iGregorianField;
    NSInteger iCutover;
    BOOL iConvertByWeekyear;
    
@protected
    HLDurationField* iDurationField;
    HLDurationField* iRangeDurationField;
}

/**
 */
- (id)initWithJulianField:(HLDateTimeField*)julianField
           gregorianField:(HLDateTimeField*)gregorianField
            cutoverMillis:(NSInteger)cutoverMillis;

/**
 */
- (id)initWithJulianField:(HLDateTimeField*)julianField
           gregorianField:(HLDateTimeField*)gregorianField
            cutoverMillis:(NSInteger)cutoverMillis
        convertByWeekyear:(BOOL)convertByWeekyear;

- (BOOL)isLenient;

- (NSInteger)get:(NSInteger)instant;

- (NSString*)asText:(NSInteger)instant
             locale:(NSLocale*)locale;

- (NSString*)asTextFromFieldValue:(NSInteger)fieldValue
                           locale:(NSLocale*)locale;

- (NSString*)asShortText:(NSInteger)instant
                  locale:(NSLocale*)locale;

- (NSString*)asShortTextFromFieldValue:(NSInteger)fieldValue
                                locale:(NSLocale*)locale;

- (NSInteger)add:(NSInteger)instant
           value:(NSInteger)value;

- (NSArray*)add:(id<HLReadablePartial>)partial 
     fieldIndex:(NSInteger)fieldIndex
         values:(NSArray*)values valueToAdd:(NSInteger)valueToAdd;

- (NSInteger)getDifference:(NSInteger)minuendInstant
         subtrahendInstant:(NSInteger)subtrahendInstant;

- (NSInteger)set:(NSInteger)instant 
           value:(NSInteger)value;

- (NSInteger)set:(NSInteger)instant
            text:(NSString*)text
          locale:(NSLocale*)locale;

- (HLDurationField*)durationField;

- (HLDurationField*)rangeDurationField;

- (BOOL)isLeap:(NSInteger)instant;

- (NSInteger)getLeapAmount:(NSInteger)instant;

- (HLDurationField*)leapDurationField;

- (NSInteger)getMinimumValue;

- (NSInteger)getMinimumValueFromPartial:(id<HLReadablePartial>)partial;

- (NSInteger)getMinimumValueFromPartial:(id<HLReadablePartial>)partial
                                 values:(NSArray*)values;

- (NSInteger)getMinimumValue:(NSInteger)instant;

- (NSInteger)getMaximumValue;

- (NSInteger)getMaximumValue:(NSInteger)instant;

- (NSInteger)getMaximumValueFromPartial:(id<HLReadablePartial>)partial;

- (NSInteger)getMaximumValueFromPartial:(id<HLReadablePartial>)partial
                                 values:(NSArray*)values;

- (NSInteger)roundFloor:(NSInteger)instant;

- (NSInteger)roundCeiling:(NSInteger)instant;

- (NSInteger)getMaximumTextLength:(NSLocale*)locale;

- (NSInteger)getMaximumShortTextLength:(NSLocale*)locale;

- (NSInteger)julianToGregorian:(NSInteger)instant;

- (NSInteger)gregorianToJulian:(NSInteger)instant;

@end

//-----------------------------------------------------------------------
/**
 */
@interface HLImpreciseCutoverField : HLCutoverField {
    
}

/**
 */
- (id)initWithJulianField:(HLDateTimeField*)julianField
           gregorianField:(HLDateTimeField*)gregorianField
            cutoverMillis:(NSInteger)cutoverMillis;

/**
 */
- (id)initWithJulianField:(HLDateTimeField*)julianField
           gregorianField:(HLDateTimeField*)gregorianField
            durationField:(HLDurationField*)durationField
            cutoverMillis:(NSInteger)cutoverMillis;

/**
 */
- (id)initWithJulianField:(HLDateTimeField*)julianField
           gregorianField:(HLDateTimeField*)gregorianField
            durationField:(HLDurationField*)durationField
            cutoverMillis:(NSInteger)cutoverMillis, 
convertByWeekyear:(BOOL)convertByWeekyear;

- (NSInteger)add:(NSInteger)instant 
           value:(NSInteger)value;

- (NSInteger)add:(NSInteger)instant
           value:(NSInteger)value;

- (NSInteger)getDifference:(NSInteger)minuendInstant
         subtrahendInstant:(NSInteger)subtrahendInstant;

// Since the imprecise fields have durations longer than the gap
// duration, keep these methods simple. The inherited implementations
// produce incorrect results.
//
// Degenerate case: If this field is a month, and the cutover is set
// far into the future, then the gap duration may be so large as to
// reduce the number of months in a year. If the missing month(s) are
// at the beginning or end of the year, then the minimum and maximum
// values are not 1 and 12. I don't expect this case to ever occur.

- (NSInteger)getMinimumValue:(NSInteger)instant;

- (NSInteger)getMaximumValue:(NSInteger)instant;

@end


//-----------------------------------------------------------------------
/**
 * Links the duration back to a ImpreciseCutoverField.
 */
@interface HLLinkedDurationField : HLDecoratedDurationField {
@private
    HLImpreciseCutoverField* iField;
}

- (id)initWithDurationField:(HLDurationField*)durationField
              dateTimeField:(HLImpreciseCutoverField*)dateTimeField;

- (NSInteger)add:(NSInteger)instant 
           value:(NSInteger)value;

- (NSInteger)add:(NSInteger)instant
           value:(NSInteger)value;

- (NSInteger)getDifference:(NSInteger)minuendInstant
         subtrahendInstant:(NSInteger)subtrahendInstant;

@end


//-----------------------------------------------------------------------
@interface HLGJChronology : HLAssembledChronology {
    
@private
    /**
     * The default GregorianJulian cutover point.
     */
    HLInstant* defaultCutover;
    
    /** Cache of zone to chronology list */
    NSDictionary* cCache;
    
    HLJulianChronology* iJulianChronology;
    HLGregorianChronology* iGregorianChronology;
    HLInstant* iCutoverInstant;
    
    NSInteger iCutoverMillis;
    NSInteger iGapDuration;
    
    
}

/**
 */
+ (NSInteger)convertByYear:(NSInteger)instant
                      from:(HLChronology*)from
                        to:(HLChronology*)to;

/**
 */
+ (NSInteger)convertByWeekyear:(NSInteger)instant
                          from:(HLChronology*)from
                            to:(HLChronology*)to;

/**
 */
+ (HLGJChronology*)instanceUTC;

/**
 */
+ (HLGJChronology*)instance;

/**
 */
+ (HLGJChronology*)instanceWithZone:(HLDateTimeZone*)zone;

/**
 */
+ (HLGJChronology*)instance:(HLDateTimeZone*)zone
           gregorianCutover:(id<HLReadableInstant>)gregorianCutover;

/**
 */
+ (HLGJChronology*)instance:(HLDateTimeZone*)zone
    gregorianCutoverInstant:(id<HLReadableInstant>)gregorianCutover
         minDaysInFirstWeek:(NSInteger)minDaysInFirstWeek;

/**
 */
+ (HLGJChronology*)instance:(HLDateTimeZone*)zone
           gregorianCutover:(NSInteger)gregorianCutover
         minDaysInFirstWeek:(NSInteger)minDaysInFirstWeek;

//-----------------------------------------------------------------------
/**
 */
- (id)initWithJulianChronology:(HLJulianChronology*)julian
           gregorianChronology:(HLGregorianChronology*)gregorian
                cutoverInstant:(HLInstant*)cutoverInstant;

/**
 */
- (id)initWithBaseChronology:(HLChronology*)base
            julianChronology:(HLJulianChronology*)julian
         gregorianChronology:(HLGregorianChronology*)gregorian
              cutoverInstant:(HLInstant*)cutoverInstant;

/**
 */
- (id)readResolve;

- (HLDateTimeZone*)zone;

// Conversion
//-----------------------------------------------------------------------
/**
 */
- (HLChronology*)withUTC;

/**
 */
- (HLChronology*)withZone:(HLDateTimeZone*)zone;

- (NSInteger)dateTimeMillisFromYear:(NSInteger)year 
                        monthOfYear:(NSInteger)monthOfYear 
                         dayOfMonth:(NSInteger)dayOfMonth
                        millisOfDay:(NSInteger)millisOfDay;

- (NSInteger)dateTimeMillisFromYear:(NSInteger)year 
                        monthOfYear:(NSInteger)monthOfYear 
                         dayOfMonth:(NSInteger)dayOfMonth
                          hourOfDay:(NSInteger)hourOfDay 
                       minuteOfHour:(NSInteger)minuteOfHour
                     secondOfMinute:(NSInteger)secondOfMinute 
                     millisOfSecond:(NSInteger)millisOfSecond;

/**
 */
- (HLInstant*)gregorianCutover;

/**
 */
- (NSInteger)minimumDaysInFirstWeek;

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

- (NSInteger)julianToGregorianByYear:(NSInteger)instant;

- (NSInteger)gregorianToJulianByYear:(NSInteger)instant;

- (NSInteger)julianToGregorianByWeekyear:(NSInteger)instant;

- (NSInteger)gregorianToJulianByWeekyear:(NSInteger)instant;

@end
