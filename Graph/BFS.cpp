#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<int> G[], int u, int v)
{
    G[u].push_back(v);
    /* For undirected graph */
    G[v].push_back(u);
}

void display(int V, vector<int> adj[])
{
    for (int i = 1; i <= V; i++)
    {
        cout<<i<<"->";
        for (auto it = adj[i].begin(); it != adj[i].end(); ++it)
            cout<<(*it)<<"->";
        cout<<"\n";
    }
}

void BFS(int V, int v, vector<int> adj[])
{
    bool visited[V+1];
    for (int i = 1; i <= V; i++)
        visited[i] = false;

    deque<int> dq;
    visited[v] = true;
    dq.push_back(v);

    while(!dq.empty())
    {
        cout<<dq.front()<<" ";
        int u = dq.front();
        dq.pop_front();

        for (auto it = adj[u].begin(); it != adj[u].end(); ++it)
        {
            if (!visited[*it])
            {
                visited[*it] = true;
                dq.push_back(*it);
            }
        }
    }
}

int main()
{
    /* No of Vertices */
    int V = 6;
    /* Graph represented as adjacency list */
    vector<int> Graph[V+1];
    add_edge(Graph, 1, 2);
    add_edge(Graph, 2, 3);
    add_edge(Graph, 3, 4);
    add_edge(Graph, 3, 6);
    add_edge(Graph, 5, 6);
    add_edge(Graph, 4, 5);

    /* Breadth first search */
    cout<<"Breadth first search : ";
    BFS(V, 1, Graph);
    cout<<"\n";

    return 0;
}