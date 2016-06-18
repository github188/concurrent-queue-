//Non-Blocking Concurrent Queue Algorithm Data Structure
//with CAS lock

#define ElementType int
#define T pointer_t
#include <stdbool.h>
#include <pthread.h>


//data structure of of point
typedef struct pointer
{
	struct node  *ptr;
	unsigned int count;

}pointer_t;

//tdata structure of node
typedef struct node
{  
  ElementType value;  
  pointer_t   next;  
}node_t;  
  
 //data structure of queue
typedef struct queue {  
  pointer_t Head;  
  pointer_t Tail;  
}queue_t;  


typedef struct queue_t*  Queue;  

void Initialize( Queue Q ); 
 
void Enqueue( ElementType X, Queue Q );  

bool Dequeue(ElementType *result, Queue Q);
bool CAS(T * addr, T expected, T value);
