#include <iostream>
#include "Periodic.h"
#include <sstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;


int main(){
  extern int period;
  std::string inputLine;
  char mode[10000], inputString[10000];
  cin >> mode;

  cin.ignore(10000, '\n');
  while(getline(cin, inputLine)){
    istringstream sstr(inputLine);
    if (sstr.peek() == '#') {
      continue;
    } else {
    sstr >> inputString;
    string someStr = zeroesDeleter(inputString);
    int n = someStr.length();
    char char_array[n+1];
    strcpy(char_array, someStr.c_str());

    if (isPeriodic(char_array)) {
        cout  << char_array  << " " << period << endl;
      }    
      else { 
        cout << char_array  << " 0" << endl; 
      }

    }
  }
}
