#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int encodeToNumeric(char c){
    if(c == '-'){
        return 10;
    }
    return c - '0';
}
int firstFormula(int n, int arr[n]){
    int rez = 0;
    for(int i = 1; i <= n; i++){
      rez += (((n-i)%10 + 1) * arr[i-1]);
    }
    rez%=11;
    return rez;
}

int secondFormula (int n, int arr[n]){
    int rez = 0;   
    for(int i = 1; i <= n + 1; i++){
      rez += (((n - i +1 ) % 9 + 1) * arr[i-1]);
    }
    
    rez%=11;
    return rez;
}

int main()
{
  
  int n;
  printf("enter n:\n");
  scanf("%d",&n);
  fflush(stdin);
  printf("enter seq: \n");
  char* arr = malloc(sizeof(char)*n);
  for (int i = 0; i < n; i++)
  {
      char c;
      scanf("%c", &c);
      fflush(stdin);
      arr[i] = c;
  }
    printf("\n");

char str[1000];
memset(str,'\0',1000);
  int digsSize = n+2;
  int* digs = malloc(sizeof(int)*n+2);
  for (int i = 0; i < digsSize-2; i++)
    {
        digs[i] = encodeToNumeric(arr[i]);
    }
int K = firstFormula(digsSize-2, digs);
digs[digsSize-2] = K;
int C = secondFormula(digsSize-2,digs);
digs[digsSize-1] = C;

printf("\n");
strcat(str,"00110");
for (int i = 0; i < digsSize; i++)
{
    if(digs[i]==0){
          strcat(str,"00001");
      }
      if(digs[i]==1){
          strcat(str,"10001");
      }
      else if(digs[i]==2){
           strcat(str,"01001");
      }
      else if(digs[i]==3){
          strcat(str,"11001");
      }
      else if(digs[i]==4){
          strcat(str,"00101");
      }
      else if(digs[i]==5){
          strcat(str,"10100");
      }
      else if(digs[i]==6){
          strcat(str,"01100");
      }
      else if(digs[i]==7){
          strcat(str,"00011");
      }
      else if(digs[i]==8){
          strcat(str,"10010");
      }
      else if(digs[i]==9){
          strcat(str,"10000");
      }
      else if(digs[i]==10){
          strcat(str,"00100");
      }
}
strcat(str,"00110");
printf("\n%s",str);
int index = 0;
char finalStr[1000];
memset(finalStr,'\0',1000);
while (str[index] != '\0')
{
    if(str[index]=='0'){
        strcat(finalStr,"0");
    }
    else{
        strcat(finalStr,"00");
    }
    strcat(finalStr,"1");
    index++;
}
index = 0;
printf("\n");
while (finalStr[index] != '\0')
{
    printf("%c ",finalStr[index]);
    index++;
}


   return 0;
}