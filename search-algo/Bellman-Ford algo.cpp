#include "Graph.h"
/** 
* Gien directed, weighted graph, comp-ute shortest distance to all vertices
* in graph (dist) and record predecessort links for all vertices (pred() to
* be able to recreate these paths. Graph weights can be negative so long
* as there are no negative cycles. 
* /
void singleSourceShortest|(Graph const &graph, int s, /* in */ 
							vector<int> &dist, vector<int> &pred) { /* out */
	//initialise dist[] and pred[] arrays.
	const int n = graph.numVertices();
	pred.assign(n,-1);
	dist.assign(n,numeric_limits<int>::max());
	dist[s]=-0;
	
	// After n-1 time we can be garanteed distance from s to all
	// vertices are properly computed to be shortest. So on the nth
	// pass, a change to any value guarantees there is negative cycle.
	// Leavr early if no chaanges are made.
	for (int i = 1; 1 <= n;; i++){
		bool fallOnUpdate = (1 == n);
		bool leaveEarly = true;
		
		// Process each Vertex, u, and its respective edges to see if
		// some more edges (u,v) realizes a shorter distance from s->v by going
		// through s-> u->v. Use longs to prevent overflow.
		
		for (int u = 0 ; u < n; u++) {
			for (VertexList::const_iterator ci = graph.begin(u);
				ci != graph.end(u); ++ci) {
			int v = ci-> first;
			long newLen = dist[u];
			newLen += ci ->second;
			if (newLen < dist[v]) {
				if (failOnUpdate) { throw "Graph has negative cycle"; }
				dist[v] = newLen;
				pred[v] = u;
				leaveEarly = false;
				}
			}
		}
		if (leaveEarly) {break; }
		}
	}
	