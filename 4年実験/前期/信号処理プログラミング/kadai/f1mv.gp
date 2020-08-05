set xlabel "time [ms]"
set ylabel "Amplitude"
set terminal postscript eps
set output 'f1mv.eps'
set datafile separator ","
plot 'f1m100wn10mv3.csv' w l ls 2 title '3 point moving average', 'f1m100wn10mv5.csv' w l ls 5 title '5 point moving average'
reset