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

int max_depth (Node *root){
    if(root==NULL){
        return 0 ;
    }
    int l =  max_depth(root->left);
    int r =   max_depth(root->right);
    int k = max(l,r) + 1 ;
    return k;

}

int main (){
    Node *root = create();
    int res = max_depth(root);
    cout<<res<<endl;
    
}