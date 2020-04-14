# include <iostream>
# include <string>
# include <vector>
# include <numeric>
# include <algorithm>
# include <fstream>

using namespace std;

#ifndef ENCRYPTION_AND_DECRYPTION_ENCRYPTION_DECRYPTION_H
#define ENCRYPTION_AND_DECRYPTION_ENCRYPTION_DECRYPTION_H

#endif //ENCRYPTION_AND_DECRYPTION_ENCRYPTION_DECRYPTION_H

// Simple Encryption Part Functions
vector<int> convert_string_to_ascii(const string& input_string);
string Repeat_Key(string s, int n);
vector<int> SumASCIIValues(vector<int> Val1, vector<int> Val2);
vector<int> Simple_Encryption(const string& Password, const string& GivenLine);

// Simple Decryption Part Functions
string Simple_Decryption(const string& Password, const vector<int>& GivenAscii);
string ConvertASCIIToString(const vector<int>& ASCII);
vector<int> MinesASCIIValues(vector<int> Val1, vector<int> Val2);

// Complex Encryption Part Functions
vector <int> CreateRandomFromPasswordSeed(const string& Password, int n);
vector<int> Complex_Encryption(const string& Password, const string& GivenLine);

// Complex Decryption Part Function
string Complex_Decryption(const string& Password, const vector<int>& GivenAscii);

//Other Functions
void Do_Action(const string& InputPath, const string& OutputPath, const string& Action, const string& Key, const string& Kind);
void Get_InputFile(string& InputPath, string& OutputPath, string& Action, string& Key, string& Kind);

