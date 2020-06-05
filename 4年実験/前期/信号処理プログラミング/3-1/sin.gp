set xlabel "t [s]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'sin_wn.eps'
set datafile separator ","
plot [][] 'sin_wn.csv' w l ls 5
reset