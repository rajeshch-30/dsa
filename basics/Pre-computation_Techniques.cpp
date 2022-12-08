#include <iostream>
using namespace std;

int main()
{
    int n, querie;
    cout << "Enter size of array : ";

    cin >> n;
    int arr[n];

    cout << "Enter element of array : ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int pre_sum[n];
   pre_sum[0] = arr[0];
   for(int i=1;i<n;i++){
    pre_sum[i] = pre_sum[i-1] + arr[i];
   }

// for(int i = 0 ; i < n ; i++){
//     cout<<pre_sum[i]<<"\t";
// }


    cout << "Enter number of queries : ";
    cin >> querie;

    int que_index1[querie];
    int que_index2[querie];
    int sum[querie];


    for(int i = 0 ;i<querie ; i++){
         cout<<"Enter index1 for querie_"<<(i+1)<<" : ";
         cin>>que_index1[i];

         cout<<"Enter index2 for querie_"<<(i+1)<<" : ";
         cin>>que_index2[i];

        // pre_sum[que_index1[i-1]] =  i-1<0 ? 0 : pre_sum[que_index1[i-1]] ;
        if(que_index1[i] == 0){
             sum[i] = pre_sum[que_index2[i]];
        }
        else{
        sum[i] = pre_sum[que_index2[i]] - pre_sum[que_index1[i]-1];
        }
    }


    for(int i = 0 ; i < querie ; i++){
    cout<<sum[i]<<"\t";
    }
    /*    brute force 

    for(int i = 0 ; i<querie; i++){
        sum[i] = 0 ;
        for(int j = que_index1[i] ; j <= que_index2[i] ; j++){
             sum[i] += arr[j] ;
        }
            cout<<sum[i]<<endl;
    }

    */

   
   return 0 ;

}