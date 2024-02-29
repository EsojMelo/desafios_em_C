#include <stdio.h>
#include <stdlib.h>

//fazer uma soma dos 200 primeiros números pares da sequência de Fibonacci.

int main(void)
{
    //
    double i = 1;
    double ant = 0;
    double pos = 0 , soma = 0;;
    int cont = 0;
    long long int div = 0;
    //process
    while (cont < 200 )
    {
        pos = i + ant;
        if (cont >= 200)
        {
            break;
        }
        ant = i;
        i = pos;
        div = pos;
        if (div % 2 == 0)
        {
            soma += i;
            cont++;
        }
    }
    //print da soma dos valores
    printf("\nsoma: %f ", soma);
    printf("\ncont: %d\n", cont);
    
    return EXIT_SUCCESS;
}