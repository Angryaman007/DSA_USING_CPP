/*
STRING COMPRESSION 

Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

 

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int ansIndex =0;

        int n=chars.size();

        while(i<n)
        {
            int j=i+1;
            while(j<n && chars[i]==chars[j])
            {
                j++;
        }
        //yaha kab aooge 
        // tab aaogge jab 
        //vector pura traverse kardiya 
        // ya fer new/different character encounter kia hai
//old charachter sotore karlo 
        chars[ansIndex++]=chars[i];
int count =j-i;

if(count>1 )
{
    //converting count into single digit and saving answer 
    string cnt=to_string(count);
    for(char ch:cnt )
    {
        chars[ansIndex++]=ch;
    }

}
i=j;
        }
        return ansIndex;
    }
};

int main()
{
Solution sol;

 vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
int result=sol.compress(chars);

cout<<"output is : "<<result<<endl;
 cout << "Compressed characters: ";
    for (int i = 0; i < result; i++) {
        cout << chars[i];
    }
    cout << endl;
return 0; 
}

//-----------IMPORTENT QUESTION------------------//

