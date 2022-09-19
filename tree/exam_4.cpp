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

stack <int> st ;

void chk_left (Node *root){
    if(root==NULL ) {
        st.push(-1);
        return ;
    } 
    chk_left(root->left);
    st.push(root->value);
    chk_left(root->right);
    return ;

}

stack<int> lr ;

void chk_right (Node *root){

    if(root==NULL ) {
        lr.push(-1);
        return ;
    } 
    chk_right(root->right);
    lr.push(root->value) ;
    chk_right(root->left);
    return ;

}



bool isSymmetric(Node * root){
    Node * l = root ;
    Node * r = root ;
    if (root == NULL){
        return true ;
    }

    chk_left(l->left);
    chk_right(r->right);
   
    while(!st.empty() && !lr.empty()){
        if(st.top() != lr.top()){
            return false ;
        }
        st.pop();
        lr.pop();
    }
    return true ;

   
  

}


int main (){
    Node * root = create();
   bool res = isSymmetric(root);
   if(res){
        cout<<"is symetric"<<endl;
   }
   else {
        cout<<"Not symetric"<<endl;
   }
  

}