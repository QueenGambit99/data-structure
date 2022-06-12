
/*********************************INCLUDES*********************************/

#include <stdio.h>
#include "stacklinked.c"

/*********************************FUNCTIONS PROTOTYPE*********************************/

void PrintStack(stackentry e);

/*********************************MAIN FUNCTION*********************************/

int main(void)
{
  /* create a stack */
  stack s;
  stackentry e;
  CreateStack(&s);
  
  /* push elements into stack */
  for (e = 0; e < 100; e = e + 10)
  {
	if (!StackFull(&s))
	{
      Push(e, &s);
	}
  }
  if (!StackEmpty(&s))
  {
    Pop(&e, &s);
  }
  /* pop the last element */

  
  /* print the stack using StackTraverse */
  StackTraverse(&s, &PrintStack);

  /* clear the stack elements */
  //ClearStack(&s);
  //StackTraverse(&s, &PrintStack);
}

/*********************************FUNCTIONS DECLARATION*********************************/

/* PrintStack() */
void PrintStack(stackentry e)
{
  printf("%d\n", e);
}
