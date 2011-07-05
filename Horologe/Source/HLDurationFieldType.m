/*
 * DurationFieldType.m
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

#import "HLDurationFieldType.h"

#import "HLConstants.h"
#import "HLDateTimeUtils.h"


@class HLDurationFieldType;
@class HLStandardDurationFieldType;

/** The eras field type. */
HLDurationFieldType* ERAS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"eras"
                                                                                  ordinal:HL_DURATION_FIELD_TYPE_ERAS];
/** The centuries field type. */
static HLDurationFieldType* CENTURIES_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"centuries"
                                                                                       ordinal:HL_DURATION_FIELD_TYPE_CENTURIES];
/** The weekyears field type. */
static HLDurationFieldType* WEEKYEARS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"weekyears"
                                                                                       ordinal:HL_DURATION_FIELD_TYPE_WEEKYEARS];
/** The years field type. */
static HLDurationFieldType* YEARS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"years"
                                                                                   ordinal:HL_DURATION_FIELD_TYPE_YEARS];
/** The months field type. */
static HLDurationFieldType* MONTHS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"months"
                                                                                    ordinal:HL_DURATION_FIELD_TYPE_MONTHS];
/** The weeks field type. */
static HLDurationFieldType* WEEKS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"weeks"
                                                                                   ordinal:HL_DURATION_FIELD_TYPE_WEEKS];
/** The days field type. */
static HLDurationFieldType* DAYS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"days"
                                                                                  ordinal:HL_DURATION_FIELD_TYPE_DAYS];
/** The halfdays field type. */
static HLDurationFieldType* HALFDAYS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"halfdays"
                                                                                      ordinal:HL_DURATION_FIELD_TYPE_HALFDAYS];
/** The hours field type. */
static HLDurationFieldType* HOURS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"hours"
                                                                                   ordinal:HL_DURATION_FIELD_TYPE_HOURS];
/** The minutes field type. */
static HLDurationFieldType* MINUTES_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"minutes"
                                                                                     ordinal:HL_DURATION_FIELD_TYPE_MINUTES];
/** The seconds field type. */
static HLDurationFieldType* SECONDS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"seconds"
                                                                                     ordinal:HL_DURATION_FIELD_TYPE_SECONDS];
/** The millis field type. */
static HLDurationFieldType* MILLIS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"millis"
                                                                                    ordinal:HL_DURATION_FIELD_TYPE_MILLIS];

@implementation HLDurationFieldType

//-----------------------------------------------------------------------
- (id)initWithName:(NSString*)name {
    self = [super init];
    if(self) {
        _iName = [name copy];
    }
    
    return self;
}

//-----------------------------------------------------------------------
+ (HLDurationFieldType*)millis {
    return MILLIS_TYPE;
}

/**
 * Get the seconds field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (HLDurationFieldType*)seconds {
    return SECONDS_TYPE;
}

/**
 * Get the minutes field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (HLDurationFieldType*)minutes {
    return MINUTES_TYPE;
}

/**
 * Get the hours field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (HLDurationFieldType*)hours {
    return HOURS_TYPE;
}

/**
 * Get the halfdays field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (HLDurationFieldType*)halfdays {
    return HALFDAYS_TYPE;
}

//-----------------------------------------------------------------------
/**
 * Get the days field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (HLDurationFieldType*)days {
    return DAYS_TYPE;
}

/**
 * Get the weeks field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (HLDurationFieldType*)weeks {
    return WEEKS_TYPE;
}

/**
 * Get the weekyears field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (HLDurationFieldType*)weekyears {
    return WEEKYEARS_TYPE;
}

/**
 * Get the months field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (HLDurationFieldType*)months {
    return MONTHS_TYPE;
}

/**
 * Get the years field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (HLDurationFieldType*)years {
    return YEARS_TYPE;
}

/**
 * Get the centuries field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (HLDurationFieldType*)centuries {
    return CENTURIES_TYPE;
}

/**
 * Get the eras field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (HLDurationFieldType*)eras {
    return ERAS_TYPE;
}

//-----------------------------------------------------------------------
/**
 * Get the name of the field.
 * By convention, names are plural.
 * 
 * @return field name
 */
