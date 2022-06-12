/*********************************INCLUDES*********************************/

#include <stdio.h>

/*********************************FUNCTIONS PROTOTYPE*********************************/

void MoveDisks(int count, int start, int end, int temp);
int Factorial(int num);
int factorial(int num);
int Fabonacci(int num);
int fabonacci(int num);

/*********************************MAIN FUNCTION*********************************/

int main(void)
{

  /* local variables */
  int count;
  int start;
  int end;
  int temp;
  
  
  /* variables declaration */
  start = 1;
  temp = 2;
  end = 3;
  int x = 3^2;
  /* insert number of elements */
  printf("Enter the number of elements: ");
  scanf("%d", &count);
  
  /* start the game */
  MoveDisks(count, start, end, temp);
  
  printf("The factorial for the number of elements (%d) is: %d\n", count, Factorial(count));
  printf("The factorial for the number of elements (%d) is: %d\n", count, factorial(count));
  printf("The Fabonacci for the number of elements (%d) is: %d\n", count, Fabonacci(count));
  printf("The Fabonacci for the number of elements (%d) is: %d\n", count, fabonacci(count));
  printf("%d", x);
}

/*********************************FUNCTIONS DECLARATION*********************************/

/* MoveDisks() */
void MoveDisks(int count, int start, int end, int temp)
{
  int swap;
  while(count >0)
  {
    MoveDisks(count-1, start, temp, end);
    printf(" move the disk %d from %d to %d\n", count, start, end);
    count --;
	swap = start;
    start = temp;
	temp = swap;
  }
}

/* Factorial() */
int Factorial(int num)
{
  if(!num)
  {
    return 1;
  }
  else
  {
    int i;
    for( i = num; i > 1; i --)
    {
      num = num * (i - 1);
    }
  }
  return num;
}

/* factorial() */
int factorial(int num)
{
  if(!num || num == 1)
  {
    return 1;    
  }
  else
  {
    return num*factorial(num-1);
  }
}

/* Fabonacci() */
int Fabonacci(int num)
{
  if (!num)
  {
    return 0;
  }
  else if(num == 1)
  {
    return 1;
  }
  else
  {
    int twolast = 1;
    int onelast = 2;
    int current = 0;
	int i;
  
    for(i = 2; i <= num; i ++)
    {
      current = twolast + onelast;
	  twolast = onelast;
	  onelast = current;
    }
	return current;
  }
}

/* fabonacci() */
int fabonacci(int num)
{
  if (!num)
  {
    return 0;
  }
  else if(num == 1)
  {
    return 1;
  }
  else
  {
    return fabonacci(num - 1) + fabonacci(num - 2);
  }
}