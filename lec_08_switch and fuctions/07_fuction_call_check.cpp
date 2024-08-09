

//Fuction Call 



// pass by valaue 


#include<iostream>
using namespace std;

/*
void dummy(int n) {
    n++;
    cout<<"n is "<<n<<endl;

}
int main()
{

int n;
cin>>n;

dummy(n);

cout<<"number n is "<<n<<endl;

return 0;

}




//nmericals practice ;

void update(int a)
{
    a=a/2;
}

int main()
{
    int a=10;
    update(a);

    cout<<a<<endl;
}

//output=10


int update(int a)
{
    a-=5;
    return a;
}
int main()
{
    int a=15;
    update(a);

    cout<<a<<endl;

}

//output is 15


*/

int update(int a)
{
int ans=a*a;
return ans;
}

int main()
{
    int a =14;
    a=update(a);
    cout<<a<<endl;
}

//output is 196