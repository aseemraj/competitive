// change int to desired type of edge weight
typedef int edge_weight;
typedef pair< int, edge_weight > pairInt;

class Graph
{
    int n;
    vector< vector< pairInt > > edge;
    vector< int > level;
    vector< bool > visited;
    int start_node;
    vector< edge_weight > dist;
    
    public:
    Graph(int num);
    void input(int n1,int n2,edge_weight w);
    bool isBipartite();
    void dfs(int num);
    void bfs(int num);
    void dijkstra(int source, int destination);
    edge_weight return_dist(int destination);
    void test();
};

Graph :: Graph(int num)
{
    n = num;
    vector< pairInt > v;
    v.clear();
    for(int i = 0;i < n;i++)
    {
        edge.push_back(v);
        level.push_back(-1);
        visited.push_back(false);
    }
    start_node = 0;
}

edge_weight Graph :: return_dist(int destination)
{
    return dist[destination];
}

void Graph :: input(int n1,int n2,edge_weight w = 0)
{
    edge[n1].push_back(make_pair(n2,w));
}

bool Graph :: isBipartite()
{
    bool ans = 1;
    bfs(start_node);
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
            bfs(i);
    }
    int n1, n2;
    vector< pairInt >::iterator it;
    for(int i = 0;i < n;i++)
    {
        n1 = i;
        for(it = edge[n1].begin();it != edge[n1].end();it++)
        {
            n2 = (*it).first;
            if( (abs(level[n1] - level[n2]))%2 == 0)
            {
                ans = 0;
                break;
            }
        }
        if(ans == 0)
            break;
    }

    return ans;
}

void Graph :: bfs(int num)
{
    int n1=num,n2;
    queue<int> q;
    q.push(n1);
    visited[n1] = 1;
    level[n1] = 0;
    while(!q.empty())
    {
        vector< pairInt >::iterator it;
        n1 = q.front();
        q.pop();
        for(it = edge[n1].begin(); it != edge[n1].end(); it++)
        {
            n2 = (*it).first;
            if(!visited[n2])
            {
                q.push(n2);
                visited[n2] = true;
                level[n2] = level[n1]+1;
            }
        }
    }


}

void Graph :: dijkstra(int source, int destination = -1)
{
    dist.clear();
    for(int i = 0; i < n; i++)
        dist.push_back(-1);
    priority_queue< pairInt, vector< pairInt >, compare > q;
    q.push(make_pair(source, 0));
    pair<int, edge_weight> p;
    int n1, n2;
    edge_weight w, d;
    int cnt = 0;
    while(!q.empty())
    {
        p = q.top();
        q.pop();
        n1 = p.first;
        w = p.second;
        if(dist[n1] == -1)
        {
            dist[n1] = w;
            cnt++;
            for(vector<pairInt >::iterator it = edge[n1].begin(); it != edge[n1].end(); it++)
            {
                n2 = it->first;
                d = w + it->second;
                if(dist[n2] == -1)
                    q.push(make_pair(n2, d));
            }
        }
        if(cnt == n || n1 == destination) break;
    }
}