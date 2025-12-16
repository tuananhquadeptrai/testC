#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NAME_LEN 64
#define MAX_USERS 10

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int age;
    double balance;
} User;

int safe_add(int a, int b, int *result) {
    if (result == NULL) {
        return -1;
    }
    if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b)) {
        return -1;
    }
    *result = a + b;
    return 0;
}

void copy_name(char *dest, size_t dest_size, const char *src) {
    if (dest == NULL || src == NULL || dest_size == 0) {
        return;
    }
    strncpy(dest, src, dest_size - 1);
    dest[dest_size - 1] = '\0';
}

User *create_user(int id, const char *name, int age, double balance) {
    User *user = (User *)malloc(sizeof(User));
    if (user == NULL) {
        return NULL;
    }
    
    user->id = id;
    copy_name(user->name, MAX_NAME_LEN, name);
    user->age = age;
    user->balance = balance;
    
    return user;
}

void print_user(const User *user) {
    if (user == NULL) {
        printf("User is NULL\n");
        return;
    }
    printf("User #%d: %s, Age: %d, Balance: %.2f\n", 
           user->id, user->name, user->age, user->balance);
}

void free_user(User *user) {
    if (user != NULL) {
        free(user);
    }
}

double calculate_total_balance(User **users, int count) {
    double total = 0.0;
    int i;
    
    if (users == NULL || count <= 0) {
        return 0.0;
    }
    
    for (i = 0; i < count; i++) {
        if (users[i] != NULL) {
            total += users[i]->balance;
        }
    }
    
    return total;
}

int main(void) {
    User *users[MAX_USERS];
    int user_count = 0;
    int sum_result;
    double total;
    
    users[0] = create_user(1, "Alice", 25, 1000.50);
    users[1] = create_user(2, "Bob", 30, 2500.75);
    users[2] = create_user(3, "Charlie", 22, 750.25);
    user_count = 3;
    
    printf("User Management System\n");
    printf("----------------------\n");
    
    if (users[0] != NULL) {
        print_user(users[0]);
    }
    if (users[1] != NULL) {
        print_user(users[1]);
    }
    if (users[2] != NULL) {
        print_user(users[2]);
    }
    
    total = calculate_total_balance(users, user_count);
    printf("\nTotal Balance: %.2f\n", total);
    
    if (safe_add(100, 200, &sum_result) == 0) {
        printf("Sum: %d\n", sum_result);
    }
    
    free_user(users[0]);
    free_user(users[1]);
    free_user(users[2]);
    
    return 0;
}