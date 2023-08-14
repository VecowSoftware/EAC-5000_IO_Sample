Ignition cmd: ignition [option] [value]
SW Version:0.1.2
   options  value
	-r	      Read All Parameter Status.
	-s            Set Parameter flag.
	-m <1/0/2>      Mode Select (0:ATX, 1:IGN Mode, 2:AT).
	-o <0..65000> Power on Delay time(sec).
	-f <0..65000> Power off Delay time(sec).
	-c <0..255>   force shutdown time(sec).
 	-g <1/0>      Enable(1)/disable(0) voltage guard.
	-u <15..50>   (voltage guard) voltage High bound.
	-d <9..49>    (voltage guard) voltage Low bound.
	-l Get Ignition power on(1)/off(0) state.			

Note: When AT mode is set, the power ON/OFF Delay cannot be used at the same time.
    	
example1: ./ignition -r (read all status).
example2: ./ignition -s -m 1 -o 15 -f 30 -c 60(set ignition mode,
                  DelayOn 15sec,DelayOff 30sec,force shutdown 60sec).
example3: ./ignition -s -m 2 (set power AT mode).	
example4: ./ignition -l (get ignition state).				  