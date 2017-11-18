#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	if( argc<2 )
	{
		perror("a.out ");
		exit(1);
	}

	struct stat st;

	int ret = lstat(argv[1],&st);
	if( ret == -1)
	{
		perror("lstat");
		exit(1);
	}

	int size = st.st_size;

	printf("file size = %d\n",size);

	return 0;
}
