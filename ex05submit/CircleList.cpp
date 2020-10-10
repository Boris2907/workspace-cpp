#include <iostream>
#include "CircleList.h"
#include <string>

using namespace std;
using namespace ds_course;


CircleList::CircleList() // constructor
	: cursor(NULL) {
	size = 0; 
}

CircleList::~CircleList() { // destructor 
	while (!empty()) remove();
}

void CircleList::add(const Elem& e) { // add after cursor
	CNode* v = new CNode;  // create a new node
	v -> elem = e;

	if (cursor == NULL) { // list is empty?
		v -> next = v; // v points to itself
		cursor = v; // cursor points to v
	}

	else { // list is nonempty?
		v -> next = cursor -> next; // link in v after cursor
		cursor -> next = v;
	}
	size++;
}

void CircleList::remove() { // remove node after cursor
	CNode* old = cursor -> next; // the node being removed
	if (old == cursor) // removing the only node?
		cursor = NULL; // list is now empty
	else
		cursor -> next = old -> next; // link out the old node
	delete old; // delete the old node
	size--;
}

bool CircleList::empty() const { // is list empty?
	return cursor == NULL;
}

const Elem& CircleList::back() const { // element at cursor
	return cursor -> elem;
}

const Elem& CircleList::front()  const { // element following cursor
	return cursor -> next -> elem;
}

void CircleList::advance() { // advance cursor
	cursor = cursor -> next;
}

int CircleList::getSize() {
	return size;
}

string CircleList::to_str()  {
	string finalList;
	for (int i = 0; i < size; ++i) {
		advance();
		finalList.append(to_string(back()));
		if (i != size) {
			finalList.append(" ");
		}
	}
	return finalList;
}




