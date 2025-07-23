#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Factorial Function
// @brief Calculates the factorial of a number using recursion.
// @param num The number to calculate the factorial for.
// @return The factorial of num.
ll factorial(ll num)
{
    if (num <= 1)
        return 1;
    return num * factorial(num - 1);
}

int main()
{
    // Enter your code here
}
