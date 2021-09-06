#include <sys/sem.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

key_t key = 1011;
#define SEMA_READ 0
#define SEMA_WRITE 1

void P(int sem_id, int num) {
  struct sembuf op;
  op.sem_num=num;
  op.sem_op=-1;
  op.sem_flg=0;
  semop(sem_id, &op, 1);
}

void V(int sem_id, int num) {
  struct sembuf op;
  op.sem_num=num;
  op.sem_op=+1;
  op.sem_flg=0;
  semop(sem_id, &op, 1);
}
/*
union semun {
    int val;
    struct semid_ds *buf;
    ushort *array;
};
*/

int main(int argc, char *argv[]) {

  if(argc != 2) {
    printf("error arg\n");
    exit(-1);
  }
  int id = atoi(argv[1]);
 

  int sem_id = semget(key, 0, SEM_R | SEM_A);
  //int sem_id = semget(key, 1, IPC_CREAT | 0666);
  if(sem_id == -1) {
    perror("semget");
    exit(-1);
  }

  P(sem_id, SEMA_WRITE);
  fprintf(stderr, "Writing in SHM...%d\n", id);
  V(sem_id, SEMA_READ);

}
