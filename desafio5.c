#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void countNum(long long int number);

int main(void)
{
    long long int num;
    char exit = ' ';

    while(exit != 'e')
    {
        printf("\nChoose a number: ");
        scanf(" %lld", &num);
        countNum(num);
        
        printf("\nDo you wanna try another operation [e - exit / c - continue]\n");
        scanf(" %s", &exit);
        exit = tolower(exit);
    }

    return EXIT_SUCCESS;
}

void countNum(long long int number)
{
    int sum = 0;
    
    if (number == 0)
        printf("\nThis number have 1 digit\n");
    
    else 
    {
        while (number >= 1)
        {
            sum++;
            number = number / 10;
        }
    
        printf("\nThis number have %d digit\n", sum);
    }
}