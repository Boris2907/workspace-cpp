#include <iostream>
#include "Ratio.h"
#include "Matrix.h"
#include <string.h>
#include <cstring>
using namespace ds_course;
using namespace std;

int main() {
    string type1, type2, operation;
    int row1, col1, row2, col2;
    
    cin >> type1 >> row1 >> col1;
    cin.ignore();
    
    if (type1.compare("MQ") == 0) {
        Matrix<Ratio> m1(row1,col1);
        cin >> m1;
        cin >> type2 >> row2 >> col2;
        
        Matrix<Ratio> m2 (row2,col2);
        cin >> m2;

        cin >> operation;
        
        if (operation.compare("ADD") == 0) {
            if (row1 != row2) {
                cout << "out_of_range" << endl;   
            }    
            if (col1 != col2) {
                cout << "out_of_range" << endl;
            }
            m1 + m2;
        } 
        else if (operation.compare("SUB") == 0) {
            if (row1 != row2) {
                cout << "out_of_range" << endl;
            }
            if (col1 != col2) {
                cout << "out_of_range" << endl;
            }
            m1 - m2;
        }
        else if (operation.compare("MUL") == 0) {
            if ( col1 != row2) {
                cout << "out_of_range" << endl;
            }  
            m1 * m2;
        }
        else {
            cout << "out_of_range" << endl;
        }
    }

    else if (type1.compare("MZ") == 0) {
        Matrix<int> m1(row1,col1);
        cin >> m1;
        cin >> type2 >> row2 >> col2;
        
        Matrix<int> m2 (row2,col2);
        cin >> m2;

        cin >> operation;
        
        if (operation.compare("ADD") == 0) {
            if (row1 != row2) {
                cout << "out_of_range" << endl;
            }    
            if (col1 != col2) {
                cout << "out_of_range" << endl;
            }
            m1 + m2;
        } 
        else if (operation.compare("SUB") == 0) {
            if (row1 != row2) {
                cout << "out_of_range" << endl;
            }
            if (col1 != col2) {
                cout << "out_of_range" << endl;
            }
            m1 - m2;
        }
        else if (operation.compare("MUL") == 0) {
            if ( col1 != row2) {
                cout << "out_of_range" << endl;
            } 
            m1 * m2;
        }
        else {
            cout << "out_of_range" << endl;
        }
    }

    else if (type1.compare("MR") == 0) {
        Matrix<double> m1(row1,col1);
        cin >> m1;
        cin >> type2 >> row2 >> col2;
            
        Matrix<double> m2 (row2,col2);
        cin >> m2;

        cin >> operation;
        
        if (operation.compare("ADD") == 0) {
            if (row1 != row2) {
                cout << "out_of_range" << endl;
            }    
            if (col1 != col2) {
                cout << "out_of_range" << endl;
            }
            m1 + m2;
        } 
        else if (operation.compare("SUB") == 0) {
            if (row1 != row2) {
                cout << "out_of_range" << endl;
            }
            if (col1 != col2) {
                cout << "out_of_range" << endl;
            }
            m1 - m2;
        }
        else if (operation.compare("MUL") == 0) {
            if ( col1 != row2) {
                cout << "out_of_range" << endl; 
            }  
            m1 * m2;
        }
        else {
            cout << "out_of_range" << endl;
        }
    }
    else {
        cout << "out_of_range" << endl;
    }
}