#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b > a)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b == 0)
    {
        return a;
    }

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int lcm(int a, int b)
{
    int flcm = (a * b) / gcd(a, b);
    return flcm;
}

int main()
{
    int n, lm;    // lm = lcm;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // lcm*gcd = a*b;

    lm = lcm(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        lm = (lm * (arr[i])) / gcd(lm, arr[i]);  // lcm(a,b,c) = lcm(lcm(a,b),c) = (lcm(a,b)*c)/gcd(lcm(a,b),c);
    }

    cout << lm;

    return 0;
}

/*

LCM (Least Common Multiple) of two numbers, ‘a’ and ‘b’ is the smallest number which is divisible by both ‘a’ & ‘b’.
Eg. LCM(10,15) = 30

How to calculate LCM of two numbers?

Approach:

    Brute Force - Since max(a, b) <= lcm(a,b) <= a*b  ; a,b>0
    Therefore, we can iterate from the minimum to the maximum possible value of LCM to find the LCM.
    Time complexity: O((a*b)-max(a,b))
    Space complexity: O(1)
    
    Using Mathematical Relation - HCF * LCM = a * b
    Hence, LCM = (a*b)/HCF 

How to calculate the LCM of three numbers?

LCM(a, b, c) = LCM(LCM(a, b), c))
                     = LCM(LCMab, c)                      
                     = (LCMab* c)/GCD(LCMab, c)

Similarly, we can calculate the LCM of the elements of an array ‘Arr[N]’

int LCM = Arr[0];
for(int i = 1; i < N; i++){
     LCM = (LCM*Arr[i])/GCD(LCM, Arr[i]);
}
*/