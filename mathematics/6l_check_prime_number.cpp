#include <iostream>
#include<cmath>
using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;

    if( n<2)
    {
        cout<<"not prime";
        return 0;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            count++; 
            break;
        }
    }
    if (count == 0)
    {
        cout << "prime";
    }
    else
    {
        cout << "not prime";
    }

    return 0;
}


/*

If a number ‘x’(>1) has only two divisors - 1 and ‘x’ ie. the number itself then it is called a Prime Number. we will learn how to check the primality of any number ‘N’ in O(N) time complexity.   

Approach:

    Brute Force - Count the factors of ‘N’ by iterating from 1 to 'N'. It will be a prime number only if the count is 2.
    Time complexity: O(N)
    Optimised Brute Force - Since we know that the factors of ‘N’ are symmetric about √N. Therefore, we can iterate from 1 to √N and count the total number of factors of ‘N’. It will be a prime number if the count is 1.
    Time complexity: O(√N ) 
    
    */