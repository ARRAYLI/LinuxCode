#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int fd =open("a.txt",O_RDWR);
	if( fd == -1 )
	{
		perror("open");
		exit(1);
	}

	printf("file open fd = %d\n",fd);

	// 找到进程文件描述符表   ======= 第一个========== 可用的文件描述符
	// 将参数指定的文件复制到该描述后          返回这个描述符

	int ret = dup(fd);
	if( fd == -1 )
	{
		perror("dup");
		exit(1);
	}

	printf(" dup fd = %d\n",ret);
	char *buf = "你是猴子请来的救兵吗？？\n";
	char *buf1 = "你大爷的，我是程序猿!!!\n";

	write(fd,buf,strlen(buf));
	write(ret,buf1,strlen(buf1));

	close(fd);
	
	return 0;
}
