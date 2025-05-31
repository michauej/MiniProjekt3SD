#pragma once

struct Node {
    int value;
    int height;
    Node* left;
    Node* right;

    Node( int v);
};

class AvlTree {
private:
    Node* root;

    int getHeight(Node* node);
    void updateHeight(Node* node);
    int getBalance(Node* node);

    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);

    Node* insert(Node* node,  int value);
    Node* remove(Node* node, int value);
    Node* getMinValueNode(Node* node);

    Node* balance(Node* node);

    void inOrder(Node* node);

public:
    AvlTree();
    ~AvlTree();

    void insert(int value);
    void remove(int value);
    void inOrder();
};
