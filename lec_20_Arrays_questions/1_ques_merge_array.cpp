/*
MERGE SORTED ARRAY 

you are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

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


void merge(int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i=0, j=0, k=0; 
    while (i<n && j<m)
    {
        if(arr1[i]<arr2[j])
        {
            arr3[k]=arr1[i];
            k++;
            i++;
        }
        else{
            arr3[k]=arr2[j];
            k++;
            j++;
        }
    }
    
    //copy kardo first elemnet ke array ko 
    while (i<n)
    {
        arr3[k]=arr1[i];
        k++;
        i++;
        /*

        OR
        arr3[k++]=arr[i++];
        this will remove the down two lines code 

        */
    }
    //copy kardo second elemnt ko 

    while (j<m)
    {
    arr2[k]=arr2[j];
    k++;
    j++;

    }
    
    
}

void print(int ans[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl; }
int main()
{
    int arr1[5]={1,3,5,7,9};
    int arr2[3]={2,4,6};

    int arr3[8]={0};

    merge(arr1,5,arr2,3,arr3);

    print(arr3,8);
    return 0;
}