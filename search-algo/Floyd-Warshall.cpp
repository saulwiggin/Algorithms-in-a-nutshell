#include "Graph.h"

void allPairsShortest(Graph const &graph,
						vector < vector<int> > &dist, /* out */
						vector <vector<int> > &pred) {	/* out */
	int n = graph.numVertices();
	
	//Intialize dist[][] with 0 on diagonals, INFIINITY where no edge
	// exists, and the weight of the edge (u,v) places in dist[u][v]. pred// initialised in corresponding way.
	for (int u = 0; u < n; u++) {
		dist[u].assign(n, numeric_limits<int>::max());
		pred[u].assign(n,-1);
		dist[u][u] = 0;
		for (VertexList::const_iterator ci = graph.begin(u);
			ci != graph.end(u); ++ci) {
		int v = ci -> first;
		dist[u][v] = ci ->second;
		pred[u][v] = u;
		}
	}
	
	for (int k = 0; k < n; k++){
		for int i = 0; i < n; i++) {
			if (dist[i][k] == numeric_limits<int>::max()) {continue;}
			
			// If an edge is found to reduced distance, update dist[][].
			// Compute using longs to avoid overflow of inifint-distance.
			for (int j = 0; j < n; j++) {
				long newLen = dist[i][k];
				newLen += dist[k][j];
				
				if ( newLen < dist[i][j]){
					dist[i][j] = newLen;
					pred[i][j] = pred[k][j];
					}
				}
			}
		}
	}
					