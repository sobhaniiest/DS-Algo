#include <bits/stdc++.h>
using namespace std;

void edge (vector<int> G[], int u, int v)
{
	G[u].push_back(v);
}

void dfs(int v, vector<int> G[], vector<bool> &gray, vector<bool> &black, bool *flag)
{
	gray[v] = true;
	for (auto it = G[v].begin(); it != G[v].end(); it++)
	{
		if (!gray[*it] && !black[*it])
			dfs(*it, G, gray, black, flag);
		else if (gray[*it] && !black[*it])
			(*flag) = true;
	}
	black[v] = true;
}

bool Detect_Cycle(int n, vector<int> G[])
{
	vector<bool> gray(n, false);
	vector<bool> black(n, false);
	bool flag = false;
	// white set
	for (int i = 1; i <= n; i++)
		dfs(i, G, gray, black, &flag);

	return flag;
}

int main()
{
	int n = 6;
	vector<int> G[n+1];
	edge(G, 1, 2);
	edge(G, 2, 3);
	edge(G, 1, 3);
	edge(G, 4, 5);
	edge(G, 5, 6);
	edge(G, 6, 4); // edge(G, 4, 6);
	edge(G, 4, 1);

	if (Detect_Cycle(n, G))
		cout << "Cycle Found!" << endl;
	else
		cout << "Cycle not Found" << endl;
}