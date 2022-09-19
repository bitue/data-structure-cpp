#include<bits/stdc++.h>
#include"ASHIK_STACK.h"
using namespace std ;




bool balance_parenthesis (string s) {
    Stack<char> st ;
    if(s[0]==')' || s[0]=='}' || s[0]==']') return false ;
    for(int i=0 ; i<s.length() ; i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
            st.push(s[i]);
        }
        if(s[i]==')'){
            if(st.Top()== '(' ){
                st.pop();
            }
            else {
                return false ;
            }
        }
         if(s[i]=='}'){
            if(st.Top()== '{' ){
                st.pop();
            }
            else {
                return false ;
            }
        }
         if(s[i]==']'){
            if(st.Top()== '[' ){
                st.pop();
            }
            else {
                return false ;
            }
        }
    }

    if(st.is_empty()) return true ;
    else return false ;
}


int main (){

    string chk ;
    cin>>chk ;
    bool res = balance_parenthesis(chk);
    if(res) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}