- (NSString*)name {
    return _iName;
}

/**
 * Gets a suitable field for this type from the given Chronology.
 *
 * @param chronology  the chronology to use, nil means ISOChronology in default zone
 * @return a suitable field
 */
- (HLDurationField*)fieldWithChronology:(HLChronology*)chronology {
    [NSException raise:HL_UNIMPLEMENTED_EXCEPTION
                format:@"%s must be implemented by subclass", _cmd];
}

/**
 * Checks whether this field supported in the given Chronology.
 *
 * @param chronology  the chronology to use, nil means ISOChronology in default zone
 * @return true if supported
 */
- (BOOL)isSupported:(HLChronology*)chronology {
    return [[self fieldWithChronology:chronology] isSupported];
}

/**
 * Get a suitable debug string.
 * 
 * @return debug string
 */
- (NSString*)description {
    return _iName;
}

@end


@implementation HLStandardDurationFieldType 

/**
 * Constructor.
 * 
 * @param name  the name to use
 */
- (id)initWithName:(NSString*)name
            ordinal:(NSInteger)ordinal {
    self = [super initWithName:name];
    if(self) {
        _iOrdinal = ordinal;
    }
    
    return self;
}

- (HLDurationField*)fieldWithChronology:(HLChronology*)chronology {
    
    chronology = [HLDateTimeUtils chronology:chronology];
    
    switch (_iOrdinal) {
        case HL_DURATION_FIELD_TYPE_ERAS:
            return chronology.eras();
        case HL_DURATION_FIELD_TYPE_CENTURIES:
            return chronology.centuries();
        case HL_DURATION_FIELD_TYPE_WEEKYEARS:
            return chronology.weekyears();
        case HL_DURATION_FIELD_TYPE_YEARS:
            return chronology.years();
        case HL_DURATION_FIELD_TYPE_MONTHS:
            return chronology.months();
        case HL_DURATION_FIELD_TYPE_WEEKS:
            return chronology.weeks();
        case HL_DURATION_FIELD_TYPE_DAYS:
            return chronology.days();
        case HL_DURATION_FIELD_TYPE_HALFDAYS:
            return chronology.halfdays();
        case HL_DURATION_FIELD_TYPE_HOURS:
            return chronology.hours();
        case HL_DURATION_FIELD_TYPE_MINUTES:
            return chronology.minutes();
        case HL_DURATION_FIELD_TYPE_SECONDS:
            return chronology.seconds();
        case HL_DURATION_FIELD_TYPE_MILLIS:
            return chronology.millis();
        default:
            // Shouldn't happen.
            [NSException raise:HL_INTERNAL_ERROR
                        format:@"Internal error: unknown ordinal type"];
    }
}

/**
 * Ensure a singleton is returned.
 * 
 * @return the singleton type
 */
- (id)_readResolve {
    switch (_iOrdinal) {
        case HL_DURATION_FIELD_TYPE_ERAS:
            return ERAS_TYPE;
        case HL_DURATION_FIELD_TYPE_CENTURIES:
            return CENTURIES_TYPE;
        case HL_DURATION_FIELD_TYPE_WEEKYEARS:
            return WEEKYEARS_TYPE;
        case HL_DURATION_FIELD_TYPE_YEARS:
            return YEARS_TYPE;
        case HL_DURATION_FIELD_TYPE_MONTHS:
            return MONTHS_TYPE;
        case HL_DURATION_FIELD_TYPE_WEEKS:
            return WEEKS_TYPE;
        case HL_DURATION_FIELD_TYPE_DAYS:
            return DAYS_TYPE;
        case HL_DURATION_FIELD_TYPE_HALFDAYS:
            return HALFDAYS_TYPE;
        case HL_DURATION_FIELD_TYPE_HOURS:
            return HOURS_TYPE;
        case HL_DURATION_FIELD_TYPE_MINUTES:
            return MINUTES_TYPE;
        case HL_DURATION_FIELD_TYPE_SECONDS:
            return SECONDS_TYPE;
        case HL_DURATION_FIELD_TYPE_MILLIS:
            return MILLIS_TYPE;
        default:
            // Shouldn't happen.
            return self;
    }
}

@end
