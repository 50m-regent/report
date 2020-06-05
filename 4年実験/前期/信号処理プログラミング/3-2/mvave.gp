set xlabel "t [s]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'mvave.eps'
set datafile separator ","
plot [][] 'mvave.csv' w l ls 5
reset