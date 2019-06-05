#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

/*
    Duplicates the input string by dynamically allocating memory for 
    the duplicate string using `malloc` and then copying the string
    into the allocated memory. Returns a pointer to the allocated memory.
    You may want to use the string_length function to figure out the
    length of the input string.
*/

int string_length(char *s)
{
    return strlen(s);
}

char *string_dup(char *src)
{
    // Get the length of the string
    int length = string_length(src);

    // Allocate enough memory for the new duplicated string
    char *duplicated_string = malloc(length + 1);

    // Another possibility:
    // for (int i = 0; i < length; i++) {
        // *(duplicated_string + i) = *(src + i)
    // }

    // Set the value of the first character pointer to the duplicate
    char *starting_char = duplicated_string;

    // While the value in src exists
    while(*src) {
        // Set value of duplicated string's first space to value of src's first space
        *duplicated_string = *src;
        // Increment both strings
        src++;
        duplicated_string++;
    }
    // Mark the ending of the string
    *duplicated_string = '\0';
    return starting_char;

}

/*
    A generic version of string_copy, mem_copy receives a block of memory
    of any type and copies its contents to the destination pointer (dest).
    You may want to cast the input pointers to char pointers first before
    performing the copying. `n` is the amount of data that should be copied
    from `src` to `dest`. 
*/
void mem_copy(void *dest, const void *src, int n)
{
    // Explicitly cast the input pointers to char pointers
    char *cast_dest = (char *) dest;
    char *cast_src = (char *) src;
    
    // Copy the contents from the source to the destination
    for (int i = 0; i < n; i++) {
        *(cast_dest + i) = *(cast_src + i);
    }
}

/*
    Given a pointer of `malloc`'d memory, this function will 
    attempt to resize the allocated memory to the new specified
    size. Any data that was previously in the old `malloc`'d 
    memory should be intact in the new resized block of memory. 
    Some edge cases to consider: how should resizing be handled
    in the case when old_size < new_size? What about when 
    old_size > new_size?
    
    Do not use the `realloc` function from the standard libary.
*/
void *resize_memory(void *ptr, int old_size, int new_size)
{
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    else if (!ptr) {
        return malloc(new_size);
    }

    else if (old_size == new_size) {
        return ptr;
    }

    void *new_block = malloc(new_size);

    if (new_size < old_size) {
        mem_copy(new_block, ptr, new_size);
    }

    else {
        mem_copy(new_block, ptr, old_size);
    }
    free(ptr);
    return new_block;
}

#ifndef TESTING
int main(void)
{
    char *s = "Some string to duplicate.";
    char *dup = string_dup(s);

    printf("Duplicated string: %s\n", dup);

    int numbers[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int *target = malloc(n * sizeof(int));
    
    mem_copy(target, numbers, n * sizeof(int));

    printf("Copied array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", target[i]);
    }

    printf("\n");

    char *url = string_dup("http://lambdaschool.com");
    char *path = string_dup("/students/");
    int url_length = string_length(url);
    int path_length = string_length(path);
    
    int new_length = url_length - 1 + path_length;
    char *new_url = resize_memory(url, url_length, new_length);
    char *p = new_url + url_length;

    while (*path != '\0') {
        *p = *path;
        p++;
        path++;
    }

    printf("Full path string: %s\n", new_url);

    return 0;
}
#endif