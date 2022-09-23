#include<bits/stdc++.h>
using namespace std ;

int main (){
    int t ;
    cin>>t ;
    while(t--){
        int n , c ;
        cin>>n>>c ;
        int k =0 ;
        int a[n];

        for(int i=0 ; i<n ; i++){
            cin>>a[i];

        }
        for(int i =0 ; i<n ; i++){
            k+=2*a[i];
           
        }
        if(k<c){
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
}