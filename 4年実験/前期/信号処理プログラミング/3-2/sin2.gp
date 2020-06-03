set xlabel "t [s]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'sin2.eps'
set datafile separator ","
plot [][] 'sin2.csv' w l ls 5
reset