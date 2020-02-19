# include <iostream>
# include <string>
# include <vector>
# include <numeric>
# include <algorithm>
# include <fstream>

using namespace std;

// Simple Encryption Part Functions
vector<int> convertStringToASCII (const string& s);
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

int main(){
    string Action, Kind, Key, InputPath, OutputPath;
    Get_InputFile(InputPath, OutputPath, Action, Key, Kind);
    Do_Action(InputPath, OutputPath, Action,  Key, Kind);
    return 0;
}

vector<int> convertStringToASCII (const string& s)
{
    vector <int> vals;
    int ascChar;
    for (char i : s)
    {
        ascChar = i;
        vals.push_back(ascChar);
    }
    return vals;
}

string Repeat_Key(string s, int n)
{
    string s1 = s;
    for (int i = 1; i < n; i++)
        s += s1;
    return s;
}

vector<int> SumASCIIValues(vector<int> Val1, vector<int> Val2)
{
    vector<int> SumOfPassAndInput;
    for ( int i = 0; i < Val1.size(); i++)
    {
        int Sum = Val1[i] + Val2[i];
        SumOfPassAndInput.push_back(Sum);
    }
    return SumOfPassAndInput;
}

vector<int> MinesASCIIValues(vector<int> Val1, vector<int> Val2)
{
    vector<int> MinesOfPassAndInput;
    for ( int i = 0; i < Val1.size(); i++)
    {
        int Mines = Val1[i] - Val2[i];
        MinesOfPassAndInput.push_back(Mines);
    }
    return MinesOfPassAndInput;
}

vector <int> CreateRandomFromPasswordSeed(const string& Password, int n)
{
    vector <int> AsciiPassword;
    vector <int> RandomVector;

    AsciiPassword = convertStringToASCII(Password);
    srand(accumulate(AsciiPassword.begin(),AsciiPassword.end(),0));
    RandomVector.reserve(n);
    for (int i = 0; i < n; i++)
        RandomVector.push_back(rand() % 11);

    return RandomVector;
}

string ConvertASCIIToString(const vector<int>& ASCII)
{
    string MyWord;
    for (auto i : ASCII) {
        MyWord += static_cast<char>(i);
    }
    return MyWord;
}


vector<int> Simple_Encryption(const string& Password, const string& GivenLine)
{
    vector<int> ASCIIValueOfInput;
    vector<int> ASCIIValueOfPassword;
    vector<int> ASCIIValueOfSum;

    string ConcatPassword;

    ASCIIValueOfInput = convertStringToASCII(GivenLine);
    ConcatPassword = Repeat_Key(Password, GivenLine.size());
    ASCIIValueOfPassword = convertStringToASCII(ConcatPassword);
    ASCIIValueOfSum = SumASCIIValues(ASCIIValueOfInput, ASCIIValueOfPassword);

    return ASCIIValueOfSum;
}

vector<int> Complex_Encryption(const string& Password, const string& GivenLine)
{
    vector<int> ASCIIValueOfInput;
    vector<int> ASCIIValueOfPassword;
    vector<int> ASCIIValueOfSum;

    string ConcatPassword;

    ASCIIValueOfInput = convertStringToASCII(GivenLine);
    ASCIIValueOfPassword = CreateRandomFromPasswordSeed(Password, GivenLine.size());
    ASCIIValueOfSum = SumASCIIValues(ASCIIValueOfInput, ASCIIValueOfPassword);

    return ASCIIValueOfSum;
}

string Simple_Decryption(const string& Password, const vector<int>& GivenAscii)
{
    vector<int> ASCIIValueOfPassword;
    vector<int> ASCIIValueOfMines;

    string ConcatPassword;
    string Output;

    ConcatPassword = Repeat_Key(Password, GivenAscii.size());
    ASCIIValueOfPassword = convertStringToASCII(ConcatPassword);
    ASCIIValueOfMines = MinesASCIIValues(GivenAscii, ASCIIValueOfPassword);
    Output = ConvertASCIIToString(ASCIIValueOfMines);

    return Output;
}

string Complex_Decryption(const string& Password, const vector<int>& GivenAscii)
{
    vector<int> ASCIIValueOfPassword;
    vector<int> ASCIIValueOfMines;

    string ConcatPassword;
    string Output;

    ASCIIValueOfPassword = CreateRandomFromPasswordSeed(Password, GivenAscii.size());
    ASCIIValueOfMines = MinesASCIIValues(GivenAscii, ASCIIValueOfPassword);
    Output = ConvertASCIIToString(ASCIIValueOfMines);

    return Output;

}

void Do_Action(const string& InputPath, const string& OutputPath, const string& Action, const string& Key, const string& Kind){
    vector<int> ASCIICode;
    string StringCode;
    string line;

    ifstream InputFile(InputPath);
    if(InputFile.fail()){
        cerr << "Error Opening the file" << endl;
        InputFile.close();
        exit(1);
    }

    ofstream OutFile;
    OutFile.open(OutputPath);
    if(OutFile.fail()){
        cerr << "Error Opening the file" << endl;
        OutFile.close();
        exit(1);
    }
    if(Action == "encrypt"){
        getline(InputFile, line);
        if(Kind == "simple")
            ASCIICode = Simple_Encryption(Key, line);
        else if(Kind == "complex")
            ASCIICode = Complex_Encryption(Key, line);

        for(int i : ASCIICode)
            OutFile << i << endl;
    }
    else if(Action == "decrypt"){
        while (getline(InputFile, line))
        {
            if(Action == "decrypt")
                ASCIICode.push_back(stoi(line));
        }
        if(Kind == "simple")
            StringCode = Simple_Decryption(Key, ASCIICode);
        else if(Kind == "complex")
            StringCode = Complex_Decryption(Key, ASCIICode);

        OutFile << StringCode;
    }
    InputFile.close();
    OutFile.close();
}

void Get_InputFile(string& InputPath, string& OutputPath, string& Action, string& Key, string& Kind) {
    string line;
    int i = 0;
    while (cin >> line) {
        if (i == 0)
            Action = line;
        if (i == 1)
            Kind = line;
        if (i == 2)
            Key = line;
        if (i == 3)
            InputPath = line;
        if (i == 4)
            OutputPath = line;
        i++;
    }
}
