#include <stdio.h>


int myAtoi(char* s) {
    int max = 2147483647;
    int min = -2147483648;
    int result = 0;
	int sign = 0;
    int i = 0;

    while (s[i] == ' '){ // implementation of the first condition (ignore any leading whitespace)
        i ++;
    }

    if (s[i] == '-' || s[i] == '+'){// implementation of the second condition (Check if the next character '+' or '-')
        if(s[i] == '-'){
            sign = 1;
        }
        i++;
    }


	for (i; s[i] != '\0'; i++){
    	int ascii_code = (int)s[i]; // ASCII character code
		if (ascii_code >= 48 && ascii_code <= 57 ){  // checking if the current element is a number
            if ((result > max / 10) || (result == max / 10 && ascii_code - 48 > max % 10)){
			    return sign == 0 ? max : min ;
            }
			result = result * 10 + (ascii_code - 48);
		}
		else{
			return sign == 0 ? result : -result;
		}
	}
	return sign == 0 ? result : -result;

}






int main() {
	int func_res = myAtoi("-9128347233");
	printf("Результат : %d\n", func_res);
	return 0;
}
