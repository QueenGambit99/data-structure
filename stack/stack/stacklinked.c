/*********************************INCLUDES*********************************/

#include <stdio.h>
#include <stdlib.h>

/*********************************DEFINES*********************************/

#define stackentry int

/*********************************TYPES*********************************/

typedef struct StackNode
{
  struct StackNode *next;
  stackentry entry;
}node;

typedef struct Stack
{
  node *top;
  int size;
}stack;

/*********************************FUNCTIONS DECLARATION*********************************/

/* CreateStack() */
void CreateStack(stack *ps)
{
  ps->top = NULL;
  ps->size = 0;
}

/* ClearStack() */
void ClearStack(stack *ps)
{
  node *pn = ps->top;
  while(!ps->top)
  {
    ps->top = pn->next;
	free(pn);
	pn = ps->top;	
  }
  ps->size = 0;
}

/* Push() */
void Push(stackentry e, stack *ps)
{
  node *pn = (node *) malloc(sizeof(node));
  pn->entry = e;
  pn->next = ps->top;
  ps->top = pn;
  ps->size ++;
}

/* Pop() */
void Pop(stackentry *pe, stack *ps)
{
  node *pn = ps->top;
  *pe = ps->top->entry;
  ps->top = ps->top->next;
  free(pn);
  ps->size --;
}

/* StackTop() */
void StackTop(stackentry *pe, stack *ps)
{
  *pe = ps->top->entry; 
}

/* StackFull() */
int StackFull(stack *ps)
{
  return 0;
}

/* StackEmpty() */
int StackEmpty(stack *ps)
{
  if(ps->top == NULL)
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
  return ps->size;
}

/* StackTraverse() */
void StackTraverse(stack *ps, void (*pf) (stackentry))
{
  node *pn;
  for(pn = ps->top; pn; pn = pn->next)
  {
    (*pf) (pn->entry);
  }
}

