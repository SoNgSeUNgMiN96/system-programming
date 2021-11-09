#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#define OUTPUT "count-prime.out"
#define MAXNUM 10000

int count;
FILE *fptr;

void sigcatch()
{
        printf("%d primes computed\n", count);
        fclose(fptr);
        exit(1);
}

int main()
{
        int number, divisor;
        void sigcatch();

        fptr = fopen(OUTPUT,"w");
        signal(SIGINT, sigcatch);
        for(number = 1; number <= MAXNUM; number++){
                for(divisor = 2; divisor < number; divisor++)
                        if ((number % divisor) == 0) break;
                if(divisor == number){
                        fprintf(fptr, "%d\n", number);
                        count++;
                }
        }
}
