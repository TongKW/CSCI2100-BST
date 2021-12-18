#ifndef BST_H
#define BST_H
#include <iostream>
#include "merge_sort.h"

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    Node(int key)
    {
        key = key;
        left = NULL;
        right = NULL;
    }
};
typedef struct Node Node;

class BST
{
    private:
        Node *root;
        void BST_fill(Node*, int, int, int*);
    public:
        int predecessor_query(int);
        BST(int *arr, int length);
};

#endif
