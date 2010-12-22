/*
 * HLDateTimeParserBucket.h
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
@class HLDateTimeParserBucket;

@interface HLSavedState : NSObject {
    
@private
    HLDateTimeZone* iZone;
    NSInteger iOffset;
    NSArray* /*SavedField[]*/ iSavedFields;
    NSInteger iSavedFieldsCount;
}    

- (id)init;

- (BOOL)restoreState:(HLDateTimeParserBucket*)enclosing;

@end


//-----------------------------------------------------------------------
@class HLDateTimeField;

@interface HLSavedField : NSObject {
    
@private
    HLDateTimeField* iField;
    NSInteger iValue;
    NSString* iText;
    NSLocale* iLocale;
}

- (id)initWithField:(HLDateTimeField*)field
              value:(NSInteger)value;

- (id)initWithField:(HLDateTimeField*)field
               text:(NSString*)text
             locale:(NSLocale*)locale;

- (NSInteger)set:(NSInteger)millis
           reset:(BOOL)reset;

/**
 */
- (NSInteger)compareTo:(HLSavedField*)obj;

- (NSInteger)compareReverse:(HLDurationField*)a
                       with:(HLDurationField*)b;

@end


//-----------------------------------------------------------------------
@class HLChronology;
@class HLDateTimeZone;
@class HLDateTimeField;
@class HLDateTimeFieldType;
@class HLSavedField;

@interface HLDateTimeParserBucket : NSObject {
    
@private
    /** The chronology to use for parsing. */
    HLChronology* iChrono;
    NSInteger iMillis;
    
    // TimeZone to switch to in computeMillis. If null, use offset.
    HLDateTimeZone* iZone;
    NSInteger iOffset;
    /** The locale to use for parsing. */
    NSLocale* iLocale;
    /** Used for parsing two-digit years. */
    NSInteger iPivotYear;
    
    NSArray* /*SavedField[]*/ iSavedFields;
    NSInteger iSavedFieldsCount;
    BOOL iSavedFieldsShared;
    
    id iSavedState;    
}

/**
 */
- (id)initWithInstantLocal:(NSInteger)instantLocal
                chronology:(HLChronology*)chrono
                    locale:(NSLocale*)locale;

/**
 */
- (id)initWithInstantLocal:(NSInteger)instantLocal
                chronology:(HLChronology*)chrono
                    locale:(NSLocale*)locale
                 pivotYear:(NSInteger)pivotYear;

//-----------------------------------------------------------------------
/**
 */
- (HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 */
- (NSLocale*)locale;

//-----------------------------------------------------------------------
/**
 */
- (HLDateTimeZone*)zone;

/**
 */
- (void)setZone:(HLDateTimeZone*)zone;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)offset;

/**
 */
- (void)setOffset:(NSInteger)offset;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)pivotYear;

/**
 */
- (void)setPivotYear:(NSInteger)pivotYear;

//-----------------------------------------------------------------------
/**
 */
- (void)saveField:(HLDateTimeField*)field
            value:(NSInteger)value;

/**
 */
- (void)saveFieldType:(HLDateTimeFieldType*)fieldType
                value:(NSInteger)value;

/**
 */
- (void)saveFieldType:(HLDateTimeFieldType*)fieldType
                 text:(NSString*)text
               locale:(NSLocale*)locale;

- (void)_saveField:(HLSavedField*)field;

/**
 */
- (id)saveState;

/**
 */
- (BOOL)restoreState:(id)savedState;

/**
 */
- (NSInteger)computeMillis;

/**
 */
- (NSInteger)computeMillis:(BOOL)resetFields;

/**
 */
- (NSInteger)computeMillis:(BOOL)resetFields
                      text:(NSString*)text;

/**
 */
+ (void)sort:(NSArray* /*HLSavedField[]*/)array
        high:(NSInteger)high;

@end
