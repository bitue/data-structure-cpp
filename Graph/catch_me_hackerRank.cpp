#include<bits/stdc++.h>
using namespace std ;

int co =0 ;

class Node {
    public :
        int value ;
        Node *left ;
        Node *right ;
        Node (int val){
            this->value = val ;
            this->left = NULL ;
            this->right = NULL ;       
        }  
};

bool checkPalindrone (string k ){
    for(int i =0 ; i<k.length()/2 ; i++){
        if(k[i]!= k[k.length()-i-1]){
            return false ;
        }
    }
    return true ;


}

void preOrder (Node *root,string res, string in) {
   
    // if(root->left == NULL && root->right == NULL){
    //     cout<<res<<endl;
    //     bool ans =  checkPalindrone(res);
    //     if(ans == true){
    //         co++;

    //     }

    // }
    if(root == NULL){
        //cout<<res<<endl;
        bool ans =  checkPalindrone(res);
        if(ans == true){
            co++;

        }
        
        return ;
    }
    res+= in[root->value];
   
    preOrder(root->left, res, in);
    //cout<<res<<endl;
       
    preOrder(root->right, res, in);

}









int main (){
   
    string input_str ;
    cin>>input_str ;
    int s ;
    cin>>s ;
    Node * root = new Node (s);
    queue<Node *> Q ;
    Q.push(root);
    while(!Q.empty()){
        Node *curr = Q.front();
        Q.pop();
        int l , r ;
        cin>>l>>r ;
        // overall two node is NULL 
        Node *n1 = NULL ;
        Node *n2 = NULL ;
        // if value is present then create the node else NULL 
        if(l!= -1) n1 =new Node(l);
        if(r!=-1) n2 = new Node(r);
        // need to assign this 
        curr->left = n1 ;
        curr->right = n2 ;


        // need to push it the queue if is is not NULL 
        if(n1 != NULL) Q.push(n1);
        if(n2 != NULL) Q.push(n2);

    }

    string add_str ="";
    

    preOrder(root, add_str , input_str );
   // preOrder(root->right, add_str , input_str );


    cout<<co/2<<endl;

   


}