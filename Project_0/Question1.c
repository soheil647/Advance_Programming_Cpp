#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
        vector<int> Teacher_Numbers;
        vector<int> Written_Numbers;
        cout << "What are the Teachers Numbers? Type 0 then enter to end it " << endl;
        int Temp_Teacher_Number;
	int Temp_Number;
	bool Get_Number = true;
        while(Get_Number){
		cin >> Temp_Teacher_Number;
		if(Temp_Teacher_Number == 0 ){
			Get_Number = false;
		}
		else{
                	Teacher_Numbers.push_back(Temp_Teacher_Number);
		}
        }
	
	Get_Number = true;
        cout << "What are the Written Numbers? Type 0 then enter to end it" << endl;
        while(Get_Number){
		cin >> Temp_Number;
		if(Temp_Number == 0){
			Get_Number = false;
		}
		else{
                	Written_Numbers.push_back(Temp_Number);
		}
        }
	
	bool Found_Written_Number;
	bool Found_Teacher_Number;
	for(int i = 0; i < Written_Numbers.size(); i++){
		Found_Written_Number = false;
		for(int j = 0; j < Teacher_Numbers.size(); j++){
			if(Written_Numbers[i] == Teacher_Numbers[j]){
				Found_Written_Number = true;
			}
		}
		if(Found_Written_Number == false){
			cout << Written_Numbers[i] << endl;
		}
	}

	for(int j = 0; j < Teacher_Numbers.size(); j++){
		Found_Teacher_Number = false;
		for(int i = 0; i < Written_Numbers.size(); i++){
			if(Teacher_Numbers[j] == Written_Numbers[i]){
				Found_Teacher_Number = true;
			}
		}
		if(Found_Teacher_Number == false){
			cout << Teacher_Numbers[j] << endl;
		}
	}
        return 0;
}

