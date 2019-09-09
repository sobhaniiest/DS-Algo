#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<int> G[], int u, int v)
{
    G[u].push_back(v);
    /* For undirected graph */
    //G[v].push_back(u);
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

void toposortuntil(int v, vector<int> adj[], bool visited[], stack<int> &st)
{
    visited[v] = true;

    for (auto it = adj[v].begin(); it != adj[v].end(); ++it)
    {
        if (!visited[(*it)])
            toposortuntil((*it), adj, visited, st);
    }

    st.push(v);
}

void topologicalsort(int V, vector<int> adj[])
{
    bool visited[V+1];

    for (int i = 1; i <= V; i++)
        visited[i] = false;

    stack<int> st;

    for (int i = 1; i <= V; i++)
    {
        if(!visited[i]){
            toposortuntil(i, adj, visited, st);
        }
    }

    cout<<"Topological sorting : ";
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
}

int main()
{
    /* No of Vertices */
    int V = 7;
    /* Graph represented as adjacency list */
    vector<int> Graph[V+1];
    add_edge(Graph, 1, 3);
    add_edge(Graph, 2, 3);
    add_edge(Graph, 3, 5);
    add_edge(Graph, 2, 4);
    add_edge(Graph, 5, 6);
    add_edge(Graph, 4, 6);
    add_edge(Graph, 6, 7);

    /* Topological Sorting */
    topologicalsort(V, Graph);

    return 0;
}