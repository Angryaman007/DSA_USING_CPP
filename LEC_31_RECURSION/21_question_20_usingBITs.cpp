#include <bits/stdc++.h>
using namespace std;

vector<string> subsequences(string str) {
    vector<string> ans;
    int n = str.length();

    // Iterate over all numbers from 1 to 2^n - 1
    for (int i = 1; i < (1 << n); i++) { // from 1 to (2^n)-1
        string subseq = "";

        // For each bit in i, if the bit is 1, include the corresponding character in subseq
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { // check if the j-th bit of i is set
                subseq += str[j];
            }
        }

        ans.push_back(subseq);
    }

    return ans;
}

int main() {
    // Input string
    string str;
    cin >> str;

    // Get all subsequences
    vector<string> result = subsequences(str);

    // Output the subsequences
    for (const string &subseq : result) {
        cout << subseq << " ";
    }

    return 0;
}
