#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>


int main(void)
{
	int fd = open("./bb.txt",O_RDWR);

	if( fd == -1)
	{
		perror("open bb.txt:");
		exit(1);
	}

	int ret = lseek(fd,0,SEEK_END);
	printf("file length = %d\n",ret);

	
	// 文件扩展
	ret = lseek(fd,2000,SEEK_END);
	printf("return value = %d\n",ret);

	// 实现文件拓展，需要最后一次写操作

	write(fd,"a",1);

	close(fd);
	

	return 0;
}
