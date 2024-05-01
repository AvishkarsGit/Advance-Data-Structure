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

    int v=6;
    vector<Edge> graph[v];
    createGraph(graph);
    printGraph(graph,v);
    cout<<endl;
    cout<<"\nBFS:";
    bfs(graph,v,0);
    bfs(graph,v,4);
    cout<<endl;
    return 0;
}