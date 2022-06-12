

    if(c == '(')
    {

      int tempCount = 0;
      char tempPostFix [100];
      char p = '0';
      int value;

     /* put the Equation in a new array */
     while(p != ')')
      {
        p = infix[++i];
        tempPostFix[tempCount++] = p;
        //printf("char is: %s\n", tempPostFix);
      }
      stack s4;
      CreateStack(&s4);
      tempPostFix[--tempCount] = '\0';
      //printf("char is: %s\n", tempPostFix);
      c = infix[++i];
      printf("c is %c\n", c);

      /* convert it into postfix and calculate it */
      s4 = PostFix(tempPostFix);
      value = EvaluatePostFix(s4);
      printf("value is %d\n", value);

      /* pushing it in the main equation */
      //Push(value, &s1);
      //StackTraverse(&s4, &PrintStack);
      char buf[100];
      sprintf(buf, "%d", value);
      count = 0;
      for(int k = 0; buf[k] != '\0'; k ++)
      {
        Push(buf[k] - '0', &s1);
        count ++;
      }
    }

