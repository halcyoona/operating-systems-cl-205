#include<stdio.h>
#include<sys/types.h>
#include<sys/dir.h>

void main(int argc,char *argv[])
{
	DIR *dir;
	struct dirent *rddir;
	printf("\n Listing the directory content\n");
	dir=opendir(argv[1]);
	while((rddir=readdir(dir))!=NULL)
	{
		printf("%s\t\n",rddir->d_name);
		printf("%d\t\n",rddir->d_size);
	}
	closedir(dir);
}