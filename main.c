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
    else{
        return 'f';
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

int getStartFromEnd(char* convertedString){
    int end = strlen(convertedString)-1;
    for (int i = end; i >= 0; i--){
        if(convertedString[i] == '0'){
            char currString[6] = {convertedString[i], convertedString[i-1], convertedString[i-2], convertedString[i-3], convertedString[i-4]};
            currString[5] = '\0';
            if(!strcmp(currString, "01100")){
                return i - 5;
            }
        }
    }
    return -1;
}
    

int getBracodeDecimal(char* barcodeDecimal, char* convertedString){
    char singlePiece[5];
    int singlePieceIndex = 0;
    int index = getStart(convertedString);
    int barcodeDecimalIndex = 0;
    while (convertedString[index] != '\0' )
    {
        if(singlePieceIndex == 4){
            singlePiece[singlePieceIndex] = convertedString[index];
            // printf("SP %s\n",singlePiece);
            char currChar = getConvertedNumber(singlePiece);
            if(currChar == 'f'){
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


int main() {
    int n;
    printf("enter n\n");
    scanf("%d",&n);
    int* arr = malloc(n * sizeof(int));
    initInputArray(n, arr);  
    char convertedString[200];
    getBlackLines(convertedString, n, arr);
    printf("%s\n",convertedString);
    printf("start: %d\n",getStart(convertedString));
    printf("end: %d\n",getStartFromEnd(convertedString));
    char barcodeDecimal[100];
    if(getStart(convertedString) == -1 || getStartFromEnd(convertedString) == -1 || getBracodeDecimal(barcodeDecimal, convertedString)){
        printf("scanning forward unsuccessful!\n");
        printf("scanning reversed...\n");
        char reversedConvertedString[200];
        strcpy(reversedConvertedString, convertedString);
        strrev(reversedConvertedString);
        if(getStart(reversedConvertedString) == -1 || getStartFromEnd(convertedString) == -1 || getBracodeDecimal(barcodeDecimal, convertedString)){
            fprintf(stderr,"invalid input\n");
            exit(EXIT_FAILURE);
        }        
        strcpy(convertedString, reversedConvertedString);
    }

    
    getBracodeDecimal(barcodeDecimal, convertedString);
    printf("%s\n",barcodeDecimal);
    
  return EXIT_SUCCESS;
}
