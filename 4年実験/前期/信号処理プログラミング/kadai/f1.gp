set xlabel "time [ms]"
set ylabel "Amplitude"
set terminal postscript eps
set output 'f1.eps'
set datafile separator ","
plot 'f1m1.csv' w l ls 3 title 'M = 1', 'f1m10.csv' w l ls 2 title 'M = 10', 'f1m100.csv' w l ls 5 title 'M = 100'
reset