// @brief: Binary Search on Number
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n && cin >> arr[i]; i++);

    while (q--)
    {
        int x;
        cin >> x;
        int l = 0, r = n - 1, ans = -1;
        bool found = false;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x)
            {
                ans = mid;
                found = true;
                break;
            }
            else if (arr[mid] < x)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << (ans == -1 ? "Not Found" : "Found") << endl;
    }
}