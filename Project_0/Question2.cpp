#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int M,N;
	int Temp_Product;

	cin >> M >> N ;

	int Products[M][N] = {};
	int Sum_Total = 0;

	for(int i = 0; i < M ; i++){
		for(int j = 0; j < N ; j++){
			cin >> Temp_Product;
		        Products[i][j] = Temp_Product;	
		}
	}
	
	for(int k = 0; k < 4; k++){
		int Max_Row = 0;
	        int Max_Column = 0;
	        int Max_Row_Index = 0;
	        int Max_Column_Index = 0;
		
		int Sum_Rows[M] = {};
		int Sum_Columns[N] = {};
		
		for(int i = 0; i < M; i++){
			for(int j =0; j < N; j++){
				Sum_Rows[i] = Products[i][j] + Sum_Rows[i];
			}
		}
	
		for(int j = 0; j < N; j++){
			for(int i = 0; i < M; i++){
				Sum_Columns[j] = Products[i][j] + Sum_Columns[j];
			}
		}	
		
		Max_Row = *max_element(Sum_Rows,Sum_Rows + M);
		Max_Column = *max_element(Sum_Columns,Sum_Columns + N);
		Max_Row_Index = distance(Sum_Rows,max_element(Sum_Rows,Sum_Rows + M));
		Max_Column_Index = distance(Sum_Columns,max_element(Sum_Columns,Sum_Columns + N));

		if(Max_Row >= Max_Column){
			Sum_Total = Max_Row + Sum_Total;
			for(int j = 0; j < N; j++){
				Products[Max_Row_Index][j] = 0;
			}
		}
		else{
			Sum_Total = Max_Column + Sum_Total;
			for(int i = 0; i < M; i++){
				Products[i][Max_Column_Index] = 0;
			}
		}
	}

	cout << Sum_Total << endl;
	return 0;
		
}
