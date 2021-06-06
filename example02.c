#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//
// Created by wfm on 2021/6/6.
//

int practice01();
int practice05();
int practice06();
int practice07();


int practice01(){
    int x = 100;
    int pid = fork();

    if (pid < 0) {
        fprintf(stderr,"fork failed\n");
        exit(1);
    } else if (pid == 0) {
        x = 101;
        printf("hello,I am child (pid:%d) x = %d\n",(int) getpid(),x);
    } else {
        int wr = wait(NULL);
        printf("wait result: %d\n",wr);
        x = 102;
        printf("hello, I am parent of %d (pid:%d) x = %d\n",pid,(int)getpid(),x);
    }
    return 0;
}



