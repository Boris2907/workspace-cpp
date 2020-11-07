#include "AlienNode.h"
#include <iostream>
#include <sstream>

using namespace ds_course;
using namespace std;

int current_height;
int indexCounter;

int myPow (int x, int p) {
  int i = 1;
  for (int j = 1; j <= p; j++)  i *= x;
  return i;
}

int makeArray(Node* root, int height, int arrayWithZeroes[]) {
    if (root == NULL) {
        if ( height >= current_height) {
           arrayWithZeroes[indexCounter] = 0;
           indexCounter++;
        }
        current_height--;
        return 0;
    } 
    else {
        current_height++;
        makeArray(root->left, height, arrayWithZeroes);
        arrayWithZeroes[indexCounter] = root->value;
        indexCounter++;
        current_height++;
        makeArray(root->right, height, arrayWithZeroes);
        current_height--;
        return 0;
    }
}


int main () {
    int height = 0;

    struct Node* root = new Node(0);

    string input;
    int parent, val;
    char type;

    while (getline(cin, input)) {
		istringstream stringstream(input);
		stringstream >> type;

		if (type == 'T') {
            stringstream >> val;
            root->value = val;
            
		}
		else if (type == 'L' || type == 'R') {
			stringstream >> parent >> val;
            int mb = root->insertNode(root,parent,val,type);
            if (mb > height) root->height = mb;
		}
        else if (type == '?') {
            current_height = 1;
            indexCounter = 0;
            stringstream >> val;
            int arrayWithZeroes[myPow(2,root->height) - 1];
            makeArray(root, root->height, arrayWithZeroes);
            for (int i = 0; i < myPow(2,root->height) - 1; i++) {
                // cout << arrayWithZeroes[i] << " ";
                if (arrayWithZeroes[i] == val) {
                    cout << arrayWithZeroes[i-1] << " " << arrayWithZeroes[i+1] << endl;
                    break;
                }
            }
        }
        else if (type == 'F') {
            // exit probably?
        }
        else {
            cout << "Bedi s bashkoi" << endl;
            return -1;
        }
    }
    return 0;
}