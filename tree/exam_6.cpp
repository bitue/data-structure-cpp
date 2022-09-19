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

Node * invert_tree(Node *root){
    Node * temp = root ;
    Node * l, *r ;
    if(root== NULL) {
        return root ;
    }
    if(root->left){
       invert_tree(root->left);

    }
    if(root->right){
       invert_tree(root->right);
    }
    swap(root->left, root->right);
    return root ;

}

void inOrder (Node * root , string &chk){
    //base condition 
    if(root == NULL) return ;
  
    inOrder(root->left , chk);  // 1
    chk+=to_string(root->value) ;// 2
    inOrder(root->right , chk); // 3

}

int main (){
    Node * root = create();
    Node * newRoot = invert_tree( root) ;
    string chk ="";
   
    inOrder(newRoot, chk);
  //  inOrder(newRoot, phk);
    cout<<chk<<endl;
  //  cout<<phk<<endl;


}