# include "Encryption_And_Decryption_Lib/Simple_EncryptionAndDecryption.cpp"

int main(){
    string Action, Kind, Key, InputPath, OutputPath;
    Get_InputFile(InputPath, OutputPath, Action, Key, Kind);
    Do_Action(InputPath, OutputPath, Action,  Key, Kind);
    return 0;
}