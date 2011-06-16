/*
 * HLLimitChronology.h
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
#import "HLChronology.h"
#import "HLDurationField.h"
#import "HLDateTimeField.h"
#import "HLDateTime.h"
#import "HLReadableDateTime.h"



//-----------------------------------------------------------------------
/**
 */
#if 0
private class LimitException extends IllegalArgumentException {
    private static final long serialVersionUID = -5924689995607498581L;
    
    private final boolean iIsLow;
    
    LimitException(String desc, boolean isLow) {
        super(desc);
        iIsLow = isLow;
    }
    
    public String getMessage() {
        StringBuffer buf = new StringBuffer(85);
        buf.append("The");
        String desc = super.getMessage();
        if (desc != null) {
            buf.append(' ');
            buf.append(desc);
        }
        buf.append(" instant is ");
        
        DateTimeFormatter p = ISODateTimeFormat.dateTime();
        p = p.withChronology(getBase());
        if (iIsLow) {
            buf.append("below the supported minimum of ");
            p.printTo(buf, getLowerLimit().getMillis());
        } else {
            buf.append("above the supported maximum of ");
            p.printTo(buf, getUpperLimit().getMillis());
        }
        
        buf.append(" (");
        buf.append(getBase());
        buf.append(')');
        
        return buf.toString();
    }
    
    public String toString() {
        return "IllegalArgumentException: " + getMessage();
    }
}
#endif


//-----------------------------------------------------------------------
@interface HLLimitDurationField : HLDecoratedDurationField {
    
}

- (id)initWithField:(HLDurationField*)field;

- (NSInteger)value:(NSInteger)duration 
           instant:(NSInteger)instant;

- (NSInteger)millis:(NSInteger)value 
            instant:(NSInteger)instant;

- (NSInteger)add:(NSInteger)instant 
          amount:(NSInteger)amount;

- (NSInteger)difference:(NSInteger)minuendInstant 
      subtrahendInstant:(NSInteger)subtrahendInstant;

@end


//-----------------------------------------------------------------------
@interface HLLimitDateTimeField : HLDecoratedDateTimeField {
    
@private    
    HLDurationField* iDurationField;
    HLDurationField* iRangeDurationField;
    HLDurationField* iLeapDurationField;
}

- (id)initWithField:(HLDateTimeField*)field
      durationField:(HLDurationField*)durationField
 rangeDurationField:(HLDurationField*)rangeDurationField
  leapDurationField:(HLDurationField*)leapDurationField;

- (NSInteger)get:(NSInteger)instant;

- (NSString*)asText:(NSInteger)instant
             locale:(NSLocale*)locale;

- (NSString*)asShortText:(NSInteger)instant
                  locale:(NSLocale*)locale;

- (NSInteger)add:(NSInteger)instant 
          amount:(NSInteger)amount;

- (NSInteger)addWrapField:(NSInteger)instant 
                   amount:(NSInteger)amount;

- (NSInteger)difference:(NSInteger)minuendInstant subtrahendInstant:(NSInteger)subtrahendInstant;

- (NSInteger)set:(NSInteger)instant 
           value:(NSInteger)value;

- (NSInteger)set:(NSInteger)instant
            text:(NSString*)text
          locale:(NSLocale*)locale;

- (HLDurationField*)durationField;

- (HLDurationField*)rangeDurationField;

- (BOOL)isLeap:(NSInteger)instant;

- (NSInteger)leapAmount:(NSInteger)instant;

- (HLDurationField*)leapDurationField;

- (NSInteger)roundFloor:(NSInteger)instant;

- (NSInteger)roundCeiling:(NSInteger)instant;

- (NSInteger)roundHalfFloor:(NSInteger)instant;

- (NSInteger)roundHalfCeiling:(NSInteger)instant;

- (NSInteger)roundHalfEven:(NSInteger)instant;

- (NSInteger)remainder:(NSInteger)instant;

- (NSInteger)minimumValue:(NSInteger)instant;

- (NSInteger)maximumValue:(NSInteger)instant;

- (NSInteger)getMaximumTextLength:(NSLocale*)locale;

- (NSInteger)getMaximumShortTextLength:(NSLocale*)locale;

@end


//-----------------------------------------------------------------------
@interface HLLimitChronology : HLAssembledChronology {
    
@private
    HLDateTime* iLowerLimit;
    HLDateTime* iUpperLimit;
    
    HLLimitChronology* iWithUTC;
}

/**
 */
+ (HLLimitChronology*)getInstance:(HLChronology*)base
                       lowerLimit:(id<HLReadableDateTime>)lowerLimit
                       upperLimit:(id<HLReadableDateTime>)upperLimit;

/**
 */
- (id)initWithChronology:(HLChronology *)base 
              lowerLimit:(HLDateTime*)lowerLimit
              upperLimit:(HLDateTime*)upperLimit;

/**
 */
- (HLDateTime*)lowerLimit;

/**
 */
- (HLDateTime*)upperLimit;

/**
 */
- (HLChronology*)withUTC;

/**
 */
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

- (void)assemble:(HLFields*)fields;

- (HLDurationField*)convertDurationField:(HLDurationField*)field
                               converted:(NSDictionary*)converted;

- (HLDateTimeField*)convertDateTimeField:(HLDateTimeField*)field
                               converted:(NSDictionary*)converted;

- (void)checkLimits:(NSInteger)instant
               desc:(NSString*)desc;

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
