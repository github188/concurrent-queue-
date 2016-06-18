//Two-Lock Concurrent Queue Algorithm DataStructure
//with TAS lock


#define ElementType int
#include <pthread.h>
#include <stdbool.h>

typedef struct QNode  
{  
  ElementType value;  
  struct QNode *Next;  
} *QNodePtr;  
  
struct Node {  
  QNodePtr Front;  
  QNodePtr Rear;  
  pthread_spinlock_t H_lock;
  pthread_spinlock_t T_lock; 
};  
//
//struct Node;  
//struct QNode;  
typedef struct Node *PtrToNode;  
typedef PtrToNode Queue;  
  
  
void  
initqueue( Queue Q );
 
void Enqueue(Queue Q,ElementType X );  

bool Dequeue(Queue Q, ElementType *result); 
