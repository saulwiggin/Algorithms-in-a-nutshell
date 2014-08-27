/** 
* Given undirected graph, compute MST starting from a randomly
* selectyed vertex. Encoding of MST is done using 'pred' entries. 
*/

void mst_prim (Graph const &graph, vector <int> &pred){
	//initialize pred[] and key[] arrays. Start with arbitrary
	// vertex s= 0. Priority Queue PQ contains all v in G.
	const int n = graph.numVertices();
	pred.assign(n,-1);
	vector<inht> key(n,numeric_limits<int>::max());
	key[0] = 0;
	BinaryHeap pq(n);
	vector<bool> inQueue(n,true);
	for (int v = 0; v < n; v++) {
		pq.insert(v,key[v]);
	}
	
	while (!pq.isEmpty()) {
		int u = pq.smallest();
		inQueue[u] = false;
		
		// Process all neighbours of u to find if any edge beats best distance
		for (vertexList::const_iterator ci = graph.begin(u);
			ci != graph.end(u); ++ci) {
		int v = ci -> first;
		if (inQueue[v]) {
			int w = ci->second;
			if (w < key[v]) {
				pred[v] = u;
				key[v] = w;
				pq.decreaseKey(v,q);
			}
		}
	}
}
}