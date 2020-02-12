#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
#define MIN(x,y) ((x) < (y) ? (x) : (y)) //calculate minimum between two values
int main() {
   int a,b;
   cin >> a;
   char s1[a];
   cin >> s1;
   cin >> b;
   char s2[b];
   cin>> s2;
   //stores the lenght of strings s1 and s2
   int common = 0;
   for (int i = 0 ; i < min(a,b) ; i++) {
	if (s1[i] != s2[i]){
	    common = i;
	    break;
	}
   }
   cout<< 2*(max(a,b) - common);
   return 0;
}
