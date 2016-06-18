#include "twolock.h"
#include "fatal.h"

//Initialize the queue 
void  
initqueue( Queue Q )  
{  
 
  //Q = malloc( sizeof( struct Node ) );  
  struct QNode *node;
  node= malloc( sizeof( struct QNode ) ); 
 
  if (!node)  
    FatalError( "Out of space!!!");  
  node->Next = NULL;
  Q->Front = Q->Rear =  node;
  
  if (pthread_spin_init(&Q->H_lock,PTHREAD_PROCESS_PRIVATE))
      FatalError( "Init header spinlock failed");
  if (pthread_spin_init(&Q->T_lock,PTHREAD_PROCESS_PRIVATE))
      FatalError( "Init tailer spinlock failed");
 
}  
  
//enter queue
void  
Enqueue(Queue Q,ElementType X)  
{  
  QNodePtr p;  
  p = malloc( sizeof( struct QNode ) );  
  if (!p)  
    FatalError( "Out of space!!!" );  
  p->value = X; 
  p->Next = NULL; 
 // printf("test\n");
  //get spin lock , if not free loop
  pthread_spin_lock(&Q->T_lock);
 //if free, insert
  Q->Rear->Next = p;  
  Q->Rear = p;
  //unlock 
  pthread_spin_unlock(&Q->T_lock);  
  printf("Insert Successfully!\n");
}  
  

bool  
Dequeue(Queue Q, ElementType *result)  
{  

    QNodePtr p;  
    p = malloc( sizeof( struct QNode ) );  
    if (!p) 
    {

      FatalError( "Out of space!!!" ); 
      return false;
    } 
       
    pthread_spin_lock(&Q->H_lock);
    p = Q->Front->Next;  
    
    if ( p == NULL ) //the queue is empty
    { 
      pthread_spin_unlock(&Q->H_lock);
      return false;
    } 

    Q->Front= p;
    *result = p->value;
    pthread_spin_unlock(&Q->H_lock);
    printf("Deque Successfully\n");
    free( p ); 
    return true; 

}  

// ElementType  
// FrontAndDequeue( Queue Q )  
// {  
//   if ( !IsEmpty( Q ) )  
//   {  
//     QNodePtr p;  
//     p = malloc( sizeof( QNode ) );  
//     if (!p)  
//       FatalError( "Out of space!!!" );  
//     p = Q->Front->Next;  
//     ElementType temp = 0;  
//     temp = p->Element;  
//     Q->Front->Next = p->Next;  
//     if ( Q->Rear == p )  
//       Q->Rear = Q->Front;  
//     free( p );  
//     return temp;  
//   }  
//   Error( "Empty queue!!!" );  
//   return 0; /* Return value used to avoid warning */  
// }  










