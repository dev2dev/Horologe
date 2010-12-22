/*
 * HLBasicSingleEraDateTimeField.h
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

#import <Foundation/Foundation.h>

#import "HLBaseDateTimeField.h"
#import "HLDateTimeConstants.h"
#import "HLDurationField.h"


#define ERA_VALUE (CE)

@interface HLBasicSingleEraDateTimeField : HLBaseDateTimeField {
    
@private
    NSString* iEraText;
}

/**
 * Restricted constructor.
 */
- (id)initWithText:(NSString*)text;

/** @inheritDoc */
- (BOOL)isLenient;

/** @inheritDoc */
- (NSInteger)get:(NSInteger)instant;

/** @inheritDoc */
- (NSInteger)set:(NSInteger)instant
             era:(NSInteger)era;

/** @inheritDoc */
- (NSInteger)set:(NSInteger)instant
            text:(NSString*)text
          locale:(NSLocale*)locale;

/** @inheritDoc */
- (NSInteger)roundFloor:(NSInteger)instant;

/** @inheritDoc */
- (NSInteger)roundCeiling:(NSInteger)instant;

/** @inheritDoc */
- (NSInteger)roundHalfFloor:(NSInteger)instant;

/** @inheritDoc */
- (NSInteger)roundHalfCeiling:(NSInteger)instant;

/** @inheritDoc */
- (NSInteger)roundHalfEven:(NSInteger)instant;

/** @inheritDoc */
- (HLDurationField*)durationField;

/** @inheritDoc */
- (HLDurationField*)rangeDurationField;

/** @inheritDoc */
- (NSInteger)minimumValue;

/** @inheritDoc */
- (NSInteger)maximumValue;

/** @inheritDoc */
- (NSString*)asText:(NSInteger)fieldValue
             locale:(NSLocale*)locale;

/** @inheritDoc */
- (NSInteger)maximumTextLength:(NSLocale*)locale;

@end
