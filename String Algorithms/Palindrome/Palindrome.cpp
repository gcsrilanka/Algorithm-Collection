#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string Palindrome(string S) {
    string P = S;
    reverse(P.begin(), P.end());

    // Return True if Palindrome
    return S == P ? "Palindrome" : "Not Palindrome";
}

// Driver Code
int main() {
    string S = "RACECAR";
    cout << Palindrome(S);
    return 0;
}
