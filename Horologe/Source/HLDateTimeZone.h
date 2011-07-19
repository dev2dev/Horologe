/*
 * DateTimeZone.h
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


@class HLDateTimeZone;
@class HLProvider;
@class HLNameProvider;
@class HLLocalDateTime;
@protocol HLReadableInstant;

/**
 * DateTimeZone represents a time zone.
 * <p>
 * A time zone is a system of rules to convert time from one geographic 
 * location to another. For example, Paris, France is one hour ahead of
 * London, England. Thus when it is 10:00 in London, it is 11:00 in Paris.
 * <p>
 * All time zone rules are expressed, for historical reasons, relative to
 * Greenwich, London. Local time in Greenwich is referred to as Greenwich Mean
 * Time (GMT).  This is similar, but not precisely identical, to Universal 
 * Coordinated Time, or UTC. This library only uses the term UTC.
 * <p>
 * Using this system, America/Los_Angeles is expressed as UTC-08:00, or UTC-07:00
 * in the summer. The offset -08:00 indicates that America/Los_Angeles time is
 * obtained from UTC by adding -08:00, that is, by subtracting 8 hours.
 * <p>
 * The offset differs in the summer because of daylight saving time, or DST.
 * The folowing definitions of time are generally used:
 * <ul>
 * <li>UTC - The reference time.
 * <li>Standard Time - The local time without a daylight saving time offset.
 * For example, in Paris, standard time is UTC+01:00.
 * <li>Daylight Saving Time - The local time with a daylight saving time 
 * offset. This offset is typically one hour, but not always. It is typically
 * used in most countries away from the equator.  In Paris, daylight saving 
 * time is UTC+02:00.
 * <li>Wall Time - This is what a local clock on the wall reads. This will be
 * either Standard Time or Daylight Saving Time depending on the time of year
 * and whether the location uses Daylight Saving Time.
 * </ul>
 * <p>
 * Unlike the Java TimeZone class, DateTimeZone is immutable. It also only
 * supports long format time zone ids. Thus EST and ECT are not accepted.
 * However, the factory that accepts a TimeZone will attempt to convert from
 * the old short id to a suitable long id.
 * <p>
 * DateTimeZone is thread-safe and immutable, and all subclasses must be as
 * well.
 * 
 * @author Brian S O'Neill
 * @author Stephen Colebourne
 * @since 1.0
 */
@interface DateTimeZone : NSObject {
    
@private
    NSString* _iZoneId;
    
}

//-----------------------------------------------------------------------
/**
 * Gets the default time zone.
 * <p>
 * The default time zone is derived from the system property {@code user.timezone}.
 * If that is {@code nil} or is not a valid identifier, then the value of the
 * JDK {@code TimeZone} default is converted. If that fails, {@code UTC} is used.
 * 
 * @return the default datetime zone object
 */
+ (HLDateTimeZone*)defaultDateTimeZone;

/**
 * Sets the default time zone.
 * 
 * @param zone  the default datetime zone object, must not be nil
 * @throws IllegalArgumentException if the zone is nil
 * @throws SecurityException if the application has insufficient security rights
 */
+ (void)setDefaultDateTimeZone:(HLDateTimeZone*)zone;

//-----------------------------------------------------------------------
/**
 * Gets a time zone instance for the specified time zone id.
 * <p>
 * The time zone id may be one of those returned by getAvailableIDs.
 * Short ids, as accepted by {@link java.util.TimeZone}, are not accepted.
 * All IDs must be specified in the long format.
 * The exception is UTC, which is an acceptable id.
 * <p>
 * Alternatively a locale independent, fixed offset, datetime zone can
 * be specified. The form <code>[+-]hh:mm</code> can be used.
 * 
 * @param id  the ID of the datetime zone, nil means default
 * @return the DateTimeZone object for the ID
 * @throws IllegalArgumentException if the ID is not recognised
 */
+ (HLDateTimeZone*)forZoneId:(NSString*)zoneId;

/**
 * Gets a time zone instance for the specified offset to UTC in hours.
 * This method assumes standard length hours.
 * <p>
 * This factory is a convenient way of constructing zones with a fixed offset.
 * 
 * @param hoursOffset  the offset in hours from UTC
 * @return the DateTimeZone object for the offset
 * @throws IllegalArgumentException if the offset is too large or too small
 */
