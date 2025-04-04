#include <iostream>
#include <math.h>

using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];

    int cnt = 0;

    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }
    // place pivot at right postion

    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // left and right wala part smbhal lete hai
    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
        return;

    // partition karenge
    int p = partition(arr, s, e);

    // left part sort karnege

    quickSort(arr, s, p - 1);

    // right part sort karege
    quickSort(arr, p + 1, e);
}
int main()
{
    int arr[5] = {2, 4, 1, 6, 9};
    int n = 5;

    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // himework inplace sorting hai ya nhi ?  stabble hai ya nhi why quick sort is preferred over merge sort
    //  space complexity is o(n) time complexity is o(nlogn), worst is 0(n^2).
}