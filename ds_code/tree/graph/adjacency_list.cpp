#include<iostream>
#include<list>
using namespace std;
class Graph
{
    int v;
    //array of list
    list<int> *l;
    public:
        Graph(int v)
        {
            this->v = v;
            l = new list<int>[v];
        }
        void add(int src,int dest){
            l[src].push_back(dest);
            l[dest].push_back(src);
        }
        void print(){
            for(int i = 0;i<v;i++){
                cout<<"Vertex "<<i<<"-> {";
                for(int nbr:l[i]){
                    cout<<""<<nbr<<","<<"";
                }
                cout<<"}"<<endl;
            }
        }
};
int main(){
    
    Graph g(4);
    g.add(0,1);
    g.add(0,2);
    g.add(1,2);
    g.add(2,3);

    g.print();
    return 0;
}