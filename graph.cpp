#include <iostream>
#include <vector>
//#define E 5
#define V 5
using namespace std;

void dfs(int node, int visited[], vector<vector<int>> adjMatrix, vector<int> &ans, int &count)
{
    visited[node] = 1;
    ans.push_back(node);
    count++;

    int numNodes = adjMatrix.size();
    for (int i = 0; i < numNodes; i++)
    {
        if (visited[i] == 0 && adjMatrix[node][i] > 0)
        {
            dfs(i, visited, adjMatrix, ans, count);
        }
    }
}

void discon0Rconnected(vector<vector<int>> adjMatrix)
{

    int count = 0;
    int visited[V] = {0};
    vector<int> ans;

    int startNode = 0;

    dfs(startNode, visited, adjMatrix, ans, count);

    if (count == V)
    {
        cout << "Graph is connected" << endl;
    }
    else
    {
        cout << "Graph is disconnected" << endl;
    }
}

int main()
{
    // Adj matrix with weights
    vector<vector<int>> adjMatrix = {{0, 2, 3, 0, 0},
                                     {2, 0, 15, 2, 0},
                                     {3, 15, 0, 0, 13},
                                     {0, 2, 0, 0, 9},
                                     {0, 0, 13, 9, 0}};

    discon0Rconnected(adjMatrix);

    return 0;
}