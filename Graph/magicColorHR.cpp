#include<bits/stdc++.h>
using namespace std ;

string chk ;



int main (){
    int t ;
    cin>>t ;
    while(t--){
        stack<char> st ;
        int n ;
        cin>>n ;
        cout<<"Y"<<endl;
        for(int i =0 ; i<n ; i++){
            char c ;
            cin>>c ;
            if(!st.empty()){
               chk ="";
              
                char a = st.top();
               
                if(a==c){
                    st.pop();
                    chk="";
                }
                else if(a=='Y' || a =='P'|| a =='C'){
                    st.push(c);

                }
                else{
                    chk+=a ;
                    chk+=c ;
                    if(chk =="RG" || chk=="GR"){
                        st.pop();
                        while(st.top()=='Y'){
                            st.pop();
                        }
                        st.push('Y');
                        chk="";
                    }
                    else if(chk =="RB" || chk=="BR"){
                        st.pop();
                        while(st.top()=='P'){
                            st.pop();
                        }
                        st.push('P');
                        chk="";
                    }
                    else if(chk =="BG" || chk=="GB"){
                        st.pop();
                        while(st.top()=='C'){
                            st.pop();
                        }
                        st.push('C');
                        chk="";
                    }

                }
            }
            else {
                st.push(c);

            }
           

          
        }

        while(!st.empty()){
            cout<<st.top();

        }
        cout<<endl;


    }

    
}