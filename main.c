#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char getConvertedNumber(char binDigit[5]){
    if(!strncmp(binDigit,"00001",5)){
        return '0';
    }
    else if(!strncmp(binDigit,"10001",5)){
        return '1';
    }
    else if(!strncmp(binDigit,"01001",5)){
        return '2';
    }
    else if(!strncmp(binDigit,"11001",5)){
        return '3';
    }
    else if(!strncmp(binDigit,"00101",5)){
        return '4';
    }
    else if(!strncmp(binDigit,"10100",5)){
        return '5';
    }
    else if(!strncmp(binDigit,"01100",5)){
        return '6';
    }
    else if(!strncmp(binDigit,"00011",5)){
        return '7';
    }
    else if(!strncmp(binDigit,"10010",5)){
        return '8';
    }
    else if(!strncmp(binDigit,"10000",5)){
        return '9';
    }
    else if(!strncmp(binDigit,"00100",5)){
        return '-';
    }
    else if(!strncmp(binDigit,"00110",5)){
        return 's';
    }
}

void initInputArray(int n, int arr[n]){
    for (int i = 0; i < n; i++)
    {
        int num;
        char temp;
        bool afterComma = false;
        scanf("%d",&num);
        scanf("%c",&temp);
        while ( temp != 32 && temp != 10 && temp != 46)
        {
            scanf("%d",&temp);
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
void getBlackLines(char* convertedString, int n, int arr[n]){
    int symbolsCnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 0){
            
            if (i == n-1)
            {
                char currChar = '0';
                convertedString[symbolsCnt] = currChar;
                // strncat(convertedString, &currChar, 1);
                symbolsCnt++;
                break;
            }

            if(arr[i+1] == 0){
                char currChar = '1';
                i++;
                convertedString[symbolsCnt] = currChar;
                symbolsCnt++;
                // strncat(convertedString, &currChar, 1);
            }
            else{
                char currChar = '0';
                convertedString[symbolsCnt] = currChar;
                symbolsCnt++;
                // strncat(convertedString, &currChar, 1);
            }
            //printf("%s\n",convertedString);
        }       
    }
    convertedString[symbolsCnt] = '\0';

}

void getBracodeDecimal(char* barcodeDecimal, char* convertedString){
    char singlePiece[5];
    int singlePieceIndex = 0;
    int index = 0;
    int barcodeDecimalIndex = 0;
    while (convertedString[index] != '\0' )
    {
        if(singlePieceIndex == 4){
            singlePiece[singlePieceIndex] = convertedString[index];
            char currChar = getConvertedNumber(singlePiece);
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
}

int main() {
    int n;
    printf("enter n\n");
    scanf("%d",&n);
    int* arr = malloc(n * sizeof(int));
    initInputArray(n, arr);

    char* convertedString = malloc(200);
    getBlackLines(convertedString, n, arr);
    printf("%s\n",convertedString);

    char barcodeDecimal[100];
    getBracodeDecimal(barcodeDecimal, convertedString);
    printf("%s\n",barcodeDecimal);
    
  return EXIT_SUCCESS;
}
