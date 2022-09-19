#include<bits/stdc++.h>
using namespace std ;

class DoubleLink {

    public :
        int value ;
        DoubleLink * prev ;
        DoubleLink * next ;
        DoubleLink (int val){
            this->prev = NULL;
            this->value =  val ;
            this->next = NULL;
        }
   
};

struct result_arr {
    
    int pos[1000]={0};

};




void display (DoubleLink *head ) {
    if (head == NULL) {
        cout<<"No value in the linked list yet";
        return ;
    }

    while(head != NULL){
        if(head->next == NULL){
            cout<<head->value;
        }
        else {
            cout<<head->value<<"->";
        }
        head = head -> next ;
    }

}
void insertion_at_tail (DoubleLink *&head , int val){
    DoubleLink * newNode = new DoubleLink(val);
    if(head == NULL){
        head = newNode;
        return ;
    }
    DoubleLink * temp = head ;
    while(temp ->next != NULL){
        temp = temp ->next ;
    }
    temp->next = newNode ;
    newNode->prev = temp;
}

result_arr result (DoubleLink *&head ){

    DoubleLink * temp = head ;
    int k=0 ;
    result_arr arr ;
   

    while(temp!= NULL){
        DoubleLink *n = temp->next ;
        //cout<<endl;
        int sum = 0 ;
        bool flag = false ;
     //  cout<<temp->value<<" temp: "<<endl;
      sum += temp->value ;
        while(n!= NULL){
           // cout<<n->value<<" n ";
           sum += n->value ;
           if(sum == 0){
                flag = true ;
                break ;
           }

            n = n->next ;

           
        }
        if(flag){
            temp = n->next ;
        }
        else {
             //cout<<temp->value<<endl;
             arr.pos[k]=temp->value ;
             k++;
            
             temp= temp->next ;

        }
       
       
    }

    return arr ;
}

int main (){

    int n ;
    cin>>n ;
    int arr [n];
    for(int i=0 ; i<n ; i++) cin>>arr[i];

    DoubleLink * head = NULL ;
    for(int i=0 ; i<n ; i++){
        insertion_at_tail(head , arr[i]);
    }

    DoubleLink * result_head = NULL ;

  //  display(head);
  result_arr p =   result(head);

    for(int i=0 ; p.pos[i] != 0 ; i++ ){
        insertion_at_tail(result_head, p.pos[i]);
       // cout<<p.pos[i]<<"for loop"<<endl;
    }

    display(result_head);

    //



}