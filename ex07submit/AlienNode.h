#include <iostream>

extern int indexCounter;

namespace ds_course {
    struct Node { 
        
        int value; 
        struct Node *left, *right; 
        struct Node *parent;
        // Node(int value, Node* parent);
        // void insertNode(Node* node, char side);
        // int makeArray(Node* root, int* arrayWithZeroes);
        Node(int value, Node* parent) { 
            this->value = value; 
            this->left = this->right = NULL; 
            this->parent = parent;
        }

        void insertNode(Node* node, char side) {
            if (side == 'L') {
                this->left = node;
            }   

            else if (side == 'R') {
                 this->right = node;
            } 
        }

        // int makeArray(Node* root, int* arrayWithZeroes) {
        //     if (root == NULL) {
        //         return 0;
        //     } 
        //     else {
        //         makeArray(root->left, arrayWithZeroes);
        //         arrayWithZeroes[indexCounter] = root->value;
        //         indexCounter++;
        //         makeArray(root->right, arrayWithZeroes);
        //         return 0;
        //     }
        // }
    }; 
}