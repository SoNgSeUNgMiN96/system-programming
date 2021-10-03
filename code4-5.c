#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

typedef struct dirent Dirent;

int main(int argc, char *argv[])
{
	Dirent *dp;
	DIR *dir_fd;

	while(--argc > 0)	{
		if(!( dir_fd = opendir(*++argv)))	{	//file 이 없어서 NULL을 리턴받는다면
			if(mkdir(*argv, S_IRWXU|S_IRWXG|S_IRWXO)==-1)	//dir 생성
				perror("opendir");
			continue;
		}
		for(int i=0; i<2; i++)	{
			int cnt=0;
			for(; (dp=readdir(dir_fd)); )	{	//dp에 엔트리가 없을때까지 엔트리를 하나씩 읽어들여옴
				if(i) printf("%s\n", dp->d_name);	//
				if(strcmp(dp->d_name, ".") && strcmp(dp->d_name, ".."))	//. 과 .. 이외의 엔트리가 있을 경우에 cnt++
				cnt++;
			}
			if(!cnt) {rmdir(*argv);	break;} //빈 dir이라면 지워줌
			rewinddir(dir_fd);
		}
		closedir(dir_fd);
	}
}

