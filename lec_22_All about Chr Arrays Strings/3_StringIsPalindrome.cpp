/*

STRING IS PALINDROME OR NOT 

You're given an alphabetical string ‘S’.



Determine whether it is palindrome or not. A palindrome is a string that is equal to itself upon reversing it.



For example:
‘S’ = racecar
The reverse of ‘S’ is: racecar
Since ‘S’ is equal to its reverse. So ‘S’ is a palindrome.
Hence output will be 1.


*/


#include<iostream>
using namespace std;

char lowerCaase(char ch)
{
    if(ch>='a' && ch<='z')
    {
        return ch;
    }
    else
    {
        char temp=ch-'A'+'a';
        return temp;

    }
}
bool checkPalindrome(char a[], int n)
{
    int s=0;
    int e=n-1;

    while (s<+e)
    {
        if( lowerCaase(a[s] )!= lowerCaase(a[e]))
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

int getLenght(char name[])
{
    int count=0;
    for(int i=0; name[i] !='\0'; i++)
    {
        count++;
    }
    return count;
}
int main()
{
char name[20];
cout<<"ENter the string "<<endl;
cin>>name;
int len=getLenght(name);
cout<<"length "<<len<<endl;

cout<<"Palindrome or Not "<<checkPalindrome(name, len )<<endl;

cout<<"character is "<<lowerCaase('b')<<endl;
cout<<"character is "<<lowerCaase('C')<<endl;
return 0; 
}