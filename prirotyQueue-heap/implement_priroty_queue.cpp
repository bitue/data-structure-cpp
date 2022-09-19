#include<bits/stdc++.h>
using namespace std ; 



class Priority_queue {
    private :
        vector<int> v ;
        int leftChild (int i){
            return (2*i)+1 ;
        }
        int rightChild (int i){
            return (2*i)+2 ;
        }
        int findParent (int c){
            return (c-1)/2 ;
        }

        void heapify (int start) {
            int l = leftChild(start);
            int r = rightChild(start);
            int small = start  ;
            if(l< v.size() && v[l] < v[small]){
               small = l ;

            }
            if(r < v.size() && v[r] < v[small]){
                small = r ;
            }

            swap(v[start], v[small]);

            if(start != small){
             
                heapify(small);

            }

        }

    public:
        void push (int val){
            v.push_back(val);
            int ami = v.size()-1 ;
           // cout<<ami<<findParent(ami)<<endl;
           
            while(v[ami] < v[findParent(ami)]){
                swap(v[ami], v[findParent(ami)]);
                ami = findParent(ami); 
               // cout<<"y"<<endl;
            }
        }

        bool empty (){
            if(v.size()==0){
                return true ;
            }
            else {
                return false ;
            }
        }

        int top(){
           return v[0];
           
        }

        void pop(){
            v[0] = v[v.size()-1];
            v.pop_back();
            heapify(0);
        }

        vector<int> getVector () {
            return v ;
        }


};

int main (){

    Priority_queue pq ;
    pq.push(10);
     pq.push(40);
      pq.push(20);
       pq.push(8);
        pq.push(99);
         pq.push(9);
          pq.push(15);
          pq.push(7);


        
        cout<<"Heap array here "<<endl;
          vector<int > vt = pq.getVector();
          for(int i=0 ; i<vt.size() ; i++){
            cout<<vt[i]<< " ";
          }

        cout<<"Heap sort "<<endl;
          while(!pq.empty()){
             int v = pq.top();
            // cout<<"i"<<endl;
             pq.pop();
             cout<<v<<" ";
          }




}