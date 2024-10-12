#include <iostream>
#include <climits>
using namespace std;

void printSum(int arr[][3], int row, int col)
{

    cout << "printing the sum  row wise :" << endl;
    for (int row = 0; row < 3; row++)
    {
        int sum = 0;

        for (int col = 0; col < 3; col++)
        {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }
    cout << endl;
}

int largestRowSum(int arr[][3], int row, int col)
{
    int maxi = INT_MIN;
    int rowIndex = -1;
    for (int row = 0; row < 3; row++)
    {
        int sum = 0;
        for (int col = 0; col < 3; col++)
        {
            sum += arr[row][col];
        }
        if (sum > maxi)
        {
            maxi = sum;
            rowIndex = row;
        }
    }
    cout << "the maximum sum is " << maxi << endl;
    return rowIndex;
}
int main()
{

    int arr[3][3];

    cout<<"Enter the elemnets"<<endl;

    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            cin>>arr[row][col];
        }
    }

    cout << "printing the array " << endl;
    // print
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    int ansIndex = largestRowSum(arr, 3, 3);
    cout << "max row is at index " << ansIndex << endl;
    return 0;
}