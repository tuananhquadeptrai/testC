#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* CWE-121: Stack Buffer Overflow - SAFE VERSION */
void stack_buffer_safe()
{
    char buffer[128];
    char source[64];
    memset(source, 'A', 63);
    source[63] = '\0';
    strcpy(buffer, source); /* SAFE: buffer đủ lớn */
    printf("%s\n", buffer);
}

/* CWE-122: Heap Buffer Overflow - SAFE VERSION */
void heap_buffer_safe()
{
    char *data = (char *)malloc(128 * sizeof(char));
    if (data == NULL) return;
    char source[64];
    memset(source, 'B', 63);
    source[63] = '\0';
    strcpy(data, source); /* SAFE: đủ bộ nhớ */
    printf("%s\n", data);
    free(data);
}

/* CWE-190: Integer Overflow - SAFE VERSION */
void integer_safe()
{
    int data = 100;
    int result = data + 1; /* SAFE: không tràn số */
    printf("Result: %d\n", result);
}

/* CWE-476: NULL Pointer Dereference - SAFE VERSION */
void null_pointer_safe()
{
    char *data = (char *)malloc(100);
    if (data != NULL) /* SAFE: kiểm tra NULL */
    {
        strcpy(data, "Hello");
        printf("%s\n", data);
        free(data);
    }
}

/* CWE-401: Memory Leak - SAFE VERSION */
void memory_safe()
{
    char *data = (char *)malloc(100 * sizeof(char));
    if (data == NULL) return;
    strcpy(data, "Hello World");
    printf("%s\n", data);
    free(data); /* SAFE: giải phóng bộ nhớ */
}

/* CWE-415: Double Free - SAFE VERSION */
void free_safe()
{
    char *data = (char *)malloc(100 * sizeof(char));
    if (data == NULL) return;
    strcpy(data, "Test");
    free(data);
    data = NULL; /* SAFE: gán NULL sau khi free */
}

/* CWE-416: Use After Free - SAFE VERSION */
void use_memory_safe()
{
    char *data = (char *)malloc(100 * sizeof(char));
    if (data == NULL) return;
    strcpy(data, "Test Data");
    printf("%s\n", data); /* SAFE: dùng trước khi free */
    free(data);
}

/* CWE-369: Divide by Zero - SAFE VERSION */
void divide_safe()
{
    int x = 10;
    int y = 2;
    if (y != 0) /* SAFE: kiểm tra trước khi chia */
    {
        int result = x / y;
        printf("Result: %d\n", result);
    }
}

int main()
{
    printf("Juliet-style SAFE code samples\n");
    return 0;
}