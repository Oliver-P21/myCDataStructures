#include "BST.h"

void inOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    inOrder(node->left);
    printf("%d, ", node->data);
    inOrder(node->right);
}

void preOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d, ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

void postOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    printf("%d, ", node->data);
}

Node* insert(Node* node, int data) {
    if (node == NULL) {
        Node* ptr = (Node*)malloc(sizeof(Node));
        ptr->data = data;
        ptr->parent = NULL;
        ptr->left = NULL;
        ptr->right = NULL;
        return ptr;
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
        node->left->parent = node;
        node->left->height = node->height - 1;
        if (node->left->height == -1) {  // this condition should only be true once at most per insert
            Node* treeRoot = findRoot(node);
            updateHeight(treeRoot);
        }
    }

    if (data > node->data) {
        node->right = insert(node->right, data);
        node->right->parent = node;
        node->right->height = node->height - 1;
        if (node->right->height == -1) {
            Node* treeRoot = findRoot(node);
            updateHeight(treeRoot);
        }
    }

    // tree does not have duplicate values
    return node;
}
void updateHeight(Node* node) {
    if (node == NULL) {
        return;
    }
    updateHeight(node->left);
    updateHeight(node->right);
    int leftHeight = node->left != NULL ? node->left->height : -1;
    int rightHeight = node->right != NULL ? node->right->height : -1;
    node->height = leftHeight > rightHeight ? (leftHeight + 1) : (rightHeight + 1);
}

Node* findRoot(Node* node) {
    Node* temp = node;  // needed for heights
    while (temp->parent != NULL) {
        temp = temp->parent;
    }
    return temp;
}

void erase(Node* node, int data) {
    Node* target = search(node, data);
    if (target == NULL) {
        return;
    }

    Node* parent = target->parent;
}

Node* findParent(Node* node, int target) {
    if (node == NULL) {
        return NULL;
    }

    if (target < node->data) {
        if (node->left != NULL) {
            if (node->left->data == target) {
                return node;
            }
            return findParent(node->left, target);
        }
        return NULL;
    }
    // may be able to refactor
    if (node->right != NULL) {
        if (node->right->data == target) {
            return node;
        }
        return findParent(node->right, target);
    }
    return NULL;
}

Node* search(Node* node, int target) {
    if (node == NULL) {
        return NULL;
    }
    if (node->data == target) {
        return node;
    }
    if (target < node->data) {
        return search(node->left, target);
    }
    return search(node->right, target);
}

Node* createTree(Node* node, const size_t SIZE, const int MAX) {
    Node* temp = NULL;
    for (size_t i = 0; i < SIZE; i++) {
        temp = insert(temp, rand() % (MAX + 1));
    }
    return temp;
}