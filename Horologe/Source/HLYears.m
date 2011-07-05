/*
 * Years.m
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

#import "HLYears.h"

#import "HLPeriod.h"
#import "HLFieldUtils.h"
#import "HLDurationFieldType.h"
#import "HLPeriodType.h"
#import "HLPeriodFormatter.h"
#import "HLLocalDate.h"


static HLYears* HL_YEARS_ZERO = [[HLYears alloc] initWithYears:0];
static HLYears* HL_YEARS_ONE = [[HLYears alloc] initWithYears:0];
static HLYears* HL_YEARS_TWO = [[HLYears alloc] initWithYears:0];
static HLYears* HL_YEARS_THREE = [[HLYears alloc] initWithYears:0];
static HLYears* HL_YEARS_MIN_VALUE = [[HLYears alloc] initWithYears:NSIntegerMin];
static HLYears* HL_YEARS_MAX_VALUE = [[HLYears alloc] initWithYears:NSIntegerMax];

static HLPeriodFormatter* parser;

@implementation HLYears

//-----------------------------------------------------------------------
+ (HLYears*)years:(NSInteger)years {
    switch (years) {
        case 0:
            return HL_YEARS_ZERO;
        case 1:
            return HL_YEARS_ONE;
        case 2:
            return HL_YEARS_TWO;
        case 3:
            return HL_YEARS_THREE;
        case NSIntegerMax:
            return HL_YEARS_MAX_VALUE;
        case NSIntegerMin:
            return HL_YEARS_MIN_VALUE;
        default:
            return [[HLYears alloc] initWithYears:years];
    }
}

//-----------------------------------------------------------------------
+ (HLYears*)yearsBetweenStartInstant:(id<HLReadableInstant>)start
                          endInstant:(id<HLReadableInstant>)end {
    NSInteger amount = [HLBaseSingleFieldPeriod betweenStart:start
                                                         end:end
                                                        type:[HLDurationFieldType years]];
    return [HLYears years:amount];
}

+ (HLYears*)yearsBetweenStartPartial:(id<HLReadablePartial>)start
                          endPartial:(id<HLReadablePartial>)end {
    if ([start isKindOfClass:[HLLocalDate class]] && 
        [end isKindOfClass:[HLLocalDate class]]) {
        HLChronology* chrono = [HLDateTimeUtils chronology:[start chronology]];
        NSInteger years = [[chrono years] differenceBetweenLocalDate:[(HLLocalDate*)end localMillis] 
                                                           localDate:[(HLLocalDate*)start localMillis]];
        return [HLYears years:years];
    }
    
    NSInteger amount = [HLBaseSingleFieldPeriod betweenStartPartial:start
                                                         endPartial:end
                                                       years:HL_YEARS_ZERO];
    return [HLYears years:amount];
}

+ (HLYears*)yearsIn:(id<HLReadableInterval>)interval {
    if (interval == nil)   {
        return HL_YEARS_ZERO;
    }
    
    NSInteger amount = [HLBaseSingleFieldPeriod betweenStartInstant:[interval start]
                                                         endInstant:[interval end]
                                                       years:[HLDurationFieldType years]];
    return [HLYears years:amount];
}

+ (HLYears*)parseYears:(NSString*)periodStr {
    if (periodStr == nil) {
        return HL_YEARS_ZERO;
    }
    
    HLPeriod* p = [parser parsePeriod:periodStr];
    return [HLYears years:[p years]];
}

//-----------------------------------------------------------------------
- (id)initWithYears:(NSInteger)years {
    self = [super initWithValue:years];
    if(self) {
        
    }
    
    return self;
}

- (id)readResolve {
    return [HLYears years:[self value]];
}

//-----------------------------------------------------------------------
- (HLDurationFieldType*)fieldType {
    return [HLDurationFieldType years];
}

- (HLPeriodType*)periodType {
    return [HLPeriodType years];
}

//-----------------------------------------------------------------------
- (NSInteger)years {
    return [self value];
}

//-----------------------------------------------------------------------
- (HLYears*)plusYearsValue:(NSInteger)years {
    if (years == 0) {
        return self;
    }
    
    return [HLYears years:[HLFieldUtils safeAddValue:[self value]
                                            andValue:years]];
}

- (HLYears*)plusYears:(HLYears*)years {
    if (years == nil) {
        return self;
    }
    
    return [self plus:[years value]];
}

//-----------------------------------------------------------------------
- (HLYears*)minusYearsValue:(NSInteger)years {
    return [self plus:[HLFieldUtils safeNegate:years]]
}

- (HLYears*)minusYears:(HLYears*)years {
    if (years == nil) {
        return self;
    }
    
    return [self minus:[years value]];
}

//-----------------------------------------------------------------------
- (HLYears*)multipliedBy:(NSInteger)scalar {
    return [HLYears years:[HLFieldUtils safeMultiplyValue:[self value]
                                                   andScalar:scalar]];
}

- (HLYears*)dividedBy:(NSInteger)divisor {
    if (divisor == 1) {
        return self;
    }
    
    return [HLYears years:([self value] / divisor)];
}

//-----------------------------------------------------------------------
- (HLYears*)negated {
    return [HLYears years:[HLFieldUtils safeNegate:[self value]]];
}

//-----------------------------------------------------------------------
- (BOOL)isGreaterThanYears:(HLYears*)other {
    if (other == nil) {
        return [self value] > 0;
    }
    
    return [self value] > [other value];
}

- (BOOL)isLessThanYears:(HLYears*)other {
    if (other == nil) {
        return [self value] < 0;
    }
    
    return [self value] < [other value];
}

//-----------------------------------------------------------------------
- (NSString*)description {
    return [NSString stringWithFormat:@"P%ldY", [self value]];
}

@end
