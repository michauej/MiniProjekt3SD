#include "AvlTree.h"
#include <iostream>
#include <algorithm>
using namespace std;

Node::Node( int v) :  value(v), height(1), left(nullptr), right(nullptr) {}

AvlTree::AvlTree() : root(nullptr) {}
AvlTree::~AvlTree() {}

int AvlTree::getHeight(Node* node) {
    return node ? node->height : 0;
}

void AvlTree::updateHeight(Node* node) {
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

int AvlTree::getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

Node* AvlTree::rotateLeft(Node* node) {
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

Node* AvlTree::rotateRight(Node* node) {
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

Node* AvlTree::balance(Node* node) {
    updateHeight(node);
    int balanceFactor = getBalance(node);

    if (balanceFactor > 1) {
        if (getBalance(node->left) < 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balanceFactor < -1) {
        if (getBalance(node->right) > 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

Node* AvlTree::insert(Node* node, int value) {
    if (!node)
        return new Node(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right,  value);
    else {
        node->value = value;
        return node;
    }

    return balance(node);
}

Node* AvlTree::getMinValueNode(Node* node) {
    while (node->left)
        node = node->left;
    return node;
}

Node* AvlTree::remove(Node* node, int key) {
    if (!node)
        return nullptr;

    if (key < node->value)
        node->left = remove(node->left, key);
    else if (key > node->value)
        node->right = remove(node->right, key);
    else {
        if (!node->left || !node->right) {
            Node* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        }
        else {
            Node* temp = getMinValueNode(node->right);
            node->value = temp->value;
            node->value = temp->value;
            node->right = remove(node->right, temp->value);
        }
    }

    return balance(node);
}

void AvlTree::inOrder(Node* node) {
    if (!node) return;
    inOrder(node->left);
    cout << node->value << " ";
    inOrder(node->right);
}

void AvlTree::insert(int value) {
    root = insert(root, value);
}

void AvlTree::remove(int key) {
    root = remove(root, key);
}

void AvlTree::inOrder() {
    inOrder(root);
    cout << endl;
}
