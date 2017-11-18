#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
	int fd = 0;
	int fd_write = 0;

	int size = 0; 
	char buf[1024] = "";

	fd = open("./open.c",O_RDONLY);
	if( fd == -1 )
	{
	
		perror("open file:");
		exit(1);
	}


	// 创建一个新的文件
	fd_write = open("stdio1.h",O_RDWR|O_CREAT|O_TRUNC,0777);

	if( fd_write == -1 )
	{
	
		perror("open file:");
		exit(1);
	}


	// 读文件 
	size = read(fd,buf,sizeof(buf));
	if(size == -1 )
	{
		perror("read file:");
		exit(1);
	
	}
	while( size )
	{

		// 读文件 
		size = read(fd,buf,sizeof(buf));
		// 读文件 
		size = read(fd,buf,sizeof(buf));
		
		printf("buf = %s\n",buf);
		// 创建文件
		// 写文件
		write(fd_write,buf,strlen(buf));

	    // 清空缓冲区
		memset(buf,0,sizeof(buf));

	}


    	
	close(fd);

	close(fd_write);

	return 0;
}
