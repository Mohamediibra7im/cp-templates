#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the index of the first element greater than or equal to the target.
 * @param nums A sorted array of integers.
 * @param n The size of the array.
 * @param target The value to search for.
 * @return The index of the first element >= target, or -1 if all elements are smaller.
 */
int lower_bound(int nums[], int n, int target)
{
    int l = 0, r = n - 1, ans = -1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (nums[m] >= target)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
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

    int lb_index = lower_bound(numbers, n, target);
    cout << "lower_bound index: " << lb_index << endl;

    // --- Example 2 ---
    target = 9;

    lb_index = lower_bound(numbers, n, target);
    cout << "lower_bound index: " << lb_index << endl;

    return 0;
}
