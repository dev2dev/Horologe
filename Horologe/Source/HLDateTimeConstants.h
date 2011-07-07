/*
 * DateTimeConstants.h
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


// These are ints not enumerations as they represent genuine int values
/** Constant (1) representing January, the first month (ISO) */
#define HL_DATETIME_JANUARY (1)

/** Constant (2) representing February, the second month (ISO) */
#define HL_DATETIME_FEBRUARY (2)

/** Constant (3) representing March, the third month (ISO) */
#define HL_DATETIME_MARCH (3)

/** Constant (4) representing April, the fourth month (ISO) */
#define HL_DATETIME_APRIL (4)

/** Constant (5) representing May, the fifth month (ISO) */
#define HL_DATETIME_MAY (5)

/** Constant (6) representing June, the sixth month (ISO) */
#define HL_DATETIME_JUNE (6)

/** Constant (7) representing July, the seventh month (ISO) */
#define HL_DATETIME_JULY (7)

/** Constant (8) representing August, the eighth month (ISO) */
#define HL_DATETIME_AUGUST (8)

/** Constant (9) representing September, the nineth month (ISO) */
#define HL_DATETIME_SEPTEMBER (9)

/** Constant (10) representing October, the tenth month (ISO) */
#define HL_DATETIME_OCTOBER (10)

/** Constant (11) representing November, the eleventh month (ISO) */
#define HL_DATETIME_NOVEMBER (11)

/** Constant (12) representing December, the twelfth month (ISO) */
#define HL_DATETIME_DECEMBER (12)

// These are ints not enumerations as they represent genuine int values
/** Constant (1) representing Monday, the first day of the week (ISO) */
#define HL_DATETIME_MONDAY (1)

/** Constant (2) representing Tuesday, the second day of the week (ISO) */
#define HL_DATETIME_TUESDAY (2)

/** Constant (3) representing Wednesday, the third day of the week (ISO) */
#define HL_DATETIME_WEDNESDAY (3)

/** Constant (4) representing Thursday, the fourth day of the week (ISO) */
#define HL_DATETIME_THURSDAY (4)

/** Constant (5) representing Friday, the fifth day of the week (ISO) */
#define HL_DATETIME_FRIDAY (5)

/** Constant (6) representing Saturday, the sixth day of the week (ISO) */
#define HL_DATETIME_SATURDAY (6)

/** Constant (7) representing Sunday, the seventh day of the week (ISO) */
#define HL_DATETIME_SUNDAY (7)


/** Constant (0) representing AM, the morning (from Calendar) */
#define HL_DATETIME_AM (0)

/** Constant (1) representing PM, the afternoon (from Calendar) */
#define HL_DATETIME_PM (1)


/** Constant (0) representing BC, years before zero (from Calendar) */
#define HL_DATETIME_BC (0)
/** Alternative constant (0) representing BCE, Before Common Era (secular) */
#define HL_DATETIME_BCE (0)

/**
 * Constant (1) representing AD, years after zero (from Calendar).
 * <p>
 * All new chronologies with differrent Era values should try to assign
 * eras as follows. The era that was in force at 1970-01-01 (ISO) is assigned
 * the value 1. Earlier eras are assigned sequentially smaller numbers.
 * Later eras are assigned sequentially greater numbers.
 */
#define HL_DATETIME_AD (1)
/**
 * Alternative constant (1) representing CE, Common Era (secular).
 * <p>
 * All new chronologies with differrent Era values should try to assign
 * eras as follows. The era that was in force at 1970-01-01 (ISO) is assigned
 * the value 1. Earlier eras are assigned sequentially smaller numbers.
 * Later eras are assigned sequentially greater numbers.
 */
#define HL_DATETIME_CE (1)


/** Milliseconds in one second (1000) (ISO) */
#define HL_DATETIME_MILLIS_PER_SECOND (1000)

/** Seconds in one minute (60) (ISO) */
#define HL_DATETIME_SECONDS_PER_MINUTE (60)
/** Milliseconds in one minute (ISO) */
public static final int MILLIS_PER_MINUTE = MILLIS_PER_SECOND * SECONDS_PER_MINUTE;

/** Minutes in one hour (ISO) */
#define HL_DATETIME_MINUTES_PER_HOUR (60)
/** Seconds in one hour (ISO) */
public static final int SECONDS_PER_HOUR = SECONDS_PER_MINUTE * MINUTES_PER_HOUR;
/** Milliseconds in one hour (ISO) */
public static final int MILLIS_PER_HOUR = MILLIS_PER_MINUTE * MINUTES_PER_HOUR;

/** Hours in a typical day (24) (ISO). Due to time zone offset changes, the
 * number of hours per day can vary. */
#define HL_DATETIME_HOURS_PER_DAY (24)
/** Minutes in a typical day (ISO). Due to time zone offset changes, the number
 * of minutes per day can vary. */
public static final int MINUTES_PER_DAY = MINUTES_PER_HOUR * HOURS_PER_DAY;
/** Seconds in a typical day (ISO). Due to time zone offset changes, the number
 * of seconds per day can vary. */
public static final int SECONDS_PER_DAY = SECONDS_PER_HOUR * HOURS_PER_DAY;
/** Milliseconds in a typical day (ISO). Due to time zone offset changes, the
 * number of milliseconds per day can vary. */
public static final int MILLIS_PER_DAY = MILLIS_PER_HOUR * HOURS_PER_DAY;

/** Days in one week (7) (ISO) */
#define HL_DATETIME_DAYS_PER_WEEK (7)
/** Hours in a typical week. Due to time zone offset changes, the number of
 * hours per week can vary. */
public static final int HOURS_PER_WEEK = HOURS_PER_DAY * DAYS_PER_WEEK;
/** Minutes in a typical week (ISO). Due to time zone offset changes, the number
 * of minutes per week can vary. */
public static final int MINUTES_PER_WEEK = MINUTES_PER_DAY * DAYS_PER_WEEK;
/** Seconds in a typical week (ISO). Due to time zone offset changes, the number
 * of seconds per week can vary. */
public static final int SECONDS_PER_WEEK = SECONDS_PER_DAY * DAYS_PER_WEEK;
/** Milliseconds in a typical week (ISO). Due to time zone offset changes, the
 * number of milliseconds per week can vary. */
public static final int MILLIS_PER_WEEK = MILLIS_PER_DAY * DAYS_PER_WEEK;

