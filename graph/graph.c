#include <stdio.h>
#include <stdlib.h>

#define MAXGRAPH 100
#define GRAPHENTRY int


typedef struct Edge
{
  int endpoint;
  struct Edge *next;
}edge;

typedef struct Vertex
{
  GRAPHENTRY entry;
  edge *first;
}vertex;

typedef struct Graph
{
  int size;
  vertex entry[MAXGRAPH];
}graph;

void CreateGraph(graph *pg)
{
  int i;
  for(i = 0; i <pg->n; i++)
  {
    pg->entry[i].first = NULL;
  }
}

int main(void)
{
}