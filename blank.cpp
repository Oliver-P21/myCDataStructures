#include <stdio.h>
#include <stdlib.h>
void print(char* s) {
    printf("@@@%s@@@@\n", s);
}

int main() {
    char* bad_string;
    print(bad_string);
    return 0;
}
