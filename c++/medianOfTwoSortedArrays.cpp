//https://leetcode.com/problems/median-of-two-sorted-arrays/description/
#include <iostream>
#include <vector>


double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    const int m = nums1.size();
    const int n = nums2.size();
}

/*


В данной задаче может быть несколько состояний каждого из векторов: 
1. Длинна вектора равна 0 (вектор пуст)
2. Длинна вектора четная - для определенния медианы нам нужно взять два центальных элемента просумировать и разделить на 2.
3. Длинна вектора нечетная - для определения медианы мы можем длину разделить на 2.


Возьмем для примера векторы с числами от 1 до 10:

vector1 = {1,3,5,7,9} - вектор нечетный, медиана 5
vector2 = {2,4,6,8,10} - вектор нечетный, медиана 6 

Обозначим медиану как х.  
unitedVectors = {1,2,3,4,5,x,6,7,8,9,10} x = (5 + 6) / 2 = 5.5


Если бы длина была нечетная - мы бы могли взять за х за два центральных числа и обозначить их как x0 и x1.
Следовательно мы должны понимать:
1.Сумма четного и нечетного числа - всегда будет давать нечетное число.
2.Сумма двух четных чисел - дает всегда четное.
3.Сумма двух нечетных чисел - дает всегда четное.

Понимание этого даст нам умение распознать ситуацию когда требуется захватывать две медианы, когда одну.
Например:
vector1 = {1,3,5,7,9} - вектор нечетный, медиана 5
vector2 = {2,4,6,8} - вектор четный, медиана х0 - 4 , х1 - 6 
Сответсвенно правилам - результат будет нечетный и медиана будет разделяться на х0 и х1.

Обозначим медиану как х0 и х1.  
unitedVectors = {1,2,3,4,5,6,7,8} x0 = 4 , x1 = 5. (x0 + x1) / 2 = 4.5


Если проаналиироваь примеры выше - можно прийти к выводу, что элементы за исключением медианы не анализируются - соответсвенно можно 
и нужно не тратить на них время.
Соответсвено наш алгоритм должен проходить по определенным этапам:
1. Обработка исключений: учитываем случаи когда m и/или n равны 0 или 1.
2. Определенние четности/нечетности для m и n

*/



int main(){
    std::vector<int> vector1 = {1,3,5,7,9}; 
    std::vector<int> vector2 = {2,4,6,8,10};
    

    return 0;
}