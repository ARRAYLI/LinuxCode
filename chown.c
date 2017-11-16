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

	// user->ftp   grop->ftp
	int ret = chown(argv[1],116,125);
	if( ret == -1 )
	{
		perror("chown");
		exit(1);
	}

	return 0;
}
