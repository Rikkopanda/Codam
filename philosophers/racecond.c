#include <stdio.h>
#include <pthread.h>

int cont = 0;

void  *routine()
{
  int i;

  i = -1;
  while (++i < 100000000)
  	  cont++;
  return (NULL);
}

int main()
{
  pthread_t tid1, tid2;

  pthread_create(&tid1, NULL, &routine, NULL);
  pthread_create(&tid2, NULL, &routine, NULL);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  printf("cont: %d\n", cont);
}
