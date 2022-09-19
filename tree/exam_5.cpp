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

void zigzag_order(Node* root ) {
    static int lv = 0 ;
    if(root== NULL){
        return ;
    }

    queue <Node *> q ;
    queue<int > res ;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        Node * curr = q.front();
        q.pop();
        if(curr != NULL){
            if(lv % 2 == 0){
                if(curr->right) q.push(curr->right);
                if(curr->left) q.push(curr->left);
                res.push(curr->value);

               


            }
            else {
                 if(curr->left) q.push(curr->left);
                 if(curr->right) q.push(curr->right);
               
                res.push(curr->value);

            }
            

        }
        else {
            if(!q.empty()){
                    q.push(NULL);
                    lv++ ;
            }

        }
    }

    while(!res.empty()){
        cout<<res.front()<<" ";
        res.pop();
    }

}

int main (){
    Node * root = create();
    zigzag_order(root);

}