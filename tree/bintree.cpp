#include<bits/stdc++.h>
using namespace std ;


class treeNode {
    public :
        char value ;
        treeNode *left ;
        treeNode *right ;
        treeNode (int val){
            this->value = val ;
            this->left = NULL ;
            this->right = NULL ;       
        }
     
};

treeNode * create (){
    cout<<" Enter the value of node (* -1 for NULL) "<<endl;
    char x ;
    cin>>x ;
    if(x=='x'){
        return NULL ;
    }
    treeNode * newNode = new treeNode(x);
    // for left child enter 
    cout<<"Enter the left child for the node value of "<<x<<endl;
    newNode->left = create();
    // for right child enter 
    cout<<"Enter the right child for the node value of "<<x<<endl;
    newNode->right = create();
    return newNode ;
}

treeNode * create_int (){
    int x ;
    cout <<"Enter -1 for the null ptr "<<endl;
    cin>>x ;
    if(x ==-1) return NULL ;
  
    treeNode * newNode = new treeNode(x);
    cout<<"Enter the value of left child of "<<x<<endl; 
    newNode->left = create_int();
    cout<<"Enter the value of the right child of"<<x<<endl;
    newNode ->right = create_int();

    return newNode ;


}

void preOrder (treeNode *root , string &chk){
    // base condition 
    if(root== NULL){
        return ;
    }

    chk+=to_string (root->value)+ " ";
    preOrder(root->left , chk);
    preOrder(root->right , chk);
}

void inOrder (treeNode * root , string &chk){
    //base condition 
    if(root == NULL) return ;
  
    inOrder(root->left , chk);  // 1
    chk+=to_string(root->value) + " " ;// 2
    inOrder(root->right , chk); // 3

}


void postOrder (treeNode *root , string &chk){
    if(root == NULL){
        return ;
    }
    postOrder(root->left, chk);
    postOrder(root->right, chk);
    chk+=to_string(root->value) + " ";


}

void levelOrder (treeNode * root , string &chk) {
    if(root == NULL) return ;
 
    queue<treeNode *> q ;
    q.push(root);
   
    
    while(!q.empty()){
        treeNode * curr = q.front();
        q.pop();
        chk +=to_string(curr->value);
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
      
    }

}

void levelOrder_sir (treeNode * root ){
    if(root == NULL) return ;

    queue<treeNode *> q ;
    q.push(root);
    q.push(NULL);
    int lv =0 ;
    while(!q.empty()){
        treeNode * chkNode = q.front();
        q.pop();
        if(chkNode != NULL){
            cout<<to_string(chkNode->value)<<" ";
            if(chkNode->left) q.push(chkNode->left);
            if(chkNode->right) q.push(chkNode->right);
           
        }
        else {
            if(!q.empty()){
              
                cout<<lv<<endl;
                lv++ ;
                q.push(NULL);
            }
        }

    }
    cout<<lv<<endl;
   
}

int level_max_value (treeNode *root , int k ) {
    int lv =0 ;
    
    if(root == NULL){
        return -1 ;
    }
    int max_value = -9999 ;
    queue <treeNode *> q ;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        treeNode *curr = q.front();
        q.pop();
        if(curr !=NULL){
        
            if(lv == k){
                if(int(curr->value)> max_value){
                    max_value = int(curr->value) ;
                }
            }
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);


        } 
        else {
            if(!q.empty()){
                q.push(NULL);
                lv++;
            }

        }

    }
    

    return max_value ;
}

int find_pos_inOrder (int value , int * in , int start , int end ){
    for(int i = start ; i<= end ; i++){
        if(in[i]== value ){
            return i ;
        }
    }
    return -1 ;
}

treeNode * buildTreePreIn (int * pre , int * in , int start , int end ) {
    static int id = 0 ;
    int curr = pre[id];
    id++;
    treeNode * newNode = new treeNode (curr);
    // base call where we stop 
    if(start == end){
        return newNode ;
    }
    // need to find the pos ;
    int pos = find_pos_inOrder(curr , in , start , end );
    newNode->left =  buildTreePreIn(pre , in , start, pos-1) ;
    newNode->right = buildTreePreIn(pre , in , pos+1 , end);
    return newNode ;


}

void left_non_leaf(treeNode * root){
    if(root == NULL) return ;
    if(root->left != NULL){
       cout<<to_string(root->value)<<" ";
        left_non_leaf(root->left);
    }
    else if (root->right != NULL){
       cout<<to_string(root->value)<<" ";
        left_non_leaf(root->right);
    }
}

void right_non_leaf (treeNode *root ){
    if(root==NULL) return ;
    if(root->right != NULL){
     cout<<to_string(root->value)<<" ";
        right_non_leaf(root->right);
    }
    else if(root->left != NULL){
        cout<<to_string(root->value)<<" ";
        right_non_leaf(root->left);
    }
}

void print_leaf (treeNode *root ) {
    if(root == NULL) return ;
    if(root->left == NULL && root->right == NULL){
        cout<<to_string(root->value)<<" ";
        return ;
       
    }
    print_leaf(root->left);
    print_leaf(root->right);

}

void boundary_traversal (treeNode *root ) {
    if(root == NULL){
        return ;
    }
    cout<<to_string(root->value)<<" ";
    //left non leaf 
    left_non_leaf(root->left);

    //left leaf
    print_leaf(root->left);
    //right leaf
    print_leaf(root->right); 
    //right non leaf
    right_non_leaf(root->right);
}

int main (){

    // binary tree implementation here create();
    treeNode * root = NULL ;
    root = create_int();
    boundary_traversal(root);
//   //  boundary_traversal(root);
//   string in ="";
//   string pre ="";
//   string post ="";

//   inOrder(root, in );
//     cout<<"inOrder : "<<in<<endl;;
//     preOrder(root, pre );
//     cout<<"PreOrder : "<<pre<<endl;

//   postOrder(root, post );
//     cout<<"PostOrder : "<<post<<endl;

  

    // string s ="";
    // inOrder(root, s);
    // count<<s<<endl;
   // levelOrder_sir(root);
   // cout<<s<<endl;
//   int res =  level_max_value(root, 2);
//   cout<<res<<endl;
    // int n ;
    // cin>>n ;
    // int pre [n];
    // int in [n];
    // for(int i=0 ; i<n ; i++){
    //     cin>>pre[i];
    // }
    // for(int i=0 ; i<n ; i++){
    //     cin>>in[i];
    // }

    // treeNode * root = buildTreePreIn(pre, in , 0 , n-1);
    // string s ="";
    // inOrder(root, s);
    // cout<<s <<endl;


   
}