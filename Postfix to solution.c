#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define size 20

int stack[size];
int top = -1;
void
push (char v)
{
  stack[++top] = v;
}

int
pop ()
{
  int item = stack[top];
  top = top - 1;
  return (item);
}

int
main ()
{
  char xp[20];
  char *e;
  scanf ("%s", xp);
  int n1, n2, n3, num;
  e = xp;
  while (*e != '\0')
    {
      if (isdigit (*e))
	{
	  num = *e - 48;
	  push (num);
	}
      else
	{
	  n1 = pop ();
	  n2 = pop ();

	  switch (*e)
	    {
	    case '+':
	      n3 = n2 + n1;
	      break;
	    case '-':
	      n3 = n2 - n1;
	      break;
	    case '*':
	      n3 = n2 * n1;
	      break;
	    case '/':
	      n3 = n2 / n1;
	      break;
	    }
	  push (n3);
	}
      e++;
    }
  printf ("%d", stack[top]);

  return 0;
}
