#include <bits/stdc++.h>
using namespace std;

void edge (vector<int> G[], int u, int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}

void dfs(int v, vector<int> G[], vector<bool> &visited, bool *flag, int *parent)
{
	visited[v] = true;
	for (auto it = G[v].begin(); it != G[v].end(); it++)
	{
		if (!visited[*it])
		{
			(*parent) = v;
			dfs(*it, G, visited, flag, parent);
		}
		else if (visited[*it] && (*it) != (*parent))
			(*flag) = true;
	}
}

bool Detect_Cycle(int n, vector<int> G[])
{
	vector<bool> visited(n+1, false);
	bool flag = false;
	int parent = 0;

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
			dfs(i, G, visited, &flag, &parent);
	}

	return flag;
}

int main()
{
	int n = 6;
	vector<int> G[n+1];
	edge(G, 1, 2);
	edge(G, 1, 6);
	edge(G, 2, 3);
	edge(G, 3, 4);
	edge(G, 4, 5);
	edge(G, 5, 2); // remove - no cycle

	if (Detect_Cycle(n, G))
		cout << "Cycle Found!" << endl;
	else
		cout << "Cycle not Found" << endl;
}