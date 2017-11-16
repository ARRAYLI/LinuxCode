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

	int ret = access(argv[1],W_OK);
	if( ret == -1 )
	{
		perror("access");
		exit(1);
	}
	printf("You can write this file\n");

	return 0;
}
