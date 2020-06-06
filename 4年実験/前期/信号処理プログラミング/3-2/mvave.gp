set xlabel "t [s]"
set ylabel "Amplitude"
set key off
set terminal postscript eps
set output 'mvave.eps'
set datafile separator ","
set multiplot
plot [][0:260] 'mvave.csv' w l ls 5
plot [][0:260] 'sin.csv' w l ls 2
reset