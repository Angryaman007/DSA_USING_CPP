#include <iostream>
using namespace std;

void update(int **p)
{
    // p=p+1;
    // khuch change hoga ishe ya nhi
    //  nhi hoga change khuch

    //*p=*p+1;
    // khuch change hoga ishe ya nhi
    // change hoga khcuh to

    **p = **p + 1;
    // yaha ishe khuch hoga change ya nhi
    // change hoga jii i hoga
}

int main()
{

    int i = 5;
    int *p = &i;
    int **p2 = &p;

    cout << endl
         << endl;

    cout << "before " << i << endl;
    cout << "before " << p << endl;
    cout << "before " << p2 << endl;
    update(p2);
    cout << "after " << i << endl;
    cout << "after " << p << endl;
    cout << "after " << p2 << endl;

    cout << endl
         << endl;

    return 0;
}