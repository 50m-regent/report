set xlabel "t [ms]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'timetone.eps'
set datafile separator ","
plot [][] 'timetone.csv' w l ls 5
reset