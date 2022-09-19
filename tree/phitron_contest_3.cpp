#include<bits/stdc++.h>
using namespace std ;

int main (){
    stack <int> st ;
   
    int n ;
    cin>>n ;
    int arr[n];

    for(int i=0 ; i<n ; i++){
       cin>>arr[i];

    }

    for(int i=0 ; i<n ; i++){
        st.push(arr[i]);
    }
    for(int i=0 ; i<n ; i++){
       int res = st.top();
       st.pop();
       cout<<res<<" ";
    }
}