#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include "Periodic.h"

using namespace std; 

int period = 0;

void findPeriodic( char word[], int wordLength, int prefix[]) { 
    int i = 1, c=0, d=0, f=0, length=0, truecounter=0;; 
    int zeroes = 0;
    string newArray = "";
    prefix[0] = 0; 

    while ( f < wordLength) {
      if (word[f]=='0') {
        zeroes++;
        f++;
      } 
      else {
        break;
      }
    }

    while (c < wordLength) {
      if (isdigit(word[c])) {
        truecounter++;
        break;
      }
      c++;
    }

    if (truecounter > 0) {
      while (d < wordLength) {
        if (isupper(word[d])) {
          word[d]=tolower(word[d]);
        }
        d++;
      }
      truecounter=0;
    }

    
    while (i < wordLength) { 
       if (word[i] == word[length]) { 
           length++; 
           prefix[i] = length; 
           i++;   
       } 
       else { 
          if (length != 0) { 
             length = prefix[length-1]; 
          } 
          else { 
             prefix[i] = 0; 
             i++; 
          } 
       } 
    } 
  period = i - length;
} 
  
bool isPeriodic(char str[]) { 
    int prefix[strlen(str)]; 

    findPeriodic(str, strlen(str), prefix); 
    int length = prefix[strlen(str)-1]; 

    if (strlen(str)%(strlen(str)-length) == 0 && length > 0) {
      return true;
    }
    else {
      return false;
    }
}

string zeroesDeleter(char input[]) {
int i = 0;
 std::vector<char> testVector;

 while ( i < strlen(input)) {
   testVector.push_back(input[i]);
   i++;
   
 }

//  for (int j = 0 ; j < testVector.size(); j++) {
//   cout << testVector[i];
//  }


  while(testVector[0] == '0'){
    testVector.erase(testVector.begin());
  }

	// for (auto x: testVector) {
	// 	cout << x << endl;;
	// }
std::reverse(testVector.begin(), testVector.end());

while(testVector[0] == '0'){
    testVector.erase(testVector.begin());
  }

std::reverse(testVector.begin(), testVector.end());

std::string s(testVector.begin(),testVector.end());
return s;
// char p[10000]; 
//   int i; 
//   for (i = 0; i < sizeof(p); i++) { 
//       p[i] = s[i]; 
//   }
//   i++;
//   p[i] = '\0';
//   cout << p << " right here";
//   return p;
}
