// Demonstration of execl() where child process executes "ls" COMMAND and Parent process executes "date" COMMAND.

#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h>


int main() {
pid_t pid = fork();

if (pid == 0) {
execl("/bin/ls", "ls", NULL);
} else {
wait(NULL);
execl("/bin/date", "date", NULL);
}
return 0;
}
