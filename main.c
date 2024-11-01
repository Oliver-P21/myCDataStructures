#include <time.h>

#include "Tree.h"
#include "assert.h"
#include "assertions.h"
#define null NULL

int main() {
    srand(time(0));

    Tree* tree;
    tree->root == null;
    printf("Inserting now\n");
    insertVal(tree, 5);
    printf("Done with insert\n");
    node_inOrder(tree->root);
    printf("%p\n", tree->root);
    printf("Value: %d\n", tree->root->data);
    printf("Size: %d\n", tree->size);

    printf("\n");
    return 0;
}