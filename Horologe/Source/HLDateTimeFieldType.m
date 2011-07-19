/*
 * DateTimeFieldType.m
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

#import "HLDateTimeFieldType.h"

#import "HLChronology.h"
#import "HLDateTimeField.h"
#import "HLDurationFieldType.h"

#import "HLConstants.h"
#import "HLDateTimeUtils.h"


@implementation HLDateTimeFieldType

//-----------------------------------------------------------------------
- (id)initWithName:(NSString*)name {
    self = [super init];
    if(self) {
        _iName = [name copy];
    }
    
    return self;
}

//-----------------------------------------------------------------------
/**
 * Get the millis of second field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)millisOfSecond {
    static HLStandardDateTimeFieldType* MILLIS_OF_SECOND_TYPE = nil;
    
    if(MILLIS_OF_SECOND_TYPE == nil) {
        MILLIS_OF_SECOND_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"millisOfSecond" 
                                                                          ordinal:MILLIS_OF_SECOND
                                                                         unitType:[HLDurationFieldType millis]
                                                                        rangeType:[HLDurationFieldType seconds]];
    }
    
    return MILLIS_OF_SECOND_TYPE;
}

/**
 * Get the millis of day field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)millisOfDay {
    static HLStandardDateTimeFieldType* MILLIS_OF_DAY_TYPE = nil;
    
    if(MILLIS_OF_DAY_TYPE == nil) {
        MILLIS_OF_DAY_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"millisOfDay" 
                                                                       ordinal:MILLIS_OF_DAY
                                                                      unitType:[HLDurationFieldType millis]
                                                                     rangeType:[HLDurationFieldType days]];
    }
    
    return MILLIS_OF_DAY_TYPE;
}

/**
 * Get the second of minute field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)secondOfMinute {
    static HLStandardDateTimeFieldType* SECOND_OF_MINUTE_TYPE = nil;
    
    if(SECOND_OF_MINUTE_TYPE == nil) {
        SECOND_OF_MINUTE_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"secondOfMinute" 
                                                                          ordinal:SECOND_OF_MINUTE
                                                                         unitType:[HLDurationFieldType seconds]
                                                                        rangeType:[HLDurationFieldType minutes]];
    }
    
    return SECOND_OF_MINUTE_TYPE;
}

/**
 * Get the second of day field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)secondOfDay {
    static HLStandardDateTimeFieldType* SECOND_OF_DAY_TYPE = nil;
    
    if(SECOND_OF_DAY_TYPE == nil) {
        SECOND_OF_DAY_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"secondOfDay" 
                                                                       ordinal:SECOND_OF_DAY
                                                                      unitType:[HLDurationFieldType seconds]
                                                                     rangeType:[HLDurationFieldType days]];
    }
    
    return SECOND_OF_DAY_TYPE;
}

/**
 * Get the minute of hour field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)minuteOfHour {
    static HLStandardDateTimeFieldType* MINUTE_OF_HOUR_TYPE = nil;
    
    if(MINUTE_OF_HOUR_TYPE == nil) {
        MINUTE_OF_HOUR_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"minuteOfHour" 
                                                                        ordinal:MINUTE_OF_HOUR
                                                                       unitType:[HLDurationFieldType minutes]
                                                                      rangeType:[HLDurationFieldType hours]];
    }
    
    return MINUTE_OF_HOUR_TYPE;
}

/**
 * Get the minute of day field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)minuteOfDay {
    static HLStandardDateTimeFieldType* MINUTE_OF_DAY_TYPE = nil;
    
    if(MINUTE_OF_DAY_TYPE == nil) {
        MINUTE_OF_DAY_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"minuteOfDay" 
                                                                       ordinal:MINUTE_OF_DAY 
                                                                      unitType:[HLDurationFieldType minutes]
                                                                     rangeType:[HLDurationFieldType days]];
    }
    
    return MINUTE_OF_DAY_TYPE;
}

/**
 * Get the hour of day (0-23) field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)hourOfDay {
    static HLStandardDateTimeFieldType* HOUR_OF_DAY_TYPE = nil;
    
    if(HOUR_OF_DAY_TYPE == nil) {
        HOUR_OF_DAY_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"hourOfDay" 
                                                                     ordinal:HOUR_OF_DAY 
                                                                    unitType:[HLDurationFieldType hours]
                                                                   rangeType:[HLDurationFieldType days]];
    }
    
    return HOUR_OF_DAY_TYPE;
}

/**
 * Get the hour of day (offset to 1-24) field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)clockhourOfDay {
    static HLStandardDateTimeFieldType* CLOCKHOUR_OF_DAY_TYPE = nil;
    
    if(CLOCKHOUR_OF_DAY_TYPE == nil) {
        CLOCKHOUR_OF_DAY_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"clockhourOfDay" 
                                                                          ordinal:CLOCKHOUR_OF_DAY 
                                                                         unitType:[HLDurationFieldType hours]
                                                                        rangeType:[HLDurationFieldType days]];
    }
    
    return CLOCKHOUR_OF_DAY_TYPE;
}

/**
 * Get the hour of am/pm (0-11) field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)hourOfHalfday {
    static HLStandardDateTimeFieldType* HOUR_OF_HALFDAY_TYPE = nil;
    
    if(HOUR_OF_HALFDAY_TYPE == nil) {
        HOUR_OF_HALFDAY_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"hourOfHalfday" 
                                                                         ordinal:HOUR_OF_HALFDAY 
                                                                        unitType:[HLDurationFieldType hours]
                                                                       rangeType:[HLDurationFieldType halfdays]];
    }
    
    return HOUR_OF_HALFDAY_TYPE;
}

/**
 * Get the hour of am/pm (offset to 1-12) field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)clockhourOfHalfday {
    static HLStandardDateTimeFieldType* CLOCKHOUR_OF_HALFDAY_TYPE = nil;
    
    if(CLOCKHOUR_OF_HALFDAY_TYPE == nil) {
        CLOCKHOUR_OF_HALFDAY_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"clockhourOfHalfday" 
                                                                              ordinal:CLOCKHOUR_OF_HALFDAY 
                                                                             unitType:[HLDurationFieldType hours]
                                                                            rangeType:[HLDurationFieldType halfdays]];
    }
    
    return CLOCKHOUR_OF_HALFDAY_TYPE;
}

/**
 * Get the AM(0) PM(1) field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)halfdayOfDay {
    static HLStandardDateTimeFieldType* HALFDAY_OF_DAY_TYPE = nil;
    
    if(HALFDAY_OF_DAY_TYPE == nil) {
        HALFDAY_OF_DAY_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"halfdayOfDay" 
                                                                        ordinal:HALFDAY_OF_DAY 
                                                                       unitType:[HLDurationFieldType halfdays]
                                                                      rangeType:[HLDurationFieldType days]];
    }
    
    return HALFDAY_OF_DAY_TYPE;
}

//-----------------------------------------------------------------------
/**
 * Get the day of week field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)dayOfWeek {
    static HLStandardDateTimeFieldType* DAY_OF_WEEK_TYPE = nil;
    
    if(DAY_OF_WEEK_TYPE == nil) {
        DAY_OF_WEEK_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"dayOfWeek" 
                                                                     ordinal:DAY_OF_WEEK 
                                                                    unitType:[HLDurationFieldType days]
                                                                   rangeType:[HLDurationFieldType weeks]];
    }
    
    return DAY_OF_WEEK_TYPE;
}

/**
 * Get the day of month field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)dayOfMonth {
    static HLStandardDateTimeFieldType* DAY_OF_MONTH_TYPE = nil;
    
    if(DAY_OF_MONTH_TYPE == nil) {
        DAY_OF_MONTH_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"dayOfMonth" 
                                                                      ordinal:DAY_OF_MONTH 
                                                                     unitType:[HLDurationFieldType days]
                                                                    rangeType:[HLDurationFieldType months]];
    }
    
    return DAY_OF_MONTH_TYPE;
}

/**
 * Get the day of year field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)dayOfYear {
    static HLStandardDateTimeFieldType* DAY_OF_YEAR_TYPE = nil;
    
    if(DAY_OF_YEAR_TYPE == nil) {
        DAY_OF_YEAR_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"dayOfYear" 
                                                                     ordinal:DAY_OF_YEAR 
                                                                    unitType:[HLDurationFieldType days]
                                                                   rangeType:[HLDurationFieldType years]];
    }
    
    return DAY_OF_YEAR_TYPE;
}

/**
 * Get the week of a week based year field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)weekOfWeekyear {
    static HLStandardDateTimeFieldType* WEEK_OF_WEEKYEAR_TYPE = nil;
    
    if(WEEK_OF_WEEKYEAR_TYPE == nil) {
        WEEK_OF_WEEKYEAR_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"weekOfWeekyear" 
                                                                          ordinal:WEEK_OF_WEEKYEAR
                                                                         unitType:[HLDurationFieldType weeks]
                                                                        rangeType:[HLDurationFieldType weekyears]];
    }
    
    return WEEK_OF_WEEKYEAR_TYPE;
}

/**
 * Get the year of a week based year field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)weekyear {
    static HLStandardDateTimeFieldType* WEEKYEAR_TYPE = nil;
    
    if(WEEKYEAR_TYPE == nil) {
        WEEKYEAR_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"weekyear" 
                                                                  ordinal:WEEKYEAR 
                                                                 unitType:[HLDurationFieldType weekyears]
                                                                rangeType:nil];
    }
    
    return WEEKYEAR_TYPE;
}

/**
 * Get the year of a week based year within a century field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)weekyearOfCentury {
    static HLStandardDateTimeFieldType* WEEKYEAR_OF_CENTURY_TYPE = nil;
    
    if(WEEKYEAR_OF_CENTURY_TYPE == nil) {
        WEEKYEAR_OF_CENTURY_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"weekyearOfCentury" 
                                                                             ordinal:WEEKYEAR_OF_CENTURY 
                                                                            unitType:[HLDurationFieldType weekyears]
                                                                           rangeType:[HLDurationFieldType centuries]];
    }
    
    return WEEKYEAR_OF_CENTURY_TYPE;
}

/**
 * Get the month of year field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)monthOfYear {
    static HLStandardDateTimeFieldType* MONTH_OF_YEAR_TYPE = nil;
    
    if(MONTH_OF_YEAR_TYPE == nil) {
        MONTH_OF_YEAR_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"monthOfYear" 
                                                                       ordinal:MONTH_OF_YEAR 
                                                                      unitType:[HLDurationFieldType months]
                                                                     rangeType:[HLDurationFieldType years]];
    }
    
    return MONTH_OF_YEAR_TYPE;
}

/**
 * Get the year field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)year {
    static HLStandardDateTimeFieldType* YEAR_TYPE = nil;
    
    if(YEAR_TYPE == nil) {
        YEAR_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"year" 
                                                              ordinal:YEAR
                                                             unitType:[HLDurationFieldType years]
                                                            rangeType:nil];
    }
    
    return YEAR_TYPE;
}

/**
 * Get the year of era field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)yearOfEra {
    static HLStandardDateTimeFieldType* YEAR_OF_ERA_TYPE = nil;
    
    if(YEAR_OF_ERA_TYPE == nil) {
        YEAR_OF_ERA_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"yearOfEra" 
                                                                     ordinal:YEAR_OF_ERA
                                                                    unitType:[HLDurationFieldType years]
                                                                   rangeType:[HLDurationFieldType eras]];
    }
    
    return YEAR_OF_ERA_TYPE;
}

/**
 * Get the year of century field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)yearOfCentury {
    static HLStandardDateTimeFieldType* YEAR_OF_CENTURY_TYPE = nil;
    
    if(YEAR_OF_CENTURY_TYPE == nil) {
        YEAR_OF_CENTURY_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"centuryOfEra" 
                                                                         ordinal:CENTURY_OF_ERA
                                                                        unitType:[HLDurationFieldType years]
                                                                       rangeType:[HLDurationFieldType centuries]];
    }
    
    return YEAR_OF_CENTURY_TYPE;
}

/**
 * Get the century of era field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)centuryOfEra {
    static HLStandardDateTimeFieldType* CENTURY_OF_ERA_TYPE = nil;
    
    if(CENTURY_OF_ERA_TYPE == nil) {
        CENTURY_OF_ERA_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"centuryOfEra" 
                                                                        ordinal:CENTURY_OF_ERA
                                                                       unitType:[HLDurationFieldType centuries]
                                                                      rangeType:[HLDurationFieldType eras]];
    }
    
    return CENTURY_OF_ERA_TYPE;
}

/**
 * Get the era field type.
 * 
 * @return the DateTimeFieldType constant
 */
