set xlabel "t [s]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'sin1.eps'
set datafile separator ","
plot [][] 'sin1.csv' w l ls 5
reset