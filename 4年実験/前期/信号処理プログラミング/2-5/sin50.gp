set xlabel "t [s]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'sin50.eps'
set datafile separator ","
plot [][] 'sin1f50.csv' w l ls 5
reset