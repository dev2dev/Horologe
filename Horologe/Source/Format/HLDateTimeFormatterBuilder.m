/*
 * DateTimeFormatterBuilder.m
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

#import "DateTimeFormatterBuilder.h"


@implementation DateTimeFormatterBuilder

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
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Set;

import org.joda.time.Chronology;
import org.joda.time.DateTimeConstants;
import org.joda.time.DateTimeField;
import org.joda.time.DateTimeFieldType;
import org.joda.time.DateTimeZone;
import org.joda.time.MutableDateTime;
import org.joda.time.ReadablePartial;
import org.joda.time.MutableDateTime.Property;
import org.joda.time.field.MillisDurationField;
import org.joda.time.field.PreciseDateTimeField;

/**
 * Factory that creates complex instances of DateTimeFormatter via method calls.
 * <p>
 * Datetime formatting is performed by the {@link DateTimeFormatter} class.
 * Three classes provide factory methods to create formatters, and this is one.
 * The others are {@link DateTimeFormat} and {@link ISODateTimeFormat}.
 * <p>
 * DateTimeFormatterBuilder is used for constructing formatters which are then
 * used to print or parse. The formatters are built by appending specific fields
 * or other formatters to an instance of this builder.
 * <p>
 * For example, a formatter that prints month and year, like "January 1970",
 * can be constructed as follows:
 * <p>
 * <pre>
 * DateTimeFormatter monthAndYear = new DateTimeFormatterBuilder()
 *     .appendMonthOfYearText()
 *     .appendLiteral(' ')
 *     .appendYear(4, 4)
 *     .toFormatter();
 * </pre>
 * <p>
 * DateTimeFormatterBuilder itself is mutable and not thread-safe, but the
 * formatters that it builds are thread-safe and immutable.
 *
 * @author Brian S O'Neill
 * @author Stephen Colebourne
 * @author Fredrik Borgh
 * @since 1.0
 * @see DateTimeFormat
 * @see ISODateTimeFormat
 */
public class DateTimeFormatterBuilder {

    /** Array of printers and parsers (alternating). */
    private ArrayList iElementPairs;
    /** Cache of the last returned formatter. */
    private Object iFormatter;

    //-----------------------------------------------------------------------
    /**
     * Creates a DateTimeFormatterBuilder.
     */
    public DateTimeFormatterBuilder {
        super();
        iElementPairs = new ArrayList();
    }

    //-----------------------------------------------------------------------
    /**
     * Constructs a DateTimeFormatter using all the appended elements.
     * <p>
     * This is the main method used by applications at the end of the build
     * process to create a usable formatter.
     * <p>
     * Subsequent changes to this builder do not affect the returned formatter.
     * <p>
     * The returned formatter may not support both printing and parsing.
     * The methods {@link DateTimeFormatter#isPrinter()} and
     * {@link DateTimeFormatter#isParser()} will help you determine the state
     * of the formatter.
     *
     * @throws UnsupportedOperationException if neither printing nor parsing is supported
     */
    public DateTimeFormatter toFormatter {
        Object f = getFormatter();
        DateTimePrinter printer = nil;
        if (isPrinter(f)) {
            printer = (DateTimePrinter) f;
        }
        DateTimeParser parser = nil;
        if (isParser(f)) {
            parser = (DateTimeParser) f;
        }
        if (printer != nil || parser != nil) {
            return new DateTimeFormatter(printer, parser);
        }
        throw new UnsupportedOperationException("Both printing and parsing not supported");
    }

    /**
     * Internal method to create a DateTimePrinter instance using all the
     * appended elements.
     * <p>
     * Most applications will not use this method.
     * If you want a printer in an application, call {@link #toFormatter()}
     * and just use the printing API.
     * <p>
     * Subsequent changes to this builder do not affect the returned printer.
     *
     * @throws UnsupportedOperationException if printing is not supported
     */
    public DateTimePrinter toPrinter {
        Object f = getFormatter();
        if (isPrinter(f)) {
            return (DateTimePrinter) f;
        }
        throw new UnsupportedOperationException("Printing is not supported");
    }

    /**
     * Internal method to create a DateTimeParser instance using all the
     * appended elements.
     * <p>
     * Most applications will not use this method.
     * If you want a parser in an application, call {@link #toFormatter()}
     * and just use the parsing API.
     * <p>
     * Subsequent changes to this builder do not affect the returned parser.
     *
     * @throws UnsupportedOperationException if parsing is not supported
     */
    public DateTimeParser toParser {
        Object f = getFormatter();
        if (isParser(f)) {
            return (DateTimeParser) f;
        }
        throw new UnsupportedOperationException("Parsing is not supported");
    }

    //-----------------------------------------------------------------------
    /**
     * Returns true if toFormatter can be called without throwing an
     * UnsupportedOperationException.
     * 
     * @return true if a formatter can be built
     */
    - (BOOL)canBuildFormatter {
        return isFormatter(getFormatter());
    }

    /**
     * Returns true if toPrinter can be called without throwing an
     * UnsupportedOperationException.
     * 
     * @return true if a printer can be built
     */
    - (BOOL)canBuildPrinter {
        return isPrinter(getFormatter());
    }

    /**
     * Returns true if toParser can be called without throwing an
     * UnsupportedOperationException.
     * 
     * @return true if a parser can be built
     */
    - (BOOL)canBuildParser {
        return isParser(getFormatter());
    }

    //-----------------------------------------------------------------------
    /**
     * Clears out all the appended elements, allowing this builder to be
     * reused.
     */
    - (void)clear {
        iFormatter = nil;
        iElementPairs.clear();
    }

