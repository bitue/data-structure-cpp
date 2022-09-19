#include<bits/stdc++.h>
using namespace std ;


int main (){
     map<int , int > mp ;
    int n ;
    cin>>n ;
    int arr [n];
    int a [n];
    for(int i =0 ; i<n ; i++) {
        cin>>arr[i];
        cin>>a[i];
    } 
    for(int i =0 ; i<n ; i++){
        mp[i]= arr[i];
    }
    sort(arr , arr+n);
    cout<<arr[0]+arr[1];
    cout<<mp.(arr[0]);
}