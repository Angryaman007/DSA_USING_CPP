#include <iostream>
using namespace std;

bool isSorted(int *arr, int size)
{

    // base case

    if (size == 0 || size == 1)
    {
        return true;
    }

    if (arr[0] > arr[1])
        return false;
    else
    {
        bool remainingPart = isSorted(arr + 1, size - 1);
        return remainingPart;
    }
}
int main()
{
    int arr[5] = {2, 4, 9, 8, 9};
    int size = 5;

    bool ans = isSorted(arr,size);
if(ans)
{
    cout<<"array is sorted"<<endl;}
    else{    
        cout<<"array is not sorted"
        <<endl;
    
}
    return 0;
}

/*
HOME WORK

input mein array like : [3,2,5,1,6]
output mein arraY LIKE : SUM KRE  USING RECUSION NOT LOOP OUT PUT IS : 17 

*/