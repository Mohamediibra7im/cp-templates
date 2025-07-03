#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the index of the last element strictly less than the target.
 * @param nums A sorted array of integers.
 * @param n The size of the array.
 * @param target The value to search for.
 * @return The index of the last element < target, or -1 if no such element exists.
 */
int upper_bound(int nums[], int n, int target)
{
    int l = 0, r = n - 1, ans = -1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (nums[m] < target)
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return ans;
}

int main()
{
    int numbers[] = {2, 5, 8, 8, 11, 13, 13, 13, 19, 22};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    int target;

    // --- Example 1 ---
    target = 13;
    int ub_index = upper_bound(numbers, n, target);
    cout << "upper_bound index: " << ub_index << endl;

    // --- Example 2 ---
    target = 9;
    ub_index = upper_bound(numbers, n, target);
    cout << "upper_bound index: " << ub_index << endl;

    return 0;
}
