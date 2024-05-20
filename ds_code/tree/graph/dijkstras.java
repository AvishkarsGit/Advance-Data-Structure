import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;

class dijkstras {
    public static class Edge{
        public int src,dest,wt;

        public Edge(int s, int d,int wt){
            this.src = s;
            this.dest = d;
            this.wt = wt;
        }
        public Edge(int s, int d){
            this.src = s;
            this.dest = d;
        }
    }

    public static class Pair implements Comparable<Pair> {
        int node;
        int dist;
        public Pair(int n,int d){
            this.node = n;
            this.dist = d;
        }

        @Override
        public int compareTo(Pair p2) {
            return this.dist - p2.dist;
        }

    }

    public static void createGraph(ArrayList<Edge> graph[],int v){
        Scanner sc = new Scanner(System.in);
        int w,to;
        for(int i= 0;i<graph.length;i++){
            graph[i] = new ArrayList<>();
        }

        for(int i = 0;i<v;i++){;
            int edges;
            System.out.print("How much Edges are for vertext ( "+ i +" ) : ");
            edges = sc.nextInt();

            for (int j = 0;j<edges;j++){
                System.out.print("Enter destination "+ i + " to  :");
                to = sc.nextInt();
                System.out.print("Enter Weight for ( "+i +" -> "+ to + " ) : ");
                w = sc.nextInt();
                graph[i].add(new Edge(i,to,w));
            }
                                
        }
    }

    public  static void printGraph(ArrayList<Edge> graph[]){
        for(int i=0;i<graph.length;i++){
            System.out.print("Vertex "+i+" : ");
            for (Edge edge : graph[i]) {
                System.out.print("(" + edge.src + "->" + edge.dest + ", Weight: " + edge.wt + ") ");
            }
            System.out.println();            
        }
    }

    public static void dijkstrasAlgo(ArrayList<Edge>graph[],int src, int V) {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        int dist[] = new int[V];

        for(int i =0;i<V;i++){
            if (i != src) {
                dist[i] = Integer.MAX_VALUE;
            }
        }
        boolean vis[] = new boolean[V];
        pq.add(new Pair(0,0));
        while (!pq.isEmpty()) {
            Pair current = pq.remove();
            if (!vis[current.node]) {
                vis[current.node] = true;
                for(int i = 0;i<graph[current.node].size();i++){
                    Edge e=  graph[current.node].get(i);
                    int u = e.src;
                    int v = e.dest;
                    if(dist[u]+e.wt < dist[v]){
                        dist[v] = dist[u]+e.wt;
                        pq.add(new Pair(v,dist[v]));
                    }
                }
            }
        }
        for(int i = 0;i<V;i++){
            System.out.print(dist[i]+ " ");
        }
        System.out.println();
    }
    public static void main(String args[]){
    
        Scanner sc =new Scanner(System.in);
        System.out.println("Enter number of vertex in graph: ");
        int vertex = sc.nextInt();
        ArrayList<Edge> graph[] = new ArrayList[vertex];
        createGraph(graph,vertex);
        printGraph(graph);
        System.out.println("Enter source vertex:");
        int source = sc.nextInt();
        dijkstrasAlgo(graph, source, vertex);
    }
}