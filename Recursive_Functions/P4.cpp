#include <iostream>
#include <string>

using namespace std;

string Find_Password(int n, string Char_Set, char New_Char, int indx, long int Hash_Code, string Answer, int number);


int main(){
    int Legnth_Password = 4;
    string Chars = "abcdefghijklmnopqrstuvwxyz";
    long int Code = 3042236360593357275;
//    cin >> Legnth_Password;
//    cin >> Chars;
//    cin >> Code;
    cout << Find_Password(Legnth_Password, Chars,Chars[0], 0, Code, "", 0);
}

string Find_Password(int n, string Char_Set, char New_Char, int indx, long int Hash_Code, string Answer, int number)
{
    hash<string> myhash;
    long int Code = 0;
    Answer += New_Char;
    cout << Answer << endl;
    for(int j = 0; j < n; j++) {
        for (int i = 0; i < Char_Set.length() && indx != n - 1; i++) {
            Answer = Find_Password(n, Char_Set, Char_Set[number], ++indx, Hash_Code, Answer, ++number);
        }
    }

    Code = myhash(Answer);
    if(Code == Hash_Code)
        return Answer;
    else
        return "Not_Found";
}