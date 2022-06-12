
/**********************************INCLUDES**********************************/

#include <stdio.h>

/**********************************DEFINES**********************************/

#define MAXLIST 10
#define LISTENTRY int

/**********************************STRUCTERS**********************************/

/* struct of list */
typedef struct List
{
  LISTENTRY entry[MAXLIST];
  int size;
}list;

/******************************FUNCTIONS BODIES******************************/

/* CreateList() */
void CreateList(list *pl)
{
  pl->size = 0;
}

/* DestroyList() */
void DestroyList(list *pl)
{
  pl->size = 0;
}

/* InsertList() */
void InsertList(int p, LISTENTRY e, list *pl) // 0 <= p <= size
{
  for(int i = pl->size; i > p; i --)
  {
    pl->entry[i] = pl->entry[i - 1];
  }
  pl->entry[p] = e;
  pl->size ++;
}

/* DeleteList() */
void DeleteList(int p, LISTENTRY *pe, list *pl) // 0 < p < size-1
{
  *pe = pl->entry[p];
  for (int i = p + 1; i < pl->size; i ++)
  {
    pl->entry[i - 1] = pl->entry[i];
  }
  pl->size --;
}

/* ListEmpty() */
int ListEmpty(list *pl)
{
  return !pl->size;
}

/* ListFull() */
int ListFull(list *pl)
{
  return (pl->size == MAXLIST);
}

/* ListSize */
int ListSize(list *pl)
{
  return pl->size;
}

/* RetrieveList() */
int RetrieveList(int p, LISTENTRY *pe, list *pl)
{
  *pe = pl->entry[p];
  return *pe;
}

/*ReplaceList() */
void ReplaceList(int p, LISTENTRY e, list *pl)
{
  pl->entry[p] = e;
}

/* TraverseList() */
void TraverseList(list *pl, void (*pf) (LISTENTRY))
{
  for(int i = 0; i < pl->size; i ++)
  {
    (*pf) (pl->entry[i]);
  }
}
