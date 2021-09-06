#include <sys/sem.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

key_t key = 1010;

void P(int sem_id) {
  struct sembuf op;
  op.sem_num=0;
  op.sem_op=-1;
  op.sem_flg=0;
  semop(sem_id, &op, 1);
}

void V(int sem_id) {
  struct sembuf op;
  op.sem_num=0;
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

int main() {

  int sem_id = semget(key, 0, SEM_R | SEM_A);
  if(sem_id == -1) {
    perror("semget");
    exit(-1);
  }
  fprintf(stderr, "Modifying semaphore\n");
  P(sem_id);

}
