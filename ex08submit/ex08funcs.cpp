#include <iostream>
#include <sstream>
#include <string.h>
#include "ex08node.h"

using namespace std;
using namespace ds_course;

extern int lineCounter;
int heightOfTree = 1, check = 0;

int str_length(char* mystring) {
	int i = 0;
	while (mystring[i] != '\0') {
		i++;
	}
	return i;
}

int compareByCharSmall(char a, char b) {
    bool aUpper = false;
    bool bUpper = false;
    if((int)a < 91&&(int)a > 64){
        aUpper = true;
        a = a + 32;
    }
    if((int)b < 91 && (int)b > 64) {
        bUpper = true;
        b = b + 32;
    }
    if(a<b) {
        return -1;
    }
    if(a>b) {
        return 1;
    }
    else {
        return 0;
    }
}
int compareByCharBig(char a, char b){
    bool aUpper = false;
    bool bUpper = false;
    if((int)a < 91 && (int)a > 64){
        aUpper = true;
        a = a + 32;
    }
    if ((int)b < 91 && (int)b > 64){
        bUpper = true;
        b = b + 32;
    }
    if (aUpper==true&&bUpper==false){
        return -1;
    }
    if (aUpper==false&&bUpper==true) {
        return 1;
    }
    else {
        return 0;
    }
}

int lexCompare(char* a, char* b) {
    int minLen = 0;
    if(str_length(a) < str_length(b) || str_length(a) == str_length(b)){
        minLen = str_length(a);
    }
    else{
        minLen = str_length(b);
    }
        int i = 0;
        while(i < minLen){
            int result = compareByCharSmall(a[i],b[i]);
            if (result == -1){
                return -1;
            }
            if (result == 1){
                return 1;
            }
            if (i == minLen -1 && result == 0){
                if(str_length(a) < str_length(b)){
                    return -1;
                }
                if(str_length(a) > str_length(b)){
                    return 1;
                }
                int j = 0;
                while(j < minLen){
                    int final = compareByCharBig(a[j], b[j]);
                    if(final == -1){
                        return -1;
                    }
                    if (final == 1){
                        return 1;
                    }
                    if(j == minLen-1 && final == 0){
                        return 0;
                    }
                    j++;    
                }
            }
            i++;
        }
    return 500;
}

int shortlexCompare(char* a, char* b) {

    if(str_length(a) < str_length(b)) {
        return -1;
    }
    if (str_length(b) < str_length(a)) {
        return 1;
    }
    else{
        return lexCompare(a,b);
    }
}
int colexCompare(char* a, char* b) {
    char reverseA[str_length(a)+1];
    char reverseB[str_length(b)+1];
    int j =0;
    for(int i = str_length(a)-1; i >= 0; i--){
        reverseA[j] = a[i];
        j++;
    }
    j = 0;
    for(int i =str_length(b)-1; i >= 0; i--){
        reverseB[j] = b[i];
        j++;
    }
    reverseB[str_length(b)] = '\0';
    reverseA[str_length(a)] = '\0';

    return lexCompare(reverseA, reverseB);
}

int height(ds_course::Node *N) {  
    if (N == NULL)  
        return 0;  
    return N->height;  
}  

int max(int a, int b) {  
    return (a > b)? a : b;  
}  
  
ds_course::Node* newNode(char * value)  
{  
    ds_course::Node* node = new ds_course::Node(); 
    int i;
    for ( i = 0; i < str_length(value); i++) {
        node->key[i] = value[i];
    }
    node->key[i+1] = '\0';
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1;
    node->badness = 1;
    return(node);  
}  
  
ds_course::Node *rightRotate(ds_course::Node *y) {  
    ds_course::Node *x = y->left;  
    ds_course::Node *T2 = x->right;  
   
    x->right = y;  
    y->left = T2;  
  
    y->height = max(height(y->left), height(y->right)) + 1;  
    x->height = max(height(x->left), height(x->right)) + 1;  

    return x;  
}  

ds_course::Node *leftRotate(ds_course::Node *x)  {  
    ds_course::Node *y = x->right;  
    ds_course::Node *T2 = y->left;  
  
    y->left = x;  
    x->right = T2;  
  
    x->height = max(height(x->left), height(x->right)) + 1;  
    y->height = max(height(y->left), height(y->right)) + 1;  
  
    return y;  
}  
  
int getBalance(ds_course::Node *N)  {  
    if (N == NULL)  
        return 0;  
    return height(N->left) - height(N->right);  
}  
  
