#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#include "encode_funcs.h"
#include "scan_data_funcs.h"
#include "formulas.h"
#include "defines.h"

// char getConvertedNumber(char binDigit[5]){
//     if(!strncmp(binDigit,"00001",5)){
//         return '0';
//     }
//     else if(!strncmp(binDigit,"10001",5)){
//         return '1';
//     }
//     else if(!strncmp(binDigit,"01001",5)){
//         return '2';
//     }
//     else if(!strncmp(binDigit,"11001",5)){
//         return '3';
//     }
//     else if(!strncmp(binDigit,"00101",5)){
//         return '4';
//     }
//     else if(!strncmp(binDigit,"10100",5)){
//         return '5';
//     }
//     else if(!strncmp(binDigit,"01100",5)){
//         return '6';
//     }
//     else if(!strncmp(binDigit,"00011",5)){
//         return '7';
//     }
//     else if(!strncmp(binDigit,"10010",5)){
//         return '8';
//     }
//     else if(!strncmp(binDigit,"10000",5)){
//         return '9';
//     }
//     else if(!strncmp(binDigit,"00100",5)){
//         return '-';
//     }
//     else if(!strncmp(binDigit,"00110",5)){
//         return 's';
//     }
//     else{
//         return 'f';
//     }
// }

char getConvertedNumber(char binDigit[5]){
    const char* arr[][12]={
        {ZERO_CODE,ONE_CODE,TWO_CODE,THREE_CODE,FOUR_CODE,FIVE_CODE,SIX_CODE,SEVEN_CODE,EIGHT_CODE,
        NINE_CODE,TEN_DASH_CODE,START_STOP_CODE},
        {"0","1","2","3","4","5","6","7","8","9","-","s"}
    };

        for(int i=0;i<12;i++){
            if(!strncmp(binDigit,arr[0][i],5)){
                return *arr[1][i];
                break;
            }


        }
         return INVALID_CODE_VALUE;


    }

int encodeBarcode(char* barcodeDecimal, char* convertedString){
    char singlePiece[BINARY_SYMBOL_LENGHT];
    int singlePieceIndex = 0;
    int index = getStart(convertedString);
    int end = getEnd(convertedString);
    int barcodeDecimalIndex = 0;
    while (index <= end )
    {
        if(singlePieceIndex == BINARY_SYMBOL_LENGHT-1){
            singlePiece[singlePieceIndex] = convertedString[index];
            char currChar = getConvertedNumber(singlePiece);
            if(currChar == INVALID_CODE_VALUE){
                return 1;
            }

            barcodeDecimal[barcodeDecimalIndex] = currChar;
            barcodeDecimalIndex++;
            singlePieceIndex = 0;
            index++;
            continue;
            
        }
        singlePiece[singlePieceIndex] = convertedString[index];
        singlePieceIndex++;
        index++;
    }
    barcodeDecimal[barcodeDecimalIndex] = '\0';
    return 0;
}

int encodeToNumeric(char c){
    if(c == DASH_ASCII){
        return TEN_DASH_NUMERIC_VALUE;
    }
    return c - ZERO_ASCII;
}

bool validateBarcode(char* barcodeDecimal){
    int barcodeDecimalLenght= strlen(barcodeDecimal);
    int C = barcodeDecimal[barcodeDecimalLenght-1] - ZERO_ASCII;
    int K = barcodeDecimal[barcodeDecimalLenght-2] - ZERO_ASCII;
    int digsSize = barcodeDecimalLenght-1;
    int* digs = malloc(sizeof(int)*digsSize);
    for (int i = 0; i < digsSize-1; i++)
    {
        digs[i] = encodeToNumeric(barcodeDecimal[i]);
        
    }

    int KCheck = calcK(digsSize-1, digs);
    digs[digsSize-1] = encodeToNumeric(barcodeDecimal[digsSize-1]);
    int CCheck = calcC(digsSize-1,digs);
    free(digs);
    if(K == KCheck && C == CCheck){
        return true;
    }
    return false;
}