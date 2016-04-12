#! /bin/bash

str="not null , some more input"
arg=$1
var=`echo "$str" | grep -c "not null"`
echo "var = $var"

if [ "$arg" == "not null" ]; then
	echo "not null"
fi
