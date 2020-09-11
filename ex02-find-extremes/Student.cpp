#include <iostream>
#include "Student.h"

using namespace ds_course;
using namespace std;

Student::Student() {
    int age;
    double height;
}




int Student::compareTo(Student ss) {
    if (ss.age == age && ss.height == height) {
        return 0;
    }
    else if (age < ss.age ) {
        return -1;
    }
    else if (age > ss.age) {
        return 1;
    }
    else if (age == ss.age && height < ss.height) {
        return -1;
    }
    else {
        return 1;
    }
}