#include<bits/stdc++.h>
#include"Queue_Temp.h"
using namespace std ;
int main (){
   typedef pair<int ,int> my_pair;
    Queue <my_pair> que ;
    for(int i=0 ; i<5 ; i++){
        int f ;
        int s ;
        cin>>f>>s ;
        que.push(make_pair(f, s));

        
    }

    while(!que.empty()){
        my_pair res = que.pop();
        cout<<res.first<<" | "<<res.second<<endl;
    }


}