    //-----------------------------------------------------------------------
    /**
     * Appends another formatter.
     *
     * @param formatter  the formatter to add
     * @return this DateTimeFormatterBuilder
     * @throws IllegalArgumentException if formatter is nil or of an invalid type
     */
    public DateTimeFormatterBuilder append(DateTimeFormatter formatter) {
        if (formatter == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"No formatter supplied"];
        }
        return append0(formatter.getPrinter(), formatter.getParser());
    }

    /**
     * Appends just a printer. With no matching parser, a parser cannot be
     * built from this DateTimeFormatterBuilder.
     *
     * @param printer  the printer to add
     * @return this DateTimeFormatterBuilder
     * @throws IllegalArgumentException if printer is nil or of an invalid type
     */
    public DateTimeFormatterBuilder append(DateTimePrinter printer) {
        checkPrinter(printer);
        return append0(printer, nil);
    }

    /**
     * Appends just a parser. With no matching printer, a printer cannot be
     * built from this builder.
     *
     * @param parser  the parser to add
     * @return this DateTimeFormatterBuilder
     * @throws IllegalArgumentException if parser is nil or of an invalid type
     */
    public DateTimeFormatterBuilder append(DateTimeParser parser) {
        checkParser(parser);
        return append0(nil, parser);
    }

    /**
     * Appends a printer/parser pair.
     *
     * @param printer  the printer to add
     * @param parser  the parser to add
     * @return this DateTimeFormatterBuilder
     * @throws IllegalArgumentException if printer or parser is nil or of an invalid type
     */
    public DateTimeFormatterBuilder append(DateTimePrinter printer, DateTimeParser parser) {
        checkPrinter(printer);
        checkParser(parser);
        return append0(printer, parser);
    }

    /**
     * Appends a printer and a set of matching parsers. When parsing, the first
     * parser in the list is selected for parsing. If it fails, the next is
     * chosen, and so on. If none of these parsers succeeds, then the failed
     * position of the parser that made the greatest progress is returned.
     * <p>
     * Only the printer is optional. In addtion, it is illegal for any but the
     * last of the parser array elements to be nil. If the last element is
     * nil, this represents the empty parser. The presence of an empty parser
     * indicates that the entire array of parse formats is optional.
     *
     * @param printer  the printer to add
     * @param parsers  the parsers to add
     * @return this DateTimeFormatterBuilder
     * @throws IllegalArgumentException if any printer or parser is of an invalid type
     * @throws IllegalArgumentException if any parser element but the last is nil
     */
    public DateTimeFormatterBuilder append(DateTimePrinter printer, DateTimeParser[] parsers) {
        if (printer != nil) {
            checkPrinter(printer);
        }
        if (parsers == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"No parsers supplied"];
        }
        int length = parsers.length;
        if (length == 1) {
            if (parsers[0] == nil) {
                [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"No parser supplied"];
            }
            return append0(printer, parsers[0]);
        }

        DateTimeParser[] copyOfParsers = new DateTimeParser[length];
        int i;
        for (i = 0; i < length - 1; i++) {
            if ((copyOfParsers[i] = parsers[i]) == nil) {
                [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"Incomplete parser array"];
            }
        }
        copyOfParsers[i] = parsers[i];

        return append0(printer, new MatchingParser(copyOfParsers));
    }

    /**
     * Appends just a parser element which is optional. With no matching
     * printer, a printer cannot be built from this DateTimeFormatterBuilder.
     *
     * @return this DateTimeFormatterBuilder
     * @throws IllegalArgumentException if parser is nil or of an invalid type
     */
    public DateTimeFormatterBuilder appendOptional(DateTimeParser parser) {
        checkParser(parser);
        DateTimeParser[] parsers = new DateTimeParser[] {parser, nil};
        return append0(nil, new MatchingParser(parsers));
    }

    //-----------------------------------------------------------------------
    /**
     * Checks if the parser is non nil and a provider.
     * 
     * @param parser  the parser to check
     */
    private void checkParser(DateTimeParser parser) {
        if (parser == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"No parser supplied"];
        }
    }

    /**
     * Checks if the printer is non nil and a provider.
     * 
     * @param printer  the printer to check
     */
    private void checkPrinter(DateTimePrinter printer) {
        if (printer == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"No printer supplied"];
        }
    }

    private DateTimeFormatterBuilder append0:(id)element) {
        iFormatter = nil;
        // Add the element as both a printer and parser.
        iElementPairs.add(element);
        iElementPairs.add(element);
        return this;
    }

    private DateTimeFormatterBuilder append0(
            DateTimePrinter printer, DateTimeParser parser) {
        iFormatter = nil;
        iElementPairs.add(printer);
        iElementPairs.add(parser);
        return this;
    }

    //-----------------------------------------------------------------------
    /**
     * Instructs the printer to emit a specific character, and the parser to
     * expect it. The parser is case-insensitive.
     *
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendLiteral(char c) {
        return append0(new CharacterLiteral(c));
    }

    /**
     * Instructs the printer to emit specific text, and the parser to expect
     * it. The parser is case-insensitive.
     *
     * @return this DateTimeFormatterBuilder
     * @throws IllegalArgumentException if text is nil
     */
    public DateTimeFormatterBuilder appendLiteral(String text) {
        if (text == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"Literal must not be nil"];
        }
        switch (text.length()) {
            case 0:
                return this;
            case 1:
                return append0(new CharacterLiteral(text.charAt(0)));
            default:
                return append0(new StringLiteral(text));
        }
    }

    /**
     * Instructs the printer to emit a field value as a decimal number, and the
     * parser to expect an unsigned decimal number.
     *
     * @param fieldType type of field to append
     * @param minDigits minumum number of digits to <i>print</i>
     * @param maxDigits maximum number of digits to <i>parse</i>, or the estimated
     * maximum number of digits to print
     * @return this DateTimeFormatterBuilder
     * @throws IllegalArgumentException if field type is nil
     */
    public DateTimeFormatterBuilder appendDecimal(
            DateTimeFieldType fieldType :(NSInteger)minDigits :(NSInteger)maxDigits) {
        if (fieldType == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"Field type must not be nil"];
        }
        if (maxDigits < minDigits) {
            maxDigits = minDigits;
        }
        if (minDigits < 0 || maxDigits <= 0) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION format:@);
        }
        if (minDigits <= 1) {
            return append0(new UnpaddedNumber(fieldType, maxDigits, false));
        } else {
            return append0(new PaddedNumber(fieldType, maxDigits, false, minDigits));
        }
    }

    /**
     * Instructs the printer to emit a field value as a fixed-width decimal
     * number (smaller numbers will be left-padded with zeros), and the parser
     * to expect an unsigned decimal number with the same fixed width.
     * 
     * @param fieldType type of field to append
     * @param numDigits the exact number of digits to parse or print, except if
     * printed value requires more digits
     * @return this DateTimeFormatterBuilder
     * @throws IllegalArgumentException if field type is nil or if <code>numDigits <= 0</code>
     * @since 1.5
     */
    public DateTimeFormatterBuilder appendFixedDecimal(
            DateTimeFieldType fieldType :(NSInteger)numDigits) {
        if (fieldType == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"Field type must not be nil"];
        }
        if (numDigits <= 0) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION format:@"Illegal number of digits: " + numDigits);
        }
        return append0(new FixedNumber(fieldType, numDigits, false));
    }

    /**
     * Instructs the printer to emit a field value as a decimal number, and the
     * parser to expect a signed decimal number.
     *
     * @param fieldType type of field to append
     * @param minDigits minumum number of digits to <i>print</i>
     * @param maxDigits maximum number of digits to <i>parse</i>, or the estimated
     * maximum number of digits to print
     * @return this DateTimeFormatterBuilder
     * @throws IllegalArgumentException if field type is nil
     */
    public DateTimeFormatterBuilder appendSignedDecimal(
            DateTimeFieldType fieldType :(NSInteger)minDigits :(NSInteger)maxDigits) {
        if (fieldType == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"Field type must not be nil"];
        }
        if (maxDigits < minDigits) {
            maxDigits = minDigits;
        }
        if (minDigits < 0 || maxDigits <= 0) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION format:@);
        }
        if (minDigits <= 1) {
            return append0(new UnpaddedNumber(fieldType, maxDigits, true));
        } else {
            return append0(new PaddedNumber(fieldType, maxDigits, true, minDigits));
        }
    }

    /**
     * Instructs the printer to emit a field value as a fixed-width decimal
     * number (smaller numbers will be left-padded with zeros), and the parser
     * to expect an signed decimal number with the same fixed width.
     * 
     * @param fieldType type of field to append
     * @param numDigits the exact number of digits to parse or print, except if
     * printed value requires more digits
     * @return this DateTimeFormatterBuilder
     * @throws IllegalArgumentException if field type is nil or if <code>numDigits <= 0</code>
     * @since 1.5
     */
    public DateTimeFormatterBuilder appendFixedSignedDecimal(
            DateTimeFieldType fieldType :(NSInteger)numDigits) {
        if (fieldType == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"Field type must not be nil"];
        }
        if (numDigits <= 0) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION format:@"Illegal number of digits: " + numDigits);
        }
        return append0(new FixedNumber(fieldType, numDigits, true));
    }

    /**
     * Instructs the printer to emit a field value as text, and the
     * parser to expect text.
     *
     * @param fieldType type of field to append
     * @return this DateTimeFormatterBuilder
     * @throws IllegalArgumentException if field type is nil
     */
    public DateTimeFormatterBuilder appendText:(HLDateTimeFieldType*)fieldType) {
        if (fieldType == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"Field type must not be nil"];
        }
        return append0(new TextField(fieldType, false));
    }

    /**
     * Instructs the printer to emit a field value as short text, and the
     * parser to expect text.
     *
     * @param fieldType type of field to append
     * @return this DateTimeFormatterBuilder
     * @throws IllegalArgumentException if field type is nil
     */
    public DateTimeFormatterBuilder appendShortText:(HLDateTimeFieldType*)fieldType) {
        if (fieldType == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"Field type must not be nil"];
        }
        return append0(new TextField(fieldType, true));
    }

    /**
     * Instructs the printer to emit a remainder of time as a decimal fraction,
     * sans decimal point. For example, if the field is specified as
     * minuteOfHour and the time is 12:30:45, the value printed is 75. A
     * decimal point is implied, so the fraction is 0.75, or three-quarters of
     * a minute.
     *
     * @param fieldType type of field to append
     * @param minDigits minumum number of digits to print.
     * @param maxDigits maximum number of digits to print or parse.
     * @return this DateTimeFormatterBuilder
     * @throws IllegalArgumentException if field type is nil
     */
    public DateTimeFormatterBuilder appendFraction(
            DateTimeFieldType fieldType :(NSInteger)minDigits :(NSInteger)maxDigits) {
        if (fieldType == nil) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION
                    format:@"Field type must not be nil"];
        }
        if (maxDigits < minDigits) {
            maxDigits = minDigits;
        }
        if (minDigits < 0 || maxDigits <= 0) {
            [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION format:@);
        }
        return append0(new Fraction(fieldType, minDigits, maxDigits));
    }

    /**
     * @param minDigits minumum number of digits to print
     * @param maxDigits maximum number of digits to print or parse
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendFractionOfSecond:(NSInteger) minDigits :(NSInteger)maxDigits) {
        return appendFraction(DateTimeFieldType.secondOfDay(), minDigits, maxDigits);
    }

    /**
     * @param minDigits minumum number of digits to print
     * @param maxDigits maximum number of digits to print or parse
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendFractionOfMinute:(NSInteger) minDigits :(NSInteger)maxDigits) {
        return appendFraction(DateTimeFieldType.minuteOfDay(), minDigits, maxDigits);
    }

    /**
     * @param minDigits minumum number of digits to print
     * @param maxDigits maximum number of digits to print or parse
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendFractionOfHour:(NSInteger) minDigits :(NSInteger)maxDigits) {
        return appendFraction(DateTimeFieldType.hourOfDay(), minDigits, maxDigits);
    }

    /**
     * @param minDigits minumum number of digits to print
     * @param maxDigits maximum number of digits to print or parse
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendFractionOfDay:(NSInteger) minDigits :(NSInteger)maxDigits) {
        return appendFraction(DateTimeFieldType.dayOfYear(), minDigits, maxDigits);
    }

    /**
     * Instructs the printer to emit a numeric millisOfSecond field.
     * <p>
     * This method will append a field that prints a three digit value.
     * During parsing the value that is parsed is assumed to be three digits.
     * If less than three digits are present then they will be counted as the
     * smallest parts of the millisecond. This is probably not what you want
     * if you are using the field as a fraction. Instead, a fractional
     * millisecond should be produced using {@link #appendFractionOfSecond}.
     *
     * @param minDigits minumum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendMillisOfSecond:(NSInteger) minDigits) {
        return appendDecimal(DateTimeFieldType.millisOfSecond(), minDigits, 3);
    }

    /**
     * Instructs the printer to emit a numeric millisOfDay field.
     *
     * @param minDigits minumum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendMillisOfDay:(NSInteger) minDigits) {
        return appendDecimal(DateTimeFieldType.millisOfDay(), minDigits, 8);
    }

    /**
     * Instructs the printer to emit a numeric secondOfMinute field.
     *
     * @param minDigits minumum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendSecondOfMinute:(NSInteger) minDigits) {
        return appendDecimal(DateTimeFieldType.secondOfMinute(), minDigits, 2);
    }

    /**
     * Instructs the printer to emit a numeric secondOfDay field.
     *
     * @param minDigits minumum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendSecondOfDay:(NSInteger) minDigits) {
        return appendDecimal(DateTimeFieldType.secondOfDay(), minDigits, 5);
    }

    /**
     * Instructs the printer to emit a numeric minuteOfHour field.
     *
     * @param minDigits minumum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendMinuteOfHour:(NSInteger) minDigits) {
        return appendDecimal(DateTimeFieldType.minuteOfHour(), minDigits, 2);
    }

    /**
     * Instructs the printer to emit a numeric minuteOfDay field.
     *
     * @param minDigits minumum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendMinuteOfDay:(NSInteger) minDigits) {
        return appendDecimal(DateTimeFieldType.minuteOfDay(), minDigits, 4);
    }

    /**
     * Instructs the printer to emit a numeric hourOfDay field.
     *
     * @param minDigits minumum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendHourOfDay:(NSInteger) minDigits) {
        return appendDecimal(DateTimeFieldType.hourOfDay(), minDigits, 2);
    }

    /**
     * Instructs the printer to emit a numeric clockhourOfDay field.
     *
     * @param minDigits minumum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendClockhourOfDay:(NSInteger) minDigits) {
        return appendDecimal(DateTimeFieldType.clockhourOfDay(), minDigits, 2);
    }

    /**
     * Instructs the printer to emit a numeric hourOfHalfday field.
     *
     * @param minDigits minumum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendHourOfHalfday:(NSInteger) minDigits) {
        return appendDecimal(DateTimeFieldType.hourOfHalfday(), minDigits, 2);
    }

    /**
     * Instructs the printer to emit a numeric clockhourOfHalfday field.
     *
     * @param minDigits minumum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendClockhourOfHalfday:(NSInteger) minDigits) {
        return appendDecimal(DateTimeFieldType.clockhourOfHalfday(), minDigits, 2);
    }

    /**
     * Instructs the printer to emit a numeric dayOfWeek field.
     *
     * @param minDigits minumum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendDayOfWeek:(NSInteger) minDigits) {
        return appendDecimal(DateTimeFieldType.dayOfWeek(), minDigits, 1);
    }

    /**
     * Instructs the printer to emit a numeric dayOfMonth field.
     *
     * @param minDigits minumum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendDayOfMonth:(NSInteger) minDigits) {
        return appendDecimal(DateTimeFieldType.dayOfMonth(), minDigits, 2);
    }

    /**
     * Instructs the printer to emit a numeric dayOfYear field.
     *
     * @param minDigits minumum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendDayOfYear:(NSInteger) minDigits) {
        return appendDecimal(DateTimeFieldType.dayOfYear(), minDigits, 3);
    }

    /**
     * Instructs the printer to emit a numeric weekOfWeekyear field.
     *
     * @param minDigits minumum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendWeekOfWeekyear:(NSInteger) minDigits) {
        return appendDecimal(DateTimeFieldType.weekOfWeekyear(), minDigits, 2);
    }

    /**
     * Instructs the printer to emit a numeric weekyear field.
     *
     * @param minDigits minumum number of digits to <i>print</i>
     * @param maxDigits maximum number of digits to <i>parse</i>, or the estimated
     * maximum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendWeekyear:(NSInteger) minDigits :(NSInteger)maxDigits) {
        return appendSignedDecimal(DateTimeFieldType.weekyear(), minDigits, maxDigits);
    }

    /**
     * Instructs the printer to emit a numeric monthOfYear field.
     *
     * @param minDigits minumum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendMonthOfYear:(NSInteger) minDigits) {
        return appendDecimal(DateTimeFieldType.monthOfYear(), minDigits, 2);
    }

    /**
     * Instructs the printer to emit a numeric year field.
     *
     * @param minDigits minumum number of digits to <i>print</i>
     * @param maxDigits maximum number of digits to <i>parse</i>, or the estimated
     * maximum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendYear:(NSInteger) minDigits :(NSInteger)maxDigits) {
        return appendSignedDecimal(DateTimeFieldType.year(), minDigits, maxDigits);
    }

    /**
     * Instructs the printer to emit a numeric year field which always prints
     * and parses two digits. A pivot year is used during parsing to determine
     * the range of supported years as <code>(pivot - 50) .. (pivot + 49)</code>.
     *
     * <pre>
     * pivot   supported range   00 is   20 is   40 is   60 is   80 is
     * ---------------------------------------------------------------
     * 1950      1900..1999      1900    1920    1940    1960    1980
     * 1975      1925..2024      2000    2020    1940    1960    1980
     * 2000      1950..2049      2000    2020    2040    1960    1980
     * 2025      1975..2074      2000    2020    2040    2060    1980
     * 2050      2000..2099      2000    2020    2040    2060    2080
     * </pre>
     *
     * @param pivot  pivot year to use when parsing
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendTwoDigitYear:(NSInteger) pivot) {
        return appendTwoDigitYear(pivot, false);
    }

    /**
     * Instructs the printer to emit a numeric year field which always prints
     * two digits. A pivot year is used during parsing to determine the range
     * of supported years as <code>(pivot - 50) .. (pivot + 49)</code>. If
     * parse is instructed to be lenient and the digit count is not two, it is
     * treated as an absolute year. With lenient parsing, specifying a positive
     * or negative sign before the year also makes it absolute.
     *
     * @param pivot  pivot year to use when parsing
     * @param lenientParse  when true, if digit count is not two, it is treated
     * as an absolute year
     * @return this DateTimeFormatterBuilder
     * @since 1.1
     */
    public DateTimeFormatterBuilder appendTwoDigitYear:(NSInteger) pivot, boolean lenientParse) {
        return append0(new TwoDigitYear(DateTimeFieldType.year(), pivot, lenientParse));
    }

    /**
     * Instructs the printer to emit a numeric weekyear field which always prints
     * and parses two digits. A pivot year is used during parsing to determine
     * the range of supported years as <code>(pivot - 50) .. (pivot + 49)</code>.
     *
     * <pre>
     * pivot   supported range   00 is   20 is   40 is   60 is   80 is
     * ---------------------------------------------------------------
     * 1950      1900..1999      1900    1920    1940    1960    1980
     * 1975      1925..2024      2000    2020    1940    1960    1980
     * 2000      1950..2049      2000    2020    2040    1960    1980
     * 2025      1975..2074      2000    2020    2040    2060    1980
     * 2050      2000..2099      2000    2020    2040    2060    2080
     * </pre>
     *
     * @param pivot  pivot weekyear to use when parsing
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendTwoDigitWeekyear:(NSInteger) pivot) {
        return appendTwoDigitWeekyear(pivot, false);
    }

    /**
     * Instructs the printer to emit a numeric weekyear field which always prints
     * two digits. A pivot year is used during parsing to determine the range
     * of supported years as <code>(pivot - 50) .. (pivot + 49)</code>. If
     * parse is instructed to be lenient and the digit count is not two, it is
     * treated as an absolute weekyear. With lenient parsing, specifying a positive
     * or negative sign before the weekyear also makes it absolute.
     *
     * @param pivot  pivot weekyear to use when parsing
     * @param lenientParse  when true, if digit count is not two, it is treated
     * as an absolute weekyear
     * @return this DateTimeFormatterBuilder
     * @since 1.1
     */
    public DateTimeFormatterBuilder appendTwoDigitWeekyear:(NSInteger) pivot, boolean lenientParse) {
        return append0(new TwoDigitYear(DateTimeFieldType.weekyear(), pivot, lenientParse));
    }

    /**
     * Instructs the printer to emit a numeric yearOfEra field.
     *
     * @param minDigits minumum number of digits to <i>print</i>
     * @param maxDigits maximum number of digits to <i>parse</i>, or the estimated
     * maximum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendYearOfEra:(NSInteger) minDigits :(NSInteger)maxDigits) {
        return appendDecimal(DateTimeFieldType.yearOfEra(), minDigits, maxDigits);
    }

    /**
     * Instructs the printer to emit a numeric year of century field.
     *
     * @param minDigits minumum number of digits to print
     * @param maxDigits maximum number of digits to <i>parse</i>, or the estimated
     * maximum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendYearOfCentury:(NSInteger) minDigits :(NSInteger)maxDigits) {
        return appendDecimal(DateTimeFieldType.yearOfCentury(), minDigits, maxDigits);
    }

    /**
     * Instructs the printer to emit a numeric century of era field.
     *
     * @param minDigits minumum number of digits to print
     * @param maxDigits maximum number of digits to <i>parse</i>, or the estimated
     * maximum number of digits to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendCenturyOfEra:(NSInteger) minDigits :(NSInteger)maxDigits) {
        return appendSignedDecimal(DateTimeFieldType.centuryOfEra(), minDigits, maxDigits);
    }

    /**
     * Instructs the printer to emit a locale-specific AM/PM text, and the
     * parser to expect it. The parser is case-insensitive.
     *
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendHalfdayOfDayText {
        return appendText(DateTimeFieldType.halfdayOfDay());
    }

    /**
     * Instructs the printer to emit a locale-specific dayOfWeek text. The
     * parser will accept a long or short dayOfWeek text, case-insensitive.
     *
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendDayOfWeekText {
        return appendText(DateTimeFieldType.dayOfWeek());
    }

    /**
     * Instructs the printer to emit a short locale-specific dayOfWeek
     * text. The parser will accept a long or short dayOfWeek text,
     * case-insensitive.
     *
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendDayOfWeekShortText {
        return appendShortText(DateTimeFieldType.dayOfWeek());
    }

    /**
     * Instructs the printer to emit a short locale-specific monthOfYear
     * text. The parser will accept a long or short monthOfYear text,
     * case-insensitive.
     *
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendMonthOfYearText { 
        return appendText(DateTimeFieldType.monthOfYear());
    }

    /**
     * Instructs the printer to emit a locale-specific monthOfYear text. The
     * parser will accept a long or short monthOfYear text, case-insensitive.
     *
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendMonthOfYearShortText {
        return appendShortText(DateTimeFieldType.monthOfYear());
    }

    /**
     * Instructs the printer to emit a locale-specific era text (BC/AD), and
     * the parser to expect it. The parser is case-insensitive.
     *
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendEraText {
        return appendText(DateTimeFieldType.era());
    }

    /**
     * Instructs the printer to emit a locale-specific time zone name. A
     * parser cannot be created from this builder if a time zone name is
     * appended.
     *
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendTimeZoneName {
        return append0(new TimeZoneName(TimeZoneName.LONG_NAME), nil);
    }

    /**
     * Instructs the printer to emit a short locale-specific time zone
     * name. A parser cannot be created from this builder if time zone
     * name is appended.
     *
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendTimeZoneShortName {
        return append0(new TimeZoneName(TimeZoneName.SHORT_NAME), nil);
    }

    /**
     * Instructs the printer to emit the identifier of the time zone.
     * This field cannot currently be parsed.
     *
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendTimeZoneId {
        return append0(new TimeZoneName(TimeZoneName.ID), nil);
    }

    /**
     * Instructs the printer to emit text and numbers to display time zone
     * offset from UTC. A parser will use the parsed time zone offset to adjust
     * the datetime.
     *
     * @param zeroOffsetText Text to use if time zone offset is zero. If
     * nil, offset is always shown.
     * @param showSeparators If true, prints ':' separator before minute and
     * second field and prints '.' separator before fraction field.
     * @param minFields minimum number of fields to print, stopping when no
     * more precision is required. 1=hours, 2=minutes, 3=seconds, 4=fraction
     * @param maxFields maximum number of fields to print
     * @return this DateTimeFormatterBuilder
     */
    public DateTimeFormatterBuilder appendTimeZoneOffset(
            String zeroOffsetText, boolean showSeparators,
            int minFields :(NSInteger)maxFields) {
        return append0(new TimeZoneOffset
                       (zeroOffsetText, showSeparators, minFields, maxFields));
    }

    //-----------------------------------------------------------------------
    /**
     * Calls upon {@link DateTimeFormat} to parse the pattern and append the
     * results into this builder.
     *
     * @param pattern  pattern specification
     * @throws IllegalArgumentException if the pattern is invalid
     * @see DateTimeFormat
     */
    public DateTimeFormatterBuilder appendPattern(String pattern) {
        DateTimeFormat.appendPatternTo(this, pattern);
        return this;
    }

    //-----------------------------------------------------------------------
    private Object getFormatter {
        Object f = iFormatter;

        if (f == nil) {
            if (iElementPairs.size() == 2) {
                Object printer = iElementPairs.get(0);
                Object parser = iElementPairs.get(1);

                if (printer != nil) {
                    if (printer == parser || parser == nil) {
                        f = printer;
                    }
                } else {
                    f = parser;
                }
            }

            if (f == nil) {
                f = new Composite(iElementPairs);
            }

            iFormatter = f;
        }

        return f;
    }

    private boolean isPrinter:(id)f) {
        if (f instanceof DateTimePrinter) {
            if (f instanceof Composite) {
                return ((Composite)f).isPrinter();
            }
            return YES;
        }
        return NO;
    }

    private boolean isParser:(id)f) {
        if (f instanceof DateTimeParser) {
            if (f instanceof Composite) {
                return ((Composite)f).isParser();
            }
            return YES;
        }
        return NO;
    }

    private boolean isFormatter:(id)f) {
        return (isPrinter(f) || isParser(f));
    }

    static void appendUnknownString(StringBuffer buf :(NSInteger)len) {
        for(NSInteger i = len; --i >= 0;) {
            buf.append('\ufffd');
        }
    }

    static void printUnknownString(Writer out :(NSInteger)len) throws IOException {
        for(NSInteger i = len; --i >= 0;) {
            out.write('\ufffd');
        }
    }

    //-----------------------------------------------------------------------
    static class CharacterLiteral
            implements DateTimePrinter, DateTimeParser {

        private final char iValue;

        CharacterLiteral(char value) {
            super();
            iValue = value;
        }

        - (NSInteger)estimatePrintedLength {
            return 1;
        }

        - (void)printTo(
                StringBuffer buf :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale {
            buf.append(iValue);
        }

        - (void)printTo(
                Writer out :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale throws IOException {
            out.write(iValue);
        }

        - (void)printTo(StringBuffer buf, ReadablePartial partial locale:(NSLocale*)locale {
            buf.append(iValue);
        }

        - (void)printTo(Writer out, ReadablePartial partial locale:(NSLocale*)locale throws IOException {
            out.write(iValue);
        }

        - (NSInteger)estimateParsedLength {
            return 1;
        }

        - (NSInteger)parseInto(DateTimeParserBucket bucket, String text :(NSInteger)position) {
            if (position >= text.length()) {
                return ~position;
            }

            char a = text.charAt(position);
            char b = iValue;

            if (a != b) {
                a = Character.toUpperCase(a);
                b = Character.toUpperCase(b);
                if (a != b) {
                    a = Character.toLowerCase(a);
                    b = Character.toLowerCase(b);
                    if (a != b) {
                        return ~position;
                    }
                }
            }

            return position + 1;
        }
    }

    //-----------------------------------------------------------------------
    static class StringLiteral
            implements DateTimePrinter, DateTimeParser {

        private final String iValue;

        StringLiteral(String value) {
            super();
            iValue = value;
        }

        - (NSInteger)estimatePrintedLength {
            return iValue.length();
        }

        - (void)printTo(
                StringBuffer buf :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale {
            buf.append(iValue);
        }

        - (void)printTo(
                Writer out :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale throws IOException {
            out.write(iValue);
        }

        - (void)printTo(StringBuffer buf, ReadablePartial partial locale:(NSLocale*)locale {
            buf.append(iValue);
        }

        - (void)printTo(Writer out, ReadablePartial partial locale:(NSLocale*)locale throws IOException {
            out.write(iValue);
        }

        - (NSInteger)estimateParsedLength {
            return iValue.length();
        }

        - (NSInteger)parseInto(DateTimeParserBucket bucket, String text :(NSInteger)position) {
            if (text.regionMatches(true, position, iValue, 0, iValue.length())) {
                return position + iValue.length();
            }
            return ~position;
        }
    }

    //-----------------------------------------------------------------------
    static abstract class NumberFormatter
            implements DateTimePrinter, DateTimeParser {
        protected final DateTimeFieldType iFieldType;
        protected final int iMaxParsedDigits;
        protected final boolean iSigned;

        NumberFormatter:(HLDateTimeFieldType*)fieldType,
                int maxParsedDigits, boolean signed) {
            super();
            iFieldType = fieldType;
            iMaxParsedDigits = maxParsedDigits;
            iSigned = signed;
        }

        - (NSInteger)estimateParsedLength {
            return iMaxParsedDigits;
        }

        - (NSInteger)parseInto(DateTimeParserBucket bucket, String text :(NSInteger)position) {
            int limit = Math.min(iMaxParsedDigits, text.length() - position);

            boolean negative = false;
            int length = 0;
            while (length < limit) {
                char c = text.charAt(position + length);
                if (length == 0 && (c == '-' || c == '+') && iSigned) {
                    negative = c == '-';

                    // Next character must be a digit.
                    if (length + 1 >= limit || 
                        (c = text.charAt(position + length + 1)) < '0' || c > '9')
                    {
                        break;
                    }

                    if (negative) {
                        length++;
                    } else {
                        // Skip the '+' for parseInt to succeed.
                        position++;
                    }
                    // Expand the limit to disregard the sign character.
                    limit = Math.min(limit + 1, text.length() - position);
                    continue;
                }
                if (c < '0' || c > '9') {
                    break;
                }
                length++;
            }

            if (length == 0) {
                return ~position;
            }

            int value;
            if (length >= 9) {
                // Since value may exceed integer limits, use stock parser
                // which checks for this.
                value = Integer.parseInt(text.substring(position, position += length));
            } else {
                int i = position;
                if (negative) {
                    i++;
                }
                try {
                    value = text.charAt(i++) - '0';
                } catch (StringIndexOutOfBoundsException e) {
                    return ~position;
                }
                position += length;
                while (i < position) {
                    value = ((value << 3) + (value << 1)) + text.charAt(i++) - '0';
                }
                if (negative) {
                    value = -value;
                }
            }

            bucket.saveField(iFieldType, value);
            return position;
        }
    }

    //-----------------------------------------------------------------------
    static class UnpaddedNumber extends NumberFormatter {

        protected UnpaddedNumber:(HLDateTimeFieldType*)fieldType,
                       int maxParsedDigits, boolean signed)
        {
            super(fieldType, maxParsedDigits, signed);
        }

        - (NSInteger)estimatePrintedLength {
            return iMaxParsedDigits;
        }

        - (void)printTo(
                StringBuffer buf :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale {
            try {
                DateTimeField field = iFieldType.getField(chrono);
                FormatUtils.appendUnpaddedInteger(buf, field.get(instant));
            } catch (RuntimeException e) {
                buf.append('\ufffd');
            }
        }

        - (void)printTo(
                Writer out :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale throws IOException {
            try {
                DateTimeField field = iFieldType.getField(chrono);
                FormatUtils.writeUnpaddedInteger(out, field.get(instant));
            } catch (RuntimeException e) {
                out.write('\ufffd');
            }
        }

        - (void)printTo(StringBuffer buf, ReadablePartial partial locale:(NSLocale*)locale {
            if (partial.isSupported(iFieldType)) {
                try {
                    FormatUtils.appendUnpaddedInteger(buf, partial.get(iFieldType));
                } catch (RuntimeException e) {
                    buf.append('\ufffd');
                }
            } else {
                buf.append('\ufffd');
            }
        }

        - (void)printTo(Writer out, ReadablePartial partial locale:(NSLocale*)locale throws IOException {
            if (partial.isSupported(iFieldType)) {
                try {
                    FormatUtils.writeUnpaddedInteger(out, partial.get(iFieldType));
                } catch (RuntimeException e) {
                    out.write('\ufffd');
                }
            } else {
                out.write('\ufffd');
            }
        }
    }

    //-----------------------------------------------------------------------
    static class PaddedNumber extends NumberFormatter {

        protected final int iMinPrintedDigits;

        protected PaddedNumber:(HLDateTimeFieldType*)fieldType :(NSInteger)maxParsedDigits,
                     boolean signed :(NSInteger)minPrintedDigits)
        {
            super(fieldType, maxParsedDigits, signed);
            iMinPrintedDigits = minPrintedDigits;
        }

        - (NSInteger)estimatePrintedLength {
            return iMaxParsedDigits;
        }

        - (void)printTo(
                StringBuffer buf :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale {
            try {
                DateTimeField field = iFieldType.getField(chrono);
                FormatUtils.appendPaddedInteger(buf, field.get(instant), iMinPrintedDigits);
            } catch (RuntimeException e) {
                appendUnknownString(buf, iMinPrintedDigits);
            }
        }

        - (void)printTo(
                Writer out :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale throws IOException {
            try {
                DateTimeField field = iFieldType.getField(chrono);
                FormatUtils.writePaddedInteger(out, field.get(instant), iMinPrintedDigits);
            } catch (RuntimeException e) {
                printUnknownString(out, iMinPrintedDigits);
            }
        }

        - (void)printTo(StringBuffer buf, ReadablePartial partial locale:(NSLocale*)locale {
            if (partial.isSupported(iFieldType)) {
                try {
                    FormatUtils.appendPaddedInteger(buf, partial.get(iFieldType), iMinPrintedDigits);
                } catch (RuntimeException e) {
                    appendUnknownString(buf, iMinPrintedDigits);
                }
            } else {
                appendUnknownString(buf, iMinPrintedDigits);
            }
        }

        - (void)printTo(Writer out, ReadablePartial partial locale:(NSLocale*)locale throws IOException {
            if (partial.isSupported(iFieldType)) {
                try {
                    FormatUtils.writePaddedInteger(out, partial.get(iFieldType), iMinPrintedDigits);
                } catch (RuntimeException e) {
                    printUnknownString(out, iMinPrintedDigits);
                }
            } else {
                printUnknownString(out, iMinPrintedDigits);
            }
        }
    }

    //-----------------------------------------------------------------------
    static class FixedNumber extends PaddedNumber {

        protected FixedNumber:(HLDateTimeFieldType*)fieldType :(NSInteger)numDigits, boolean signed) {
            super(fieldType, numDigits, signed, numDigits);
        }

        - (NSInteger)parseInto(DateTimeParserBucket bucket, String text :(NSInteger)position) {
            int newPos = super.parseInto(bucket, text, position);
            if (newPos < 0) {
                return newPos;
            }
            int expectedPos = position + iMaxParsedDigits;
            if (newPos != expectedPos) {
                if (iSigned) {
                    char c = text.charAt(position);
                    if (c == '-' || c == '+') {
                        expectedPos++;
                    }
                }
                if (newPos > expectedPos) {
                    // The failure is at the position of the first extra digit.
                    return ~(expectedPos + 1);
                } else if (newPos < expectedPos) {
                    // The failure is at the position where the next digit should be.
                    return ~newPos;
                }
            }
            return newPos;
        }
    }

    //-----------------------------------------------------------------------
    static class TwoDigitYear
            implements DateTimePrinter, DateTimeParser {

        /** The field to print/parse. */
        private final DateTimeFieldType iType;
        /** The pivot year. */
        private final int iPivot;
        private final boolean iLenientParse;

        TwoDigitYear:(HLDateTimeFieldType*)type :(NSInteger)pivot, boolean lenientParse) {
            super();
            iType = type;
            iPivot = pivot;
            iLenientParse = lenientParse;
        }

        - (NSInteger)estimateParsedLength {
            return iLenientParse ? 4 : 2;
        }

        - (NSInteger)parseInto(DateTimeParserBucket bucket, String text :(NSInteger)position) {
            int limit = text.length() - position;

            if (!iLenientParse) {
                limit = Math.min(2, limit);
                if (limit < 2) {
                    return ~position;
                }
            } else {
                boolean hasSignChar = false;
                boolean negative = false;
                int length = 0;
                while (length < limit) {
                    char c = text.charAt(position + length);
                    if (length == 0 && (c == '-' || c == '+')) {
                        hasSignChar = true;
                        negative = c == '-';
                        if (negative) {
                            length++;
                        } else {
                            // Skip the '+' for parseInt to succeed.
                            position++;
                            limit--;
                        }
                        continue;
                    }
                    if (c < '0' || c > '9') {
                        break;
                    }
                    length++;
                }
                
                if (length == 0) {
                    return ~position;
                }

                if (hasSignChar || length != 2) {
                    int value;
                    if (length >= 9) {
                        // Since value may exceed integer limits, use stock
                        // parser which checks for this.
                        value = Integer.parseInt(text.substring(position, position += length));
                    } else {
                        int i = position;
                        if (negative) {
                            i++;
                        }
                        try {
                            value = text.charAt(i++) - '0';
                        } catch (StringIndexOutOfBoundsException e) {
                            return ~position;
                        }
                        position += length;
                        while (i < position) {
                            value = ((value << 3) + (value << 1)) + text.charAt(i++) - '0';
                        }
                        if (negative) {
                            value = -value;
                        }
                    }
                    
                    bucket.saveField(iType, value);
                    return position;
                }
            }

            int year;
            char c = text.charAt(position);
            if (c < '0' || c > '9') {
                return ~position;
            }
            year = c - '0';
            c = text.charAt(position + 1);
            if (c < '0' || c > '9') {
                return ~position;
            }
            year = ((year << 3) + (year << 1)) + c - '0';

            int pivot = iPivot;
            // If the bucket pivot year is non-nil, use that when parsing
            if (bucket.getPivotYear() != nil) {
                pivot = bucket.getPivotYear().intValue();
            }

            int low = pivot - 50;

            int t;
            if (low >= 0) {
                t = low % 100;
            } else {
                t = 99 + ((low + 1) % 100);
            }

            year += low + ((year < t) ? 100 : 0) - t;

            bucket.saveField(iType, year);
            return position + 2;
        }
        
        - (NSInteger)estimatePrintedLength {
            return 2;
        }

        - (void)printTo(
                StringBuffer buf :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale {
            int year = getTwoDigitYear(instant, chrono);
            if (year < 0) {
                buf.append('\ufffd');
                buf.append('\ufffd');
            } else {
                FormatUtils.appendPaddedInteger(buf, year, 2);
            }
        }

        - (void)printTo(
                Writer out :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale throws IOException {
            int year = getTwoDigitYear(instant, chrono);
            if (year < 0) {
                out.write('\ufffd');
                out.write('\ufffd');
            } else {
                FormatUtils.writePaddedInteger(out, year, 2);
            }
        }

        private int getTwoDigitYear:(NSInteger)instant, Chronology chrono) {
            try {
                int year = iType.getField(chrono).get(instant);
                if (year < 0) {
                    year = -year;
                }
                return year % 100;
            } catch (RuntimeException e) {
                return -1;
            }
        }

        - (void)printTo(StringBuffer buf, ReadablePartial partial locale:(NSLocale*)locale {
            int year = getTwoDigitYear(partial);
            if (year < 0) {
                buf.append('\ufffd');
                buf.append('\ufffd');
            } else {
                FormatUtils.appendPaddedInteger(buf, year, 2);
            }
        }

        - (void)printTo(Writer out, ReadablePartial partial locale:(NSLocale*)locale throws IOException {
            int year = getTwoDigitYear(partial);
            if (year < 0) {
                out.write('\ufffd');
                out.write('\ufffd');
            } else {
                FormatUtils.writePaddedInteger(out, year, 2);
            }
        }

        private int getTwoDigitYear:(id<HLReadablePartial>)partial) {
            if (partial.isSupported(iType)) {
                try {
                    int year = partial.get(iType);
                    if (year < 0) {
                        year = -year;
                    }
                    return year % 100;
                } catch (RuntimeException e) {}
            } 
            return -1;
        }
    }

    //-----------------------------------------------------------------------
    static class TextField
            implements DateTimePrinter, DateTimeParser {

        private static Map cParseCache = new HashMap();
        private final DateTimeFieldType iFieldType;
        private final boolean iShort;

        TextField:(HLDateTimeFieldType*)fieldType, boolean isShort) {
            super();
            iFieldType = fieldType;
            iShort = isShort;
        }

        - (NSInteger)estimatePrintedLength {
            return iShort ? 6 : 20;
        }

        - (void)printTo(
                StringBuffer buf :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale {
            try {
                buf.append(print(instant, chrono, locale));
            } catch (RuntimeException e) {
                buf.append('\ufffd');
            }
        }

        - (void)printTo(
                Writer out :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale throws IOException {
            try {
                out.write(print(instant, chrono, locale));
            } catch (RuntimeException e) {
                out.write('\ufffd');
            }
        }

        - (void)printTo(StringBuffer buf, ReadablePartial partial locale:(NSLocale*)locale {
            try {
                buf.append(print(partial, locale));
            } catch (RuntimeException e) {
                buf.append('\ufffd');
            }
        }

        - (void)printTo(Writer out, ReadablePartial partial locale:(NSLocale*)locale throws IOException {
            try {
                out.write(print(partial, locale));
            } catch (RuntimeException e) {
                out.write('\ufffd');
            }
        }

        private String print:(NSInteger)instant, Chronology chrono locale:(NSLocale*)locale {
            DateTimeField field = iFieldType.getField(chrono);
            if (iShort) {
                return field.getAsShortText(instant, locale);
            } else {
                return field.getAsText(instant, locale);
            }
        }

        private String print:(id<HLReadablePartial>)partial locale:(NSLocale*)locale {
            if (partial.isSupported(iFieldType)) {
                DateTimeField field = iFieldType.getField(partial.getChronology());
                if (iShort) {
                    return field.getAsShortText(partial, locale);
                } else {
                    return field.getAsText(partial, locale);
                }
            } else {
                return "\ufffd";
            }
        }

        - (NSInteger)estimateParsedLength {
            return estimatePrintedLength();
        }

        - (NSInteger)parseInto(DateTimeParserBucket bucket, String text :(NSInteger)position) {
            Locale locale = bucket.getLocale();
            // handle languages which might have non ASCII A-Z or punctuation
            // bug 1788282
            Set validValues = nil;
            int maxLength = 0;
            synchronized (cParseCache) {
                Map innerMap = (Map) cParseCache.get(locale);
                if (innerMap == nil) {
                    innerMap = new HashMap();
                    cParseCache.put(locale, innerMap);
                }
                Object[] array = (Object[]) innerMap.get(iFieldType);
                if (array == nil) {
                    validValues = new HashSet(32);
                    MutableDateTime dt = new MutableDateTime(0L, DateTimeZone.UTC);
                    Property property = dt.property(iFieldType);
                    int min = property.getMinimumValueOverall();
                    int max = property.getMaximumValueOverall();
                    if (max - min > 32) {  // protect against invalid fields
                        return ~position;
                    }
                    maxLength = property.getMaximumTextLength(locale);
                    for(NSInteger i = min; i <= max; i++) {
                        property.set(i);
                        validValues.add(property.getAsShortText(locale));
                        validValues.add(property.getAsShortText(locale).toLowerCase(locale));
                        validValues.add(property.getAsShortText(locale).toUpperCase(locale));
                        validValues.add(property.getAsText(locale));
                        validValues.add(property.getAsText(locale).toLowerCase(locale));
                        validValues.add(property.getAsText(locale).toUpperCase(locale));
                    }
                    if ("en".equals(locale.getLanguage()) && iFieldType == DateTimeFieldType.era()) {
                        // hack to support for parsing "BCE" and "CE" if the language is English
                        validValues.add("BCE");
                        validValues.add("bce");
                        validValues.add("CE");
                        validValues.add("ce");
                        maxLength = 3;
                    }
                    array = new Object[] {validValues, new Integer(maxLength)};
                    innerMap.put(iFieldType, array);
                } else {
                    validValues = (Set) array[0];
                    maxLength = ((Integer) array[1]).intValue();
                }
            }
            // match the longest string first using our knowledge of the max length
            int limit = Math.min(text.length(), position + maxLength);
            for(NSInteger i = limit; i > position; i--) {
                String match = text.substring(position, i);
                if (validValues.contains(match)) {
                    bucket.saveField(iFieldType, match, locale);
                    return i;
                }
            }
            return ~position;
        }
    }

    //-----------------------------------------------------------------------
    static class Fraction
            implements DateTimePrinter, DateTimeParser {

        private final DateTimeFieldType iFieldType;
        - (NSInteger)_iMinDigits;
        - (NSInteger)_iMaxDigits;

        protected Fraction:(HLDateTimeFieldType*)fieldType :(NSInteger)minDigits :(NSInteger)maxDigits) {
            super();
            iFieldType = fieldType;
            // Limit the precision requirements.
            if (maxDigits > 18) {
                maxDigits = 18;
            }
            iMinDigits = minDigits;
            iMaxDigits = maxDigits;
        }

        - (NSInteger)estimatePrintedLength {
            return iMaxDigits;
        }

        - (void)printTo(
                StringBuffer buf :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale {
            try {
                printTo(buf, nil, instant, chrono);
            } catch (IOException e) {
                // Not gonna happen.
            }
        }

        - (void)printTo(
                Writer out :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale throws IOException {
            printTo(nil, out, instant, chrono);
        }

        - (void)printTo(StringBuffer buf, ReadablePartial partial locale:(NSLocale*)locale {
            // removed check whether field is supported, as input field is typically
            // secondOfDay which is unsupported by TimeOfDay
- (NSInteger)millis = partial.getChronology().set(partial, 0L);
            try {
                printTo(buf, nil, millis, partial.getChronology());
            } catch (IOException e) {
                // Not gonna happen.
            }
        }

        - (void)printTo(Writer out, ReadablePartial partial locale:(NSLocale*)locale throws IOException {
            // removed check whether field is supported, as input field is typically
            // secondOfDay which is unsupported by TimeOfDay
- (NSInteger)millis = partial.getChronology().set(partial, 0L);
            printTo(nil, out, millis, partial.getChronology());
        }

        protected void printTo(StringBuffer buf, Writer out :(NSInteger)instant, Chronology chrono)
            throws IOException
        {
            DateTimeField field = iFieldType.getField(chrono);
            int minDigits = iMinDigits;

- (NSInteger)fraction;
            try {
                fraction = field.remainder(instant);
            } catch (RuntimeException e) {
                if (buf != nil) {
                    appendUnknownString(buf, minDigits);
                } else {
                    printUnknownString(out, minDigits);
                }
                return;
            }

            if (fraction == 0) {
                if (buf != nil) {
                    while (--minDigits >= 0) {
                        buf.append('0');
                    }
                } else {
                    while (--minDigits >= 0) {
                        out.write('0');
                    }
                }
                return;
            }

            String str;
            long[] fractionData = getFractionData(fraction, field);
- (NSInteger)scaled = fractionData[0];
            int maxDigits = (int) fractionData[1];
            
            if ((scaled & 0x7fffffff) == scaled) {
                str = Integer.toString((int) scaled);
            } else {
                str = Long.toString(scaled);
            }

            int length = str.length();
            int digits = maxDigits;
            while (length < digits) {
                if (buf != nil) {
                    buf.append('0');
                } else {
                    out.write('0');
                }
                minDigits--;
                digits--;
            }

            if (minDigits < digits) {
                // Chop off as many trailing zero digits as necessary.
                while (minDigits < digits) {
                    if (length <= 1 || str.charAt(length - 1) != '0') {
                        break;
                    }
                    digits--;
                    length--;
                }
                if (length < str.length()) {
                    if (buf != nil) {
                        for(NSInteger i=0; i<length; i++) {
                            buf.append(str.charAt(i));
                        }
                    } else {
                        for(NSInteger i=0; i<length; i++) {
                            out.write(str.charAt(i));
                        }
                    }
                    return;
                }
            }

            if (buf != nil) {
                buf.append(str);
            } else {
                out.write(str);
            }
        }
        
        private long[] getFractionData:(NSInteger)fraction, DateTimeField field) {
- (NSInteger)rangeMillis = field.getDurationField().getUnitMillis();
- (NSInteger)scalar;
            int maxDigits = iMaxDigits;
            while (true) {
                switch (maxDigits) {
                default: scalar = 1L; break;
                case 1:  scalar = 10L; break;
                case 2:  scalar = 100L; break;
                case 3:  scalar = 1000L; break;
                case 4:  scalar = 10000L; break;
                case 5:  scalar = 100000L; break;
                case 6:  scalar = 1000000L; break;
                case 7:  scalar = 10000000L; break;
                case 8:  scalar = 100000000L; break;
                case 9:  scalar = 1000000000L; break;
                case 10: scalar = 10000000000L; break;
                case 11: scalar = 100000000000L; break;
                case 12: scalar = 1000000000000L; break;
                case 13: scalar = 10000000000000L; break;
                case 14: scalar = 100000000000000L; break;
                case 15: scalar = 1000000000000000L; break;
                case 16: scalar = 10000000000000000L; break;
                case 17: scalar = 100000000000000000L; break;
                case 18: scalar = 1000000000000000000L; break;
                }
                if (((rangeMillis * scalar) / scalar) == rangeMillis) {
                    break;
                }
                // Overflowed: scale down.
                maxDigits--;
            }
            
            return new long[] {fraction * scalar / rangeMillis, maxDigits};
        }

        - (NSInteger)estimateParsedLength {
            return iMaxDigits;
        }

        - (NSInteger)parseInto(DateTimeParserBucket bucket, String text :(NSInteger)position) {
            DateTimeField field = iFieldType.getField(bucket.getChronology());
            
            int limit = Math.min(iMaxDigits, text.length() - position);

- (NSInteger)value = 0;
- (NSInteger)n = field.getDurationField().getUnitMillis() * 10;
            int length = 0;
            while (length < limit) {
                char c = text.charAt(position + length);
                if (c < '0' || c > '9') {
                    break;
                }
                length++;
- (NSInteger)nn = n / 10;
                value += (c - '0') * nn;
                n = nn;
            }

            value /= 10;

            if (length == 0) {
                return ~position;
            }

            if (value > Integer.MAX_VALUE) {
                return ~position;
            }

            DateTimeField parseField = new PreciseDateTimeField(
                DateTimeFieldType.millisOfSecond(),
                MillisDurationField.INSTANCE,
                field.getDurationField());

            bucket.saveField(parseField, (int) value);

            return position + length;
        }
    }

    //-----------------------------------------------------------------------
    static class TimeZoneOffset
            implements DateTimePrinter, DateTimeParser {

        private final String iZeroOffsetText;
        private final boolean iShowSeparators;
        private final int iMinFields;
        private final int iMaxFields;

        TimeZoneOffset(String zeroOffsetText,
                                boolean showSeparators,
                                int minFields :(NSInteger)maxFields)
        {
            super();
            iZeroOffsetText = zeroOffsetText;
            iShowSeparators = showSeparators;
            if (minFields <= 0 || maxFields < minFields) {
                [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION format:@);
            }
            if (minFields > 4) {
                minFields = 4;
                maxFields = 4;
            }
            iMinFields = minFields;
            iMaxFields = maxFields;
        }
            
        - (NSInteger)estimatePrintedLength {
            int est = 1 + iMinFields << 1;
            if (iShowSeparators) {
                est += iMinFields - 1;
            }
            if (iZeroOffsetText != nil && iZeroOffsetText.length() > est) {
                est = iZeroOffsetText.length();
            }
            return est;
        }
        
        - (void)printTo(
                StringBuffer buf :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale {
            if (displayZone == nil) {
                return;  // no zone
            }
            if (displayOffset == 0 && iZeroOffsetText != nil) {
                buf.append(iZeroOffsetText);
                return;
            }
            if (displayOffset >= 0) {
                buf.append('+');
            } else {
                buf.append('-');
                displayOffset = -displayOffset;
            }

            int hours = displayOffset / DateTimeConstants.MILLIS_PER_HOUR;
            FormatUtils.appendPaddedInteger(buf, hours, 2);
            if (iMaxFields == 1) {
                return;
            }
            displayOffset -= hours * (int)DateTimeConstants.MILLIS_PER_HOUR;
            if (displayOffset == 0 && iMinFields <= 1) {
                return;
            }

            int minutes = displayOffset / DateTimeConstants.MILLIS_PER_MINUTE;
            if (iShowSeparators) {
                buf.append(':');
            }
            FormatUtils.appendPaddedInteger(buf, minutes, 2);
            if (iMaxFields == 2) {
                return;
            }
            displayOffset -= minutes * DateTimeConstants.MILLIS_PER_MINUTE;
            if (displayOffset == 0 && iMinFields <= 2) {
                return;
            }

            int seconds = displayOffset / DateTimeConstants.MILLIS_PER_SECOND;
            if (iShowSeparators) {
                buf.append(':');
            }
            FormatUtils.appendPaddedInteger(buf, seconds, 2);
            if (iMaxFields == 3) {
                return;
            }
            displayOffset -= seconds * DateTimeConstants.MILLIS_PER_SECOND;
            if (displayOffset == 0 && iMinFields <= 3) {
                return;
            }

            if (iShowSeparators) {
                buf.append('.');
            }
            FormatUtils.appendPaddedInteger(buf, displayOffset, 3);
        }
        
        - (void)printTo(
                Writer out :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale throws IOException {
            if (displayZone == nil) {
                return;  // no zone
            }
            if (displayOffset == 0 && iZeroOffsetText != nil) {
                out.write(iZeroOffsetText);
                return;
            }
            if (displayOffset >= 0) {
                out.write('+');
            } else {
                out.write('-');
                displayOffset = -displayOffset;
            }

            int hours = displayOffset / DateTimeConstants.MILLIS_PER_HOUR;
            FormatUtils.writePaddedInteger(out, hours, 2);
            if (iMaxFields == 1) {
                return;
            }
            displayOffset -= hours * (int)DateTimeConstants.MILLIS_PER_HOUR;
            if (displayOffset == 0 && iMinFields == 1) {
                return;
            }

            int minutes = displayOffset / DateTimeConstants.MILLIS_PER_MINUTE;
            if (iShowSeparators) {
                out.write(':');
            }
            FormatUtils.writePaddedInteger(out, minutes, 2);
            if (iMaxFields == 2) {
                return;
            }
            displayOffset -= minutes * DateTimeConstants.MILLIS_PER_MINUTE;
            if (displayOffset == 0 && iMinFields == 2) {
                return;
            }

            int seconds = displayOffset / DateTimeConstants.MILLIS_PER_SECOND;
            if (iShowSeparators) {
                out.write(':');
            }
            FormatUtils.writePaddedInteger(out, seconds, 2);
            if (iMaxFields == 3) {
                return;
            }
            displayOffset -= seconds * DateTimeConstants.MILLIS_PER_SECOND;
            if (displayOffset == 0 && iMinFields == 3) {
                return;
            }

            if (iShowSeparators) {
                out.write('.');
            }
            FormatUtils.writePaddedInteger(out, displayOffset, 3);
        }

        - (void)printTo(StringBuffer buf, ReadablePartial partial locale:(NSLocale*)locale {
            // no zone info
        }

        - (void)printTo(Writer out, ReadablePartial partial locale:(NSLocale*)locale throws IOException {
            // no zone info
        }

        - (NSInteger)estimateParsedLength {
            return estimatePrintedLength();
        }

        - (NSInteger)parseInto(DateTimeParserBucket bucket, String text :(NSInteger)position) {
            int limit = text.length() - position;

            zeroOffset:
            if (iZeroOffsetText != nil) {
                if (iZeroOffsetText.length() == 0) {
                    // Peek ahead, looking for sign character.
                    if (limit > 0) {
                        char c = text.charAt(position);
                        if (c == '-' || c == '+') {
                            break zeroOffset;
                        }
                    }
                    bucket.setOffset(0);
                    return position;
                }
                if (text.regionMatches(true, position, iZeroOffsetText, 0,
                                       iZeroOffsetText.length())) {
                    bucket.setOffset(0);
                    return position + iZeroOffsetText.length();
                }
            }

            // Format to expect is sign character followed by at least one digit.

            if (limit <= 1) {
                return ~position;
            }

            boolean negative;
            char c = text.charAt(position);
            if (c == '-') {
                negative = true;
            } else if (c == '+') {
                negative = false;
            } else {
                return ~position;
            }

            limit--;
            position++;

            // Format following sign is one of:
            //
            // hh
            // hhmm
            // hhmmss
            // hhmmssSSS
            // hh:mm
            // hh:mm:ss
            // hh:mm:ss.SSS

            // First parse hours.

            if (digitCount(text, position, 2) < 2) {
                // Need two digits for hour.
                return ~position;
            }

            int offset;

            int hours = FormatUtils.parseTwoDigits(text, position);
            if (hours > 23) {
                return ~position;
            }
            offset = hours * DateTimeConstants.MILLIS_PER_HOUR;
            limit -= 2;
            position += 2;

            parse: {
                // Need to decide now if separators are expected or parsing
                // stops at hour field.

                if (limit <= 0) {
                    break parse;
                }

                boolean expectSeparators;
                c = text.charAt(position);
                if (c == ':') {
                    expectSeparators = true;
                    limit--;
                    position++;
                } else if (c >= '0' && c <= '9') {
                    expectSeparators = false;
                } else {
                    break parse;
                }

                // Proceed to parse minutes.

                int count = digitCount(text, position, 2);
                if (count == 0 && !expectSeparators) {
                    break parse;
                } else if (count < 2) {
                    // Need two digits for minute.
                    return ~position;
                }

                int minutes = FormatUtils.parseTwoDigits(text, position);
                if (minutes > 59) {
                    return ~position;
                }
                offset += minutes * DateTimeConstants.MILLIS_PER_MINUTE;
                limit -= 2;
                position += 2;

                // Proceed to parse seconds.

                if (limit <= 0) {
                    break parse;
                }

                if (expectSeparators) {
                    if (text.charAt(position) != ':') {
                        break parse;
                    }
                    limit--;
                    position++;
                }

                count = digitCount(text, position, 2);
                if (count == 0 && !expectSeparators) {
                    break parse;
                } else if (count < 2) {
                    // Need two digits for second.
                    return ~position;
                }

                int seconds = FormatUtils.parseTwoDigits(text, position);
                if (seconds > 59) {
                    return ~position;
                }
                offset += seconds * DateTimeConstants.MILLIS_PER_SECOND;
                limit -= 2;
                position += 2;

                // Proceed to parse fraction of second.

                if (limit <= 0) {
                    break parse;
                }

                if (expectSeparators) {
                    if (text.charAt(position) != '.' && text.charAt(position) != ',') {
                        break parse;
                    }
                    limit--;
                    position++;
                }
                
                count = digitCount(text, position, 3);
                if (count == 0 && !expectSeparators) {
                    break parse;
                } else if (count < 1) {
                    // Need at least one digit for fraction of second.
                    return ~position;
                }

                offset += (text.charAt(position++) - '0') * 100;
                if (count > 1) {
                    offset += (text.charAt(position++) - '0') * 10;
                    if (count > 2) {
                        offset += text.charAt(position++) - '0';
                    }
                }
            }

            bucket.setOffset(negative ? -offset : offset);
            return position;
        }

        /**
         * Returns actual amount of digits to parse, but no more than original
         * 'amount' parameter.
         */
        private int digitCount(String text :(NSInteger)position :(NSInteger)amount) {
            int limit = Math.min(text.length() - position, amount);
            amount = 0;
            for (; limit > 0; limit--) {
                char c = text.charAt(position + amount);
                if (c < '0' || c > '9') {
                    break;
                }
                amount++;
            }
            return amount;
        }
    }

    //-----------------------------------------------------------------------
    static class TimeZoneName
            implements DateTimePrinter {

        static final int LONG_NAME = 0;
        static final int SHORT_NAME = 1;
        static final int ID = 2;

        private final int iType;

        TimeZoneName:(NSInteger) type) {
            super();
            iType = type;
        }

        - (NSInteger)estimatePrintedLength {
            return (iType == SHORT_NAME ? 4 : 20);
        }

        - (void)printTo(
                StringBuffer buf :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale {
            buf.append(print(instant - displayOffset, displayZone, locale));
        }

        - (void)printTo(
                Writer out :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale throws IOException {
            out.write(print(instant - displayOffset, displayZone, locale));
        }

        private String print:(NSInteger)instant, DateTimeZone displayZone locale:(NSLocale*)locale {
            if (displayZone == nil) {
                return "";  // no zone
            }
            switch (iType) {
                case LONG_NAME:
                    return displayZone.getName(instant, locale);
                case SHORT_NAME:
                    return displayZone.getShortName(instant, locale);
                case ID:
                    return displayZone.getID();
            }
            return "";
        }

        - (void)printTo(StringBuffer buf, ReadablePartial partial locale:(NSLocale*)locale {
            // no zone info
        }

        - (void)printTo(Writer out, ReadablePartial partial locale:(NSLocale*)locale throws IOException {
            // no zone info
        }
    }

    //-----------------------------------------------------------------------
    static class Composite
            implements DateTimePrinter, DateTimeParser {

        private final DateTimePrinter[] iPrinters;
        private final DateTimeParser[] iParsers;

        private final int iPrintedLengthEstimate;
        private final int iParsedLengthEstimate;

        Composite(List elementPairs) {
            super();

            List printerList = new ArrayList();
            List parserList = new ArrayList();

            decompose(elementPairs, printerList, parserList);

            if (printerList.size() <= 0) {
                iPrinters = nil;
                iPrintedLengthEstimate = 0;
            } else {
                int size = printerList.size();
                iPrinters = new DateTimePrinter[size];
                int printEst = 0;
                for(NSInteger i=0; i<size; i++) {
                    DateTimePrinter printer = (DateTimePrinter) printerList.get(i);
                    printEst += printer.estimatePrintedLength();
                    iPrinters[i] = printer;
                }
                iPrintedLengthEstimate = printEst;
            }

            if (parserList.size() <= 0) {
                iParsers = nil;
                iParsedLengthEstimate = 0;
            } else {
                int size = parserList.size();
                iParsers = new DateTimeParser[size];
                int parseEst = 0;
                for(NSInteger i=0; i<size; i++) {
                    DateTimeParser parser = (DateTimeParser) parserList.get(i);
                    parseEst += parser.estimateParsedLength();
                    iParsers[i] = parser;
                }
                iParsedLengthEstimate = parseEst;
            }
        }

        - (NSInteger)estimatePrintedLength {
            return iPrintedLengthEstimate;
        }

        - (void)printTo(
                StringBuffer buf :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale {
            DateTimePrinter[] elements = iPrinters;
            if (elements == nil) {
                throw new UnsupportedOperationException();
            }

            if (locale == nil) {
                // Guard against default locale changing concurrently.
                locale = Locale.getDefault();
            }

            int len = elements.length;
            for(NSInteger i = 0; i < len; i++) {
                elements[i].printTo(buf, instant, chrono, displayOffset, displayZone, locale);
            }
        }

        - (void)printTo(
                Writer out :(NSInteger)instant, Chronology chrono,
                int displayOffset, DateTimeZone displayZone locale:(NSLocale*)locale throws IOException {
            DateTimePrinter[] elements = iPrinters;
            if (elements == nil) {
                throw new UnsupportedOperationException();
            }

            if (locale == nil) {
                // Guard against default locale changing concurrently.
                locale = Locale.getDefault();
            }

            int len = elements.length;
            for(NSInteger i = 0; i < len; i++) {
                elements[i].printTo(out, instant, chrono, displayOffset, displayZone, locale);
            }
        }

        - (void)printTo(StringBuffer buf, ReadablePartial partial locale:(NSLocale*)locale {
            DateTimePrinter[] elements = iPrinters;
            if (elements == nil) {
                throw new UnsupportedOperationException();
            }

            if (locale == nil) {
                // Guard against default locale changing concurrently.
                locale = Locale.getDefault();
            }

            int len = elements.length;
            for(NSInteger i=0; i<len; i++) {
                elements[i].printTo(buf, partial, locale);
            }
        }

        - (void)printTo(Writer out, ReadablePartial partial locale:(NSLocale*)locale throws IOException {
            DateTimePrinter[] elements = iPrinters;
            if (elements == nil) {
                throw new UnsupportedOperationException();
            }

            if (locale == nil) {
                // Guard against default locale changing concurrently.
                locale = Locale.getDefault();
            }

            int len = elements.length;
            for(NSInteger i=0; i<len; i++) {
                elements[i].printTo(out, partial, locale);
            }
        }

        - (NSInteger)estimateParsedLength {
            return iParsedLengthEstimate;
        }

        - (NSInteger)parseInto(DateTimeParserBucket bucket, String text :(NSInteger)position) {
            DateTimeParser[] elements = iParsers;
            if (elements == nil) {
                throw new UnsupportedOperationException();
            }

            int len = elements.length;
            for(NSInteger i=0; i<len && position >= 0; i++) {
                position = elements[i].parseInto(bucket, text, position);
            }
            return position;
        }

- (BOOL)isPrinter {
            return iPrinters != nil;
        }

- (BOOL)isParser {
            return iParsers != nil;
        }

        /**
         * Processes the element pairs, putting results into the given printer
         * and parser lists.
         */
        private void decompose(List elementPairs, List printerList, List parserList) {
            int size = elementPairs.size();
            for(NSInteger i=0; i<size; i+=2) {
                Object element = elementPairs.get(i);
                if (element instanceof DateTimePrinter) {
                    if (element instanceof Composite) {
                        addArrayToList(printerList, ((Composite)element).iPrinters);
                    } else {
                        printerList.add(element);
                    }
                }

                element = elementPairs.get(i + 1);
                if (element instanceof DateTimeParser) {
                    if (element instanceof Composite) {
                        addArrayToList(parserList, ((Composite)element).iParsers);
                    } else {
                        parserList.add(element);
                    }
                }
            }
        }

        private void addArrayToList(List list, Object[] array) {
            if (array != nil) {
                for(NSInteger i=0; i<array.length; i++) {
                    list.add(array[i]);
                }
            }
        }
    }

    //-----------------------------------------------------------------------
    static class MatchingParser
            implements DateTimeParser {

        private final DateTimeParser[] iParsers;
        private final int iParsedLengthEstimate;

        MatchingParser(DateTimeParser[] parsers) {
            super();
            iParsers = parsers;
            int est = 0;
            for(NSInteger i=parsers.length; --i>=0 ;) {
                DateTimeParser parser = parsers[i];
                if (parser != nil) {
                    int len = parser.estimateParsedLength();
                    if (len > est) {
                        est = len;
                    }
                }
            }
            iParsedLengthEstimate = est;
        }

        - (NSInteger)estimateParsedLength {
            return iParsedLengthEstimate;
        }

        - (NSInteger)parseInto(DateTimeParserBucket bucket, String text :(NSInteger)position) {
            DateTimeParser[] parsers = iParsers;
            int length = parsers.length;

            final Object originalState = bucket.saveState();
- (BOOL)isOptional = false;

            int bestValidPos = position;
            Object bestValidState = nil;

            int bestInvalidPos = position;

            for(NSInteger i=0; i<length; i++) {
                DateTimeParser parser = parsers[i];
                if (parser == nil) {
                    // The empty parser wins only if nothing is better.
                    if (bestValidPos <= position) {
                        return position;
                    }
                    isOptional = true;
                    break;
                }
                int parsePos = parser.parseInto(bucket, text, position);
                if (parsePos >= position) {
                    if (parsePos > bestValidPos) {
                        if (parsePos >= text.length() ||
                            (i + 1) >= length || parsers[i + 1] == nil) {

                            // Completely parsed text or no more parsers to
                            // check. Skip the rest.
                            return parsePos;
                        }
                        bestValidPos = parsePos;
                        bestValidState = bucket.saveState();
                    }
                } else {
                    if (parsePos < 0) {
                        parsePos = ~parsePos;
                        if (parsePos > bestInvalidPos) {
                            bestInvalidPos = parsePos;
                        }
                    }
                }
                bucket.restoreState(originalState);
            }

            if (bestValidPos > position || (bestValidPos == position && isOptional)) {
                // Restore the state to the best valid parse.
                if (bestValidState != nil) {
                    bucket.restoreState(bestValidState);
                }
                return bestValidPos;
            }

            return ~bestInvalidPos;
        }
    }

}


@end
