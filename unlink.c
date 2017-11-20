#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>



int main(void)
{
	int fd = open("timefile",O_CREAT|O_RDWR,0644);

	if( fd == -1 )
	{
		perror("open");	
		exit(1);	
	}

	int ret =unlink("timefile");
	if( ret == -1 )
	{
		perror("unlink");
		exit(1);
	
	}

	// write file
		
	write(fd,"hello\n",6);

	// 设置文件指针到文件首部

	lseek(fd,0,SEEK_SET);

	// read file

	char buf[20]={0};
	read(fd,buf,sizeof(buf));

	printf("%s\n",buf);



	return 0;
}
