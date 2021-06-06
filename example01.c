#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int test01(){
    printf("hello world (pid:%d)\n",getpid());
    int pid = fork();

    if (pid < 0) {
        fprintf(stderr,"fork failed\n");
        exit(1);
    } else if (pid == 0) {
        printf("hello,I am child (pid:%d)\n",(int) getpid());
    } else {
        printf("hello, I am parent of %d (pid:%d)\n",pid,(int)getpid());
    }
    return 0;
}

int test02(){
    printf("hello world (pid:%d)\n",getpid());
    int pid = fork();

    if (pid < 0) {
        fprintf(stderr,"fork failed\n");
        exit(1);
    } else if (pid == 0) {
        printf("hello,I am child (pid:%d)\n",(int) getpid());
    } else {
        int cw = wait(NULL);
        printf("hello, I am parent of %d (cw:%d) (pid:%d)\n",pid,cw,(int)getpid());
    }
    return 0;
}
