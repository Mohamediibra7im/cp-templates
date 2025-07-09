#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// @brief Checks if a number is prime.
// @param n The number to check.
// @return True if n is prime, false otherwise.
bool isPrime(ll n)
{
    if (n < 2 || (n % 2 == 0 && n != 2))
        return false;
    for (int i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0)
            return false;
    return true;
}

// GCD is the largest positive integer that divides both numbers without leaving a remainder.
// @brief Calculates the GCD (Greatest Common Divisor) of two numbers.
// @param a The first number.
// @param b The second number.
// @return The GCD of a and b.
ll GCD(ll a, ll b)
{
    return (b == 0 ? a : GCD(b, a % b));
}

// LCM is the smallest positive integer that is divisible by both numbers.
// @brief Calculates the LCM (Least Common Multiple) of two numbers.
// @param a The first number.
// @param b The second number.
// @return The LCM of a and b.
ll LCM(ll a, ll b)
{
    return a / GCD(a, b) * b;
}

// GCD for array of numbers
// @brief Calculates the GCD of a array of numbers.
// @param v A vector of long long integers.
// @return The GCD of all elements in the vector.
ll GCD_Vect(vector<ll> &v)
{
    ll ans = v[0];
    for (int i = 1; i < v.size(); i++)
        ans = GCD(ans, v[i]);
    return ans;
}

// LCM for array of numbers
// @brief Calculates the LCM of a array of numbers.
// @param v A vector of long long integers.
// @return The LCM of all elements in the vector.
ll LCM_Vect(vector<ll> &v)
{
    ll ans = 1;
    for (int i = 1; i < v.size(); i++)
        ans = LCM(ans, v[i]);
    return ans;
}

// Prime factorization of a number
// @brief Calculates the prime factorization of a number.
// @param n The number to factorize.
// @return A vector containing the prime factors of n.
vector<int> primeFactorization(ll n)
{
    vector<int> factors;
    while (n % 2 == 0)
    {
        factors.push_back(2), n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            factors.push_back(i), n /= i;
        }
    }
    if (n > 2)
    {
        factors.push_back(n);
    }
    return factors;
}

// Count Prime Divisor
// @brief Counts the number of prime divisors of a number.
// @param n The number to analyze.
int countPrimeDivisor(ll n)
{
    int cnt = 0;
    for (ll i = 1; i <= n; ++i) {
        int count = 0;
        vector<int> factors = primeFactorization(i);
        set<int> unique_factors(factors.begin(), factors.end());
        if (unique_factors.size() == 2) {
            cnt++;
        }
    }
    return cnt;
}

// Find k factors of a number
// @brief Finds k factors of a number n.
// @param n The number to factorize.
// @param k The number of factors to find.
// @return A vector containing the first k factors of n, or {-1} if not enough factors exist.
vector<int> findKFactors(ll n, int k)
{
    vector<int> factors = primeFactorization(n);
    if (factors.size() < k)
        return {-1};
    vector<int> result;
    for (int i = 0; i < k - 1; ++i)
        result.push_back(factors[i]);
    int last = 1;
    for (int i = k - 1; i < factors.size(); ++i)
        last *= factors[i];
    result.push_back(last);
    return result;
}

// Get all divisors of a number
// @brief Returns a vector containing all divisors of a number.
// @param n The number to find divisors for.
// @return A vector containing all divisors of n.
vector<ll> getDivisors(ll n)
{
    vector<ll> divisors;
    for (int i = 1; i < sqrt(n); i++)
        if (n % i == 0)
            divisors.push_back(i), divisors.push_back(n / i);
    if (sqrt(n) == int(sqrt(n)))
        divisors.push_back(sqrt(n));
    return divisors;
}

// Prints all divisors of a number in increasing order
// @brief Prints all divisors of a number.
// @param n The number to find divisors for.
void printDivisors(ll n)
{
    set<ll> divisors;
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            divisors.insert(i);
            divisors.insert(n / i);
        }
    }
    for (auto &d : divisors)
        cout << d << " ";
    cout << endl;
}

