#include <iostream>

using namespace std; 

namespace ds_course {
    struct Node { 
        int height = 0;
        int value; 
        struct Node *left, *right; 
        // Node(int value);
        // void printInorder(Node* node);
        // void insertNode(Node* node, int parent, int val, char side);
        Node(int value) { 
            this->value = value; 
            left = right = NULL; 
        }

        void printInorder(Node* node) { 
            if (node == NULL) 
            return; 
            printInorder(node->left); 
            cout << node->value << " "; 
            printInorder(node->right);  
        }

        int insertNode(Node* node, int parent, int val, char side) {
            if (node == NULL) 
                return 0; 
            if (node->value == parent)  {
                if (side == 'L') {
                    node->left = new Node(val);
                }
                else if (side == 'R') {
                    node->right = new Node(val);
                }
                else {
                    cout << "WTF R U DOING DUDE?" << endl;
                    return 0;
                }
            }
            int left_height = insertNode(node->left, parent, val, side); 
            int right_height = insertNode(node->right, parent, val, side);  

            if (left_height >= right_height)
                return left_height + 1;
            else
                return right_height + 1;
        }
    }; 
}