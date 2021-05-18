#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    // int arr[] = {1,2,3,10,4,5};
    // int rez = 0;
    // int n = 6;
    // for(int i = 1; i <= n; i++){
    //   rez += (((n-i)%10 + 1) * arr[i-1]);
    // }
    // rez%=11;

    int rez2 = 0;
    int arr2[] = {1,2,3,10,4,5,5};
    int n = 6;
    
    for(int i = 1; i <= n + 1; i++){
      rez2 += (((n - i +1 ) % 9 + 1) * arr2[i-1]);
    }
    
    rez2%=11;
    printf("\n%d", rez2); 

    // int rez2 = 0;
    // int arr2[] = {4,2,8};
    // int n = 3;
    
    // for(int i = 1; i <= n; i++){
    //   rez2 += ((((n-1) - i +1 ) % 9 + 1) * arr2[i-1]);
    // }
    // rez2%=11;
    // printf("\n%d", rez2);

  return EXIT_SUCCESS;
}