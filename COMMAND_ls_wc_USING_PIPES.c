// COMMAND ls|wc USING PIPES

#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 

int main() {
int fd[2];
pipe(fd);
pid_t pid = fork(); if (pid == 0) {
close(fd[0]);
dup2(fd[1], STDOUT_FILENO);
close(fd[1]);
execl("/bin/ls", "ls", NULL);
} else if (pid > 0) { close(fd[1]);
dup2(fd[0], STDIN_FILENO);
close(fd[0]);
execl("/usr/bin/wc", "wc", NULL);
} else {
perror("fork failed"); return 1;}
return 0;
}
