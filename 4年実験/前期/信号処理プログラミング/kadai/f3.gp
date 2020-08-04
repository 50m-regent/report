set xlabel "t [ms]"
set ylabel "Amplitude"
set terminal postscript eps
set output 'f3.eps'
set datafile separator ","
plot 'f3m1.csv' w l ls 3 title 'M = 1', 'f3m10.csv' w l ls 2 title 'M = 10', 'f3m100.csv' w l ls 5 title 'M = 100'
reset