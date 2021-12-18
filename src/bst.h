#ifndef BST_H
#define BST_H

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
        int query(int);
};

#endif
