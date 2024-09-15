//https://leetcode.com/problems/regular-expression-matching/description/
// #include <iostream>
// #include <string>



// bool isMatch(std::string s, std::string p) {
//     int firstString = 0;
//     int secondString = 0;

//     while(s[firstString] != '\0' && p[secondString] != '\0'){
//         char currrent_char1 = s[firstString];
//         char currrent_char2 = p[secondString];

//         if (currrent_char2 == '*' || currrent_char2 == '.'){
//             if(currrent_char2 == '.'){
//                 firstString++;
//                 secondString++;
//             }
//             else{
//                 int secondStringCopy = secondString;
//                 char penultimateEl = s[secondStringCopy - 1];
//                 char nextEl = p[secondString + 1];
                

//             }
//         }
//         else{
//             if (currrent_char1 != currrent_char2){
//                 return false;
//             }
//             firstString++;
//             secondString++;
//         }        
//     }


// }




// int main(){

//     std::string test1 = "aa";
//     std::string test2 = "aa";

//     bool funcResult = isMatch(test1, test2);
//     std::cout<< "Func result: " << funcResult << std::endl;

//     return 0;
// }



#include <iostream>
#include <string>



// bool isMatch(std::string s, std::string p) {
//     int firstStr = 0; // s current index 
//     int secondStr = 0; // p current index

//     while(s[firstStr] != '\0' && p[secondStr] != '\0'){
//         if (p[secondStr] == '.'){ // condithion for special char
//             firstStr++;
//             secondStr++;
//         }
//         else if (p[secondStr] == '*'){ // condithion for special char
//             char previousChar = p[secondStr - 1];
//             if(previousChar == '.'){
//                 while(s[firstStr] != p[secondStr + 1] && s[firstStr] != '\0'){
//                     firstStr++;
//                 }
//                 secondStr++;
//             }
//             else if(previousChar == '*'){
//                 firstStr++;
//                 secondStr++;
//             }
//             else{
//                 while(s[firstStr] == previousChar){
//                     firstStr++;
//                 }
//                 secondStr++;
//             }
//         }
//         else if (s[firstStr] == p[secondStr]){ // condition for regular characters
//             firstStr++;
//             secondStr++;
//         }
//         else{
//             return false;
//         }
//     }



//     // exit conditions :
//     if (s[firstStr] == '\0' && p[secondStr] == '\0'){
//         return true;
//     }
//     else{
//         return false;
//     }
// }


/*
-----------------------------------
READ ME
DETAILED FUNCTION DOCUMENTATION:
-----------------------------------


sIndex, pIndex - variables that store the current index of elements s and p.

previousElement - This element goes before the special character '*' and according to the conditions of the task, 
may or may not exist in unlimited quantities.


*/

bool isMatch(std::string s, std::string p) {
    int sIndex = 0;
    int pIndex = 0;

    while(s[sIndex] != '\0' && p[pIndex] != '\0'){
        if(p[pIndex] == '.'){
            sIndex++;
            pIndex++;
        }
        else if (p[pIndex + 1] == '*'){
            char previousElement = s[sIndex]; 
            if(s[sIndex] == previousElement){
                while(s[sIndex] == previousElement){
                    sIndex++;
                }
            }

            pIndex += 2; // do not forget that we took two elements ('*' and the previous one)

        }

        else{ // if no condition is met then we must compare both characters
            if (s[sIndex] != p[pIndex]){ 
                return false;
            }
            sIndex++;
            pIndex++;
        }
    }


    // exit condithion
    if(s[sIndex] == '\0' && p[pIndex] == '\0'){
        return true;
    }
    else if (s[sIndex] == '\0'){
        while (p[pIndex] != '\0'){
            if(p[pIndex + 1] != '*'){
                return false;
            }
            pIndex += 2;
        }
    }
    else {
        return false;
    }



}


int main(){
    std::string testString = "aab";
    std::string testPattern = "c*a*b";

    int result = isMatch(testString, testPattern);

    std::string newRes = result == 1 ? "true" : "false";
    std::cout << newRes << std::endl;

    return 0;
}