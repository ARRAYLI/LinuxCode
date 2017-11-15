#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>


int main(int argc, char *argv[] )
{

	if( argc<2 )
	{
		perror("./a.out filepath");
		exit(1);
	}

	printf(" agrv[1] = %s\n",argv[1]);
	// 修改当前的路径
	int ret =chdir(argv[1]);
	if( ret == -1 )
	{
		perror("chdir");
		exit(1);	
	}

	// 在这里通过在改变后的目录下创建一个新的文件，来证明目录已经改变
	int fd = open("chdir.txt",O_CREAT|O_RDWR,0644);
	if( fd == -1 )
	{
		perror("open");	
		exit(1);
	}

	close(fd);

	// 获取改变目录后的目录名
	char buf[100]={0};

	getcwd(buf,sizeof(buf));
	printf("current dir: %s\n",buf);

	return 0;
}
