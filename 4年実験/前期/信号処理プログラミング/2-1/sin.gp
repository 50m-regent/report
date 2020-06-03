set xlabel "t [s]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'sin.eps'
set datafile separator ","
plot [][] 'sin100f4.csv' w l ls 5
reset