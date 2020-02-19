#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int multiply(int *a,int n, int indx);

int main() {
    int s[] = {1,2,3,4};
    multiply(s,sizeof(s)/sizeof(int),0);
    for(int i:s)
        cout << i << " " ;
    return 0;
}

int multiply(int *a,int n, int indx) {
    if(indx > n)
        return 1;

    a[indx] *= multiply(a,n,indx+1);
    return a[indx];
}