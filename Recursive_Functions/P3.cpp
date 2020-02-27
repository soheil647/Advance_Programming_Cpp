#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

void Gold(int **network, int &m, int &n);
int find_way(vector<int> &way, int **network, vector<int> &result_vector, int &result, int &m, int &n);

int main()
{
    int number;
    int m,n;

    cout << "Enter m: ";
    cin >> m;
    cout << "Enter n: ";
    cin >> n;

    int **network = (int **)malloc(m * sizeof(int *));
    for (int i=0; i<m; i++)
        network[i] = (int *)malloc(n * sizeof(int));


   for(int i=0 ; i < m ; i++)
    {
        for(int j=0 ; j < n ; j++)
        {
            cin >> number;
            network[i][j] = number;
        }
    }
   Gold(network, m, n);

    return 0;
}

void Gold(int **network, int &m, int &n)
{
    vector<int> way;
    vector<int> result_vector;
    int result = 0;
    for(int row = 0 ; row < m ; row++)
    {
        for(int col = 0 ; col < n ; col++)
        {
            if (network[row][col] != 0)
            {
                way.push_back(row);
                way.push_back(col);
                find_way(way, network, result_vector, result, m, n);

                result = 0;
            }
        }
    }
   cout << *max_element(result_vector.begin(), result_vector.end()) << endl;

}

