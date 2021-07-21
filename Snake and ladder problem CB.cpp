#include<iostream>
#include<queue>
#include<map>
#include<list>
using namespace std;

template<typename T>
class graph{

    map<T,list<T>> adjMap;
public:
    void addEdge(T u,T v,bool bidir=true){
    adjMap[u].push_back(v);
    if(bidir){
        adjMap[v].push_back(u);
    }
    }

    void print()
    {
    for(auto i:adjMap){
        cout<<i.first<<"->";
        for(auto spunk:i.second){
            cout<<spunk<<",";
        }
        cout<<endl;
    }
    }

int bfs(T src,T dest){
      queue<T> q;
      map<T,int> dist;
      map<T,T> parent;
        for(auto i:adjMap){
            dist[i.first]=INT_MAX;
        }
        q.push(src);
        dist[src]=0;
        parent[src]=src;
        while(!q.empty()){
            T node = q.front();
            q.pop();
            for(int neighbour:adjMap[node]){
                if(dist[neighbour]==INT_MAX){
                    q.push(neighbour);
                    dist[neighbour]=dist[node]+1;
                    parent[neighbour]=node;
                }
            }
        }

        //print
        /*for(auto i:adjMap){
            T node=i.first;
            cout<<"Dist of "<<node<<" is "<<dist[node]<<endl;
        }*/

        T temp=dest;    //we make destination as temp;
        while(temp!=src){
            cout<<temp<<"<--";
            temp=parent[temp];//parent[temp] gives the parent node of dest, that is where it comes from;
        }
        cout<<src<<endl;    //at the end we print source,i.e, 1 in our case;
       return dist[dest];   //dist[dest] gives the no of steps to reach destination
}

};

int main ()
{
    graph<int> g;
    int b[50]={0};
    b[2]=13;
    b[5]=2;
    b[9]=18;
   b[18]=11;
   b[17]=-13;
   b[20]=-14;
   b[24]=-8;
   b[25]=-10;
   b[32]=-2;
   b[34]=-22;
    //construct pairs and graphs of u and v
    for(int u=0;u<=36;u++){
        for(int dice=1;dice<=6;dice++)//at every node we can throw a dice
        {
            int v=u+dice+b[u+dice];
            g.addEdge(u,v,false);
        }
    }
    cout<<"Shortest path is \n"<<g.bfs(1,36)<<endl;

    return 0;
}
