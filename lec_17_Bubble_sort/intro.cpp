/*

Problem statement
Bubble Sort is one of the sorting algorithms that works by repeatedly swapping the adjacent elements of the array if they are not in sorted order.

You are given an unsorted array consisting of N non-negative integers. Your task is to sort the array in non-decreasing order using the Bubble Sort algorithm.

For Example:
Bubble Sort implementation for the given array:  {6,2,8,4,10} is shown below :-

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= Arr[i] <= 1000

Where 'T' represents the number of test cases, 'N' represents the size of the array, and Arr[i] represents the elements of the array.
Time Limit: 1 sec.
Sample Input 1:
1
5
6 2 8 4 10 
Sample Output 1:
2 4 6 8 10

TIME COMPLEXITY IS : O(N^2)
SPACE COMPLEXITY IS : O(1) MEANS  CONSTANT 

BEST TIME COMPLEXITY : when arr is already sorted and it is linear O(n).
WORST TIME COMPLEXITY IS : O(N^2)


//--------HOMEWORK------------//

WHAT IS INPLACE SHORT 

QUIZE IN DESCRIPTION 

LET n=i; and i=0; to <n -1
so what will be j= ?

int below code 

*/

//---------------CODE--------------//

#include <bits/stdc++.h> 
using namespace std;
void bubbleSort(vector<int>& arr, int n)
{   

for(int i=1; i<n; i++)
{
    //for round 1 to n-1
for(int j=0; j<n-i; j++)
//process element  till n-i th index 
{
  if (arr[j] > arr[j + 1]) {
    swap(arr[j], arr[j + 1]);
  }
}
}
}

int main()
{
    
    vector<int>arr={6, 2 ,8 ,4 ,10};
    int n=arr.size();

    bubbleSort(arr,n);

     cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;


}