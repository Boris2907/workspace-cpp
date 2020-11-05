#include "AlienNode.h"
#include <vector>
#include <iostream>

using namespace ds_course;
using namespace std;

// Node::Node(int value) { 
//     this->value = value; 
//     left = right = NULL; 
// }

// void Node::printInorder(Node* node) { 
//     if (node == NULL) 
//         return; 
  
//     printInorder(node->left); 
  
//     cout << node->value << " "; 
  
//     printInorder(node->right);  
// }

// void Node::insertNode(Node* node, int parent, int val, char side) {
//     if (node == NULL) 
//         return; 
        
//     if (node->value == parent)  {
//         if (side == 'L') {
//             node->left = new Node(val);
//             return;
            
//         }
//         else if (side == 'R') {
//             node->right = new Node(val);
//             return;
            
//         }
//         else {
//             cout << "WTF R U DOING DUDE?" << endl;
//             return;
//         }
//     }

//     insertNode(node->left, parent, val, side); 
  
//     insertNode(node->right, parent, val, side);  
// }


// int Node::getVal() {
// 	return  val;
// }

// void Node::reflect() {
// 	reverse(children.begin(), children.end());
// 	for (auto& x : children)
// 		x.reflect();
// }

// void Node::addChild(Node child) {
// 	children.push_back(child);
// }

// void Node::printPreorder() {
// 	cout << getVal() << " ";
// 	for (auto& x : children)
// 		cout << x.getVal() << ' ';
// 	cout << endl;
// }