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
Node* insertNode(Node* root, Node* newNode) {
    if (root == NULL) {
        return newNode;
    }

    if (newNode->data < root->data) {
        root->left = insert(root->left, newNode);
        root->left->parent = root;
        root->left->height = root->height - 1;
        if (root->left->height == -1) {  // this condition should only be true once at most per insert
            Node* treeRoot = findRoot(root);
            updateHeight(treeRoot);
        }
    }

    if (newNode->data > root->data) {
        root->right = insert(root->right, newNode);
        root->right->parent = root;
        root->right->height = root->height - 1;
        if (root->right->height == -1) {
            Node* treeRoot = findRoot(root);
            updateHeight(treeRoot);
        }
    }

    // tree does not have duplicate values
    return root;
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
    Node* temp = node;  // needed to find the heights
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

Node* createTree(const size_t SIZE, const int MAX) {
    Node* temp = NULL;
    for (size_t i = 0; i < SIZE; i++) {
        temp = insert(temp, rand() % (MAX + 1));
    }
    return temp;
}