set xlabel "t [ms]"
set ylabel "Amplitude"
set terminal postscript eps
set output 'right.eps'
set datafile separator ","
plot 'test.csv' using 1:3 w l ls 5 title 'Right'
reset