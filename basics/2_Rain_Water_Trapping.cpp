#include <iostream>
using namespace std;
int main()
{
    long long n, ans = 0;
    cin >> n;
    long long h[n];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    long long pre_max[n], suf_max[n];

    pre_max[0] = h[0];
    for (int i = 1; i < n; i++)
    {
        pre_max[i] = pre_max[i - 1] > h[i] ? pre_max[i - 1] : h[i];
    }

    suf_max[n - 1] = h[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suf_max[i] = suf_max[i + 1] > h[i] ? suf_max[i + 1] : h[i];
    }

    for (int i = 1; i < n - 1; i++)
    {
        int deciding_height = pre_max[i - 1] >= suf_max[i + 1] ? suf_max[i + 1] : pre_max[i - 1];
        ans += deciding_height > h[i] ? deciding_height - h[i] : 0;
    }

    cout << ans;

    return 0;
}

/*
Given n non-negative integers representing height h of n bars, where the width of each bar is 1

, compute how much water it can trap after raining.

Diagram for Example 1

Input Format

Line 1 represents total number of bars denoted n
. Line 2 represents hi of total n

bars.

Output Format

Print the total units of water stored due to these n

bars

Example 1:

Input

12

0 1 0 2 1 0 1 3 2 1 2 1

Output

6

Explanation

The above figure represents the diagram for Example 1. Here, 6 units of water is trapped between bars of width 1.

Example 2:

Input

6

4 2 0 3 2 5

Output

9

Constraints

    1

≤ n ≤ 105
0
≤ hi ≤ 109

Example
Input
6
4 2 0 3 2 5
Output
9

*/