#include<bits/stdc++.h>
#define loop(i, a, b) for(int i=a;i<b;i++)
#define SIZE 100000
typedef long long ll;
using namespace std;
bool visited[SIZE];
class Graph
{
    int n;
    list<int> *adj;
    public:
        Graph(int n){this->n=n;adj=new list<int>[n];}
        void addEdge(int u, int v){adj[u].push_back(v);}
        void BFS(int s);
        void DFS(int v);
};
// BFS traversal of graph starting from node s
void Graph::BFS(int s)
{
    list<int> q;
    visited[s] = true;
    q.push_back(s);
    list<int>::iterator i;
    while(!q.empty())
    {
        s = q.front();
        // Do something with the node. Here we print it
        cout<<s<<' ';
        q.pop_front();
        for(i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                q.push_back(*i);
            }
        }
    }
}
// DFS traversal of graph
void Graph::DFS(int v)
{
    visited[v] = true;
    // Do something with the node. Here we print it
    cout<<v<<' ';
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFS(*i);
}
int main()
{
    ios_base::sync_with_stdio(0);
    Graph g(4);
    g.addEdge(3, 1);
    g.addEdge(3, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 0);
    g.addEdge(3, 0);

    // DFS start
    loop(i, 0, 4)visited[i]=false;
    loop(i, 0, 4)
        if(!visited[i])
            g.DFS(i);
    cout<<endl;
    // DFS end

    // BFS start
    loop(i, 0, 4)visited[i]=false;
    loop(i, 0, 4)
        if(!visited[i])
            g.BFS(i);
    // BFS end

    return 0;
}
