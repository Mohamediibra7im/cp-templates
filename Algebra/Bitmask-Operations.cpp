#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Function to get the binary representation of a number in a given base
// @param num The number to convert.
// @param base The base to convert to (e.g., 2 for binary, 10 for decimal, 16 for hexadecimal).
// @return A vector containing the digits of the number in the specified base.
// @note The function reverses the digits to present them in the correct order.
vector<ll> getRepresentation(ll num, ll base)
{
    vector<ll> ans;
    while (num)
    {
        ans.push_back(num % base);
        num /= base;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Function to check if a bit is set (equal to 1) at position i
// @param n The number to check.
// @param i The bit position to check (0-indexed).
// @return True if the bit is set, false otherwise.
bool KnowBit(ll n, int i)
{
    return (n >> i) & 1;
}

// Function to turn on a bit (set it = 1) at position i in number n
// @param n The number to modify.
// @param i The bit position to set (0-indexed).
// @return The modified number with the bit set.
// if the bit is 0, it will be set to 1.
ll Setbit(ll n, int i)
{
    return n | (1 << i);
}

// Function to turn off a bit (set it = 0) at position i in number n
// @param n The number to modify.
// @param i The bit position to reset (0-indexed).
// @return The modified number with the bit reset.
// if the bit is 1, it will be set to 0.
ll Resetbit(ll n, int i)
{
    return n & (~(1 << i));
}

// Function to flip a bit at position i in number n
// @param n The number to modify.
// @param i The bit position to flip (0-indexed).
// @return The modified number with the bit flipped.
// if the bit is 0, it will be set to 1, and if it is 1, it will be set to 0.
ll flip(ll n, int i)
{
    return n ^ (1 << i);
}

// Function to count the number of bits set to 1 in a number
// @param n The number to analyze.
// @return The count of bits set to 1 in n.
int countOnes(int n)
{
    return __builtin_popcount(n); // for int numbers
    // return __builtin_popcountll(n); // for long long numbers
}

// Function to check if a number is a power of two
// @param n The number to check.
// @return True if n is a power of two, false otherwise.
// A number is a power of two if it has exactly one bit set (equal to 1) in its binary representation
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return 0;
    return !(n & (n - 1));
}

// Function to generate all subsets of a set
// @param s The input set as a vector of integers.
// @return A vector of vectors containing all subsets of the input set.
// @note The function iterates through all possible masks from 0 to 2^n - 1,
// where n is the size of the input set. For each mask, it checks which bits
// are set and includes the corresponding elements in the subset.
vector<vector<int>> generateSubsets(const vector<int> &s)
{
    int n = s.size();
    vector<vector<int>> ans;
    auto KnowBit = [](long long n, int i)
    {
        return (n >> i) & 1;
    };

    for (int mask = 0; mask < (1 << n); mask++)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if (KnowBit(mask, i) == 1)
            {
                v.push_back(s[i]);
            }
        }
        ans.push_back(v);
    }
    sort(ans.begin(), ans.end());
    return ans;
}




int main()
{

    /*
    - Example usage of generateSubsets function
    - This will generate all subsets of the input set and print them.
    - Uncomment the code below to test the function.
    int n;
    vector<int> s(20);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    s.resize(n);

    vector<vector<int>> ans = generateSubsets(s);

    for (auto &x : ans) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    */
}

