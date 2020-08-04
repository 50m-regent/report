set xlabel "t [ms]"
set ylabel "Amplitude"
set terminal postscript eps
set output 'mvave5-2.eps'
set datafile separator ","
plot 'mvave5-2.csv' w l ls 5 title 'Offline', 'sin_wn.csv' w l ls 2 title 'White noise', 'sin.csv' w l ls 3 title 'Sin'
reset