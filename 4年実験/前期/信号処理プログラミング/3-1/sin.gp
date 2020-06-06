set xlabel "t [s]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'sin_wn.eps'
set datafile separator ","
set multiplot
plot [][0:260] 'sin_wn.csv' w l ls 5
plot [][0:260] 'sin.csv' w l ls 2
reset