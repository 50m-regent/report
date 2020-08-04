set xlabel "t [ms]"
set ylabel "Amplitude"
set terminal postscript eps
set output 'mvave5-1.eps'
set datafile separator ","
plot 'mvave5-1.csv' w l ls 5 title 'Online', 'sin_wn.csv' w l ls 2 title 'White noise', 'sin.csv' w l ls 3 title 'Sin'
reset