set xtics pi/2
set format x "%2.1P{/Symbol p}"
set xlabel "r [rad]"
set ylabel "saw(r)"
set key off
set terminal postscript eps
set output 'saw.eps'
set datafile separator ","
plot [][-1.05:1.05] 'saw.csv' w l ls 5
reset