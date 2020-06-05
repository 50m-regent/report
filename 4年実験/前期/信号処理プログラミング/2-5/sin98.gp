set xlabel "t [s]"
set ylabel "Amplitude"
set terminal postscript eps
set output 'sin98.eps'
set datafile separator ","
set multiplot
plot [][0:250] 'sin98.csv', 'sin98_2.csv'
#plot [][0:250] 'sin98.csv' w l ls 5
#plot [][0:250] 'sin98_2.csv' w l ls 2
reset