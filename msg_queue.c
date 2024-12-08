// THE SENDER

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/ipc.h> 
#include <sys/msg.h>

#define MAX 100 struct message_buffer {
long message_type;
char message_text[MAX];
} message;

int main() { key_t key; int msgid;

key = ftok("progfile", 65);


msgid = msgget(key, 0666 | IPC_CREAT); message.message_type = 1;

printf("Enter a message: "); fgets(message.message_text, MAX, stdin);


msgsnd(msgid, &message, sizeof(message), 0); printf("Message sent: %s", message.message_text);
return 0;
}



// THE RECEIVER

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <sys/ipc.h> 
#include <sys/msg.h>
#define MAX 100 struct message_buffer {
long message_type;
char message_text[MAX];
} message; int main() {
key_t key; int msgid;

key = ftok("progfile", 65);

msgid = msgget(key, 0666 | IPC_CREAT); msgrcv(msgid, &message, sizeof(message), 1, 0); printf("Message received: %s", message.message_text); msgctl(msgid, IPC_RMID, NULL);
return 0;
}
