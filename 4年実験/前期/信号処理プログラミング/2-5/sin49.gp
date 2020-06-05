set xlabel "t [s]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'sin49.eps'
set datafile separator ","
plot [][] 'sin49.csv' w l ls 5
reset