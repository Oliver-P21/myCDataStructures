#include <time.h>

#include "BST.h"
#include "assert.h"
#include "assertions.h"
#define null NULL

int main() {
    srand(time(0));

    Node* tree = null;
    tree = insert(tree, 5);

    return 0;
}