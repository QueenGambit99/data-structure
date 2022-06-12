/*******************************INCLUDES***********************************/

#include <stdio.h>
#include<stdlib.h>

/*******************************MACROS***********************************/

#define TREEENTRY int

/*******************************TYPES***********************************/

/* Tree node. */
typedef struct Node
{
  TREEENTRY entry;
  struct Node *left;
  struct Node *right;
}node;

/* Tree structure. */
typedef node *tree;

/*******************************PROTOTYPES********************************/

void CreateTree(tree *pt); //
void ClearTree(tree *pt); //
void InsertTree(tree *pt, TREEENTRY e); //
int  DeleteTree(tree *pt, TREEENTRY *pe);
void DeleteTreeAux(tree *pt);
void TraverseTree(tree *pt, void (*pf) (TREEENTRY)); //
void PrintTree(TREEENTRY e);  //
int  TreeSize(tree *pt);  //
int  TreeDepth(tree *pt);
int  TreeEmpty(tree *pt);  //
int  TreeFull(tree *pt);  //
int  TreeFind(tree *pt, TREEENTRY *pe);

/*******************************MAINFUNC********************************/

int main(void)
{
  int e;
  tree t;
  CreateTree(&t);

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

  printf("first Tree is \n");
  printf("Size is %d \nDepth is %d\n", TreeSize(&t), TreeDepth(&t));
  TraverseTree(&t, &PrintTree);

  e = 10;
  DeleteTree(&t, &e);

  printf("Second Tree is \n");
  printf("Size is %d \nDepth is %d\n", TreeSize(&t), TreeDepth(&t));
  TraverseTree(&t, &PrintTree);

  e = 7;
  printf("is %d exist? %d\n", e, TreeFind(&t, &e));

  ClearTree(&t);

  printf("Third Tree is \n");
  printf("Size is %d \nDepth is %d\n", TreeSize(&t), TreeDepth(&t));
  TraverseTree(&t, &PrintTree);

  e = 7;
  printf("is %d exist? %d\n", e, TreeFind(&t, &e));
}

/*******************************FUNCTIONS********************************/

                            /* CreateTree */
void CreateTree(tree *pt)
{
  *pt = NULL;
}

                            /* ClearTree */
void ClearTree(tree *pt)
{

  if(*pt)
  {
    ClearTree(&(*pt)->left);
    ClearTree(&(*pt)->right);
    free(*pt);
    *pt = NULL;
  }
}

                            /* InsertTree */
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

                            /* DeleteTreeAux */
void DeleteTreeAux(tree *pt)
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

                            /* DeleteTree */
int DeleteTree(tree *pt, TREEENTRY *pe)
{
  node *pn, *pp;
  pn = *pt;
  pp = NULL;
  int found = 0;
  while(found == 0 && pn)
  {
    if(*pe == pn->entry)
    {
      found = 1;
    }
    else if(*pe < pn->entry )
    {
      pp = pn;
      pn = pn->left;
    }
    else
    {
      pp = pn;
      pn = pn->right;
    }
  }
  if(found)
  {
    if(!pp)
    {
      DeleteTreeAux(pt);
    }
    else if(*pe < pp->entry)
    {
      DeleteTreeAux(&pp->left);
    }
    else
    {
      DeleteTreeAux(&pp->right);
    }
  }
  return found;
}

                            /* TraverseTree */
void TraverseTree(tree *pt, void (*pf) (TREEENTRY))
{
  if(*pt)
  {
    TraverseTree(&(*pt)->left, pf);
    (*pf) ((*pt)->entry);
    TraverseTree(&(*pt)->right, pf);
  }
}

                            /* PrintTree */
void PrintTree(TREEENTRY e)
{
  printf("e is %d\n", e);
}

                            /* TreeSize */
int TreeSize(tree *pt)
{
  if(!*pt)
   return 0;
  return(1 + TreeSize(&(*pt)->left) + TreeSize(&(*pt)->right));
}

                            /* TreeDepth */
int TreeDepth(tree *pt)
{
  if(!*pt)
   return 0;
  int a = TreeDepth(&(*pt)->right);
  int b = TreeDepth(&(*pt)->left);
  return a>=b? 1+a : 1 +b;
}
                            /* TreeEmpty */
int TreeEmpty(tree *pt)
{
  return !(*pt);
}

                            /* TreeFull */
int TreeFull(tree *pt)
{
  return 0;
}

                            /* TreeFind */
int TreeFind(tree *pt, TREEENTRY *pe)
{
  node *pn = *pt;
  while(pn)
  {
    if(*pe == pn->entry)
    {
      return 1;

    }
    if(*pe < pn->entry )
    {
      pn = pn->left;
    }
    else
    {
      pn = pn->right;
    }
  }
  return 0;
}
