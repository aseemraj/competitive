#include <iostream>
using namespace std;

const int MAXBUILDINGS = 40;
const int MAXEDGES = 800;

bool conns[MAXBUILDINGS][MAXBUILDINGS];
int vals[MAXBUILDINGS];
int bestCost;

struct edge {
    int i, j;
    int cost;
    bool used;
} edges[MAXEDGES];
bool best[MAXEDGES];


int visit(int v, int prev, int num, int n, bool& biConn)
//
// standard modified DFS method to check for biconnectivity
//
{
    int min;
    vals[v] = num;
    min = num;
    for(int i=0; i<n; i++) {
        if (conns[v][i]) {
            if (vals[i] == -1) {
                int m = visit(i, v, num+1, n, biConn);
                if (!biConn)
                    return -1;
                if (m < min)
                    min = m;
                if (m > vals[v]) {
                    biConn = false;
                    return -1;
                }
            }
            else if (i != prev && vals[i] < min)
                min = vals[i];
        }
    }
    return min;
}

bool biConnected(int n)
/*
 * check if graph is biconnected 
 */
{
    int j, k;
    for(k=1; k<n; k++) {
        vals[k] = -1;
    }
    vals[0] = 0;
    bool biConn = true;
    for(j=0; j<n; j++) {
        if (vals[j] == -1 && conns[0][j]) {     // unused connection
            int min = visit(j, 0, 1, n, biConn);
            if (min > 0 || !biConn)
                return false;
        }
    }
//  j++;
//  for(;j<n; j++)
//      if (conns[0][j] && vals[j] == -1)
//          return false;
    for(k=1; k<n; k++)
        if (vals[k] == -1)
            return false;
    return true;
}

void bestBiConn(int e, int maxedges, int minedges, int cost, int n)
//
// recursively builds all subgraphs and checks to see if they are
//   biconnected
//
// updates global bestCost whenever it finds a biconnected graph with
//   loweer cost than previous ones
//
// search bounded by current lowest cost (bestCost) of previous subgraphs
//
// e - current edge to consider
// maxedges - maximum number of edges in graph
// minedges - minimum number of edges remaining to add to get enough edges
//            to check for biconnectivity
// cost - current cost of edges used in graph
// n - number of nodes in graph (passed to biConnected())
//
{
    if (e == maxedges)
        return;
    int i = edges[e].i;
    int j = edges[e].j;
    edges[e].used = true;
    conns[i][j] = conns[j][i] = true;
    minedges--;
    cost += edges[e].cost;
    if (cost < bestCost) {
        if (minedges > 0)               // not enough edges to be biconnected yet
            bestBiConn(e+1, maxedges, minedges, cost, n);
        else {
            if (biConnected(n)) {
                bestCost = cost;
                for(int k=0; k<maxedges; k++)
                    best[k] = edges[k].used;
            }
            bestBiConn(e+1, maxedges, minedges, cost, n);
        }

    }
    edges[e].used = false;
    conns[i][j] = conns[j][i] = false;
    minedges++;
    cost -= edges[e].cost;
    bestBiConn(e+1, maxedges, minedges, cost, n);
}

int getNextEdge(int m)
/*
 * return the unchecked edge with highest cost
 */
{
    int maxVal = -1;
    int e = -1;
    for(int i=0; i<m; i++) {
        if(!edges[i].used && edges[i].cost > maxVal) {
            maxVal = edges[i].cost;
            e = i;
        }
    }
    return e;
}

void getEstimate(int n, int m)
// 
//  get an estimate of the min cost by removeing each edge, largest to
//  smallest:
//    if removal still results in biconnected graph
//       then discard edge
//       else use it in final solution
//
{
    for(int k=0; k<m; k++) {
        int e = getNextEdge(m);
        edges[e].used = true;
        int i = edges[e].i;
        int j = edges[e].j;
        conns[i][j] = conns[j][i] = false;
        if (biConnected(n)) {
            bestCost -= edges[e].cost;      // biconnected graph exists without this edge
        }
        else {
            conns[i][j] = conns[j][i] = true;
        }
    }
}

int main()
{
    int n, m, i, j, k;
    cin >> n >> m;
    int ncases = 0;
    while (n != 0) {
        ncases++;
        for(i=0; i<n; i++) {
            for(j=0; j<n; j++) {
                conns[i][j] = false;
            }
        }
        bestCost = 0;
        for(k=0; k<m; k++) {
            cin >> i >> j;
            edges[k].i = i-1;
            edges[k].j = j-1;
            cin >> edges[k].cost;
            bestCost += edges[k].cost;
            edges[k].used = false;      // initializations for getEstimate
            conns[j-1][i-1] = conns[i-1][j-1] = true;
        }

        if (!biConnected(n))
            cout << "There is no reliable net possible for test case " << ncases << "." << endl;
        else {
            getEstimate(n, m);          // get estimate of lowest cost...
            bestCost++;                 // .. and make sure bestBiConn can
                                        //   at least find this solution

                                        // initialize for bestBiConn by
                                        //   removing all edges from graph
            for(i=0; i<n; i++)
                for(j=0; j<n; j++)
                    conns[i][j] = false;
            for(i=0; i<m; i++)
                edges[i].used = false;
            bestBiConn(0, m, n, 0, n);  // now solve problem for real

            cout << "The minimal cost for test case " << ncases << " is " << bestCost << "." << endl;
        }

        cin >> n >> m;
    }
return 0;
}