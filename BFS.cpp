 #include <bits/stdc++.h>
 using namespace std;

 void edge(vector<int> G[], int u, int v)
 {
     G[u].push_back(v);
     G[v].push_back(u);
 }

 void disp(vector<int> G[], int v)
 {
     cout<<"Adjacency List Representation:\n";
     for(int i=0;i<v;i++)
     {
         cout<<i;
         for(auto j=G[i].begin();j!=G[i].end();j++)
            cout<<" -> "<<*j;
         cout<<"\n";
     }
 }

 void BFS(vector<int> G[], int v)
 {
     vector<int> visit;
     deque<int> qu;
     for(int i=0;i<v;i++)
        visit.push_back(0);
     int s = 2;
     qu.push_back(s);
     visit[s] = 1;
     cout<<"\nBreadth First Traversal : \n";
     while(!qu.empty())
     {
         s = qu.front();
         cout<<s<<" ";
         qu.pop_front();
         for(auto x=G[s].begin();x!=G[s].end();x++)
         {
             if(!visit[*x])
             {
                 visit[*x]=1;
                 qu.push_back(*x);
             }
         }
     }
     cout<<"\n";
 }

 int main()
 {
     int v = 5;
     vector<int> G[v];
     edge(G, 0, 1);
     edge(G, 0, 4);
     edge(G, 1, 2);
     edge(G, 1, 3);
     edge(G, 1, 4);
     edge(G, 2, 3);
     edge(G, 3, 4);

     disp(G, v);

     BFS(G, v);
 }
