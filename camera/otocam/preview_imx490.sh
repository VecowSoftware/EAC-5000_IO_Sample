#!/bin/sh
gst-launch-1.0 v4l2src device="/dev/video0" ! "video/x-raw, format=(string)UYVY, width=(int)2880, height=(int)1860" ! nvvidconv ! "video/x-raw(memory:NVMM), width=480, height=270, format=(string)I420" ! nvvidconv ! xvimagesink sync=false &
sleep 0.5
gst-launch-1.0 v4l2src device="/dev/video1" ! "video/x-raw, format=(string)UYVY, width=(int)2880, height=(int)1860" ! nvvidconv ! "video/x-raw(memory:NVMM), width=480, height=270, format=(string)I420" ! nvvidconv ! xvimagesink sync=false &
sleep 0.5
gst-launch-1.0 v4l2src device="/dev/video2" ! "video/x-raw, format=(string)UYVY, width=(int)2880, height=(int)1860" ! nvvidconv ! "video/x-raw(memory:NVMM), width=480, height=270, format=(string)I420" ! nvvidconv ! xvimagesink sync=false &
sleep 0.5
gst-launch-1.0 v4l2src device="/dev/video3" ! "video/x-raw, format=(string)UYVY, width=(int)2880, height=(int)1860" ! nvvidconv ! "video/x-raw(memory:NVMM), width=480, height=270, format=(string)I420" ! nvvidconv ! xvimagesink sync=false &
sleep 0.5
gst-launch-1.0 v4l2src device="/dev/video4" ! "video/x-raw, format=(string)UYVY, width=(int)2880, height=(int)1860" ! nvvidconv ! "video/x-raw(memory:NVMM), width=480, height=270, format=(string)I420" ! nvvidconv ! xvimagesink sync=false &
sleep 0.5
gst-launch-1.0 v4l2src device="/dev/video5" ! "video/x-raw, format=(string)UYVY, width=(int)2880, height=(int)1860" ! nvvidconv ! "video/x-raw(memory:NVMM), width=480, height=270, format=(string)I420" ! nvvidconv ! xvimagesink sync=false &
sleep 0.5
gst-launch-1.0 v4l2src device="/dev/video6" ! "video/x-raw, format=(string)UYVY, width=(int)2880, height=(int)1860" ! nvvidconv ! "video/x-raw(memory:NVMM), width=480, height=270, format=(string)I420" ! nvvidconv ! xvimagesink sync=false &
sleep 0.5
gst-launch-1.0 v4l2src device="/dev/video7" ! "video/x-raw, format=(string)UYVY, width=(int)2880, height=(int)1860" ! nvvidconv ! "video/x-raw(memory:NVMM), width=480, height=270, format=(string)I420" ! nvvidconv ! xvimagesink sync=false &


