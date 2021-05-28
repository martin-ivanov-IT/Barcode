#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "formulas.h"
#include "scan_data_funcs.h"
#include "encode_funcs.h"
#include "defines.h"

int main() {
    int n;
    printf("enter n\n");
    scanf("%d",&n);
    int* arr = malloc(n * sizeof(int));
    initInputArray(n, arr);  
    char convertedString[STRING_SIZE];
    fetchData(convertedString, n, arr);
    free(arr);
    char barcodeDecimal[STRING_SIZE];
    scanFetchedData(convertedString, barcodeDecimal);
    encodeBarcode(barcodeDecimal, convertedString);
    if(validateBarcode(barcodeDecimal)){
        printf("The barcode is valid:\n");
        for (size_t i = 0; i < strlen(barcodeDecimal)-CONTROL_SYMBOLS_COUNT; i++)
        {
           printf("%c",barcodeDecimal[i]);
        }    
    }
    else{
        printf("invalid barcode validation unsuccessful");
    }

    
  return EXIT_SUCCESS;
}
