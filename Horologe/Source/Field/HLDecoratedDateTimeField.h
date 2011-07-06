/*
 * DecoratedDateTimeField.h
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

#import "HLBaseDateTimeField.h"


@class HLDateTimeField;
@class HLDurationField;

/**
 * <code>DecoratedDateTimeField</code> extends {@link BaseDateTimeField},
 * implementing only the minimum required set of methods. These implemented
 * methods delegate to a wrapped field.
 * <p>
 * This design allows new DateTimeField types to be defined that piggyback on
 * top of another, inheriting all the safe method implementations from
 * BaseDateTimeField. Should any method require pure delegation to the
 * wrapped field, simply override and use the provided getWrappedField method.
 * <p>
 * DecoratedDateTimeField is thread-safe and immutable, and its subclasses must
 * be as well.
 *
 * @author Brian S O'Neill
 * @since 1.0
 * @see DelegatedDateTimeField
 */
@interface HLDecoratedDateTimeField : HLBaseDateTimeField {
    
@private
    /** The DateTimeField being wrapped */
    HLDateTimeField* _iField;
    
}

/**
 * Constructor.
 * 
 * @param field  the field being decorated
 * @param type  allow type to be overridden
 */
- (id)initWithDateTimeField:(HLDateTimeField*)field
                       type:(HLDateTimeFieldType*)type;

/**
 * Gets the wrapped date time field.
 * 
 * @return the wrapped DateTimeField
 */
- (HLDateTimeField*)wrappedField;

- (BOOL)isLenient;

- (NSInteger)getInstantValue:(NSInteger)instant;

- (NSInteger)setInstantValue:(NSInteger)instant 
                       value:(NSInteger)value;

- (HLDurationField*)durationField;

- (HLDurationField*)rangeDurationField;

- (NSInteger)minimumValue;

- (NSInteger)maximumValue;

- (NSInteger)roundFloor:(NSInteger)instant;

@end
