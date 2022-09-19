#include<bits/stdc++.h>

using namespace std ;

int prefixNotationToResult (string s){

    stack<int> st ;


    for(int i= s.length()-1 ; i>=0 ; i--){
        // 0-9 it could be value

        if(s[i]>='0' && s[i]<='9'){

            st.push(s[i]-'0');
              cout<<3<<endl;

        }
        else {

            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(s[i]=='+'){


                    st.push(a+b);

            }
            else if(s[i] =='-'){


                    st.push(a-b);


            }
             else if(s[i] =='*'){


                    st.push(a*b);


            }
            else if(s[i] =='/'){


                    st.push(a/b);


            }
            else if(s[i] =='^'){


                    st.push(pow(a, b));


            }

        }






    }

    return st.top();





}

int main (){

    cout<<prefixNotationToResult("+9*3/84")<<endl;

}
