#include <sys/sem.h>
#include <stdio.h>

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
/* ver semctl */
/*
union semun {
    int val;
    struct semid_ds *buf;
    ushort *array;
};
*/

int main() {

  int sem_id = semget(key, 1, IPC_CREAT | 0666 );

  union semun semarg;
  semarg.val = 0; // init sema 
  semctl(sem_id, 0, SETVAL, semarg);


  while(1) {
    P(sem_id); // enter critical region
    fprintf(stderr, "Critical Region\n");
    V(sem_id);
  }
  
  semctl(sem_id, 0, IPC_RMID, NULL); // should be in signal handler..
  
}
