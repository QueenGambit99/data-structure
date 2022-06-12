#include <stdio.h>
#include<stdlib.h>

#define TREEENTRY int


typedef struct Node
{
  TREEENTRY entry;
  struct Node *left;
  struct Node *right;
}node;

typedef node *tree;

void CreateTree(tree *pt)
{
  *pt = NULL;   //
}

void InsertTreeRec(tree *pt, TREEENTRY *pe)
{
  if(!*pt)
  {
    *pt = (node *) malloc(sizeof(node));
    (*pt)->entry = *pe;
    (*pt)->left = NULL;
    (*pt)->right = NULL;
  }
  else if(*pe < (*pt)->entry)
    InsertTreeRec(&(*pt)->left, pe);
  else
    InsertTreeRec(&(*pt)->right, pe);
}

void InsertTree(tree *pt, TREEENTRY e)
{
  node *cur, *prev;
  node *pn = (node *) malloc(sizeof(node));
  pn->entry = e;
  pn->left = NULL;
  pn->right = NULL;
  if(!*pt)
  {
    *pt = pn;
  }
  else
  {
    cur = *pt;
    while(cur)
    {
      prev = cur;
      if(pn->entry < cur->entry)
      {
        cur = cur->left;
      }
      else
      {
        cur = cur->right;
      }
    }
    if(pn->entry < prev->entry)
    {
      prev->left = pn;
    }
    else
    {
      prev->right = pn;
    }
  }
}

int TreeSize(tree *pt)
{
  if(!*pt)
   return 0;
  return(1 + TreeSize(&(*pt)->left) + TreeSize(&(*pt)->right));
}

int TreeDepth(tree *pt)
{
  if(!*pt)
   return 0;
  int a = TreeDepth(&(*pt)->right);
  int b = TreeDepth(&(*pt)->left);
  return a>=b? 1+a : 1 +b;
}

void TraverseTreeRec(tree *pt, void (*pf) (TREEENTRY))
{
  if(*pt)
  {
    TraverseTreeRec(&(*pt)->left, pf);
    (*pf) ((*pt)->entry);
    TraverseTreeRec(&(*pt)->right, pf);
  }
}

int FindTreeElementRec(tree *pt, TREEENTRY *pe)
{
  if(!*pt)
  {
    return 0;
  }
  if(*pe == (*pt)->entry)
  {
    return 1;
  }
  if(*pe < (*pt)->entry)
  {
    FindTreeElementRec(&(*pt)->left, pe);
  }
  else
  {
    FindTreeElementRec(&(*pt)->right, pe);
  }
}

int FindTreeElement(tree *pt, TREEENTRY *pe)
{
  node *pn = *pt;
  while(pn)
  {
    printf("%d\n", pn->entry);
    if(*pe == pn->entry)
    {
      printf("FOUND!");
      return 1;

    }
    if(*pe < pn->entry )
    {
      printf("NotFound ... search left!\n");
      pn = pn->left;
    }
    else
    {
      printf("NotFound ... search right\n");
      pn = pn->right;
    }
  }
  printf("NotFound at all\n");
  return 0;
}

void DeleteTree(tree *pt)
{
  node *pn, *pr;
  pn = *pt;
  if(!(*pt)->left)
  {
    *pt = (*pt)->right;
  }
  else if(!(*pt)->right)
  {
    *pt = (*pt)->left;
  }
  else
  {
    *pt = (*pt)->right;
    for(pr = pn->right; pn->left; pn = pn->left);
    pr->left = pn->left;
  }
  free(pn);
}

void DeleteTree2(tree *pt)
{
  node *pn, *pr;
  pn = *pt;
  if(!(*pt)->left)
  {
    *pt = (*pt)->right;
  }
  else if(!(*pt)->right)
  {
    *pt = (*pt)->left;
  }
  else
  {
    pn = (*pt)->left;
    if(!pn->right)
    {
      (*pt)->entry = pn->entry;
      (*pt)->left  = pn->left;
    }
    else
    {
      do
      {
        pr = pn;
        pn = pn->right;
      }while(pn->right);
      (*pt)->entry = pn->entry;
      pr->right = pn->left;
    }
  }
  free(pn);
}

int DeleteElement(tree *pt, TREEENTRY *pe)
{
  node *pn, *pp;
  pn = *pt;
  pp = NULL;
  int found = 0;
  while(found == 0)
  {
    if(*pe == pn->entry)
    {
      found = 1;

     printf("Elements %d %d are %d\n", pn->entry, *pe, found);
    }
    else if(*pe < pn->entry )
    {
      pp = pn;
      pn = pn->left;

      printf("Elements %d %d are %d\n", pp->entry, *pe, found);
    }
    else
    {
      pp = pn;
      pn = pn->right;

      printf("Elements %d %d are %d\n", pp->entry, *pe, found);
    }
  }
  if(found)
  {
    if(!pp)
    {
      printf("We will now delete the root\n");
      DeleteTree2(pt);
    }
    else if(*pe < pp->entry)
    {
      printf("We will now delete the left child\n");
      DeleteTree2(&pp->left);
    }
    else
    {
      printf("We will now delete the right child\n");
      DeleteTree2(&pp->right);
    }
  }
  return found;
}


void PrintTree(TREEENTRY e)
{
  printf("e is %d\n", e);
}

int main(void)
{
  int e;
  tree t;
  CreateTree(&t);
#if 0
  e = 10;
  InsertTreeRec(&t, &e);
  e = 5;
  InsertTreeRec(&t, &e);
  e = 6;
  InsertTreeRec(&t, &e);
  e = 3;
  InsertTreeRec(&t, &e);
  e = 7;
  InsertTreeRec(&t, &e);
  e = 4;
  InsertTreeRec(&t, &e);
  e = 2;
  InsertTreeRec(&t, &e);
  e = 11;
  InsertTreeRec(&t, &e);
  printf("Size is %d \nDepth is %d\n", TreeSize(&t), TreeDepth(&t));
  TraverseTreeRec(&t, &PrintTree);
#endif

  e = 10;
  InsertTree(&t, e);
  e = 5;
  InsertTree(&t, e);
  e = 34;
  InsertTree(&t, e);
  e = 3;
  InsertTree(&t, e);
  e = 7;
  InsertTree(&t, e);
  e = 4;
  InsertTree(&t, e);
  e = 2;
  InsertTree(&t, e);
  e = 11;
  InsertTree(&t, e);
  printf("Size is %d \nDepth is %d\n", TreeSize(&t), TreeDepth(&t));
  TraverseTreeRec(&t, &PrintTree);
  e = 10;
  DeleteElement(&t, &e);
  printf("Size is %d \nDepth is %d\n", TreeSize(&t), TreeDepth(&t));
  TraverseTreeRec(&t, &PrintTree);
  //printf("is 3 exist? %d\n", FindTreeElement(&t, &e));

}