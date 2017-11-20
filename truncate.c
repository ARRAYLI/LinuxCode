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

	int ret = truncate(argv[1],1024);
	if( ret == -1 )
	{
		perror("truncate");
		exit(1);
	}
	return 0;
}
