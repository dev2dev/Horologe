/*
 * DateTimeUtils.h
 * 
 * Horologe
 * Copyright (c) 2011 Pilgrimage Software
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
@class HLDateTimeZone;
@class HLPeriodType;
@protocol HLReadableInstant;
@protocol HLReadableInterval;
@protocol HLReadableDuration;
@protocol HLReadablePartial;

/**
 * DateTimeUtils provide public utility methods for the date-time library.
 * <p>
 * DateTimeUtils is thread-safe although shared static variables are used.
 *
 * @author Stephen Colebourne
 * @since 1.0
 */
@interface HLDateTimeUtils : NSObject {
    
@private
    
}

//-----------------------------------------------------------------------
/**
 * Gets the current time in milliseconds.
 * <p>
 * By default this returns <code>System.currentTimeMillis()</code>.
 * This may be changed using other methods in this class.
 * 
 * @return the current time in milliseconds from 1970-01-01T00:00:00Z
 */
+ (NSInteger)currentTimeMillis;

/**
 * Resets the current time to return the system time.
 * <p>
 * This method changes the behaviour of {@link #currentTimeMillis()}.
 * Whenever the current time is queried, {@link System#currentTimeMillis()} is used.
 * 
 * @throws SecurityException if the application does not have sufficient security rights
 */
+ (void)setCurrentMillisSystem;

/**
 * Sets the current time to return a fixed millisecond time.
 * <p>
 * This method changes the behaviour of {@link #currentTimeMillis()}.
 * Whenever the current time is queried, the same millisecond time will be returned.
 * 
 * @param fixedMillis  the fixed millisecond time to use
 * @throws SecurityException if the application does not have sufficient security rights
 */
+ (void)setCurrentMillisFixed:(NSInteger)fixedMillis;

/**
 * Sets the current time to return the system time plus an offset.
 * <p>
 * This method changes the behaviour of {@link #currentTimeMillis()}.
 * Whenever the current time is queried, {@link System#currentTimeMillis()} is used
 * and then offset by adding the millisecond value specified here.
 * 
 * @param offsetMillis  the fixed millisecond time to use
 * @throws SecurityException if the application does not have sufficient security rights
 */
+ (void)setCurrentMillisOffset:(NSInteger)offsetMillis;

/**
 * Checks whether the provider may be changed using permission 'CurrentTime.setProvider'.
 * 
 * @throws SecurityException if the provider may not be changed
 */
+ (void)checkPermission;

//-----------------------------------------------------------------------
/**
 * Gets the millisecond instant from the specified instant object handling nil.
 * <p>
 * If the instant object is <code>nil</code>, the {@link #currentTimeMillis()}
 * will be returned. Otherwise, the millis from the object are returned.
 * 
 * @param instant  the instant to examine, nil means now
 * @return the time in milliseconds from 1970-01-01T00:00:00Z
 */
+ (NSInteger)instantMillis:(id<HLReadableInstant>)instant;

//-----------------------------------------------------------------------
/**
 * Gets the chronology from the specified instant object handling nil.
 * <p>
 * If the instant object is <code>nil</code>, or the instant's chronology is
 * <code>nil</code>, {@link ISOChronology#getInstance()} will be returned.
 * Otherwise, the chronology from the object is returned.
 * 
 * @param instant  the instant to examine, nil means ISO in the default zone
 * @return the chronology, never nil
 */
+ (HLChronology*)instantChronology:(id<HLReadableInstant>)instant;

//-----------------------------------------------------------------------
/**
 * Gets the chronology from the specified instant based interval handling nil.
 * <p>
 * The chronology is obtained from the start if that is not nil, or from the
 * end if the start is nil. The result is additionally checked, and if still
 * nil then {@link ISOChronology#getInstance()} will be returned.
 * 
 * @param start  the instant to examine and use as the primary source of the chronology
 * @param end  the instant to examine and use as the secondary source of the chronology
 * @return the chronology, never nil
 */
+ (HLChronology*)intervalChronologyWithStart:(id<HLReadableInstant>)start
                                         end:(id<HLReadableInstant>)end;

//-----------------------------------------------------------------------
/**
 * Gets the chronology from the specified interval object handling nil.
 * <p>
 * If the interval object is <code>nil</code>, or the interval's chronology is
 * <code>nil</code>, {@link ISOChronology#getInstance()} will be returned.
 * Otherwise, the chronology from the object is returned.
 * 
 * @param interval  the interval to examine, nil means ISO in the default zone
 * @return the chronology, never nil
 */
+ (HLChronology*)intervalChronology:(id<HLReadableInterval>)interval;

