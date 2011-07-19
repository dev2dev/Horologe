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
const HLDurationFieldType* HL_DURATION_FIELD_ERAS_TYPE;
/** The centuries field type. */
const HLDurationFieldType* HL_DURATION_FIELD_CENTURIES_TYPE;
/** The weekyears field type. */
const HLDurationFieldType* HL_DURATION_FIELD_WEEKYEARS_TYPE;
/** The years field type. */
const HLDurationFieldType* HL_DURATION_FIELD_YEARS_TYPE;
/** The months field type. */
const HLDurationFieldType* HL_DURATION_FIELD_MONTHS_TYPE;
/** The weeks field type. */
const HLDurationFieldType* HL_DURATION_FIELD_WEEKS_TYPE;
/** The days field type. */
const HLDurationFieldType* HL_DURATION_FIELD_DAYS_TYPE;
/** The halfdays field type. */
const HLDurationFieldType* HL_DURATION_FIELD_HALFDAYS_TYPE;
/** The hours field type. */
const HLDurationFieldType* HL_DURATION_FIELD_HOURS_TYPE;
/** The minutes field type. */
const HLDurationFieldType* HL_DURATION_FIELD_MINUTES_TYPE;
/** The seconds field type. */
const HLDurationFieldType* HL_DURATION_FIELD_SECONDS_TYPE;
/** The millis field type. */
const HLDurationFieldType* HL_DURATION_FIELD_MILLIS_TYPE;

@implementation HLDurationFieldType

+ (void)initialize {
    
     HL_DURATION_FIELD_ERAS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"eras"
                                                                                                              ordinal:HL_DURATION_FIELD_TYPE_ERAS];
     HL_DURATION_FIELD_CENTURIES_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"centuries"
                                                                                                             ordinal:HL_DURATION_FIELD_TYPE_CENTURIES];
     HL_DURATION_FIELD_WEEKYEARS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"weekyears"
                                                                                                             ordinal:HL_DURATION_FIELD_TYPE_WEEKYEARS];
     HL_DURATION_FIELD_YEARS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"years"
                                                                                                         ordinal:HL_DURATION_FIELD_TYPE_YEARS];
     HL_DURATION_FIELD_MONTHS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"months"
                                                                                                          ordinal:HL_DURATION_FIELD_TYPE_MONTHS];
    HL_DURATION_FIELD_WEEKS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"weeks"
                                                                                                         ordinal:HL_DURATION_FIELD_TYPE_WEEKS];
     HL_DURATION_FIELD_DAYS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"days"
                                                                                                        ordinal:HL_DURATION_FIELD_TYPE_DAYS];
    HL_DURATION_FIELD_HALFDAYS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"halfdays"
                                                                                                            ordinal:HL_DURATION_FIELD_TYPE_HALFDAYS];
    HL_DURATION_FIELD_HOURS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"hours"
                                                                                                         ordinal:HL_DURATION_FIELD_TYPE_HOURS];
    HL_DURATION_FIELD_MINUTES_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"minutes"
                                                                                                           ordinal:HL_DURATION_FIELD_TYPE_MINUTES];
    HL_DURATION_FIELD_SECONDS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"seconds"
                                                                                                           ordinal:HL_DURATION_FIELD_TYPE_SECONDS];
    HL_DURATION_FIELD_MILLIS_TYPE = [[HLStandardDurationFieldType alloc] initWithName:@"millis"
                                                                                                          ordinal:HL_DURATION_FIELD_TYPE_MILLIS];
}

//-----------------------------------------------------------------------
- (id)initWithName:(NSString*)name {
    self = [super init];
    if(self) {
        _iName = [name copy];
    }
    
    return self;
}

//-----------------------------------------------------------------------
+ (const HLDurationFieldType*)millis {
    return HL_DURATION_FIELD_MILLIS_TYPE;
}

/**
 * Get the seconds field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (const HLDurationFieldType*)seconds {
    return HL_DURATION_FIELD_SECONDS_TYPE;
}

/**
 * Get the minutes field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (const HLDurationFieldType*)minutes {
    return HL_DURATION_FIELD_MINUTES_TYPE;
}

/**
 * Get the hours field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (const HLDurationFieldType*)hours {
    return HL_DURATION_FIELD_HOURS_TYPE;
}

/**
 * Get the halfdays field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (const HLDurationFieldType*)halfdays {
    return HL_DURATION_FIELD_HALFDAYS_TYPE;
}

//-----------------------------------------------------------------------
/**
 * Get the days field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (const HLDurationFieldType*)days {
    return HL_DURATION_FIELD_DAYS_TYPE;
}

/**
 * Get the weeks field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (const HLDurationFieldType*)weeks {
    return HL_DURATION_FIELD_WEEKS_TYPE;
}

/**
 * Get the weekyears field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (const HLDurationFieldType*)weekyears {
    return HL_DURATION_FIELD_WEEKYEARS_TYPE;
}

/**
 * Get the months field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (const HLDurationFieldType*)months {
    return HL_DURATION_FIELD_MONTHS_TYPE;
}

/**
 * Get the years field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (const HLDurationFieldType*)years {
    return HL_DURATION_FIELD_YEARS_TYPE;
}

/**
 * Get the centuries field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (const HLDurationFieldType*)centuries {
    return HL_DURATION_FIELD_CENTURIES_TYPE;
}

/**
 * Get the eras field type.
 * 
 * @return the DateTimeFieldType constant
 */
- (const HLDurationFieldType*)eras {
    return HL_DURATION_FIELD_ERAS_TYPE;
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
- (id)readResolve {
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
