#!/bin/python
import cv2
def cv2_cvt(img):
	img = cv2.cvtColor(img, cv2.COLOR_BayerRG2RGB)	##demosaic
	#img = cv2.resize(img, [640,480])
	return img
def cv2_vcap(i):
	vc = cv2.VideoCapture(i, cv2.CAP_V4L2)	##"/dev/video0"
	if not vc.isOpened():
		return
	vc.set(cv2.CAP_PROP_CONVERT_RGB, 0)
	vc.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*'RG12'))
	w=int(vc.get(cv2.CAP_PROP_FRAME_WIDTH)); h=int(vc.get(cv2.CAP_PROP_FRAME_HEIGHT))
	while True:
		ret,img = vc.read()
		if not ret:
			break
		img.dtype = 'uint16'
		img = cv2_cvt(img.reshape(h,w))
		cv2.imshow('cv_vcap', img)
		if cv2.waitKey(1)==ord('q'):
			break
	vc.release()
	cv2.destroyAllWindows()

if __name__ == '__main__':
	cv2_vcap(0)
