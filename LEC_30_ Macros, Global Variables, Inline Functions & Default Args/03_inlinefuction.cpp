#include <iostream>
using namespace std;

inline int getMax(int &a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int a = 1, b = 2;
    int ans = 0;

    /*
        if(a>b)
        {
            ans=a;
        }
        else
        {
            ans=b;
        }

    */

    // the above condition can be rewrite as

    // ans= (a>b) ? a : b;
    
    ans = getMax(a, b);
    cout << ans << endl;

    a = a + 3;
    b = b + 1;

    // ans= (a>b) ? a : b;

    ans = getMax(a, b);
    cout << ans << endl;

    return 0;
}