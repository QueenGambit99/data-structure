
/**********************************INCLUDES**********************************/

#include <stdio.h>
#include <stdlib.h>

/**********************************DEFINES**********************************/

#define LISTENTRY int
#define MAXLIST   100

/**********************************STRUCTERS**********************************/

typedef struct Node
{
  struct Node *next;
  struct Node *previous;
  LISTENTRY  entry;
}node;

typedef struct Dlist
{
  node *head;
  node *tail;
  node *current;
  int size;
  int currentpos;
}list;

/**********************************FUNCTIONS**********************************/

/* CreateList() */
void CreateList(list *pl)
{
  pl->head = NULL;
  pl->tail = NULL;
  pl->current = NULL;
  pl->size = 0;
  pl->currentpos = 0;
}

/* DestroyList() */
void DestroyList(list *pl)
{
  pl->current = pl->head;
  while(pl->head)
  {
    if(pl->head == pl->tail)
    {
      free(pl->current);
      pl->head = NULL;
      pl->tail = NULL;
      pl->current = NULL;
    }
    else
    {
      pl->tail->next = pl->current->next;
      pl->current->next->previous = pl->tail;
      pl->head = pl->current->next;
      free(pl->current);
      pl->current = pl->head;
    }
  }
  pl->size = 0;
  pl->currentpos = 0;
}

/* ListEmpty() */
int ListEmpty(list *pl)
{
  return !pl->size;
}

/* ListFull() */
int ListFull(list *pl)
{
  return 0;
}

/* ListSize */
int ListSize(list *pl)
{
  return pl->size;
}

/* RetrieveList() */
int RetrieveList(int p, LISTENTRY *pe, list *pl)
{
  if(p == pl->currentpos)
  {
  }

  else if(p > pl->currentpos)
  {
    for(; pl->currentpos < p; pl->currentpos ++)
    {
      pl->current = pl->current->next;
    }
  }

  else
  {
    for(; pl->currentpos > p; pl->currentpos --)
    {
      pl->current = pl->current->previous;
    }
  }

  *pe = pl->current->entry;
  return *pe;
}

/* ReplaceList() */
void ReplaceList(int p, LISTENTRY e, list *pl)
{
  if(p == pl->currentpos)
  {
  }

  else if(p > pl->currentpos)
  {
    for(; pl->currentpos < p; pl->currentpos ++)
    {
      pl->current = pl->current->next;
    }
  }

  else
  {
    for(; pl->currentpos > p; pl->currentpos --)
    {
      pl->current = pl->current->previous;
    }
  }

  pl->current->entry = e;
}

/* TraverseList() */
void TraverseList(list *pl, void (*pf) (LISTENTRY))
{
  node *pn;
  for(pn = pl->head; pn != pl->tail; pn = pn->next)
  {
    (*pf) (pn->entry);
  }
  if(!ListEmpty(pl))
  {
    (*pf) (pn->entry);
  }
}

/* PrintList() */
void PrintList(LISTENTRY e)
{
  printf("%d\n", e);
}

