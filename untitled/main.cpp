
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <numeric>

using namespace std;

void Read_Input_File(string &type, string &kind, string &key, string &input_file, string &output_file);
vector<int> Convert_StringToASCII(string &input_string);
string Build_Key_String(string &key, int number_of_iter);
vector<int> Add_Key_to_Word(vector<int> Word_vector, vector<int> Key_vector);
vector<int> Subtract_Key_from_Word(vector<int> Coded_ASCII_Vector, vector<int>  Key_ASCII_Vector);
string Convert_ASCII_to_String(const vector<int>& Word_ASCII_Vector);
vector<int> Build_Random_Key_Vector(string &key, int number_of_random);
vector<int> Simple_Encrypt(string &key, string &word);
string Simple_Decrypt(string &key, const vector<int>& Coded_ASCII_Vector);
vector<int> Complex_Encrypt(string &key, string &word);
string Complex_Decrypt(string &key, const vector<int>& Coded_ASCII_Vector);
void Lets_Do_Encrypt_or_Decrypt(string &type, string &kind, string &key, string &input_file, string &output_file);






int main() {
    string type, kind, key, input_file, output_file;

    Read_Input_File(type, kind, key, input_file, output_file);
    Lets_Do_Encrypt_or_Decrypt(type, kind, key, input_file, output_file);
    return 0;
}


vector<int> Convert_StringToASCII(string &input_string)
{
    vector<int> ASCII_Code_of_String;
    int ASCII_of_Char;
    for(char & i : input_string)
    {
        ASCII_of_Char = (int) i;
        ASCII_Code_of_String.push_back(ASCII_of_Char);
    }

    return ASCII_Code_of_String;
}

string Build_Key_String(string &key, int number_of_iter)
{
    string key_string;
    for(int i=0 ; i < number_of_iter ; i++)
        key_string += key;

    return key_string;
}

vector<int> Add_Key_to_Word(vector<int> Word_vector, vector<int> Key_vector)
{
    vector<int> Key_Plus_Word_Vector;
    int Coded_ASCII_Char;

    for(int i=0 ; i < Word_vector.size() ; i++)
    {
        Coded_ASCII_Char = Word_vector[i] + Key_vector[i];
        Key_Plus_Word_Vector.push_back(Coded_ASCII_Char);
    }
    return Key_Plus_Word_Vector;
}

vector<int> Subtract_Key_from_Word(vector<int> Coded_ASCII_Vector, vector<int>  Key_ASCII_Vector)
{
    vector<int>  Word_ASCII_Vector;
    int Word_ASCII_Char;

    for(int i=0 ; i < Coded_ASCII_Vector.size() ; i++)
    {
        Word_ASCII_Char = Coded_ASCII_Vector[i] - Key_ASCII_Vector[i];
        Word_ASCII_Vector.push_back(Word_ASCII_Char);
    }
    return Word_ASCII_Vector;
}

string Convert_ASCII_to_String(const vector<int>& Word_ASCII_Vector)
{
    string Word_String;
    for(int i : Word_ASCII_Vector)
    {
        Word_String += (char) i;
    }
    return Word_String;
}

vector<int> Build_Random_Key_Vector(string &key, int number_of_random)
{
    int Random;
    int Key_Sum = 0;
    vector<int> Random_Key;
    vector<int> Key_ASCII;

    Key_ASCII = Convert_StringToASCII(key);
    Key_Sum = accumulate(Key_ASCII.begin(),Key_ASCII.end(),0);

    srand(Key_Sum);

    for(int j=0 ; j < number_of_random ; j++)
    {
        Random = rand();
        Random_Key.push_back(Random % 11);
    }

    return Random_Key;
}


//Simple Encrypt
vector<int> Simple_Encrypt(string &key, string &word)
{
    vector<int> Word_ASCII_Vector;
    vector<int>  Key_ASCII_Vector;
    vector<int> Key_Plus_Word_Vector;
    string Key_String;

    Word_ASCII_Vector = Convert_StringToASCII(word);
    Key_String = Build_Key_String(key, word.length());
    Key_ASCII_Vector = Convert_StringToASCII(Key_String);
    Key_Plus_Word_Vector = Add_Key_to_Word(Word_ASCII_Vector, Key_ASCII_Vector);

    return Key_Plus_Word_Vector;
}

