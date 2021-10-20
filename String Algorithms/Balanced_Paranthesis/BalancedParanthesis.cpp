#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool BracketsBalanced(string expression)
{
    stack<char> stk;    // Stack for hold brackets
    char x;

    // Traversing Expression
    for (char & i : expression) {
        if (i == '(' || i == '[' || i == '{') {
            stk.push(i);
            continue;
        }

        // If current bracket isn't a opening bracket then stack cannot be zero.
        if (stk.empty())
            return false;

        // Check
        if (i == ')'){
            x = stk.top();
            stk.pop();
            if (x == '{' || x == '[')
                return false;
        }
        else if (i == '}') {
            x = stk.top();
            stk.pop();
            if (x == '(' || x == '[')
                return false;
        } else if (i == ']'){
            x = stk.top();
            stk.pop();
            if (x == '(' || x == '{')
                return false;
        }
        else {
            continue;
        }
    }

    return (stk.empty());
}

// Driver code
int main()
{
    string expression = "{()}[]";

    cout << (BracketsBalanced(expression) ? "Balanced" : "Not Balanced");

    return 0;
}
