set xlabel "t [ms]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'squ.eps'
set datafile separator ","
plot [][-2.55:2.55] 'squ.csv' w l ls 5
reset