+ (HLDateTimeFieldType*)era {
    // internal constants
    static HLStandardDateTimeFieldType* ERA_TYPE = nil;
    
    if(ERA_TYPE == nil) {
        ERA_TYPE = [[HLStandardDateTimeFieldType alloc] initWithName:@"era" 
                                                             ordinal:ERA
                                                            unitType:[HLDurationFieldType eras]
                                                           rangeType:nil];
    }
    
    return ERA_TYPE;
}

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
- (NSString*)name {
    return _iName;
}

/**
 * Get the duration unit of the field.
 * 
 * @return duration unit of the field, never nil
 */
- (HLDurationFieldType*)durationType {
    [NSException raise:HL_UNIMPLEMENTED_EXCEPTION
                format:@"Method %s must be implemented by sub-class!", _cmd];
}

/**
 * Get the duration range of the field.
 * 
 * @return duration range of the field, nil if unbounded
 */
- (HLDurationFieldType*)rangeDurationType {
    [NSException raise:HL_UNIMPLEMENTED_EXCEPTION
                format:@"Method %s must be implemented by sub-class!", _cmd];
}

/**
 * Gets a suitable field for this type from the given Chronology.
 *
 * @param chronology  the chronology to use, nil means ISOChronology in default zone
 * @return a suitable field
 */
