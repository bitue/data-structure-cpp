#include<bits/stdc++.h>
using namespace std ;

class Node {
public:
    int value ;
    Node *next ;
    Node (int val){
        this->value = val ;
        this->next = NULL ;

    }

};

class Queue {
    Node *front ;
    Node *rear ;
    public:
        Queue (){
            this->front = NULL ;
            this->rear = NULL ;

        }

        // push 

        void push (int val){
            Node *newNode = new Node(val);
            if(rear == NULL){
                rear = newNode ;
                front = newNode ;
            }
            else {
                rear->next = newNode ;
                rear = newNode ;
            }
        }

        // pop 

        int pop (){
            Node *dellNode = front ;
            int chk ;
            if(front == NULL ){
                cout<<"Queue underflow here ";
                return -1 ;

            }

            front = front->next ;
            if(front == NULL) {
                rear = NULL ;
            }
            chk = dellNode->value ;
            delete dellNode ;
            return chk ;
        }

        // back 
        int back (){
            return rear->value ;
        }
        // peck 
        int peck (){
            return front->value ;
        }
        //empty 
        bool empty (){
            if(front==NULL && rear == NULL) return true ;
            else return false ;
        }


};