i2ctransfer -y -f 2 w2@0x38 0xC5 0xCC
i2ctransfer -y -f 2 w2@0x38 0xC6 0x0C
v4l2-ctl -c trigger_mode=2 -d 0
v4l2-ctl -c trigger_mode=2 -d 1
v4l2-ctl -c trigger_mode=2 -d 2
v4l2-ctl -c trigger_mode=2 -d 3
v4l2-ctl -c trigger_mode=2 -d 4
v4l2-ctl -c trigger_mode=2 -d 5
v4l2-ctl -c trigger_mode=2 -d 6
v4l2-ctl -c trigger_mode=2 -d 7

v4l2-ctl -c frame_sync=0 -d 0
v4l2-ctl -c frame_sync=0 -d 1
v4l2-ctl -c frame_sync=0 -d 2
v4l2-ctl -c frame_sync=0 -d 3
v4l2-ctl -c frame_sync=0 -d 4
v4l2-ctl -c frame_sync=0 -d 5
v4l2-ctl -c frame_sync=0 -d 6
v4l2-ctl -c frame_sync=0 -d 7

