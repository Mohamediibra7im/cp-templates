#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Fibonacci Function
// @brief Calculates the nth Fibonacci number using recursion.
// @param n The position in the Fibonacci sequence.
// @return The nth Fibonacci number.
ll fibonacci(ll n)
{
    if (n <= 2)
        return n - 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    // Enter your code here
}
