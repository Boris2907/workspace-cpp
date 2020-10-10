#include <iostream>
#include <string>
#include "CircleList.h"
#include <sstream>
#include <exception>

using namespace std;
using namespace ds_course;

class OutOfBoundsException {
private:
	string printedMsg;
public:
	OutOfBoundsException(const string& msg);
	~OutOfBoundsException();
	string getMessage() const;
};

OutOfBoundsException::OutOfBoundsException(const string& msg) {
	printedMsg = msg;
	cerr << "OutOfBoundsException: " << printedMsg << endl;
}

OutOfBoundsException::~OutOfBoundsException() { 
	delete this; 
}

string OutOfBoundsException::getMessage() const {
	return printedMsg;
}


void ins(CircleList listt, int position, int value) {
	int size = listt.getSize();
	int times = 0;
	int times1 = 0;
	int left = 0;
	
	if (position <= size) {
		while (times != position) {
			listt.advance();
			times++;
		}
		listt.add(value);
		left = size - position +1;
		while (times1 != left) {
			listt.advance();
			times1++;
		}
	}
	else 
		throw OutOfBoundsException("Invalid position");
	

}

void del(CircleList listt, int position) {
	int size = listt.getSize();
	int times = 0;
	int times1 = 0;
	int left = 0;

	if (position <= size) {
		while (times != position) {
			listt.advance();
			times++;
		}
		listt.remove();
		left = size - position + 1;
		while (times1 != left) {
			listt.advance();
			times1++;
		}
	}
	else 
		throw OutOfBoundsException("Invalid position");
	
}


int main() {
	CircleList listt;
	
	int sizeOfArray, a;
	string operation;
	cin >> sizeOfArray; // number of elements 
	for (int i = 0; i < sizeOfArray; ++i) {
		cin >> a;
		/*cout << a << " cin " << endl;*/
		listt.add(a); // adding to circular list
		listt.advance();
	}
	int value, position;
	string input;


	while (getline(cin, input)) {
		istringstream stringstream(input);
		stringstream >> operation;
		if (operation.compare("INS") == 0) {
			stringstream >> position >> value;
			ins(listt, position, value);
			cout << "i inserted something!!";
		}
		else if (operation.compare("DEL") == 0) {
			stringstream  >> value;
			del(listt, value);
			cout << "i deleted something!!";
		}
	}

	cout << listt.to_str() << endl;

	return 0;
}

