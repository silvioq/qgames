#!/bin/bash
HAY_ERROR=0
verbose=""
if [ $1x == "-vx" ]; then
    verbose="-v"
fi

for file in `ls qgtest/*.qgtest`;
do
    ./test-qgames  $verbose $file
    if [ $? != 0 ]; then
        echo  "$file  ERROR!"
        HAY_ERROR=1
    else
        echo  "$file  OK"
    fi
done
exit  $HAY_ERROR
