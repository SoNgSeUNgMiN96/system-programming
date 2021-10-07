#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if((argc<3 || argc>4) || (argc==4 && strcmp(argv[1], "-s")))	//argc가 3또는 4가아닌경우 또는 4지만 옵션이 -s가 아닌경우 아래처럼 옵션을 넣으라고 해야함
	{
		printf("Usage: %s  %s\n", argv[0],"<orig_file> <new_file>");
		return 1;
	}
	if(argc==4)
		return symlink(argv[2], argv[3]);	/* create symbolic link */
	else
		return link(argv[1], argv[2]);	/* create hard link */
}

