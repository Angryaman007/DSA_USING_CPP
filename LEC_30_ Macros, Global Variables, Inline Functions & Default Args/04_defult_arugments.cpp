#include <iostream>
using namespace std;

void print(int arr[], int n, int start = 0)
{
    for (int i = start; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int arr[5] = {10, 21, 23, 44, 50};

    int size = 5;

    print(arr, size, 2);
    
// using aruguments
cout<<endl<<"Using Arguments"<<endl;

    print(arr, size);

    return 0;
}