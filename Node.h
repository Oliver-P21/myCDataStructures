#ifndef NODE_H
#define NODE_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int height;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
} Node;

void node_inOrder(Node*);
void node_postOrder(Node*);
void node_preOrder(Node*);
void node_erase(Node*, int);
Node* node_insertVal(Node*, int);
Node* node_findRoot(Node*);
Node* node_search(Node*, int);
Node* node_createTree(const size_t, const int);
void node_updateHeight(Node*);
Node* node_findSuccessor(Node*);

#endif