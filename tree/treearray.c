#include <stdio.h>
#include <stdlib.h>


#define TREEENTRY int
#define MAXTREE   20



typedef struct Tree
{
  TREEENTRY entry[MAXTREE];
  int root;
  int top;
  int size;
  int depth;
  int root_indx;

  //Temp Tree struct
  TREEENTRY parent[MAXTREE];
  int top_parent;
  TREEENTRY left[MAXTREE];
  int top_left;
  TREEENTRY right[MAXTREE];
  int top_right;
}tree;

void CreateTree(tree *pt);
void ClearTree(tree *pt);
void InsertTree(tree *pt, TREEENTRY e);
void InsertDrawTree(tree *pt, TREEENTRY e);
void TraverseTree(tree *pt, void (*pf) (TREEENTRY));
void PrintTree(TREEENTRY e);
void PrintDrawTree(tree *pt);
int  TreeSize(tree *pt);
int  TreeEmpty(tree *pt);
int  TreeFull(tree *pt);
int  FindDrawTree(tree *pt, TREEENTRY *pe);
int  FindTree(tree *pt, TREEENTRY *pe);
void DeleteTree(tree *pt, TREEENTRY *pe);
void DeleteDrawTree(tree *pt, TREEENTRY *pe);

void CreateTree(tree *pt)
{
  int i;

  pt->top = 0;
  pt->size = 0;
  pt->depth = 0;
  pt->root = 0;
  pt->root_indx = 0;

  for(i = 0; i < MAXTREE; i ++)
  {
    pt->right[i]  = 'a';
    pt->left[i]   = 'a';
  }

  pt->top_left = 0;
  pt->top_right = 0;
  pt->top_parent = 0;
}

void ClearTree(tree *pt)
{
  int i;
  pt->top = 0;
  pt->size = 0;
  pt->depth = 0;
  pt->root = 0;
  pt->root_indx = 0;

  pt->top_left = 0;
  pt->top_right = 0;
  pt->top_parent = 0;

  for(i = 0; i < MAXTREE; i ++)
  {
    pt->right[i]  = 'a';
    pt->left[i]   = 'a';
  }
}

void InsertTree(tree *pt, TREEENTRY e)
{
  if(pt->size == 0)
  {
    pt->root = e;
    pt->root_indx = 0;
    pt->entry[pt->top] = e;
  }
  else
  {
    int value;
    int i = 0;
    while((i != pt->top) && (e > pt->entry[i]))
    {
      i ++;
    }

    value = i;

    for(i = 0; i < (pt->top - value); i ++)
    {
      pt->entry[pt->top - i] = pt->entry[pt->top - i - 1];
    }
    pt->entry[value] = e;

    if(e < pt->root)
    {
      pt->root_indx ++;
    }
  }
  pt->top ++;
  pt->size ++;

  InsertDrawTree(pt, e);

}

void InsertDrawTree(tree *pt, TREEENTRY e)
{
  int i = 0;
  int element;

  pt->parent[pt->top_parent] = e;

  if(pt->top_parent == 0)
  {
  }
  else
  {
    while(i < pt->top_parent)
    {
      if(e < pt->parent[i])
      {
        if(pt->left[i] != 'a')
        {
          element = pt->left[i];
          i = FindDrawTree(pt, &element);
        }
        else
        {
          pt->left[i] = e;
          pt->top_left ++;
          break;
        }
      }
      else
      {
        if(pt->right[i] != 'a')
        {
          element = pt->right[i];
          i = FindDrawTree(pt, &element);
        }
        else
        {
          pt->right[i] = e;
          pt->top_right ++;
          break;
        }
      }
    }
  }
  pt->top_parent ++;
}

int FindTree(tree *pt, TREEENTRY *pe)
{
  int start;
  int end;
  int middle;

  start = 0;
  end = pt->top - 1;

  while(start <= end)
  {
    middle = (start + end) / 2;

    if(*pe == pt->entry[middle])
      return middle;
    if(*pe < pt->entry[middle])
      end = middle - 1;
    else
      start = middle + 1;
  }
  return -1;
}

int FindDrawTree(tree *pt, TREEENTRY *pe)
{
  int i = 0;
  for(; i < pt->top_parent; i++)
  {
    if(*pe == pt->parent[i])
    {
      break;
    }
  }
  return i;
}

int FindRightChild(tree *pt, TREEENTRY *pe)
{
  int i = 0;
  int found = 0;
  for(; i < pt->top_parent; i++)
  {
    if(*pe == pt->right[i])
    {
      found = 1;
      break;
    }
  }
  if(found)
    return i;
  return -1;
}

int FindLeftChild(tree *pt, TREEENTRY *pe)
{
  int i = 0;
  int found = 0;
  for(; i < pt->top_parent; i++)
  {
    if(*pe == pt->left[i])
    {
      found = 1;
      break;
    }
  }
  if(found)
    return i;
  return -1;
}
void TraverseTree(tree *pt, void (*pf) (TREEENTRY))
{
  int i;
  for(i = 0; i < pt->top; i ++)
  {
    (*pf) (pt->entry[i]);
  }
}

void PrintTree(TREEENTRY e)
{
  printf("e is %d\n", e);
}

void PrintDrawTree(tree *pt)
{
  for(int i = 0; i < pt->size; i ++)
  {
    printf("parent: %d         left: %d          right: %d\n", pt->parent[i], pt->left[i], pt->right[i]);
  }
}
int  TreeSize(tree *pt)
{
  return pt->size;
}

int TreeEmpty(tree *pt)
{
  return !pt->size;
}

int TreeFull(tree *pt)
{
  return (pt->top == MAXTREE);
}

void DeleteTree(tree *pt, TREEENTRY *pe)
{
  int index;

  index = FindTree(pt, pe);
  if (index != -1)
  {
    for(; index < (pt->top -1); index ++)
    {
      pt->entry[index] = pt->entry[index + 1];
    }

    pt->top --;
    pt->size --;
  }

}

void DeleteDrawTree(tree *pt, TREEENTRY *pe)
{
  int element_index;
  int right_index;
  int left_index;

  element_index = TreeDrawfind(pt, pe);

  if(pt->right[element_index] == 'a')
  {
    right_index = FindRightChild(pt, pe);
    if(right_index != -1)
    {
    }
    else
    {
      left_index = FindLeftChild(pt, pe);
    }
  }
}

int main(void)
{
  int e;

  tree t;
  CreateTree(&t);

  InsertTree(&t, 1);

  TraverseTree(&t, &PrintTree);
  printf("size is %d\n", TreeSize(&t));

  e = 1;
  DeleteTree(&t, &e);

  TraverseTree(&t, &PrintTree);
  printf("size is %d\n", TreeSize(&t));

  DeleteTree(&t, &e);
  TraverseTree(&t, &PrintTree);
  printf("size is %d\n", TreeSize(&t));
#if 0
  InsertTree(&t, 2);
  InsertTree(&t, 9);
  InsertTree(&t, 3);
  InsertTree(&t, 4);
  InsertTree(&t, 0);
  InsertTree(&t, 5);
  InsertTree(&t, 2);
  InsertTree(&t, 9);
  InsertTree(&t, 5);

  TraverseTree(&t, &PrintTree);
  printf("size is %d\n", TreeSize(&t));

  e = 0;
  DeleteTree(&t, &e);
  DeleteTree(&t, &e);


  TraverseTree(&t, &PrintTree);
  printf("size is %d\n", TreeSize(&t));

  PrintDrawTree(&t);

  e = 14;
  printf("%d is in index %d\n", e, FindTree(&t, &e));
#endif
}