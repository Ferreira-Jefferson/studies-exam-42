#include <stdio.h>

int is_balance(char *str)
{
  int open = 0;
  int close = 0;
  
  for (int i = 0; str[i]; i++)
  {
     if (str[i] == '(')
      open++;
    else if (str[i] == ')')
    {     
      if (open > 0)
        open--;
      else
        close++;
    }
    
  }
  return close + open;
}

void solve(char *str, int size_error, int size_change)
{
  if (size_change == size_error)
  {
    if (is_balance(str) == 0)
      printf("%s\n", str);
    return ;
  }

	for (int i = 0; str[i]; i++)
	{
		solve(str, size_error, size_change+1);
			
		char temp = str[i];
		str[i] = 'x';
		solve(str, size_error, size_change + 1);
		str[i] = temp;
	}

}

int main() {
//   printf("%d\n", is_balance("()()"));
//   printf("%d\n", is_balance("()(")); (x)
//   printf("%d\n", is_balance(")))((("));
  char str[] = "()(";
  solve(str, is_balance(str), 0);
  return 0;
}