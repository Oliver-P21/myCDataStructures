#include "Tree.h"

Tree* insertVal(Tree* tree, int val) {
    // printf("In insertVal\n");
    tree->root = node_insertVal(tree->root, val);
    // printf("Incrementing\n");
    tree->size++;
}
