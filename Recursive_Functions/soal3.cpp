#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

vector<string> Allowed_Moves(int Goldmine[3][3], int Rows, int Columns, int current_row, int current_column);
int BFS_GoldMine(int sum_max, int Goldmine[3][3], int Rows, int Columns, int current_row, int current_column);

int main()
{
    int number;
    int Columns=3,Rows=3;
    int sum_max = 0;
    int Goldmine[3][3];
    Goldmine[0][0] = 0;
    Goldmine[1][0] = 6;
    Goldmine[2][0] = 0;
    Goldmine[0][1] = 5;
    Goldmine[1][1] = 8;
    Goldmine[2][1] = 7;
    Goldmine[0][2] = 0;
    Goldmine[1][2] = 9;
    Goldmine[2][2] = 0;

//    cout << "Enter Columns: ";
//    cin >> Columns;
//    cout << "Enter Rows: ";
//    cin >> Rows;
//
//    int **network = (int **)malloc(Columns * sizeof(int *));
//    for (int i=0; i < Columns; i++)
//        network[i] = (int *)malloc(Rows * sizeof(int));
//
//
//    for(int i=0 ; i < Columns ; i++)
//    {
//        for(int j=0 ; j < Rows ; j++)
//        {
//            cin >> number;
//            network[i][j] = number;
//        }
//    }
    cout << BFS_GoldMine(sum_max, Goldmine, Rows, Columns, 0, 0) << endl;
    return 0;
}

int BFS_GoldMine(int sum_max, int Goldmine[3][3], int Rows, int Columns, int current_row, int current_column, vector<int> Pass_Column, vector<int> Pass_Row){
    vector<string> Moves;
    Moves = Allowed_Moves(Goldmine, Rows, Columns, current_row, current_column);
    for(string i: Moves)
        cout << i;
    cout << endl;
    if(Goldmine[current_column][current_row] != 0) {
        if (!Moves.empty()) {
            for (const string &i: Moves) {
                if (i == "up" && ) {
                    current_column--;
                }
                if (i == "down") {
                    current_column++;
                }
                if (i == "right") {
                    current_row++;
                }
                if (i == "left") {
                    current_row--;
                }
                Pass_Column.push_back(current_column);
                Pass_Row.push_back(current_row);
                sum_max += BFS_GoldMine(sum_max, Goldmine, Rows, Columns, current_row, current_column, Pass_Column, Pass_Row);
            }
        }
    }
    else {
        current_row++;
        sum_max += BFS_GoldMine(sum_max, Goldmine, Rows, Columns, current_row, current_column);
    }
    return sum_max;
}

vector<string> Allowed_Moves(int Goldmine[3][3], int Rows, int Columns, int current_row, int current_column){

    vector<string> allow_moves;
    if(Goldmine[current_column + 1][current_row] != 0 && current_column + 1 <= Columns && current_column >= 0)
        allow_moves.push_back("down");
    if(Goldmine[current_column - 1][current_row] != 0 && current_column - 1 <= Columns && current_column >= 0)
        allow_moves.push_back("up");
    if(Goldmine[current_column][current_row + 1] != 0 && current_row + 1 <= Rows && current_row + 1 >= 0)
        allow_moves.push_back("right");
    if(Goldmine[current_column][current_row - 1] != 0 && current_row - 1 <= Rows && current_row - 1 >= 0)
        allow_moves.push_back("left");
    return allow_moves;
}