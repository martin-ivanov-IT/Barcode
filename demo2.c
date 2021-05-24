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


char getConvertedNumber(char binDigit[5]){
    const char* arr[][12]={
        {"00001","10001","01001","11001","00101","10100","01100","00011","10010","1000","00100","00110"},
        {"0","1","2","3","4","5","6","7","8","9","-","s"}
    };

        for(int i=0;;i++){
            if(!strncmp(binDigit,arr[0][i],5)){
                return *arr[1][i];
                break;
            }

              return 'f';
        }

    }