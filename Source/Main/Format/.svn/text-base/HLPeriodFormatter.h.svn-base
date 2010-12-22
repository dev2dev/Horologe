/*
 * HLPeriodFormatter.h
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


@class HLPeriodPrinter;
@class HLPeriodParser;
@class HLPeriodType;
@protocol HLReadablePeriod;
@protocol HLReadWritablePeriod;

@interface HLPeriodFormatter : NSObject {
    
@private
    /** The internal printer used to output the datetime. */
    HLPeriodPrinter* iPrinter;
    /** The internal parser used to output the datetime. */
    HLPeriodParser* iParser;
    /** The locale to use for printing and parsing. */
    NSLocale* iLocale;
    /** The period type used in parsing. */
    HLPeriodType* iParseType;
}

/**
 */
- (id)initWithPrinter:(HLPeriodPrinter*)printer
               parser:(HLPeriodParser*)parser;

/**
 */
- (id)_initWithPrinter:(HLPeriodPrinter*)printer
                parser:(HLPeriodParser*)parser
                locale:(NSLocale*)locale
                  type:(HLPeriodType*)type;

//-----------------------------------------------------------------------
/**
 */
- (BOOL)isPrinter;

/**
 */
- (HLPeriodPrinter*)printer;

/**
 */
- (BOOL)isParser;

/**
 */
- (HLPeriodParser*)parser;

//-----------------------------------------------------------------------
/**
 */
- (HLPeriodFormatter*)withLocale:(NSLocale*)locale;

/**
 */
- (NSLocale*)locale;

//-----------------------------------------------------------------------
/**
 */
- (HLPeriodFormatter*)withParseType:(HLPeriodType*)type;

/**
 */
- (HLPeriodType*)parseType;

//-----------------------------------------------------------------------
/**
 */
- (void)printToString:(NSMutableString*)buf
               period:(id<HLReadablePeriod>)period;

/**
 */
- (void)printTo:(NSOutputStream*)writer
         period:(id<HLReadablePeriod>)period;

/**
 */
- (NSString*)print:(id<HLReadablePeriod>)period;

/**
 */
- (void)_checkPrinter;

/**
 */
- (void)_checkPeriod:(id<HLReadablePeriod>)period;

//-----------------------------------------------------------------------
/**
 */
- (NSInteger)parseInto:(id<HLReadWritablePeriod>)period
                  text:(NSString*)text
              position:(NSInteger)position;

/**
 */
- (HLPeriod*)parsePeriod:(NSString*)text;

/**
 */
- (HLMutablePeriod*)parseMutablePeriod:(NSString*)text;

/**
 */
- (void)_checkParser;

@end
