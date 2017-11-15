#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


// 获取 root 目录下的文件个数
int get_file_count(char *root)
{
	// open dir
	DIR * dir = NULL;
	dir = opendir(root);
	if( NULL == dir )
	{
		perror("opendir");
		exit(1);
	}

	// 遍历当前打开的目录
	struct dirent* ptr = NULL;
	char path[1024]={0};
	int total = 0;
	while( (ptr = readdir(dir) )!= NULL)
	{
		// 过滤掉 . 和 ..
		if( strcmp(ptr->d_name,".") == 0 || strcmp(ptr->d_name,"..") == 0 )
		{
		
			continue;	
		}
	
		// 如果是目录，递归读目录
		if(ptr->d_type == DT_DIR)
		{
			sprintf(path,"%s/%s",root,ptr->d_name);
			total += get_file_count(path);
		}

		// 如果是普通文件
		if( ptr->d_type == DT_REG )
		{
				total++;	
		}
	}
	
	// 关闭目录
	closedir(dir);
	return total;
}

int main(int argc,char *argv[])
{
	if( argc<2 )
	{
		perror("./a.out dir\n");
		exit(1);	
	}

	// 获取文件个数
	int count =	get_file_count(argv[1]);

	printf("%s has file numbers : %d\n",argv[1],count);	
	return 0;
}
