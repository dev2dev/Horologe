/*
 * HLDateTimeUtils.h
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


@class HLChronology;
@class HLDateFormatSymbols;
@class HLPeriodType;
@class HLDateTimeZone;
@protocol HLMillisProvider;
@protocol HLReadableInstant;
@protocol HLReadableInterval;
@protocol HLReadableDuration;
@protocol HLReadablePartial;


@interface HLDateTimeUtils : NSObject {
    
}

- (id)_init;

//-----------------------------------------------------------------------
/**
 */
+ (NSInteger)currentTimeMillis;

/**
 */
+ (void)setCurrentMillisSystem;

/**
 */
+ (void)setCurrentMillisFixed:(NSInteger)fixedMillis;

/**
 */
+ (void)setCurrentMillisOffset:(NSInteger)offsetMillis;

/**
 */
+ (void)setCurrentMillisProvider:(id<HLMillisProvider>)millisProvider;

//-----------------------------------------------------------------------
/**
 */
+ (NSInteger)instantMillis:(id<HLReadableInstant>)instant;

//-----------------------------------------------------------------------
/**
 */
+ (HLChronology*)instantChronology:(id<HLReadableInstant>)instant;

//-----------------------------------------------------------------------
/**
 */
+ (HLChronology*)intervalChronology:(id<HLReadableInstant>)start
                                end:(id<HLReadableInstant>)end;

//-----------------------------------------------------------------------
/**
 */
+ (HLChronology*)intervalChronology:(id<HLReadableInterval>)interval;

//-----------------------------------------------------------------------
/**
 */
+ (id<HLReadableInterval>)readableInterval:(id<HLReadableInterval>)interval;

//-----------------------------------------------------------------------
/**
 */
+ (HLChronology*)chronology:(HLChronology*)chrono;

//-----------------------------------------------------------------------
/**
 */
+ (HLDateTimeZone*)dateTimeZone:(HLDateTimeZone*)zone;

//-----------------------------------------------------------------------
/**
 */
+ (HLPeriodType*)periodType:(HLPeriodType*)type;

//-----------------------------------------------------------------------
/**
 */
+ (NSInteger)getDurationMillis:(id<HLReadableDuration>)duration;

//-----------------------------------------------------------------------
/**
 */
+ (BOOL)isContiguous:(id<HLReadablePartial>)partial;

//-----------------------------------------------------------------------
/**
 */
+ (HLDateFormatSymbols*)dateFormatSymbols:(NSLocale*)locale;

@end


//-----------------------------------------------------------------------
@protocol HLMillisProvider

- (NSInteger)millis;

@end


//-----------------------------------------------------------------------
@interface HLSystemMillisProvider : NSObject <HLMillisProvider> {
    
}

- (NSInteger)millis;

@end


//-----------------------------------------------------------------------
@interface HLFixedMillisProvider : NSObject <HLMillisProvider> {
    
@private
    /** The fixed millis value. */
    NSInteger iMillis;
    
}

- (id)initWithMillis:(NSInteger)millis;

- (NSInteger)millis;

@end


//-----------------------------------------------------------------------
@interface HLOffsetMillisProvider : NSObject <HLMillisProvider> {
    
@private
    /** The fixed millis value. */
    NSInteger iMillis;
    
}

- (id)initWithMillis:(NSInteger)offsetMillis;

- (NSInteger)millis;

@end


