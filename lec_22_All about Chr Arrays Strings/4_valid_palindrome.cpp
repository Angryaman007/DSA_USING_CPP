/*

 VALID PALINDROME 

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

 

*/
#include<iostream>
#include<string>
using namespace std; 
class Solution {
    private:
    bool valid(char ch )
    {
        if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9'))
        {
            return 1;

    }
        return 0;
    }
    char lowerCaase(char ch)
{
    if((ch>='a' && ch<='z')||(ch>='0'&& ch<='9'))
    {
        return ch;
    }
    else
    {
        char temp=ch-'A'+'a';
        return temp;

    }
}
bool checkPalindrome(string a)
{
    int s=0;
    int e=a.length()-1;

    while (s<+e)
    {
        if(a[s] !=a[e])
        {
            return 0;
        }
        else
        {
            s++;
            e--;
        }
    }
    return 1; 
 }  
public:
    bool isPalindrome(string s) {
      //....FALTU CHARACHTER HATA DO ........//
string temp="";

for(int j=0; j<s.length(); j++)
{
    if(valid(s[j]))
    {
        temp.push_back(s[j]);
    }
}
//.....LOWER CASE ............//

for(int j=0; j<temp.length(); j++)
{
    temp[j]=lowerCaase(temp[j]);
}
return checkPalindrome(temp);
    }
};

int main()
{
      Solution sol;
    
    string s = "A man, a plan, a canal: Panama";
    
    bool result = sol.isPalindrome(s);
    
    if (result) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}

