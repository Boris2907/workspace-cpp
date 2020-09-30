#include <iostream>
#include "Periodic.h"
#include <bits/stdc++.h>

using namespace std;


int main(){
  extern int period;
  char mode[10000], inputString[10000];
  cin >> mode;
  while(!cin.eof()){
    cin >> inputString;
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
