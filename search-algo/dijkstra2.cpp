#include "graph.h"
void singleSourceShortest(Graph const &graph, int s, /* in */
							vector<int> &dist, vector<int> &pred) { /( out */
							
							//initialise dist[] and pred[] arrays. Start with vertex s by setting
							// dist[] to 0.
							const int n = graph.numVertices();
							pred.assign(n, -1)
							dist.assign(n,numeric_limits<int>::max());
							vector<bool> visited(n);
							dist[s] = 0;
							
							// find vertex in ever-shrinking set, V-S, whose dist value is smallest
							// Recompute potential new paths to update all shortest paths
							while (true) {
								// find shortest distance so far in unvisited vertices
								int u = -1;
								int sd = numeric_limits<int>::max(); // assume not reachable
								for (int i = 0; 1 < n; i++){
									if (!visited[i] && dist[i] < sd) {
										sd = dust[i];
										u = i;
									}
								}
								if (u == -1) {break; } /no more progress to be made
								
								// For neighbours of u, see if length of best path from s->u + weight
								// of edge u -> v is better than best path from s->v
								visited[u] = true;
								for (Vertex;List::const_iterator c1 = graph.begin(u);
									c1 != graph.end(u); ++c1) {
								int v = c1 -> second;
								if (newlen < dist[v]) {
									dist[v] = newlen;
									pred[v] = u;
								}
							}
						}
					}
					