/*Briefing: Calculator [+] [-] [x] [/] between 2 numbers */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char menu(void);
void sum(float a, float b);
void sub(float a, float b);
void mult(float a, float b);
void divi(float a, float b);

float main(void)
{
    char choose;
    float a, b;
    char exit = ' ';

    while(exit != 'e')
    {
        printf("\nNumber 1: ");
        scanf(" %f", &a);
        printf("\nNumber 2: ");
        scanf(" %f", &b);

        choose = menu();
        if (choose == '+')
            sum(a, b);
        if (choose == '-')
            sub(a, b);
        if (choose == '*')
            mult(a, b);
        if (choose == '/')
        {
            while (b == 0) //Is not valid split a number by 0
            {
                printf("The second number cannot be 0 in divisor way\n");
                printf("Change the values\n");
                printf("\nNumber 1: ");
                scanf(" %f", &a);
                printf("\nNumber 2: ");
                scanf(" %f", &b);
            }
            
            divi(a, b);
        }
        
        printf("Do you wanna try another operation [e - exit / c - continue]");
        scanf(" %s", &exit);
        exit = tolower(exit);
    }

    return EXIT_SUCCESS;
}

char menu(void)
{
    char operator;

    printf("\nchoose one of these operations:\n"
            "[+] - Addition\n"
            "[-] - subtraction\n"
            "[*] - Multiplication\n"
            "[/] - Division\n\n"
            "Choose one: ");
    scanf(" %s", &operator);
    return operator;
}
/*Sum equation*/
void sum(float a, float b)
{
    float sum = a + b;
    printf("%.2f + %.2f = %.2f\n", a, b, sum);
}
/*subtraction equation*/
void sub(float a, float b)
{
    float sub = a - b;
    printf("%.2f - %.2f = %.2f\n", a, b, sub);
}
/*multiplication equation*/
void mult(float a, float b)
{
    float mult = a * b;
    printf("%.2f x %.2f = %.2f\n", a, b, mult);
}
/*division equation*/
void divi(float a, float b)
{
    float div = a / b;
    printf("%.2f / %.2f = %.2f\n", a, b, div);
}