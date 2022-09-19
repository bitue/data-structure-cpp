#include<bits/stdc++.h>
#include"ASHIK_STACK.h"
using namespace std ;


int precesion_calc (char c ){

    if(c == '^'){
        return 3 ;
    }
    else if (c=='*' || c=='/'){
        return 2 ;
    }
    else if (c=='+' || c=='-'){
        return 1 ;
    }
    else {
        return -1 ;
    }


}

string infix_prefix (string chk){

    string result ;

    stack<char> st ;
    // reverse it
    reverse(chk.begin() , chk.end());

    // need to apply the condition
    for(int i =0 ; i<chk.length(); i++){
        if(chk[i]>='0' && chk[i] <= '9') {
            result+=chk[i];

        }
        else if(chk[i] == ')') {
            st.push(chk[i]);
        }
        else if(chk[i] == '(' ) {
            while(!st.empty() && st.top()!= ')') {
                result+=st.top();
                st.pop();
            }
            if(!st.empty()) {
                st.pop();
            }

        }
        else {
            if(!st.empty() && precesion_calc(chk[i]) <= precesion_calc(st.top()) ) {
                result+=st.top();
                st.pop();
            }
            st.push(chk[i]);
        }
    }

    while(!st.empty()){
        result +=st.top();
        st.pop();
    }
    // make it reverse again
    reverse(result.begin(), result.end());

    return result ;
}

int main (){

    cout<<infix_prefix("(1+2)*(3*4)")<<endl;





}
