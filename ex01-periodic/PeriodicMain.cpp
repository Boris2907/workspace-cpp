#include <iostream>
#include "Periodic.h"

using namespace std;


int main(){
  extern int period;
  char mode[10000], inputString[10000];
  cin >> mode;
  while(true){
    cin >> inputString;
    // zeroesDeleter(inputString);
    if (isPeriodic(inputString)) {
        cout  << inputString  << " " << period << endl;
      }    
      else { 
        cout << inputString  << " 0" << endl; 
      }
  }
}