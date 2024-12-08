# include <stdio.h>
#include <stdlib.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <string.h>

int main() { int fd;
char *fifo = "/tmp/myfifo";
char writeMessage[] = "Hello from parent!"; char readMessage[100];
mkfifo(fifo, 0666); pid_t pid = fork();
if (pid < 0) { perror("Fork failed"); return 1;
}

if (pid == 0) {
fd = open(fifo, O_RDONLY);
read(fd, readMessage, sizeof(readMessage)); printf("Child received: %s\n", readMessage); close(fd);
} else {
fd = open(fifo, O_WRONLY);
write(fd, writeMessage, strlen(writeMessage) + 1); printf("Parent sent: %s\n", writeMessage); close(fd);
}
unlink(fifo);

return 0;
}
