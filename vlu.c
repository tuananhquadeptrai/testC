#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* CWE-121: Stack-based Buffer Overflow */
void stack_buffer_overflow_bad()
{
    char buffer[64];
    char source[128];
    memset(source, 'A', 127);
    source[127] = '\0';
    strcpy(buffer, source); /* FLAW: buffer overflow */
    printf("%s\n", buffer);
}

/* CWE-122: Heap-based Buffer Overflow */
void heap_buffer_overflow_bad()
{
    char *data = (char *)malloc(64 * sizeof(char));
    char source[128];
    memset(source, 'B', 127);
    source[127] = '\0';
    strcpy(data, source); /* FLAW: heap buffer overflow */
    printf("%s\n", data);
    free(data);
}

/* CWE-190: Integer Overflow */
void integer_overflow_bad()
{
    int data = 2147483647; /* INT_MAX */
    int result = data + 1; /* FLAW: integer overflow */
    printf("Result: %d\n", result);
}

/* CWE-476: NULL Pointer Dereference */
void null_pointer_deref_bad()
{
    char *data = NULL;
    printf("%s\n", data); /* FLAW: NULL pointer dereference */
}

/* CWE-401: Memory Leak */
void memory_leak_bad()
{
    char *data = (char *)malloc(100 * sizeof(char));
    strcpy(data, "Hello World");
    printf("%s\n", data);
    /* FLAW: memory not freed - memory leak */
}

/* CWE-415: Double Free */
void double_free_bad()
{
    char *data = (char *)malloc(100 * sizeof(char));
    strcpy(data, "Test");
    free(data);
    free(data); /* FLAW: double free */
}

/* CWE-416: Use After Free */
void use_after_free_bad()
{
    char *data = (char *)malloc(100 * sizeof(char));
    strcpy(data, "Test Data");
    free(data);
    printf("%s\n", data); /* FLAW: use after free */
}

/* CWE-369: Divide by Zero */
void divide_by_zero_bad()
{
    int x = 10;
    int y = 0;
    int result = x / y; /* FLAW: divide by zero */
    printf("Result: %d\n", result);
}

int main()
{
    printf("Juliet-style vulnerability samples\n");
    return 0;
}