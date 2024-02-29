#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char menu(void);
void sum(int a, int b);
void sub(int a, int b);
void mult(int a, int b);
void divi(int a, int b);

int main(void)
{
    char choose;
    int a, b;
    char exit = ' ';

    while(exit != 'e')
    {
        printf("\nNumber 1: ");
        scanf(" %d", &a);
        printf("\nNumber 2: ");
        scanf(" %d", &b);

        choose = menu();
        if (choose == '+')
            sum(a, b);
        if (choose == '-')
            sub(a, b);
        if (choose == '*')
            mult(a, b);
        if (choose == '/')
        {
            while (b == 0)
            {
                printf("The second number cannot be 0 in divisor way\n");
                printf("Choose another one to second number: ");
                scanf(" %d", &b);
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

void sum(int a, int b)
{
    int sum = a + b;
    printf("%d + %d = %d\n", a, b, sum);
}

void sub(int a, int b)
{
    int sub = a - b;
    printf("%d - %d = %d\n", a, b, sub);
}

void mult(int a, int b)
{
    int mult = a * b;
    printf("%d x %d = %d\n", a, b, mult);
}

void divi(int a, int b)
{
    int div = a / b;
    printf("%d / %d = %d\n", a, b, div);
}