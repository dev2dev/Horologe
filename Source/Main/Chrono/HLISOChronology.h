/*
 * HLISOChronology.h
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
#import "HLDateTimeZone.h"


#define FAST_CACHE_SIZE (64)

@interface HLStub : NSObject {
    
    @private 
    HLDateTimeZone* iZone;
}
    
- (id)initWithZone:(HLDateTimeZone*)zone;
    
- (id)readResolve;
    
//    private void writeObject(ObjectOutputStream out) throws IOException {
//        out.writeObject(iZone);
//    }
//    
//    private void readObject(ObjectInputStream in)
//    throws IOException, ClassNotFoundException
//    {
//        iZone = (DateTimeZone)in.readObject();
//    }

@end


@interface HLISOChronology : HLAssembledChronology {

@private    
    /** Singleton instance of a UTC ISOChronology */
    HLISOChronology* instanceUTC;
    
    /** Fast cache of zone to chronology */
    NSArray* cFastCache;
    
    /** Cache of zone to chronology */
    NSDictionary* cCache;
}

/**
 */
+ (HLISOChronology*)instanceUTC;

/**
 */
+ (HLISOChronology*)instance;

/**
 */
+ (HLISOChronology*)instance:(HLDateTimeZone*)zone;

// Constructors and instance variables
//-----------------------------------------------------------------------

/**
 */
- (id)initWithChronology:(HLChronology *)base;

// Conversion
//-----------------------------------------------------------------------
/**
 */
- (HLChronology*)withUTC;

/**
 */
- (HLChronology*)withZone:(HLDateTimeZone*)zone;

// Output
//-----------------------------------------------------------------------
/**
 */
- (NSString*)string;

- (void)assemble:(HLFields*)fields;

/**
 */
- (BOOL)isEqual:(id)object;

/**
 */
- (NSInteger)hashCode;

/**
 */
- (id)writeReplace;

@end
