set xlabel "t [ms]"
set ylabel "Amplitude"
set terminal postscript eps
set output 'chimes.eps'
set datafile separator ","
plot 'chimes.csv' using 1:2 w l ls 5 title 'Left', 'chimes.csv' using 1:3 w l ls 3 title 'Right',
reset