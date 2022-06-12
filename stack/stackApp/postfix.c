
/*********************************INCLUDES*********************************/

#include <stdio.h>
#include <math.h>
#include "stacklinked.c"

/*********************************FUNCTIONS PROTOTYPE*********************************/

stack PostFix(char infix[]);
int Precedent(char op1, char c);
int Power(int count);
void PrintStack(stackentry e);
float EvaluatePostFix(stack s);
float Operation(char op, int op1, int op2);
int NegSign(char opbef);

/*********************************MAIN FUNCTION*********************************/

int main(void)
{
  stack s3;
  CreateStack(&s3);
  char infix[] = "5/3";
  s3 = PostFix(infix);
  StackTraverse(&s3, &PrintStack);
  printf("The value is %f\n", EvaluatePostFix(s3));
  float a = 2.5;
  printf("The value is %f\n", a);
}

/*********************************PostFix()*********************************/

stack PostFix(char infix[])
{

  /* initialization of local variables */
  int    infix_indx;
  int    num_indx;
  int    op;
  int    num_value;
  int    count;
  char   infix_char;
  char   last_char;

  /* declaration of local variables */
  infix_indx    = 0;
  num_value     = 0;
  count         = 0;
  last_char     = -1;

  /* create a stack for postfix */
  stack s1_temp_postfix;
  CreateStack(&s1_temp_postfix);

  /* create a stack for storing operatos */
  stack s2_operators;
  CreateStack(&s2_operators);

  /* do that while the equation does not finish */
  do
  {
    infix_char = infix[infix_indx];

    /* do nothing */
    if(infix_char== ' ')
    {

    }

    /* put every digit from the number in the stack */
    else if(infix_char >= '0' && infix_char <= '9')
    {
      Push((int)(infix_char - '0'), &s1_temp_postfix);
      count ++;
    }

    /* make operators after '(' are the most precedence */
    else if(infix_char == '(')
    {
      Push(infix_char, &s2_operators);
    }

    /* erase '(' and push remaining operators after it into postfix stack */
    else if(infix_char == ')')
    {
      while(!StackEmpty(&s2_operators))
      {
        StackTop(&op, &s2_operators);

        if(op == '(')
        {
          Pop(&op, &s2_operators);
          break;
        }
        else
        {
          Pop(&op, &s2_operators);
          Push(op, &s1_temp_postfix);
        }
      }
    }

    /* when the element of the array is an operator */
    else
    {

      /* put n in the stack in case '-' is negative sign */
      if(infix_char == '-' && (last_char == -1 || NegSign(last_char)))
      {
        Push('n', &s2_operators);
      }

      else
      {

      /* convert previous single digits in the stack into the number */
      for(num_indx = 0; num_indx < count; num_indx ++)
      {
        Pop(&op, &s1_temp_postfix);
        num_value = num_value + op * Power(num_indx);
      }

      /* reset the count for the next loop */
      count = 0;

      /* put the number from previous loop in the postfix stack */
      Push(num_value, &s1_temp_postfix);

      //printf("num_value is %d when c is %c and c before is %c\n", x, c, last_char);

      /* reset the num_value for next digits */
      num_value = 0;

      /* put the operators in precedent order */
      if(infix_char != '\0' && !StackEmpty(&s2_operators))
      {
        StackTop(&op, &s2_operators);
        //printf("op is %c\n", op);
        while(!StackEmpty(&s2_operators) && Precedent(op, infix_char))
        {
          Pop(&op, &s2_operators);
          Push(op, &s1_temp_postfix);
          if(!StackEmpty(&s2_operators))
          {
            StackTop(&op, &s2_operators);
          }
        }
      }

      /* push the operator into postfix stack */
      if(infix_char != '\0')
      {
        Push(infix_char, &s2_operators);
      }
    }
   }

   if(infix_char != ' ')
   {
     last_char = infix_char;
     printf("Last Char is %c\n", last_char);
   }

    /* increase the loop index */
    infix_indx ++;
    //printf("i is %d\n", infix_indx);
  }
  while(infix_char != '\0');

  /* push the remaining operators from operators stack into postfix stack */
  while(!StackEmpty(&s2_operators))
  {
    Pop(&op, &s2_operators);
    Push((int) op, &s1_temp_postfix);
  }

  /* return the stack */
  return s1_temp_postfix;
}

