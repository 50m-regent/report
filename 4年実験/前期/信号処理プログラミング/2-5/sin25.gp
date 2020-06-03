set xlabel "t [s]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'sin25.eps'
set datafile separator ","
plot [][] 'sin1f25.csv' w l ls 5
reset