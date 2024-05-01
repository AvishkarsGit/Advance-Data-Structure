#include<iostream>
#include<vector>
using namespace std;
class Edge {
    private:
        int src, dest;
    public:
        Edge(int s,int d){
            this->src = s;
            this->dest = d;
        }
        int getSource(){
            return src;
        }
        int getDestination(){
            return dest;
        }
};
void createGraph(vector<Edge> graph[]){

    //0-1-2-3  //4-5
    graph[0].push_back(Edge(0,1));

    graph[1].push_back(Edge(1,0));
    graph[1].push_back(Edge(1,2));

    graph[2].push_back(Edge(2,1));
    graph[2].push_back(Edge(2,3));

    graph[3].push_back(Edge(3,2));

    graph[4].push_back(Edge(4,5));
    
    graph[5].push_back(Edge(5,4));
    
}
void dfs(vector<Edge> graph[],int current,vector<bool> visited){
    cout<<current<<" ";
    visited[current] = true;
    for (Edge edge:graph[current]){
        int i = edge.getDestination();
        if(!visited[edge.getDestination()]){
            dfs(graph,edge.getDestination(),visited);
        }
    }
}
int main()
{
    int v=6;
    vector<Edge> graph[v];

    createGraph(graph);
    vector<bool> visited(v,false);
    dfs(graph,0,visited);
    dfs(graph,4,visited);
    return 0;
}