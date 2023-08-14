#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>

#define I2C_ADAPTER "/dev/i2c-8"
#define ADC_ADDR 0x49 
#define CH1_REG_ADDR 0x8c
#define CH2_REG_ADDR 0xcc

#define SIZE 255

int fd;




int i2c_read(int fd, int addr, int reg, int *val)
{
     if(ioctl(fd, I2C_SLAVE, addr)<0) {
            printf("fail to set i2c device slave address!\n");
            close(fd);
            return -1;
        }

     if(write(fd, &reg, 1)){
         if(read(fd, val, 1)){
                 return 0;
        }
    }
	return -1;
}




int main(int argc,char *argv[])
{       
	int val = 0;
	fd = open(I2C_ADAPTER, O_RDWR);
        if(fd < 0)
        {
            perror("Can't open I2C device.\n");
            return -1;
        }
	i2c_read(fd,ADC_ADDR ,CH1_REG_ADDR,&val);
	printf("ADC_V=%f\n",val*0.0097*21);
	val = 0;
	i2c_read(fd,ADC_ADDR ,CH2_REG_ADDR,&val);
        printf("ADC_I=%f\n",val*0.0097/0.05);// 換料需要修改
	
	return 0;
}
