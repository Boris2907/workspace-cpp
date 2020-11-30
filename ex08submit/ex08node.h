#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

namespace ds_course{
    class Node  
    {  
    public: 
        char key[31];  
        Node *left;  
        Node *right;  
        int height;
        int badness;  
    };    
}

void printInorder(ds_course::Node* node);
int str_length(char* mystring);

// Compare
int comparePlusType(char* type, char *word, char*nodeWord);

// Insert
int compareByCharSmall(char a, char b);
int compareByCharBig(char a, char b);
int lexCompare(char* a, char* b);
int shortlexCompare(char* a, char* b);
int colexCompare(char* a, char* b);
int max(int a, int b);  
int height(ds_course::Node *N);  
ds_course::Node* newNode(char * value);  
ds_course::Node *rightRotate(ds_course::Node *y);  
ds_course::Node *leftRotate(ds_course::Node *x);  
int getBalance(ds_course::Node *N);  
ds_course::Node* insert(ds_course::Node* node, char * key, char* type);  
// Delete
ds_course::Node * minValueNode(ds_course::Node* node);  
ds_course::Node* deleteNode(ds_course::Node* root, char * key, char* type);

// G
void wordToGet(ds_course::Node* node, char * word, ds_course::Node* root);
bool isInTree(ds_course::Node *root, char * word);

// L
bool hasPath(ds_course::Node *root, char *location, char * key);
void printPath(ds_course::Node *root, char * key);

// D
void printAll(ds_course::Node *root, char* begin, char* end, char* type);


