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

void DFS_Recursive(int v, vector<int> adj[], bool visited[])
{
    visited[v] = true;
    cout<<v<<" ";

    for (auto it = adj[v].begin(); it != adj[v].end(); ++it)
    {
        if (!visited[*it])
            DFS_Recursive(*it, adj, visited);
    }
}

void DFS_Ittrative(int V, int v, vector<int> adj[])
{
    bool visited[V+1];
    for (int i = 1; i <= V; i++)
        visited[i] = false;

    stack<int> st;
    visited[v] = true;
    st.push(v);

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        int u = st.top();
        st.pop();

        for (auto it = adj[u].begin(); it != adj[u].end(); ++it)
        {
            if (!visited[*it])
            {
                visited[*it] = true;
                st.push(*it);
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

    /* Depth first search - Recursive */
    bool visited[V+1];
    for (int i = 1; i <= V; i++)
        visited[i] = false;

    cout<<"Depth first search Recursive: ";
    DFS_Recursive(1, Graph, visited);
    cout<<"\n";

    /* Depth first search - Ittrative */
    cout<<"Depth first search Ittrative: ";
    DFS_Ittrative(V, 1, Graph);
    cout<<"\n";

    return 0;
}