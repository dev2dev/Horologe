/*
 * HLPeriodType.m
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

#import "HLPeriodType.h"


static HLPeriodType* cStandard;
static HLPeriodType* cYMDTime;
static HLPeriodType* cYMD;
static HLPeriodType* cYWDTime;
static HLPeriodType* cYWD;
static HLPeriodType* cYDTime;
static HLPeriodType* cYD;
static HLPeriodType* cDTime;
static HLPeriodType* cTime;

static HLPeriodType* cYears;
static HLPeriodType* cMonths;
static HLPeriodType* cWeeks;
static HLPeriodType* cDays;
static HLPeriodType* cHours;
static HLPeriodType* cMinutes;
static HLPeriodType* cSeconds;
static HLPeriodType* cMillis;

@interface HLPeriodType

- (HLPeriodType*)withFieldRemoved:(NSInteger)indicesIndex 
                             name:(NSString*)name;

@end

@implementation HLPeriodType

+ (HLPeriodType*)standard {
    HLPeriodType* type = cStandard;
    if (type == nil) {
        type = new PeriodType(
                              "Standard",
                              new DurationFieldType[] {
                                  DurationFieldType.years(), DurationFieldType.months(),
                                  DurationFieldType.weeks(), DurationFieldType.days(),
                                  DurationFieldType.hours(), DurationFieldType.minutes(),
                                  DurationFieldType.seconds(), DurationFieldType.millis(),
                              },
                              new int[] { 0, 1, 2, 3, 4, 5, 6, 7, }
                              );
        cStandard = type;
    }
    return type;
}

+ (HLPeriodType*)yearMonthDayTime() {
    PeriodType type = cYMDTime;
    if (type == null) {
        type = new PeriodType(
                              "YearMonthDayTime",
                              new DurationFieldType[] {
                                  DurationFieldType.years(), DurationFieldType.months(),
                                  DurationFieldType.days(),
                                  DurationFieldType.hours(), DurationFieldType.minutes(),
                                  DurationFieldType.seconds(), DurationFieldType.millis(),
                              },
                              new int[] { 0, 1, -1, 2, 3, 4, 5, 6, }
                              );
        cYMDTime = type;
    }
    return type;
}

+ (HLPeriodType*)yearMonthDay() {
    PeriodType type = cYMD;
    if (type == null) {
        type = new PeriodType(
                              "YearMonthDay",
                              new DurationFieldType[] {
                                  DurationFieldType.years(), DurationFieldType.months(),
                                  DurationFieldType.days(),
                              },
                              new int[] { 0, 1, -1, 2, -1, -1, -1, -1, }
                              );
        cYMD = type;
    }
    return type;
}

+ (HLPeriodType*)yearWeekDayTime() {
    PeriodType type = cYWDTime;
    if (type == null) {
        type = new PeriodType(
                              "YearWeekDayTime",
                              new DurationFieldType[] {
                                  DurationFieldType.years(),
                                  DurationFieldType.weeks(), DurationFieldType.days(),
                                  DurationFieldType.hours(), DurationFieldType.minutes(),
                                  DurationFieldType.seconds(), DurationFieldType.millis(),
                              },
                              new int[] { 0, -1, 1, 2, 3, 4, 5, 6, }
                              );
        cYWDTime = type;
    }
    return type;
}

+ (HLPeriodType*)yearWeekDay() {
    PeriodType type = cYWD;
    if (type == null) {
        type = new PeriodType(
                              "YearWeekDay",
                              new DurationFieldType[] {
                                  DurationFieldType.years(),
                                  DurationFieldType.weeks(), DurationFieldType.days(),
                              },
                              new int[] { 0, -1, 1, 2, -1, -1, -1, -1, }
                              );
        cYWD = type;
    }
    return type;
}

+ (HLPeriodType*)yearDayTime() {
    PeriodType type = cYDTime;
    if (type == null) {
        type = new PeriodType(
                              "YearDayTime",
                              new DurationFieldType[] {
                                  DurationFieldType.years(), DurationFieldType.days(),
                                  DurationFieldType.hours(), DurationFieldType.minutes(),
                                  DurationFieldType.seconds(), DurationFieldType.millis(),
                              },
                              new int[] { 0, -1, -1, 1, 2, 3, 4, 5, }
                              );
        cYDTime = type;
    }
    return type;
}

+ (HLPeriodType*)yearDay() {
    PeriodType type = cYD;
    if (type == null) {
        type = new PeriodType(
                              "YearDay",
                              new DurationFieldType[] {
                                  DurationFieldType.years(), DurationFieldType.days(),
                              },
                              new int[] { 0, -1, -1, 1, -1, -1, -1, -1, }
                              );
        cYD = type;
    }
    return type;
}

+ (HLPeriodType*)dayTime() {
    PeriodType type = cDTime;
    if (type == null) {
        type = new PeriodType(
                              "DayTime",
                              new DurationFieldType[] {
                                  DurationFieldType.days(),
                                  DurationFieldType.hours(), DurationFieldType.minutes(),
                                  DurationFieldType.seconds(), DurationFieldType.millis(),
                              },
                              new int[] { -1, -1, -1, 0, 1, 2, 3, 4, }
                              );
        cDTime = type;
    }
    return type;
}

+ (HLPeriodType*)time() {
    PeriodType type = cTime;
    if (type == null) {
        type = new PeriodType(
                              "Time",
                              new DurationFieldType[] {
                                  DurationFieldType.hours(), DurationFieldType.minutes(),
                                  DurationFieldType.seconds(), DurationFieldType.millis(),
                              },
                              new int[] { -1, -1, -1, -1, 0, 1, 2, 3, }
                              );
        cTime = type;
    }
    return type;
}

+ (HLPeriodType*)years() {
    PeriodType type = cYears;
    if (type == null) {
        type = new PeriodType(
                              "Years",
                              new DurationFieldType[] { DurationFieldType.years() },
                              new int[] { 0, -1, -1, -1, -1, -1, -1, -1, }
                              );
        cYears = type;
    }
    return type;
}

+ (HLPeriodType*)months() {
    PeriodType type = cMonths;
    if (type == null) {
        type = new PeriodType(
                              "Months",
                              new DurationFieldType[] { DurationFieldType.months() },
                              new int[] { -1, 0, -1, -1, -1, -1, -1, -1, }
                              );
        cMonths = type;
    }
    return type;
}

+ (HLPeriodType*)weeks() {
    PeriodType type = cWeeks;
    if (type == null) {
        type = new PeriodType(
                              "Weeks",
                              new DurationFieldType[] { DurationFieldType.weeks() },
                              new int[] { -1, -1, 0, -1, -1, -1, -1, -1, }
                              );
        cWeeks = type;
    }
    return type;
}

+ (HLPeriodType*)days() {
    PeriodType type = cDays;
    if (type == null) {
        type = new PeriodType(
                              "Days",
                              new DurationFieldType[] { DurationFieldType.days() },
                              new int[] { -1, -1, -1, 0, -1, -1, -1, -1, }
                              );
        cDays = type;
    }
    return type;
}

+ (HLPeriodType*)hours() {
    PeriodType type = cHours;
    if (type == null) {
        type = new PeriodType(
                              "Hours",
                              new DurationFieldType[] { DurationFieldType.hours() },
                              new int[] { -1, -1, -1, -1, 0, -1, -1, -1, }
                              );
        cHours = type;
    }
    return type;
}

+ (HLPeriodType*)minutes() {
    PeriodType type = cMinutes;
    if (type == null) {
        type = new PeriodType(
                              "Minutes",
                              new DurationFieldType[] { DurationFieldType.minutes() },
                              new int[] { -1, -1, -1, -1, -1, 0, -1, -1, }
                              );
        cMinutes = type;
    }
    return type;
}

+ (HLPeriodType*)seconds() {
    PeriodType type = cSeconds;
    if (type == null) {
        type = new PeriodType(
                              "Seconds",
                              new DurationFieldType[] { DurationFieldType.seconds() },
                              new int[] { -1, -1, -1, -1, -1, -1, 0, -1, }
                              );
        cSeconds = type;
    }
    return type;
}

+ (HLPeriodType*)millis() {
    PeriodType type = cMillis;
    if (type == null) {
        type = new PeriodType(
                              "Millis",
                              new DurationFieldType[] { DurationFieldType.millis() },
                              new int[] { -1, -1, -1, -1, -1, -1, -1, 0, }
                              );
        cMillis = type;
    }
    return type;
}

+ (HLPeriodType*)forFields:(NSArray*)types {
    if (types == nil || [types count] == 0) {
        [NSException raise:NSInvalidArgumentException format:@"Types array must not be null or empty"];
    }
    for (NSInteger i = 0; i < types.length; i++) {
        if ([types objectAtIndex:i] == nil) {
            [NSException raise:NSInvalidArgumentException format:@"Types array must not contain null"];
        }
    }
    NSDictionary* cache = cTypes;
    if (cache.isEmpty()) {
        cache.put(standard(), standard());
        cache.put(yearMonthDayTime(), yearMonthDayTime());
        cache.put(yearMonthDay(), yearMonthDay());
        cache.put(yearWeekDayTime(), yearWeekDayTime());
        cache.put(yearWeekDay(), yearWeekDay());
        cache.put(yearDayTime(), yearDayTime());
        cache.put(yearDay(), yearDay());
        cache.put(dayTime(), dayTime());
        cache.put(time(), time());
        cache.put(years(), years());
        cache.put(months(), months());
        cache.put(weeks(), weeks());
        cache.put(days(), days());
        cache.put(hours(), hours());
        cache.put(minutes(), minutes());
        cache.put(seconds(), seconds());
        cache.put(millis(), millis());
    }
    PeriodType inPartType = new PeriodType(null, types, null);
    Object cached = cache.get(inPartType);
    if (cached instanceof PeriodType) {
        return (PeriodType) cached;
    }
    if (cached != nil) {
        [NSException raise:NSInvalidArgumentException format:@"PeriodType does not support fields: %@", cached];
    }
    HLPeriodType* type = [self standard];
    List<DurationFieldType> list = new ArrayList<DurationFieldType>(Arrays.asList(types));
    if (list.remove(DurationFieldType.years()) == false) {
        type = type.withYearsRemoved();
    }
    if (list.remove(DurationFieldType.months()) == false) {
        type = type.withMonthsRemoved();
    }
    if (list.remove(DurationFieldType.weeks()) == false) {
        type = type.withWeeksRemoved();
    }
    if (list.remove(DurationFieldType.days()) == false) {
        type = type.withDaysRemoved();
    }
    if (list.remove(DurationFieldType.hours()) == false) {
        type = type.withHoursRemoved();
    }
    if (list.remove(DurationFieldType.minutes()) == false) {
        type = type.withMinutesRemoved();
    }
    if (list.remove(DurationFieldType.seconds()) == false) {
        type = type.withSecondsRemoved();
    }
    if (list.remove(DurationFieldType.millis()) == false) {
        type = type.withMillisRemoved();
    }
    if (list.size() > 0) {
        cache.put(inPartType, list);
        throw new IllegalArgumentException("PeriodType does not support fields: " + list);
    }
    // recheck cache in case initial array order was wrong
    PeriodType checkPartType = new PeriodType(null, type.iTypes, null);
    PeriodType checkedType = (PeriodType) cache.get(checkPartType);
    if (checkedType != null) {
        cache.put(inPartType, checkedType);
        return checkedType;
    }
    cache.put(inPartType, type);
    return type;
}

- (id)_initWithName:(NSString*)name types:(NSArray*)types indices:(NSArray*)indices {
    
    if(self = [super init]) {
        iName = [name retain];
        iTypes = [NSArray arrayWithArray:types];
        iIndices = [NSArray arrayWithArray:indices];
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (NSString*)name {
    return iName;
}

- (NSInteger)size {
    return [iTypes count];
}

- (HLDurationFieldType*)fieldTypeAtIndex:(NSInteger)index {
    return [iTypes objectAtIndex:index];
}

- (BOOL)isSupported:(HLDurationFieldType*)type {
    return ([self indexOf:type] >= 0);
}

- (NSInteger)indexOf:(HLDurationFieldType*)type {
    for (int i = 0, isize = [self size]; i < isize; i++) {
        if ([iTypes objectAtIndex:i] == type) {
            return i;
        }
    }
    
    return -1;
}

- (NSString*)description {
    return [NSString stringWithFormat:@"PeriodType[%@]", [self name]];
}

//-----------------------------------------------------------------------
- (NSInteger)_indexedField:(id<HLReadablePeriod>)period
                     index:(NSInteger)index {
    NSInteger realIndex = [[iIndices objectAtIndex:index] integerValue];
    return (realIndex == -1 ? 0 : [period value:realIndex]);
}

- (BOOL)_setIndexedField:(id<HLReadablePeriod>)period
                   index:(NSInteger)index
                  values:(NSMutableArray*)values
                   value:(NSInteger)newValue {
    NSInteger realIndex = [[iIndices objectAtIndex:index] integerValue];
    if (realIndex == -1) {
        [NSException raise:NSInvalidArgumentException format:@"Field is not supported"];
    }
    [values replaceObjectAtIndex:realIndex 
                      withObject:[NSNumber numberWithInteger:newValue]];
    return YES;
}

- (BOOL)_addIndexedField:(id<HLReadablePeriod>)period
                   index:(NSInteger)index
                  values:(NSMutableArray*)values
                   value:(NSInteger)valueToAdd {
    if (valueToAdd == 0) {
        return NO;
    }
    NSInteger realIndex = [iIndices objectAtIndex:index];
    if (realIndex == -1) {
        [NSException raise:NSInvalidArgumentException format:@"Field is not supported"];
    }
    [values replaceObjectAtIndex:realIndex 
                      withObject:[NSNumber numberWithInteger:[HLFieldUtils safeAddValue:[values objectAtIndex:realIndex] 
                                                                                toValue:valueToAdd]]];
    return YES;
}

//-----------------------------------------------------------------------
- (HLPeriodType*)withYearsRemoved {
    return [self withFieldRemoved:0 name:@"NoYears"];
}

- (HLPeriodType*)withMonthsRemoved {
    return [self withFieldRemoved:1 name:@"NoMonths"];
}

- (HLPeriodType*)withWeeksRemoved {
    return [self withFieldRemoved:2 name:"NoWeeks"];
}

- (HLPeriodType*)withDaysRemoved {
    return [self withFieldRemoved:3 name:"NoDays"];
}

- (HLPeriodType*)withHoursRemoved {
    return [self withFieldRemoved:4 name:"NoHours"];
}

- (HLPeriodType*)withMinutesRemoved {
    return [self withFieldRemoved:5 name:"NoMinutes";
            }
            
            - (HLPeriodType*)withSecondsRemoved {
                return [self withFieldRemoved:6 name:"NoSeconds"];
            }
            
            - (HLPeriodType*)withMillisRemoved {
                return [self withFieldRemoved:7 name:"NoMillis"];
            }
            
            - (HLPeriodType*)withFieldRemoved:(NSInteger)indicesIndex
                             name:(NSString*)name {
                                 NSInteger fieldIndex = [iIndices objectAtIndex:indicesIndex];
                                 if (fieldIndex == -1) {
                                     return self;
                                 }
                                 
                                 NSMutableArray* types = [NSMutableArray arrayWithCapacity:([self size] - 1)];
                                 for (NSInteger i = 0; i < [iTypes count]; i++) {
                                     if (i < fieldIndex) {
                                         [types replaceObjectAtIndex:i withObject:[iTypes objectAtIndex:i]];
                                     } 
                                     else if (i > fieldIndex) {
                                         [types replaceObjectAtIndex:(i - 1) withObject:[iTypes objectAtIndex:i]];
                                     }
                                 }
                                 
                                 NSInteger capacity = 8;
                                 NSMutableArray* indices = [NSMutableArray arrayWithCapacity:capacity];
                                 for (int i = 0; i < capacity; i++) {
                                     if (i < indicesIndex) {
                                         [indices replaceObjectAtIndex:i withObject:[iIndices objectAtIndex:i]];
                                     } 
                                     else if (i > indicesIndex) {
                                         [indices replaceObjectAtIndex:i withObject:([[iIndices objectAtIndex:i] integerValue] == -1 ? [NSNumber numberWithInteger:-1] : [iIndices objectAtIndex:i] - 1)];
                                     } 
                                     else {
                                         [indices replaceObjectAtIndex:i withObject:[NSNumber numberWithInteger:-1]];
                                     }
                                 }
                                 
                                 return [[[HLPeriodType alloc] _initWithName:[self name] types:types indices:indices] autorelease];
                             }
            
            //-----------------------------------------------------------------------
            - (BOOL)isEqual:(id)obj {
                if (self == obj) {
                    return YES;
                }
                if (![obj isKindOfClass:[HLPeriodType class]]) {
                    return NO;
                }
                HLPeriodType* other = (HLPeriodType*) obj;
                return (Arrays.equals(iTypes, other.iTypes));
            }
            
            - (NSInteger)hashCode {
                NSInteger hash = 0;
                for (NSInteger i = 0; i < [iTypes count]; i++) {
                    hash += [[[iTypes objectAtIndex:i] integerValue] hashCode];
                }
                
                return hash;
            }
            
            @end
