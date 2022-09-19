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

int find_tlt_count (Node * root , int *tlt){
      if(root== NULL){
        return 0 ; // break down condition is if it goes to null then it returns 0 as a sum value 
    }
    int l = find_tlt_count(root->left, tlt);
    int r = find_tlt_count(root->right, tlt);

    // find the tlt 
   *tlt+=abs(l-r); // tlt update 
   
   
    
    return l + r  +  root->value; // return the left sum + right sum + currNode value 

}

int findTilt(Node* root) {
    int co = 0;  // use the tlt values 
    find_tlt_count(root, &co); // pass the tlt value ref so that change can be detect 
    return co;
  
   

}


int main (){
    Node * root = create();

  
    int res = findTilt(root);
    cout<<res<<endl;
   
 

}