- (HLDateTimeField*)field:(HLChronology*)chronology {
    [NSException raise:HL_UNIMPLEMENTED_EXCEPTION
                format:@"Method %s must be implemented by sub-class!", _cmd];
}

/**
 * Checks whether this field supported in the given Chronology.
 *
 * @param chronology  the chronology to use, nil means ISOChronology in default zone
 * @return true if supported
 */
- (BOOL)isSupported:(HLChronology*)chronology {
    return [[self field:chronology] isSupported];
}

/**
 * Get a suitable debug string.
 * 
 * @return debug string
 */
- (NSString*)description {
    return [self name];
}
@end


@implementation HLStandardDateTimeFieldType 

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
         rangeType:(HLDurationFieldType*)rangeType {
    
    self = [super initWithName:name];
    if(self) {
        _iOrdinal = ordinal;
        _iUnitType = [unitType retain];
        _iRangeType = [rangeType retain];
    }
    
    return self;
}

/** @inheritdoc */
- (HLDurationFieldType*)durationType {
    return _iUnitType;
}

/** @inheritdoc */
- (HLDurationFieldType*)rangeDurationType {
    return _iRangeType;
}

/** @inheritdoc */
- (HLDateTimeField*)field:(HLChronology*)chronology) {
    chronology = [HLDateTimeUtils chronology:chronology];
    
    switch (_iOrdinal) {
        case ERA:
            return [chronology era];
        case YEAR_OF_ERA:
            return [chronology yearOfEra];
        case CENTURY_OF_ERA:
            return [chronology centuryOfEra];
        case YEAR_OF_CENTURY:
            return [chronology yearOfCentury];
        case YEAR:
            return [chronology year];
        case DAY_OF_YEAR:
            return [chronology dayOfYear];
        case MONTH_OF_YEAR:
            return [chronology monthOfYear];
        case DAY_OF_MONTH:
            return [chronology dayOfMonth];
        case WEEKYEAR_OF_CENTURY:
            return [chronology weekyearOfCentury];
        case WEEKYEAR:
            return [chronology weekyear];
        case WEEK_OF_WEEKYEAR:
            return [chronology weekOfWeekyear];
        case DAY_OF_WEEK:
            return [chronology dayOfWeek];
        case HALFDAY_OF_DAY:
            return [chronology halfdayOfDay];
        case HOUR_OF_HALFDAY:
            return [chronology hourOfHalfday];
        case CLOCKHOUR_OF_HALFDAY:
            return [chronology clockhourOfHalfday];
        case CLOCKHOUR_OF_DAY:
            return [chronology clockhourOfDay];
        case HOUR_OF_DAY:
            return [chronology hourOfDay];
        case MINUTE_OF_DAY:
            return [chronology minuteOfDay];
        case MINUTE_OF_HOUR:
            return [chronology minuteOfHour];
        case SECOND_OF_DAY:
            return [chronology secondOfDay];
        case SECOND_OF_MINUTE:
            return [chronology secondOfMinute];
        case MILLIS_OF_DAY:
            return [chronology millisOfDay];
        case MILLIS_OF_SECOND:
            return [chronology millisOfSecond];
        default:
            // Shouldn't happen.
            [NSException raise:HL_INTERNAL_ERROR
                        format:@"Unrecognized ordinal: %ld", _iOrdinal];
    }
}

