gst-launch-1.0 v4l2src device=/dev/video0 ! "video/x-raw, width=(int)3840, height=(int)2160,pixelformat=UYVY" ! fpsdisplaysink video-sink=xvimagesink text-overlay=false
