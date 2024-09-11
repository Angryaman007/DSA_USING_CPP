/*Problem statement
Selection sort is one of the sorting algorithms that works by repeatedly finding the minimum element from the unsorted part of the array and putting it at the beginning of the unsorted region of the array.

You are given an unsorted array consisting of N non-negative integers. Your task is to sort the array in non-decreasing order using the Selection Sort algorithm.


TIME COMPLEXITY IS O(N^2)
SPACE COMPLEXITY IS CONSTANT 
as there is only use of variables and not more then 1 fuction 

BEST CASE TIME COMPLEXITY : ARRAY IS ALREADY SHORTED THEN ALSO [O(N^2)]
WORST CASE TIME COMPLEXITY IS SASMES AS BEST CASE COMPLEXITY.

//--------USE CASES ---------//

1.whenever the size of an array is small then selction short is used 

//--------HOMEWORK-------------//

1.FLOWCHART 
2.IS STABLE OR UNSTABLE 


//-----------FLOW CHART------------//

                +--------------------+
                |     Start           |
                +--------------------+
                          |
                          v
                +--------------------+
                |  Input: Array and   |
                |  its length (n)     |
                +--------------------+
                          |
                          v
              +---------------------------+
              |  Outer loop: i = 0 to n-1  |
              +---------------------------+
                          |
                          v
              +-------------------------------+
              |  Set minIndex = i (assume i is |
              |  the index of the smallest     |
              |  element initially)            |
              +-------------------------------+
                          |
                          v
              +-------------------------------+
              |  Inner loop: j = i+1 to n-1   |
              +-------------------------------+
                          |
                          v
           +---------------------------------------+
           |  If arr[j] < arr[minIndex]            |
           |      minIndex = j                     |
           +---------------------------------------+
                          |
                          v
          +------------------------------------------+
          |  After inner loop: Swap arr[minIndex]    |
          |  with arr[i]                             |
          +------------------------------------------+
                          |
                          v
              +---------------------------+
              |  Increment i and repeat    |
              |  the outer loop until i < n|
              +---------------------------+
                          |
                          v
               +----------------------+
               |  Sorted array output  |
               +----------------------+
                          |
                          v
                    +-----------+
                    |    End     |
                    +-----------+

ANS 2:

-------Selection Sort is generally an unstable sorting algorithm. This is because during the swapping operation, elements with equal values may not retain their relative order.-----------------

EG:
INPUTE IS THIS : {4A,3,2,4B};  
THEN 
OUTPUT WILL BE :{2, 3, 4B, 4A}


*/

//-----------------CODE-----------------//
#include <bits/stdc++.h> 
#include<vector>
#include <algorithm>
using namespace std;

int selectionSort(vector<int>& arr, int n)
{   
    // Write your code here.

    for (int i = 0; i < n - 1; i++) {
      int minIndex = i;

      for (int j = i + 1; j < n; j++)
    { 

        if(arr[j]<arr[minIndex])
        
            minIndex=j;
        
    }
    swap(arr[minIndex], arr[i]);
    }
}

int main(){
    vector<int> arr = {22,1, 2, 8, 4, 9,3,5,13,11,20,17};  
     // vector<int> arr = {4A, 5,3,2,4B};  

    
    int n=arr.size();

    selectionSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}