set xlabel "t [ms]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'sin.eps'
set datafile separator ","
plot [][] 'sin.csv' w l ls 5
reset