#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int flag;
	int fd;

	// 测试字符串

	char *p = "我们是一个由中国特使社会主义的国家！！！！！";
	char *q ="呵呵，社会主义好哇";

	// 以只写方式打开文件

	fd = open("test.txt",O_WRONLY);
	if( fd == -1 )
	{
		perror("open");
		exit(1);
	
	}

	// 输入新的内容，该内容会覆盖原来的内容
	if( write(fd,p,strlen(p)) == -1 )
	{
		perror("write");
		exit(1);
	}

	//	使用 F_GETFL 命令得到文件状态标志
	int flags = fcntl(fd,F_GETFL,0); 
	if( flags == -1 )
	{
		perror("fcntl");
		exit(1);
	}

	//	将文件状态标志添加 “追加写” 选项

	flag |= O_APPEND;

	// 将文件状态修改为追加写

	if( fcntl(fd,F_SETFL,flag) == -1 )
	{
		perror("fcntl");
		exit(1);
	}

	// 再次输入新的内容，该内容会追加到旧内容对的后面

	if( write(fd,q,strlen(q)) == -1 )
	{
		perror("write again");
		exit(1);
	}
	
	return 0;
}
