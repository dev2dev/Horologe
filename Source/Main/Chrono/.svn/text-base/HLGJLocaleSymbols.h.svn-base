/*
 * HLGJLocaleSymbols.h
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


#define FAST_CACHE_SIZE 64

@interface HLGJLocaleSymbols : NSObject {
    
@private
    NSArray* cFastCache;
    NSDictionary* cCache;
    
    private final WeakReference<Locale> iLocale;
    
    NSArray* iEras;
    NSArray* iDaysOfWeek;
    NSArray* iShortDaysOfWeek;
    NSArray* iMonths;
    NSArray* iShortMonths;
    NSArray* iHalfday;
    
    NSDictionary* iParseEras;
    NSDictionary* iParseDaysOfWeek;
    NSDictionary* iParseMonths;
    
    NSInteger iMaxEraLength;
    NSInteger iMaxDayOfWeekLength;
    NSInteger iMaxShortDayOfWeekLength;
    NSInteger iMaxMonthLength;
    NSInteger iMaxShortMonthLength;
    NSInteger iMaxHalfdayLength;
}

+ (HLGJLocaleSymbols*)forLocale(NSLocale*)locale;

+ (NSArray*)realignMonths:(NSArray*)months;

+ (NSArray*)realignDaysOfWeek(NSArray*)daysOfWeek;

+ (void)addSymbolsMap:(NSDictionary*)map
              symbols:(NSArray*)symbols
             integers:(NSArray*)integers;

+ (void)addNumeralsMap:(NSDictionary*)map
                 start:(NSInteger)start
                   end:(NSInteger)end
              integers:(NSArray*)integers;

+ (NSInteger)maxLength(NSArray*)a;

/**
 */
- (id)initWithLocale:(NSLocale*)locale;

- (NSString*)eraValueToText:(NSInteger)value;

- (NSInteger)eraTextToValue:(NSString*)text;

- (NSInteger)eraMaxTextLength;

- (NSString*)monthOfYearValueToText:(NSInteger)value;

- (NSString*)monthOfYearValueToShortText:(NSInteger)value;

- (NSInteger)monthOfYearTextToValue:(NSString*)text;

- (NSInteger)monthMaxTextLength;

- (NSInteger)monthMaxShortTextLength;

- (NSString*)dayOfWeekValueToText:(NSInteger)value;

- (NSString*)dayOfWeekValueToShortText:(NSInteger)value;

- (NSInteger)dayOfWeekTextToValue:(NSString*)text;

- (NSInteger)dayOfWeekMaxTextLength;

- (NSInteger)dayOfWeekMaxShortTextLength;

- (NSString*)halfdayValueToText:(NSInteger)value;

- (NSInteger)halfdayTextToValue:(NSString*)text;

- (NSInteger)halfdayMaxTextLength;

@end
