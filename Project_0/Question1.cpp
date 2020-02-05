#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
        vector<int> Teacher_Numbers;
        vector<int> Written_Numbers;
        
	int Temp_Number;

        while(cin >> Temp_Number){
		bool ForTeacher = false;
		for(int i = 0; i < Teacher_Numbers.size(); i++){
			if(Temp_Number == Teacher_Numbers[i]){
				ForTeacher = true;
			}
		}
		if(ForTeacher){
                	Written_Numbers.push_back(Temp_Number);
		}
		else{
			Teacher_Numbers.push_back(Temp_Number);
		}
        }
	
	bool Found_Written_Number;
	bool Found_Teacher_Number;
	bool Not_True = true;

	for(int i = 0; i < Written_Numbers.size(); i++){
		Found_Written_Number = false;
		for(int j = 0; j < Teacher_Numbers.size(); j++){
			if(Written_Numbers[i] == Teacher_Numbers[j]){
				Found_Written_Number = true;
			}
		}
		if(Found_Written_Number == false){
			cout << Written_Numbers[i] << endl;
			Not_True = false;
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
			Not_True = false;
		}
	}

	if(Not_True) {
		cout << "0" << endl;
	}
        return 0;
}

