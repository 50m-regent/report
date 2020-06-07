set xlabel "t [ms]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'ringin.eps'
set datafile separator ","
plot [][] 'ringin.csv' w l ls 5
reset