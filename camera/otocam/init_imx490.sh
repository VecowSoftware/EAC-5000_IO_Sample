echo 397 > /sys/class/gpio/export 
echo out > /sys/class/gpio/PH.06/direction 
echo 1 > /sys/class/gpio/PH.06/value 
echo 486 > /sys/class/gpio/export
echo out > /sys/class/gpio/PAC.00/direction
echo 1 > /sys/class/gpio/PAC.00/value 
echo 394 > /sys/class/gpio/export 
echo out > /sys/class/gpio/PH.03/direction 
echo 1 > /sys/class/gpio/PH.03/value 
echo 487 > /sys/class/gpio/export 
echo out > /sys/class/gpio/PAC.01/direction 
echo 1 > /sys/class/gpio/PAC.01/value 
echo 431 > /sys/class/gpio/export 
echo out > /sys/class/gpio/PM.07/direction 
echo 1 > /sys/class/gpio/PM.07/value 



sleep 5
insmod max9296.ko
sleep 3
insmod nv_imx390.ko sensor_model=imx490isp
sleep 2

i2ctransfer -f -y 2 w1@0x72 0x01
i2ctransfer -f -y 2 w3@0x48 0x00 0x03 0x40 
i2ctransfer -f -y 2 w1@0x72 0x02
i2ctransfer -f -y 2 w3@0x48 0x00 0x03 0x40 
i2ctransfer -f -y 2 w1@0x73 0x01
i2ctransfer -f -y 2 w3@0x48 0x00 0x03 0x40 
i2ctransfer -f -y 2 w1@0x73 0x02
i2ctransfer -f -y 2 w3@0x48 0x00 0x03 0x40 


