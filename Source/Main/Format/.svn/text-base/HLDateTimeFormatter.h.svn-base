/*
 * HLDateTimeFormatter.h
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


@class HLDateTimePrinter;
@class HLDateTimeParser;
@class HLChronology;
@class HLDateTimeZone;
@class HLAppendable;
@class HLLocalDate;
@class HLLocalTime;
@class HLLocalDateTime;
@class HLDateTime;
@class HLMutableDateTime;
@protocol HLReadableInstant;
@protocol HLReadWritableInstant;

@interface HLDateTimeFormatter : NSObject {
    
@private
    /** The internal printer used to output the datetime. */
    HLDateTimePrinter* iPrinter;
    /** The internal parser used to output the datetime. */
    HLDateTimeParser* iParser;
    /** The locale to use for printing and parsing. */
    NSLocale* iLocale;
    /** Whether the offset is parsed. */
    BOOL iOffsetParsed;
    /** The chronology to use as an override. */
    HLChronology* iChrono;
    /** The zone to use as an override. */
    HLDateTimeZone* iZone;
    /* The pivot year to use for two-digit year parsing. */
    NSInteger iPivotYear;    
}

/**
 */
- (id)initWithPrinter:(HLDateTimePrinter*)printer
               parser:(HLDateTimeParser*)parser;

//-----------------------------------------------------------------------
/**
 */
- (BOOL)isPrinter;

/**
 */
- (HLDateTimePrinter*)printer;

/**
 */
- (BOOL)isParser;

/**
 */
- (HLDateTimeParser*)parser;

//-----------------------------------------------------------------------
/**
 */
- (HLDateTimeFormatter*)withLocale:(NSLocale*)locale;

/**
 */
- (NSLocale*)locale;

//-----------------------------------------------------------------------
/**
 */
- (HLDateTimeFormatter*)withOffsetParsed;

/**
 */
- (BOOL)isOffsetParsed;

//-----------------------------------------------------------------------
/**
 */
- (HLDateTimeFormatter*)withChronology:(HLChronology*)chrono;

/**
 */
- (HLChronology*)chronology;

//-----------------------------------------------------------------------
/**
 */
- (HLDateTimeFormatter*)withZoneUTC;

/**
 */
- (HLDateTimeFormatter*)withDateTimeZone:(HLDateTimeZone*)zone;

/**
 */
- (HLDateTimeZone*)dateTimeZone;

//-----------------------------------------------------------------------
/**
 */
- (HLDateTimeFormatter*)withPivotYear:(NSInteger)pivotYear;

/**
 */
- (HLDateTimeFormatter*)withPivotYear:(NSInteger)pivotYear;

/**
 */
- (NSInteger)pivotYear;

//-----------------------------------------------------------------------
/**
 */
- (void)printToString:(NSMutableString*)buf
      readableInstant:(id<HLReadableInstant>)instant;

/**
 */
- (void)printToStream:(NSOutputStream*)stream
      readableInstant:(id<HLReadableInstant>)instant;

/**
 */
- (void)printToAppendable:(HLAppendable*)appendable
          readableInstant:(id<HLReadableInstant>)instant;

//-----------------------------------------------------------------------
/**
 */
- (void)printToString:(NSMutableString*)buf
              instant:(NSInteger)instant;

/**
 */
- (void)printToStream:(NSOutputStream*)stream
              instant:(NSInteger)instant;

/**
 */
- (void)printToAppendable:(HLAppendable*)appendable
                  instant:(NSInteger)instant;

//-----------------------------------------------------------------------
/**
 */
- (void)printToString:(NSMutableString*)buf
      readablePartial:(id<HLReadablePartial>)partial;

/**
 */
- (void)printToStream:(NSOutputStream*)stream
      readablePartial:(id<HLReadablePartial>)partial;

/**
 */
- (void)printToAppendable:(HLAppendable*)appendable
          readablePartial:(id<HLReadablePartial>)partial;

//-----------------------------------------------------------------------
/**
 */
- (NSString*)printInstant:(id<HLReadableInstant>)instant;

/**
 */
- (NSString*)print:(NSInteger)instant;

/**
 */
- (NSString*)printPartial:(id<HLReadablePartial>)partial;

- (void)printTo:(NSMutableString*)buf
        instant:(NSInteger)instant
     chronology:(HLChronology*)chrono;

- (void)printToStream:(NSOutputStream*)stream
              instant:(NSInteger)instant
           chronology:(HLChronology*)chrono;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)parseInto:(id<HLReadWritableInstant>)instant
                  text:(NSString*)text
              position:(NSInteger)position;

/**
 */
- (NSInteger)parseMillis:(NSString*)text;

/**
 */
- (HLLocalDate*)parseLocalDate:(NSString*)text;

/**
 */
- (HLLocalTime*)parseLocalTime:(NSString*)text;

/**
 */
- (HLLocalDateTime*)parseLocalDateTime:(NSString*)text;

/**
 */
- (HLDateTime*)parseDateTime:(NSString*)text;

/**
 */
- (HLMutableDateTime*)parseMutableDateTime:(NSString*)text;

@end
