#include "Tree.h"

Tree* insertVal(Tree* tree, int val) {
    // printf("In insertVal\n");
    tree->root = node_insertVal(tree->root, val);
    // printf("Incrementing\n");
    tree->size++;
}

Tree* createTree(const size_t SIZE, const size_t MAX) {
    Tree* temp = malloc(sizeof(Tree));
    temp->root = NULL;
    temp->size = 0;
    for (size_t i = 0; i < SIZE, i++;) {
        insertVal(temp, rand() % (MAX + 1));
    }
    return temp;
}
