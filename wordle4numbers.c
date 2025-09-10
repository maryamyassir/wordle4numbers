#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
        printf("Hello World!\n");

        //a random number needs <stdlib.h>
        int randnum = rand() % 10; // Range: [0, N-1], in this case from 0 - 9
        // printf("%d\n", randnum);

        // ok so after compiling it I found out that you need to "seed" the rand(), meaning that the computer uses an
        // algorithm to generate a random number and if the algorithm is the same each time you run it, the random
        // number will be the same
        // a common practice is to "seed" it with the time, since it is always changing

        // to get the time you need <time.h>
        // to "seed" something with rand() you need to use srand(), this only "seeds" rand(), to generate a random
        // number, you still have to use rand(), just make sure it's seeded first.

        //seeding rand()
        srand(time(NULL));

        // new random number after rand() is seeded
        int randnum2 = rand() % 10;
        // printf("%d\n", randnum2);

        //note: yes it worked, the numbers generated after being seeded change every second you run the program

        // so for the wordle4numbers, the code will generate 3 random numbers to create a 3 digit number and the user
        // has to guess the 1st, 2nd, and 3rd, number

        //random digit 1
        int digit1 = rand() % 10;

        //random digit 2
        int digit2 = rand() % 10;

        //random digit 3
        int digit3 = rand() % 10;

        //printing the random numbers to test
        printf("%d\n", digit1);
        printf("%d\n", digit2);
        printf("%d\n", digit3);

        //initializing user's guess numbers
        int guess1, guess2, guess3;

        //now to print the "game"
        printf("----Wordle 4 Numbers!!----\n");
        printf("-Guess the 3 digit number-\n\n");
        printf("----     X | X | X    ----\n\n");

        for (int rounds; rounds < 7; rounds++)
        {
        printf("1st digit guess: ");
        scanf("%d", &guess1);

        printf("\n2nd digit guess: ");
        scanf("%d", &guess2);

        printf("\n3rd digit guess: ");
        scanf("%d", &guess3);

        printf("%d\n", guess1);
        printf("%d\n", guess2);
        printf("%d\n", guess3);

        // checking if the guesses are equal
        int guess1correct = 0;
        int guess2correct = 0;
        int guess3correct = 0;

        if (guess1 == digit1)
        {
                guess1correct = 1;
                printf("1st digit is correct!\n");
        }
        else if ((guess1 == digit2) || (guess1 == digit3))
        {
                printf("1st digit exists but not in the right spot.\n");
        }
        else
        {
                printf("1st digit is not correct.\n");
        }


        //CHECKING 2ND GUESS
        if (guess2 == digit2)
        {
                guess2correct = 1;
                printf("2nd digit is correct!\n");
        }
        else if ((guess2 == digit1) || (guess2 == digit3))
        {
                printf("2nd digit exists but not in the right spot.\n");
        }
        else
        {
                printf("2nd digit is not correct.\n");
        }

        // CHECKING 3RD GUESS
        if (guess3 == digit3)
        {
                guess3correct = 1;
                printf("3rd digit is correct!\n");
        }
        else if ((guess3 == digit2) || (guess3 == digit1))
        {
                printf("3rd digit exists but not in the right spot.\n");
        }
        else
        {
                printf("3rd digit is not correct.\n");
        }

        // displaying updated board
        //
        // if guess 1 is right
        if (guess1correct == 1)
        {
                // then if guess 2 is right
                if(guess2correct == 1)
                {
                        //then if guess 3 is right
                        if(guess3correct == 1)
                        {
                                printf("----     %d | %d | %d    ----\n\n", guess1, guess2, guess3);
                                break;
                        }

                        //then if guess 3 is not right
                        else
                        {
                                printf("----     %d | %d | X    ----\n\n", guess1, guess2);
                        }


                }

                // if guess guess 2 is not right
                else
                {
                        //if guess 3 is right
                        if (guess3correct == 1)
                        {
                                printf("----     %d | X | %d    ----\n\n", guess1, guess3);
                        }

                        // if guess 3 is not right
                        else
                        {
                                printf("----     %d | X | X    ----\n\n", guess1);
                        }

                }

        }

        // else if guess 1 is not right
        else
        {
                // then if guess 2 is right
                if (guess2correct == 1)
                {
                        // then if guess 3 is right
                        if (guess3correct == 1)
                        {

                                printf("----     X | %d | %d    ----\n\n", guess2, guess3);
                        }

                        //then if guess 3 is not right
                        else
                        {
                                printf("----     X | %d | X     ----\n", guess2);
                        }
                }

                // then if guess 2 is not right
                else
                {
                        // if guess 3 is right
                        if (guess3correct == 1)
                        {
                                printf("----     X | X | %d    ----\n\n", guess3);
                        }

                        // if guess 3 is not right
                        else
                        {
                                printf("----     X | X | X    ----\n\n");
                        }
                }
        }
   