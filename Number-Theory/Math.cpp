#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7, maxA = 2e6 + 5;

// @brief Checks if a number is prime.
// @param n The number to check.
// @return True if n is prime, false otherwise.
bool isPrime(ll n)
{
    if (n < 2 || (n % 2 == 0 && n != 2))
        return false;
    for (int i = 3; i * i <= n; i += 2)
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
    for (int i = 3; i * i <= n; i += 2)
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
    for (ll i = 1; i <= n; ++i)
    {
        int count = 0;
        vector<int> factors = primeFactorization(i);
        set<int> unique_factors(factors.begin(), factors.end());
        if (unique_factors.size() == 2)
        {
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
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
            divisors.push_back(i), divisors.push_back(n / i);
    if (sqrt(n) == int(sqrt(n)))
        divisors.push_back(sqrt(n));
    return divisors;
}

// Number of divisors of a number
// @brief Calculates the number of divisors of a number.
// @param n The number to analyze.
// @return The total number of divisors of n.
int numberOfDivisors(ll n)
{
    int divisors = 0;
    for (int i = 1; i * i <= n; i++)
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
    for (int i = 1; i * i < n; i++)
        if (n % i == 0)
            sumDivisors += ((n / i) + i);
    ll sq = sqrt(n);
    return sumDivisors + (sq * sq == n ? sq : 0);
}

// get Composite Numbers
// @brief Returns a vector containing all composite numbers up to n.
// @param n The upper limit for composite numbers.
vector<ll> getCompositeNumbers(ll n)
{
    vector<ll> compositeNumbers;
    for (ll i = 4; i <= n; i++)
    {
        if (!isPrime(i))
        {
            compositeNumbers.push_back(i);
        }
    }
    return compositeNumbers;
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
        for (auto &i : nums)
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

// nCr Function
// @brief Calculates the number of combinations of n items taken r at a time.
// @param n The total number of items.
// @param r The number of items to choose.
// @return The number of combinations (nCr).
// @note Uses precomputed factorials and their inverses for efficiency.
ll nCr(ll n, ll r)
{
    if (n < r || r < 0)
        return 0LL;
    return fact[n] * invfact[n - r] % mod * invfact[r] % mod;
}

// nPr Function
// @brief Calculates the number of permutations of n items taken r at a time.
// @param n The total number of items.
// @param r The number of items to arrange.
// @return The number of permutations (nPr).
// @note Uses precomputed factorials and their inverses for efficiency.
ll nPr(ll n, ll r)
{
    if (n < r || r < 0)
        return 0LL;
    return fact[n] * invfact[n - r] % mod;
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

// Fast Power Calculation
// @brief Calculates (base^exp) % mod using exponentiation by squaring.
// @param base The base number.
// @param exp The exponent.
// @return The result of base^exp.
ll fastPower(ll base, ll expo, ll mod)
{
    base %= mod;
    ll res = 1;
    while (expo > 0)
    {
        if (expo & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        expo >>= 1;
    }
    return res;
}

// Modular Inverse Calculation
// @brief Calculates the modular inverse of x under modulo using Fermat's Little Theorem.
// @param x The number to find the inverse of.
// @param mod The modulo value.
ll invMod(ll x, ll mod)
{
    return fastPower(x, mod - 2, mod);
}

// Modular Addition
// @brief Adds two numbers under modulo.
// @param a The first number.
// @param b The second number.
// @return The result of (a + b) mod m.
ll add(ll a, ll b)
{
    return ((a % mod) + (b % mod)) % mod;
}

// Modular Multiplication
// @brief Multiplies two numbers under modulo.
// @param a The first number.
// @param b The second number.
// @return The result of (a * b) mod m.
ll mul(ll a, ll b)
{
    return ((a % mod) * (b % mod)) % mod;
}

// Modular Division
// @brief Divides two numbers under modulo using modular inverse.
// @param a The numerator.
// @param b The denominator.
// @return The result of (a / b) mod m.
ll divide(ll a, ll b)
{
    return mul(a, invMod(b, mod));
}

// Modular Subtraction
// @brief Subtracts two numbers under modulo.
// @param a The first number.
// @param b The second number.
// @return The result of (a - b) mod m.
ll sub(ll a, ll b)
{
    return ((((a % mod) - (b % mod)) % mod) + mod) % mod;
}

// Sieve of Eratosthenes
// @brief Generates all prime numbers up to n using the Sieve of Eratosthenes.
// @param n The upper limit for prime generation.
// @return A vector containing all prime numbers up to n.
// @note The Sieve of Eratosthenes is an efficient algorithm to find all primes up to a given limit.
vector<ll> sieve(ll n)
{
    vector<bool> prime(n + 1, true);
    for (ll i = 2; i * i <= n; i++)
    {
        if (prime[i] == true)
        {
            for (ll j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }

    // @note This part collects all prime numbers from the sieve.
    vector<ll> res;
    for (ll p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            res.push_back(p);
        }
    }
    return res;
}

// Euler's Totient Function
// @brief Calculates the number of integers up to n that are coprime with n.
// @param n The number to analyze.
// @return The value of Euler's Totient Function for n.
void PHI(int n)
{
    vector<int> phi(n + 1);
    phi[0] = 0, phi[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        phi[i] = i - 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= n; j += i)
        {
            phi[j] -= phi[i];
        }   
    }
}

// Factorial and Inverse Factorial Precomputation
// @brief Precomputes factorials and their modular inverses up to maxA.
// @param mod The modulo value.
// @note This function is used to efficiently calculate combinations and permutations.
ll fact[maxA + 1], invfact[maxA + 1];
void factorial(int mod)
{
    fact[0] = 1;
    for (int i = 1; i < maxA; i++)
        fact[i] = i * fact[i - 1] % mod;
    invfact[maxA - 1] = fastPower(fact[maxA - 1], mod - 2, mod);
    for (int i = maxA - 2; i >= 0; i--)
        invfact[i] = (i + 1) * invfact[i + 1] % mod;
}

int main()
{
    // Enter your code here
}
