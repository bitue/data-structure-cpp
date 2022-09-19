#include<bits/stdc++.h>
using namespace std ; 

class Priority_queue {
    private :
        vector<int> v ;
        int findParent (int c ) {
            return (c-1)/2 ;
        }
        int leftChild (int p) {
            return (2*p)+1 ;
        }
        int rightChild (int p){
            return (2*p)+2 ;
        }

        void heapify (int start) {
            int l = leftChild(start);
            int r = rightChild(start);
            int large  = start ;
            if(l < v.size() &&v[large] <v[l]){
                large = l ;
            }
            if(r< v.size() &&v[large] < v[r]){
                large = r ;
            }
            swap(v[start], v[large]);
            cout<<endl<< "start : "<<start<<" large :"<<large <<endl;
            cout<<"current array situation "<<endl;
            
            // for(int i =0 ; i<v.size(); i++){
            //     cout<<v[i]<<" ";
            // }
            // cout<<endl;
         
            if(start != large){
               // cout<<"Then again heapify occur with the start value is "<<large<<endl;
                heapify(large);

            }
            return ;
        }

    public:
        void push (int val){
            v.push_back(val);
            int ami = v.size()-1 ;
            while(v[ami] > v[findParent(ami)]){
                swap(v[ami], v[findParent(ami)]);
                ami = findParent(ami);

            }
        }
        int top() {
            return v[0];
        }
        bool empty (){
            return v.size() == 0 ;
        }

        void pop(){
            v[0] = v[v.size()-1];
            v.pop_back();
            heapify(0);


        }
        vector<int> getVector (){
            return v ;
        }
     

};

void printVector (vector <int> vt){
    for(auto it = vt.begin(); it!=vt.end(); it++){
        cout<<*it<<" ";
    }

}

int main (){

    Priority_queue pq ;
    pq.push(10);
    printVector(pq.getVector());
    pq.push(40);
    printVector(pq.getVector());
    pq.push(20);
    printVector(pq.getVector());
    pq.push(8);
      printVector(pq.getVector());
    pq.push(99);
      printVector(pq.getVector());
    pq.push(9);
      printVector(pq.getVector());
    pq.push(15);
      printVector(pq.getVector());
    pq.push(7);
      printVector(pq.getVector());

    cout<<"heap sort "<<endl;
    while(!pq.empty()){
        int v = pq.top();
        pq.pop();
        cout<<v<<" ";
    }
    


}