//Simple Decrypt
string Simple_Decrypt(string &key, const vector<int>& Coded_ASCII_Vector)
{
    vector<int> Key_ASCII_Vector;
    vector<int> Word_ASCII_Vector;
    string key_string;
    string Word_Decoded_String;

    key_string = Build_Key_String(key, Coded_ASCII_Vector.size());
    Key_ASCII_Vector = Convert_StringToASCII(key_string);
    Word_ASCII_Vector = Subtract_Key_from_Word(Coded_ASCII_Vector ,Key_ASCII_Vector);
    Word_Decoded_String = Convert_ASCII_to_String(Word_ASCII_Vector);

    return Word_Decoded_String;
}

//Complex Encrypt
vector<int> Complex_Encrypt(string &key, string &word)
{
    vector<int> Word_ASCII_Vector;
    vector<int>  Key_ASCII_Vector;
    vector<int> Coded_Word_Vector;
    string Key_String;

    Word_ASCII_Vector = Convert_StringToASCII(word);
    Key_ASCII_Vector = Build_Random_Key_Vector(key, word.length());
    Coded_Word_Vector = Add_Key_to_Word(Word_ASCII_Vector, Key_ASCII_Vector);

    return Coded_Word_Vector;
}

//Complex Decrypt
string Complex_Decrypt(string &key, const vector<int>& Coded_ASCII_Vector)
{
    vector<int> Key_ASCII_Vector;
    vector<int> Word_ASCII_Vector;
    string key_string;
    string Word_Decoded_String;

    key_string = Build_Key_String(key, Coded_ASCII_Vector.size());
    Build_Random_Key_Vector(key, Coded_ASCII_Vector.size());
    Word_ASCII_Vector = Subtract_Key_from_Word(Coded_ASCII_Vector ,Key_ASCII_Vector);
    Word_Decoded_String = Convert_ASCII_to_String(Word_ASCII_Vector);

    return Word_Decoded_String;
}

void Lets_Do_Encrypt_or_Decrypt(string &type, string &kind, string &key, string &input_file, string &output_file)
{
    string word;
    string Code;
    string  Word_Decrypted_String;
    vector<int> Word_Encrypted_ASCII_Vector;
    vector<int> Code_ASCII_Vector;


    ifstream InputFile(input_file);
    if(InputFile.fail()){
        cout << "InputFile Does not Open" << endl;
        return;
    }

    ofstream OutputFile(output_file);
    if(OutputFile.fail()){
        cout << "OutputFile Does not Open" << endl;
        return;
    }

    if(type == "encrypt")
    {
        getline(InputFile, word);
        if(kind == "simple")
        {
            Word_Encrypted_ASCII_Vector = Simple_Encrypt(key, word);
        }

        else if(kind == "complex")
        {
            Word_Encrypted_ASCII_Vector = Complex_Encrypt(key, word);
        }
        for(int i : Word_Encrypted_ASCII_Vector)
        {
            OutputFile << i << endl;
        }

    }
    else if(type == "decrypt")
    {
        while (getline(InputFile, Code))
        {
            Code_ASCII_Vector.push_back(stoi(Code));
        }

        if(kind == "simple")
        {
            Word_Decrypted_String = Simple_Decrypt(key, Code_ASCII_Vector);
        }
        else if(kind == "complex")
        {
            Word_Decrypted_String = Complex_Decrypt(key, Code_ASCII_Vector);
        }
        OutputFile << Word_Decrypted_String;
    }
    InputFile.close();
    OutputFile.close();
}

void Read_Input_File(string &type, string &kind, string &key, string &input_file, string &output_file) {
    string instructions;
    int i=0;

    while(cin >> instructions)
    {
        if (i == 0)
            type = instructions;
        if (i == 1)
            kind = instructions;
        if (i == 2)
            key = instructions;
        if (i == 3)
            input_file = instructions;
        if (i == 4)
            output_file = instructions;

        i++;
    }
}

