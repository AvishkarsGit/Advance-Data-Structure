#include<iostream>
#include<vector>
#include<stack>
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
void createGraph(vector<Edge> graph[],int v){

        int w,to;
        for(int i = 0;i<v;i++){;
            int edges;
            cout<<"How much Edges are for vertext ( "<<i<<" ) : ";
            cin>>edges;

            for (int j = 0;j<edges;j++){
                cout<<"Enter destination "<< i << " to  :";
                cin>>to;
                graph[i].push_back(Edge(i,to));
            }.
                                
        }
}
void dfs(vector<Edge> graph[],int current,bool visited[]){
    
    visited[current] = true;
    cout<<current<<" ";
    
    for(Edge edge : graph[current]){
        if (!visited[edge.getDestination()]){
            dfs(graph, edge.getDestination(), visited);
        }
    }
}

void printGraph(vector<Edge> graph[],int v){
    for(int i = 0;i<v;i++){
        cout<<"\nvertex "<<i<<" : ";
        for(Edge edge: graph[i]){
            cout<<"("<<edge.getSource()<<","<<edge.getDestination()<<")";
        }
        cout<<endl;
    }
}

int main()
{
    int v=5;
    vector<Edge> graph[v];

    createGraph(graph);
    printGraph(graph,v);
    bool visited[v];
    dfs(graph,1,visited);
    cout<<endl;
    return 0;
}