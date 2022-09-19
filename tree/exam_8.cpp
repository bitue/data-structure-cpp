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

vector<int > vt ;


void average_level (Node *root){
    if(root == NULL) {
        return ;
    }
    queue<Node *> q ;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node * curr = q.front();
        q.pop();
        if(curr!= NULL){
            vt.push_back(curr->value);
            if(curr->left) q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
        else {
            vt.push_back(-1);
            if(!q.empty()){
                q.push(NULL);
            }
        }

    }
    int k=0;
    float co =0 ;

    for(auto it = vt.begin(); it !=vt.end(); it++){
        
        if(*it == -1){
            cout<<co/k<<" ";
            k=0;
            co=0 ;

        }
        else {
            co +=*it ;
            k++;
        }
    }

   

}

int main (){
    Node *root = create();
    average_level(root);

  
}