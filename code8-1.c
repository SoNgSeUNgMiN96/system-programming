#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void ouch(int sig);

int main()
{
        signal(SIGINT, ouch);
        while(1){
                printf("Hello World!\n");
                sleep(1);
        }
}

void ouch(int sig)
{
        printf("OUCH! – I got signal %d\n", sig);
   (void) signal(SIGINT, SIG_DFL);
}
