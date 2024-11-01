#include "Node.h"

void node_inOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    node_inOrder(node->left);
    printf("%d, ", node->data);
    node_inOrder(node->right);
}

void node_preOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d, ", node->data);
    node_preOrder(node->left);
    node_preOrder(node->right);
}

void node_postOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    node_postOrder(node->left);
    node_postOrder(node->right);
    printf("%d, ", node->data);
}

Node* node_insertVal(Node* node, int data) {
    if (node == NULL) {
        Node* ptr = (Node*)malloc(sizeof(Node));
        ptr->data = data;
        ptr->parent = NULL;
        ptr->left = NULL;
        ptr->right = NULL;
        return ptr;
    }

    if (data < node->data) {
        node->left = node_insertVal(node->left, data);
        node->left->parent = node;
        node->left->height = node->height - 1;
        if (node->left->height == -1) {  // this condition should only be true once at most per insert
            Node* treeRoot = node_findRoot(node);
            node_updateHeight(treeRoot);
        }
    }

    if (data > node->data) {
        node->right = node_insertVal(node->right, data);
        node->right->parent = node;
        node->right->height = node->height - 1;
        if (node->right->height == -1) {
            Node* treeRoot = node_findRoot(node);
            node_updateHeight(treeRoot);
        }
    }

    // tree does not have duplicate values
    return node;
}

void node_updateHeight(Node* node) {
    if (node == NULL) {
        return;
    }
    node_updateHeight(node->left);
    node_updateHeight(node->right);
    int leftHeight = node->left != NULL ? node->left->height : -1;
    int rightHeight = node->right != NULL ? node->right->height : -1;
    node->height = leftHeight > rightHeight ? (leftHeight + 1) : (rightHeight + 1);
}

Node* node_findRoot(Node* node) {
    Node* temp = node;  // needed to update the heights
    while (temp->parent != NULL) {
        temp = temp->parent;
    }
    return temp;
}

// Ignores case where removing the root, refactor later, handle case in typdef Tree
void node_erase(Node* node, int data) {
    Node* target = node_search(node, data);
    if (target == NULL) {
        return;
    }

    if (node_findRoot(target)->data == data) {
        return;
    }

    Node* parent = target->parent;                        // never null
    if (target->left == NULL && target->right == NULL) {  // leaf node
        if (parent->left == target) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }

    } else if (target->right == NULL) {
        if (parent->left == target) {
            parent->left = target->left;
        } else {
            parent->right = target->left;
        }
        target->left->parent = parent;

    } else if (target->left == NULL) {
        if (parent->left == target) {
            parent->left = target->right;
        } else {
            parent->right = target->right;
        }
        target->right->parent = parent;
    } else {
    }
}

Node* node_findSuccessor(Node* root) {
    if (root == NULL) {
        return NULL;
    }
}

Node* node_search(Node* node, int target) {
    if (node == NULL) {
        return NULL;
    }
    if (node->data == target) {
        return node;
    }
    if (target < node->data) {
        return node_search(node->left, target);
    }
    return node_search(node->right, target);
}

Node* node_createTree(const size_t SIZE, const int MAX) {
    Node* temp = NULL;
    for (size_t i = 0; i < SIZE; i++) {
        temp = node_insertVal(temp, rand() % (MAX + 1));
    }
    return temp;
}