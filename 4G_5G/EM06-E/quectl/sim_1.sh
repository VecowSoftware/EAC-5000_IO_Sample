sudo echo 391 > /sys/class/gpio/export
sudo echo out > /sys/class/gpio/PH.00/direction
sudo echo 0 > /sys/class/gpio/PH.00/value
