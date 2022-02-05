

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class graph{
    int vertices;
    vector<pair<int,int>> *g;
    bool *visited; 
    public:
    graph(){
        vertices=0;
    }
    graph(int no){
        vertices=no;
        g = new vector<pair<int,int>>[vertices+1];
        visited = new bool[vertices];
    }

    void addEdge(int u, int v, int w)
    {
        g[u].emplace_back(make_pair(v, w));
        g[v].emplace_back(make_pair(u, w));
    }
    
    void display(){
    	cout << "Adjacency List:" << endl;
	    for (int i=0; i < vertices; i++)
	    {
	        cout << i;
	        for (int j=0; j < g[i].size(); j++)
	            cout << " -> " << g[i][j].first << "," << g[i][j].second;
	        cout << endl;
	    }
	}

//digikstra steps
//1. all vertices distannce = infinite
//2. start distance =0
//3.insert start and  0 in queue
//4.until queue is not empty pop and for popoed nodes's adj nodes 
//
//
//

    void dijkstra(int start)
{
    vector<int> dist(vertices,999999);

    priority_queue < pair<int,int> , vector <pair<int,int>> , greater<pair<int,int>> > pq;

    // Add start to pq, where distance is 0
    pq.push(make_pair(start, 0 ));
    dist[start] = 0;

    while(!pq.empty())
    {
        // Get min distance vertex from pq
        int u = pq.top().first;
        pq.pop();

        for(int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i].first;
            int weight = g[u][i].second;

            // If the distance to v is shorter by going through u
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(v,dist[v]));
            }
        }
    }
	 cout << "Vertex      Distance from Source" << endl;
    for (int i = 0; i < vertices; ++i)
        cout << i << "\t\t" << dist[i] << endl;}

    
    void BFS(int start){

        for (int i = 0; i < vertices; i++){
            visited[i]=false;
        }

        queue<int>q;
        q.push(start);
        visited[start]=true;

        while(!q.empty()){
            int vertex=q.front();
            cout<<vertex<<" ";
            q.pop();

            for(int i=0;i<g[vertex].size();i++){
            if(!visited[g[vertex][i].first]){
                q.push(g[vertex][i].first);
                visited[g[vertex][i].first]=true;
            }
            }
    }
    }

    //function for dfs traversal
    void DFSI(int start){

            for (int i = 0; i < vertices; i++)
        {
            visited[i]=false;
        }

        stack<int> stk;//stack in STL

        stk.push(start);
        visited[start]=true;

        while(!stk.empty()){

            int vertex=stk.top();
            cout<<vertex<<" ";
            stk.pop();

            for(int i=0;i<g[vertex].size();i++){

            if(!visited[g[vertex][i].first]){
                stk.push(g[vertex][i].first);
                visited[g[vertex][i].first]=true;
            }
            
            }
        }
    }


    void DFS(int vertex) {

        visited[vertex] = true;
        if(vertex<vertices){
        cout << vertex << " ";}
        for (int i = 0; i < g[vertex].size(); i++)
            if (visited[g[vertex][i].first]==false)
            DFS(g[vertex][i].first);
}

bool isCyclicUtil(int v, bool *inpath)
{
        visited[v] = true;
        inpath[v] = true;
  
        // Recur for all the vertices adjacent to this vertex
        for(int i = 0; i <= g[v].size(); ++i)
        {
            if (inpath[g[v][i].first])
                return true;
            else if ( !visited[g[v][i].first])
            isCyclicUtil(i,inpath);
            
        }
    inpath[v] = false; 
    return false; // remove the vertex from recursion stack
}

// steps for cycle
// 1.make visited and in path array and initialize with 0
// 2.for all vertices call cycle function 
// 3.send inpath in fuction and current node 
// 4. make visited and inpath true for thhe node true 
// 5.check for v's adj nodes if and node is present already in in path then return true
// 6. else if its not visited call ifunction again with adj and inpoath

bool isCyclic()
{

    bool *inpath = new bool[vertices];
    for(int i = 0; i < vertices; i++)
    {
        visited[i] = false;
        inpath[i] = false;
    }
  
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < vertices; i++)
        if (isCyclicUtil(i, inpath))
            return true;
  
    return false;
}




};





int main()
{
    // pair of node, weight

    graph g1(9);
    g1.addEdge( 0, 1, 4);
    g1.addEdge( 0, 7, 8);
    g1.addEdge(1, 2, 8);
    g1.addEdge( 1, 7, 11);
    g1.addEdge( 2, 3, 7);
    g1.addEdge( 2, 8, 2);
    g1.addEdge( 2, 5, 4);
    g1.addEdge( 3, 4, 9);
    g1.addEdge( 3, 5, 14);
    g1.addEdge(4, 5, 10);
    g1.addEdge(5, 6, 2);
    g1.addEdge(6, 7, 1);
    g1.addEdge( 6, 8, 6);
    g1.addEdge(7, 8, 7);
    g1.display();
    g1.dijkstra(0);
    g1.DFSI(0);
    cout<<endl;
     g1.BFS(0);
     cout<<endl;
     g1.DFSI(0);
     cout<<endl;
     cout<<g1.isCyclic();
   
    return 0;
}
