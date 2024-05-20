#include<iostream>
#include<vector>
#include<queue>
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
        }                                
    }
}

void bfs(vector<Edge> graph[],int v,int start){

    vector<bool> visited(v,false);
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int current = q.front();  
        q.pop();
        if(!visited[current]){
            cout<<" "<<current;
            visited[current] = true;
            for(Edge edge:graph[current]){
                int i = edge.getDestination();
                q.push(i);
            }
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
int main(){

    int v,start;
    cout<<"\nEnter size of graph:";
    cin>>v;
    vector<Edge> graph[v];
    createGraph(graph,v);
    printGraph(graph,v);
    cout<<endl;
    cout<<"\nEnter starting vertex: ";
    cin>>start;
    cout<<"\nBFS:";
    bfs(graph,v,start);
    cout<<endl;
    return 0;
}