+ (HLDateTimeZone*)forOffsetHours:(NSInteger)hoursOffset;

/**
 * Gets a time zone instance for the specified offset to UTC in hours and minutes.
 * This method assumes 60 minutes in an hour, and standard length minutes.
 * <p>
 * This factory is a convenient way of constructing zones with a fixed offset.
 * The minutes value is always positive and in the range 0 to 59.
 * If constructed with the values (-2, 30), the resulting zone is '-02:30'.
 * 
 * @param hoursOffset  the offset in hours from UTC
 * @param minutesOffset  the offset in minutes from UTC, must be between 0 and 59 inclusive
 * @return the DateTimeZone object for the offset
 * @throws IllegalArgumentException if the offset or minute is too large or too small
 */
+ (HLDateTimeZone*)forOffsetHoursMinutes:(NSInteger)hoursOffset 
                           minutesOffset:(NSInteger)minutesOffset;

/**
 * Gets a time zone instance for the specified offset to UTC in milliseconds.
 *
 * @param millisOffset  the offset in millis from UTC
 * @return the DateTimeZone object for the offset
 */
+ (HLDateTimeZone*)forOffsetMillis:(NSInteger)millisOffset;

/**
 * Gets a time zone instance for a JDK TimeZone.
 * <p>
 * DateTimeZone only accepts a subset of the IDs from TimeZone. The
 * excluded IDs are the short three letter form (except UTC). This 
 * method will attempt to convert between time zones created using the
 * short IDs and the full version.
 * <p>
 * This method is not designed to parse time zones with rules created by
 * applications using <code>SimpleTimeZone</code> directly.
 * 
 * @param zone  the zone to convert, nil means default
 * @return the DateTimeZone object for the zone
 * @throws IllegalArgumentException if the zone is not recognised
 */
+ (HLDateTimeZone*)forTimeZone:(NSTimeZone*)zone;

//-----------------------------------------------------------------------
/**
 * Gets the zone provider factory.
 * <p>
 * The zone provider is a pluggable instance factory that supplies the
 * actual instances of DateTimeZone.
 * 
 * @return the provider
 */
+ (HLProvider*)provider;

/**
 * Sets the zone provider factory.
 * <p>
 * The zone provider is a pluggable instance factory that supplies the
 * actual instances of DateTimeZone.
 * 
 * @param provider  provider to use, or nil for default
 * @throws SecurityException if you do not have the permission DateTimeZone.setProvider
 * @throws IllegalArgumentException if the provider is invalid
 */
+ (void)setProvider:(HLProvider*)provider;

//-----------------------------------------------------------------------
/**
 * Gets the name provider factory.
 * <p>
 * The name provider is a pluggable instance factory that supplies the
 * names of each DateTimeZone.
 * 
 * @return the provider
 */
+ (HLNameProvider*)nameProvider;

/**
 * Sets the name provider factory.
 * <p>
 * The name provider is a pluggable instance factory that supplies the
 * names of each DateTimeZone.
 * 
 * @param nameProvider  provider to use, or nil for default
 * @throws SecurityException if you do not have the permission DateTimeZone.setNameProvider
 * @throws IllegalArgumentException if the provider is invalid
 */
+ (void)setNameProvider:(HLNameProvider*)nameProvider;

// Instance fields and methods
//--------------------------------------------------------------------

/**
 * Constructor.
 * 
 * @param id  the id to use
 * @throws IllegalArgumentException if the id is nil
 */
- (id)initWithZoneId:(NSString*)zoneId;

// Principal methods
//--------------------------------------------------------------------

/**
 * Gets the ID of this datetime zone.
 * 
 * @return the ID of this datetime zone
 */
- (NSString*)zoneId;

/**
 * Returns a non-localized name that is unique to this time zone. It can be
 * combined with id to form a unique key for fetching localized names.
 *
 * @param instant  milliseconds from 1970-01-01T00:00:00Z to get the name for
 * @return name key or nil if id should be used for names
 */
- (NSString*)nameKey:(NSInteger)instant;

