#!/bin/sh

for i in `find . -name '*.[hm]' -print`
do
	echo $i
	DIRNAME=`dirname $i`
	FILENAME=`echo $i | sed -E -e 's/^.+\/([a-zA-Z]+\.[hm])/HL\1/'`
	echo "dir: $DIRNAME"
	echo "file: $FILENAME"
	
	mv $i "$DIRNAME/$FILENAME"
	
done