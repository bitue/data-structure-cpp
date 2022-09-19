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

stack <int> st ;
stack <int> lt ;

void inOrder_1 (Node * root) {
    
    if(root == NULL){
        return ;
    }
    inOrder_1(root->left);
    st.push(root->value);
    
    inOrder_1(root->right);
    

}
void inOrder_2 (Node * root) {
    
    if(root == NULL){
        return ;
    }
    inOrder_2(root->left);
    lt.push(root->value);
    
    inOrder_2(root->right);
    

}

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


bool isSame (Node *root1 , Node * root2) {
    
    inOrder_1 (root1);
    inOrder_2 (root2);
    while(!st.empty() && !lt.empty()){
        if(st.top() != lt.top()){
            return false ;
        }
        st.pop();
        lt.pop();
    }
    return true ;


}

int main (){
    cout<<"Root 1 :"<<endl;

    Node * root1  = create();
    
    cout<<"Root 2 :"<<endl;

    Node * root2 = create();

    bool res  = isSame(root1, root2);
    if(res) {
        cout<<"same "<<endl;
    }
    else {
        cout<<"Not"<<endl;
    }

  //  inOrder(root);



}