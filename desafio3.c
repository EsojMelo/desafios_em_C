#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 30

int palindrome(void);

int main(void)
{
    char exit = ' ';

    while (exit != 'q')
    {
        palindrome();
        printf("\n\nDo you wanna test another word [q - quit / c - continue] ?");
        scanf(" %c", &exit);
        exit = tolower(exit);
    }

    return EXIT_SUCCESS;
}

int palindrome(void)
{
    char word[N];
    int size;
    printf("Write a word: ");
    scanf(" %s", word);
    size = strlen(word);
    for (int i = 0; i < size / 2; i++)
    {
        if (word[i] != word[size - i - 1])
        {
            printf("This word IS NOT a palindrome");
            return 0;
        }
    }
    
    printf("This word IS a palindrome");
    return 0;
}