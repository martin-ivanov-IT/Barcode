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
    printf("%s\n",convertedString);//remove me
    char barcodeDecimal[STRING_SIZE];
    printf("start : %d\n", (getStart(convertedString)));//remove me
    printf("end : %d\n", (getEnd(convertedString)));//remove me
    scanFetchedData(convertedString, barcodeDecimal);
    encodeBarcode(barcodeDecimal, convertedString);
    printf("%s\n",barcodeDecimal);//remove me
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
