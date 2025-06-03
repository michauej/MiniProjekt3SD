#pragma once

struct Node {
    int key;
    int value;
    int height;
    Node* left;
    Node* right;

    Node(int k, int v);
};

class AvlTree {
private:
    Node* root;

    int getHeight(Node* node);
    void updateHeight(Node* node);
    int getBalance(Node* node);

    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);

    Node* insert(Node* node, int key, int value);
    Node* remove(Node* node, int key);
    Node* getMinValueNode(Node* node);

    Node* balance(Node* node);

    void inOrder(Node* node);

public:
    AvlTree();
    ~AvlTree();

    void insert(int key, int value);
    void remove(int key);
    void inOrder();
};