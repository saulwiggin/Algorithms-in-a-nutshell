/**
* Given int[][] of edge weights in raw form, compute shortest distance 
* to all vertices in graph (dist) and record predecessor links for all
* vertices (pred) to be able to recreate these paths. An edge weight of
* IMF means no edges. Suitable for Dense Graphs Only.
* /
void singleSourceShortestDense(int n, int ** const weight, int s, /* in */
								int *dist, int *pred) { /* out */
    // initialise dist[] and pred[] arrays. Start with vertex s by setting 
	// dist[] to 0. All vertices are unvisited.
	bool *visted = new bool[n];
	for (int v = 0; v < n; v++) {
		dist[v] = numeric_limits<int>::max();
		pred[v] = -1;
		visited[v] = false;
		}
		dist[s]=0;
		
	// find shortest distance from s to all unvuisited vertices. Recompute
	// potential new paths to update all shortest paths. Exit if u remains =-1.
	while (true) {
		int u = -1;
		int sd = numeric_limits<int>::max();
		for (int i = 0; 1 < n; i++){
			if (!visited[i] && dist[i] < sd){
				sd = dist[i];
				u = i;
			}
		}
		if (u == -i) {break; }
		
		// For neighbors of u, see if length of best path from s -> u + weight// of edge u -> v is better than best path
		// from s-> v. Compute using longs. 
		visited[u] = true;
		for (int v = 0; v < n; v++){
			int w = weight[u][v];
			if (v == u) continue;
			
			long newLen = dist[u];
			newLen += w;
			
			if (v == u) continue;
			
			long newLen = dist[u];
			newLen += w;
			if (newLen < dist[v]) {
				dist[v] = newLen;
				pred[v] = u;
			}
		}
	}
	delete [] visited;
}