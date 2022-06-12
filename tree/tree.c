#include <stdio.h>
#include <stdlib.h>


#define TREEENTRY int


typedef struct Node
{
  TREEENTRY entry;
  struct Node *left;
  struct Node *right;
}node;

typedef node *tree1;

typedef struct tree
{
  node *root;
  int size;
  int depth;
}tree2;

void CreateTree1(tree1 *pt)
{
  *pt = NULL;   //
}

void CreateTree2(tree2 *pt)
{
  pt->root = NULL;
  pt->size = 0;
  pt->depth = 0;
}

int Tree1Empty(tree1 *pt)
{
  return !(*pt);
}

int Tree2Empty(tree2 *pt)
{
  return !pt->root;
}

int Tree1Full(tree1 *pt)
{
  return 0;
}

int Tree2Full(tree2 *pt)
{
  return 0;
}

void TraverseTree1Rec(tree1 *pt, void (*pf) (TREEENTRY))
{
  if(!*pt)
  {
    TraverseTree1Rec(&(*pt)->left, pf);
    (*pf) ((*pt)->entry);
    TraverseTree1Rec(&(*pt)->right, pf);
  }
}

void TraverseTree2Rec(tree2 *pt, void (*pf) (TREEENTRY))
{
  if(!pt->root)
  {
    TraverseTree1Rec(&pt->root->left, pf);
    (*pf) (pt->root->entry);
    TraverseTree1Rec(&pt->root->right, pf);
  }
}

void ClearTree1Rec(tree1 *pt)
{
  if(*pt)
  {
    ClearTree1Rec(&(*pt)->left);
    ClearTree1Rec(&(*pt)->right);
    free(pt);
  }
}

void ClearTree2Rec(tree2 *pt)
{
  if(pt->root)
  {
    ClearTree2Rec(&pt->root->left);
    ClearTree2Rec(&pt->root->right);
    free(pt);
  }
}

void ClearTree1(tree1 *pt)
{
  ClearTree1Rec(pt);
  *pt = NULL;
}

void ClearTree2(tree2 *pt)
{
  ClearTree2Rec(pt);
  pt->root = NULL;
}

void CompTrees(tree1 *pt1, tree2 *pt2)
{
  pt1 = NULL;
  pt2->root = NULL;
  if(pt1 == &(pt2->root))
    printf("F\n");
}

int main(void)
{
  tree1 t1;
  tree2 t2;
  CompTrees(&t1, &t2);

}
