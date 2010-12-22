//
//  main.m - ZoneInfoCompiler
//  Horologe
//
//  Created by Paul Schifferer on 10/18/10.
//  Copyright (c) 2010 Pilgrim Age Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Horologe/Horologe.h>

#import "HLZoneInfoCompiler.h"


void printUsage() {
    printf("Usage: ZoneInfoCompiler <options> <source files>\n");
printf("where possible options include:\n");
printf("  -src <directory>    Specify where to read source files\n");
printf("  -dst <directory>    Specify where to write generated files\n");
printf("  -verbose            Output verbosely (default false)\n");
}

//-----------------------------------------------------------------------
/**
 * Launches the ZoneInfoCompiler tool.
 *
 * <pre>
 * Usage: ./ZoneInfoCompiler &lt;options&gt; &lt;source files&gt;
 * where possible options include:
 *   -src &lt;directory&gt;    Specify where to read source files
 *   -dst &lt;directory&gt;    Specify where to write generated files
 *   -verbose            Output verbosely (default false)
 * </pre>
 */
int main(int argc, char** argv) {
   
    if (argc == 0) {
        printUsage();
        return 1;
    }
    
    File inputDir = null;
    File outputDir = null;
    boolean verbose = false;
    
    int i;
    for (i=0; i<args.length; i++) {
        try {
            if ("-src".equals(args[i])) {
                inputDir = new File(args[++i]);
            } else if ("-dst".equals(args[i])) {
                outputDir = new File(args[++i]);
            } else if ("-verbose".equals(args[i])) {
                verbose = true;
            } else if ("-?".equals(args[i])) {
                printUsage();
                return;
            } else {
                break;
            }
        } catch (IndexOutOfBoundsException e) {
            printUsage();
            return;
        }
    }
    
    if (i >= args.length) {
        printUsage();
        return;
    }
    
    File[] sources = new File[args.length - i];
    for (int j=0; i<args.length; i++,j++) {
        sources[j] = inputDir == null ? new File(args[i]) : new File(inputDir, args[i]);
    }
    
    cVerbose.set(verbose);

    HLZoneInfoCompiler* zic = [[HLZoneInfoCompiler alloc] init];
    zic.compile(outputDir, sources);
}
