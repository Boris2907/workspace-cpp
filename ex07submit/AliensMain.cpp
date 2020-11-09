#include "AlienNode.h"
#include <iostream>
#include <sstream>

using namespace ds_course;
using namespace std;

//test 2 segfault, test 3 segfault, test 4 segfault, test 5 segfault, 
int indexCounter;

int makeArray(Node* root, int* arrayWithZeroes) {
    if (root == NULL) {
        return 0;
    } 
    else {
        makeArray(root->left, arrayWithZeroes);
        arrayWithZeroes[indexCounter] = root->value;
        indexCounter++;
        makeArray(root->right, arrayWithZeroes);
        return 0;
    }
}

void printInorder(Node* node) { 
            if (node == NULL) 
            return; 
            printInorder(node->left); 
            cout << node->value << " "; 
            printInorder(node->right);  
        }

int main () {
    struct Node* megaRoot[11000];
    string input;
    int parent, val;
    char type;
    while (getline(cin, input)) {
		istringstream stringstream(input);
		stringstream >> type;
		if (type == 'T') {
            stringstream >> val;
            if (megaRoot[val] != 0) {
                cout << "error6" << endl;
                continue;
            }
            megaRoot[val] = new Node(val, NULL);
		}

		else if (type == 'L' || type == 'R') {
			stringstream >> parent >> val;
            if (parent == val) {
                cout << "error1" << endl;
                continue;
            }
            if (megaRoot[parent] == 0) {
                cout << "error2" << endl;
                continue;
            }
            if (megaRoot[val] != 0) {
                cout << "error3 " << endl;
                continue;
            }
            if (megaRoot[parent]->left != NULL && type == 'L') {
                cout << "error4" << endl;
                continue;
            }
            if (megaRoot[parent]->right != NULL && type == 'R') {
                cout << "error5" << endl;
                continue;
            }
            megaRoot[val] = new Node(val, megaRoot[parent]);
            megaRoot[parent]->insertNode(megaRoot[val], type);
        }

        else if (type == '?') {   
            stringstream >> val;
            if (megaRoot[val] == 0) {
                cout << "error0" << endl;
                continue;
            }
            Node* callNode = new Node(-1   , NULL);
            callNode = megaRoot[val];
            for (int i = 0; i < 10001; i++) {
                if (callNode->parent == NULL) {
                    break;
                }
                callNode = callNode->parent;
            }
            indexCounter = 0;
            int finalArray[10000];
            // printInorder(callNode);
            // cout << val << endl;
            makeArray(callNode, finalArray);
            for (int i = 0; i < indexCounter; i++) {
                // cout << finalArray[i] << " ";
                if (finalArray[i] == val) {
                    if (i == 0) {
                        cout << 0 << " " << finalArray[i+1] << endl;
                    }
                    else if ( i == indexCounter) {
                        cout << finalArray[i-1] << " " << 0 << endl;
                    }
                    else {
                        cout << finalArray[i-1] << " " << finalArray[i+1] << endl;
                    }
                    break;
                }
            }
        }
        
        else if (type == 'F') {
            return 0;
        }
        else {
            cout << "Wrong input!";
            return -1;
        }
    }
    return 0;
}