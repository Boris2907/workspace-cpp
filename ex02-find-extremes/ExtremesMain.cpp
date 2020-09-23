#include <iostream>
#include <iomanip>
#include "Student.h"

using namespace std;
using namespace ds_course;

Student getMin(Student* ss, int count) {
    int min = 0;
    for (int i = 1; i != count; i++) {   
        if (ss[i].compareTo(ss[min]) == -1) {
            min = i;
        }
    }
    Student minS = ss[min];
    return minS;
}

Student getMax(Student* ss, int count) {
    int max = 0;
    for (int i = 1; i != count; i++) {
        if (ss[i].compareTo(ss[max]) == 1) {
            max = i;
        }
    }
    Student maxS = ss[max];
    return maxS;
}

int main() {
    int N, age, i;
    double height;
    i = 0;

    cin >> N;
    Student stu[10000];

    while ( i != N) {       
        cin >> age >> height;
        stu[i].age = age;
        stu[i].height = height;
        i++;
    }
    
    Student minimal{ getMin(stu, N) };
    cout << minimal.age << " " << std::fixed << std::setprecision(5) << minimal.height << endl;

    Student maximal{ getMax(stu, N) };
    cout << maximal.age << " " << std::fixed << std::setprecision(5) << maximal.height << endl;

    return 0;
}