ds_course::Node* insert(ds_course::Node* node, char * key, char* type)  {  
    if (node == NULL)  {
        return(newNode(key)); 
    }
         
    if (comparePlusType(type, key, node->key) == -1)   { 
        node->left = insert(node->left, key, type); 
    }

    else if (comparePlusType(type, key, node->key) == 1) {
        node->right = insert(node->right, key, type);  
    }

    else if (comparePlusType(type, key, node->key) == 500) {
        cout << "Somehing went wrong!";
    }

    else  if (comparePlusType(type, key, node->key) == 0) {
        node->badness++;
    }
     
    node->height = 1 + max(height(node->left), height(node->right));  

    int balance = getBalance(node);  

    // Left Left Case  
    if (balance > 1 && comparePlusType(type, key, node->left->key) == -1)  
        return rightRotate(node);  
  
    // Right Right Case  
    if (balance < -1 && comparePlusType(type, key, node->right->key) == 1)  
        return leftRotate(node);  
  
    // Left Right Case  
    if (balance > 1 && comparePlusType(type, key, node->left->key) == 1) {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && comparePlusType(type, key, node->right->key) == -1) {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    return node;  
}  

ds_course::Node * minValueNode(ds_course::Node* node)  {  
    ds_course::Node* current = node;  

    while (current->left != NULL)  
        current = current->left;  
    return current;  
}  

void printInorder(ds_course::Node* node) { 
    if (node == NULL) 
    return; 
    for (int i = 0 ; i < str_length(node->key); i++)
        cout << node->key[i];
    cout << endl;
    printInorder(node->left); 
    printInorder(node->right);  
}

ds_course::Node* deleteNode(ds_course::Node* root, char * key, char* type) {  
    if (root == NULL)  
        return root;  

    if ( comparePlusType(type, key, root->key) == -1 ) 
        root->left = deleteNode(root->left, key, type);  
  
    else if( comparePlusType(type, key, root->key) == 1)  
        root->right = deleteNode(root->right, key, type);  

    else {  
        // node with only one child or no child  
        if((root->left == NULL) || (root->right == NULL)) {  
            ds_course::Node *temp = root->left ? root->left : root->right;  
            // No child case  
            if (temp == NULL)  {  
                temp = root;  
                root = NULL;  
            }  
            else // One child case  
            *root = *temp;
            free(temp);  
        }  
        else{  
            // node with two children: successor
            ds_course::Node* temp = minValueNode(root->right);  
            int i;
            for ( i = 0; i < str_length(temp->key); i++) {
                root->key[i] = temp->key[i];  
            }
            root->key[i] = '\0';    
            root->badness = temp->badness;
            root->height = temp->height;

            root->right = deleteNode(root->right, temp->key, type);  
        }  
    }  
  
    if (root == NULL)  
    return root;  
  
    root->height = 1 + max(height(root->left), height(root->right));  
  
    int balance = getBalance(root);  
  
    // Left Left Case  
    if (balance > 1 && getBalance(root->left) >= 0)  
        return rightRotate(root);  
  
    // Left Right Case  
    if (balance > 1 && getBalance(root->left) < 0) {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 && getBalance(root->right) <= 0)  
        return leftRotate(root);  
  
    // Right Left Case  
    if (balance < -1 && getBalance(root->right) > 0) {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  

    return root;  
}  
  
void wordToGet(ds_course::Node* node, char * word, ds_course::Node* root) {
    if (node == NULL) 
        return; 
    
    if (strcmp(word, node->key) == 0) {
        cout << lineCounter << " (";
        for (int i = 0 ; i < str_length(node->key); i++)
            cout << node->key[i];
        cout << "," << node->badness << ")" << endl;
    }
    
    wordToGet(node->left, word, root);     
    wordToGet(node->right, word, root);  

    if (!isInTree(root, word) && check == 0) {
        cout << lineCounter << " (";
        for (int i = 0 ; i < str_length(word); i++)
            cout << word[i];
        cout << "," << 0 << ")" << endl;
        check++;
    }
    return;
}

bool hasPath(Node *root, char *location, char * word) { 
    if (!root) 
        return false; 
    
    if (strcmp(word, root->key) == 0)   
        return true; 
      
    if (hasPath(root->left, location, word)) {
        location[heightOfTree] = 'L';
        heightOfTree++;
        return true; 
    }

    else if (hasPath(root->right, location, word))  {
        location[heightOfTree] = 'R';
        heightOfTree++;
        return true; 
    }
    
    return false;             
} 
  
void printPath(Node *root, char* word) { 
    char arr[16];
    arr[0] = '*';

    cout << lineCounter;
    if (hasPath(root, arr, word)) {
        cout << " *";
        for (int g = heightOfTree-1; g != 0 ; g--)     
            cout << arr[g];
        cout << endl;
    } 
    else
        cout << " N" << endl;
} 

bool isInTree(ds_course::Node *root, char * word) {
    if (!root) 
        return false; 

    if (strcmp(word, root->key) == 0)   
        return true; 

    if (isInTree(root->left, word) || isInTree(root->right, word)) {
        return true; 
    }
      
    return false;     
}

void printAll(ds_course::Node *node, char* begin, char* end, char* type) {
    if (node == NULL) 
        return; 

    printAll(node->left, begin, end, type);    
    if (strcmp(begin, "_") == 0 && (strcmp(end, "_") == 0)) {
        cout << " (";
        for (int i = 0 ; i < str_length(node->key); i++)
            cout << node->key[i];
        cout << "," << node->badness << ")" ;
    } 

    else if (strcmp(begin,"_") == 0) {
        if (comparePlusType(type, end, node->key) == 1) {
            cout << " (";
            for (int i = 0 ; i < str_length(node->key); i++)
                cout << node->key[i];
            cout << "," << node->badness << ")";
        }
    }

    else if (strcmp(end,"_") == 0) {
        if (comparePlusType(type, begin, node->key) == -1) {
            cout << " (";
            for (int i = 0 ; i < str_length(node->key); i++)
                cout << node->key[i];
            cout << "," << node->badness << ")";
        }
    }

    else {
        if (comparePlusType(type, end, node->key) == 1 && comparePlusType(type, begin, node->key) == -1) {
            cout << " (";
            for (int i = 0 ; i < str_length(node->key); i++)
                cout << node->key[i];
            cout << "," << node->badness << ")";
        }
    }
    
    printAll(node->right,  begin, end, type);  
    return;
}

int comparePlusType(char* type, char *word, char*nodeWord) {
    if (strcmp(type, "LEX") == 0) 
        return lexCompare(word, nodeWord);
    
    else if (strcmp(type, "SHORTLEX") == 0) 
        return shortlexCompare(word, nodeWord);
    
    else if (strcmp(type, "COLEX") == 0) 
        return colexCompare(word, nodeWord);

    return -500;
}