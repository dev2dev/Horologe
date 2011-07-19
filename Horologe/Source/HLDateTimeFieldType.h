/*
 * DateTimeFieldType.h
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


@class HLDurationFieldType;
@class HLDateTimeField;
@class HLChronology;

typedef enum _HLStandardFieldType {
    ERA = 1,
    YEAR_OF_ERA = 2,
    CENTURY_OF_ERA = 3,
    YEAR_OF_CENTURY = 4,
    YEAR = 5,
    DAY_OF_YEAR = 6,
    MONTH_OF_YEAR = 7,
    DAY_OF_MONTH = 8,
    WEEKYEAR_OF_CENTURY = 9,
    WEEKYEAR = 10,
    WEEK_OF_WEEKYEAR = 11,
    DAY_OF_WEEK = 12,
    HALFDAY_OF_DAY = 13,
    HOUR_OF_HALFDAY = 14,
    CLOCKHOUR_OF_HALFDAY = 15,
    CLOCKHOUR_OF_DAY = 16,
    HOUR_OF_DAY = 17,
    MINUTE_OF_DAY = 18,
    MINUTE_OF_HOUR = 19,
    SECOND_OF_DAY = 20,
    SECOND_OF_MINUTE = 21,
    MILLIS_OF_DAY = 22,
    MILLIS_OF_SECOND = 23,            
} HLStandardFieldType;

/**
 * Identifies a field, such as year or minuteOfHour, in a chronology-neutral way.
 * <p>
 * A field type defines the type of the field, such as hourOfDay.
 * If does not directly enable any calculations, however it does provide a
 * {@link #getField(Chronology)} method that returns the actual calculation engine
 * for a particular chronology.
 * It also provides access to the related {@link DurationFieldType}s.
 * <p>
 * Instances of <code>DateTimeFieldType</code> are singletons.
 * They can be compared using <code>==</code>.
 * <p>
 * If required, you can create your own field, for example a quarterOfYear.
 * You must create a subclass of <code>DateTimeFieldType</code> that defines the field type.
 * This class returns the actual calculation engine from {@link #getField(Chronology)}.
 *
 * @author Stephen Colebourne
 * @author Brian S O'Neill
 * @since 1.0
 */
@interface HLDateTimeFieldType : NSObject {
    
@private
    /** The name of the field. */
    NSString* _iName;
    
}

//-----------------------------------------------------------------------
/**
 * Constructor.
 * 
 * @param name  the name to use
 */
- (id)initWithName:(NSString*)name;

//-----------------------------------------------------------------------
/**
 * Get the millis of second field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)millisOfSecond;

/**
 * Get the millis of day field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)millisOfDay;

/**
 * Get the second of minute field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)secondOfMinute;

/**
 * Get the second of day field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)secondOfDay;

/**
 * Get the minute of hour field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)minuteOfHour;

/**
 * Get the minute of day field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)minuteOfDay;

/**
 * Get the hour of day (0-23) field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)hourOfDay;

/**
 * Get the hour of day (offset to 1-24) field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)clockhourOfDay;

/**
 * Get the hour of am/pm (0-11) field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)hourOfHalfday;

/**
 * Get the hour of am/pm (offset to 1-12) field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)clockhourOfHalfday;

/**
 * Get the AM(0) PM(1) field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)halfdayOfDay;

//-----------------------------------------------------------------------
/**
 * Get the day of week field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)dayOfWeek;

/**
 * Get the day of month field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)dayOfMonth;

/**
 * Get the day of year field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)dayOfYear;

/**
 * Get the week of a week based year field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)weekOfWeekyear;

/**
 * Get the year of a week based year field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)weekyear;

/**
 * Get the year of a week based year within a century field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)weekyearOfCentury;

/**
 * Get the month of year field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)monthOfYear;

/**
 * Get the year field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)year;

/**
 * Get the year of era field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)yearOfEra;

/**
 * Get the year of century field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)yearOfCentury;

/**
 * Get the century of era field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)centuryOfEra;

/**
 * Get the era field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)era;

//-----------------------------------------------------------------------
/**
 * Get the name of the field.
 * <p>
 * By convention, names follow a pattern of "dddOfRrr", where "ddd" represents
 * the (singular) duration unit field name and "Rrr" represents the (singular)
 * duration range field name. If the range field is not applicable, then
 * the name of the field is simply the (singular) duration field name.
 * 
 * @return field name
 */
- (NSString*)name;

/**
 * Get the duration unit of the field.
 * 
 * @return duration unit of the field, never nil
 */
- (HLDurationFieldType*)durationType;

/**
 * Get the duration range of the field.
 * 
 * @return duration range of the field, nil if unbounded
 */
- (HLDurationFieldType*)rangeDurationType;

/**
 * Gets a suitable field for this type from the given Chronology.
 *
 * @param chronology  the chronology to use, nil means ISOChronology in default zone
 * @return a suitable field
 */
- (HLDateTimeField*)field:(HLChronology*)chronology;

/**
 * Checks whether this field supported in the given Chronology.
 *
 * @param chronology  the chronology to use, nil means ISOChronology in default zone
 * @return true if supported
 */
- (BOOL)isSupported:(HLChronology*)chronology;

@end


@interface HLStandardDateTimeFieldType : HLDateTimeFieldType {
    
@private
    /** The ordinal of the standard field type, for switch statements */
    NSInteger _iOrdinal;
    
    /** The unit duration of the field. */
    HLDurationFieldType* _iUnitType;
    /** The range duration of the field. */
    HLDurationFieldType* _iRangeType;
    
}

/**
 * Constructor.
 * 
 * @param name  the name to use
 * @param ordinal  the byte value for the oridinal index
 * @param unitType  the unit duration type
 * @param rangeType  the range duration type
 */
- (id)initWithName:(NSString*)name
           ordinal:(NSInteger)ordinal
          unitType:(HLDurationFieldType*)unitType
         rangeType:(HLDurationFieldType*)rangeType;

/** @inheritdoc */
- (HLDurationFieldType*)durationType;

/** @inheritdoc */
- (HLDurationFieldType*)rangeDurationType;

/** @inheritdoc */
- (HLDateTimeField*)field:(HLChronology*)chronology;

@end
