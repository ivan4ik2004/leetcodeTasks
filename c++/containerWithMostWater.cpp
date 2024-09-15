// https://leetcode.com/problems/container-with-most-water/

#include <iostream>
#include <vector>

/*
Скорость 1-го алгоритма:

Для 0 элементов - 0 действий, для 1 элемента - 2 действия, для 2 - 5 действий...
У нас выходит формула : 0 + 2 + 3 + 4 + 5 + 6 ... n раз 


// */

// int actionsCounter(int vectorSize){
//     if (vectorSize == 0){
//         return 0;
//     }
//     int addStep = 2;
//     int result = 0;
//     while (vectorSize > 0){
//         result += addStep++;
//         vectorSize--;
//     }
//     return result;

// }


// int maxArea(std::vector<int>& height) {

//     int max = 0;

//     for (int i = 0; i < height.size(); i++){
//         int currentDistance = 0; 
//         for(int j = i; j < height.size(); j++){
//             int minEl;
//             if (height[i] > height[j]){
//                 minEl = height[j];
//             }
//             else{
//                 minEl = height[i];
//             }

//             if ((minEl * currentDistance) > max){
//                 max = minEl * currentDistance;
//             }
//             currentDistance++;
//         }
//     }

 
//     return max;
// }



/*
Скорость 2-го алгоритма:

n^2


// */

// int maxArea(std::vector<int>& height) {
//     int listSize = height.size(); 
//     int maxResult = 0;
//     for (int i = 0; i < listSize; i++){
//         for (int j = listSize; j > i ; j--){

//             int currentResult;

//             if(height[j] > height[i]){
//                 currentResult = height[i] * (j - i) ;
//                 maxResult = currentResult > maxResult ? currentResult : maxResult;
//                 break;
//             }
//             else {
//                 currentResult = height[j] * (j - i) ;
//                 maxResult = currentResult > maxResult ? currentResult : maxResult;
//             }
//         }
//     }
    
//     return maxResult;
// }



/*
Решение от CHAT GPT
Скорость 3-го алгоритма:

n (Линейная)


// */

int maxArea(std::vector<int>& height){

    int maxResult = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right){
        int currentResult = std::min(height[left], height[right] * (right - left));
        maxResult = std::max(currentResult, maxResult);

        if (height[left] < height[right]){
            left++;
        }
        else{
            right--;
        }

    }
}


int main(){
    std::vector<int> testVec = {1,8,6,2,5,4,8,3,7};
    
    int result = maxArea(testVec);
    std::cout << "Result:" << result << std::endl;
    return 0;
}
