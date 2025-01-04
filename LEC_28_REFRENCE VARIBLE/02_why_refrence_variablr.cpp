#include<iostream>
using namespace std;

void update2(int& n){
    n++;
}

void update1(int n){
    n++;
}

int main()
{
    
    int n =5;
    
    cout<<"before "<<n<<endl;
    
    update2(n);

    cout<<"after "<<n<<endl;

    return 0;

}
