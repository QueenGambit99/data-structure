
/**********************************INCLUDES**********************************/

#include <stdio.h>
#include <stdlib.h>

/**********************************DEFINES**********************************/

#define QUEUEENTRY int
#define MAXQUEUE   10

/**********************************STRUCTERS**********************************/

/* struct of node */
typedef struct QueueNode
{
  struct QueueNode *next;
  QUEUEENTRY       entry;
}node;

/* struct of queue */
typedef struct Queue
{
  node *front;
  node *rear;
  int size;
}queue;

/******************************FUNCTIONS BODIES******************************/

/*CreateQueue() */
void CreateQueue(queue *pq)
{
  pq->front = NULL;
  pq->rear  = NULL;
  pq->size  = 0;
}

/* ClearQueue() */
void ClearQueue(queue *pq)
{
  while(pq->rear)
  {
    pq->rear = pq->front->next;
    free(pq->front);
    pq->front = pq->rear;
  }
  pq->size = 0;
}

/* InQueue() */
void InQueue(QUEUEENTRY e, queue *pq)
{
  node *pn = (node *) malloc(sizeof(node));
  pn->entry = e;
  pn->next = NULL;
  if(!pq->front)
  {
    pq->front = pn;
  }
  else
  {
    pq->rear->next = pn;
  }
  pq->rear = pn;
  pq->size ++;
}

/* DeQueue() */
void DeQueue(QUEUEENTRY *pe, queue *pq)
{
  node *pn = pq->front;
  *pe = pn->entry;
  pq->front = pn->next;
  free(pn);
  if(!pq->front)
  {
    pq->rear = NULL;
  }
  pq->size --;
}

/* TraverseQueue() */
void TraverseQueue(queue *pq, void (*pf) (QUEUEENTRY))
{
  node *pn;
  for(pn = pq->front; pn; pn = pn->next)
  {
    (*pf) (pn->entry);
  }
}

/* QueueEmpty() */
int QueueEmpty(queue *pq)
{
  return !pq->front;
}

/* QueueFull() */
int QueueFull(queue *pq)
{
  return 0;
}

/* QueueSize() */
int QueueSize(queue *pq)
{
  return pq->size;
}

/* QueueFront() */
int QueueFront(QUEUEENTRY *pe, queue *pq)
{
  *pe = pq->front->entry;
  return *pe;
}
