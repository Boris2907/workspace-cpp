#include "ex08node.h"
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;
using namespace ds_course;

extern int check;
extern int heightOfTree;

int lineCounter = 0;

int main () {
    int insertCounter = 0, loopCounter = 0;
    string input, type, operation, value, wordBegin, wordEnd;
    int parent, val;
    cin >> type;
    
    Node *root = NULL;  
    while (getline(cin, input)) {
		istringstream stringstream(input);
		stringstream >> operation;
        lineCounter++;
        if ( operation.compare("I") == 0) {
            while (stringstream) {
                if (loopCounter == 0) {
                    stringstream >> value;
                    loopCounter++;
                    continue;
                }
                char something[value.length() + 1];
                strcpy(something, value.c_str());
                char typeChar[type.length()+1];
                strcpy(typeChar, type.c_str());
                root = insert(root, something, typeChar);
                stringstream >> value;
            }
            loopCounter = 0;
        }
        else if (operation.compare("G") == 0) {
            check = 0;
            stringstream >> value;
            char something[value.length() + 1];
            strcpy(something, value.c_str());
            wordToGet(root, something, root);
        }
        else if (operation.compare("D") == 0) {
            stringstream >> wordBegin >> wordEnd;
            char wordBeginChar[wordBegin.length()+1], wordEndChar[wordEnd.length()+1];
            strcpy(wordBeginChar, wordBegin.c_str());
            strcpy(wordEndChar, wordEnd.c_str());
            cout << lineCounter;
            char typeChar[type.length()+1];
            strcpy(typeChar, type.c_str());
            printAll(root, wordBeginChar, wordEndChar, typeChar);
            cout << endl;

        }
        else if (operation.compare("L") == 0) {
            stringstream >> value;
            char something[value.length() + 1];
            heightOfTree = 1;
            strcpy(something, value.c_str());
            printPath(root, something);
        }
        else if (operation.compare("E") == 0) {
            while (stringstream) {
                if (loopCounter == 0) {
                    stringstream >> value;
                    loopCounter++;
                    continue;
                }
                char something[value.length() + 1];
                strcpy(something, value.c_str());
                char typeChar[type.length()+1];
                strcpy(typeChar, type.c_str());
                root = deleteNode(root, something, typeChar);
                stringstream >> value;
            }
            loopCounter = 0;
        }
        else if (operation.compare("F") == 0) {
            return -1;
        }  
    }
}
