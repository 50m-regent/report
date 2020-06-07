set xlabel "t [ms]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'ringout.eps'
set datafile separator ","
plot [][] 'ringout.csv' w l ls 5
reset