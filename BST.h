#ifndef BST_H
#define BST_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct sNode {
    int data;
    int height;
    struct sNode* parent;
    struct sNode* left;
    struct sNode* right;
} Node;

void inOrder(Node*);
void postOrder(Node*);
void preOrder(Node*);
void erase(Node*, int);
Node* insert(Node*, int);
Node* findParent(Node*, int);
Node* search(Node*, int);
Node* createTree(Node*, const int, const int);
void updateHeight(Node*);

#endif