
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
  int size;
}list;

/* CreateList() */
void CreateList(list *pl)
{
  pl->head = NULL;
  pl->size = 0;
}

/* DestroyList() */
void DestroyList(list *pl)
{
  node *pn = pl->head;
  while(pn)
  {
    pn = pn->next;
    free(pl->head);
    pl->head = pn;
  }
  pl->size = 0;
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
  node *pn;
  int i;
  for(i = 0, pn = pl->head; i < p; i ++)
  {
    pn = pn->next;
  }
  *pe = pn->entry;
  return *pe;
}

/*ReplaceList() */
void ReplaceList(int p, LISTENTRY e, list *pl)
{
  node *pn;
  int i;
  for(i = 0, pn = pl->head; i < p; i ++)
  {
    pn = pn->next;
  }
  pn->entry = e;
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
  node *pn, *pnn;
  int i;
  pnn = (node *) malloc(sizeof(node));
  pnn->entry = e;
  pnn->next = NULL;
  if(p == 0)
  {
    pnn->next = pl->head;
    pl->head = pnn;
  }
  else
  {
    for(i = 0, pn = pl->head; i < p - 1; i ++)
    {
      pn = pn->next;
    }
    pnn->next  = pn->next;
    pn->next = pnn;
  }
  pl->size ++;
}

/* DeleteList() */
void DeleteList(int p, LISTENTRY *pe, list *pl) // 0 <= p <= size
{
  node *pn, *pon;
  int i;
  if(p == 0)
  {
    pn = pl->head;
    pl->head = pn->next;
  }
  else
  {
    for(i = 0, pn = pl->head; i < p - 1; i ++)
    {
      pn = pn->next;
    }
    pon = pn;
    pn = pn->next;
    pon->next = pn->next;
  }
  *pe = pn->entry;
  free(pn);
  pl->size --;
}
