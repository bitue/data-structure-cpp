#include<bits/stdc++.h>
using namespace std ;

class Graph {
    private:
        int V ;
        list<int>*adj ;

    public:
        Graph(int V){
            this->V = V ;
            this->adj = new list<int>[V]; // V nodes with adj list first ptr assigned ;


        }

        void addEdge (int u , int v ){
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }

        void printAdjList (int level){
            cout<<level<<" : ";
            for(auto it = adj[level].begin() ; it != adj[level].end(); it++){
                cout<<*it<<" ";
             
            }
            cout<<endl;

        }

        void BFS_level_order (int source ,int level){
            vector<bool> vt(V, false) ;
            int co =0 ;
            queue<int> q ;
            q.push(source);
           
            vt[source]= true ;
            while(!q.empty()){
                int ele = q.front();
                q.pop();
               
                cout<<ele<<" ";
                if(vt[ele] == false){
                    vt[ele]= true ;
                    for(auto it = adj[ele].begin() ; it != adj[ele].end() ; it++){
                        cout<<*(it)<<" ";
                        q.push(*it) ;
                    }
               }




            }

        }

};

int main (){
    int n , e ;
    cin>>n>>e ;
    Graph g(n);

    for(int i=0 ; i<e ; i++){
        int u , v;
        cin>>u>>v ;
        g.addEdge(u, v);
     
    }

    cout<<endl;

    for(int i=0 ; i<n ; i++){
        g.printAdjList(i);
    }

    cout<<"BFS traversal "<<endl;
    g.BFS_level_order(0, 1);





}