#include <stdio.h>
#include <termios.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>




void print_help()
{
     printf("Example: serial.exe com\n");
     printf("com  => 1/2\n");
     printf("com1 => /dev/ttyHS0\n");
     printf("com2 => /dev/ttyHS4\n");
     
     
}


int main(int argc, char	*argv[])
{

	int	fd, interface, ret, mode;
	char	buf[1024];
	struct termios T_new;
    int i;
    
    char fn[50];    
    
    int idx = 8;
    if(argc == 2)
    {
    switch(atoi(argv[1]))
    {
     case 1:
          idx = 0;
     break;
     case 2:
          idx = 4;
     break;
    }
    }
    
    if(idx!=1&&idx!=0)
    {
     print_help();
     return 0;
    }
    printf("/dev/ttyTHS%d\n",idx);
    sprintf(fn,"/dev/ttyTHS%d",idx);
    fd = open(fn, O_RDWR | O_NOCTTY | O_NDELAY);

	
	if (fd == -1) {
		printf("open %s Failed, errno: %d\r\n",fn, errno);
		return 0;
	}



        if (tcgetattr(fd, &T_new) != 0) {
		sprintf("tcgetattr failed. errno: %d\r\n", errno);
		close(fd);
		return 0; 	
        }
        
        T_new.c_cflag = (B9600| CS8 | CREAD | CLOCAL | CRTSCTS);
	T_new.c_oflag = 0;
        T_new.c_iflag = 0;
        T_new.c_lflag = 0;
        

        if (tcsetattr(fd, TCSANOW, &T_new) != 0) {
		close(fd);
		return 0; 
        }
        
      
        
        while(1)
        {
	
                write(fd, "12345", 5);
                sleep(1);


	       
              
                
        } 
        

	return 0;
}
