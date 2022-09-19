#include<bits/stdc++.h>
using namespace std ;

template<typename T> class Node {
public :

    T value ;
    Node *prev ;
    Node *next ;

    Node (T value ){
        this->value = value ;
        this->next =NULL;
        this->prev =NULL;

    }


};

template<typename S> class Stack {
    Node <S> * head ;
    Node <S> * top ;
    int len =0 ;

public :
    Stack (){
        this->head = head ;
        this->top = head ;
        this->len =0 ;
    }
    // push
    void push (S val){
        Node <S>*newNode = newNode <S>(val) ;
        if(head == NULL){
           this->head = newNode ;
           this->top = newNode ;
           this->len ++;
           return ;
        }
        this->top->next = newNode ;
        newNode->prev = top ;
        top = newNode ;
        this->len ++;
        return ;
    }

    // pop

    S pop (){
        S res ;

        if(head == NULL){
                cout<<"There is no element in the stack"<<endl;
                return res ;

        }

        if(head == top) {
            res = top->value ;
            head = top = NULL ;
            this->len --;
            return res ;
        }
        Node <S> * dellNode = top ;
        res = dellNode->value ;
        this->len --;
        top =  dellNode->prev ;
        top->next = NULL ;
        delete dellNode ;


        return res ;

    }

    // Top

    S Top (){
        S res ;
        if(top== NULL){
            cout<<"Stack overflow "<<endl;
            return res ;

        }
        return this->top->value ;
    }

    // empty
    bool is_empty_(Node <S> *head){
        if(head == NULL) return true ;
        else return false ;

    }
    // size
    int size_ (){
        return len ;

    }




};





