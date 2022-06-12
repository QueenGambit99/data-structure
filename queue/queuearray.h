
/**********************************INCLUDES**********************************/

#include <stdio.h>

/**********************************DEFINES**********************************/

#define QUEUEENTRY int
#define MAXQUEUE   100

/**********************************STRUCTERS**********************************/

/* struct of queue */
typedef struct Queue
{
  QUEUEENTRY entry[MAXQUEUE];
  int        size;
  int        rear;
  int        front;
}queue;

/******************************FUNCTIONS BODIES******************************/

/* CreateQueue() */
void CreateQueue(queue *pq)
{
  pq->front = 0;
  pq->rear = -1;
  pq->size = 0;
}

/* ClearQueue() */
void ClearQueue(queue *pq)
{
  pq->front = 0;
  pq->rear = -1;
  pq->size = 0;
}

/* InQueue() */
void InQueue(QUEUEENTRY e, queue *pq)
{
  pq->rear = (pq->rear + 1) % MAXQUEUE;
  pq->entry[pq->rear] = e;
  pq->size ++;
}

/* DeQueue */
void DeQueue(QUEUEENTRY *pe, queue *pq)
{
  *pe = pq->entry[pq->front];
  pq->front = (pq->front + 1) % MAXQUEUE;
  pq->size --;
}

/* QueueSize() */
int QueueSize(queue *pq)
{
  return pq->size;
}

/* QueueFull() */
int QueueFull(queue *pq)
{
  return (pq->size == MAXQUEUE);
}

/* QueueEmpty */
int QueueEmpty(queue *pq)
{
  return !pq->size;
}

/* QueueFront */
int QueueFront(QUEUEENTRY *pe, queue *pq)
{
  *pe = pq->entry[pq->front];
  return *pe;
}

/* TraverseQueue */
void TraverseQueue(queue *pq, void (*pf) (QUEUEENTRY))
{
  int pos, s;
  for(pos = pq->front, s = 0; s < pq->size; s ++)
  {
    (*pf) (pq->entry[pos]);
    pos = (pos + 1) % MAXQUEUE;
  }
}
