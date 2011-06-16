/*
 * HLZonedChronology.h
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
#import "HLBaseDurationField.h"
#import "HLDurationField.h"
#import "HLDateTimeZone.h"
#import "HLBaseDateTimeField.h"
#import "HLDateTimeField.h"


//-----------------------------------------------------------------------
/*
 */
@interface HLZonedDurationField : HLBaseDurationField {
    
@private
    HLDurationField* iField;
    BOOL iTimeField;
    HLDateTimeZone* iZone;
}

- (id)initWithField:(HLDurationField*)field
               zone:(HLDateTimeZone*)zone;

- (BOOL)isPrecise;

- (NSInteger)unitMillis;

- (NSInteger)value:(NSInteger)duration 
           instant:(NSInteger)instant;

- (NSInteger)millis:(NSInteger)value 
            instant:(NSInteger)instant;

- (NSInteger)add:(NSInteger)instant 
           value:(NSInteger)value;

- (NSInteger)difference:(NSInteger)minuendInstant 
      subtrahendInstant:(NSInteger)subtrahendInstant;

- (NSInteger)offsetToAdd:(NSInteger)instant;

- (NSInteger)offsetFromLocalToSubtract:(NSInteger)instant;

- (NSInteger)addOffset:(NSInteger)instant;

@end


//-----------------------------------------------------------------------
/**
 */
@interface HLZonedDateTimeField : HLBaseDateTimeField {
    
@private
    HLDateTimeField* iField;
    HLDateTimeZone* iZone;
    HLDurationField* iDurationField;
    BOOL iTimeField;
    HLDurationField* iRangeDurationField;
    HLDurationField* iLeapDurationField;
}

- (id)initWithField:(HLDateTimeField*)field
               zone:(HLDateTimeZone*)zone
      durationField:(HLDurationField*)durationField
 rangeDurationField:(HLDurationField*)rangeDurationField
  leapDurationField:(HLDurationField*)leapDurationField;

- (BOOL)isLenient;

- (NSInteger)get:(NSInteger)instant;

- (NSString*)asText:(NSInteger)instant 
             locale:(NSLocale*)locale;

- (NSString*)asShortText:(NSInteger)instant 
                  locale:(NSLocale*)locale;

- (NSString*)fieldValueAsText:(NSInteger)fieldValue 
                       locale:(NSLocale*)locale;

- (NSString*)fieldValueAsShortText:(NSInteger)fieldValue 
                            locale:(NSLocale*)locale;

- (NSInteger)add:(NSInteger)instant 
           value:(NSInteger)value;

- (NSInteger)addWrapField:(NSInteger)instant 
                    value:(NSInteger)value;

- (NSInteger)set:(NSInteger)instant 
           value:(NSInteger)value;

- (NSInteger)set:(NSInteger)instant 
            text:(NSString*)text 
          locale:(NSLocale*)locale;

- (NSInteger)difference:(NSInteger)minuendInstant 
      subtrahendInstant:(NSInteger)subtrahendInstant;

- (HLDurationField*)durationField;

- (HLDurationField*)rangeDurationField;

- (BOOL)isLeap:(NSInteger)instant;

- (NSInteger)leapAmount:(NSInteger)instant;

- (HLDurationField*)leapDurationField;

- (NSInteger)roundFloor:(NSInteger)instant;

- (NSInteger)roundCeiling:(NSInteger)instant;

- (NSInteger)remainder:(NSInteger)instant;

- (NSInteger)minimumValue;

- (NSInteger)minimumValue:(NSInteger)instant;

- (NSInteger)minimumValueFromPartial:(id<HLReadablePartial>)instant;

- (NSInteger)minimumValue:(id<HLReadablePartial>)instant 
                   values:(NSArray*)values;

- (NSInteger)maximumValue;

- (NSInteger)maximumValue:(NSInteger)instant;

- (NSInteger)maximumValue:(id<HLReadablePartial>)instant;

- (NSInteger)maximumValue:(id<HLReadablePartial>)instant
                   values:(NSArray*)values;

- (NSInteger)maximumTextLength:(NSLocale*)locale;

- (NSInteger)maximumShortTextLength:(NSLocale*)locale;

- (NSInteger)getOffsetToAdd:(NSInteger)instant;

@end


//-----------------------------------------------------------------------
@interface HLZonedChronology : HLAssembledChronology {
    
}

/**
 */
+ (HLZonedChronology*)instance:(HLChronology*)base
                          zone:(HLDateTimeZone*)zone;

+ (BOOL)useTimeArithmetic:(HLDurationField*)field;

/**
 */
- (id)initWithChronology:(HLChronology*)base
                    zone:(HLDateTimeZone*)zone;

- (HLDateTimeZone*)zone;

- (HLChronology*)withUTC;

- (HLChronology*)withZone:(HLDateTimeZone*)zone;

- (NSInteger)getDateTimeMillis:(NSInteger)year 
                   monthOfYear:(NSInteger)monthOfYear 
                    dayOfMonth:(NSInteger)dayOfMonth
                   millisOfDay:(NSInteger)millisOfDay;

- (NSInteger)getDateTimeMillis:(NSInteger)year 
                   monthOfYear:(NSInteger)monthOfYear 
                    dayOfMonth:(NSInteger)dayOfMonth
                     hourOfDay:(NSInteger)hourOfDay 
                  minuteOfHour:(NSInteger)minuteOfHour
                secondOfMinute:(NSInteger)secondOfMinute 
                millisOfSecond:(NSInteger)millisOfSecond;

- (NSInteger)getDateTimeMillis:(NSInteger)instant
                     hourOfDay:(NSInteger)hourOfDay 
                  minuteOfHour:(NSInteger)minuteOfHour
                secondOfMinute:(NSInteger)secondOfMinute
                millisOfSecond:(NSInteger)millisOfSecond;

/**
 */
- (NSInteger)localToUTC:(NSInteger)instant;

- (void)assemble:(HLFields*)fields;

- (HLDurationField*)convertDurationField:(HLDurationField*)field
                               converted:(NSDictionary*)converted;

- (HLDateTimeField*)convertDateTimeField:(HLDateTimeField*)field
                               converted:(NSDictionary*)converted;

//-----------------------------------------------------------------------
/**
 */
- (BOOL)isEqual:(id)obj;

/**
 */
- (NSInteger)hashCode;

/**
 */
- (NSString*)string;

@end
