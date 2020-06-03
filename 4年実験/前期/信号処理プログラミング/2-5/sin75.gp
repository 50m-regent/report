set xlabel "t [s]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'sin75.eps'
set datafile separator ","
plot [][] 'sin1f75.csv' w l ls 5
reset