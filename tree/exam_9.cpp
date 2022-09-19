#include<bits/stdc++.h>
using namespace std; 

class Node {
    public :
        int value ;
        Node * left ;
        Node * right ;
        Node (int val ){
            this->left = NULL ;
            this->value = val ;
            this->right = NULL ;

        }

};


Node * create (){
    cout <<"Enter the value of the node -1 for null"<<endl;
    int x ;
    cin>>x ;
    if(x == -1 ) {
        return NULL ;
    }

    Node * newNode = new Node (x);
    cout<<"What will be the left child of this node of "<< x <<endl;
    newNode->left = create();
    cout<<"what will be the right child of this node of "<<x <<endl;
    newNode->right = create();

    return newNode ;
}

void inOrder (Node * root , string &chk){
    //base condition 
    if(root == NULL) return ;
  
    inOrder(root->left , chk);  // 1
    chk+=to_string(root->value) ;// 2
    inOrder(root->right , chk); // 3

}
string s ="";

bool is_unival(Node* root) {
    inOrder(root, s);
    for(int i=0 ; i<s.length()-1; i++){
        if(s[i]!=s[i+1]){
            return false ;
        }
    }
    return true ;

}

int main (){
    Node *root = create();
    bool res = is_unival(root);
    if(res){
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
  
   

}