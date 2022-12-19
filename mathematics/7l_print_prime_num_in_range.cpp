#include <iostream>
#include <cmath>

using namespace std;

int check_prime(int n)
{   
    int count = 0;
    if (n < 2)
    {
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
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{
    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        if(check_prime(i))
        {
            cout<<i<<" ";
        }
    }

    return 0;
}


/*

In this lecture, we will learn how to find all the prime numbers in the range of 1 to N using the Sieve of Eratosthenes. It is the most efficient pre-processing technique to find all the prime numbers less than 10^7.
Note: It is not advisable to use it if N>10^7 or if the range is not starting from 1. 

Approach:

    Brute Force - We can iterate from 1 to N and can check the primality of each number individually.
    Time complexity: O(N√N)
    Space complexity: O(1)
    Using Sieve of Eratosthenes - In this technique, we create a boolean array to represent the state of the numbers from 1 to N. Initially we assume each one of them to be prime and we iterate from 2 to N marking all their divisors to be non-prime in the boolean array.
    We follow this process only for the numbers that are marked as prime in the boolean array. At the end, we will be left with the true nature of the numbers in the boolean array.
    Time complexity: N/2+N/3+N/5+N/7+...+=N[1/2+1/3+1/5+1/7+...+] = O(Nlog(logN))
    Space complexity: O(N)
    
    */