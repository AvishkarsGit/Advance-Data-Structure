#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class Edge {
    private:
        int src, dest,cost;
    public:
        Edge(int s,int d,int c){
            this->src = s;
            this->dest = d;
            this->cost = c;
        }
        int getSource(){
            return src;
        }
        int getDestination(){
            return dest;
        }
        int getCost(){
            return cost;
        }
};


void createGraph(vector<Edge> graph[]){


    /*        1
          0 ----- 1
          | \     |
        4 |   \3  | 2
          |     \ |
          2 ----- 3
              5

    */
    graph[0].push_back(Edge(0,1,1));
    graph[0].push_back(Edge(0,2,4));
    graph[0].push_back(Edge(0,3,3));

    graph[1].push_back(Edge(1,0,1));
    graph[1].push_back(Edge(1,3,2));


    graph[2].push_back(Edge(2,0,4));
    graph[2].push_back(Edge(2,3,5));

    graph[3].push_back(Edge(3,1,2));
    graph[3].push_back(Edge(3,2,5));

}
int primsMST(vector<Edge> graph[], int V) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    pq.push(make_pair(0, 0));
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (Edge& e : graph[u]) {
            int v = e.getDestination();
            int weight = e.getCost();

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    int mstWeight = 0;
    for (int i = 1; i < V; i++)
        mstWeight += key[i];

    return mstWeight;
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
    int v=4;
    vector<Edge> graph[v];

    createGraph(graph);
    printGraph(graph,v);
    int mst = primsMST(graph,v);
    cout<<"\nMinimum spanning tree:"<<mst;
    cout<<endl;
    return 0;
}