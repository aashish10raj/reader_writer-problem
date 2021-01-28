#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include<stdint.h>

void * reader(void *) ;  
 void *writer (void *) ;  
 sem_t writeblock,mutex ;  
 int readcount=0 ;
 int data=0;  
 int main()  
 {  
  //int a=1,b=1;  
  int i,b;
     system("clear");  
     pthread_t rtid[5],wtid[5];
  sem_init(&writeblock,0,1) ;  
  sem_init(&mutex,0,1) ;  
  for(i=0;i<=3;i++)
  {
    pthread_create(&wtid[i],NULL,writer,(void *)i);
    pthread_create(&rtid[i],NULL,reader,(void *)i);
  }
  for(i=0;i<=3;i++)
  {
    pthread_join(wtid[i],NULL);
    pthread_join(rtid[i],NULL);
  }
  
  
 }  
 void * reader(void * arg)  
 {  
  int c=(int)arg ;  
  printf("\nreader %d is created",c);  
     sleep(1);  
  sem_wait(&mutex) ;  
     readcount++;  
     if(readcount==1)  
         sem_wait(&writeblock) ;  
  sem_post(&mutex) ;  
 /*Critcal Section */  
  printf("\n\nreader %d is reading data %d\n ",c,data);  
  sleep(1) ;  
  printf("\nreader%d finished reading\n",c);  
 
  sem_wait(&mutex) ;  
     readcount-- ;  
     if(readcount==0)  
         sem_post(&writeblock) ;  
  sem_post(&mutex) ;  
 }  
 void * writer(void * arg)  
 {  
 int c=(int)arg ;  
  printf("\nwriter %d is created",c);  
     sleep(1);  
  sem_wait(&writeblock) ;  
  data++;
  printf("\nwriter %d is writing data %d\n",c,data) ;  
  sleep(1);  
  printf("\nwriter%d finished writing\n",c);  
  sem_post(&writeblock) ;  
 }