// Number of divisors of a number
// @brief Calculates the number of divisors of a number.
// @param n The number to analyze.
// @return The total number of divisors of n.
int numberOfDivisors(ll n)
{
    int divisors = 0;
    for (int i = 1; i <= sqrt(n); i++)
        if (n % i == 0)
            divisors += 2;
    return divisors - (sqrt(n) == (int)sqrt(n));
}

// Sum of divisors of a number
// @brief Calculates the sum of all divisors of a number.
// @param n The number to analyze.
// @return The sum of all divisors of n.
ll sumOfDivisors(ll n)
{
    ll sumDivisors = 0;
    for (int i = 1; i < sqrt(n); i++)
        if (n % i == 0)
            sumDivisors += ((n / i) + i);
    ll sq = sqrt(n);
    return sumDivisors + (sq * sq == n ? sq : 0);
}

// Summation of first n natural numbers
// @brief Calculates the summation of the first n natural numbers.
// @param x The number of terms to sum.
// @return The sum of the first x natural numbers.
ll Summation(ll x)
{
    return x * (x + 1) / 2;
}

// Permutation of a vector of numbers
// @brief Prints all permutations of a vector of numbers.
// @param nums A vector of integers to permute.
void printPermutation(vector<int> &nums)
{
    ll Factorial = 1;
    for (int i = 1; i <= nums.size(); i++)
        Factorial *= i;
    while (Factorial--)
    {
        for(auto &i : nums)
            cout << i << " ";
        cout << endl;
        next_permutation(nums.begin(), nums.end());
    }
}

// Permutation of a string
// @brief Prints all permutations of a string.
// @param s The string to permute.
void PrintStringPermutation(string s)
{
    sort(s.begin(), s.end());
    do
    {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));
}

// Combination of n choose r
// @brief Calculates the number of combinations of n items taken r at a time.
// @param n The total number of items.
// @param r The number of items to choose.
// @return The number of combinations (nCr).
ll nCr(ll n, ll r)
{
    if (r > n)
        return 0;
    ll p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    // condition for minimum choose
    if (n < 1)
        return 0;
    while (r)
    {
        p *= n, k *= r;
        ll m = __gcd(p, k);
        p /= m, k /= m, n--, r--;
    }
    return p;
}

// Permutation of n choose r
// @brief Calculates the number of permutations of n items taken r at a time.
// @param n The total number of items.
// @param r The number of items to choose.
// @return The number of permutations (nPr).
ll nPr(ll n, ll r)
{
    if(r > n)
        return 0;
    ll npr = 1;
    while (r-- > 0)
    {
        npr *= n--;
    }
    return npr;
}

// Big Modulo Calculation
// @brief Calculates 'a' mod for 'big int'
// @param a The base number as a string
// @param mod The modulo value
// @return The result of a mod
ll bigMod(string s, ll mod)
{
    ll res = 0;
    for (char c : s)
    {
        res = (res * 10 + (c - '0')) % mod;
    }
    return res;
}

// Modular Exponentiation
// @brief Calculates (x^n) mod m using fast exponentiation.
// @param x The base number.
// @param n The exponent.
// @param m The modulo value.
// @return The result of (x^n) mod m.
int modpower(int x, int n, int m)
{
    if (n == 0) // base case
        return 1 % m;
    ll u = modpower(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) // when 'n' is odd
        u = (u * x) % m;
    return u;
}

// Fast Power Calculation
// @brief Calculates base raised to the power exp using fast exponentiation.
// @param base The base number.
// @param exp The exponent.
// @return The result of base^exp.
ll fastPower(ll base, ll exp)
{
    ll power = 1;
    while (exp)
    {
        if (exp & 1)
            power *= base;
        exp >>= 1;
        base *= base;
    }
    return power;
}

// Sieve of Eratosthenes
// @brief Generates all prime numbers up to n using the Sieve of Eratosthenes.
// @param n The upper limit for prime generation.
// @return A vector containing all prime numbers up to n.
// @note The Sieve of Eratosthenes is an efficient algorithm to find all primes up to a given limit.
vector<ll> sieve(ll n)
{
    vector<bool> prime(n + 1, true);
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (prime[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }

    // @note This part collects all prime numbers from the sieve.
    vector<ll> res;
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            res.push_back(p);
        }
    }
    return res;
}

int main()
{
    // Enter your code here
}