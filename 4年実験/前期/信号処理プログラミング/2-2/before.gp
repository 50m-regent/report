set xlabel "t [s]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'before.eps'
set datafile separator ","
plot [][] 'before.csv' w l ls 5
reset