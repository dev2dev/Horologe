//
//  HLDateMidnight+HLProperty.m
//  Horologe
//
//  Created by Paul Schifferer on 10/17/10.
//  Copyright (c) 2010 Pilgrim Age Software. All rights reserved.
//

#import "HLDateMidnight.h"


@interface HLProperty (PrivateMethods)
- (void)writeObject:(NSOutputStream*)stream;
- (void)readObject:(NSInputStream*)stream;
@end

@implementation HLProperty

- (id)_initWithInstant:(HLDateMidnight*)instant
                field:(HLDateTimeField*)field {
    if(self = [super init]) {
        iInstant = instant;
        iField = field;
    }
    
    return self;
}

- (void)writeObject:(NSOutputStream*)stream {
    [stream writeObject:iInstant];
    [stream writeObject:[iField type]];
}

- (void)readObject:(NSInputStream*)stream {
    iInstant = (HLDateMidnight*)[stream readObject];
    HLDateTimeFieldType* type = (HLDateTimeFieldType*)[stream readObject];
    iField = [type field:[iInstant chronology]];
}

//-----------------------------------------------------------------------
- (HLDateTimeField*)field {
    return iField;
}

- (NSInteger)_millis {
    return [iInstant millis];
}

- (HLChronology*)_chronology {
    return [iInstant chronology];
}

- (HLDateMidnight*)dateMidnight {
    return iInstant;
}

//-----------------------------------------------------------------------
- (HLDateMidnight*)addToCopy:(NSInteger)value {
    return [iInstant withMillis:[iField add:[iInstant millis] value:value]];
}

- (HLDateMidnight*)addWrapFieldToCopy:(NSInteger)value {
    return [iInstant withMillis:[iField addWrapField:[iInstant millis] value:value]];
}

//-----------------------------------------------------------------------
- (HLDateMidnight*)setCopy:(NSInteger)value {
    return [iInstant withMillis:[iField set:[iInstant millis] value:value]];
}

- (HLDateMidnight*)setCopyWithText:(NSString*)text 
                            locale:(NSLocale*)locale {
    return [iInstant withMillis:[iField set:[iInstant millis] text:text locale:locale]];
}

- (HLDateMidnight*)setCopyWithText:(NSString*)text {
    return [self setCopyWithText:text locale:nil];
}

//-----------------------------------------------------------------------
- (HLDateMidnight*)withMaximumValue {
    return [self setCopy:[self maximumValue]];
}

- (HLDateMidnight*)withMinimumValue {
    return [self setCopy:[self minimumValue]];
}

//-----------------------------------------------------------------------
- (HLDateMidnight*)roundFloorCopy {
    return [iInstant withMillis:[iField roundFloor:[iInstant millis]]];
}

- (HLDateMidnight*)roundCeilingCopy {
    return [iInstant withMillis:[iField roundCeiling:[iInstant millis]]];
}

- (HLDateMidnight*)roundHalfFloorCopy {
    return [iInstant withMillis:[iField roundHalfFloor:[iInstant millis]]];
}

- (HLDateMidnight*)roundHalfCeilingCopy {
    return [iInstant withMillis:[iField roundHalfCeiling:[iInstant millis]]];
}

- (HLDateMidnight*)roundHalfEvenCopy {
    return [iInstant withMillis:[iField roundHalfEven:[iInstant millis]]];
}

- (void)dealloc {
    // Clean-up code here.
    [iInstant release];
    [iField release];
    
    [super dealloc];
}

@end
