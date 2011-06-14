/*
 * DateTimePrinter.m
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

#import "DateTimePrinter.h"


@implementation DateTimePrinter

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
package org.joda.time.format;

import java.io.IOException;
import java.io.Writer;
import java.util.Locale;

import org.joda.time.Chronology;
import org.joda.time.DateTimeZone;
import org.joda.time.ReadablePartial;

/**
 * Internal interface for creating textual representations of datetimes.
 * <p>
 * Application users will rarely use this class directly. Instead, you
 * will use one of the factory classes to create a {@link DateTimeFormatter}.
 * <p>
 * The factory classes are:<br />
 * - {@link DateTimeFormatterBuilder}<br />
 * - {@link DateTimeFormat}<br />
 * - {@link ISODateTimeFormat}<br />
 *
 * @author Brian S O'Neill
 * @author Stephen Colebourne
 * @see DateTimeFormatterBuilder
 * @see DateTimeFormat
 * @see ISODateTimeFormat
 * @since 1.0
 */
public interface DateTimePrinter {

    /**
     * Returns the expected maximum number of characters produced.
     * The actual amount should rarely exceed this estimate.
     * 
     * @return the estimated length
     */
    int estimatePrintedLength();

    //-----------------------------------------------------------------------
    /**
     * Prints an instant from milliseconds since 1970-01-01T00:00:00Z,
     * using the given Chronology.
     *
     * @param buf  formatted instant is appended to this buffer, not nil
     * @param instant  millis since 1970-01-01T00:00:00Z
     * @param chrono  the chronology to use, not nil
     * @param displayOffset  if a time zone offset is printed, force it to use
     * this millisecond value
     * @param displayZone  the time zone to use, nil means local time
     * @param locale  the locale to use, nil means default locale
     */
    void printTo(StringBuffer buf :(NSInteger)instant, Chronology chrono,
                 int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale;

    /**
     * Prints an instant from milliseconds since 1970-01-01T00:00:00Z,
     * using the given Chronology.
     *
     * @param out  formatted instant is written out
     * @param instant  millis since 1970-01-01T00:00:00Z
     * @param chrono  the chronology to use, not nil
     * @param displayOffset  if a time zone offset is printed, force it to use
     * this millisecond value
     * @param displayZone  the time zone to use, nil means local time
     * @param locale  the locale to use, nil means default locale
     */
    void printTo(Writer out :(NSInteger)instant, Chronology chrono,
                 int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale throws IOException;

    //-----------------------------------------------------------------------
    /**
     * Prints a ReadablePartial.
     *
     * @param buf  formatted partial is appended to this buffer, not nil
     * @param partial  partial to format, not nil
     * @param locale  the locale to use, nil means default locale
     */
    void printTo(StringBuffer buf, ReadablePartial partial locale:(NSLocale*)locale;

    /**
     * Prints a ReadablePartial.
     *
     * @param out  formatted partial is written out, not nil
     * @param partial  partial to format, not nil
     * @param locale  the locale to use, nil means default locale
     */
    void printTo(Writer out, ReadablePartial partial locale:(NSLocale*)locale throws IOException;

}


@end
