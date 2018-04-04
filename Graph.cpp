#include "Graph.h"

#include <cmath>
#include <algorithm>

Vertex::Vertex(GPS in): info(in) {}


Edge::Edge(int edgeId, long long id, double w): edgeId(edgeId), id(id), weight(w) {}

int Edge::getEdgeId() const {
	return edgeId;
}

long long Edge::getId() const {
	return id;
}

int Graph::getNumVertex() const {
	return vertexSet.size();
}

/*
 * Auxiliary function to find a vertex with a given content.
 */

Vertex * Graph::findVertex(const long long &id) const {
	auto it = vertexSet.find(id);

	if (it != vertexSet.end())
		return it->second;
	else
		return NULL;
}

/****************** 1a) addVertex ********************/

/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */

bool Graph::addVertex(const long long &id, const GPS &in) {
	return vertexSet.insert(std::pair<long long, Vertex*>(id, new Vertex(in))).second;
}

/****************** 1b) addEdge ********************/

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */


bool Graph::addEdge(const long long &sourcid, const long long &destid, int edgeId) {
	auto v1 = findVertex(sourcid);
	auto v2 = findVertex(destid);
	if (v1 == NULL || v2 == NULL)
		return false;

	v1->addEdge(edgeId, destid, v1->getInfo().distance(v2->getInfo()));
	return true;
}


bool Graph::addDoubleEdge(const long long &sourcid, const long long &destid, int edgeId) {
	auto v1 = findVertex(sourcid);
	auto v2 = findVertex(destid);
	if (v1 == NULL || v2 == NULL)
		return false;
	v1->addEdge(edgeId, destid, v1->getInfo().distance(v2->getInfo()));
	v2->addEdge(edgeId, sourcid, v1->getInfo().distance(v2->getInfo()));
	return true;
}


/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */

void Vertex::addEdge(int edgeId, long long id, double w) {
	adj.push_back(Edge(edgeId, id, w));
}

bool Vertex::operator<(Vertex & vertex) const {
	return (this->dist < vertex.getDist());
}


/****************** 1c) removeEdge ********************/

/*
 * Removes an edge from a graph (this).
 * The edge is identified by the source (sourc) and destination (dest) contents.
 * Returns true if successful, and false if such edge does not exist.
 */

bool Graph::removeEdge(const long long &sourcid, const long long &destid) {
	auto v1 = findVertex(sourcid);
	if (v1 == NULL)
		return false;
	return v1->removeEdgeTo(destid);
}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */

bool Vertex::removeEdgeTo(long long id) {
	for (int i = 0; i < adj.size(); ++i)
	{
		if (adj[i].id == id)
		{
			adj.erase(adj.begin()+i);
			return true;
		}
	}
	return false;
}


GPS Vertex::getInfo() const
{
	return info;
}

vector<Edge> Vertex::getAdj() const
{
	return adj;
}



/****************** 1d) removeVertex ********************/

/*
 *  Removes a vertex with a given content (in) from a graph (this), and
 *  all outgoing and incoming edges.
 *  Returns true if successful, and false if such vertex does not exist.
 */

bool Graph::removeVertex(const long long &id) {
	return vertexSet.erase(id);
}


/****************** 2a) dfs ********************/

/*
 * Performs a depth-first search (dfs) in a graph (this).
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */

vector<GPS> Graph::dfs() const {
	vector<GPS> res;
	for (auto v : vertexSet)
		v.second->visited = false;
	for (auto v : vertexSet)
		if (! v.second->visited)
			dfsVisit(v.second, res);
	return res;
}

/*
 * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
 * Updates a parameter with the list of visited node contents.
 */

void Graph::dfsVisit(Vertex *v, vector<GPS> & res) const {
	v->visited = true;
	res.push_back(v->info);
	for (auto & e : v->adj) {
		auto w = findVertex(e.id);
		if ( ! w->visited)
			dfsVisit(w, res);
	}
}

/****************** 2b) bfs ********************/

/*
 * Performs a breadth-first search (bfs) in a graph (this), starting
 * from the vertex with the given source contents (source).
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */

vector<GPS> Graph::bfs(const long long &id) const {
	vector<GPS> res;
	auto s = findVertex(id);
	if (s == NULL)
		return res;
	queue<Vertex *> q;
	for (auto v : vertexSet)
		v.second->visited = false;
	q.push(s);
	s->visited = true;
	while (!q.empty()) {
		auto v = q.front();
		q.pop();
		res.push_back(v->info);
		for (auto & e : v->adj) {
			auto w = findVertex(e.id);
			if ( ! w->visited ) {
				q.push(w);
				w->visited = true;
			}
		}
	}
	return res;
}

/****************** 2c) toposort ********************/

/*
 * Performs a topological sorting of the vertices of a graph (this).
 * Returns a vector with the contents of the vertices by topological order.
 * If the graph has cycles, returns an empty vector.
 * Follows the algorithm described in theoretical classes.
 */

vector<GPS> Graph::topsort() const {
	vector<GPS> res;

	for (auto v : vertexSet)
		v.second->indegree = 0;
	for (auto v : vertexSet)
		for (auto & e : v.second->adj)
			findVertex(e.id)->indegree++;

	queue<Vertex*> q;
	for (auto v : vertexSet)
		if (v.second->indegree == 0)
			q.push(v.second);

	while( !q.empty() ) {
		Vertex* v = q.front();
		q.pop();
		res.push_back(v->info);
		for(auto & e : v->adj) {
			auto w = findVertex(e.id);
			w->indegree--;
			if(w->indegree == 0)
				q.push(w);
		}
	}

	if ( res.size() != vertexSet.size() ) {
		cout << "Ordenacao Impossivel!" << endl;
		res.clear();
		return res;
	}

	return res;
}

