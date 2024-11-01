#include "Node.h"

typedef struct Tree {
    Node* root;
    size_t size;
} Tree;

Tree* insertVal(Tree*, int);
Tree* createTree(const size_t, const size_t);