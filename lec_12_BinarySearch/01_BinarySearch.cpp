#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{

    int start = 0;
    int end = size - 1;
    //int mid = (start + end) / 2;
    // given is okay but not ifficient as the vlaue of is larger it can fail like for 2^31 etc... so uses this for optimization 
     int mid=start+(end-start)/2; 

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        // go to right wala part
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
    cout << "element not found" << endl;
}

int main()
{

    int even[6] = {2, 4, 6, 8, 12, 18};
    int odd[5] = {3, 8, 11, 13, 17};
    
    int evenindex=binarySearch(even, 6, 20);
    cout<<"index of 12 is "<<evenindex<<endl;
    int oddindex=binarySearch(odd, 5, 13);
    cout<<"index of 13 is "<<oddindex<<endl;


    return 0;

}