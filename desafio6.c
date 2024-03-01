/*Briefing: It make a sum of the even firts numbers of Fibonacci serie.*/
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    //
    double i = 1;
    double ant = 0;
    double pos = 0 , soma = 0;;
    int cont = 0;
    int div = 1;
    /*Only count if the number is even */
    while (cont < 200 )
    {
        pos = i + ant;
        if (cont >= 200)
        {
            break;
        }
        ant = i;
        i = pos;
        div++;
        if (div > 2) // This series have a logical sequence, each 2 odds numbers the next is even
        {
            soma += i;
            cont++;
            div = 0;
            printf(" %.0f\n", i);
        }
    }
    //print the values sum
    printf("\nsoma: %.0f ", soma); //it don't have a great precision but is valid
    printf("\ncont: %d\n", cont);
    
    return EXIT_SUCCESS;
}