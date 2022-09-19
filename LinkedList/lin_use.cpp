#include<bits/stdc++.h>
#include"stack_linear_link_list.h"
using namespace std ;

int main (){
    Stack st ;
    st.push(11);
    st.print_all();
    st.push(12);
    st.print_all();
   int res =  st.pop();
   cout<<res<<endl;
    st.print_all();
    st.push(13);
    st.print_all();
    st.push(14);
    st.print_all();
    st.pop();
    st.print_all();
    st.pop();
    st.print_all();

}