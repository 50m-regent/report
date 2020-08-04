set xlabel "t [s]"
set ylabel "Amplitude"
set terminal postscript eps
set output 'mvave3-1.eps'
set datafile separator ","
plot 'mvave3-1.csv' w l ls 5, 'sin_wn.csv' w l ls 2, 'sin.csv' w l ls 3
reset