/*********************************DEFINES*********************************/

#define stackentry int
#define maxstack 100

/*********************************TYPES*********************************/

typedef struct Stack
{
  stackentry entry[maxstack];
  int top;
}stack;

/*********************************FUNCTIONS PROTOTYPE*********************************/

void CreateStack(stack *ps);
void ClearStack(stack *ps);
void Push(stackentry e, stack *ps);
void Pop(stackentry *pe, stack *ps);
void StackTop(stackentry *pe, stack *ps);
int  StackFull(stack *ps);
int  StackEmpty(stack *ps);
int  StackSize(stack *ps);
void StackTraverse(stack *ps, void (*pf) (stackentry e));
