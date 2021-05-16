#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char arr[3];
    arr[0] = 'a';
    arr[1] = 's';
    arr[2] = 'd';
    int result = strncmp(arr, "asd", 3);
     printf("%d\n", result);
    
 

  return EXIT_SUCCESS;
}