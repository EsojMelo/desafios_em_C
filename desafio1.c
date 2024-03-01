/*Briefing: Check the prime number*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

//prototype
void primeNumber(void);

//main function
int main(void)
{
    char exit = ' ';

    while (exit != 'e')
    {
        primeNumber();
        printf("\n\nDo you wanna test anothe number [e - exit / c - continue]: ");
        scanf(" %c", &exit);
        exit = tolower(exit);
    }

    return EXIT_SUCCESS;
}

/*Verify if the number is prime or not*/
void primeNumber(void)
{
    int number;
    int choose;
    int nonPrimeCount = 0;

    printf("\nChoose a number: ");
    scanf(" %d", &choose);
    if (choose == 0)
        printf("\nchoose another non zero number"); //zero is not valid
    
    else
    {
        for ( number = 1; number < choose ; number++)
        {    
            if (choose % number == 0)
                nonPrimeCount++; //Counter of divisions
            if (nonPrimeCount > 1)/*if nonPrimeCount exceed 1 this is not prime*/
            {
                printf("\nThe choosed number IS NOT prime");
                break;
            }
        }
        
        if (nonPrimeCount == 1 || choose == 1)// the number 1 is prime
            printf("\nThe choosed number IS prime");
    }
}