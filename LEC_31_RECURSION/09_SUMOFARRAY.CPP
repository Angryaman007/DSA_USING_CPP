#include <iostream>
using namespace std;

int sumArray(int *arr, int size)
{
    // base case

    if (size == 0)
    {
        return 0;
    }
    //recusive fuction case
    return arr[0] + sumArray(arr + 1, size - 1);
}
int main()
{
    int arr[]={2,34,5,6,1};
    int size = 5;
    int sum = sumArray(arr, size);
    cout << "sum of array is : " << sum << endl;

    return 0;
}