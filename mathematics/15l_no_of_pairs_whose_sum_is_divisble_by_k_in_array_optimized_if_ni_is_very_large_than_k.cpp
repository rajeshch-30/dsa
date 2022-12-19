// only useful if n>>>>>k ;   because time complexity if n+k while in brute force its nsquare

#include <iostream>
using namespace std;

int main()
{
    int n, k, count = 0;
    cin >> n >> k;

    if (n < 2)
    {
        cout << "0";
        return 0;
    }

    int *arr = new int[n];
    int *rem_count = new int[k];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < k; i++)
    {
        rem_count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        rem_count[arr[i] % k]++;
    }

    count += ((rem_count[0]) * (rem_count[0] - 1)) / 2;

    for (int i = 1; i < k / 2 - 1; i++)
    {
        count += (rem_count[i]) * (rem_count[k - i]);
    }

    if ((k) % 2 == 0)
    {
        count += ((rem_count[k / 2]) * (rem_count[k / 2] - 1)) / 2;
    }
    else
    {
        count += ((rem_count[k / 2]) * (rem_count[k / 2 + 1]));
    }

    cout << count;

    return 0;
}

/*

Here we have been given an integer array 'Arr[N]' and an integer ‘k’. We have to find the total number of pairs (i, j) such that (Arr[i]+Arr[j]) is divisible by ‘k’ where i≠j, Arr[i]>=0.

Note: Both (i,j) and (j,i) are counted as the same 

Approach:

    Brute Force - Consider all the possible pairs of the array & count ones whose sum is divisible by ‘k’.
    Time complexity: O(N^2)
    Space complexity: O(1)
    Using the property of Modulus - The remainder of the sum is equal to the sum of remainders.
    (ai+aj)%k = (ai%k+aj%k)%k
    If ai%k = r1 & aj%k = r2
    then, (ai+aj)%k = (r1+r2)%k where 0<=r1,r2<=k-1
    The above equation will yield zero if, 

    r1 + r2 = 0
    It is possible when: r1 = 0 & r2 = 0
    r1 + r2 = k
    It is possible when: r1 = i & r2 = k-i where 1<=i<=k-1
    We can create an array cnt[k] to store the frequency of remainders from 0 to k-1. By the rule of products and the rule of combinatorics, the answer will be given as -

Answer

Time complexity: O(N+k)
Space complexity: O(k)

*/