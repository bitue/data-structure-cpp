#include<bits/stdc++.h>
using namespace std ;

int binarySearch(int lb , int ub , int target , int *a){
    int co =1 ;
    while(ub>=lb){
        cout<<"Iteration no : "<<co<<endl;

        int mid = (ub +lb)/2 ;
        cout<<"Mid value : "<<a[mid]<<endl;

        if(a[mid] > target) {
            cout<<"a[mid] > target"<<endl;
            ub = mid-1 ;
            cout<<"lb : "<<lb<<" ub : "<<ub<<" target : "<<target<<" a[mid] : "<<a[mid]<<endl;
          
        }
        else if(a[mid]<target){
            cout<<"a[mid] < target"<<endl;
            lb= mid+1 ;
            cout<<"lb : "<<lb<<" ub : "<<ub<<" target : "<<target<<" a[mid] : "<<a[mid]<<endl;
           
        }
        else {
            cout<<"a[mid] == target"<<endl;
            cout<<"lb : "<<lb<<" ub : "<<ub<<" target : "<<target<<" a[mid] : "<<a[mid]<<endl;
            return mid ;
        }
        co++;
     

    }
   
    return -1 ;

   
}

int main (){

    int n ;
    cin>>n ;
    int arr[n];
    for(int i=0 ; i<n ; i++) cin>>arr[i];
   // sort(arr, arr+n);
    int res = binarySearch(0, n-1, 4, arr);
    cout<<"find index : "<<res<<endl;

}