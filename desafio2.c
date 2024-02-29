#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

//prototype
void triangle(void);

//main function
int main(void)
{
    char exit = ' ';

    while (exit != 's')
    {
        triangle();
        printf("\n\nVocê quer testar outros valores [s - sair / c - continuar] ?");
        scanf(" %c", &exit);
        exit = tolower(exit);
    }

    return EXIT_SUCCESS;
}

void triangle(void)
{
    float lado1, lado2, lado3;
    float hipotenusa1;
    float hipotenusa2;
    float hipotenusa3;

    printf("\nLado 1: ");
    scanf(" %f", &lado1);
    printf("\nLado 2: ");
    scanf(" %f", &lado2);
    printf("\nLado 3: ");
    scanf(" %f", &lado3);

    hipotenusa1 = sqrt(pow(lado2, 2) + pow(lado3, 2));
    hipotenusa2 = sqrt(pow(lado1, 2) + pow(lado3, 2));
    hipotenusa3 = sqrt(pow(lado1, 2) + pow(lado2, 2));

    if (lado1 + lado2 >= lado3 && lado1 + lado3 >= lado2 && lado2 + lado3 >= lado1)
    {
        printf("\nEsse triangulo existe e é: ");
        
        if (lado1 == lado2 || lado2 == lado3 || lado1 == lado3)
        {
            if (lado1 == lado2 && lado1 == lado3)
                printf("\nEQUILATERO");
                
            else 
                printf("\nISOCELES");
        }

        else if (lado1 == hipotenusa1 || lado2 == hipotenusa2 || lado3 == hipotenusa3)
            printf("\nRETANGULO");

        else
        {
            printf("\nESCALENO");
        } 
    }

    else
        printf("\nNão é possível formar esse triangulo"); 
}