/* InsertList() */
void InsertList(int p, LISTENTRY e, list *pl)
{
  node *pn = (node *) malloc(sizeof(node));
  if(pl->size == 1)
  {
    pn->next = pl->head;
    pn->previous = pl->head;
    pn->entry = e;
    pl->head->previous = pn;
    pl->head->next = pn;
    pl->current = pn;
    if(p == 0)
    {
      pl->head = pn;
    }
    else
    {
      pl->tail = pn;
    }
    pl->currentpos = p;
  }
  else if(p == 0)
  {
    if(ListEmpty(pl))
    {
      pl->head = pn;
      pl->tail = pn;
      pn->next = pn;
      pn->previous = pn;
      pn->entry = e;
      pl->current = pn;
      pl->currentpos = 0;
    }
    else
    {
      pl->currentpos = 0;
      pl->current = pl->head;
      pn->next = pl->head;
      pn->previous = pl->tail;
      pn->entry = e;
      pl->tail->next = pn;
      pl->head->previous = pn;
      pl->head = pn;
      pl->current = pn;
    }
  }
  else
  {
    if(p == pl->currentpos)
    {
      pl->current = pl->current->previous;
    }
    else if(p > pl->currentpos)
    {
      for(; pl->currentpos < p - 1; pl->currentpos ++)
      {
        pl->current = pl->current->next;
      }
    }
    else
    {
      for(; pl->currentpos > p - 1; pl->currentpos --)
      {
          pl->current = pl->current->previous;
      }
    }
      pl->currentpos = p;
      pn->next = pl->current->next;
      pn->previous = pl->current;
      pn->entry = e;
      pl->current->next->previous = pn;
      pl->current->next = pn;
      pl->current = pl->current->next;
  }
  if(pn->previous == pl->tail && p != 0)
  {
    pl->tail = pn;
  }
  pl->size ++;
}

/* DeleteList() */
void DeleteList(int p, LISTENTRY *pe, list *pl)
{
  node *pn;
  if(p == 0)
  {
    if(pl->size == 1)
    {
      *pe = pl->head->entry;
      free(pl->head);
      pl->head = NULL;
      pl->tail = NULL;
      pl->current = NULL;
    }
    else
    {
      pl->current = pl->head;
      pl->head = pl->head->next;
      pl->head->previous = pl->tail;
      pl->tail->next = pl->head;
      *pe = pl->current->entry;
      free(pl->current);
      pl->current = pl->head;
    }
    pl->currentpos = 0;
  }
  else
  {
    if(p == pl->currentpos)
    {
    }
    else if(p > pl->currentpos)
    {
      for(; pl->currentpos < p ; pl->currentpos ++)
      {
        pl->current = pl->current->next;
      }
    }
    else
    {
      for(; pl->currentpos > p; pl->currentpos --)
      {
          pl->current = pl->current->previous;
      }
    }
    pl->current->next->previous = pl->current->previous;
    pl->current->previous->next = pl->current->next;
    pn = pl->current;
    pl->current = pl->current->next;
    *pe = pn->entry;
    free(pn);
  }
  if((p != 0) && (pl->tail != pl->head->previous))
  {
    pl->tail = pl->head->previous;
  }
  pl->size --;
}

int main(void)
{
  int e;
  list l;
  CreateList(&l);

  InsertList(0, 0, &l);
  printf("-->\n");
  TraverseList(&l, &PrintList);
  InsertList(1, 1, &l);
  printf("-->\n");
  TraverseList(&l, &PrintList);
  InsertList(2, 2, &l);
  printf("-->\n");
  TraverseList(&l, &PrintList);
  InsertList(3, 3, &l);
  printf("-->\n");
  TraverseList(&l, &PrintList);
  InsertList(2, 22, &l);
  printf("-->\n");
  TraverseList(&l, &PrintList);
  InsertList(4, 5, &l);
  printf("-->\n");
  TraverseList(&l, &PrintList);
  InsertList(0, 21, &l);
  printf("-->\n");
  TraverseList(&l, &PrintList);
  DeleteList(3, &e, &l);
  printf("-->\n");
  TraverseList(&l, &PrintList);
  InsertList(5, 55, &l);
  printf("-->\n");
  TraverseList(&l, &PrintList);
  DeleteList(5, &e, &l);
  printf("-->\n");
  TraverseList(&l, &PrintList);
  DeleteList(1, &e, &l);
  ReplaceList(4, 34, &l);
  printf("-->\n");
  TraverseList(&l, &PrintList);
  printf("e is %d\n", e);
  DestroyList(&l);
  InsertList(0, 5, &l);
  DeleteList(0, &e, &l);
  printf("e is %d\n", e);
  printf("-->\n");
  TraverseList(&l, &PrintList);

}