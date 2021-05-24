#include "formulas.h"
int calcK(int n, int arr[n]){
    int rez = 0;
    for(int i = 1; i <= n; i++){
      rez += (((n-i)%10 + 1) * arr[i-1]);
    }
    rez%=11;
    return rez;
}

int calcC (int n, int arr[n]){
    int rez = 0;   
    for(int i = 1; i <= n + 1; i++){
      rez += (((n - i +1 ) % 9 + 1) * arr[i-1]);
    }
    
    rez%=11;
    return rez;
}