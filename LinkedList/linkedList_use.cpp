
#include<bits/stdc++.h>
using namespace std ;

class Node {

public :
    int value ;
    Node *next ;

    Node(int value ){
        this->value = value ;
        this->next = NULL ;

    }

};



void insert_at_tail (Node *&head , int value){

    Node *newNode = new Node(value);
    Node *temp = head ;


    if(head == NULL){

        head = newNode ;

    }
    else {
        while(temp->next != NULL){
            temp= temp->next ;
        }
        temp->next = newNode ;

    }

}

void insert_at_head(Node *&head , int val){

    Node *newNode = new Node(val);

    if(head == NULL){
        head = newNode ;
        return ;
    }
    else {
        newNode->next = head ;
        head = newNode ;
        return ;
    }


}

void display (Node *&head){
    Node *temp = head ;
    if(temp== NULL){
        cout<<"Linked list is empty"<<endl;
        return ;
    }

    while(temp!= NULL){
        if(temp->next == NULL){
            cout<<temp->value;


        }
        else {
             cout<<temp->value<<"-->";

        }
         temp = temp->next ;

    }

}

Node* recursive_link_list (Node *&head){

    Node *currNode = head ;
    Node *prevNode = NULL ;
    Node *nextNode = head->next ;

    while(true){
        currNode->next = prevNode;
        prevNode = currNode ;
        currNode = nextNode ;
        if(currNode == NULL){
            return prevNode ;
        }
        else {
            nextNode = nextNode->next ;
        }

    }


}

Node * reverse_linkedList_recursion (Node *&head){
    //base call
    if(head == NULL){
        return NULL ;
    }
    if(head ->next == NULL ){

        return head ;
    }
    // recursive call
    Node *newHead = reverse_linkedList_recursion(head->next);
    head->next->next = head ;
    head->next = NULL;
    return newHead ;
}

bool check_palindrone (Node *first , Node *last){

    while( first != NULL && last != NULL){
        if(first->value != last->value){
            return false ;
        }

        first = first->next ;
        last = last->next ;
    }

    return true ;


}


int main (){

    Node *head = NULL;

    int n ;
    cin>>n ;
    int arr[n];
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];

    }



    for(int i =0 ; i<n ; i++){
        insert_at_tail(head, arr[i]);

    }




    cout<<"After recurrsion"<<endl;
    Node *tailHead ;

    tailHead = reverse_linkedList_recursion(head);

    bool res = check_palindrone(head, tailHead);
    if(res){
        cout<<"TRUE"<<endl;
    }
    else {
        cout<<"FALSE"<<endl;
    }



}
