#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t q = fork();
    if(q==0){
        printf("child process");
    }
    else{
        wait(NULL);
        printf("parent process");
    }
    return 0;
}