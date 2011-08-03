/*
 * AbstractPartialFieldProperty.m
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

#import "HLAbstractPartialFieldProperty.h"

#import "HLDateTimeField.h"
#import "HLDurationField.h"
#import "HLReadableInstant.h"
#import "HLReadablePartial.h"

#import "HLFieldUtils.h"

#import "HLConstants.h"


@implementation HLAbstractPartialFieldProperty

    //-----------------------------------------------------------------------
- (HLDateTimeField*)field {
    [NSException raise:HL_UNIMPLEMENTED_EXCEPTION
                format:@"%@: %s is abstract and must be implemented by subclass!", self, _cmd];
}

    - (HLDateTimeFieldType*)fieldType {
        return [[self field] fieldType];
    }

    - (NSString*)name {
        return [[self field] name];
    }

- (id<HLReadablePartial>)readablePartial {
    [NSException raise:HL_UNIMPLEMENTED_EXCEPTION
                format:@"%@: %s is abstract and must be implemented by subclass!", self, _cmd];
}

    //-----------------------------------------------------------------------
- (NSInteger)value {
    [NSException raise:HL_UNIMPLEMENTED_EXCEPTION
                format:@"%@: %s is abstract and must be implemented by subclass!", self, _cmd];
}

    - (NSString*)valueAsString {
        return [NSString stringWithFormat:@"%ld", [self value]];
    }

    - (NSString*)valueAsText {
        return [self valueAsTextWithLocale:nil];
    }

    - (NSString*)valueAsTextWithLocale:(NSLocale*)locale {
        return [[self field] valueAsText:[self readablePartial] 
                                   value:[self value] 
                                  locale:locale];
    }

    - (NSString*)valueAsShortText {
        return [self valueAsShortTextWithLocale:nil];
    }

    - (NSString*)valueAsShortTextWithLocale:(NSLocale*)locale {
        return [[self field] valueAsShortText:[self readablePartial] 
                                        value:[self value] 
                                       locale:locale];
    }

    //-----------------------------------------------------------------------
- (HLDurationField*)durationField {
        return [[self field] durationField];
    }

- (HLDurationField*)rangeDurationField {
        return [[self field] rangeDurationField];
    }

    //-----------------------------------------------------------------------
    - (NSInteger)getMinimumValueOverall {
        return [[self field] minimumValue];
    }

    - (NSInteger)getMinimumValue {
        return [[self field] minimumValueWithPartial:[self readablePartial]];
    }

    - (NSInteger)getMaximumValueOverall {
        return [[self field] maximumValue];
    }

    - (NSInteger)getMaximumValue {
        return [[self field] maximumValueWithPartial:[self readablePartial]];
    }

    //-----------------------------------------------------------------------
    - (NSInteger)getMaximumTextLengthWithLocale:(NSLocale*)locale {
        return [[self field] maximumTextLengthWithLocale:locale];
    }

    - (NSInteger)getMaximumShortTextLengthWithLocale:(NSLocale*)locale {
        return [[self field] maximumShortTextLengthWithLocale:locale];
    }

    //-----------------------------------------------------------------------
    - (NSInteger)compareToInstant:(id<HLReadableInstant>)instant {
        if (instant == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"The instant must not be nil"];
        }
        int thisValue = [self value];
        int otherValue = [instant valueOfFieldType:[self fieldType]];
        if (thisValue < otherValue) {
            return -1;
        } 
        else if (thisValue > otherValue) {
            return 1;
        } 
        else {
            return 0;
        }
    }

    - (NSInteger)compareToPartial:(id<HLReadablePartial>)partial {
        if (partial == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"The instant must not be nil"];
        }
        int thisValue = [self value];
        int otherValue = [partial valueOfFieldType:[self fieldType]];
        if (thisValue < otherValue) {
            return -1;
        } 
        else if (thisValue > otherValue) {
            return 1;
        }
        else {
            return 0;
        }
    }

    //-----------------------------------------------------------------------
    - (BOOL)isEqualTo:(id)object {

        if(self == object) {
            return YES;
        }
        if(![object isKindOfClass:[HLAbstractPartialFieldProperty class]]) {
            return NO;
        }
        HLAbstractPartialFieldProperty* other = (HLAbstractPartialFieldProperty*)object;
        
        return ([self get] == [other get] &&
            [self fieldType] == [other fieldType] &&
             [HLFieldUtils isObject:[[self readablePartial] chronology]
                      equalToObject:[[other readablePartial] chronology]]);
    }

    //-----------------------------------------------------------------------
    - (NSUInteger)hash {
        int hash = 19;
        hash = 13 * hash + [self get];
        hash = 13 * hash + [[self fieldType] hash];
        hash = 13 * hash + [[[self readablePartial] chronology] hash];
        return hash;
    }

    //-----------------------------------------------------------------------
    - (NSString*)description {
        return [NSString stringWithFormat:@"HLAbstractPartialFieldProperty[%@]", [self name]];
    }

@end
