#include <time.h>

#include "Tree.h"
#include "assert.h"
#include "assertions.h"
#define null NULL

int main() {
    srand(time(0));

    Tree* tree = createTree(25, 100);
    node_inOrder(tree->root);
    return 0;
}