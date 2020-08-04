set xlabel "t [ms]"
set ylabel "Amplitude"
set terminal postscript eps
set output 'test.eps'
set datafile separator ","
plot 'f3m100wn10.csv' w l ls 5 title 'M = 100'
reset