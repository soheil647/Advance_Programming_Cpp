#include <iostream>
#include <vector>

using namespace std;

// Recursive function to replace each element of the array with product
// of every other element without using division operator
int findProduct(vector<int>& arr, int n, int left, int i)
{
    // base case: no elements left on right side
    if (i == n)
        return 1;

    // take back-up of current element
    int curr = arr[i];

    // calculate product of the right sub-array
    int right = findProduct(arr, n, left * arr[i], i + 1);

    // replace current element with product of left and right sub-array
    arr[i] = left * right;

    // return product of right sub-array including current element
    return curr * right;
}

// main function
int main()
{
    vector<int> arr;

    int temp;
    while(cin >> temp){
        arr.push_back(temp);
    }
    int n = arr.size();

    findProduct(arr, n, 1, 0);

    // print the modified array
    for(int i: arr)
        cout << i << " ";

    return 0;
}