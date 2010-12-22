/*
 * HLFixedDateTimeZone.h
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

#import "HLDateTimeZone.h"


@interface HLFixedDateTimeZone : HLDateTimeZone {
    
@private 
    NSString* iNameKey;
    NSInteger iWallOffset;
    NSInteger iStandardOffset;
}

- (id)initWithName:(NSString*)name
           nameKey:(NSString*)nameKey
        wallOffset:(NSInteger)wallOffset
    standardOffset:(NSInteger)standardOffset;

- (NSString*)nameKey:(NSInteger)instant;

- (NSInteger)getOffset:(NSInteger)instant;

- (NSInteger)getStandardOffset:(NSInteger)instant;

- (NSInteger)getOffsetFromLocal:(NSInteger)instantLocal;

- (BOOL)isFixed;

- (NSInteger)nextTransition:(NSInteger)instant;

- (NSInteger)previousTransition:(NSInteger)instant;

#if 0
/**
 * Override to return the correct timzone instance.
 * @since 1.5
 */
public java.util.TimeZone toTimeZone() {
    String id = getID();
    if (id.length() == 6 && (id.startsWith("+") || id.startsWith("-"))) {
        // standard format offset [+-]hh:mm
        // our ID is without any prefix, so we need to add the GMT back
        return java.util.TimeZone.getTimeZone("GMT" + getID());
    }
    // unusual offset, so setup a SimpleTimeZone as best we can
    return new java.util.SimpleTimeZone(iWallOffset, getID());
}
#endif

- (BOOL)isEqual:(id)obj;

- (NSInteger)hashCode;

@end
