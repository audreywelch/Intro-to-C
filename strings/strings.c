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

    // for(length = 0; s[length] != '\0'; ++length);
    // printf("Length of string: %d\n", length);

    while (*(s + length) != '\0') {
        length++;
    }

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
    // set the count to the length of the string
    int count = string_length(s);
    int i = 0;

    // while the count is still greater than 1
    while (count >= 1) {

        // decrement the counter by 1
        count--;

        // the pointer in rv points to the first character,
        // Set it equal to the pointer of the original string + the count
        // Since it has been decremented, it won't include the last item, which is the 0
        // and it will be the last actual character in the array
        *(rv + i) = *(s + count);

        // increment i by 1
        i++;
    }
    // Set the last element to 0 to signal that it is the end of the array
    *(rv + i) = '\0';
    printf("%s\n", rv);
    return rv;
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
    
