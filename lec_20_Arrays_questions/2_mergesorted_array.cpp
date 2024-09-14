/*

MERGE SORTED ARRAY 

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

*/
#include<iostream>
#include<vector>
using namespace std;

void merge(int num1[],int m, int num2[], int n )
{
    int temp[m+n];
    int i=0, j=0, k=0;

    while (i<m && j<n )
    {
if(num1[i]<=num2[j])
{
    temp[k]=num1[i];
    i++;


}
else{
    temp[k]=num2[j];
    j++;
   
}
k++;
    }

    //copy karo first elennt ko

    while (i<m)
    {
        temp[k]=num1[i];
        i++;
        k++;
    }
    
    while (j<n)
    {
        temp[k]=num2[j];
        j++;
        k++;

    }
    

    for(int i=0; i<m+n; i++)
    {
        num1[i]=temp[i];
    }
    
}

void print(int num1[], int size)
{
    for(int i=0; i<size; i++ )
    {
        cout<<num1[i]<<" ";
    }
    cout<<endl;
}
int main()
{

    
    int num1[6]={1,2,3,0,0,0};
    int num2[3]={2,5,6};

    merge(num1,3, num2,3);

    print(num1,6);
    return 0;
}

