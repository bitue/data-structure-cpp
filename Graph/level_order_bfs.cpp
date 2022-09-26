#include<bits/stdc++.h>
using namespace std ;

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
            adj[v].push_back(u);
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
                    cout<<curr.first<<" ";
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

    // cout<<"print the adj list "<<endl;
    // for(int i=0 ; i<v ; i++){
    //     g.printAdjList(i);
    // }

    g.BFS_with_level(0, lv);



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



    4 4
    0 1
    0 2
    1 3
    2 3


    */

}