//part1: posix multi-threads
//part2: posix concurrent queue realizing


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#ifdef twolock

#include "twolock.h"

#else

#include "nonblock.h"

#endif
//#include <linux/spinlock.h>




Queue Q;
void *thread(void *threadid)
{
	int tid;
	tid = (int)threadid;
	printf("Hello World! It's me, thread #%d!\n", tid);
	pthread_exit(NULL);
}

void *EQ()
{
  int i;
  for (i=0; i<2;i++)
  { 
  int n;
  printf( "Thread %d: Enqueu data in queue:\n",pthread_self());
  scanf( "%d", &n );
  Enqueue( Q,n );
  }
}
void *DQ()
{
  
   
  int result,i;
  for(i =0; i < 2;i++)
  {
  printf( "Thread %d  get data in queue:\n",pthread_self());
  Dequeue(Q, &result);
  printf("%d\n",result);
  }
}
int main(void)
{
	  int n, num, m,i,j;  
          #ifdef twolock
	  Q = malloc( sizeof( struct Node ));  
          #else
         
	  Q = malloc( sizeof( queue_t ));
	  #endif  
          initqueue(Q);
	  printf( "Initialization complete.\n" );  
	  for (i = 0;i < 2;i++)
	  {
		
		pthread_t t = i;
		pthread_create(&t,NULL,EQ,NULL);
		pthread_join(t,NULL);
	  }          
	   
	  for (j = 2;j < 4;j++)
	  {
		
		pthread_t t = j;
		pthread_create(&t,NULL,DQ,NULL);
		pthread_join(t,NULL);
	  }

	  
	  //if ( IsEmpty( Q ) )  
	    //printf( "Queue is empty \n" );  
	 // printf( "Please input the number of elements in the queue:" );  
	  //scanf( "%d", &n );  
	  //printf( "Please input %d elements put in queue:\n", n );  
	  /*for(i = 0; i < n; i++ )  
	  {  
	    scanf( "%d", &num );  
	    Enqueue( Q,num );  
	  }  
	  //printf( "Front element: %d.\n", Front( Q ) );  
	  printf( "Elements in queue:\n" );  
	 // while ( !IsEmpty( Q )) {  
	   // printf( "%3d", FrontAndDequeue( Q ) );  
	 // }  
	 // DisposeQueue( Q );  
	  int result;
	  for(i = 0; i < n; i++ )
          {
            //scanf( "%d", &num );
            Dequeue(Q, &result);
	    printf("%d\n",result);
          }
	  printf( "\n" );  
		*/

	// pthread_spinlock_t spinlock;
	// static pthread_rwlock_t my_rwlock = PTHREAD_RWLOCK_INITIALIZER;
	// pthread_t id;
	// void *ret;
	// int i,retv;
	// int t=123;
	// retv=pthread_create(&id,NULL,(void *) thread,(void *)t);
	// if (retv!=0)
	// {
	// 	printf ("Create pthread error!/n");
	// 	return 1;
	// }
	// for (i=0;i<3;i++)
	// 	printf("This is the main process.\n");
	// pthread_join(id,&ret);
	// printf("The thread return value is%d\n",(int)ret);
	// return 0;

}
