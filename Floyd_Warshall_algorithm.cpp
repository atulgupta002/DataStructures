#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Edge;

class Vertex
{
public:
    int id;
    vector<Edge *> adjList;

    Vertex() {}

    Vertex(int id)
    {
        this->id = id;
    }

    int getID()
    {
        return id;
    }

    vector<Edge *> getAdjList()
    {
        return adjList;
    }
};

class Edge
{
public:
    Vertex *start;
    Vertex *end;
    int weight;

    Edge(Vertex *start, Vertex *end, int weight)
    {
        this->start = start;
        this->end = end;
        this->weight = weight;
    }

    int getWeight()
    {
        return weight;
    }

    Vertex *getStart()
    {
        return start;
    }

    Vertex *getEnd()
    {
        return end;
    }
};

vector<Vertex *> vertices;
vector<Edge *> edges;

Vertex *getVertex(int id)
{
    for (auto current : vertices)
    {
        if (current->id == id)
        {
            return current;
        }
    }
    return nullptr;
}

void addEdge(Vertex *start, Vertex *end, int weight)
{
    Edge *edge = new Edge(start, end, weight);
    start->adjList.push_back(edge);
    edges.push_back(edge);
    if (!getVertex(start->id))
    {
        vertices.push_back(start);
    }
    if (!getVertex(end->id))
    {
        vertices.push_back(end);
    }
}

int **getWeightMatrix()
{
    int n = vertices.size();
    int **W = new int *[n];

    for (int i = 0; i < n; i++)
    {
        W[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                W[i][j] = 0;
            }
            else
            {
                W[i][j] = INT_MAX;
            }
        }
    }

    for (auto vertex : vertices)
    {
        int startID = vertex->id;

        vector<Edge *> edges = vertex->adjList;
        int endID;

        for (auto edge : edges)
        {
            if (edge->start->id == startID)
            {
                endID = edge->end->id;
            }
            else
            {
                endID = edge->start->id;
            }
            W[startID - 1][endID - 1] = edge->weight;
        }
    }
    return W;
}

void printMatrix(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] < -1000 || matrix[i][j] > 1000)
            {
                cout << "I"
                     << " ";
            }
            else
            {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}

// Floyd Warshall algorithm to find the shortest distance between two vertices on a directed graph.
void floydWarshall()
{
    int n = vertices.size();
    int **W = getWeightMatrix();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (W[i][k] != INT_MAX && W[j][i] != INT_MAX && W[j][i] + W[i][k] < W[j][k])
                    W[j][k] = min(W[j][k], W[j][i] + W[i][k]);
            }
        }
    }
    printMatrix(W, n);
}

// Driver code.
int main()
{
    // complete the main function
    Vertex *one = new Vertex(1);
    Vertex *two = new Vertex(2);
    Vertex *three = new Vertex(3);
    Vertex *four = new Vertex(4);

    addEdge(one, two, 8);
    addEdge(one, four, 1);
    addEdge(two, three, 1);
    addEdge(three, one, 4);
    addEdge(four, two, 2);
    addEdge(four, three, 9);

    cout << "Shortest distance matrix: " << endl;
    floydWarshall();

    return 0;
}
