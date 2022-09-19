#include<bits/stdc++.h>
using namespace std ;

void print (int n , int l ){
    int static c = 0;
 
    for(int i=0 ; i<n/2+c-1; i++){
        cout<<" ";

    }
    for(int i=0 ; i<l ;i++){
        cout<<"*";
    }
    cout<<endl;
    c++ ;
    if(c==n/2 ){
        c=0 ;
    }


   


}


int main (){
    int n ;
    cin>>n ;
    int arr [n]={0};
    int co =1 ;
    for(int i=0 ; i< n/2 ; i++){
        arr[i]= co ;
        arr[n-i-1] = co ;
        co+=2 ;
    }
    arr[n/2]= n ;

    for(int i =0 ; i<n ; i++){
        cout<<arr[i]<<endl;
    }

    for(int i=0 ; i<n ; i++){
        print(n, arr[i]);
    }

    

}