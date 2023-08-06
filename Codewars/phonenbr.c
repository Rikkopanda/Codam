#include <stdio.h>
char *create_phone_number(char phnum[15], const unsigned char nums[10])
{
// write to phnum and return it
// it must be nul-terminated
// country doenst matter
  int i;
  int j;
  
  j = 0;
  i = 0;
  phnum[0] = '(';
  phnum[4] = ')';
  phnum[5] = ' ';
  phnum[10] = '-';
  
  while(i < 14)
  {
    if(i != 0 && i != 4 && i != 5 && i != 10)
    {
      phnum[i] = nums[j] + '0';
      j++;
    }
    i++;
  }
  phnum[i] = '\0';
  return phnum;
}

int main(void)
{
  char number[15];
  create_phone_number(number, (const unsigned char[]){1,2,3,4,5,6,7,8,9,0});
  printf("%s\n", number);
}