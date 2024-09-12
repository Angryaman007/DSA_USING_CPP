/*


Problem statement
You are given ‘N’ integers in the form of an array ‘ARR’. Print the sorted array using the insertion sort.

Note :
No need to return anything. You should sort the array in-place.
For example :
Let ‘ARR’ be: [1, 4, 2]
The sorted array will be: [1, 2, 4].



*/

//----------CODE---------------//

#include <bits/stdc++.h>
#include<vector>
using namespace std;

void insertionSort(int n, vector<int> &arr)
{

    for (int i = 0; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                // shift
                arr[j + 1] = arr[j];
            }
            else
            {
                // ruk jou
                break;
            }
        }
        arr[j + 1] = temp;
    }
}
int main()
{

vector<int>arr={10,2,5,3,6};
int n=arr.size();

insertionSort( n, arr);

for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;


}