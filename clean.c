#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ITEMS 10

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    double price;
} Item;

int safe_add(int a, int b, int *result) {
    if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b)) {
        return -1;
    }
    *result = a + b;
    return 0;
}

void safe_string_copy(char *dest, const char *src, size_t dest_size) {
    if (dest == NULL || src == NULL || dest_size == 0) {
        return;
    }
    strncpy(dest, src, dest_size - 1);
    dest[dest_size - 1] = '\0';
}

Item *create_item(int id, const char *name, double price) {
    Item *item = (Item *)malloc(sizeof(Item));
    if (item == NULL) {
        return NULL;
    }
    
    item->id = id;
    safe_string_copy(item->name, name, MAX_NAME_LENGTH);
    item->price = price;
    
    return item;
}

void free_item(Item *item) {
    if (item != NULL) {
        free(item);
    }
}

void print_item(const Item *item) {
    if (item == NULL) {
        printf("Item is NULL\n");
        return;
    }
    printf("ID: %d, Name: %s, Price: %.2f\n", item->id, item->name, item->price);
}

int main(void) {
    Item *item = create_item(1, "Apple", 2.50);
    
    if (item != NULL) {
        print_item(item);
        free_item(item);
    }
    
    int result;
    if (safe_add(100, 200, &result) == 0) {
        printf("Sum: %d\n", result);
    }
    
    return 0;
}