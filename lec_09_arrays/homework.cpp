//pair sum 
// find duplicx
//sort zero and array 


//Problem statement
/*

You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].

Now, in the given array/list, 'M' numbers are present twice and one number is present only once.

You need to find and return that number which is unique in the array/list.

 Note:
Unique element is always present in the array/list according to the given condition.

solution====:::;

int findUnique(int *arr, int size)
{
    int ans=0;

    for(int i=0; i<size; i++){
        ans=ans^arr[i];
    }
    return ans;
    
}

/////Problem statement

You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once. There is a single integer value that is present in the array twice. Your task is to find the duplicate integer value present in the array.

For example:

Consider ARR = [1, 2, 3, 4, 4], the duplicate integer value present in the array is 4. Hence, the answer is 4 in this case.
Note :
A duplicate number is always present in the given array.

*/

//leatcode promblem no 1207
//leatcode promblem no 442
