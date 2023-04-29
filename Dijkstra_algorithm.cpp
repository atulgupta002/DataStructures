#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Edge;

// Vertex class
class Vertex
{
public:
    char label;
    int dist;
    // add additional attribute and/or member function
    vector<Edge *> adjList;
    bool visited;

    Vertex(char label)
    {
        this->label = label;
        dist = 0;
        visited = false;
    }

    char getLabel()
    {
        return label;
    }
    int getDist()
    {
        return dist;
    }

    vector<Edge *> getList()
    {
        return adjList;
    }
};

// Edge class
class Edge
{
public:
    Vertex *start;
    Vertex *end;
    int weight;

    // add additional attribute and/or member function
    Edge(Vertex *start, Vertex *end, int weight)
    {
        this->start = start;
        this->end = end;
        this->weight = weight;
    }

    Vertex *getStart()
    {
        return start;
    }

    Vertex *getEnd()
    {
        return end;
    }

    int getWeight()
    {
        return weight;
    }
};

vector<Vertex *> vertices;
vector<Edge *> edges;

// Function to add an edge to the graph.
void addEdge(Vertex *start, Vertex *end, int weight)
{
    Edge *edge = new Edge(start, end, weight);
    start->adjList.push_back(new Edge(start, end, weight));
    end->adjList.push_back(new Edge(start, end, weight)); // for undirected graphs.
    if (std::find(vertices.begin(), vertices.end(), start) == vertices.end())
    {
        vertices.push_back(start);
    }
    if (std::find(vertices.begin(), vertices.end(), end) == vertices.end())
    {
        vertices.push_back(end);
    }
    edges.push_back(edge);
}

// Function to execute Dijsktra's algorithm on the graph from the vertex 'start'.
void dijkstra(Vertex *start)
{
    // implement dijkstra's algo to find the shortest path
    priority_queue<Vertex *> pq;
    for (auto current : vertices)
    {
        current->dist = INT_MAX;
    }
    start->dist = 0;
    pq.push(start);

    while (!pq.empty())
    {
        Vertex *current = pq.top();
        pq.pop();
        for (Edge *edge : current->adjList)
        {
            Vertex *neighbor = edge->end;
            int dist_through_u = current->dist + edge->weight;
            if (dist_through_u < neighbor->dist)
            {
                neighbor->dist = dist_through_u;
                pq.push(neighbor);
            }
        }
    }

    // Printing the distances of all the verticies from the start vertex.
    for (auto vertex : vertices)
    {
        cout << vertex->label << " " << vertex->dist << endl;
    }
}

// Driver code.
int main()
{
    // complete the main function
    Vertex *A = new Vertex('A');
    Vertex *B = new Vertex('B');
    Vertex *C = new Vertex('C');
    Vertex *D = new Vertex('D');
    Vertex *E = new Vertex('E');
    Vertex *F = new Vertex('F');
    Vertex *G = new Vertex('G');

    addEdge(A, B, 1);
    addEdge(A, C, 3);
    addEdge(A, F, 10);
    addEdge(B, C, 1);
    addEdge(B, D, 7);
    addEdge(B, E, 5);
    addEdge(B, G, 2);
    addEdge(C, D, 9);
    addEdge(C, E, 3);
    addEdge(D, E, 2);
    addEdge(D, F, 1);
    addEdge(D, G, 12);
    addEdge(E, F, 2);

    dijkstra(A);

    return 0;
}
