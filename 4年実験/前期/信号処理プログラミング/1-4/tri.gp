set xtics pi/2
set format x "%2.1P{/Symbol p}"
set xlabel "r [rad]"
set ylabel "tri(r)"
set key off
set terminal postscript eps
set output 'tri.eps'
set datafile separator ","
plot [][-1.05:1.05] 'tri.csv' w l ls 5
reset