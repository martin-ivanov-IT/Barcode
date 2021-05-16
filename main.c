#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int readNextNumber(FILE* file, bool* isEof){
    
    char str[1000];
    int i = 0;
    char c = fgetc(file);
    while (c!=' ' && c!='\n')
    {
        if(feof(file) ){
            str[i++] = c;
            str[i] = '\0';
            *isEof = true;
            return atoi(str);
        }

        str[i++] = c;
        c = fgetc(file);
        
 
    }
    str[i] = '\0';

    return atoi(str);
    
}

void readData(FILE* file, int n, int array[n]){
    bool isEof = false;
    int index = 0;
    int num = readNextNumber(file, &isEof);
    while (!isEof)
    {
        array[index] = num;
        num = readNextNumber(file, &isEof);
        index++;
    }
    
}
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
void convertInput(char* convertedValue, int n, int arr[n]){
    char binDigigt[5];
    int numbers[n];
    int indexbinDigigt = 0;
    int convertedValueIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 1){
            continue;
        }

        else if(arr[i] == 0){
            if(i == n-1 || arr[i+1] == 0){
                binDigigt[indexbinDigigt] = '1';
                indexbinDigigt++;
            }
            else if (arr[i+1] ==1){
                binDigigt[indexbinDigigt] = '0';
                indexbinDigigt++;
            }

            if(indexbinDigigt == 5){
                convertedValue[convertedValueIndex] = getConvertedNumber(binDigigt);
                convertedValueIndex++;
                indexbinDigigt++;
            }
            
        }
        convertedValue[convertedValueIndex] = '\0';

    }
    
}

int main() {
    FILE *dataPtr = NULL;
    char* INPUT = "INPUT.txt";
    dataPtr = fopen (INPUT, "r");
    if(dataPtr==NULL){
        printf("Failed to open %s.\n",INPUT);
    }

    int n;
    n = readNextNumber(dataPtr,false);
    printf("%d\n",n);
    int* arr = malloc(n * sizeof(int));
    readData(dataPtr, n, arr);
    char* convertedValue = malloc(n);
    convertInput(convertedValue, n, arr);
    printf("%s\n",convertedValue);
    
 

  return EXIT_SUCCESS;
}