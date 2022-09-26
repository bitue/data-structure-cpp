#include<bits/stdc++.h>
using namespace std ;

vector<int> res ;
class Node {
    public :
        int value ;
        Node *left ;
        Node *right ;
        Node (int val){
            this->value = val ;
            this->left = NULL ;
            this->right = NULL ;       
        }  
};


void inOrder(Node *root){
 
    if(root==NULL) return ;
    inOrder(root->left);
    res.push_back(root->value);
    inOrder(root->right);


}


int main (){
   
    int s ;
    cin>>s ;
    Node * root = new Node (s);
    queue<Node *> Q ;
    Q.push(root);
    while(!Q.empty()){
        Node *curr = Q.front();
        Q.pop();
        int l , r ;
        cin>>l>>r ;
        // overall two node is NULL 
        Node *n1 = NULL ;
        Node *n2 = NULL ;
        // if value is present then create the node else NULL 
        if(l!= -1) n1 =new Node(l);
        if(r!=-1) n2 = new Node(r);
        // need to assign this 
        curr->left = n1 ;
        curr->right = n2 ;


        // need to push it the queue if is is not NULL 
        if(n1 != NULL) Q.push(n1);
        if(n2 != NULL) Q.push(n2);

    }

    inOrder(root);

    int o ;
    cin>>o ;
    while(o--){
        int x ;
        cin>>x ;
        if(x==2){
            sort(res.begin(), res.end());
            cout<<res[res.size()-1]<<endl;
            res.pop_back();

        }
        else {
            int y ;
            cin>>y ;
            res.push_back(y);


        }

    }



}
