set xlabel "t [ms]"
set ylabel "Amplitude"
set terminal postscript eps
set output 'f3mv.eps'
set datafile separator ","
plot 'f3m100wn10mv3.csv' w l ls 2 title '3 point moving average', 'f3m100wn10mv5.csv' w l ls 5 title '5 point moving average'
reset