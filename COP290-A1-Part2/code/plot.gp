#!/usr/bin/gnuplot
# this script requires execution time for matrix size 10, 100, 1000 to be in the ../data/time folder. The times for different executions (i.e. simple, pthread, etc.) should be tab separated.

do for [size in "10 100 1000"]{
    set terminal png size 800,600
    set output "../Plots/".size."by".size.".png"

    set style fill solid 0.25 border -1
    set style boxplot outliers pointtype 7
    set style data boxplot

    set title "Squrare Matrix size:".size font 'Arial,14';
    set ylabel "Time in milliseconds"
    set xtics ('Simple' 1, 'PThread' 2, 'Openblas' 3,'MKL' 4)
    plot for [i=1:4] "../Time/time".size.".txt" using (i):i notitle
}