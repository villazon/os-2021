#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGSZ     128
typedef struct msgbuf {
    long    mtype;
    char    mtext[MSGSZ];
} message_buf;

int main(int argc, char *argv[])
{
    int msqid;
    key_t key = 1234;
    message_buf  rbuf;

    /* get the MQ with name “1234” created by the server */
    msqid = msgget(key, 0666); 

    /* get message with type 1 */
    msgrcv(msqid, &rbuf, MSGSZ, 1, 0);

    printf("%s\n", rbuf.mtext); /* print answer */

    exit(0);
}
