#!/usr/bin/bash
# this script requires input matrices in data folder. The data folder must reside in the parent directory of this script.

for SIZE in 10 100 1000
do
    for TYPE in simple pthread openblas
    do
        COUNT=0
        echo
        echo "${TYPE}:"
        while [ $COUNT -lt 20 ]
        do
            ((COUNT++))
            ./yourcode.out fullyconnected ../data/mat"${SIZE}".txt ../data/weight"${SIZE}".txt ../data/bias"${SIZE}".txt "${TYPE}" ../output/"${TYPE}"/out"${SIZE}".txt
        done
    done

    # mkl
    COUNT=0
    echo
    echo "mkl:"
    while [ $COUNT -lt 20 ]
    do
        ((COUNT++))
        ./yourcode_Mkl.out fullyconnected ../data/mat"${SIZE}".txt ../data/weight"${SIZE}".txt ../data/bias"${SIZE}".txt mkl ../output/mkl/out"${SIZE}".txt
    done
done