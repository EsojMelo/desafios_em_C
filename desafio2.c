/*Briefing: sort the type of triangle by the sides*/
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

    while (exit != 'q') //run the function until you don't need more
    {
        triangle();
        printf("\n\nDo you wanna test another values [q - quit / c - continue] ?");
        scanf(" %c", &exit);
        exit = tolower(exit);
    }

    return EXIT_SUCCESS;
}

void triangle(void)
{
    float side1, side2, side3;
    float hypotenuse1;
    float hypotenuse2;
    float hypotenuse3;

    printf("\nside 1: ");
    scanf(" %f", &side1);
    printf("\nside 2: ");
    scanf(" %f", &side2);
    printf("\nside 3: ");
    scanf(" %f", &side3);

    /*We need the hypotenuse formula to check if the the triangle is rectangle*/
    hypotenuse1 = sqrt(pow(side2, 2) + pow(side3, 2));
    hypotenuse2 = sqrt(pow(side1, 2) + pow(side3, 2));
    hypotenuse3 = sqrt(pow(side1, 2) + pow(side2, 2));

    if (side1 + side2 >= side3 && side1 + side3 >= side2 && side2 + side3 >= side1) //the sum of 2 sides have to be greater than 1 side
    {
        printf("\nThere is this triangle and is: ");
        
        if (side1 == side2 || side2 == side3 || side1 == side3)
        {
            if (side1 == side2 && side1 == side3)
                printf("\nEQUILATERAL");
                
            else 
                printf("\nISOSCELES");
        }

        else if (side1 == hypotenuse1 || side2 == hypotenuse2 || side3 == hypotenuse3)
            printf("\nRECTANGULAR");

        else
        {
            printf("\nSCALENE");
        } 
    }

    else
        printf("\nIsn't there this triangle"); 
}