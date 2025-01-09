#include <iostream>
using namespace std;

int factorial(int n)
{

    // cout<<n<<endl;


    //  base case
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
    // writing return is mandatory

    /*or

    int smallerPromblem=factorial(n-1);
    int biggerPromblem=n * smallerProblem;
    return biggerPromblem;

    */
}

int main()
{
    int n;
    cin >> n;
    int ans = factorial(n);
    cout << ans << endl;
}