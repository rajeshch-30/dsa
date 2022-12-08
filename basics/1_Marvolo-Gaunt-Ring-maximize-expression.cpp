#include <iostream>
#include<climits>

using namespace std;
int main() {
    long long n,p,q,r,x =LLONG_MIN;
	cin>>n>>p>>q>>r;
	if(n<1){
		cout<<0;
		return 0;
	}
	
	long arr[n],pre_max[n],suf_max[n];
	for(int i =0 ; i<n ; i++){
     cin>>arr[i];
	}
	
	pre_max[0]= p*arr[0];
	for(int i = 1 ; i<n ; i++){
     pre_max[i] = pre_max[i-1] < p*arr[i] ? p*arr[i] : pre_max[i-1];
	}
	
	suf_max[n-1]= r*arr[n-1];
	for(int i = n-2 ; i>=0 ; i--){
     suf_max[i] = suf_max[i+1] < r*arr[i] ? r*arr[i] : suf_max[i+1];
	}
	
	for(int i = 0; i < n ; i++){
      long long temp;
		temp = pre_max[i] + q*arr[i] + suf_max[i];
		x = x > temp ? x : temp;	
	}
	cout<<x;
	
    return 0;
}

/*

Professor Dumbledore is helping Harry destroy the Horcruxes. He went to Gaunt Shack as he suspected a Horcrux to be present there. He saw Marvolo Gaunts Ring and identified it as a Horcrux. Although he destroyed it, he is still affected by its curse. Professor Snape is helping Dumbledore remove the curse. For this, he wants to give Dumbledore exactly x

drops of the potion he made.

Value of x
is calculated as maximum of p ∗ ai + q ∗ aj + r ∗ ak for given p,q,r and array _a_1, _a_2, ...a_n such that 1 ≤ i ≤ j ≤ k ≤ n. Help Snape find the value of x. Do note that the value of x

may be negative.

Input Format

    First line of input contains 4

integers n, p, q, r ( −109≤  p, q, r  ≤ 109 ,  1 ≤ n ≤105
).
Next line of input contains n space separated integers a1
, a2, a3...., an (−109≤ ai ≤ 109

    ).

Output Format

    Output a single integer the maximum value of p

∗ ai + q ∗ aj + r ∗ ak

    that can be obtained provided 1 ≤ i ≤ j ≤ k ≤ n.

Sample Input 0

5 1 2 -3
-1 -2 -3 -4 -5

Sample Output 0

12

Explanation

Selecting i = j = 1 and k = 5 gives the answer 12

.
Example
Input
5 1 2 -3
-1 -2 -3 -4 -5
Output
12

*/