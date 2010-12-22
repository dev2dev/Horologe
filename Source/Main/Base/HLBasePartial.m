/*
 * HLBasePartial.m
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

#import "Base/HLBasePartial.h"
#import "Core/HLDateTimeUtils.h"
#import "Core/HLChronology.h"
#import "Convert/HLPartialConverter.h"
#import "Core/HLDateTimeField.h"
#import "Format/HLDateTimeFormat.h"
#import "Convert/HLConverterManager.h"


@implementation HLBasePartial

//-----------------------------------------------------------------------
- (id)_init {
    
    if(self = [self _initWithMillis:[HLDateTimeUtils currentTimeMillis] chronology:nil]) {
        
    }
    
    return self;
}

- (id)_initWithChronology:(HLChronology*)chronology {
    
    if(self = [self _initWithMillis:[HLDateTimeUtils currentTimeMillis] chronology:chronology]) {
        
    }
    
    return self;
}

- (id)_init:(NSInteger)instant {
    
    if(self = [self _initWithMillis:instant chronology:nil]) {
        
    }
    
    return self;
}

- (id)_initWithMillis:(NSInteger)instant
           chronology:(HLChronology*)chronology {
    
    if(self = [super _init]) {
        chronology = [HLDateTimeUtils chronology:chronology];
        iChronology = [[chronology withUTC] retain];
        iValues = [chronology get:self millis:instant];
    }
    
    return self;
}

- (id)_initWithObject:(id)instant
           chronology:(HLChronology*)chronology {
    
    if(self = [super _init]) {
        HLPartialConverter* converter = [[HLConverterManager instance] partialConverter:instant];
        chronology = [converter chronologyFromInstant:instant chronology:chronology];
        chronology = [HLDateTimeUtils chronology:chronology];
        iChronology = [[chronology withUTC] retain];
        iValues = [converter partialValuesFromPartial:self instant:instant chronology:chronology];
    }
    
    return self;
}

- (id)_initWithObject:(id)instant 
           chronology:(HLChronology*)chronology 
               parser:(HLDateTimeFormatter*)parser {
    
    if(self = [super _init]) {
        HLPartialConverter* converter = [[HLConverterManager instance] partialConverter:instant];
        chronology = [converter chronologyFromInstant:instant chronology:chronology];
        chronology = [HLDateTimeUtils chronology:chronology];
        iChronology = [[chronology withUTC] retain];
        iValues = [converter partialValuesFromPartial:self instant:instant chronlogy:chronology parser:parser];
    }
    
    return self;
}

- (id)_initWithValues:(NSArray*)values
           chronology:(HLChronology*)chronology {
    
    if(self = [super _init]) {
        chronology = [HLDateTimeUtils chronology:chronology];
        iChronology = [[chronology withUTC] retain];
        [chronology validate:self values:values];
        iValues = [[NSArray arrayWithArray:values] retain];
    }
    
    return self;
}

- (id)_initWithPartial:(HLBasePartial*)base
                values:(NSArray*)values {
    
    if(self = [super _init]) {
        iChronology = [[base chronology] retain];
        iValues = [[NSArray arrayWithArray:values] retain];
    }
    
    return self;
}

- (id)_initWithPartial:(HLBasePartial*)base 
            chronology:(HLChronology*)chrono {
    
    if(self = [super _init]) {
        iChronology = [[chrono withUTC] retain];
        iValues = [[base values] retain];
    }
    
    return self;
}

//-----------------------------------------------------------------------
- (NSInteger)valueAtIndex:(NSInteger)index {
    return [iValues objectAtIndex:index];
}

- (NSArray*)values {
    return [NSArray arrayWithArray:iValues];
}

- (HLChronology*)chronology {
    return iChronology;
}

//-----------------------------------------------------------------------
- (void)_setValueAtIndex:(NSInteger)index 
                   value:(NSInteger)value {
    HLDateTimeField* field = [self fieldAtIndex:index];
    iValues = [field set:self index:index values:iValues value:value];
}

- (void)_setValues:(NSArray*)values {
    [[self chronology] validate:self values:values];
    iValues = [[NSArray arrayWithArray:values] retain];
}

//-----------------------------------------------------------------------
- (NSString*)stringWithPattern:(NSString*)pattern {
    if (pattern == nil) {
        return [self description];
    }
    
    return [[HLDateTimeFormat forPattern:pattern] printPartial:self];
}

- (NSString*)stringWithPattern:(NSString*)pattern 
                        locale:(NSLocale*)locale {
    if (pattern == nil) {
        return [self description];
    }
    
    return [[[HLDateTimeFormat forPattern:pattern] withLocale:locale] printPartial:self];
}

@end
