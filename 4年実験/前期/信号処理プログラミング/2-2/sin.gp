set xlabel "t [s]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'sin.eps'
set datafile separator ","
set multiplot
plot [][] 'sin150f4.csv' w l ls 5
plot [][] 'before.csv' w l ls 2
reset