/****************** 3a) maxNewChildren  ********************/

/*
 * Performs a breadth-first search in a graph (this), starting
 * from the vertex with the given source contents (source).
 * During the search, determines the vertex that has a maximum number
 * of new children (adjacent not previously visited), and returns the
 * contents of that vertex and the number of new children.
 */


int Graph::maxNewChildren(const long long &id, GPS &inf) const {
	auto s = findVertex(id);
	if (s == NULL)
		return 0;
	queue<Vertex *> q;
	int maxChildren = 0;
	inf = s->info;
	for (auto v : vertexSet)
		v.second->visited = false;
	q.push(s);
	s->visited = true;
	while (!q.empty()) {
		auto v = q.front();
		q.pop();
		int nChildren=0;
		for (auto & e : v->adj) {
			auto w = findVertex(e.id);
			if ( ! w->visited ) {
				w->visited = true;
				q.push(w);
				nChildren++;
			}
		}
		if (nChildren>maxChildren) {
			maxChildren = nChildren;
			inf = v->info;
		}
	}
	return maxChildren;
}

/****************** 3a) isDAG  ********************/

/*
 * Performs a depth-first search in a graph (this), to determine if the graph
 * is acyclic (acyclic directed graph or DAG).
 * During the search, a cycle is found if an edge connects to a vertex
 * that is being processed in the the stack of recursive calls (see theoretical classes).
 * Returns true if the graph is acyclic, and false otherwise.
 */


bool Graph::isDAG() const {
	for (auto v : vertexSet) {
		v.second->visited = false;
		v.second->processing = false;
	}
	for (auto v : vertexSet)
		if (! v.second->visited)
			if ( ! dfsIsDAG(v.second) )
				return false;
	return true;
}

/**
 * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
 * Returns false (not acyclic) if an edge to a vertex in the stack is found.
 */

bool Graph::dfsIsDAG(Vertex *v) const {
	v->visited = true;
	v->processing = true;
	for (auto & e : v->adj) {
		auto w = findVertex(e.id);
		if (w->processing)
			return false;
		if (! w->visited)
			if (! dfsIsDAG(w))
				return false;
	}
	v->processing = false;
	return true;
}

void Graph::listVertices() const {

	for (auto i : vertexSet)
	{
		cout << i.second->getInfo() << "\n";
	}
}

int Graph::size() const {
	return vertexSet.size();
}


pair<long long, Vertex*> Graph::getClosestGPS(const GPS &in) const {

	pair<long long, Vertex*> smallest = *vertexSet.begin();
	double mingpsvalue = in.distance(smallest.second->getInfo());

	for (auto i : vertexSet)
	{
		if (in.distance(i.second->getInfo()) < mingpsvalue)
		{
			mingpsvalue = in.distance(i.second->getInfo());
			smallest = i;
		}
	}

	return smallest;
}


Vertex * Graph::initSingleSource(const long long &id) {
	for (auto v : vertexSet) {
		v.second->dist = INF;
		v.second->path = nullptr;
	}
	auto s = findVertex(id);
	s->dist = 0;
	return s;
}
// * Analyzes an edge in single-source shortest path algorithm.
// * Returns true if the target vertex was relaxed (dist, path).
// * Used by all single-source shortest path algorithms.
// */
bool Graph::relax(Vertex *v, Vertex *w, double weight) {
	if (v->getDist() + weight < w->getDist()) {
		w->setDist(v->getDist() + weight);
		w->path = v;
		return true;
	}
	else
		return false;
}
// /**
// * Dijkstra algorithm.
// */
void Graph::dijkstraShortestPath(const long long &id) {
	auto s = initSingleSource(id);
	MutablePriorityQueue<Vertex> q;
	q.insert(s);
	while ( ! q.empty() ) {
		auto v = q.extractMin();
		for (auto e : v->adj) {
			auto oldDist = this->findVertex(e.id)->dist;
			if (relax(v, this->findVertex(e.id), e.weight)) {
				if (oldDist == INF)
					q.insert(this->findVertex(e.id));
				else
					q.decreaseKey(this->findVertex(e.id));
			}
		}
	}
}

vector<Vertex*> Graph::getPath(const long long &originid, const long long &destid) const {
	vector<Vertex*> res;

	auto v = this->findVertex(destid);
	auto vi = this->findVertex(originid);

	if (v == nullptr || v->dist == INF) // missing or disconnected
		return res;

	for ( ; v != nullptr ; v = v->path)
		res.push_back(v);

	reverse(res.begin(), res.end());

	return res;
}

long long Graph::findId(const Vertex* in) const
{
	for (auto i : vertexSet)
		if (i.second == in)
			return i.first;

	return -1;
}

// struct compareVertex
// {
// 	bool operator() (const Vertex* a, const Vertex* b) const
// 	{
// 		return (!(a->getDist() < b->getDist()));
// 	}
// };

// bool comp (const Vertex* a, const Vertex* b)
// {
// 	return (!(a->getDist() < b->getDist()));
// }
