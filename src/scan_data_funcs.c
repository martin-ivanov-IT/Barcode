#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "scan_data_funcs.h"
#include "encode_funcs.h"

void initInputArray(int n, int arr[n]){
    for (int i = 0; i < n; i++)
    {
        int num;
        char temp;
        scanf("%d",&num);
        scanf("%c",&temp);
        while ( temp != 32 && temp != 10 && temp != 46)
        {
            scanf("%c",&temp);
        }

        if (temp == 46)
        {
            scanf("%c",&temp);
            num = temp - 48;
            num = num<5 ? 0 : 1;
            while ( temp != 32 && temp != 10)
            {
                scanf("%c",&temp);
            }
            
        }        
        arr[i] = num;
    }
}

void fetchData(char* convertedString, int n, int arr[n]){
    int symbolsCnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 0){
            char currChar = '0';
            if (i == n-1)
            {
                convertedString[symbolsCnt] = currChar;
                symbolsCnt++;
                break;
            }

            while (arr[i+1]==0)
            {
                currChar = '1';
                i++;
            }
            convertedString[symbolsCnt] = currChar;
            symbolsCnt++;       
        }       
    }
    convertedString[symbolsCnt] = '\0';
}

int getStart(char* convertedString){
    int index = 0;
    while (convertedString[index] != '\0')
    {
        if(convertedString[index] == '0'){
            char currString[6] = {convertedString[index], convertedString[index+1], convertedString[index+2], convertedString[index+3], convertedString[index+4]};
            currString[5] = '\0';
            if(!strcmp(currString, "00110")){
                return index + 5;
            }
        }
        index++;
    }
    return -1;   
}

int getEnd(char* convertedString){
    int end = strlen(convertedString)-1;
    int start = getStart(convertedString);
    //starts searching for an end from the end of the string
    // for (int i = end; i >= start; i--){
    //     if(convertedString[i] == '0'){
    //         char currString[6] = {convertedString[i], convertedString[i-1], convertedString[i-2], convertedString[i-3], convertedString[i-4]};
    //         currString[5] = '\0';
    //         if(!strcmp(currString, "01100")){
    //             return i - 5;
    //         }
    //     }
    // }

//starts searching for an end right after start is found
    for (int i = start; i <= end; i+=5){
        if(convertedString[i] == '0'){
            char currString[6] = {convertedString[i], convertedString[i+1], convertedString[i+2], convertedString[i+3], convertedString[i+4]};
            currString[5] = '\0';
            if(!strcmp(currString, "00110")){
                return i;
            }
        }
    }
    return -1;  
}

void scanFetchedData(char* convertedString, char* barcodeDecimal){
    if(getStart(convertedString) == -1 || getEnd(convertedString) == -1 || encodeBarcode(barcodeDecimal, convertedString)){
        printf("scanning forward unsuccessful!\n");
        printf("scanning reversed...\n");
        char reversedConvertedString[200];
        strcpy(reversedConvertedString, convertedString);
        strrev(reversedConvertedString);
        printf("start reversed: %d\n", (getStart(reversedConvertedString)));
        printf("end reversed: %d\n", (getEnd(reversedConvertedString)));
        printf("print reversed: %s\n",reversedConvertedString);

            if(getStart(reversedConvertedString) == -1){  
                fprintf(stderr,"Barcode truncated. Move the scanner to the right.\n");
                exit(EXIT_FAILURE);
            }

            else if(getEnd(reversedConvertedString) == -1){     
                fprintf(stderr,"Barcode truncated. Move the scanner to the left.\n");
                exit(EXIT_FAILURE);
            }

            else if(encodeBarcode(barcodeDecimal, reversedConvertedString)){
                fprintf(stderr,"invalid input\n");
                exit(EXIT_FAILURE);
            }

        strcpy(convertedString, reversedConvertedString);
    }
}

