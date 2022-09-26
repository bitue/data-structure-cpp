#include<bits/stdc++.h>
using namespace std ;

int co =0 ;

class Graph {
    private:

        int V ;
        list<int> * adj ;

    public:
        Graph(int nodes){
            this->V = nodes ;
            this->adj = new list<int> [V];
        }

        void addEdge (int u , int v ){
            
            adj[u].push_back(v);
           // adj[v].push_back(u);
        }

        void printAdjList (int source){
            cout<<"Source : "<<source<<"  ";
            for(auto v : adj[source]){
                cout<<(v)<<" ";
            }
            cout<<endl;


        }

        void BFS_with_level (int source, int level){
            vector<bool> vt(V, false);
            vector<pair<int , int >> res ;
            queue<pair <int , int>> q ;
            q.push(make_pair(source, 0));
            vt[source]  = true ;
            while(!q.empty()){
                pair<int , int> curr = q.front();
                if(curr.second == level) {
                    co++;
                    //cout<<curr.first<<" ";
                }
                q.pop();
               // vt[curr.first]  = true ;
                for(auto i : adj[curr.first]){
                    if(vt[i] == false ){
                        q.push(make_pair(i, curr.second+1));
                        vt[i]= true ;
                    }


                }

            }

        }

        void DFS (int source){
            static vector<bool> vt(V, false);
            vt[source]= true ;
            co++;
          //  cout<<source<<" ";
            for(auto i : adj[source]){
                if(vt[i]== false){
                    vt[i]= true ;
                    DFS(i);
                    

                }
            }

        }

};

int main (){

    int v , e ;
    cin>>v>>e ;
    Graph g(v);
    for(int i=0 ; i<e ; i++){
        int u , v ;
        cin>>u >>v ;
        g.addEdge(u, v);

    }
    int lv ;
    cin>>lv ;

    g.DFS(lv);
    cout<<co-1<<endl;
  //  cout<<co<<endl;



}