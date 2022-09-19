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

Node * insertion_BST(Node * root , int value ) {
    //make node
    Node * newNode = new Node (value);
    if(root == NULL){
        root = newNode ;
        return root;
    }

    else {
        if(value >root->value){
         root->right = insertion_BST(root->right, value);

        }
        else if(value < root->value){
            root->left = insertion_BST(root->left , value);

        }
    }

    return root ; 
}

void inOrder (Node * root ){
    //base condition
    if(root == NULL) return ;

    inOrder(root->left );  // 1
    cout<<root->value<<" ";
    inOrder(root->right); // 3

}

Node * inOrderSucc (Node * root){
    Node * curr = root ;
    while(curr->left != NULL){
        curr = curr->left ;
    }

    return curr ;

}

Node * search_BST (Node *root , int value ) {
    if(root== NULL) {
        return NULL ;
    }
    if(root->value == value ) {
        cout<<root->value<<" ->";
        return root ;
    }
    else if (value > root->value){
        cout<<root->value<<" ->";
        return search_BST(root->right, value);
    }
    else {
        cout<<root->value<<" ->";
        return search_BST(root->left, value );
    }
}


Node * delete_BST (Node *root , int val){
    // iteration to go this node 
    if(val >root->value){
        root->right = delete_BST(root->right, val);
    }
    else if(val<root->value){
        root->left = delete_BST(root->left, val);
    }
    else {
        // need to implement the case 
        // case 1 -> no child one child 
       

        if(root->left == NULL){
            Node *temp = root->right ;
            free(root);
            return temp ;
        }
        else if(root->right == NULL){
            Node *temp = root->left ;
            free(root);
            return temp;
        }
        // case 2 -> two child 
        else {
            Node * temp = inOrderSucc(root->right) ;
            root->value = temp->value ;
           //  free(temp); 
           root->right  = delete_BST(root->right ,temp->value);
           
        }

       
    }
    return root ;
}


int main (){
    int n ;
    cin>>n ;
    Node * root = NULL ;
    for(int i =0 ; i<n ; i++){
        int val ;
        cin>>val ;
        root = insertion_BST(root, val);


    }
    // cout<<"Before "<<endl;
    // inOrder(root);
    // cout<<"search  key enter here "<<endl;
    // int key ;
    // cin>>key ;

    // if(search_BST(root, key) != NULL){
    //     cout<<"Yes ";
    // }
    // else {
    //     cout<<"No"<<endl;
    // }

    cout<<"Before delete "<<endl;
    inOrder(root);

    cout<<"Delete the key value "<<endl;
    int key ;
    cin>>key ;
  Node * curr =   delete_BST(root, key);
  inOrder(curr);
//    Node * curr =  delete_BST(root, key);
//     cout<<"After the delete part  "<<endl;
//     inOrder(curr);
    // cout<<"value search in the BST "<<endl ;
    // int val ;
    // cin>>val ;

    // if( search_BST(root, val) != NULL){
    //     cout<<"Value exits in BST"<<endl;
    // }
    // else {
    //     cout<<"Not found "<<endl;
    // }

}
