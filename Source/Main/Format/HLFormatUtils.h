/*
 * HLFormatUtils.h
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


#define LOG_10 (log(10))

@interface HLFormatUtils : NSObject {
    
}

/**
 */
- (id)_init;

/**
 */
+ (void)appendPaddedIntegerToString:(NSMutableString*)buf 
                              value:(NSInteger)value 
                               size:(NSInteger)size;

/**
 */
+ (void)appendPaddedIntegerToString:(NSMutableString*)buf 
                              value:(NSInteger)value 
                               size:(NSInteger)size;

/**
 */
+ (void)writePaddedIntegerToStream:(NSOutputStream*)stream 
                             value:(NSInteger)value 
                              size:(NSInteger)size;

/**
 */
+ (void)writePaddedIntegerToStream:(NSOutputStream*)stream 
                             value:(NSInteger)value 
                              size:(NSInteger)size;

/**
 */
+ (void)appendUnpaddedIntegerToString:(NSMutableString*)buf 
                                value:(NSInteger)value;

/**
 */
+ (void)appendUnpaddedIntegerToString:(NSMutableString*)buf 
                                value:(NSInteger)value;

/**
 */
+ (void)writeUnpaddedIntegerToStream:(NSOutputStream*)stream 
                               value:(NSInteger)value;

/**
 */
+ (NSInteger)calculateDigitCount:(NSInteger)value;

+ (NSInteger)parseTwoDigits:(NSString*)text 
                   position:(NSInteger)position;

+ (NSString*)createErrorMessage:(NSString*)text
                       errorPos:(NSInteger)errorPos;

@end