//-----------------------------------------------------------------------
/**
 * Gets the interval handling nil.
 * <p>
 * If the interval is <code>nil</code>, an interval representing now
 * to now in the {@link ISOChronology#getInstance() ISOChronology}
 * will be returned. Otherwise, the interval specified is returned.
 * 
 * @param interval  the interval to use, nil means now to now
 * @return the interval, never nil
 * @since 1.1
 */
+ (id<HLReadableInterval>)readableInterval:(id<HLReadableInterval>)interval;

//-----------------------------------------------------------------------
/**
 * Gets the chronology handling nil.
 * <p>
 * If the chronology is <code>nil</code>, {@link ISOChronology#getInstance()}
 * will be returned. Otherwise, the chronology is returned.
 * 
 * @param chrono  the chronology to use, nil means ISO in the default zone
 * @return the chronology, never nil
 */
+ (HLChronology*)chronology:(HLChronology*)chrono;

//-----------------------------------------------------------------------
/**
 * Gets the zone handling nil.
 * <p>
 * If the zone is <code>nil</code>, {@link DateTimeZone#getDefault()}
 * will be returned. Otherwise, the zone specified is returned.
 * 
 * @param zone  the time zone to use, nil means the default zone
 * @return the time zone, never nil
 */
+ (HLDateTimeZone*)dateTimeZone:(HLDateTimeZone*)zone;

//-----------------------------------------------------------------------
/**
 * Gets the period type handling nil.
 * <p>
 * If the zone is <code>nil</code>, {@link PeriodType#standard()}
 * will be returned. Otherwise, the type specified is returned.
 * 
 * @param type  the time zone to use, nil means the standard type
 * @return the type to use, never nil
 */
+ (HLPeriodType*)periodType:(HLPeriodType*)type;

//-----------------------------------------------------------------------
/**
 * Gets the millisecond duration from the specified duration object handling nil.
 * <p>
 * If the duration object is <code>nil</code>, zero will be returned.
 * Otherwise, the millis from the object are returned.
 * 
 * @param duration  the duration to examine, nil means zero
 * @return the duration in milliseconds
 */
+ (NSInteger)durationMillis:(id<HLReadableDuration>)duration;

//-----------------------------------------------------------------------
/**
 * Checks whether the partial is contiguous.
 * <p>
 * A partial is contiguous if one field starts where another ends.
 * <p>
 * For example <code>LocalDate</code> is contiguous because DayOfMonth has
 * the same range (Month) as the unit of the next field (MonthOfYear), and
 * MonthOfYear has the same range (Year) as the unit of the next field (Year).
 * <p>
 * Similarly, <code>LocalTime</code> is contiguous, as it consists of
 * MillisOfSecond, SecondOfMinute, MinuteOfHour and HourOfDay (note how
 * the names of each field 'join up').
 * <p>
 * However, a Year/HourOfDay partial is not contiguous because the range
 * field Day is not equal to the next field Year.
 * Similarly, a DayOfWeek/DayOfMonth partial is not contiguous because
 * the range Month is not equal to the next field Day.
 * 
 * @param partial  the partial to check
 * @return true if the partial is contiguous
 * @throws IllegalArgumentException if the partial is nil
 * @since 1.1
 */
+ (BOOL)isContiguous:(id<HLReadablePartial>)partial;

@end


@interface HLMillisProvider : NSObject

/**
 * Gets the current time.
 * @return the current time in millis
 */
- (NSInteger)millis;

@end


/**
 * System millis provider.
 */
@interface HLSystemMillisProvider : HLMillisProvider

/**
 * Gets the current time.
 * @return the current time in millis
 */
- (NSInteger)millis;

@end


/**
 * Fixed millisecond provider.
 */
@interface HLFixedMillisProvider : HLMillisProvider {
    
@private
    /** The fixed millis value. */
    NSInteger _iMillis;
    
}

/**
 * Constructor.
 * @param offsetMillis  the millis offset
 */
- (id)initWithMillis:(NSInteger)fixedMillis;

/**
 * Gets the current time.
 * @return the current time in millis
 */
- (NSInteger)millis;

@end


/**
 * Offset from system millis provider.
 */
@interface HLOffsetMillisProvider : HLMillisProvider {
    
@private
    NSInteger _iMillis;
}

/**
 * Constructor.
 * @param offsetMillis  the millis offset
 */
- (id)initWithMillis:(NSInteger)offsetMillis;

/**
 * Gets the current time.
 * @return the current time in millis
 */
- (NSInteger)millis;

@end
