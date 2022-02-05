#include<iostream>

using namespace std;

// Number of vertices in the graph  
const int V=6;

// Function to find the vertex with minimum distance value 
int min_dist(int distance[], bool visited[])  
{ 
    int min = 999, min_index;  // 999 represents an Infinite value

    for (int v = 0; v < V; v++) { 
        if (visited[v] == false && distance[v] < min) { 
        	// vertex should not be visited
            min = distance[v];
			min_index = v;  
        }
    }    
    return min_index;  
}  

// Function to print the final MST stored in parent[]  
int print_MST(int parent[], int cost[V][V])  
{  
    int minCost=0;
	cout<<"Edge \tWeight\n";  
    for (int i = 1; i< V; i++) {
		cout<<parent[i]<<" - "<<i<<" \t"<<cost[i][parent[i]]<<" \n";  
		minCost+=cost[i][parent[i]];
    }
	cout<<"Total cost is"<<minCost;
}  

// Function to find the MST using adjacency cost matrix representation  
void find_MST(int cost[V][V])  
{  
    int parent[V], distance[V];
    bool visited[V];

    // Initialize all the arrays 
    for (int i = 0; i< V; i++) { 
        distance[i] = 999;    // 99 represents an Infinite value
        visited[i] = false;
        parent[i]=-1;
    }    

    distance[0] = 0;  // Include first vertex in MST by setting its distance vaue to 0.  
    parent[0] = -1; // First node is always root of MST  

    // The MST will have maximum V-1 vertices  
    for (int x = 0; x < V - 1; x++) 
    {  
        // Finding the minimum distance vertex from the 
        //set of vertices not yet included in MST  
        int u = min_dist(distance, visited);  

        visited[u] = true;  // Add the minimum distance vertex to the MST  

        // Update distance and parent arrays
        for (int v = 0; v < V; v++)  
        {
            // cost[u][v] is non zero only for adjacent vertices of u  
            // visited[v] is false for vertices not yet included in MST  
            // distance[] gets updated only if cost[u][v] is smaller than distance[v]  
            if (cost[u][v]!=0 && visited[v] == false && cost[u][v] < distance[v])
            {  
                parent[v] = u;
                distance[v] = cost[u][v];  
            }        
        }
    }

    // print the final MST  
	print_MST(parent, cost);  
}  

// main function
int main()  
{  
    int cost[V][V];
	cout<<"Enter the vertices for a graph with 6 vetices";
    for (int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
			cin>>cost[i][j];
        }
    }
	find_MST(cost);  

    return 0;  
}  