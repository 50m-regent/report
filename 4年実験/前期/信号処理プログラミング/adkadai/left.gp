set xlabel "t [ms]"
set ylabel "Amplitude"
set terminal postscript eps
set output 'left.eps'
set datafile separator ","
plot 'test.csv' using 1:2 w l ls 5 title 'Left'
reset