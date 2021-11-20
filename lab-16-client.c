#include <sys/types.h>
#include <sys/socket.h>
#include <sys/unistd.h>
#include <sys/un.h>
#include <stdio.h>
#include <string.h>
#define NAME "socket"

int main() 
{ 
	int	sock;
	struct sockaddr_un name;
	char buf[1024];
	
	sock=socket(PF_UNIX, SOCK_DGRAM, 0);
	name.sun_family=PF_UNIX;
	strcpy(name.sun_path, NAME); 
	printf("socket %s\nsun_path = %s\n",NAME,name.sun_path);

	scanf("%s",buf);
	//printf("%s\n",buf);
	sendto(sock, (const char*)buf, 1024, 0,(struct sockaddr*)&name, sizeof(struct sockaddr_un)); //서버에게 본인의 주소와 경로를 전송 (여기서는 PF_UNIX와 PATH에는 socket이라는 문자열을 임의로 넣어줌)
	
	//printf("전송완료 ? \n");
	unlink(NAME); 
	close(sock);
}

