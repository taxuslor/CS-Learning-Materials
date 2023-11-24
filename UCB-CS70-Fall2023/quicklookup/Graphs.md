- *Formal definitons: a (undirected) graph is defined by a set of vertices V and a set of edges E. Here we require E to be a set but not a multi-set (a set where an element can appear multiple times). A graph is formally specified as an ordered pair G = (V,E), where V is the vertex set and E is the edge set.*
- We say that edge *e* = {*u*, *v*} (or *e* = (*u*, *v*)) is *incident* on vertices *u* and *v*, and that *u* and *v* are *neighbors* or *adjacent*.
- *If G is undirected, then the degree of vertex u ∈ V is the number of edges incident to u, i.e., degree*(*u) = |{v ∈ V : {u, v} ∈ E }|. A vertex u whose degree is 0 is called an isolated vertex.*
- *For a directed graph, the in-degree of a vertex u is the number of edges from other vertices to u, and the out-degree of u is the number of edges from u to other vertices.*
- *A self-loop: {u,u}.*
- *Let G = (V,E) be an undirected graph.
  A path in G is a sequence of edges {v1,v2} {v2,v3}...{vn-2,vn-1}{vn-1,vn} where v1,...,vn are distinct. We say that there is a path between v1 and vn. 
  A cycle in G is a sequence of edges {v1,v2} {v2,v3}...{vn-1,vn}{vn,v1} where v1,...,vn are distinct.
  A walk in G is a sequence of edges with possibly repeated vertices.
  A tour in G is  a walk which starts and ends at the same vertex.*
- *A graph is said to be connected if there is a path between any two distinct vertices. Any graph (even a disconnected one ) always consists of a collection of collected components.*
- *Given a graph G, an Eulerian walk uses each edge ecactly once. Moreover, if an Eulerian walk is closed, then it is called Eulerian tour.*
- *Theorem 5.1 (Euler's Theorem(1736)). An undirected graph G = (V,E) has an Eulerian tour iff G is even degree, and connected (except possibly for isolated vertices).*
- *A graph is a tree if it is connected and acyclic (contains no cycles). A tree is a connected graph where the number of vertices is one more than the number of edges. A tree is a connected graph such that if you delete any edge it becomes disconnected.*
- *A graph is planar if it can be drawn on the plane without crossings.*
- *A bipartite graph, G = (V,E) which is a graph where the vertices are split into two groups and edges only go between groups.*
- *When a planar graph is drawn on the plane, one can distinguish, besides its vertices (their number will be denoted v here) and edges (their number is e), the faces of the graph (more precisely, of the drawing). The faces are the regions into which the graph subdivides the plane. One of them is infinite, and the others are finite. The number of faces is denoted f .*
- *Theorem 5.2. (Euler's formula) For every connceted planar graph, v + f = e + 2.*
- *Denote by si the number of sides of face i. In any planar graph, ∑(i=1,f) si = 2e.*
- *If we assume that there are at least two edges, every face has at least three sides. If follows that 3f <= 2e. Solving for f and plugging into Euler's formula we get e <= 3v - 6.*
- *Theorem 5.3. A graph is non-planar if and only if it contains K5 or K3,3.*
- *Take a planar graph G, and assume it has no bridges and no degree-two nodes. Draw a new graph G\*: Start by placing a node on each face of G. Then draw an edge between two faces if they touch at an edge — draw the new edge so that it crosses that edge. The result is G\*, also a planar graph. Notice now that, if you construct the dual of G\*, it is the original graph: (G\*)\* = G.*
- *Theorem 5.4. Every planar graph can be colored with five colors.*
- Complete graphs: In an undirected complete graph, every pair of (distinct) vertices u and v are connected by an edge {u, v}. The notation Kn denotes the unique complete graph on n vertices. Complete graphs are "maximally connected".
- Trees: Trees are "minimally connected". Formally, there are a number of equivalent definitions of when a graph *G* = (*V*,*E*) is a tree, including:
  1. *G* is connected and contains no cycles.
  2. *G* is connected and has *n*1 edges (where *n* = |*V*|).
  3. *G* is connected, and the removal of any single edge disconnects *G*. 
  4. *G* has no cycles, and the addition of any single edge creates a cycle.
- Rooted Trees: In a rooted tree, there is a designated node called the *root*, which we think of as sitting at the top of the tree. The bottom-most nodes are called *leaves*, and the intermediate nodes are called *internal nodes*. Note that in a rooted tree, a root is never a leaf. In particular, this differs from an unrooted tree; in an unrooted tree, *leaves* are any vertex of degree 1. The *depth d* of the tree is the length of the longest path from the root to a leaf. Moreover, the tree can be thought of as grouped into layers or *levels*, where the *k*-th level for *k* 2 {0,1,...,*d*} is the set of vertices which are connected to the root via a path consisting of precisely *k* edges.
- *Theorem 5.5. The statements “G is connected and contains no cycles” and “G is connected and has n - 1 edges” are equivalent.*
- Hypercubes: The vertex set of the *n*-dimensional hypercube *G* = (*V*,*E*) is given by *V* = {0,1}*n*, where recall {0,1}*n* denotes the set of all *n*-bit strings. In other words, each vertex is labeled by a unique *n*-bit string, such as 00110···0100. The edge set *E* is defined as follows: Two vertices *x* and *y* are connected by edge {*x*,*y*} if and only if *x* and *y* differ in exactly one bit position. For example, *x* = 0000 and *y* = 1000 are neighbors, but *x* = 0000 and *y* = 0011 are not. More formally, *x* = *x*1*x*2 ...*x**n* and *y* = *y*1*y*2 ...*y**n* are neighbors if and only if there is an *i* 2 {1,...,*n*} such that *x**j* = *y**j* for all *j* 6= *i*, and *x**i* 6= *y**i*. 
- *Lemma 5.1. The total number of edges in an n-dimensional hypercube is n(2^(n-1)).*
- *Theorem 5.6. Let S ⊆ V be such that |S| <= |V-S|(i.e., that |S| <= 2^(n-1)), and let Es denote the set of edges connecting S to V - S, i.e., Es = {{u,v} ∈ E| u ∈ S and v ∈ V - S}. Then, it holds that |Es| >= |S|.*