/**
 * Gets the short name of this datetime zone suitable for display using
 * the default locale.
 * <p>
 * If the name is not available for the locale, then this method returns a
 * string in the format <code>[+-]hh:mm</code>.
 * 
 * @param instant  milliseconds from 1970-01-01T00:00:00Z to get the name for
 * @return the human-readable short name in the default locale
 */
- (NSString*)shortName:(NSInteger)instant;

/**
 * Gets the short name of this datetime zone suitable for display using
 * the specified locale.
 * <p>
 * If the name is not available for the locale, then this method returns a
 * string in the format <code>[+-]hh:mm</code>.
 * 
 * @param instant  milliseconds from 1970-01-01T00:00:00Z to get the name for
 * @param locale  the locale to get the name for
 * @return the human-readable short name in the specified locale
 */
- (NSString*)shortName:(NSInteger)instant 
                locale:(NSLocale*)locale;

/**
 * Gets the long name of this datetime zone suitable for display using
 * the default locale.
 * <p>
 * If the name is not available for the locale, then this method returns a
 * string in the format <code>[+-]hh:mm</code>.
 * 
 * @param instant  milliseconds from 1970-01-01T00:00:00Z to get the name for
 * @return the human-readable long name in the default locale
 */
- (NSString*)name:(NSInteger)instant;

/**
 * Gets the long name of this datetime zone suitable for display using
 * the specified locale.
 * <p>
 * If the name is not available for the locale, then this method returns a
 * string in the format <code>[+-]hh:mm</code>.
 * 
 * @param instant  milliseconds from 1970-01-01T00:00:00Z to get the name for
 * @param locale  the locale to get the name for
 * @return the human-readable long name in the specified locale
 */
- (NSString*)nameWithInstant:(NSInteger)instant 
                      locale:(NSLocale*)locale;

/**
 * Gets the millisecond offset to add to UTC to get local time.
 * 
 * @param instant  milliseconds from 1970-01-01T00:00:00Z to get the offset for
 * @return the millisecond offset to add to UTC to get local time
 */
- (NSInteger)offsetWithInstantValue:(NSInteger)instant;

/**
 * Gets the millisecond offset to add to UTC to get local time.
 * 
 * @param instant  instant to get the offset for, nil means now
 * @return the millisecond offset to add to UTC to get local time
 */
- (NSInteger)offsetWithInstant:(id<HLReadableInstant>)instant;

/**
 * Gets the standard millisecond offset to add to UTC to get local time,
 * when standard time is in effect.
 * 
 * @param instant  milliseconds from 1970-01-01T00:00:00Z to get the offset for
 * @return the millisecond offset to add to UTC to get local time
 */
- (NSInteger)standardOffsetWithInstantValue:(NSInteger)instant;

/**
 * Checks whether, at a particular instant, the offset is standard or not.
 * <p>
 * This method can be used to determine whether Summer Time (DST) applies.
 * As a general rule, if the offset at the specified instant is standard,
 * then either Winter time applies, or there is no Summer Time. If the
 * instant is not standard, then Summer Time applies.
 * <p>
 * The implementation of the method is simply whether {@link #getOffset(long)}
 * equals {@link #getStandardOffset(long)} at the specified instant.
 * 
 * @param instant  milliseconds from 1970-01-01T00:00:00Z to get the offset for
 * @return true if the offset at the given instant is the standard offset
 * @since 1.5
 */
- (BOOL)isStandardOffset:(NSInteger)instant;

/**
 * Gets the millisecond offset to subtract from local time to get UTC time.
 * This offset can be used to undo adding the offset obtained by getOffset.
 *
 * <pre>
 * millisLocal == millisUTC   + getOffset(millisUTC)
 * millisUTC   == millisLocal - getOffsetFromLocal(millisLocal)
 * </pre>
 *
 * NOTE: After calculating millisLocal, some error may be introduced. At
 * offset transitions (due to DST or other historical changes), ranges of
 * local times may map to different UTC times.
 * <p>
 * This method will return an offset suitable for calculating an instant
 * after any DST gap. For example, consider a zone with a cutover
 * from 01:00 to 01:59:<br />
 * Input: 00:00  Output: 00:00<br />
 * Input: 00:30  Output: 00:30<br />
 * Input: 01:00  Output: 02:00<br />
 * Input: 01:30  Output: 02:30<br />
 * Input: 02:00  Output: 02:00<br />
 * Input: 02:30  Output: 02:30<br />
 * <p>
 * NOTE: The behaviour of this method changed in v1.5, with the emphasis
 * on returning a consistent result later along the time-line (shown above).
 *
 * @param instantLocal  the millisecond instant, relative to this time zone, to
 * get the offset for
 * @return the millisecond offset to subtract from local time to get UTC time
 */
