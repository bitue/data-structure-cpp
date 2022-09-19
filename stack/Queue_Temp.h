#include<bits/stdc++.h>
using namespace std ;

template<typename N>  class Node {
public:
    N value ;
    Node<N> *next ;
    Node (N val){
        this->value = val ;
        this->next = NULL ;

    }

};

template <typename Q> class Queue {
    Node<Q> *front ;
    Node<Q> *rear ;
    public:
        Queue (){
            this->front = NULL ;
            this->rear = NULL ;

        }

        // push 

        void push (Q val){
            Node <Q> *newNode = new Node<Q>(val);
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

        Q pop (){
            Node<Q> *dellNode = front ;
            Q chk ;
            if(front == NULL ){
                cout<<"Queue underflow here ";
                return chk;

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
        Q back (){
            return rear->value ;
        }
        // peck 
        Q peck (){
            return front->value ;
        }
        //empty 
        bool empty (){
            if(front==NULL && rear == NULL) return true ;
            else return false ;
        }


};