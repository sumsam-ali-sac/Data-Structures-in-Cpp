// DFS algorithm in C++

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


class Graph {
  int numVertices;
  vector<int> *adjLists;
  vector<pair<pair<int,int>, int>> weights;
  bool *visited;

   public:

  Graph(int numVertices) {
  this->numVertices = numVertices;
  adjLists = new vector<int>[numVertices];
  visited = new bool[numVertices]{false};
}

  void addEdge(int src, int dest) {
  adjLists[src].push_back(dest);
  adjLists[dest].push_back(src);
  weights.push_back(pair(pair(src,dest),1));
  weights.push_back(pair(pair(dest,src),1));
}
void display(){
    for(int i=0;i< numVertices;i++){
        for(int j=0;j< adjLists[i].size();j++){
            ;
        }
        cout<<endl;
    }
}
void addVertex() {
    
    vector<int> *newadjLists;
    newadjLists = new vector<int>[numVertices+1];

    for(int i=0;i< numVertices;i++){
        for(int j=0;j< adjLists[i].size();j++){
             newadjLists[i].push_back(adjLists[i][j]);
        }
    }

    delete adjLists;
    adjLists=newadjLists;
    numVertices++;


    int edges;
    cout<<"\nEnter number of edges to this vertex:";
    cin>>edges;
    int vertex;
    for (int i = 0; i < edges; i++)
    {
        cout<<"vexter no "<<i+1<<" : ";
        cin>>vertex;
        adjLists[numVertices-1].push_back(vertex);
        adjLists[vertex].push_back(numVertices-1);
    }
    
    
    BFS(numVertices-1);
}

void BFS(int start){

    for (int i = 0; i < numVertices; i++)
  {
      visited[i]=false;
  }

  queue<int>q;
  q.push(start);
  visited[start]=true;

  while(!q.empty()){
    int vertex=q.front();
    cout<<vertex<<" ";
    q.pop();

    for(int i=0;i<adjLists[vertex].size();i++){
      if(!visited[adjLists[vertex][i]]){
        q.push(adjLists[vertex][i]);
        visited[adjLists[vertex][i]]=true;
      }
    }
  }
}

//function for dfs traversal
void DFSI(int start){

    for (int i = 0; i < numVertices; i++)
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

    for(int i=0;i<adjLists[vertex].size();i++){

      if(!visited[adjLists[vertex][i]]){
        stk.push(adjLists[vertex][i]);
        visited[adjLists[vertex][i]]=true;
      }
      
    }
  }
}


  void DFS(int vertex) {

  visited[vertex] = true;
  cout << vertex << " ";
  for (int i = 0; i <= adjLists[vertex].size(); ++i)
    if (visited[i]==false)
      DFS(i);
}


};


int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);

  g.DFS(0);
  cout<<endl;
  g.BFS(0);
  cout<<endl;
  g.DFSI(0);
  g.addVertex();

  return 0;
}