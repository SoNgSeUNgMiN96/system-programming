#include <stdlib.h>    /*environ.c*/                                                        
#include <stdio.h>                                                             
#include <string.h>                                                            

//환경변수이름을 통한 값을 확인해주는 프로그램입니다.
                                                                               
int main(int argc, char *argv[])                                               
{                                                                              
        char *var, *value;                                                     
        if(argc != 2) {                                             
                fprintf(stderr,"usage: environ var [value]\n");                
                exit(1);                                                       
        } 
	var = argv[1];                                                         
        value = getenv(var);                                                   
        if (value)                                                              
           printf("Variable %s has value %s\n", var, value);              
        else                                                                   
           printf("Variable %s has no value\n", var); 
}

