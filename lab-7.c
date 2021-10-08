#include <stdio.h>
#include <stdlib.h>                                                            
#include <limits.h>
#include <unistd.h>

/*
	이 프로그램은 기존 PATH 를 밀어버리고 현재 이 프로그램의 경로로 PATH 를 설정하는 프로그램이나 , 기존 PATH로 복구하는 프로그램입니다.
	만약, PATH에 cwd를 넣은채로 저장하려면 setenv("PATH",PATHTEMP,1); 라인을 주석처리하면됩니다.
*/


int main(){
	
	char *PATHTEMP;
	PATHTEMP = getenv("PATH");

	char name[PATH_MAX];
	getcwd(name,PATH_MAX);	

	printf("현재 PATH = %s\n",PATHTEMP);
	printf("현재 cwd = %s\n",name);
	
	setenv("PATH",name,1);
	printf("now PATH = %s\n",getenv("PATH"));
	
	setenv("PATH",PATHTEMP,1);
	printf("now PATH = %s\n",getenv("PATH"));
	
}
