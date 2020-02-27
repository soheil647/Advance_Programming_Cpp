#include <iostream>
#include <string>

using namespace std;

// For Finding Password Recursively
string Find_Password(string Char_Set, int Password_Length, unsigned long int Password_Hash, string Password);

int main() {
    int Password_Length;
    string Char_Set;
    unsigned long int Password_Hash;
    // Get Input: Length of password, Chars that can be in password and Hash of password
    cin >> Password_Length >> Char_Set >> Password_Hash;
    // Recursively find what is the Password
    cout << Find_Password(Char_Set, Password_Length, Password_Hash, "") << endl;
    return 0;
}

string Find_Password(string Char_Set, int Password_Length, unsigned long int Password_Hash, string Password) {
    hash<string> HashOfPassword;
    // To check if founded password is the real key
    if (Password.length() == Password_Length) {
        if (HashOfPassword(Password) == Password_Hash) {
            return Password;
        } else {
            return "Not_Found";
        }
    }
    // To add each character from Char_set to password and check if we got the real one
    for (int i = 0; i < Char_Set.length(); i++) {
        // Add a new Char from Charset until checking all of the possible Passwords
        string new_pass = Find_Password(Char_Set, Password_Length, Password_Hash, Password + Char_Set[i]);
        // If it Finds the Password Return it
        if (new_pass != "Not_Found")
            return new_pass;
    }
    return "Not_Found";
}
