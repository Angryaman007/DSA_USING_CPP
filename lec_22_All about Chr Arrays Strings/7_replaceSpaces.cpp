/*
REPLACE SPACES 

Problem statement
You have been given a string 'STR' of words. You need to replace all the spaces between words with “@40”.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 50
0 <= |STR| <= 100

Where ‘|STR|’ is the length of a particular string including spaces.

Time limit: 1 sec
Sample Input 1:
2
Coding Ninjas Is A Coding Platform
Hello World
Sample Output 1:
Coding@40Ninjas@40Is@40A@40Coding@40Platform
Hello@40World


*/


#include<iostream>
#include<string>
using namespace std;

string replaceSpaces(string &str)
{
    string temp="";
    for(int i=0; i<str.length(); i++)
    {
if(str[i]==' ')
{
temp.push_back('@');
temp.push_back('4');
temp.push_back('0');
}
else
{
    temp.push_back(str[i]);
}
    }
    return temp;
}

int main()
{
  
cout<<"enter the sentece "<<endl;
char str[1000];
cin.getline(str,1000);// it is used to input a sentenc or line with spaces and tab as only cin<<endl; does not exucte tap spaces and enter .
    string ans(str);
    cout<<replaceSpaces(ans)<<endl;
    return 0;



}

/*

SOME INBUIL FUCTION ARE:

COMPARE:::
compare(s1,s2)
strcmp(s1,s2);

COPY:::
strcpy(destination arry, given array);


*/