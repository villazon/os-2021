#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>

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
/* ver semctl */
/*
union semun {
    int val;
    struct semid_ds *buf;
    ushort *array;
};
*/

int main() {

  int sem_id = semget(key, 2, IPC_CREAT | 0666 );

  union semun semarg;
  semarg.val = 0; // init SEMA_READ = 0 
  semctl(sem_id, SEMA_READ, SETVAL, semarg);

  semarg.val = 1; // init sema 
  semctl(sem_id, SEMA_WRITE, SETVAL, semarg);


  while(1) { 
    P(sem_id, SEMA_READ); // enter critical region
    fprintf(stderr, "Critical Region\n");
    fprintf(stderr, "Reading SHM...\n");
    sleep(1);
    V(sem_id, SEMA_WRITE);
  }
  
  semctl(sem_id, 0, IPC_RMID, NULL); // should be in signal handler..
  
}
