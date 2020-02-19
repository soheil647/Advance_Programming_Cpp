#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string Teta (string w);

int main() {
    string Input;
    cin >> Input;
    cout << Teta(Input) << endl;
    return 0;
}

string Teta (string w)
{
    if(w.length() == 1)
        return w;
    else
    {
        string half = w.substr(0, w.length()/2);
        string otherHalf = w.substr(w.length()/2);

        reverse(half.begin(), half.end());
        reverse(otherHalf.begin(), otherHalf.end());
        return Teta(otherHalf) + Teta(half);
    }
}
