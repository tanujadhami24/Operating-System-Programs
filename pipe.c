#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
    int fd[2],n;
    char buffer[100];
    pid_t p;
    pipe(fd);
    p = fork();
    if(p>0){
        printf("passing value to child\n ");
        write(fd[1],"hello\n",6);
    }
    else{
        printf("receiving data from parent ");
        n = read(fd[0],buffer,100);
        write(1,buffer,n);
    }
    return 0;
}