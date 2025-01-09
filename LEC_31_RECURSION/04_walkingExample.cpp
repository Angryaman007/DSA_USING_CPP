#include <iostream>
using namespace std;

void reachHome(int strt, int dest)
{
    cout << "start value: " << strt << " destination value: " << dest << endl;
    // base case
    if (strt == dest)
    {
        cout << "ghar aagya hun " << endl;
        return;
    }

    // processing ---ek step aage bhajou
    strt++;

    reachHome(strt, dest);
}
int main()
{

    int dest = 10;
    int strt = 1;

    cout << endl;
    reachHome(strt, dest);

    return 0;
}