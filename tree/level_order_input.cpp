#include<bits/stdc++.h>
using namespace std ;

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


void inOrder (Node *root){
    if(root==NULL) return ;
    inOrder(root->left);
    cout<<root->value<<" ";
    inOrder(root->right);
}

int main (){
    Node *root = NULL ;

 
    int a ;
    cin>>a ;
    root = new Node (a);
    queue<Node *> q ;
    q.push(root);
    while(!q.empty()){
        Node * curr = q.front();
        q.pop();
        int n1 , n2 ;
        cin>>n1>>n2 ;
        Node * l = NULL;
        Node * r = NULL ;
        if(n1!= -1) l = new Node(n1);
        if(n2!=-1) r = new Node(n2);
        curr->left = l ;
        curr->right = r ;
        if(l!= NULL) q.push(l);
        if(r!= NULL) q.push(r);


        }



    inOrder(root);




}