#include<bits/stdc++.h>
using namespace std ;


class Node {
    public:
        int value ;
        Node *next ;

        Node(int val){
            this->next = NULL;
            this->value = val ;
        }

};

class Stack {
    Node * top ;
    Node * head ;

    public :
        Stack(){
            this->head = NULL ;
            this->top = NULL ;

        }

        void push (int val){
            Node * newNode =new Node(val);
            if(head == NULL){
                head = newNode ;
                top = newNode ;
                return ;
            }
            else {
                top->next = newNode ;
                top = newNode ;

            }
        }

        int pop (){
            int chk ;
            if(head == top){
                chk =head ->value ;
                head = NULL ;
                top = NULL ;
                return chk ;
            }
            else {
                Node * temp = head ;
                while(temp->next->next != NULL){
                    temp= temp->next ;
                }
                chk = temp->next->value ;
                temp->next = NULL ;
                delete temp->next ;
                return chk ;
            }
        }

        int Top (){
            if(top == NULL){
                cout<<"No value in the stack"<<endl;
                return -1;
            }
            return top->value ;
        }

        bool empty (){
            if(head == NULL){
                return true ;
            }
            else return false ;

        }
        void print_all (){
            Node *temp = head ;
            cout<<endl;
            while(temp != NULL){
                if(temp->next == NULL){
                    cout<<temp->value;
                }
                else {
                    cout<<temp->value<<"-->";
                }
                temp = temp->next ;
            }
        }


};