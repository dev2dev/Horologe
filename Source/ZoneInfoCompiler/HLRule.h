//
//  HLRule.h
//  Horologe
//
//  Created by Paul Schifferer on 10/18/10.
//  Copyright (c) 2010 Pilgrim Age Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface HLRule : NSObject {
@private
    
}

private static class Rule {
    public final String iName;
    public final int iFromYear;
    public final int iToYear;
    public final String iType;
    public final DateTimeOfYear iDateTimeOfYear;
    public final int iSaveMillis;
    public final String iLetterS;
    
    Rule(StringTokenizer st) {
        iName = st.nextToken().intern();
        iFromYear = parseYear(st.nextToken(), 0);
        iToYear = parseYear(st.nextToken(), iFromYear);
        if (iToYear < iFromYear) {
            throw new IllegalArgumentException();
        }
        iType = parseOptional(st.nextToken());
        iDateTimeOfYear = new DateTimeOfYear(st);
        iSaveMillis = parseTime(st.nextToken());
        iLetterS = parseOptional(st.nextToken());
    }
    
    /**
     * Adds a recurring savings rule to the builder.
     */
    public void addRecurring(DateTimeZoneBuilder builder, String nameFormat) {
        String nameKey = formatName(nameFormat);
        iDateTimeOfYear.addRecurring
        (builder, nameKey, iSaveMillis, iFromYear, iToYear);
    }
    
    private String formatName(String nameFormat) {
        int index = nameFormat.indexOf('/');
        if (index > 0) {
            if (iSaveMillis == 0) {
                // Extract standard name.
                return nameFormat.substring(0, index).intern();
            } else {
                return nameFormat.substring(index + 1).intern();
            }
        }
        index = nameFormat.indexOf("%s");
        if (index < 0) {
            return nameFormat;
        }
        String left = nameFormat.substring(0, index);
        String right = nameFormat.substring(index + 2);
        String name;
        if (iLetterS == null) {
            name = left.concat(right);
        } else {
            name = left + iLetterS + right;
        }
        return name.intern();
    }
    
    public String toString() {
        return
        "[Rule]\n" + 
        "Name: " + iName + "\n" +
        "FromYear: " + iFromYear + "\n" +
        "ToYear: " + iToYear + "\n" +
        "Type: " + iType + "\n" +
        iDateTimeOfYear +
        "SaveMillis: " + iSaveMillis + "\n" +
        "LetterS: " + iLetterS + "\n";
    }
}

@end
