#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGSZ     128  /* message size */
typedef struct msgbuf {
         long    mtype;
         char    mtext[MSGSZ];
} message_buf; /* Message structure */

int main(int argc, char* argv[])
{
    int msqid, msgflg = IPC_CREAT | 0666;
    key_t key = 1234;
    message_buf sbuf;
    size_t buf_length;

    if(argc < 2) {
      printf("Usage: %s \"a message\"\n", argv[0]);
      exit(-1);
    }
    
    fprintf(stderr, "\nmsgget: Calling msgget(%d,%d)\n",key,msgflg);
    msqid = msgget(key, msgflg ); 

    sbuf.mtype = 1; /* We use message type 1 */
    strcpy(sbuf.mtext, argv[1]); /* this is the message */
    buf_length = strlen(sbuf.mtext) + 1 ;

    msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT); /* Send a message */
    printf ("%d, %ld, %s, %ld\n", msqid, sbuf.mtype, sbuf.mtext, buf_length);
    printf("Message: \"%s\" Sent\n", sbuf.mtext);
}
