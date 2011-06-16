Horologe is an idiomatic port of the popular Java date/time library Joda-Time.

Why port a Java library?
========================

Joda-Time is an excellent library.  While it mostly serves to provide a better interface
to time and date functionality for Java, addressing those needs better than the JDK-provided
classes, and the Cocoa time and date classes are fairly sufficient for most tasks, I felt 
like having this library in Cocoa would fill the gap.

And it scratches an itch of mine for a project I'm working on. :)

What do you mean "idiomatic"?
=============================

Cocoa has a number of different conventions, such as getter/setter naming among others,
and just porting the code from Java would be wrong in so many ways.  By adjusting the
code so that it adopts the idioms of Cocoa, the library seems more natural in a Cocoa
programming environment.