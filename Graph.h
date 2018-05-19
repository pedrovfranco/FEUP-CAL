/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <utility>
#include "GPS.h"
#include <limits>
#include "MutablePriorityQueue.h"
#include <set>

using namespace std;

class Edge;
class Graph;
class Vertex;


/****************** Provided structures  ********************/
#define INF std::numeric_limits<double>::max()

class Vertex
{
 GPS info;                // contents
 vector<Edge> adj;  // list of outgoing edges
 bool visited;          // auxiliary field used by dfs and bfs
 bool processing = false;       // auxiliary field used by isDAG
 int indegree;          // auxiliary field used by topsort
 double dist = 0;
 Vertex *path = NULL;

 void addEdge(int edgeId, long long id, double w);
 void addEdge(int edgeId, long long id, double w, string name);
 bool removeEdgeTo(long long id);

public:
	int queueIndex = 0;


	Vertex(GPS in);
	bool operator<(Vertex & vertex) const;
	GPS getInfo() const;
	friend class Graph;
	friend class MutablePriorityQueue<Vertex>;
	double getDist()const {return dist;}
	double setDist(double dist){this->dist = dist;}
	int getQueueIndex(){return queueIndex;}
	void setQueueIndex(int i){queueIndex=i;}
	vector<Edge> getAdj() const;
};



class Edge
{
	int edgeId;             // Edge id
	long long id;           // Vertex id
	double weight;          // edge weight
	string roadName;

public:
	Edge(int edgeId, long long id, double w, string name);
	int getEdgeId() const;
	long long getId() const;
	string getRoadName() const;
	friend class Graph;
	friend class Vertex;
};


struct classcomp
{
	bool operator() (const pair<long long, double>& lhs, const pair<long long, double>& rhs) const
	{
		return (lhs.second < rhs.second);
	}
};

class Graph
{
	unordered_map<long long, Vertex *> vertexSet;    // vertex set

	void dfsVisit(Vertex *v,  vector<GPS> & res) const;
	bool dfsIsDAG(Vertex *v) const;

public:
	int getNumVertex() const;
	bool addVertex(const long long &id, const GPS &in);
	bool removeVertex(const long long &id);
	bool addEdge(const long long &sourcid, const long long &destid, int edgeId);
	bool addEdge(const long long &sourcid, const long long &destid, int edgeId, string name);
	bool addDoubleEdge(const long long &sourcid, const long long &destid, int edgeId);
	bool addDoubleEdge(const long long &sourcid, const long long &destid, int edgeId, string name);
	bool removeEdge(const long long &sourcid, const long long &destid);
	vector<GPS> dfs() const;
	vector<GPS> bfs(const long long &id) const;
	vector<GPS> topsort() const;
	int maxNewChildren(const long long &id, GPS &inf) const;
	bool isDAG() const;
	Vertex *findVertex(const long long &id) const;
	void listVertices() const;
	int size() const;
	pair<long long, Vertex*> getClosestGPS(const GPS &in) const;
	Vertex * initSingleSource(const long long &id);
	bool relax(Vertex *v, Vertex *w, double weight);
	void dijkstraShortestPath(const long long &id);
	vector<Vertex*> getPath(const long long &originid, const long long &destid) const;
	long long findId(const Vertex* in) const;
	void floydWarshall();

	set<pair<long long, double>, classcomp> searchByRoadName(string roadName);

	Edge findEdge(long long edgeId);

	};


#endif /* GRAPH_H_ */