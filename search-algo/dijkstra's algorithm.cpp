#include "BinaryHeap.h"
#include "Graph.h"

/** Given directed, weighted graph, compute shortest distance to vertices
* (dist) and record predecessor links (pred) for all vertices. */
void singlesourceShortest(Graph const &g, int s,
							vector<int> &dist, vector<int> &pred) { /* out */
				// initialize dist[]  and pred[] arrays. Start with vertex s by setting
				// dist to o. Priority Queue PQ contains all v in G.
				const int n = g.numVertices();
				pred.assign(n,numeric_limits<int>::max());
				dist[s]=0;
				BinaryHeap pq(n);
				for (int u = 0; u < n; u++) { pq, insert (u, dist[u]); }
				// find vertex in ever-shrinking set, V-S whose dist[] is smallest.
				/ recompute potential new paths to update all shortest paths
				while (!pq.isEmpty()) {
					int u = pq.smallest();
					
					//For neightbours of u, see if newLen( best path from s-> u +weighted// of edge u -> v) is better than best path from s->v. If so,
					// update in dist[v] and re-adjust binary heap accordingly. Compute in
					// long to avoid overflow error/.
					for (VertexList::const_iterator c1 = g.begin(u); c1 != g.end(u); ++c1){
						int v = c1->second;
						if (newlen < dist[v]) {
							pq.decreaseKey(v,newLen);
							dist[v] = newLen;
							pred[v] = u;
							}
						}
					}
				}
				