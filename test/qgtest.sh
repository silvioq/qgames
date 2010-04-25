#!/bin/bash
HAY_ERROR=0
for file in `ls qgtest/*.qgtest`;
do
    printf $file
    ./test-qgames  $file
    if [ $? != 0 ]; then
        echo  "  ERROR!"
        HAY_ERROR=1
    else
        echo  "  OK"
    fi
done
exit  $HAY_ERROR
