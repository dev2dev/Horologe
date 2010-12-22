/*
 * HLISOPeriodFormat.h
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

#import "HLPeriodFormatter.h"


@interface HLISOPeriodFormat : NSObject {
    
@private
    /** Cache of standard format. */
    HLPeriodFormatter* cStandard;
    /** Cache of alternate months format. */
    HLPeriodFormatter* cAlternate;
    /** Cache of alternate extended months format. */
    HLPeriodFormatter* cAlternateExtended;
    /** Cache of alternate weeks format. */
    HLPeriodFormatter* cAlternateWithWeeks;
    /** Cache of alternate extended weeks format. */
    HLPeriodFormatter* cAlternateExtendedWihWeeks;    
}

/**
 */
- (id)init;

//-----------------------------------------------------------------------
/**
 */
+ (HLPeriodFormatter*)standard;

/**
 */
+ (HLPeriodFormatter*)alternate;

/**
 */
+ (HLPeriodFormatter*)alternateExtended;

/**
 */
+ (HLPeriodFormatter*)alternateWithWeeks;

/**
 */
+ (HLPeriodFormatter*)alternateExtendedWithWeeks;

@end