int find_way(vector<int> &way, int **network, vector<int> &result_vector, int &result, int &m, int &n)
{
    int current_value;
    int current_row;
    int current_col;
    int flag = 0;
    int number;
    vector<int> local_way;

    current_row = way[way.size()-2];
    current_col = way[way.size()-1];
    current_value = network[current_row][current_col];

    result += current_value;

    if((current_row == 0) && (current_col == 0))
    {

        if(network[current_row][current_col + 1] != 0)
        {
            local_way.push_back(current_row);
            local_way.push_back(current_col + 1);
        }
        if(network[current_row + 1][current_col] != 0)
        {
            local_way.push_back(current_row + 1);
            local_way.push_back(current_col);
        }


        number = local_way.size();
        for(int i=0 ; i <= number ; i = i + 2)
        {

            if((local_way.size() != 0) && (way.size() != 0))
            {

                for(int j=0 ; j < way.size() ; j=j+2)
                {

                    if((local_way[i] == way[j]) && (local_way[i + 1] == way[j + 1]))
                    {
                        flag = 1;
                    }
                }
                if(flag == 1)
                {
                    local_way.pop_back();
                    local_way.pop_back();
                    flag = 0;
                    return 0;
                }
                else
                {
                    way.push_back(local_way[i]);
                    way.push_back(local_way[i + 1]);

                    find_way(way, network, result_vector, result, m, n);

                    if(local_way.size() >= 2)
                    {
                        local_way.pop_back();
                        local_way.pop_back();
                    }
                }
            }
            else if(local_way.size() < 2)
            {

                result_vector.push_back(result);
                result = result - network[way[way.size()-2]][way[way.size()-1]];
                way.pop_back();
                way.pop_back();
                return 0;
            }


        }
    }

    else if((current_row == 0) && (current_col == (n-1)))
    {

        if(network[current_row + 1][current_col] != 0)
        {
            local_way.push_back(current_row + 1);
            local_way.push_back(current_col);
        }
        if(network[current_row][current_col - 1] != 0)
        {
            local_way.push_back(current_row);
            local_way.push_back(current_col - 1);
        }

        number = local_way.size();

        for(int i=0 ; i <= number ; i = i + 2)
        {
            if((local_way.size() != 0) && (way.size() != 0))
            {
                for(int j=0 ; j < way.size()-1 ; j=j+2)
                {
                    if((local_way[i] == way[j]) && (local_way[i + 1] == way[j + 1]))
                    {
                        flag = 1;
                    }
                }
                if(flag == 1)
                {
                    local_way.pop_back();
                    local_way.pop_back();
                    flag = 0;
                }
                else
                {
                    way.push_back(local_way[i]);
                    way.push_back(local_way[i + 1]);
                    find_way(way, network, result_vector, result, m, n);
                    local_way.pop_back();
                    local_way.pop_back();
                }
            }
            else if(local_way.size() == 0)
            {
                result_vector.push_back(result);
                result = result - network[way[way.size()-2]][way[way.size()-1]];
                way.pop_back();
                way.pop_back();
                return 0;
            }
        }
    }

    else if((current_row == (m-1)) && (current_col == (n-1)))
    {
        if(network[current_row][current_col - 1] != 0)
        {
            local_way.push_back(current_row);
            local_way.push_back(current_col - 1);
        }

        if(network[current_row - 1][current_col] != 0)
        {
            local_way.push_back(current_row - 1);
            local_way.push_back(current_col);
        }


        number = local_way.size();

        for(int i=0 ; i <= number ; i = i + 2)
        {
            if((local_way.size() != 0) && (way.size() != 0))
            {
                for(int j=0 ; j < way.size()-1 ; j=j+2)
                {
                    if((local_way[i] == way[j]) && (local_way[i + 1] == way[j + 1]))
                    {
                        flag = 1;
                    }
                }
                if(flag == 1)
                {
                    local_way.pop_back();
                    local_way.pop_back();
                    flag = 0;
                }
                else
                {
                    way.push_back(local_way[i]);
                    way.push_back(local_way[i + 1]);
                    find_way(way, network, result_vector, result, m, n);
                    local_way.pop_back();
                    local_way.pop_back();
                }
            }
            else if(local_way.size() == 0)
            {
                result_vector.push_back(result);
                result = result - network[way[way.size()-2]][way[way.size()-1]];
                way.pop_back();
                way.pop_back();
                return 0;
            }
        }
    }

    else if((current_row == (m-1)) && (current_col == 0))
    {

        if(network[current_row][current_col + 1] != 0)
        {
            local_way.push_back(current_row);
            local_way.push_back(current_col + 1);
        }

        if(network[current_row - 1][current_col] != 0)
        {
            local_way.push_back(current_row - 1);
            local_way.push_back(current_col);
        }


        number = local_way.size();

        for(int i=0 ; i <= number ; i = i + 2)
        {
            if((local_way.size() != 0) && (way.size() != 0))
            {
                for(int j=0 ; j < way.size()-1 ; j=j+2)
                {
                    if((local_way[i] == way[j]) && (local_way[i + 1] == way[j + 1]))
                    {
                        flag = 1;
                    }
                }
                if(flag == 1)
                {
                    local_way.pop_back();
                    local_way.pop_back();
                    flag = 0;
                }
                else
                {
                    way.push_back(local_way[i]);
                    way.push_back(local_way[i + 1]);
                    local_way.pop_back();
                    local_way.pop_back();
                    find_way(way, network, result_vector, result, m, n);

                }
            }
            else if(local_way.size() == 0)
            {
                result_vector.push_back(result);
                result = result - network[way[way.size()-2]][way[way.size()-1]];
                way.pop_back();
                way.pop_back();
                return 0;
            }
        }
    }

    else if((current_row == 0) && ((current_col != 0)||(current_col != (n-1))))
    {

        if(network[current_row][current_col + 1] != 0)
        {
            local_way.push_back(current_row);
            local_way.push_back(current_col + 1);
        }

        if(network[current_row + 1][current_col] != 0)
        {
            local_way.push_back(current_row + 1);
            local_way.push_back(current_col);
        }

        if(network[current_row][current_col - 1] != 0)
        {
            local_way.push_back(current_row);
            local_way.push_back(current_col - 1);
        }


        number = local_way.size();

        for(int i=0 ; i <= number ; i = i + 2)
        {
            if((local_way.size() != 0) && (way.size() != 0))
            {
                for(int j=0 ; j < way.size()-1 ; j=j+2)
                {
                    if((local_way[i] == way[j]) && (local_way[i + 1] == way[j + 1]))
                    {
                        flag = 1;
                    }
                }
                if(flag == 1)
                {
                    local_way.pop_back();
                    local_way.pop_back();
                    flag = 0;
                }
                else
                {
                    way.push_back(local_way[i]);
                    way.push_back(local_way[i + 1]);
                    find_way(way, network, result_vector, result, m, n);
                    local_way.pop_back();
                    local_way.pop_back();
                }
            }
            else if(local_way.size() == 0)
            {
                result_vector.push_back(result);
                result = result - network[way[way.size()-2]][way[way.size()-1]];
                way.pop_back();
                way.pop_back();
                return 0;
            }
        }
    }

    else if(((current_row != 0)||(current_row != (m-1))) && (current_col == 0))
    {

        if(network[current_row][current_col + 1] != 0)
        {
            local_way.push_back(current_row);
            local_way.push_back(current_col + 1);
        }

        if(network[current_row + 1][current_col] != 0)
        {
            local_way.push_back(current_row + 1);
            local_way.push_back(current_col);
        }

        if(network[current_row - 1][current_col] != 0)
        {
            local_way.push_back(current_row - 1);
            local_way.push_back(current_col);
        }

        number = local_way.size();

        for(int i=0 ; i <= number ; i = i + 2)
        {
            if((local_way.size() != 0) && (way.size() != 0))
            {
                for(int j=0 ; j < way.size()-1 ; j=j+2)
                {
                    if((local_way[i] == way[j]) && (local_way[i + 1] == way[j + 1]))
                    {
                        flag = 1;
                    }
                }
                if(flag == 1)
                {
                    local_way.pop_back();
                    local_way.pop_back();
                    flag = 0;
                }
                else
                {
                    way.push_back(local_way[i]);
                    way.push_back(local_way[i + 1]);
                    find_way(way, network, result_vector, result, m, n);
                    local_way.pop_back();
                    local_way.pop_back();
                }
            }
            else if(local_way.size() == 0)
            {
                result_vector.push_back(result);
                result = result - network[way[way.size()-2]][way[way.size()-1]];
                way.pop_back();
                way.pop_back();
                return 0;
            }
        }
    }

    else if((current_row == (m-1)) && ((current_col != 0)||(current_col != (n-1))))
    {

        if(network[current_row][current_col + 1] != 0)
        {
            local_way.push_back(current_row);
            local_way.push_back(current_col + 1);
        }

        if(network[current_row][current_col - 1] != 0)
        {
            local_way.push_back(current_row);
            local_way.push_back(current_col - 1);
        }

        if(network[current_row - 1][current_col] != 0)
        {
            local_way.push_back(current_row - 1);
            local_way.push_back(current_col);
        }

        number = local_way.size();

        for(int i=0 ; i <= number ; i = i + 2)
        {
            if((local_way.size() != 0) && (way.size() != 0))
            {
                for(int j=0 ; j < way.size()-1 ; j=j+2)
                {
                    if((local_way[i] == way[j]) && (local_way[i + 1] == way[j + 1]))
                    {
                        flag = 1;
                    }
                }
                if(flag == 1)
                {
                    local_way.pop_back();
                    local_way.pop_back();
                    flag = 0;
                }
                else
                {
                    way.push_back(local_way[i]);
                    way.push_back(local_way[i + 1]);
                    find_way(way, network, result_vector, result, m, n);
                    local_way.pop_back();
                    local_way.pop_back();
                }
            }
            else if(local_way.size() == 0)
            {
                result_vector.push_back(result);
                result = result - network[way[way.size()-2]][way[way.size()-1]];
                way.pop_back();
                way.pop_back();
                return 0;
            }
        }
    }

    else if((((current_row != 0)||(current_row != (m-1))) && (current_col == (n-1))))
    {
        if(network[current_row + 1][current_col] != 0)
        {
            local_way.push_back(current_row + 1);
            local_way.push_back(current_col);
        }

        if(network[current_row][current_col - 1] != 0)
        {
            local_way.push_back(current_row);
            local_way.push_back(current_col - 1);
        }

        if(network[current_row - 1][current_col] != 0)
        {
            local_way.push_back(current_row - 1);
            local_way.push_back(current_col);
        }

        number = local_way.size();

        for(int i=0 ; i <= number ; i = i + 2)
        {
            if((local_way.size() != 0) && (way.size() != 0))
            {
                for(int j=0 ; j < way.size()-1 ; j=j+2)
                {
                    if((local_way[i] == way[j]) && (local_way[i + 1] == way[j + 1]))
                    {
                        flag = 1;
                    }
                }
                if(flag == 1)
                {
                    local_way.pop_back();
                    local_way.pop_back();
                    flag = 0;
                }
                else
                {
                    way.push_back(local_way[i]);
                    way.push_back(local_way[i + 1]);
                    find_way(way, network, result_vector, result, m, n);
                    local_way.pop_back();
                    local_way.pop_back();
                }
            }
            else if(local_way.size() == 0)
            {
                result_vector.push_back(result);
                result = result - network[way[way.size()-2]][way[way.size()-1]];
                way.pop_back();
                way.pop_back();
                return 0;
            }
        }
    }

    else
    {

        if(network[current_row][current_col + 1] != 0)
        {
            local_way.push_back(current_row);
            local_way.push_back(current_col + 1);
        }

        if(network[current_row + 1][current_col] != 0)
        {
            local_way.push_back(current_row + 1);
            local_way.push_back(current_col);
        }

        if(network[current_row][current_col - 1] != 0)
        {
            local_way.push_back(current_row);
            local_way.push_back(current_col - 1);
        }

        if(network[current_row - 1][current_col] != 0)
        {
            local_way.push_back(current_row - 1);
            local_way.push_back(current_col);
        }

        number = local_way.size();

        for(int i=0 ; i <= number ; i = i + 2)
        {
            if((local_way.size() != 0) && (way.size() != 0))
            {
                for(int j=0 ; j < way.size()-1 ; j=j+2)
                {
                    if((local_way[i] == way[j]) && (local_way[i + 1] == way[j + 1]))
                    {
                        flag = 1;
                    }
                }
                if(flag == 1)
                {
                    local_way.pop_back();
                    local_way.pop_back();
                    flag = 0;
                }
                else
                {
                    way.push_back(local_way[i]);
                    way.push_back(local_way[i + 1]);
                    find_way(way, network, result_vector, result, m, n);
                    local_way.pop_back();
                    local_way.pop_back();
                }
            }
            else if(local_way.size() == 0)
            {
                result_vector.push_back(result);
                result = result - network[way[way.size()-2]][way[way.size()-1]];
                way.pop_back();
                way.pop_back();
                return 0;
            }
        }
    }
    return 0;
}