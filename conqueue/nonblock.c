#include "nonblock.h"
#include "fatal.h"

//define CAS
bool CAS(T * addr, T expected, T value) {

   if (*addr == expected) {

      *addr = value;

      return true;

   }

   return false;

} 
//Initialize the queue 
void  
Initialize( Queue Q )  
{  
 
  //Q = malloc( sizeof( struct Node ) );  
  node_t  node = malloc( sizeof( struct node) ); 
 
  if (!node)  
    FatalError( "Out of space!!!");  
  node->Next.ptr = NULL;
  Q->Header.ptr = Q->Tail.ptr =  node;
}  
  
//enter queue
void  
Enqueue(Queue Q,ElementType value)  
{  
  node_t  node = malloc( sizeof( struct node) );  
  if (!node)  
    FatalError( "Out of space!!!" );  
  node->value = value; 
  node->next = NULL; 
  while(1)
  {
      pointer_t tail = Q->Tail;
      pointer_t next = tail.ptr->next;
      if (tail == Q->Tail)
      {
            // Try to link node at the end of the linked list
           if (next.ptr == NULL) 
           {

              pointer_t nextptr = malloc( sizeof( struct pointer );
              nextptr->ptr = node;
              nextptr->count = next.count + 1;

              if (CAS(&tail.ptr->next, next, nextptr)
                break;  // Enqueue is done.  Exit loop


           }

      }
      else 
      {
           pointer_t nextptr = malloc( sizeof( struct pointer );
           nextptr->ptr = next.ptr;
           nextptr->count = tail.count + 1;            
           CAS(&Q->Tail, tail, nextptr);
      }



  }
   // Enqueue is done.  Try to swing Tail to the inserted node
   pointer_t nextptr = malloc( sizeof( struct pointer );
   nextptr->ptr = node;
   nextptr->count = tail.count + 1;  
   CAS(&Q->Tail, tail, nextptr);     

}  
  
bool Dequeue(Queue Q,ElementType *pvalue)
{
  while(1)
  {
      pointer_t head = Q->Head;
      pointer_t tail = Q->Tail;
      pointer_t next = tail.ptr->next;
      if (head == Q->Head)      // Are head, tail, and next consistent?
          if (head.ptr == tail.ptr) // Is queue empty or Tail falling behind?
          {
            if (next.ptr == NULL) // Is queue empty?
                 return false;      // Queue is empty, couldn't dequeue
            // Tail is falling behind.  Try to advance it
            pointer_t nextptr = malloc(sizeof( struct pointer );
            nextptr->ptr = next.ptr;
            nextptr->count = tail.count + 1; 
            CAS(&Q->Tail, tail,nextptr);
          }
          else 
          {      // No need to deal with Tail
                  // Read value before CAS
                  // Otherwise, another dequeue might free the next node
            *pvalue = next.ptr->value

                  // Try to swing Head to the next node
            pointer_t nextptr = malloc( sizeof( struct pointer );
            nextptr->ptr = next.ptr;
            nextptr->count = head.count + 1; 
            if (CAS(&Q->Head, head, nextptr))
              break             // Dequeue is done.  Exit loop
            
           }
  }
  free(head.ptr);
  return true;
}













