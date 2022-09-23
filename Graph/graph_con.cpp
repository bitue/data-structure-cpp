#include<bits/stdc++.h>
using namespace std ;

typedef pair<int , int> edgeWeight ;

class Graph {
    private:
        int V ;
        list <edgeWeight> *adj ;
    public:
        Graph(int value ){
            this->V = value ;
            this->adj = new list<edgeWeight>[V];

        }
        void addEdge (int u , int v , int w){
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u,w));
        }

        void printNeighbour (int chk){
            cout<<chk<<": ";
            for(auto it = adj[chk].begin(); it != adj[chk].end(); it ++){
                 cout<<"("<<(*it).first<<", "<<(*it).second<<")"<<" -> ";
            }
            cout<<endl;
        }

        void BFS (int source ) {
            vector<bool> vt(V, false);
            queue<int> Q ;
            Q.push(source);
            vt[source] = true ;
            while(!Q.empty()){
                int element = Q.front();
                cout<<element<<" ";
                Q.pop();
                for(auto v : adj[element]){
                    int ele = v.first ;
                    if(vt[ele] == false){
                        vt[ele] = true ;
                        Q.push(ele);

                    }
                    

                }
            }

        }

        void DFS (int source){
            static vector<bool> vt(V, false);

            cout<<source<<" ";
            vt[source]= true ;

            for(auto i : adj[source]){
                int ele = i.first ;
                if(vt[ele]== false ){
                   
                    DFS(ele);
                  
                }
            }
            
            
            
        }

};

int main (){
    int V , E , s ;
    cin>>V >>E >> s;
    Graph g(V);

    for(int i =0 ; i<E ; i++){
        int u , v , w ;
        cin>>u>>v>>w ;
        g.addEdge(u, v, w);

    }

    // print the all adj 

    for(int i =0 ; i<V ; i++){
        g.printNeighbour(i);
    }

    cout<<endl<<endl;

    g.BFS(s);
    cout<<endl<<endl;
    g.DFS(s);

    /*


    7 10 5 
    0 1 7
    0 2 1
    0 5 3
    1 3 11
    2 3 3
    2 5 8
    3 6 1
    4 5 6
    4 6 4
    5 6 2


    */


}