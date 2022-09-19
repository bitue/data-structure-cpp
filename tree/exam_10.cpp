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

vector<int> vt ;

void inOrder (Node * root ){
    //base condition 
    if(root == NULL) return ;
  
    inOrder(root->left );  // 1
    vt.push_back(root->value);
    inOrder(root->right ); // 3

}



int second_minimum(Node* root) {
    inOrder(root);
    // for(auto it = vt.begin(); it!=vt.end(); it++){
    //     cout<<*it<<" ";
    // }
    //sort the vt
    sort(vt.begin(), vt.end());
    int k =0 ;
    int min_num = *(vt.begin());
    for(auto it = vt.begin(); it !=vt.end(); it++){
        if(min_num== *it){
            k++;
        }
    }
   // cout<<vt.at(k)<<" "<<k<<"   <=k"<<" ";
    if(vt.size()-1 <=k){
        return -1 ;
    }
    else {
        return vt.at(k) ;
    }


}

int main (){
    Node *root = create();
    int res = second_minimum(root);
    cout<<res<<endl;
}