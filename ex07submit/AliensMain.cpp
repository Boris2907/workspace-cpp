#include "AlienNode.h"
#include <iostream>
#include <sstream>

using namespace ds_course;
using namespace std;

int tree_height(Node* root) {
    // Get the height of the tree
    if (!root)
        return 0;
    else {
        // Find the height of both subtrees
        // and use the larger one
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);

        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
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
            if (mb > height) height = mb;
		}
        else if (type == '?') {
            // DFStoArray(root);
            // height = tree_height(root);
            cout <<"height is " << height << endl;

            // сделать аррей с нулями
            // запринтить боковые
        }
        else if (type == 'F') {
            return 0;
        }
        else {
            cout << "Bedi s bashkoi" << endl;
            return -1;
        }
    }
    
//         else if (type == '?') {
// 			stringstream >> val;
//             if (nodeList[val].val) {
//                 if (nodeList[val].childCount == 0) {
//                     cout << 0 << " " << nodeList[val].parent << endl;
//                 }   
//                 else if (nodeList[val].childCount == 2) {
//                     cout << nodeList[val].left << " " << nodeList[val].right << endl;
//                 }
//                 else if (nodeList[val].childCount == 1) {
//                     if (nodeList[val].left) {
//                         cout << nodeList[val].left << " " << nodeList[val].parent << endl;
//                     }
//                     else if (nodeList[val].right) {
//                         cout << nodeList[val].right << " " << nodeList[val].parent << endl;
//                     }
//                 } 
//             }
// 		}
//         else if (type == 'F') {
//             return 0;
//         }
// 	}    
    root->printInorder(root);
    return 0;
}
    
    

    // {
    //     while (getline(cin, line))
    //     {
    //         if (line[0] == '0')
    //         {
    //             break;
    //         }
    //         vector<int> numberList;
    //         istringstream treeline(line);
    //         int currentNode;
    //         while (treeline >> currentNode) 
    //         {
    //             numberList.push_back(currentNode);
    //         }
    //         Node myNode(numberList[0]);
    //         for (int i = 1; i < numberList.size(); i++) 
    //         {
    //             myNode.addChild(numberList[i]);
                
    //         }
    //         nodeList.push_back(myNode);
    //     }
    
    /*else 
    {
        cout << "Unable to open the file! The input file name should be 'in.txt'! ";
        return 0;
    }*/

    // for (int i = 0; i < nodeList.size(); i++)
    // {
    //     nodeList[i].reflect();
    //     if (findHeadNode(nodeList[i].getVal(), nodeList) == 1) 
    //         finalNodeList.push_back(nodeList[i]);
    // }

    // for (int i = 0; i < finalNodeList[0].children.size(); i++)
    //     subTrees(finalNodeList[0].children[i].getVal(), nodeList);
    
    // for (int i = 0; i < finalNodeList.size(); i++) 
    //     finalNodeList[i].printPreorder();

    // cout << '0';
   
