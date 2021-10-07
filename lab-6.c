/*
   이 프로그램은 dirname과 suffix를 입력받아 해당 dir 내에 suffix가 동일한 첫 번째 파일을 확인하고 , 그 파일의 inode와 파일명을 출력해주는 프로그램입니다.
   ./실행파일명 dirname suffix 를 입력하여 사용합니다. 
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>

typedef struct dirent Dirent;

int match(char *s1, char *s2){  
    int diff = strlen(s1) - strlen(s2);     //접미사를 확인하므로 마지막 인덱스에서 접미사의 글자수만큼 인덱스를 뺌
    if (strlen(s1) > strlen(s2))  return(strcmp(&s1[diff], s2) == 0) ;  //마지막 글자들을 비교하여 동일한지를 확인함 
    else  return(0); 
}


int main(int argc, char *argv[])
{
	Dirent *dp;
	DIR *dir_fd;
    struct stat buf;

    if(argc!=3){
        printf("Usage : ./a.out <dirname> <suffix>\n");
        exit(1);
    }
        

    if(!(dir_fd = opendir(argv[1])))
        perror("dir_fd");
	else
        printf("dir %s opened\n",argv[1]);
    

	for(; (dp=readdir(dir_fd)); )	{	//dp에 엔트리가 없을때까지 엔트리를 하나씩 읽어들여옴
        
        if(match(dp->d_name,argv[2])){  
            stat(dp->d_name,&buf);
            printf("inode = %llu\nfilename = %s\n",buf.st_ino,dp->d_name);
            break;
        }
	}
	closedir(dir_fd);
	
}

