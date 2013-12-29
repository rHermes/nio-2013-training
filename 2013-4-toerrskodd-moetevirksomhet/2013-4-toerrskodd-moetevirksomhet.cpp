// 2013-4-toerrskodd-moetevirksomhet.cpp
#include <iostream>
#include <set>
#include <vector>
#include <sys/types.h>
#include <limits>
#include <algorithm>
#include <utility>

using namespace std;

typedef vector < vector<int> > Graph_t;

// My own implementation of Dijkstra's algorithem, tweaked to fit
// the task.
vector<int64_t> Dijkstra(Graph_t &Graph, unsigned source) {

  // Now we have a basic vector, with the costs.
  vector<int64_t> dist(Graph.size(), numeric_limits<int64_t>::max());
  vector<int64_t> previous(Graph.size(), -1);
  
  // setting our starting point.
  dist[source] = 0;

  // Make a list of all nodes.
  set<int> Q;
  
  for(int i = 0; i < Graph.size(); ++i) {
    Q.insert(i);
  }

  while(Q.size()) {
    int64_t min = numeric_limits<int64_t>::max();
    unsigned min_node = 0;

    // Select the node with the lowest distance
    for(set<int>::iterator it=Q.begin(); it != Q.end(); it++) {
      if (dist[*it] < min) {
	min = dist[*it];
	min_node = *it;
      }
    }
    // Now we have our vertex u.
    // vector<edge> &u = Graph[min_node];
    unsigned u = min_node;
    Q.erase(u);

    if(dist[u] == numeric_limits<int64_t>::max())
      break;

    for(int v = 0; v < Graph[u].size(); ++v) {
      // If the edge is -1 it doesn't exist
      if(Graph[u][v] == -1)
	continue;

      // now we only need to add the value of it.
      int64_t alt = dist[u] + Graph[u][v];
      if (alt < dist[v]) {
	dist[v] = alt;
	previous[v] = u;
      }
    }
  }
  return previous;
}

// Calculate the  finally weight.
int64_t calc_weight(vector<int64_t>a, vector<int64_t> b, vector<int64_t> c, Graph_t &Graph) {
  int64_t min = numeric_limits<int64_t>::max();
  for(int i = 0; i < Graph.size(); ++i) {
    set< pair<int, int> > edges;

    // Finding all uniqe edges.
    {
      int64_t u = i;
      while(a[u] != -1) {
	if(a[u] > u)
	  edges.insert(make_pair(a[u], u));
	else
	  edges.insert(make_pair(u, a[u]));

	u = a[u];
      }

      u = i;
      while(b[u] != -1) {
	if(b[u] > u)
	  edges.insert(make_pair(b[u], u));
	else
	  edges.insert(make_pair(u, b[u]));

	u = b[u];
      }

      u = i;
      while(c[u] != -1) {
	if(c[u] > u)
	  edges.insert(make_pair(c[u], u));
	else
	  edges.insert(make_pair(u, c[u]));

	u = c[u];
      }
    }
    int64_t minCurPath = 0;
    for(set< pair<int, int> >::iterator it = edges.begin(); it != edges.end(); ++it) {
      minCurPath += Graph[it->first][it->second];
    }

    if (minCurPath < min)
      min = minCurPath;
  }
  return min;
}

int main(void) {
  int n, m;
  cin >> n >> m;

  // Create our graph!
  Graph_t inGraph;
  inGraph.resize(n, vector<int>(n, -1));
  
  // Fill the graph with content
  for(int i = 0; i < m; ++i) {
    int a, b, k;
    cin >> a >> b >> k;
    inGraph[a][b] = k;
    inGraph[b][a] = k;
  }

  // get the cordinates for the three nodes we want to connect
  int a, b, c;
  cin >> a >> b >> c;

  vector<int64_t> minA = Dijkstra(inGraph, a);
  vector<int64_t> minB = Dijkstra(inGraph, b);
  vector<int64_t> minC = Dijkstra(inGraph, c);

  
  // okay now to find the least costly graph. Let us calculate this for each of the nodes in the graph.
  int64_t answer = calc_weight(minA, minB, minC, inGraph);

  cout << answer << endl;
  return 0;
}
