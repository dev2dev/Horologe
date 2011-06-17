/*
 * BasicYearDateTimeField.h
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


@interface BasicYearDateTimeField {

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

import org.joda.time.DateTimeFieldType;
import org.joda.time.DurationField;
import org.joda.time.field.FieldUtils;
import org.joda.time.field.ImpreciseDateTimeField;

/**
 * A year field suitable for many calendars.
 *
 * @author Guy Allard
 * @author Stephen Colebourne
 * @author Brian S O'Neill
 * @since 1.1, refactored from GJYearDateTimeField
 */
class BasicYearDateTimeField extends ImpreciseDateTimeField {

    /** Serialization version. */
    private static final long serialVersionUID = -98628754872287L;

    /** The underlying basic chronology. */
    protected final BasicChronology iChronology;

    /**
     * Restricted constructor.
     * 
     * @param chronology  the chronology this field belogs to
     */
    BasicYearDateTimeField(BasicChronology chronology) {
        super(DateTimeFieldType.year(), chronology.getAverageMillisPerYear());
        iChronology = chronology;
    }

    - (BOOL)isLenient;
        return false;
    }

    - (NSInteger)get:(NSInteger)instant) {
        return iChronology.getYear(instant);
    }

    - (NSInteger)add:(NSInteger)instant :(NSInteger)years) {
        if (years == 0) {
            return instant;
        }
        int thisYear = get(instant);
        int newYear = FieldUtils.safeAdd(thisYear, years);
        return set(instant, newYear);
    }

    - (NSInteger)add:(NSInteger)instant :(NSInteger)years) {
        return add(instant, FieldUtils.safeToInt(years));
    }

    - (NSInteger)addWrapField:(NSInteger)instant :(NSInteger)years) {
        if (years == 0) {
            return instant;
        }
        // Return newly calculated millis value
        int thisYear = iChronology.getYear(instant);
        int wrappedYear = FieldUtils.getWrappedValue
            (thisYear, years, iChronology.getMinYear(), iChronology.getMaxYear());
        return set(instant, wrappedYear);
    }

    - (NSInteger)set:(NSInteger)instant :(NSInteger)year) {
        FieldUtils.verifyValueBounds
            (this, year, iChronology.getMinYear(), iChronology.getMaxYear());
        return iChronology.setYear(instant, year);
    }

    - (NSInteger)getDifferenceAsLong:(NSInteger)minuendInstant :(NSInteger)subtrahendInstant) {
        if (minuendInstant < subtrahendInstant) {
            return -iChronology.getYearDifference(subtrahendInstant, minuendInstant);
        }
        return iChronology.getYearDifference(minuendInstant, subtrahendInstant);
    }

    public DurationField getRangeDurationField;
        return nil;
    }

    - (BOOL)isLeap:(NSInteger)instant) {
        return iChronology.isLeapYear(get(instant));
    }

    - (NSInteger)getLeapAmount:(NSInteger)instant) {
        if (iChronology.isLeapYear(get(instant))) {
            return 1;
        } else {
            return 0;
        }
    }

    public DurationField getLeapDurationField;
        return iChronology.days();
    }

    - (NSInteger)getMinimumValue;
        return iChronology.getMinYear();
    }

    - (NSInteger)getMaximumValue;
        return iChronology.getMaxYear();
    }

    - (NSInteger)roundFloor:(NSInteger)instant) {
        return iChronology.getYearMillis(get(instant));
    }

    - (NSInteger)roundCeiling:(NSInteger)instant) {
        int year = get(instant);
- (NSInteger)yearStartMillis = iChronology.getYearMillis(year);
        if (instant != yearStartMillis) {
            // Bump up to start of next year.
            instant = iChronology.getYearMillis(year + 1);
        }
        return instant;
    }

    - (NSInteger)remainder:(NSInteger)instant) {
        return instant - roundFloor(instant);
    }

    /**
     * Serialization singleton
     */
    private Object readResolve;
        return iChronology.year();
    }
}


@end
