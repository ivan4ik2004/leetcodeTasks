#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
URL OF DECISION: https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/description/
Execution start date: 17.08.2024
End of decision: 17.08.2024
Approximate time costs: ~ 1 hour 
*/



/*
Если оба числа находятся рядом с друг другом и у них есть сходство в плане четности (они оба четные или нечетные) - мы 
можем поменять их местами.
Цель:
    вернуть строку максимально лексиграфически наименьшую  строку. 

Нужно помнить, что подобную операцию мы можем сделать всего единожды, следовательно нужно начинать с старшего разряда,
ведь его наиболее выгодней менять и продвигаться слева направо. Первые встречающиеся соседние числа, которые подходят под требование 
задачи - меняем.

*/


char* getSmallestString(char* s) {
    int sLen = strlen(s);

    char* newstring = (char *)malloc(sizeof(char) * (sLen + 1));
    if (newstring == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }

    int i;
    for (i = 0; i < sLen - 1; i++) {
        if ((s[i] % 2 != 0 && s[i + 1] % 2 != 0 && s[i] > s[i + 1]) || 
            (s[i] % 2 == 0 && s[i + 1] % 2 == 0 && s[i] > s[i + 1])) {
            
            // Обмен соседних цифр
            newstring[i] = s[i + 1];
            newstring[i + 1] = s[i];
            i += 1;  // Пропускаем следующий символ, так как он уже обработан
            
            // Копируем оставшиеся символы
            for (int j = i + 1; j < sLen; j++) {
                newstring[j] = s[j];
            }

            newstring[sLen] = '\0';  // Завершаем строку
            return newstring;
        } else {
            newstring[i] = s[i];
        }
    }

    if( i < sLen){
        newstring[i] = s[i];
    }


    newstring[sLen] = '\0';
    return newstring;
}



int main(){
    char myS[] = "001";
    char *result = getSmallestString(myS);
    printf("%s\n", result);
    free(result);
    return 0;
}
