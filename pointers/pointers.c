#include <stdio.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    // while pointer y points to something
    while(*y) {
        // set x's pointer to be the character at y's pointer
        *x = *y;
        // increment x by 1
        x++;
        // increment y by 1
        y++;
    }
    // set x's pointer, which is now at the space after final character to 0
    *x = '\0';
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, char c)
{
    // While the string is not at the end of the array
    while (*str != '\0') {
        // if the pointer to the string is equal to c
        if (*str == c) {
            // return and print it
            printf("%s\n", str);
            return str;
        }
        // Increment the string by one
        str++;
    }
    return NULL;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    // While the haystack pointer exists
    while(*haystack) {
        // Set a pointer that points to the beginning of the haystack
        char *begin = haystack;
        // Set the pointer that points to the inside of the needle
        char *inside = needle;

        // While the haystack pointer and the inside pointer are equal to the inside pointer
        while (*haystack && *inside && *haystack == *inside) {
            // Look at the next character by incrementing both
            haystack++;
            inside++;
        }
        
        // If the inside pointer is at the end
        if (!*inside) {
            // return what we have so far
            return begin;
        }

        // Set the haystack to one after the beginning
        haystack = begin + 1;
    }
    return NULL;
}

#ifndef TESTING
int main(void)
{
    char *found_char = find_char("hello", 'e');
    char *found_string = find_string("world", "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
