#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
ll pref_sum[N];
int a[N];

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        pref_sum[i] = pref_sum[i - 1] + a[i];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << pref_sum[r] - pref_sum[l - 1] << endl;
    }

}

// used to solve problems like:
// https://cses.fi/problemset/task/1646