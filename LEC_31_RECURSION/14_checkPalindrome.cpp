#include <iostream>
using namespace std;

bool checkPalindrome(string str, int i, int j)
{

    // base case

    if (i > j)
        return true;

    if (str[i] != str[j])
        return false;

    else
    {
        // recursinve call
        return checkPalindrome(str, i + 1, j-1);
    }
}

int main()
{
    string name = "mannam";
    cout << endl;
    bool isPalindrome = checkPalindrome(name, 0, name.length() - 1);
    if (isPalindrome)
    {
        cout << " ITs a Palindrome "
             << endl;
    }
    else
    {
        cout << "ITs not a Palilndrome"
             << endl;
    }

    return 0;
}