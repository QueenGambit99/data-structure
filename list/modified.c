
/**********************************INCLUDES**********************************/

#include <stdio.h>
#include <stdlib.h>

/**********************************DEFINES**********************************/

#define MAXLIST 10
#define LISTENTRY int

/**********************************STRUCTERS**********************************/

typedef struct Node
{
  struct Node *next;
  LISTENTRY entry;
}node;

typedef struct List
{
  node *head;
  node *current;
  int currentpos;
  int size;
}list;

/**********************************FUNCTIONS**********************************/

/* CreateList() */
void CreateList(list *pl)
{
  pl->head = NULL;
  pl->size = 0;
  pl->current= NULL;
  pl->currentpos = 0;
}

/* DestroyList() */
void DestroyList(list *pl)
{
  pl->current = pl->head;
  while(pl->current)
  {
    pl->current = pl->current->next;
    free(pl->head);
    pl->head = pl->current;
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
    *pe = pl->current->entry;
  }
  else
  {
    if(p <= pl->currentpos)
    {
      pl->current = pl->head;
      pl->currentpos = 0;
    }
    for(; pl->currentpos < p; pl->currentpos ++)
    {
      pl->current = pl->current->next;
    }
    *pe = pl->current->entry;
  }
  return *pe;
}

/*ReplaceList() */
void ReplaceList(int p, LISTENTRY e, list *pl)
{
  if(p == pl->currentpos)
  {
    pl->current->entry = e;
  }
  else
  {
    if(p <= pl->currentpos)
    {
      pl->current = pl->head;
      pl->currentpos = 0;
    }
    for(; pl->currentpos < p; pl->currentpos ++)
    {
      pl->current = pl->current->next;
    }
  }
  pl->current->entry = e;
}

/* TraverseList() */
void TraverseList(list *pl, void (*pf) (LISTENTRY))
{
  node *pn;
  for(pn = pl->head; pn ; pn = pn->next)
  {
    (*pf) (pn->entry);
  }
}

/* InsertList() */
void InsertList(int p, LISTENTRY e, list *pl) // 0 <= p <= size
{
  node *pnn;
  pnn = (node *) malloc(sizeof(node));
  pnn->entry = e;
  pnn->next = NULL;
  if(p == 0)
  {
    pnn->next = pl->head;
    pl->head = pnn;
    pl->current = pl->head;
    pl->currentpos = 0;
  }
  else
  {
    if(p <= pl->currentpos)
    {
      pl->currentpos = 0;
      pl->current = pl->head;
    }
    for(; pl->currentpos < p - 1; pl->currentpos ++)
    {
      pl->current = pl->current->next;
    }
    pnn->next  = pl->current->next;
    pl->current->next = pnn;
  }
  pl->size ++;
}

/* DeleteList() */
void DeleteList(int p, LISTENTRY *pe, list *pl) // 0 <= p <= size
{
  node  *pon;
  if(p == 0)
  {
    *pe = pl->head->entry;
    pl->current = pl->head->next;
    free(pl->head);
    pl->head = pl->current;
    pl->currentpos = 0;
  }
  else
  {
    if(p <= pl->currentpos)
    {
      pl->currentpos = 0;
      pl->current = pl->head;
    }
    for(; pl->currentpos < p - 1; pl->currentpos ++)
    {
      pl->current = pl->current->next;
    }
    pon = pl->current;
    pl->current = pl->current->next;
    pon->next = pl->current->next;
    *pe = pl->current->entry;
    free(pl->current);
    pl->current = pon;
  }
  pl->size --;
}
