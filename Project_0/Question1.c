#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
        vector<int> Teacher_Numbers;
        vector<int> Written_Numbers;
        cout << "What are the Teachers Numbers?" << endl;
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
        cout << "Teachers Said Numbers Are:" << endl;
        for(int i = 0; i < Teacher_Numbers.size(); i++){
                cout << Teacher_Numbers[i] << " ";
        }
        cout << endl;
	
	Get_Number = true;
        cout << "What are the Written Numbers?" << endl;
        while(Get_Number){
		cin >> Temp_Number;
		if(Temp_Number == 0){
			Get_Number = false;
		}
		else{
                	Written_Numbers.push_back(Temp_Number);
		}
        }
        cout << "Student Written Numbers Are:" << endl;
        for(int i = 0; i < Written_Numbers.size(); i++){
                cout << Written_Numbers[i] << " ";
        }
        cout << endl;
	
	sort(Teacher_Numbers.begin(), Teacher_Numbers.end());
	sort(Written_Numbers.begin(), Written_Numbers.end());

	for(int i = 0; i < Written_Numbers.size(); i++){
		if(Written_Numbers[i] == Teacher_Numbers[i]){
			cout << "Correct ";
		}
		else{
			cout << Written_Numbers[i];
		}
	}
        return 0;
}

