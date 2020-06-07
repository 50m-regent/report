set xtics pi/2
set format x "%2.1P{/Symbol p}"
set xlabel "r [rad]"
set ytics pi/2
set format y "%2.1P{/Symbol p}"
set ylabel "rad(r)"
set key off
set terminal postscript eps
set output 'rad.eps'
set datafile separator ","
plot [][-0.1:2*pi+0.1] 'rad.csv' w l ls 5
reset