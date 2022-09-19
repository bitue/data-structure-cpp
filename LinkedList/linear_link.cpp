#include<bits/stdc++.h>
using namespace std ;

class Node {
    public :
        int value ;
        Node * next ;

        Node(int val){
            this->next = NULL ;
            this->value = val ;
        }

};

void insert_at_tail(Node *&head , int val){
    Node * newNode = new Node (val);
    Node *temp = head ;
    if(head == NULL){
        head = newNode ;
    }
    else {
        while(temp->next !=NULL){
            temp = temp->next ;
        }
        temp->next = newNode ;
    }
}

void print_all_nodes(Node *n){
    while(n!= NULL){
        if(n->next == NULL) cout<<n->value<<" ";
        else {
            cout<<n->value<<"->";

        }
        n= n->next ;

    }
}

void insert_at_head (Node*&head, int val){
    Node * newNode = new Node(val);
    if(head== NULL){
        head = newNode ;
    }
    else {
        newNode->next = head ;
         head = newNode ;

    }
    

}

int len (Node *n){
    int l =1 ;
    while(n!= NULL){
        l++;
    }
    return l ;
}

int find_pos (Node *&head, int val){
    Node * temp = head ;
    int co =1 ;
    while(temp!= NULL){
        if(temp->value == val){
            return co ;
        }
        temp= temp->next ;
        co++;
    }
    return -1 ;
}

void insert_at_after_spec_pos(Node *&head, int pos , int val ){
    Node * temp = head ;
    Node * newNode = new Node(val);
    for(int i=0 ; i<pos-2 ; i++){
        temp = temp->next ;
    }
    if(pos==1){
        insert_at_head(head , val);
        return ;
    }
  
    Node *upNode = temp->next ;
    temp->next = newNode ;
    newNode->next = upNode ;


}

void insert_at_specefic_value (Node*&head, int search_value , int insert_value) {
    int pos = find_pos(head, search_value) ;
    if(pos == -1){
        cout<<"No position found to insert"<<endl;
        return ;
    }
    else {
        insert_at_after_spec_pos(head, pos+1, insert_value);
    }
}

void delete_head (Node *&head) {
    if(head == NULL){
        cout<<"There is no value in linked list yet !!"<<endl;
    }
    else {
        Node *temp = head ;
        head = temp->next ; // we need to update the head value so we need pointer ka address hae 
        delete temp ;
    }
   
}

void delete_at_specefic_pos (Node *&head , int pos ){
    Node *temp = head ;
    if(pos==1){
        
        delete_head(head);
        return ;
    }
    for(int i=0 ; i<pos-2 ; i++){
        temp= temp->next ;
    }

    Node *dellNode = temp->next ;
    Node *upNode = temp->next->next ;
    temp->next = upNode ;
    delete dellNode ;

}

void delete_at_specefic_value (Node *&head , int val ){
    Node *temp = head ;
    int pos = find_pos(head, val);
   
    delete_at_specefic_pos(head, pos);
}

void make_circular_linear_list (Node *&head ){
    Node *temp = head ;
    while(temp->next!= NULL){
        temp= temp->next ;
    }
    temp->next = head ;
}

int main (){
    int n ;
    cin>>n ;
    int arr [n];
    for(int i=0 ; i<n ; i++) cin>>arr[i];
    Node *head = NULL ;
    for(int i=0 ; i<n ; i++){
        insert_at_tail(head, arr[i]);
    }
    print_all_nodes(head);
    int search_value , insert_value ;
    cout<<"Enter the search value and inserted value "<<endl;
    cin>>search_value>>insert_value ;

    //
    insert_at_specefic_value(head, search_value, insert_value);
    print_all_nodes(head);

    cout<<"Delete at specefic value "<<endl;
    cout<<"value u want to delete"<<endl;
    int delete_value ;
    cin>>delete_value ;
    delete_at_specefic_value(head, delete_value);
    print_all_nodes(head);

    make_circular_linear_list(head);
     print_all_nodes(head);


}