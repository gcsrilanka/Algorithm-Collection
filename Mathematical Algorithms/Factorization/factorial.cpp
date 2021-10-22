#include <iostream>
using namespace std;

int main()
{
    int n, factorial = 1;

    cout << "Enter number to find the factorial: ";
    cin >> n;
    
    for (int c=1; c<=n; c++)
    {
        factorial = factorial*c;
    }

    cout << "Factorial of "<< n << "= " << factorial << endl;
    return 0;
}
