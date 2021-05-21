#include <stdio.h>
#include <string.h>
int main()
{
   char s[100];
    char c[100];
   printf("Enter a string to reverse\n");
   gets(s);
    strcpy(c, s);
   strrev(c);

   printf("Reverse of the string: %s\n", c);

   return 0;
}