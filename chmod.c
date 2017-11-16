#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	if( argc<2 )
	{
		perror("a.out filename");
		exit(1);
	}

	int ret = chmod(argv[1],0777);
	if( ret == -1 )
	{
		perror("chmod");
		exit(1);
	}

	return 0;
}
