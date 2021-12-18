// This file implements a static version of Binary Search Tree (BST) in class
#include "merge_sort.h"
#include <iostream>

#define INT_MIN -2147483648

using namespace std;

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

// Static BST that takes 
class BST
{
    private:
        Node *root;
        void BST_fill(Node*, int, int, int*);
    public:
        int predecessor_query(int);
    // Take an array of integers and length as input
    BST(int *arr, int length)
    {
        // make a copy of the input array
        int arr_copy[length];
        for (int i = 0; i < length; i++)
        {
            arr_copy[i] = arr[i];
        }
        // sort the copy array
        merge_sort(arr_copy, 0, length);
        root = new Node(0);
        // fill the BST with values in arr_copy
        BST_fill(root, 0, length, arr_copy);
    }

    // helper function that only used once in initialization
    void BST_fill(Node *current, int start, int end, int *arr)
    {
        if (start > end) return;
        int middle_index = (start + end) / 2;
        int middle_key = arr[middle_index];
        current -> key = middle_key;
        BST_fill(current -> left, start, middle_index - 1, arr);
        BST_fill(current -> right, middle_index + 1, end, arr);
    }

    // return the predecessor of the target
    int predecessor_query(int target)
    {
        Node *iter = root;
        int predecessor = INT_MIN;
        while (iter)
        {
            if (iter -> key == target) return target;
            if (iter -> key < target)
            {
                if (iter -> key > predecessor) predecessor = iter -> key;
                iter = iter -> right;
                continue;
            }
            if (iter -> key > target) iter = iter -> left;
        }
        return predecessor;
    }
    
};