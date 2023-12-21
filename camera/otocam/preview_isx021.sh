#!/bin/bash
for ((i=0;i<8;i++)); do
	[ -e /dev/video$i ] || continue
	gst-launch-1.0 v4l2src device=/dev/video$i \
		! nvvidconv ! "video/x-raw(memory:NVMM),width=1920,height=1080" \
		! nvvidconv ! xvimagesink sync=0 &
	sleep 1
done
