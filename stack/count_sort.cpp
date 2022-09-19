#include<bits/stdc++.h>
using namespace std ;

void print_arr(int *a , int n ){
    cout<<endl;
    for(int i=0 ; i<n ; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main (){
    int n ;
    cin>>n ;
    int arr[n];
    for(int i=0 ; i<n ; i++) cin>>arr[i];

    // step 1: find the max value ;
    int max_value = arr[0];
    for(int i=1 ; i<n ; i++){
        max_value = max(max_value, arr[i]);
    }
    // step 2: initialize a frequency array 
    int curr[max_value+1]={0};
    // step 3: make it frequency array 

    for(int i=0 ; i<n ; i++){
        curr[arr[i]]++;
    }
    cout<<"print the frequency array "<<endl;
    print_arr(curr, max_value+1);
    // step 4 : make the curr to prefix sum array 
    int init_sum = curr[0];
    for(int i=1 ; i<max_value+1 ; i++){
        init_sum += curr[i];
        curr[i]= init_sum ;
    }
    cout<<"print the frequency array of prefix sum "<<endl;
    print_arr(curr, max_value+1);
    //step 5 : make a result arr length of main array length 
    int result_arr[n]={0};

    for(int i=n-1 ; i>=0 ; i--){  // step 6 : reverse order traverse the main arr
        int k = arr[i]; // step 7 : k = arr[i]  
        cout<<"before the cumalitive sum"<<endl;
        print_arr(curr, max_value+1);
        curr[k]--; // prefix_sum frequency array kth value decrease 
        cout<<"after the cumalitive sum"<<endl;
        print_arr(curr, max_value+1);

        result_arr[curr[k]]= arr[i]; // prefix_sum kth value of the index of result arr will be assigned by arr[i]
        
        cout<<"Now the present condition the result arr"<<endl;
        print_arr(result_arr, n);


    }

    cout<<"final condition after counting sort "<<endl;
    print_arr(result_arr, n);
}