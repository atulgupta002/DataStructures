// Assignment 4 - Atul Gupta

#include <iostream>
#include <list>
#include <queue>

using namespace std;

// C++ class to implement graphs
class Graph
{ // graph class
  // add necessary attributes to represent graph

public:
  // add required member function to represent graph
  int numVertices;
  list<int> *vertexList;
  bool *visited; // to track if a node has been visited.

  // Class constructor
  Graph(int n)
  {
    numVertices = n;
    vertexList = new list<int>[n];
    visited = new bool[n];
  }

  // Function to add an edge and a node to the graph.
  void addEdge(int a1, int a2)
  {
    vertexList[a1].push_back(a2);
    vertexList[a2].push_back(a1);
  }

  // Function to add an edge to undirected graph.
  void addEdgeUndirected(int a1, int a2)
  {
    vertexList[a1].push_back(a2);
  }

  // Function to implement Breadth First Search on a graph.
  void
  BFS(int startNode)
  {
    // implement BFS
    visited[startNode] = true;
    queue<int> q;
    q.push(startNode);

    while (!q.empty())
    {
      int current = q.front();
      cout << current << " ";
      q.pop();

      for (int adjacent : vertexList[current])
      {
        if (!visited[adjacent])
        {
          visited[adjacent] = true;
          q.push(adjacent);
        }
      }
    }
  }

  // Function to implement Depth First Search on a graph.
  void DFS(int startNode)
  {
    // implement DFS
    visited[startNode] = true;
    cout << startNode << " ";
    DFS_Recursive(startNode);
    clearVisits(numVertices);
  }

  void DFS_Recursive(int vertex)
  {
    for (int adjacent : vertexList[vertex])
    {
      // If the adjacent node is not yet visited, print the value and visit the next node.
      if (!visited[adjacent])
      {
        cout << adjacent << " ";
        visited[adjacent] = true;
        DFS_Recursive(adjacent);
      }
    }
  }

  // Function to clear the visited variable of al the nodes.
  void clearVisits(int n)
  {
    for (int i = 0; i < n; i++)
    {
      visited[i] = false;
    }
  }
};

// Driver code
int main()
{
  // main function
  int n = 11;
  Graph g(n);
  g.addEdge(1, 2);
  g.addEdge(1, 4);
  g.addEdge(2, 5);
  g.addEdge(2, 4);
  g.addEdge(4, 5);
  g.addEdge(4, 5);
  g.addEdge(5, 3);
  g.addEdge(5, 9);
  g.addEdge(9, 10);
  g.addEdge(7, 10);
  g.addEdge(9, 7);

  g.BFS(1);

  g.clearVisits(n);
  cout << endl;

  g.DFS(1);
}
