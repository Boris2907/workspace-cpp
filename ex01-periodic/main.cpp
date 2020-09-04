#include<iostream> 
#include<cstring> 
#include<vector>

using namespace std; 

int period = 0;

void findPeriodic(char word[], int wordLength, int prefix[]) { 
    int length = 0; 
    int i = 1; 
    int zeroes = 0;
    int c=0;
    int d=0;
    prefix[0] = 0; 

    while (int f=0 < wordLength) {
      if (word[f]==0) {
        zeroes++;
        f++;
      }
      else {
        break;
      }
    }

    int truecounter=0;

    while (c < wordLength) {
      if (isdigit(word[c])) {
        truecounter++;
        break;
      }
      c++;
      
    }

    if (truecounter>0) {
      while (d < wordLength) {
        if (isupper(word[d])) {
          word[d]=tolower(word[d]);
        }
        d++;
      }
      truecounter=0;
    }


    //char *word2 = new char[wordLength-zeroes];
   // for (int k=0; k < wordLength;k++) word[k]=k+1;
    //for (int k=0; k<wordLength;k++) word2[k]=word[k+1];
    
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
  
int main() { 
  char list[][100] = {"ABCABC","ABCD", "ABABA", "017017", "20192019", "0012e12E", "12F12"};
   int n = sizeof(list)/sizeof(list[0]); 

   for (int i=0; i<n; i++) {
      if (isPeriodic(list[i])==true) {
        cout  << list[i]  << " " << period << "\n";
      }   
      else { 
        cout << list[i]  << " 0" << "\n" ; 
      }
   }

   return 0; 
} 