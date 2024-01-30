// PAL Week 4 - Exercise:
//					guess the right value
// 
// Program:
// • Define a hidden guess (value) in your program
// • Prompt the user to enter an integer
// • Continue prompting the user until they guess the right number!
// 
// Challenge:
// • Can you think of a way to randomly generate a guess instead of
// hardcoding one?
//     • Kudos if you give it a try!
// PROG71985-W24
// 
// 
// revision history
// 1.0			2023-01-29      initial

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(void)
{
    // initialize random number seed
	srand((unsigned)time(NULL));

    int num = rand() % 100 + 1; // generate between 0 and 100

    // prompting the user and verifying 
    int guess;
    do
    {
		// printf("num: %d\n", num);
        
        printf("Guess a number:\n");
        int symbols_returned = scanf("%d", &guess);
        
        /*
        * incorrect input
        * guess is correct
        * guess is incorrect
        */
        if (symbols_returned != 1)
        {
            while (getchar() != '\n')
                continue;
            printf("Invalid input.\n");
        }
        else if (guess == num)
        {
            printf("\aYipee! You guessed it right!\n");
        }
        else
        {
            if (guess < num)
                printf("You guessed too low! Try again.\n");

            if (guess > num)
                printf("You guessed too high! Try again.\n");
        }
    }while(num != guess);

    return 0;
}
