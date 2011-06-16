/*
 * HLDateTimeFormat.h
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

#import "HLDateTimePrinter.h"
#import "HLDateTimeParser.h"


/** Style constant for FULL. */
#define FULL (0)  /* DateFormat.FULL */
/** Style constant for LONG. */
#define LONG (1)  /* DateFormat.LONG */
/** Style constant for MEDIUM. */
#define MEDIUM (2)  /* DateFormat.MEDIUM */
/** Style constant for SHORT. */
#define SHORT (3)  /* DateFormat.SHORT */
/** Style constant for NONE. */
#define NONE (4)

/** Type constant for DATE only. */
#define DATE (0)
/** Type constant for TIME only. */
#define TIME (1)
/** Type constant for DATETIME. */
#define DATETIME (2)

@class HLChronology;
@class HLDateTimeZone;
@class HLDateTimeFormatter;
@protocol HLReadablePartial;

//-----------------------------------------------------------------------
@interface HLStyleFormatter : NSObject <HLDateTimePrinter, HLDateTimeParser> {
    
    NSDictionary* cCache;
    
    NSInteger iDateStyle;
    NSInteger iTimeStyle;
    NSInteger iType;
}

- (id)initWithDateStyle:(NSInteger)dateStyle 
              timeStyle:(NSInteger)timeStyle 
                   type:(NSInteger)type;

- (NSInteger)estimatePrintedLength;

- (void)printToString:(NSMutableString*)buf 
              instant:(NSInteger)instant
           chronology:(HLChronology*)chrono
        displayOffset:(NSInteger)displayOffset
          displayZone:(HLDateTimeZone*)displayZone
               locale:(NSLocale*)locale;

- (void)printToStream:(NSOutputStream*)stream 
              instant:(NSInteger)instant
           chronology:(HLChronology*)chrono
        displayOffset:(NSInteger)displayOffset
          displayZone:(HLDateTimeZone*)displayZone
               locale:(NSLocale*)locale;

- (void)printToString:(NSMutableString*)buf
              partial:(id<HLReadablePartial>)partial
               locale:(NSLocale*)locale;

- (void)printToStream:(NSOutputStream*)stream
              partial:(id<HLReadablePartial>)partial
               locale:(NSLocale*)locale;

- (NSInteger)estimateParsedLength;

- (NSInteger)parseInto:(HLDateTimeParserBucket*)bucket
                  text:(NSString*)text 
              position:(NSInteger)position;

- (HLDateTimeFormatter*)formatter:(NSLocale*)locale;

- (NSString*)pattern:(NSLocale*)locale;

@end


//-----------------------------------------------------------------------
@class HLDateTimeFormatter;
@class HLDateTimeFormatterBuilder;

@interface HLDateTimeFormat : NSObject {
    
@private    
    /** Maps patterns to formatters, patterns don't vary by locale. */
    NSDictionary* cPatternedCache;
    /** Maps patterns to formatters, patterns don't vary by locale. */
    NSArray* /*HLDateTimeFormatter*/ cStyleCache;
}


//-----------------------------------------------------------------------
/**
 */
+ (HLDateTimeFormatter*)forPattern:(NSString*)pattern;

/**
 */
+ (HLDateTimeFormatter*)forStyle:(NSString*)style;

/**
 */
+ (NSString*)patternForStyle:(NSString*)style
                      locale:(NSLocale*)locale;

//-----------------------------------------------------------------------
/**
 */
+ (HLDateTimeFormatter*)shortDate;

/**
 */
+ (HLDateTimeFormatter*)shortTime;

/**
 */
+ (HLDateTimeFormatter*)shortDateTime;

//-----------------------------------------------------------------------
/**
 */
+ (HLDateTimeFormatter*)mediumDate;

/**
 */
+ (HLDateTimeFormatter*)mediumTime;

/**
 */
+ (HLDateTimeFormatter*)mediumDateTime;

//-----------------------------------------------------------------------
/**
 */
+ (HLDateTimeFormatter*)longDate;

/**
 */
+ (HLDateTimeFormatter*)longTime;

/**
 */
+ (HLDateTimeFormatter*)longDateTime;

//-----------------------------------------------------------------------
/**
 */
+ (HLDateTimeFormatter*)fullDate;

/**
 */
+ (HLDateTimeFormatter*)fullTime;

/**
 */
+ (HLDateTimeFormatter*)fullDateTime;

//-----------------------------------------------------------------------
/**
 */
+ (void)appendPatternTo:(HLDateTimeFormatterBuilder*)builder
                pattern:(NSString*)pattern;

//-----------------------------------------------------------------------
/**
 */
- (id)init;

//-----------------------------------------------------------------------
/**
 */
+ (void)parsePatternTo:(HLDateTimeFormatterBuilder*)builder
               pattern:(NSString*)pattern;

/**
 */
+ (NSString*)parseToken:(NSString*)pattern
               indexRef:(NSArray*)indexRef;

/**
 */
+ (BOOL)isNumericToken:(NSString*)token;

//-----------------------------------------------------------------------
/**
 */
+ (HLDateTimeFormatter*)createFormatterForPattern:(NSString*)pattern;

/**
 */
+ (HLDateTimeFormatter*)createFormatterForStyle:(NSString*)style;

/**
 */
+ (HLDateTimeFormatter*)createFormatterForStyleIndex:(NSInteger)dateStyle 
                                           timeStyle:(NSInteger)timeStyle;

/**
 */
+ (NSInteger)selectStyle:(char)ch;

@end