/*********************************Precedent()*********************************/

int Precedent(char op1, char c)
{
  if(op1 == 'n')
    return 1;

  if (op1 == '^')
    return (c != 'n');

  if ((op1 == '*') || (op1 == '/'))
    return (c != 'n') && (c != '^');

  if ((op1 == '+') || (op1 == '-'))
     return ((c != 'n') && (c != '^') && (c != '*') && (c != '/'));

  return 0;
}

/*********************************Power()*********************************/

int Power(int count)
{
  int num = 1;

  if (count == 0)
      return 1;
  else if (count == 1)
      return 10;
  else
  {
    for(int i = 1; i <= count; i ++)
    {
      num = num * 10;
    }
    return num;
  }
}

/*********************************PrintStack()*********************************/

void PrintStack(stackentry e)
{
  switch(e)
  {
    case '+':
      printf("%c\n", e);
      break;
    case '-':
      printf("%c\n", e);
      break;
    case '*':
      printf("%c\n", e);
      break;
    case '/':
      printf("%c\n", e);
      break;
    //case '^':
      //printf("%c\n", e);
      //break;
    case 'n':
      printf("%c\n", e);
      break;
    default:
      printf("%d\n", e);
      break;
  }
}

/*********************************EvaluatePostFix()*********************************/

float EvaluatePostFix(stack s)
{

  /* intilization for local variables */
  int op;
  int op1;
  int op2;
  float result;


  /* create a stack for rearranging the postfix */
  stack s1_postfix;
  CreateStack(&s1_postfix);

  /* create a stack for the calculation */
  stack s_calc;
  CreateStack(&s_calc);

  /* rearranging the postfix stack */
  while(!StackEmpty(&s))
  {
    Pop(&op, &s);
    Push(op, &s1_postfix);
  }

  /* print the final stack */
  printf("Final postfix equation is \n");
  StackTraverse(&s1_postfix, &PrintStack);

  /* calcualate the postfix */
  while(!StackEmpty(&s1_postfix))
  {

    Pop(&op, &s1_postfix);

    if(op != '-' && op != '+' && op != '*' && op != '/' && op != '^' && op != 'n')
    {
      Push(op, &s_calc);
    }

    else
    {
      if(op == 'n')
      {
        Pop(&op1, &s_calc);
        result = Operation(op, op1, 0);
      }
      else
      {
        Pop(&op2, &s_calc);
        Pop(&op1, &s_calc);
        result = Operation(op, op1, op2);
      }
      Push(result, &s_calc);
      //printf("the result is %d\n", result);
    }
  }

  Pop(&result, &s_calc);

  return result;
}

/*********************************Operation()*********************************/

float Operation(char op, int op1, int op2)
{
  switch(op)
  {
    case 'n':
      return (-op1);
      break;
	case '+':
      return(op1 + op2);
      break;
	case '-':
      return(op1 - op2);
      break;
   	case '*':
      return(op1 * op2);
      break;
	case '/':
      return(op1 / op2);
      break;
	  //case '^':
      //return(Power(op1, op2));
      //break;
  }
}

// 3  * - 3
int NegSign(char opbef)
{
switch(opbef)
  {
	  case '+':
      return 1;
      break;
	  case '-':
      return 1;
      break;
   	case '*':
      return 1;
      break;
	  case '/':
      return 1;
      break;
	  //case '^':
      //return 1;
      //break;
    default:
      return 0;
      break;
  }
}