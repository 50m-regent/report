set xlabel "t [ms]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'diff.eps'
set datafile separator ","
plot [][-11:11] 'diff.csv' w l ls 5
reset