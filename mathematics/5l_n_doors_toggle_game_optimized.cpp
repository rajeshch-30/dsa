#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;

    int sq = sqrt(n);
    cout<<sq;            // only need count of perfect squares whose square is smaller than or equals to n;

/*
    for (int i = 1; i < n; i++)
    {
        int sq = sqrt(i);
        if (sq * sq == i) // finally gate will be open if factors of i are odd
        {
            count++;
        }
    }

    cout << count;

*/
    return 0;
}

/*

There are N doors that are initially closed. There are N rounds and In every round ‘i’, we have to toggle the states of all the doors which are a multiple of ‘i’. Find the number of doors open at the end of the game.

Approach: We know that a door will be toggled only if it is divisible by ‘i’. This implies that a door will be toggled as many times as the number of factors it has.
Since we know that a perfect square has an odd number of factors while an imperfect square has an even number of factors. Therefore, only the state of those doors will change that are a perfect square or the doors having an odd number of factors. 

Answer = (int)sqrt(N)
*/