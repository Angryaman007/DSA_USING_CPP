#include <iostream>
using namespace std;

int main()
{
    int row;
    cout << "Enter the number of rows: ";
    cin >> row;

    // Creating a jagged array (array of pointers)
    int **arr = new int *[row];
    
    // Allocating memory for each row with different column sizes
    for (int i = 0; i < row; i++)
    {
        int col;
        cout << "Enter the number of columns for row " << i + 1 << ": ";
        cin >> col;

        arr[i] = new int[col]; // Allocating memory for current row

        // Taking input for the current row
        cout << "Enter elements for row " << i + 1 << ": ";
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Outputting the jagged array
    cout << "\nJagged Array:\n";
    for (int i = 0; i < row; i++)
    {
        int col; // Need to know the number of columns in each row
        cout << "Enter the number of columns for row " << i + 1 << ": ";
        cin >> col;

        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Releasing memory
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i]; // Free each row
    }
    delete[] arr; // Free the array of pointers

    return 0;
}