- (NSInteger)offsetFromLocal:(NSInteger)instantLocal;

/**
 * Converts a standard UTC instant to a local instant with the same
 * local time. This conversion is used before performing a calculation
 * so that the calculation can be done using a simple local zone.
 *
 * @param instantUTC  the UTC instant to convert to local
 * @return the local instant with the same local time
 * @throws ArithmeticException if the result overflows a long
 * @since 1.5
 */
- (NSInteger)convertUTCToLocal:(NSInteger)instantUTC;

/**
 * Converts a local instant to a standard UTC instant with the same
 * local time. This conversion is used after performing a calculation
 * where the calculation was done using a simple local zone.
 *
 * @param instantLocal  the local instant to convert to UTC
 * @param strict  whether the conversion should reject non-existent local times
 * @return the UTC instant with the same local time, 
 * @throws ArithmeticException if the result overflows a long
 * @throws IllegalArgumentException if the zone has no eqivalent local time
 * @since 1.5
 */
- (NSInteger)convertLocalToUTC:(NSInteger)instantLocal
                        strict:(BOOL)strict;

/**
 * Gets the millisecond instant in another zone keeping the same local time.
 * <p>
 * The conversion is performed by converting the specified UTC millis to local
 * millis in this zone, then converting back to UTC millis in the new zone.
 *
 * @param newZone  the new zone, nil means default
 * @param oldInstant  the UTC millisecond instant to convert
 * @return the UTC millisecond instant with the same local time in the new zone
 */
- (NSInteger)millisKeepLocal:(HLDateTimeZone*)newZone 
                  oldInstant:(NSInteger)oldInstant;

/**
 * Checks if the given {@link LocalDateTime} is within a gap.
 * <p>
 * When switching from standard time to Daylight Savings Time there is
 * typically a gap where a clock hour is missing. This method identifies
 * whether the local datetime refers to such a gap.
 * 
 * @param localDateTime  the time to check, not nil
 * @return true if the given datetime refers to a gap
 * @since 1.6
 */
- (BOOL)isLocalDateTimeGap:(HLLocalDateTime*)localDateTime;

//-----------------------------------------------------------------------
/**
 * Returns true if this time zone has no transitions.
 *
 * @return true if no transitions
 */
- (BOOL)isFixed;

/**
 * Advances the given instant to where the time zone offset or name changes.
 * If the instant returned is exactly the same as passed in, then
 * no changes occur after the given instant.
 *
 * @param instant  milliseconds from 1970-01-01T00:00:00Z
 * @return milliseconds from 1970-01-01T00:00:00Z
 */
- (NSInteger)nextTransition:(NSInteger)instant;

/**
 * Retreats the given instant to where the time zone offset or name changes.
 * If the instant returned is exactly the same as passed in, then
 * no changes occur before the given instant.
 *
 * @param instant  milliseconds from 1970-01-01T00:00:00Z
 * @return milliseconds from 1970-01-01T00:00:00Z
 */
- (NSInteger)previousTransition:(NSInteger)instant;

// Basic methods
//--------------------------------------------------------------------

/**
 * Get the datetime zone as a {@link java.util.TimeZone}.
 * 
 * @return the closest matching TimeZone object
 */
- (NSTimeZone*)toTimeZone;

/**
 * Compare this datetime zone with another.
 * 
 * @param object the object to compare with
 * @return true if equal, based on the ID and all internal rules
 */
- (BOOL)isEqualToObject:(id)object;

/**
 * By default, when DateTimeZones are serialized, only a "stub" object
 * referring to the id is written out. When the stub is read in, it
 * replaces itself with a DateTimeZone object.
 * @return a stub object to go in the stream
 */
- (id)writeReplace;

@end

