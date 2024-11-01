/*

Given an integer n, return the number of prime numbers that are strictly less than n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
       int cnt = 0;
       vector<bool> prime(n, true);

       // Edge cases for 0 and 1
       if (n <= 2) return 0;
       
       prime[0] = prime[1] = false;

       for (int i = 2; i < n; i++) {
           if (prime[i]) {
               cnt++;
               
               for (int j = 2 * i; j < n; j += i) {
                   prime[j] = false;
               }
           }
       }
       return cnt;
    }
};

int main() {
    Solution sol;
    
    int n1 = 0;
    int n2 = 1;
    int n3 = 10;

    cout << "Number of primes less than " << n1 << " is: " << sol.countPrimes(n1) << endl;
    cout << "Number of primes less than " << n2 << " is: " << sol.countPrimes(n2) << endl;
    cout << "Number of primes less than " << n3 << " is: " << sol.countPrimes(n3) << endl;

    return 0;
}
