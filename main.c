#include <time.h>

#include "BST.h"
#include "assert.h"
#include "assertions.h"
#define null NULL

int main() {
    srand(time(0));

    Node* tree = null;
    tree = createTree(1000, 10000);
    inOrder(tree);
    printf("\n");
    return 0;
}