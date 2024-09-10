/*

Problem statement

Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.



There are ‘m’ number of students, and the task is to allocate all the books to the students.



Allocate books in such a way that:

1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.


You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.



If the allocation of books is not possible, return -1.



Example:
Input: ‘n’ = 4 ‘m’ = 2 
‘arr’ = [12, 34, 67, 90]

Output: 113

Explanation: All possible ways to allocate the ‘4’ books to '2' students are:

12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.

12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.

12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.

We are getting the minimum in the last case.

Hence answer is ‘113’.

*/



#include<iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int mid){


    int studentCount=1;
    int pageSum=0;

    for(int i=0; i<n; i++){
        if(pageSum+arr[i]<=mid)
        {
pageSum +=arr[i];
        }
        else
        {
studentCount++;
if(studentCount>m  || arr[i]>mid){
    return false;
}
pageSum=arr[i];
        }
    }
    return true;
}


int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if (m > n) {
        return -1;  // Not enough books for each student
    }
    int s=0;
    int sum=0;
    for (int i = 0; i < n; i++) {
      sum += arr[i];
    }
    int e= sum;
    int ans=-1;
    int mid=s+(e-s)/2;

    while(s<=e)
    {
        if(isPossible(arr,n,m,mid)){
            ans=mid;
            e=mid-1;

        }
        else{
            s=mid+1;
          
        }
       
        mid=s+(e-s)/2;
        
    }
return ans;
}
int main()
{
    
//    vector<int> arr = {2, 8, 8, 4, 5};  // Pages in each book
//     int n = arr.size(), m = 6;          // Number of books and students

//     cout << findPages(arr, n, m) << endl;  // Call the function and output the result

//or//
//  int n = 5;  // Number of books
//     int m = 6;  // Number of students
//     vector<int> arr = {2,8,8,4,5};  // Array of pages in each book
//     int result=findPages(arr,n,m);
// cout<<result<<endl;
//or//

   vector<int> arr = {2, 8, 8, 4, 5};
    cout << findPages(arr, arr.size(), 6) << endl;
    return 0;

}