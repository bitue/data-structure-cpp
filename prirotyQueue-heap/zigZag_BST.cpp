#include<bits/stdc++.h>
using namespace std ;

class Node {
    public:
        int value ;
        Node *left ;
        Node * right ;

        Node (int val){
            this->value = val ;
            this->left = NULL ;
            this->right = NULL ;
        }

};

Node * InsertBST (Node *root , int val) {
    Node * newNode = new Node (val);
    if(root == NULL){
        root = newNode ;
        return root ;

    }

    else {


        if(val >root->value){
        root->right = InsertBST(root->right , val);
        }
        else if(val < root->value){
        root->left = InsertBST(root->left , val);

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

void zigZagTraversal (Node *root){
    bool flag = true ;
    if(root == NULL){
        return ;
    }
    else {
        stack<Node  *> curr ;
        stack<Node *> next ;
        curr.push(root);
        while(!curr.empty()) {
            Node * current = curr.top();
            cout<<current->value<<" ";
            curr.pop();
            if(flag){
            
                if(current->left){
                    next.push(current->left);
                }
                if(current->right){
                    next.push(current->right);

                }

                
                   

            }
            else {
                
                if(current->right){
                    next.push(current->right);

                }
                if(current->left){
                    next.push(current->left);
                }

            }

            if(curr.empty()){
                swap(curr, next);
                  
          
                flag = !flag ;

            }
          

          
           
          

        }
    }
}

int main (){
    int n ;
    cin>>n ;

    Node *root = NULL ;
    for(int i =0 ; i<n ; i++){
        int value ;
        cin>>value ;
        root = InsertBST(root, value );
        
    }

   // inOrder(root);
   zigZagTraversal(root);

}