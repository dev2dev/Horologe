/*
 * GJEraDateTimeField.h
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


@interface GJEraDateTimeField {

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
import org.joda.time.field.BaseDateTimeField;
import org.joda.time.field.FieldUtils;
import org.joda.time.field.UnsupportedDurationField;

/**
 * Provides time calculations for the era component of time.
 *
 * @author Stephen Colebourne
 * @author Brian S O'Neill
 * @since 1.0
 */
final class GJEraDateTimeField extends BaseDateTimeField {
    
    /** Serialization version */
    private static final long serialVersionUID = 4240986525305515528L;

    private final BasicChronology iChronology;

    /**
     * Restricted constructor
     */
    GJEraDateTimeField(BasicChronology chronology) {
        super(DateTimeFieldType.era());
        iChronology = chronology;
    }

    - (BOOL)isLenient;
        return NO;
    }

    /**
     * Get the Era component of the specified time instant.
     * 
     * @param instant  the time instant in millis to query.
     */
    - (NSInteger)get:(NSInteger)instant) {
        if (iChronology.getYear(instant) <= 0) {
            return DateTimeConstants.BCE;
        } else {
            return DateTimeConstants.CE;
        }
    }

    - (NSString*)getAsText:(NSInteger) fieldValue locale:(NSLocale*)locale {
        return GJLocaleSymbols.forLocale(locale).eraValueToText(fieldValue);
    }

    /**
     * Set the Era component of the specified time instant.
     * 
     * @param instant  the time instant in millis to update.
     * @param era  the era to update the time to.
     * @return the updated time instant.
     * @throws IllegalArgumentException  if era is invalid.
     */
    - (NSInteger)set:(NSInteger)instant :(NSInteger)era) {
        FieldUtils.verifyValueBounds(this, era, DateTimeConstants.BCE, DateTimeConstants.CE);
            
        int oldEra = get(instant);
        if (oldEra != era) {
            int year = iChronology.getYear(instant);
            return iChronology.setYear(instant, -year);
        } else {
            return instant;
        }
    }

    - (NSInteger)set:(NSInteger)instant, String text locale:(NSLocale*)locale {
        return set(instant, GJLocaleSymbols.forLocale(locale).eraTextToValue(text));
    }

    - (NSInteger)roundFloor:(NSInteger)instant) {
        if (get(instant) == DateTimeConstants.CE) {
            return iChronology.setYear(0, 1);
        } else {
            return Long.MIN_VALUE;
        }
    }

    - (NSInteger)roundCeiling:(NSInteger)instant) {
        if (get(instant) == DateTimeConstants.BCE) {
            return iChronology.setYear(0, 1);
        } else {
            return Long.MAX_VALUE;
        }
    }

    - (NSInteger)roundHalfFloor:(NSInteger)instant) {
        // In reality, the era is infinite, so there is no halfway point.
        return roundFloor(instant);
    }

    - (NSInteger)roundHalfCeiling:(NSInteger)instant) {
        // In reality, the era is infinite, so there is no halfway point.
        return roundFloor(instant);
    }

    - (NSInteger)roundHalfEven:(NSInteger)instant) {
        // In reality, the era is infinite, so there is no halfway point.
        return roundFloor(instant);
    }

    public DurationField getDurationField;
        return UnsupportedDurationField.getInstance(DurationFieldType.eras());
    }

    public DurationField getRangeDurationField;
        return nil;
    }

    - (NSInteger)getMinimumValue;
        return DateTimeConstants.BCE;
    }

    - (NSInteger)getMaximumValue;
        return DateTimeConstants.CE;
    }

    - (NSInteger)getMaximumTextLength:(NSLocale*)locale {
        return GJLocaleSymbols.forLocale(locale).getEraMaxTextLength();
    }

    /**
     * Serialization singleton
     */
    private Object readResolve;
        return iChronology.era();
    }
}


@end
