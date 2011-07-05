/*
 * DurationFieldType.h
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
@class HLDurationField;
@class HLDurationFieldType;

#define HL_DURATION_FIELD_TYPE_ERAS (1)
#define HL_DURATION_FIELD_TYPE_CENTURIES (2)
#define HL_DURATION_FIELD_TYPE_WEEKYEARS (3)
#define HL_DURATION_FIELD_TYPE_YEARS (4)
#define HL_DURATION_FIELD_TYPE_MONTHS (5)
#define HL_DURATION_FIELD_TYPE_WEEKS (6)
#define HL_DURATION_FIELD_TYPE_DAYS (7)
#define HL_DURATION_FIELD_TYPE_HALFDAYS (8)
#define HL_DURATION_FIELD_TYPE_HOURS (9)
#define HL_DURATION_FIELD_TYPE_MINUTES (10)
#define HL_DURATION_FIELD_TYPE_SECONDS (11)
#define HL_DURATION_FIELD_TYPE_MILLIS (12)

/** The eras field type. */
extern HLDurationFieldType* ERAS_TYPE;
/** The centuries field type. */
extern HLDurationFieldType* CENTURIES_TYPE;
/** The weekyears field type. */
extern HLDurationFieldType* WEEKYEARS_TYPE;
/** The years field type. */
extern HLDurationFieldType* YEARS_TYPE;
/** The months field type. */
extern HLDurationFieldType* MONTHS_TYPE;
/** The weeks field type. */
extern HLDurationFieldType* WEEKS_TYPE;
/** The days field type. */
extern HLDurationFieldType* DAYS_TYPE;
/** The halfdays field type. */
extern HLDurationFieldType* HALFDAYS_TYPE;
/** The hours field type. */
extern HLDurationFieldType* HOURS_TYPE;
/** The minutes field type. */
extern HLDurationFieldType* MINUTES_TYPE;
/** The seconds field type. */
extern HLDurationFieldType* SECONDS_TYPE;
/** The millis field type. */
extern HLDurationFieldType* MILLIS_TYPE;

/**
 * Identifies a duration field, such as years or minutes, in a chronology-neutral way.
 * <p>
 * A duration field type defines the type of the field, such as hours.
 * If does not directly enable any calculations, however it does provide a
 * {@link #getField(Chronology)} method that returns the actual calculation engine
 * for a particular chronology.
 * <p>
 * Instances of <code>DurationFieldType</code> are singletons.
 * They can be compared using <code>==</code>.
 * <p>
 * If required, you can create your own field, for example a quarters.
 * You must create a subclass of <code>DurationFieldType</code> that defines the field type.
 * This class returns the actual calculation engine from {@link #getField(Chronology)}.
 *
 * @author Stephen Colebourne
 * @author Brian S O'Neill
 * @since 1.0
 */
@interface HLDurationFieldType : NSObject {
    
@private
    /** The name of the field type. */
    NSString* _iName;
    
}

//-----------------------------------------------------------------------
/**
 * Constructor.
 * 
 * @param name  the name to use, which by convention, are plural.
 */
- (id)initWithName:(NSString*)name;

//-----------------------------------------------------------------------
/**
 * Get the millis field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDurationFieldType*)millis;

/**
 * Get the seconds field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDurationFieldType*)seconds;

/**
 * Get the minutes field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDurationFieldType*)minutes;

/**
 * Get the hours field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDurationFieldType*)hours;

/**
 * Get the halfdays field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDurationFieldType*)halfdays;

//-----------------------------------------------------------------------
/**
 * Get the days field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDurationFieldType*)days;

/**
 * Get the weeks field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDurationFieldType*)weeks;

/**
 * Get the weekyears field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDurationFieldType*)weekyears;

/**
 * Get the months field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDurationFieldType*)months;

/**
 * Get the years field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDurationFieldType*)years;

/**
 * Get the centuries field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDurationFieldType*)centuries;

/**
 * Get the eras field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDurationFieldType*)eras;

//-----------------------------------------------------------------------
/**
 * Get the name of the field.
 * By convention, names are plural.
 * 
 * @return field name
 */
- (NSString*)name;

/**
 * Gets a suitable field for this type from the given Chronology.
 *
 * @param chronology  the chronology to use, nil means ISOChronology in default zone
 * @return a suitable field
 */
- (HLDurationField*)fieldWithChronology:(HLChronology*)chronology;

/**
 * Checks whether this field supported in the given Chronology.
 *
 * @param chronology  the chronology to use, nil means ISOChronology in default zone
 * @return true if supported
 */
- (BOOL)isSupported:(HLChronology*)chronology;

/**
 * Get a suitable debug string.
 * 
 * @return debug string
 */
- (NSString*)description;

@end


@interface HLStandardDurationFieldType : HLDurationFieldType {
    
@private
    /** The ordinal of the standard field type, for switch statements */
NSInteger _iOrdinal;
    
}

/**
 * Constructor.
 * 
 * @param name  the name to use
 */
- (id)initWithName:(NSString*)name
           ordinal:(NSInteger)ordinal;

- (HLDurationField*)fieldWithChronology:(HLChronology*)chronology;

/**
 * Ensure a singleton is returned.
 * 
 * @return the singleton type
 */
- (id)_readResolve;

@end
