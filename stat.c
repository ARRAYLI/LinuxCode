#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<pwd.h>     // 所有者信息
#include<grp.h>     // 所属组信息
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>


int main(int argc,char *argv[])
{
	if( argc<2 )
	{
		perror("./a.out filename\n");	
		exit(1);
	}

	struct stat st;		

	int ret = stat(argv[1],&st);   // 获取文件或者目录的所有信息存储于 st 结构体中

	if( ret == -1 )
	{
		perror("stat");
		exit(1);
	}

	// 存储文件类型和访问权限

	char perms[11] = {0};

	// 判断文件类型

	switch( st.st_mode & S_IFMT )
	{
		case S_IFSOCK:   // 套接字文件
			perms[0] = 's';
			break;
		case S_IFLNK:	 // 软连接文件
			perms[0] = 'l';
			break;
		case S_IFREG:	 // 普通文件
			perms[0] = '-';
			break;
		case S_IFBLK:    // 块设备文件
			perms[0] = 'b';
			break;
		case S_IFDIR:    // 目录文件

			perms[0] = 'd';
			break;
		case S_IFCHR:    // 字符设备文件

			perms[0] = 'c';
			break;
		case S_IFIFO:    // 管道文件

			perms[0] = 'p';
			break;
		default:
			break;

	}

	// 判断文件的访问权限
	// 文件的所有者
	perms[1] = (st.st_mode & S_IRUSR) ? 'r':'-';
	perms[2] = (st.st_mode & S_IWUSR) ? 'w':'-';
	perms[3] = (st.st_mode & S_IXUSR) ? 'x':'-';

	// 文件的所属组
	perms[4] = (st.st_mode & S_IRGRP) ? 'r':'-';
	perms[5] = (st.st_mode & S_IWGRP) ? 'w':'-';
	perms[6] = (st.st_mode & S_IXGRP) ? 'x':'-';

	// 文件的其他用户

	perms[7] = (st.st_mode & S_IROTH) ? 'r':'-';
	perms[8] = (st.st_mode & S_IWOTH) ? 'w':'-';
	perms[9] = (st.st_mode & S_IXOTH) ? 'x':'-';

	// 硬链接计数

	int nums = st.st_nlink;

	// 文件所有者

	char *fileuser = getpwuid(st.st_uid)->pw_name;

	// 文件所属组
	char *filegroup = getgrgid(st.st_gid)->gr_name;

	// 文件大小
	int size = (int)st.st_size;

	// 文件修改时间

	char *time = ctime(&st.st_mtime);
	char mtime[512]="";
	strncpy(mtime,time,strlen(time)-1);

	// 保存输出信息格式
	char buf[1024]={0};

	// 把对应信息按格式输出到 buf 中
	sprintf(buf,"%s %d %s %s      %d %s %s",perms,nums,fileuser,filegroup,size,mtime,argv[1]);

	// 打印 buf 
	printf("%s\n",buf);

	//	drwxrwxr-x 3 arrayli arrayli      4096 11月 13 23:19 day05
	//	-rw-r--r-- 1 arrayli arrayli      8980 11月  7 22:05 examples.desktop


	return 0;
}


