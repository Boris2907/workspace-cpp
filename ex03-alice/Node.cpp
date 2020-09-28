#include "Node.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace ds_course;
using namespace std;

Node::Node(int vv) {
	this-> val = vv;
	children;

}

int Node::getVal() {
	return  val;
}

void Node::reflect() {
	reverse(children.begin(), children.end());
	for (auto& x : children)
		x.reflect();
}

void Node::addChild(Node child) {
	children.push_back(child);
}

void Node::printPreorder() {
	cout << getVal() << " ";
	for (auto& x : children)
		cout << x.getVal() << ' ';
	cout << endl;
}
