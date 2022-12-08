#include<iostream>
using namespace std;

int main(){
    int len, total_water_height = 0;
    cout<<"length of array : ";
    cin>>len;
    int arr[len];
    cout<<"entries of array : ";

    for(int  i=0 ; i<len ; i++){
        cin>>arr[i];
    }

    int pre_max[len], suf_max[len];
    
    pre_max[0] = arr[0];
    for(int i = 1 ; i < len ; i++){
        pre_max[i] = arr[i] > pre_max[i-1] ? arr[i] : pre_max[i-1];
    }

    suf_max[0] = arr[len-1];
    for(int i=len-2 ; i>=0 ; i--){
        suf_max[i] = arr[i] > suf_max[i+1] ? arr[i] : suf_max[i+1];
    }

    for(int i = 1 ; i < len-1 ; i++){  
        total_water_height += ( pre_max[i-1] < suf_max[i+1] ? pre_max[i-1] : suf_max[i+1] ) > arr[i] ? ( pre_max[i-1] < suf_max[i+1] ? pre_max[i-1] : suf_max[i+1] ) - arr[i] : 0 ;
        
    }

    cout<<total_water_height;

    /*
    
    Lecture 5: Histogram Problem

In this lecture, we will discuss the Rainwater collection problem. Here, we have been given an integer array ‘Arr[N]’ containing the heights of 'N' pillars. We have to find the total height of the water column trapped between the pillars after the rainfall. 

Approach:

    Which pillars will hold water on their tops?

Histogram

It can be seen in the above illustration, only the pillars with a larger pillar in their left and right neighbourhood can hold water. 

    Will the boundary pillars hold water?
    No, since there is no supporting pillar on the other side. 
    Solution - If we know the largest left and right neighbours for each pillar then we can find the amount of water that it can hold on its top. 

Amount of water on the top of pillar 'i' = max(0, (min(largest left neighbour, largest right neighbour) - height of pillar i))

    Implementation - Can you think of how to apply a pre-computation technique that was taught in the previous lecture?
    For pre-processing, we can calculate the prefix and suffix max for each pillar and use it to find the amount of water they will hold on their top.

    Time complexity: O(N)
    Space complexity: O(N)
    */
}