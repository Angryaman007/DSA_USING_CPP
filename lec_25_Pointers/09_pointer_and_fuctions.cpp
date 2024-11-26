#include <iostream>
using namespace std;

// how to use pass by value method

void print(int *p)
{
    cout << *p << endl;
}
// exit

void update(int *p)
{
    // p = p + 1;
    // cout<<"inside "<<p<<endl;
    *p = *p + 1;
}
int getSum(int *arr, int n)

{
    cout << endl
         << "size :" << sizeof(arr) << endl;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()

{
    /*
     int value = 5;
     int *p = &value;

     //    print(p);

     cout << "Before " << *p << endl;

     update(p);

     cout << "After " << *p << endl;
 */
    int arr[5] = {1, 2, 3, 4, 5};
    cout << "Sum is " << getSum(arr, 5) << endl;

    return 0;
}

// study this https://www.naukri.com/code360/guided-paths/pointers/content/235645/offering/3168907 
// and solve the question on codestudio 