/**
 * Ensure a singleton is returned.
 * 
 * @return the singleton type
 */
- (id)_readResolve {
    switch (_iOrdinal) {
        case ERA:
            return [self era];
        case YEAR_OF_ERA:
            return [self yearOfEra];
        case CENTURY_OF_ERA:
            return [self centuryOfEra];
        case YEAR_OF_CENTURY:
            return [self yearOfCentury];
        case YEAR:
            return [self year];
        case DAY_OF_YEAR:
            return [self dayOfYear];
        case MONTH_OF_YEAR:
            return [self monthOfYear];
        case DAY_OF_MONTH:
            return [self dayOfMonth];
        case WEEKYEAR_OF_CENTURY:
            return [self weekyearOfCentury];
        case WEEKYEAR:
            return [self weekyear];
        case WEEK_OF_WEEKYEAR:
            return [self weekOfWeekyear];
        case DAY_OF_WEEK:
            return [self dayOfWeek];
        case HALFDAY_OF_DAY:
            return [self halfdayOfDay];
        case HOUR_OF_HALFDAY:
            return [self hourOfHalfday];
        case CLOCKHOUR_OF_HALFDAY:
            return [self clockhourOfHalfday];
        case CLOCKHOUR_OF_DAY:
            return [self clockhourOfDay];
        case HOUR_OF_DAY:
            return [self hourOfDay];
        case MINUTE_OF_DAY:
            return [self minuteOfDay];
        case MINUTE_OF_HOUR:
            return [self minuteOfHour];
        case SECOND_OF_DAY:
            return [self secondOfDay];
        case SECOND_OF_MINUTE:
            return [self secondOfMinute];
        case MILLIS_OF_DAY:
            return [self millisOfDay];
        case MILLIS_OF_SECOND:
            return [self millisOfSecond];
        default:
            // Shouldn't happen.
            return self;
    }
}

@end
