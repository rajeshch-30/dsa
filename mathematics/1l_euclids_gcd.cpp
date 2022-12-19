#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if (b > a)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b == 0)
    {
        cout << a;
        return 0;
    }

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    cout << a;
    return 0;
}

/*

GCD (Greatest Common Divisor) or HCF (Highest Common Factor) of two numbers ‘a’ & ‘b’ (a,b >=0) is the largest number that divides both ‘a’ & ‘b’.
Eg. GCD(10,15) = 5

How to calculate GCD?

Approach:

Brute Force - Since 1 <= GCD(a,b) <= min(a,b)   ; a, b > 0
We can create a for loop from min(a,b) to 1 and check if the number is divisible by both ‘a’ and ‘b’.
Time complexity: O(min(a, b))
Space complexity: O(1)
Euclid’s Division Lemma - We can use the concept of repeated divisions to find the GCD of two numbers ‘a’ and ‘b’.
Here, the divisor = max(a, b) and dividend = min(a, b). We repeatedly perform division operations until the remainder becomes zero.

For a>=b, after every division,
divisor = a%b
dividend = b

Time complexity: O(log2(max(a,b))
Space complexity: O(1)

Note: GCD of any non-zero number with zero is the number itself.
*/
