/*

MAXIMUM OCCURING CHARACTER 

Given a string str of lowercase alphabets. The task is to find the maximum occurring character in the string str. If more than one character occurs the maximum number of time then print the lexicographically smaller character.

Example 1:

Input:
str = testsample
Output: e
Explanation: e is the character which
is having the highest frequency.


*/

#include<iostream>
#include<string>

using namespace std;


char getMaxOccCharacter(string s)
{
    int arr[26]={0};
// create an array of coutnt of characters 
    for(int i=0; i<s.length(); i++)
    {
        //lowercase
        int number=0;
        char ch=s[i];
        if(ch>='a' && ch<='z')
        {
            number =ch-'a';

        }
        //uppercase
        else
        {
number =ch-'A';
        }
        arr[number]++;

    }
    //find maximum character 
    int maxi=-1, ans=0;
    for(int i=0; i<26; i++)
    {
        if(maxi <arr[i])
        {
            ans=i;
            maxi=arr[i];
        }
    }
    char finalAns='a'+ans;
    return finalAns;
}

int main()
{

    string s;
    cin>>s;
cout<<getMaxOccCharacter(s)<<endl;
    return 0;

}