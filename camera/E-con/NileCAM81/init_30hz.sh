i2ctransfer -y -f 2 w2@0x38 0xC5 0x43
i2ctransfer -y -f 2 w2@0x38 0xC6 0x04
v4l2-ctl -c trigger_mode=2 -d 0
v4l2-ctl -c trigger_mode=2 -d 1
v4l2-ctl -c trigger_mode=2 -d 2
v4l2-ctl -c trigger_mode=2 -d 3
v4l2-ctl -c trigger_mode=2 -d 4
v4l2-ctl -c trigger_mode=2 -d 5
v4l2-ctl -c trigger_mode=2 -d 6
v4l2-ctl -c trigger_mode=2 -d 7

v4l2-ctl -c frame_sync=1 -d 0
v4l2-ctl -c frame_sync=1 -d 1
v4l2-ctl -c frame_sync=1 -d 2
v4l2-ctl -c frame_sync=1 -d 3
v4l2-ctl -c frame_sync=1 -d 4
v4l2-ctl -c frame_sync=1 -d 5
v4l2-ctl -c frame_sync=1 -d 6
v4l2-ctl -c frame_sync=1 -d 7



