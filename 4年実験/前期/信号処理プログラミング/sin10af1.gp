set xzeroaxis lt 1 lw 1
set style line 1 lt 2 lw 1 pt 5
set datafile separator ","
plot 'sin10af1.csv' u 1:2 t "sin" w l ls 1
reset