#!/bin/bash
for file in `ls qgtest/*.qgtest`;
do
    echo $file
    ./test-qgames  $file
    if [ $? != 0 ]; then
        exit 1;
    fi
done

