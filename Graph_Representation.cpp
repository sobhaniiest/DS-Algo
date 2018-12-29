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
 }
