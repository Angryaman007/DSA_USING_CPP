#include <iostream>
using namespace std;

void revers(string& str, int i, int j)
{

    cout<<"Call recieved for "<<str<<endl;
    // base case

    if (i > j)
        return;

    swap(str[i], str[j]);
    i++;
    j--;

    // Recursive CAll

    revers(str, i, j);
}

int main()
{

    string name = "amandeep";
cout<<endl;

    revers(name, 0, name.length() - 1);
    cout<<endl;
    cout << name << endl;

    return 0;
}