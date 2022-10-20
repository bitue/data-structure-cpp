#include<bits/stdc++.h>
using namespace std ;


int main (){
    // char c , chk ;
    // string res ;
    int t ;
    cin>>t ;
    for(int j=0 ; j<t ; j++){
        int l ; 
        cin>>l ;
        string s ;
      
        cin>>s ;
       // cout<<s<<endl;
        stack<char> st ;

        st.push(s[0]);

        // for(int i=1 ; i<s.length(); i++){
            
        // }
        cout<<s.length()<<endl;

        for(int i =1 ; i<s.length(); i++){
            //cout<<"Y"<<endl;
          
               char chk = s[i];
               char c = st.top();
               string res = "";
                res+=chk;
                res+=c ;
               // cout<<res<<"res"<<chk<<"chk"<<endl;
             //  cout<<s[i]<<st.top()<<endl;
             cout<<"Y"<<endl;

                if(res == "RG" || res =="GR"){
                    res ="";
                    st.pop();
                    if(!st.empty()){
                        if(st.top()=='Y'){
                        st.pop();
                        }
                        else {
                        st.push('Y');

                        }

                    }
                  
                  
                }
                else if(res == "BG" || res =="GB"){
                    res ="";
                    st.pop();

                    //  if(st.top()=='C'){
                    //     st.pop();
                    // }
                    // else {
                    //     st.push('C');

                    // }
                     if(!st.empty()){
                        if(st.top()=='C'){
                        st.pop();
                        }
                        else {
                        st.push('C');

                        }

                    }
                  

                }
                else if(res=="RB" || res=="BR"){
                    res="";
                    st.pop();
                    // if(st.top()=='P'){
                    //     st.pop();
                    // }
                    // else {
                    //     st.push('P');

                    // }
                    if(!st.empty()){
                        if(st.top()=='P'){
                        st.pop();
                        }
                        else {
                        st.push('P');

                        }

                    }
                  
                }
                else if(c==chk){
                    st.pop();
                    res="";


                }
                else {
                    st.push(c);
                    res="";
                }
            
        }

        while(!st.empty()){
            cout<<st.top();
            st.pop();
        }
        cout<<endl;
    }
}