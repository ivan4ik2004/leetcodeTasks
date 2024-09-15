#include <stdio.h>
#include <stdlib.h>


/*
URL OF DECISION: https://leetcode.com/problems/find-the-winning-player-in-coin-game/description/
Execution start date: 03.08.2024
End of decision: 06.08.2024
Approximate time costs: 3 hours
*/


/*
Note regarding the task: since the conditions of the problem indicate that player must pick up coins with a total value 115,
the player can do it for the one way - 75 + 4(10) or 1X + 4Y. The player is unable to do so, they lose the game.
*/

char* losingPlayer(int x, int y) {
    if(x < 1 || y < 4){
        return "Bob";
    }

    // how manmy times i can take x or y:
    int number1 = x; 
    int number2 = y / 4;

    //The most significant condition will be the one that is less
    if(number1 < number2){
        int winner1 = number1 % 2;
        if(winner1 == 0){
            return "Bob";
        }
        else{
            return "Alice";
        }
    }
    else{
        int winner2 = number2 % 2;
        if(winner2 == 0){
            return "Bob";
        }
        else{
            return "Alice";
        }

    }

}



int main(){
    int x = 2;
    int y = 12;
    printf("Func result: %s\n", losingPlayer(x,y));
    return 0;
}
