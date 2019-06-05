#include <stdio.h>
#include <stdlib.h>

// gcc -Wall -Wextra -o hello hello.c
// ./hello

/*
    Given a character array s (as a pointer), return the number of 
    characters in the string.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char *s)
{
    int length;

    for(length = 0; s[length] != '\0'; ++length);
    printf("Length of string: %d\n", length);

    return length;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char *rv, char *s)
{
    // while the new array is less than the given array
    // while (rv < s) {
    //     char temporary = *rv;
    //     *rv-- = *s;
    //     *s++ = temporary;
    // }
    // printf("%s", s);
    // return s;

    int beginning = 0;
    int ending = 0;
    int length = 0;
    //int length = string_length(s);

    while (s[length] != '\0') {
        length++;
    }

    ending = length - 1;

    for (beginning = 0; beginning < length; beginning++) {
        rv[beginning] = s[ending];
        ending--;

    }

    rv[beginning] = '0';

    printf("%s\n", rv);

    return 0;

}

#ifndef TESTING
int main(void)
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "a man a plan a canal panama";

    char rv[512];

    printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

    return 0;
}
#endif
    
