#include<bits/stdc++.h>
using namespace std ;

int main (){
    int t ;
    cin>>t ;
    while (t--){
        string s1 ;
        string s2 ;
        cin>>s1 >>s2 ;
        int co1 =0 ;
        int co2 = 0 ;
        int i =0 ;
        int j =0 ;
        while(s1[i]=='X'){
            co1++;
            i++;
        }
        i--;
        while(s2[j]=='X'){
            co2++;
            j++;
        }
        j--;
     
        int val1 =0 ;
       
        if(s1[i+1]=='L'){
            val1+=1000;
            val1+=co1;
          

        }
        else if (s1[i+1]=='M'){
            val1+=500 ;
            val1+=co1 ;
        }
        else {
            val1+=100 ;
            val1-=co1 ;
        }

        int val2 =0 ;
        
        if(s2[j+1]=='L'){
            val2+=1000;
            val2+=co2 ;
          

        }
        else if (s2[j+1]=='M'){
            val2+=500 ;
            val2+=co2 ;
        }
        else {
            val2+=100 ;
            val2-=co2;
        }

      


        if(val1>val2){
            cout<<">";
        }
        else if (val1 < val2){
            cout<<"<";
        }
        else {
            cout<<" ";
        }



    
        
    }
}