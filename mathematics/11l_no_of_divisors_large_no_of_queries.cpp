#include <iostream>
using namespace std;

int main()
{
    int n, maxn;
    cin >> n >> maxn;

    int primes[maxn + 1], spf[maxn + 1];

    for (int i = 1; i < maxn + 1; i++)
    {
        primes[i] = 1;
        spf[i] = -1;
    }

    primes[1] = 0;
    for (int i = 2; i * i <= maxn; i++)
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

    int querie;
    for (int i = 0; i < n; i++)
    {   

        int count = 0,divisors = 1;
        cin >> querie;
        int temp = spf[querie];
        while (spf[querie] != -1)
        {

            count++;

            querie = querie / spf[querie];

            if (temp != spf[querie])
            {
                divisors *= (count + 1);
                count = 0;
                temp = spf[querie];
            }
        }
        if (querie != 1)
        {
            divisors *= 2;
        }
        cout << divisors << "\n";
    }

    return 0;
}

/*

In continuation with the previous lecture on Fast Factorization, we will learn how to efficiently count the factors of a number ‘N’ by using the Rule of Products.

We have been given an integer, N = (P1)^c1(P2)^c2(P3)^c3..(Pi)^ci; where P1, P2, P3,.., Pi are prime numbers, then print the value of c1 + c2 + c3 +..+ ci.

Approach: Since we know that any factor of N consists of the product of some or all the prime factors of N. And for every prime factor Pi with power ci, we have (ci+1) different powers to consider in the product. 

Therefore by Rule of Products, total number of divisors = (c1+1)(c2+1)(c3+1)..(ci+1).
 */