#include <iostream>
using namespace std;

int main()
{
    int n, maxn;
    cin >> n >> maxn;
    // --------------------------------------------
    // int querie[n];
    //--------------------------------------------
    int primes[maxn + 1], spf[maxn + 1];
    // primes[] keep track of of prime numbers less than maxn+1
    // spf[] keep track of smallest prime factor of every number less than maxn+1
    // -------------------------------------------------------------
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> querie[i];
    // }
    // ---------------------------------------------------------------

    for (int i = 1; i < maxn + 1; i++)
    {
        primes[i] = 1;
        spf[i] = -1;
    }

    // sieve of ertosthenes

    primes[1] = 0;
    for (int i = 2; i * i <= maxn; i++) // used to avoid use of cmath library
    {
        if (primes[i] == 1)
        {
            for (int j = i; i * j <= maxn; j++)
            {
                if (primes[i * j] == 1)
                {
                    primes[i * j] = 0;
                    spf[i * j] = i;
                }
            }
        }
    }
    // -------------------------------------------------------------------------------
    // for (int i = 0; i < n; i++)
    // {
    //     // cin >> querie;
    //     while (spf[querie[i]] != -1)
    //     {
    //         cout << spf[querie[i]] << " ";
    //         querie[i] = querie[i] / spf[querie[i]];
    //     }
    //     if (querie[i] != 1)
    //     {
    //         cout << querie[i];
    //     }
    //     cout << "\n";
    // }
    // ----------------------------------------------------------------------------------
    int querie;
    for (int i = 0; i < n; i++)
    {
        cin >> querie;
        while (spf[querie] != -1)
        {
            cout << spf[querie] << " ";
            querie = querie / spf[querie];
        }
        if (querie != 1)
        {
            cout << querie;
        }
        cout << "\n";
    }

    return 0;
}


/*

In this lecture, we will learn the concept of fast factorisation by finding the prime factorisation of Q queries.

Print the prime factorisation of n1, n2, n3,.., nq (ni<=N).

Approach:

    Using Sieve of Eratosthenes - Create an array of prime numbers (<=N) using the Sieve of Eratosthenes. Iterate through the array to find all the prime factors of ni.
    Time complexity: O(Nlog(logN)+(number of primes x (logN)))
    Space complexity: O(N)
    Using Smallest Prime Factor (SPF) - This method helps in getting rid of useless prime numbers by finding the smallest prime factor of all the numbers till N. We implement this algorithm by slightly modifying the code of the sieve of Eratosthenes.
    Time complexity: O(NloglogN + QlogN)
    Space complexity: O(N) 
    */