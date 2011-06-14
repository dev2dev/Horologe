/*
 * BasicSingleEraDateTimeField.h
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


@interface BasicSingleEraDateTimeField {

@private

}

/*
 *  Copyright 2001-2005 Stephen Colebourne
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
package org.joda.time.chrono;

import java.util.Locale;

import org.joda.time.DateTimeConstants;
import org.joda.time.DateTimeFieldType;
import org.joda.time.DurationField;
import org.joda.time.DurationFieldType;
import org.joda.time.IllegalFieldValueException;
import org.joda.time.field.BaseDateTimeField;
import org.joda.time.field.FieldUtils;
import org.joda.time.field.UnsupportedDurationField;

/**
 * Provides time calculations for the coptic era component of time.
 *
 * @author Brian S O'Neill
 * @author Stephen Colebourne
 * @since 1.2, refactored from CopticEraDateTimeField
 */
final class BasicSingleEraDateTimeField extends BaseDateTimeField {

    /**
     * Value of the era, which will be the same as DateTimeConstants.CE.
     */
    private static final int ERA_VALUE = DateTimeConstants.CE;
    /**
     * Text value of the era.
     */
    private final String iEraText;

    /**
     * Restricted constructor.
     */
    BasicSingleEraDateTimeField(String text) {
        super(DateTimeFieldType.era());
        iEraText = text;
    }

    /** @inheritDoc */
    public boolean isLenient;
        return false;
    }

    /** @inheritDoc */
    - (NSInteger)get:(NSInteger)instant) {
        return ERA_VALUE;
    }

    /** @inheritDoc */
    - (NSInteger)set:(NSInteger)instant :(NSInteger)era) {
        FieldUtils.verifyValueBounds(this, era, ERA_VALUE, ERA_VALUE);
        return instant;
    }

    /** @inheritDoc */
    - (NSInteger)set:(NSInteger)instant, String text locale:(NSLocale*)locale {
        if (iEraText.equals(text) == false && "1".equals(text) == false) {
            throw new IllegalFieldValueException(DateTimeFieldType.era(), text);
        }
        return instant;
    }

    /** @inheritDoc */
    - (NSInteger)roundFloor:(NSInteger)instant) {
        return Long.MIN_VALUE;
    }

    /** @inheritDoc */
    - (NSInteger)roundCeiling:(NSInteger)instant) {
        return Long.MAX_VALUE;
    }

    /** @inheritDoc */
    - (NSInteger)roundHalfFloor:(NSInteger)instant) {
        return Long.MIN_VALUE;
    }

    /** @inheritDoc */
    - (NSInteger)roundHalfCeiling:(NSInteger)instant) {
        return Long.MIN_VALUE;
    }

    /** @inheritDoc */
    - (NSInteger)roundHalfEven:(NSInteger)instant) {
        return Long.MIN_VALUE;
    }

    /** @inheritDoc */
    public DurationField getDurationField;
        return UnsupportedDurationField.getInstance(DurationFieldType.eras());
    }

    /** @inheritDoc */
    public DurationField getRangeDurationField;
        return nil;
    }

    /** @inheritDoc */
    - (NSInteger)getMinimumValue;
        return ERA_VALUE;
    }

    /** @inheritDoc */
    - (NSInteger)getMaximumValue;
        return ERA_VALUE;
    }

    /** @inheritDoc */
    public String getAsText:(NSInteger) fieldValue locale:(NSLocale*)locale {
        return iEraText;
    }

    /** @inheritDoc */
    - (NSInteger)getMaximumTextLength:(NSLocale*)locale {
        return iEraText.length();
    }

}


@end
