#include <stdio.h>
#include <string.h>
#include <stdlib.h>



char* convert(char* s, int numRows) {
        // BASIC VARIABLE: 
        int stringLen = strlen(s);
        int maxStringsLen = numRows > 1 ? stringLen / 2 : stringLen;

        // STANDARD CONDITHION: 
        if (numRows < 2 || stringLen <= numRows){
            return s;
        }

        // VARIABLE FOR SAVE:
        char *stringsList = malloc(sizeof(char) * (maxStringsLen * numRows)); // all lines will be stored here
        if (stringsList == NULL){ // check if memory has been allocated
            return NULL;
        }
        int *indexData =  calloc(sizeof(int), numRows); // here the rows are divided into 'numRows' and indexes for adding are stored
        if (indexData == NULL){ // check if memory has been allocated x2
            free(stringsList);
            return NULL;
        }

        int startPoint = 0; // the value for adding the first element is always 0
        for (int i = 0; i < numRows; i ++){
            indexData[i] = startPoint;
            startPoint += maxStringsLen; // here a value is generated to add for the next element
        }

        // VARIABLE FOR ADD:
        int addingDirection = 0; // here it is determined in which direction the addition will go: 0 - from element 0 to 'numRows', 
        // 1 - back.
        int addIndex = 0; //is responsible for which row we will insert the current character into (from 0 to 'numRows' - 1)
    
        for (int i = 0; i < stringLen - 1; i++){
            stringsList[indexData[addIndex]] = s[i];
            indexData[addIndex]++;
            if (addIndex == 0 || addIndex == numRows - 1){ // change direction if the conditions are true:
                addingDirection = !addingDirection;
            }
            addIndex += addingDirection ? 1 : -1;
        }
        

    
        // CLEANING UP LINE INDENTS:
        int newSize = 0;
        for (int j = 0; j < (maxStringsLen * numRows); j++){
            if(stringsList[j] != NULL){
                stringsList[newSize++] = stringsList[j];
            }
        }
        stringsList[newSize] = '\0';

        free(indexData);
        return stringsList;
        
}


int main(){
    char headSrting[] = "A";
    int numRows = 1;
    char *result = convert(headSrting, numRows);
    printf("Result: %s\n", result);
    
    return 0;
}