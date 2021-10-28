wc --lines data.dat  | awk '{print $1;}'
grep -c "d[ao]lor" data.dat
wc -w data.dat | awk '{print $1;}'
grep  -c "[ ^]mol" data.dat
