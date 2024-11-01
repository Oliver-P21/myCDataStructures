#ifndef ASSERTIONS_H
#define ASSERTIONS_H
#include <stdbool.h>
#include <stdio.h>
void assertTrue(bool);
void assertFalse(bool);
void assertNull(void*);

void assertNull(void* ptr) {
    if (ptr == NULL) {
        printf("Success!\n");
    } else {
        printf("Failure...\n");
    }
}

void assertNotNull(void* ptr) {
    if (ptr != NULL) {
        printf("Success!\n");
    } else {
        printf("Failure...\n");
    }
}
void assertTrue(bool condition) {
    if (condition) {
        printf("Success!\n");
    } else {
        printf("Failure...\n");
    }
}
void assertFalse(bool condition) {
    if (!condition) {
        printf("Success!\n");
    } else {
        printf("Failure...\n");
    }
}

#endif