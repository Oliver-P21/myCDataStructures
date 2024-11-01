#ifndef BST_H
#define BST_H
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

void inOrder(Node*);
void postOrder(Node*);
void preOrder(Node*);
void erase(Node*, int);
Node* insert(Node*, int);
Node* insertNode(Node*, Node*);
Node* findRoot(Node*);
Node* search(Node*, int);
Node* createTree(const size_t, const int);
void updateHeight(Node*);
Node* findSuccessor(Node*);

#endif