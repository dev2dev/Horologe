/*
 * HLZoneInfoCompiler.h
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


@class HLDateTimeOfYear;
@class HLChronology;
@class HLDateTimeZone;

@interface HLZoneInfoCompiler : NSObject {
    
    HLDateTimeOfYear* cStartOfYear;
    HLChronology* cLenientISO;
    BOOL verbose;
    
    // Maps names to RuleSets.
    NSDictionary* iRuleSets;
    
    // List of Zone objects.
    NSArray* iZones;
    
    // List String pairs to link.
    NSArray* iLinks;
    
}

@property (nonatomic, assign) BOOL verbose;

+ (HLDateTimeOfYear*)startOfYear;

+ (HLChronology*)lenientISOChronology;

+ (void)writeZoneInfoMap:(NSOutputStream*)dout
                 zoneMap:(NSDictionary*)zimap;

+ (NSInteger)parseYear:(NSString*)str
          defaultValue:(NSInteger)def;

+ (NSInteger)parseMonth:(NSString*)str;

+ (NSInteger)parseDayOfWeek:(NSString*)str;

+ (NSString*)parseOptional:(NSString*)str;

+ (NSInteger)parseTime:(NSString*)str;

+ (char)parseZoneChar:(char)c;

/**
 * @return false if error.
 */
+ (BOOL)test:(NSString*)ident 
          tz:(HLDateTimeZone*)tz;

- (id)init;

/**
 * Returns a map of ids to DateTimeZones.
 *
 * @param outputDir optional directory to write compiled data files to
 * @param sources optional list of source files to parse
 */
- (NSDictionary*)compile:(NSFile*)outputDir
                 sources:(NSArray*)sources;

- (void)parseDataFile:(NSInputStream*)stream;

@end
