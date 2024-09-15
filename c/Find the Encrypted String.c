/*
https://leetcode.com/problems/find-the-encrypted-string/description/
Execution start date: 17.07.2024
End of decision: 01.08.2024
*/ 


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// FIRST TRY:
// char* getEncryptedString(char* s, int k) {

//     int lenS = strlen(s);
//     if(lenS <= k){
//         return s;
//     }

//     char* newS = (char*)malloc((lenS + 1) * sizeof(char)); // new String 
//     int kCpy = k; // just copy k 
//     for(int i = 0; i < lenS; i++,kCpy++){
//         newS[i] = s[kCpy];
//     }


//     int stringFullness = lenS - k; // number of elements in our new String
//     for(int c = 0; c <= k ; c++){
//         newS[stringFullness++] = s[c];
//     }

//     newS[lenS] = '\0';
//     return newS;
// }


// SECOND TRY 

char* getEncryptedString(char* s, int k) {

    int lenS = strlen(s);
    k = k % lenS;

    char* newS = (char *)malloc( (lenS + 1)  * sizeof(char));


    for (int c = 0 ; c < lenS; c++){
        newS[c] = s[(c + k) % lenS];
    }

    newS[lenS] = '\0';
    return newS;


}



int main(){

    char myS[] = "dart";
    int k = 3;
    char *result = getEncryptedString(myS, k);
    printf("Func result:\t%s\n", result);

    free(result);

    return 0;
}