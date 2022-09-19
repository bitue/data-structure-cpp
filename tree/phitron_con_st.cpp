#include<bits/stdc++.h>
using namespace std ;

int main (){
    int n ;
    cin>>n ;
    char a [n];
    for(int i=0 ; i<n ; i++){
        cin>>a[i];
    }

    int curr [n]={0};
    int co_p =0 ;
    int co_m =0 ;
    bool plus = false ;
    bool min = false ;
    for(int i=0 ; i<n ; i++){
        if(a[i]=='+' && !plus ){
            plus = true ;
            min = false ;
            co_p =1 ;
            curr[i]= co_p ;


        }
        if(a[i]=='-' && !min ){
            min = true ;
            plus = false ;
            co_m = 1 ;
            curr[i]= co_m ;


        }

        if(a[i]=='+' && plus){
           
            curr[i]= co_p ;
             co_p ++ ;
            
        }
        if(a[i]=='-' && min){
          
            curr[i]= co_m ;
              co_m ++ ;
        }



    }

    // for(int i=0 ; i<n ; i++){
    //     cout<<curr[i]<<" ";
    // }

    int res = 1 ;

    for(int i=0 ; i<n ; i++){
        res = max(curr[i], res);
    }

    cout<<res;


  
}