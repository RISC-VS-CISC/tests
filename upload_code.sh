cp grmon.tcl grmon_temp.tcl
sed -i "s/{bit_stream_file}/`echo $1`/" grmon_temp.tcl
./grmon -digilent -c grmon_temp.tcl -echo 
rm ./grmon_temp.tcl