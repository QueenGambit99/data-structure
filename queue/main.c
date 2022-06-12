
/**********************************INCLUDES**********************************/

#include <stdio.h>
#include "queuelinked.h"

/***************************FUNCTIONS DECLARATION***************************/

void PrintQueue(QUEUEENTRY e);

/*******************************MAIN FUNCTION*******************************/

int main(void)
{
  int i;
  queue q;
  CreateQueue(&q);
  for(i = 1; i <= 10; i ++)
  {
    if(!QueueFull(&q))
    {
      InQueue(i, &q);
    }
  }
  printf("First Queue is: \n");
  TraverseQueue(&q, &PrintQueue);
  if(!QueueFull(&q))
  {
    InQueue(11, &q);
  }
    DeQueue(&i, &q);
  printf("Second Queue is: \n");
  TraverseQueue(&q, &PrintQueue);

  QueueFront(&i, &q);
  printf("Third Queue is: \n");
  TraverseQueue(&q, &PrintQueue);

  printf("size is %d and front is %d\n", QueueSize(&q), i);

  ClearQueue(&q);
  printf("Forth Queue is: \n");
  TraverseQueue(&q, &PrintQueue);
}

/******************************FUNCTIONS BODIES******************************/

/* PrintQueue() */
void PrintQueue(QUEUEENTRY e)
{
  printf("%d\n", e);
}
