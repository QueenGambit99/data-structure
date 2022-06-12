
/**********************************INCLUDES**********************************/

#include <stdio.h>
#include "modified.c"
//#include "listlinked.h"
/***************************FUNCTIONS DECLARATION***************************/

void PrintList(LISTENTRY e);

/*******************************MAIN FUNCTION*******************************/

int main(void)
{
  list l;
  CreateList(&l);
  int i;
  for(i = 0; i < 10; i ++)
  {
    InsertList(i, i, &l);
  }
  if(!ListFull(&l))
  {
    InsertList(ListSize(&l), 10, &l);
  }

  printf("First list is \n");
  TraverseList(&l, &PrintList);

  RetrieveList(3, &i, &l);
  ReplaceList(3, 33, &l);
  printf("i is %d\n", i);

  DeleteList(1, &i, &l);
  printf("second list is \n");
  TraverseList(&l, &PrintList);

  InsertList(3, 3, &l);
  printf("second list is \n");
  TraverseList(&l, &PrintList);

#if 0
  //InsertList(0, 1, &l);
  InsertList(ListSize(&l), 11, &l);
  DeleteList(0, &i, &l);
  //DeleteList(3, &i, &l);
  RetrieveList(4, &i, &l);
  ReplaceList(4, 2, &l);

  printf("Second list is \n");
  TraverseList(&l, &PrintList);
  printf("i is %d\n", i);

  DestroyList(&l);
  printf("Third list is \n");

    InsertList(0, 0, &l);
    InsertList(1, 1, &l);
  if(!ListEmpty(&l))
  {
    DeleteList(ListSize(&l) - 1, &i, &l);
  }

  printf("Forth list is \n");
  TraverseList(&l, &PrintList);
#endif
}

/******************************FUNCTIONS BODIES******************************/

/* PrintList() */
void PrintList(LISTENTRY e)
{
  printf("%d\n", e);
}