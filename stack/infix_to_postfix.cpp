#include<bits/stdc++.h>
using namespace std ;

int postfix_res (string chk){

    stack<int> res ;
    for(int i =0 ; i<chk.length(); i++){
        if(chk[i]>='0' && chk[i]<='9'){
            res.push(chk[i]-'0');
        }
        else {
            int secondTop = res.top() ;
            res.pop();
            int firstTop = res.top() ;
            res.pop();

            if(chk[i] =='+') {
                res.push(firstTop + secondTop);
            }
              if(chk[i] =='-') {
                res.push(firstTop - secondTop);
            }
              if(chk[i] =='*') {
                res.push(firstTop * secondTop);
            }
              if(chk[i] =='/') {
                res.push(firstTop / secondTop);
            }
              if(chk[i] =='^') {
                res.push(pow(firstTop, secondTop));
            }
        }


    }

    return res.top();


}

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

string infix_to_postfix (string chk){

    string res ;
    stack<char> st ;
    for(int i =0 ; i<chk.length(); i++){
        if(chk[i]>='0' && chk[i]<= '9'){
            res+=chk[i];
        }
        else if(chk[i]=='(') {
            st.push(chk[i]) ;

        }
        else if(chk[i]==')') {
            while(!st.empty() && st.top() != '(') {
                  res+=st.top();
                  st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else {

            if(!st.empty() && precesion_calc(chk[i]) <= precesion_calc(st.top())) {
                res+=st.top();
                st.pop();
            }
            st.push(chk[i]);


        }
    }

    while(!st.empty()){
        res+=st.top();
        st.pop();
    }

    return res ;


}

int main (){

   string result = infix_to_postfix("(1+2)*(3+4)");
   cout<<result<<endl;
   cout<<postfix_res(result)<<endl;




}
