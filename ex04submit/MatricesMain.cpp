#include <iostream>
#include "Ratio.h"
#include "Matrix.h"
#include <string.h>

using namespace ds_course;
using namespace std;

int main() {
    // rational arithmetic 
    // It is not quite right: fractions not simplified

    string type1, type2, operation;
    int row1, col1, row2, col2;


    /*Ratio r1(2, 3);
    Ratio r2(2, 4);
    cout << (r1 * r2) << endl;*/

    //read from input
    cin >> type1 >> row1 >> col1;
    cin.ignore();
    Matrix<Ratio> m1(row1, col1);
    cin >> m1;

    cin >> type2 >> row2 >> col2;
    cin.ignore();
    Matrix<Ratio> m2(row2, col2);
    cin >> m2;

    cin >> operation;

    cout << "THE ROW and COLUMN ARE: " << row1 << " " << col1 << " " << type1 << " " << operation << endl;
    cout << "(m1 == m2) is " << ((m1 == m2) ? "true" : "false") << endl;
    cout << "m2.a[1][1] = " << m2.a[1][1] << endl;
}