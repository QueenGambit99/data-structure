/*********************************INCLUDES*********************************/

#include <stdio.h>

/*********************************FUNCTIONS DECLARATION*********************************/

/* CreateStack() */
void CreateStack(stack *ps)
{
  ps->top = 0;
}

/* ClearStack() */
void ClearStack(stack *ps)
{
  ps->top = 0;
}

/* Push() */
void Push(stackentry e, stack *ps)
{
  ps->entry[ps->top] = e;
  ps->top ++;
}

/* Pop() */
void Pop(stackentry *pe, stack *ps)
{
  ps->top --;
  *pe = ps->entry[ps->top];
}

/* StackTop() */
void StackTop(stackentry *pe, stack *ps)
{
  *pe = ps->entry[ps->top-1]; 
}

/* StackFull() */
int StackFull(stack *ps)
{
  if(ps->top == maxstack)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

/* StackEmpty() */
int StackEmpty(stack *ps)
{
  if(ps->top == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

/* StackSize() */
int StackSize(stack *ps)
{
  return ps->top;
}

/* StackTraverse() */
void StackTraverse(stack *ps, void (*pf) (stackentry))
{
  int i;
  for(i = ps->top; i > 0; i --)
  {
    (*pf) (ps->entry[i-1]);
  }
}
