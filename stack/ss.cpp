#include<bits/stdc++.h>
#include"ASHIK_STACK.h"
using namespace std ;

int main (){
    // Push(x+y), Push(y+z), Pop(), Push(y*z), Push(x*y), Pop(), Pop()
    Stack<int> st ;
    int x = 8 ;
    int y= 11 ;
    int z = 19 ;
    st.push(x+y);
     cout<<"Show status "<<endl;
    st.display();
    cout<<endl;
    st.push(y+z);
        cout<<"Show status "<<endl;
      st.display();
       cout<<endl;
    st.pop();
     cout<<"Show status "<<endl;
      st.display();
       cout<<endl;
    st.push(y*z);
     cout<<"Show status "<<endl;
      st.display();
       cout<<endl;
    st.push(x*y);
     cout<<"Show status "<<endl;
      st.display();
       cout<<endl;
    st.pop();
     cout<<"Show status "<<endl;
      st.display();
       cout<<endl;
    st.pop();
     cout<<"Show status "<<endl;
      st.display();
       cout<<endl;

}

