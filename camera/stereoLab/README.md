
##### ISP file : 

* The ZED-X are provided with a custom ISP file. You need to install it to have a good image : 

`$ sudo cp ./ISP/zedx_ar0234.isp /var/nvidia/nvcam/settings/`
`$ sudo chmod 644 /var/nvidia/nvcam/settings/zedx_ar0234.isp`
`$ sudo chown root:root /var/nvidia/nvcam/settings/zedx_ar0234.isp`



### SDK Installation

Install the latest version available on Stereolabs Website : 
https://www.stereolabs.com/developers/release/

Note : ZED SDK v4.X only for GMSL2 based cameras

Use the command start with "ZED" to monitor cameras.

Use ZED Explorer to list and see cameras : 

`$ ZED_Explorer --all`



