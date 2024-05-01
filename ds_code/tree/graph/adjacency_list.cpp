#include<iostream>
#include<vector>
using namespace std;

class Edge{
    private:
        int src;
        int dest;
    public:
        Edge(int s, int d){
            this->src = s;
            this->dest = d;
        }

        int getSource() {
            return src;
        }
        
        int getDestination(){
            return dest;
        }
};
void createGraph(vector<Edge> graph[]){
    
    graph[0].push_back(Edge(0,2));
    
    graph[1].push_back(Edge(1,2));
    graph[1].push_back(Edge(1,3));

    graph[2].push_back(Edge(2,0));
    graph[2].push_back(Edge(2,1));
    graph[2].push_back(Edge(2,3));

    graph[3].push_back(Edge(3,1));
    graph[3].push_back(Edge(3,2));

}
void printGraph(vector<Edge> graph[], int V) {
    for (int i = 0; i < V; ++i) {
        cout << "vertex " << i << ": ";
        for (Edge edge : graph[i]) {
            cout << "(" << edge.getSource() << ", " << edge.getDestination() << ") ";
        }
        cout << endl;
    }
}

int main(){
    int v =4;
    vector<Edge> graph[v];
    createGraph(graph);

    printGraph(graph,v);
    return 0;
}