#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h> 









void change_io_sta(int portnum,int mode)
{
        int iMode1 = 0, iMode2 = 0; 
	char  *sMode1="PAC.02", *sMode2= "PP.04",*sMode3="PN.01",*sMode4="PP.06";
	char buf[200];
	if(portnum == 1)
	{
        	iMode1 = 488;
        	iMode2 = 444;
	if(mode== 232)
        {
                sprintf(buf,"echo %d > /sys/class/gpio/export",iMode1);
                system(buf);
                sprintf(buf,"echo out > /sys/class/gpio/%s/direction",sMode1);
                system(buf);
                sprintf(buf,"echo 1 > /sys/class/gpio/%s/value",sMode1);
                system(buf);
                sprintf(buf,"echo %d > /sys/class/gpio/export",iMode2);
                system(buf);
                sprintf(buf,"echo out > /sys/class/gpio/%s/direction",sMode2);
                system(buf);
                sprintf(buf,"echo 0 > /sys/class/gpio/%s/value",sMode2);
                system(buf);
        }
        else if(mode == 422)
        {
                sprintf(buf,"echo %d > /sys/class/gpio/export",iMode1);
                system(buf);
                sprintf(buf,"echo out > /sys/class/gpio/%s/direction",sMode1);
                system(buf);
                sprintf(buf,"echo 1 > /sys/class/gpio/%s/value",sMode1);
                system(buf);
                sprintf(buf,"echo %d > /sys/class/gpio/export",iMode2);
                system(buf);
                sprintf(buf,"echo out > /sys/class/gpio/%s/direction",sMode2);
                system(buf);
                sprintf(buf,"echo 1 > /sys/class/gpio/%s/value",sMode2);
                system(buf);
        }
        else if(mode == 485)
        {
                sprintf(buf,"echo %d > /sys/class/gpio/export",iMode1);
                system(buf);
                sprintf(buf,"echo out > /sys/class/gpio/%s/direction",sMode1);
                system(buf);
                sprintf(buf,"echo 0 > /sys/class/gpio/%s/value",sMode1);
                system(buf);
                sprintf(buf,"echo %d > /sys/class/gpio/export",iMode2);
                system(buf);
                sprintf(buf,"echo out > /sys/class/gpio/%s/direction",sMode2);
                system(buf);
                sprintf(buf,"echo 1 > /sys/class/gpio/%s/value",sMode2);
                system(buf);
        }
        else
        {
                sprintf(buf,"Only support RS232/RS422/RS485 mode.");
        }

	}
	else if(portnum == 2)
	{
        	iMode1 = 433;
        	iMode2 = 446;
        if(mode== 232)
        {
                sprintf(buf,"echo %d > /sys/class/gpio/export",iMode1);
                system(buf);
                sprintf(buf,"echo out > /sys/class/gpio/%s/direction",sMode3);
                system(buf);
                sprintf(buf,"echo 1 > /sys/class/gpio/%s/value",sMode3);
                system(buf);
                sprintf(buf,"echo %d > /sys/class/gpio/export",iMode2);
                system(buf);
                sprintf(buf,"echo out > /sys/class/gpio/%s/direction",sMode4);
                system(buf);
                sprintf(buf,"echo 0 > /sys/class/gpio/%s/value",sMode4);
                system(buf);
        }
        else if(mode == 422)
        {
                sprintf(buf,"echo %d > /sys/class/gpio/export",iMode1);
                system(buf);
                sprintf(buf,"echo out > /sys/class/gpio/%s/direction",sMode3);
                system(buf);
                sprintf(buf,"echo 1 > /sys/class/gpio/%s/value",sMode3);
                system(buf);
                sprintf(buf,"echo %d > /sys/class/gpio/export",iMode2);
                system(buf);
                sprintf(buf,"echo out > /sys/class/gpio/%s/direction",sMode4);
                system(buf);
                sprintf(buf,"echo 1 > /sys/class/gpio/%s/value",sMode4);
                system(buf);
        }
        else if(mode == 485)
        {
                sprintf(buf,"echo %d > /sys/class/gpio/export",iMode1);
                system(buf);
                sprintf(buf,"echo out > /sys/class/gpio/%s/direction",sMode3);
                system(buf);
                sprintf(buf,"echo 0 > /sys/class/gpio/%s/value",sMode3);
                system(buf);
                sprintf(buf,"echo %d > /sys/class/gpio/export",iMode2);
                system(buf);
                sprintf(buf,"echo out > /sys/class/gpio/%s/direction",sMode4);
                system(buf);
                sprintf(buf,"echo 1 > /sys/class/gpio/%s/value",sMode4);
                system(buf);
        }
        else
        {
                sprintf(buf,"Only support RS232/RS422/RS485 mode.");
        }
	}
        else
	{
               return;
	}

}



void switch_mode(int com , int mode)
{
     char fn[50];
     int fd;
     struct termios T_new;

     switch(com)
     {
      case 1:
           sprintf(fn,"/dev/ttyTHS0");
           break;
      case 2:
           sprintf(fn,"/dev/ttyTHS4");
           break;
      
     }

     fd = open(fn, O_RDWR | O_NOCTTY | O_NDELAY);
     switch(mode)
     {
     	case 232:
	     tcgetattr(fd, &T_new);
	     T_new.c_cflag |= CRTSCTS; 
	     tcsetattr(fd, TCSANOW, &T_new);
	     close(fd);
             break;
       case 422:
       case 485:
	     tcgetattr(fd, &T_new);
	     T_new.c_cflag &= ~CRTSCTS; 
	     tcsetattr(fd, TCSANOW, &T_new);
	     close(fd);
             break;
     }
     change_io_sta(com,mode);

     printf("Switch COM%d(%s) to %d mode\n",com,fn,mode);
     

     return;
}

void print_help()
{
     printf("Example: vig_setcom.exe com mode\n");
     printf("com  => 1/2\n");
     printf("mode => 232/422/485\n");
     printf("COM1 => /dev/ttyTHS0\n");
     printf("COM2 => /dev/ttyTHS4\n");
     
     
}


int main(int argc, char	*argv[])
{
    int com = 0; // 
    int mode = 0; // 232 / 485 / 422
    unsigned char flag_error = 0;
    
    
    if(argc!=3)
    {
     goto error;
    }
    
    com = atoi(argv[1]);
    if(com < 1 || com >2)
    {
      goto error;
    }
    
    mode = atoi(argv[2]);
    if((mode != 232)&& (mode != 422)&& (mode != 485) )
    {
      goto error;
    }
    
    switch_mode(com,mode);
    
    return 0;
    
    error:
    	print_help();
    return 0;
    
}

