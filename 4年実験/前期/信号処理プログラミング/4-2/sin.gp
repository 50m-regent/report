set xlabel "t [s]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'sin.eps'
set datafile separator ","
set multiplot
plot [][] 'sin.csv' w l ls 2
reset