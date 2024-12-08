#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t q = fork();
    if(q==0){
        sleep(2);
        printf("child process, my id is %d \n",getpid());
        printf("my parent id is %d \n",getppid());
    }
    else{
        printf("parent process, my id is %d \n",getpid());
        printf("my child id is %d \n",q);
    }
    printf("common");
    return 0;
}