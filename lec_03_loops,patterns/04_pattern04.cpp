#include <iostream>
using namespace std;

int main()
{
    /*

    ---To print a pattern like this---
        1
       121
      12321
     1234321
    123454321

    */
    int n;
    cin >> n;

    int row = 1;
    while (row <= n)
    {
        // print first space triangle
        int space = n - row;
        while (space)
        {
            cout << " ";
            space = space - 1;
        }
        // print 2nd triangle
        int col = 1;
        while (col <= row)
        {
            cout << col;
            col = col + 1;
        }
        // print 3rd triangle
        int start = row - 1;
        while (start)
        {
            cout << start;
            start = start - 1;
        }

        cout << endl;
        row = row + 1;
    }
}

/*

//---home work---\\
---try to print this pattern--

1234554321
1234**4321
123****321
12******21
1********1

*/